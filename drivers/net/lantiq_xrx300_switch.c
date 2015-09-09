/*
 * Copyright (C) 2010-2011 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <netdev.h>
#include <miiphy.h>
#include <watchdog.h>
#include <linux/compiler.h>
#include <asm/gpio.h>
#include <asm/processor.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/pm.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/dma.h>
#include <asm/arch/soc.h>
#include <asm/arch/switch.h>

#define LTQ_ETH_RX_BUFFER_CNT		PKTBUFSRX
#define LTQ_ETH_TX_BUFFER_CNT		8
#define LTQ_ETH_RX_DATA_SIZE		PKTSIZE_ALIGN
#define LTQ_ETH_IP_ALIGN		2
#define LTQ_PHY_ANEG_TIMEOUT		3000

#define LTQ_MDIO_DRV_NAME		"ltq-mdio"
#define LTQ_ETH_DRV_NAME		"ltq-eth"

#define LTQ_ETHSW_MAX_GMAC		6
#define LTQ_ETHSW_PMAC			6

struct ltq_mdio_phy_addr_reg {
	union {
		struct {
			unsigned rsvd:1;
			unsigned lnkst:2;	/* Link status control */
			unsigned speed:2;	/* Speed control */
			unsigned fdup:2;	/* Full duplex control */
			unsigned fcontx:2;	/* Flow control mode TX */
			unsigned fconrx:2;	/* Flow control mode RX */
			unsigned addr:5;	/* PHY address */
		} bits;
		u16 val;
	};
};

enum ltq_mdio_phy_addr_lnkst {
	LTQ_MDIO_PHY_ADDR_LNKST_AUTO = 0,
	LTQ_MDIO_PHY_ADDR_LNKST_UP = 1,
	LTQ_MDIO_PHY_ADDR_LNKST_DOWN = 2,
};

enum ltq_mdio_phy_addr_speed {
	LTQ_MDIO_PHY_ADDR_SPEED_M10 = 0,
	LTQ_MDIO_PHY_ADDR_SPEED_M100 = 1,
	LTQ_MDIO_PHY_ADDR_SPEED_G1 = 2,
	LTQ_MDIO_PHY_ADDR_SPEED_AUTO = 3,
};

enum ltq_mdio_phy_addr_fdup {
	LTQ_MDIO_PHY_ADDR_FDUP_AUTO = 0,
	LTQ_MDIO_PHY_ADDR_FDUP_ENABLE = 1,
	LTQ_MDIO_PHY_ADDR_FDUP_DISABLE = 3,
};

enum ltq_mdio_phy_addr_fcon {
	LTQ_MDIO_PHY_ADDR_FCON_AUTO = 0,
	LTQ_MDIO_PHY_ADDR_FCON_ENABLE = 1,
	LTQ_MDIO_PHY_ADDR_FCON_DISABLE = 3,
};

struct ltq_mii_mii_cfg_reg {
	union {
		struct {
			unsigned res:1;		/* Hardware reset */
			unsigned en:1;		/* xMII interface enable */
			unsigned isol:1;	/* xMII interface isolate */
			unsigned ldclkdis:1;	/* Link down clock disable */
			unsigned rsvd:1;
			unsigned crs:2;		/* CRS sensitivity config */
			unsigned rgmii_ibs:1;	/* RGMII In Band status */
			unsigned rmii:1;	/* RMII ref clock direction */
			unsigned miirate:3;	/* xMII interface clock rate */
			unsigned miimode:4;	/* xMII interface mode */
		} bits;
		u16 val;
	};
};

enum ltq_mii_mii_cfg_miirate {
	LTQ_MII_MII_CFG_MIIRATE_M2P5 = 0,
	LTQ_MII_MII_CFG_MIIRATE_M25 = 1,
	LTQ_MII_MII_CFG_MIIRATE_M125 = 2,
	LTQ_MII_MII_CFG_MIIRATE_M50 = 3,
	LTQ_MII_MII_CFG_MIIRATE_AUTO = 4,
};

enum ltq_mii_mii_cfg_miimode {
	LTQ_MII_MII_CFG_MIIMODE_MIIM = 1,
	LTQ_MII_MII_CFG_MIIMODE_RMIIM = 3,
	LTQ_MII_MII_CFG_MIIMODE_RGMII = 4,
	LTQ_MII_MII_CFG_MIIMODE_GMIIM = 9,
	LTQ_MII_MII_CFG_MIIMODE3_GMIIM = 1,
};

struct ltq_eth_priv {
	struct ltq_dma_device dma_dev;
	struct mii_dev *bus;
	struct eth_device *dev;
	struct phy_device *phymap[LTQ_ETHSW_MAX_GMAC];
	int rx_num;
	int tx_num;
};

static struct ar10_switch_regs *switch_regs =
	(struct ar10_switch_regs *) CKSEG1ADDR(LTQ_SWITCH_BASE);

void switch_mem_fix(u32 mem_id, u32 rar0_1, u32 addr)
{
	u32 rar_addr = 0;

	addr |= 0x20000;

	switch (mem_id) {
	case 0x9:
		rar_addr = rar0_1 ? 8 : 0;
		break;
	case 0xa:
		rar_addr = rar0_1 ? 10 : 2;
		break;
	case 0xb:
		rar_addr = rar0_1 ? 12 : 4;
		break;
	case 0xc:
		rar_addr = rar0_1 ? 14 : 6;
		break;
	default:
		break;
	}

	printf("Fix switch memory: %08x -> %08x\n", addr, rar_addr);

	ltq_writel(&switch_regs->core.ssb_data, addr);
	ltq_writel(&switch_regs->core.ssb_addr, rar_addr);
	ltq_writel(&switch_regs->core.ssb_mode, 1);

	while (ltq_readl(&switch_regs->core.ssb_mode))
		;
}

static inline int ar10_switch_mdio_is_busy(void)
{
	u32 mdio_ctrl = ltq_readl(&switch_regs->mdio.mdio_ctrl);

	return mdio_ctrl & MDIO_CTRL_MBUSY;
}

static inline void ar10_switch_mdio_poll(void)
{
	while (ar10_switch_mdio_is_busy())
		cpu_relax();
}

static int ar10_switch_mdio_read(struct mii_dev *bus, int phyad, int devad,
					int regad)
{
	u32 mdio_ctrl;
	int retval;

	mdio_ctrl = MDIO_CTRL_OP_READ |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

	ar10_switch_mdio_poll();
	ltq_writel(&switch_regs->mdio.mdio_ctrl, mdio_ctrl);
	ar10_switch_mdio_poll();
	retval = ltq_readl(&switch_regs->mdio.mdio_read);

#if 0
	printf("%s: phyad %x, devad %x, regad %x, val %x\n",
		__func__, phyad, devad, regad, retval);
#endif

	return retval;
}

static int ar10_switch_mdio_write(struct mii_dev *bus, int phyad, int devad,
					int regad, u16 val)
{
	u32 mdio_ctrl;

	mdio_ctrl = MDIO_CTRL_OP_WRITE |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

#if 0
	printf("%s: phyad %x, devad %x, regad %x, val %x\n",
		__func__, phyad, devad, regad, val);
#endif

	ar10_switch_mdio_poll();
	ltq_writel(&switch_regs->mdio.mdio_write, val);
	ltq_writel(&switch_regs->mdio.mdio_ctrl, mdio_ctrl);

	return 0;
}

static void ltq_eth_gmac_update(struct phy_device *phydev, int num)
{
	struct ltq_mdio_phy_addr_reg phy_addr_reg;
	struct ltq_mii_mii_cfg_reg mii_cfg_reg;

	phy_addr_reg.val = ltq_readl(to_mdio_phyaddr(switch_regs, num));

	switch (num) {
	case 0:
	case 5:
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs, num));
		break;
	default:
		mii_cfg_reg.val = 0;
		break;
	}

	phy_addr_reg.bits.addr = phydev->addr;

	if (phydev->link)
		phy_addr_reg.bits.lnkst = LTQ_MDIO_PHY_ADDR_LNKST_UP;
	else
		phy_addr_reg.bits.lnkst = LTQ_MDIO_PHY_ADDR_LNKST_DOWN;

	switch (phydev->speed) {
	case SPEED_1000:
		phy_addr_reg.bits.speed = LTQ_MDIO_PHY_ADDR_SPEED_G1;
		mii_cfg_reg.bits.miirate = LTQ_MII_MII_CFG_MIIRATE_M125;
		break;
	case SPEED_100:
		phy_addr_reg.bits.speed = LTQ_MDIO_PHY_ADDR_SPEED_M100;
		switch (mii_cfg_reg.bits.miimode) {
		case LTQ_MII_MII_CFG_MIIMODE_RMIIM:
			mii_cfg_reg.bits.miirate = LTQ_MII_MII_CFG_MIIRATE_M50;
			break;
		default:
			mii_cfg_reg.bits.miirate = LTQ_MII_MII_CFG_MIIRATE_M25;
			break;
		}
		break;
	default:
		phy_addr_reg.bits.speed = LTQ_MDIO_PHY_ADDR_SPEED_M10;
		mii_cfg_reg.bits.miirate = LTQ_MII_MII_CFG_MIIRATE_M2P5;
		break;
	}

	if (phydev->duplex == DUPLEX_FULL)
		phy_addr_reg.bits.fdup = LTQ_MDIO_PHY_ADDR_FDUP_ENABLE;
	else
		phy_addr_reg.bits.fdup = LTQ_MDIO_PHY_ADDR_FDUP_DISABLE;

	ltq_writel(to_mdio_phyaddr(switch_regs, num), phy_addr_reg.val);

	switch (num) {
	case 0:
	case 5:
		ltq_writel(to_mii_miicfg(switch_regs, num), mii_cfg_reg.val);
		break;
	default:
		break;
	}
}

static inline u8 *ltq_eth_rx_packet_align(int rx_num)
{
	u8 *packet = (u8 *) NetRxPackets[rx_num];

	/*
	 * IP header needs
	 */
	return packet + LTQ_ETH_IP_ALIGN;
}

static int ltq_eth_phy_startup(struct ltq_eth_priv *priv)
{
	struct phy_device *phydev;
	int i, j;

	puts("Waiting for PHY link\n");

	for (i = 0; i < LTQ_PHY_ANEG_TIMEOUT; i++) {
		for (j = 0; j < LTQ_ETHSW_MAX_GMAC; j++) {
			phydev = priv->phymap[j];
			if (!phydev)
				continue;

			WATCHDOG_RESET();

			phy_startup(phydev);

			if (phydev->link) {
				ltq_eth_gmac_update(phydev, j);
				printf("Using PHY at addr %d, speed %d, duplex %d\n",
					phydev->addr, phydev->speed,
					phydev->duplex);
				return 0;
			}
		}

		if (ctrlc())
			return -1;

		udelay(1000);
	}

	return -1;
}

static int ltq_eth_init(struct eth_device *dev, bd_t * bis)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	int i, err;

	err = ltq_eth_phy_startup(priv);
	if (err) {
		puts("No PHY link found\n");
		return -1;
	}

	for (i = 0; i < LTQ_ETH_RX_BUFFER_CNT; i++)
		ltq_dma_rx_map(dma_dev, i, ltq_eth_rx_packet_align(i),
			LTQ_ETH_RX_DATA_SIZE);

	ltq_dma_enable(dma_dev);

	priv->rx_num = 0;
	priv->tx_num = 0;

	return 0;
}

static void ltq_eth_halt(struct eth_device *dev)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	struct phy_device *phydev;
	int i;

	ltq_dma_reset(dma_dev);

	for (i = 0; i < LTQ_ETHSW_MAX_GMAC; i++) {
		phydev = priv->phymap[i];
		if (!phydev)
			continue;

		phy_shutdown(phydev);
		phydev->link = 0;
		ltq_eth_gmac_update(phydev, i);
	}
}

static int ltq_eth_send(struct eth_device *dev, void *packet, int length)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;

#if 0
	printf("%s: packet %p, len %d\n", __func__, packet, length);
#endif

	ltq_dma_tx_map(dma_dev, priv->tx_num, packet, length, 10);
	priv->tx_num = (priv->tx_num + 1) % LTQ_ETH_TX_BUFFER_CNT;

	return 0;
}

static int ltq_eth_recv(struct eth_device *dev)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	u8 *packet;
	int len;

	if (!ltq_dma_rx_poll(dma_dev, priv->rx_num))
		return 0;

#if 0
	printf("%s: rx_num %d\n", __func__, priv->rx_num);
#endif

	len = ltq_dma_rx_length(dma_dev, priv->rx_num);
	packet = ltq_eth_rx_packet_align(priv->rx_num);

#if 0
	printf("%s: received: packet %p, len %u, rx_num %d\n",
		__func__, packet, len, priv->rx_num);
#endif

	if (len)
		NetReceive(packet, len);

	ltq_dma_rx_map(dma_dev, priv->rx_num, packet,
		LTQ_ETH_RX_DATA_SIZE);

	priv->rx_num = (priv->rx_num + 1) % LTQ_ETH_RX_BUFFER_CNT;

	return 0;
}

static void ltq_eth_gmac_init(int num)
{
	struct ltq_mdio_phy_addr_reg phy_addr_reg;
	struct ltq_mii_mii_cfg_reg mii_cfg_reg;

	/* Reset PHY status to link down */
	phy_addr_reg.val = ltq_readl(to_mdio_phyaddr(switch_regs, num));
	phy_addr_reg.bits.addr = num;
	phy_addr_reg.bits.lnkst = LTQ_MDIO_PHY_ADDR_LNKST_DOWN;
	phy_addr_reg.bits.speed = LTQ_MDIO_PHY_ADDR_SPEED_M10;
	phy_addr_reg.bits.fdup = LTQ_MDIO_PHY_ADDR_FDUP_DISABLE;
	ltq_writel(to_mdio_phyaddr(switch_regs, num), phy_addr_reg.val);

	/* Reset and disable MII interface */
	switch (num) {
	case 0:
	case 5:
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs, num));
		mii_cfg_reg.bits.en = 0;
		mii_cfg_reg.bits.res = 1;
		mii_cfg_reg.bits.miirate = LTQ_MII_MII_CFG_MIIRATE_M2P5;
		ltq_writel(to_mii_miicfg(switch_regs, num), mii_cfg_reg.val);
		break;
	default:
		break;
	}

	/*
	 * - enable frame checksum generation
	 * - enable padding of short frames
	 * - disable flow control
	 */
	ltq_writel(to_mac_ctrl(switch_regs, num, 0),
		MAC_CTRL0_PADEN | MAC_CTRL0_FCS | MAC_CTRL0_FCON_NONE);
}

static void ltq_eth_pmac_init(void)
{
	/*
	 * Configure frame header control:
	 * - enable flow control
	 * - enable CRC check for packets from DMA to PMAC
	 * - remove special tag from packets from PMAC to DMA
	 * - add CRC for packets from DMA to PMAC
	 */
	ltq_writel(&switch_regs->pmac.hd_ctl, /*PMAC_HD_CTL_FC |*/
		PMAC_HD_CTL_CCRC | PMAC_HD_CTL_RST | PMAC_HD_CTL_AC |
		PMAC_HD_CTL_RC);

	ltq_writel(&switch_regs->pmac.rx_ipg, 0x8b);

	/*
	 * - enable frame checksum generation
	 * - enable padding of short frames
	 * - disable flow control
	 */
	ltq_writel(to_mac_ctrl(switch_regs, LTQ_ETHSW_PMAC, 0),
		MAC_CTRL0_PADEN | MAC_CTRL0_FCS | MAC_CTRL0_FCON_NONE);
}

static void ltq_eth_hw_init(void)
{
	int i;

	/* Power up ethernet and switch subsystems */
	ltq_pm_enable(LTQ_PM_ETH);

	/* Enable switch macro */
	ltq_setbits(&switch_regs->mdio.glob_ctrl, MDIO_GLOB_CTRL_SE);

	/* Disable MDIO auto-polling for all ports */
	ltq_writel(&switch_regs->mdio.mdc_cfg_0, 0);

	/*
	 * Enable and set MDIO management clock to 2.5 MHz. This is the
	 * maximum clock for FE PHYs.
	 * Formula for clock is:
	 *
	 *      50 MHz
	 * x = ----------- - 1
	 *      2 * f_MDC
	 */
	ltq_writel(&switch_regs->mdio.mdc_cfg_1, MDIO_MDC_CFG1_RES |
		MDIO_MDC_CFG1_MCEN | 5);

	/* Init MAC connected to CPU  */
	ltq_eth_pmac_init();

	/* Init MACs connected to external MII interfaces */
	for (i = 0; i < LTQ_ETHSW_MAX_GMAC; i++)
		ltq_eth_gmac_init(i);
}

static void ltq_eth_port_config(struct ltq_eth_priv *priv,
					const struct ltq_eth_port_config *port)
{
	struct ltq_mii_mii_cfg_reg mii_cfg_reg;
	struct phy_device *phydev;
	int setup_gpio = 0;

	switch (port->num) {
	case 0:	/* xMII0 */
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs,
					port->num));
		mii_cfg_reg.bits.en = port->flags ? 1 : 0;

		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_GMII:
			/* GMII MAC mode, connected to external PHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_GMIIM;
			setup_gpio = 1;
			break;
		case PHY_INTERFACE_MODE_RMII:
			/* RMII MAC mode, connected to external PHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_RMIIM;
			setup_gpio = 1;
			break;
		case PHY_INTERFACE_MODE_RGMII:
			/* RGMII MAC mode, connected to external PHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_RGMII;
			setup_gpio = 1;

			/* RGMII clock delays */
			ltq_writel(to_mii_pcdu(switch_regs, port->num),
				port->rgmii_rx_delay << PCDU_RXDLY_SHIFT |
				port->rgmii_tx_delay);
			break;
		default:
			break;
		}

		ltq_writel(to_mii_miicfg(switch_regs, port->num),
			mii_cfg_reg.val);
		break;
	case 3:	/* internal GPHY3 */
		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_MII:
			/* internal GPHY0 (FE) */
			ltq_clrbits(to_mii_miicfg(switch_regs, port->num),
				LTQ_MII_MII_CFG_MIIMODE3_GMIIM);
			break;
		case PHY_INTERFACE_MODE_GMII:
			/* internal GPHY3 (GE) */
			ltq_setbits(to_mii_miicfg(switch_regs, port->num),
				LTQ_MII_MII_CFG_MIIMODE3_GMIIM);
			break;
		default:
			break;
		}
		break;
	case 5:	/* internal GPHY1 or xMII1 */
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs,
					port->num));
		mii_cfg_reg.bits.en = port->flags ? 1 : 0;

		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_MII:
			/* MII MAC mode, connected to internal GPHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_MIIM;
			break;
		case PHY_INTERFACE_MODE_RMII:
			/* RMII MAC mode, connected to external PHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_RMIIM;
			setup_gpio = 1;
			break;
		case PHY_INTERFACE_MODE_RGMII:
			/* RGMII MAC mode, connected to external PHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_RGMII;
			setup_gpio = 1;

			/* RGMII clock delays */
			ltq_writel(to_mii_pcdu(switch_regs, port->num),
				port->rgmii_rx_delay << PCDU_RXDLY_SHIFT |
				port->rgmii_tx_delay);
			break;
		default:
			break;
		}

		ltq_writel(to_mii_miicfg(switch_regs, port->num),
			mii_cfg_reg.val);
		break;
	default:
		break;
	}

	/* Setup GPIOs for MII with external PHYs/MACs */
	if (setup_gpio) {
		/* MII/MDIO */
		gpio_set_altfunc(42, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR,
					GPIO_DIR_OUT);
		/* MII/MDC */
		gpio_set_altfunc(43, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR,
					GPIO_DIR_OUT);
	}

	/* Connect to internal/external PHYs */
	if (port->flags & LTQ_ETH_PORT_PHY) {
		phydev = phy_connect(priv->bus, port->phy_addr, priv->dev,
					port->phy_if);
		if (phydev)
			phy_config(phydev);

		priv->phymap[port->num] = phydev;
	}
}

int ltq_eth_initialize(const struct ltq_eth_board_config *board_config)
{
	struct eth_device *dev;
	struct mii_dev *bus;
	struct ltq_eth_priv *priv;
	struct ltq_dma_device *dma_dev;
	int i, ret;

	build_check_ar10_registers();

	ltq_reset_switch_mem_repair();
	ltq_dma_init();
	ltq_eth_hw_init();

	dev = calloc(1, sizeof(struct eth_device));
	if (!dev)
		return -1;

	priv = calloc(1, sizeof(struct ltq_eth_priv));
	if (!priv)
		return -1;

	bus = mdio_alloc();
	if (!bus)
		return -1;

	sprintf(dev->name, LTQ_ETH_DRV_NAME);
	dev->priv = priv;
	dev->init = ltq_eth_init;
	dev->halt = ltq_eth_halt;
	dev->recv = ltq_eth_recv;
	dev->send = ltq_eth_send;

	sprintf(bus->name, LTQ_MDIO_DRV_NAME);
	bus->read = ar10_switch_mdio_read;
	bus->write = ar10_switch_mdio_write;
	bus->priv = priv;

	dma_dev = &priv->dma_dev;
	dma_dev->port = 0;
	dma_dev->rx_chan.chan_no = 0;
	dma_dev->rx_chan.class = 0;
	dma_dev->rx_chan.num_desc = LTQ_ETH_RX_BUFFER_CNT;
	dma_dev->rx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev->rx_burst_len = LTQ_DMA_BURST_2WORDS;
	dma_dev->tx_chan.chan_no = 1;
	dma_dev->tx_chan.class = 0;
	dma_dev->tx_chan.num_desc = LTQ_ETH_TX_BUFFER_CNT;
	dma_dev->tx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev->tx_burst_len = LTQ_DMA_BURST_2WORDS;

	priv->bus = bus;
	priv->dev = dev;

	ret = ltq_dma_register(dma_dev);
	if (ret)
		return -1;

	ret = mdio_register(bus);
	if (ret)
		return -1;

	ret = eth_register(dev);
	if (ret)
		return -1;

	for (i = 0; i < board_config->num_ports; i++)
		ltq_eth_port_config(priv, &board_config->ports[i]);

	return 0;
}
