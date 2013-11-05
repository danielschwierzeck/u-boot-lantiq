/*
 * Copyright (C) 2010-2011 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#define DEBUG

#include <common.h>
#include <malloc.h>
#include <netdev.h>
#include <miiphy.h>
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
	LTQ_MII_MII_CFG_MIIMODE_MIIP = 0,
	LTQ_MII_MII_CFG_MIIMODE_MIIM = 1,
	LTQ_MII_MII_CFG_MIIMODE_RMIIP = 2,
	LTQ_MII_MII_CFG_MIIMODE_RMIIM = 3,
	LTQ_MII_MII_CFG_MIIMODE_RGMII = 4,
};

struct ltq_eth_priv {
	struct ltq_dma_device dma_dev;
	struct mii_dev *bus;
	struct eth_device *dev;
	struct phy_device *phymap[LTQ_ETHSW_MAX_GMAC];
	int rx_num;
	int tx_num;
};

static struct vr9_switch_regs *switch_regs =
	(struct vr9_switch_regs *) CKSEG1ADDR(LTQ_SWITCH_BASE);

static inline void vr9_switch_sync(void)
{
	__asm__("sync");
}

static inline int vr9_switch_mdio_is_busy(void)
{
	u32 mdio_ctrl = ltq_readl(&switch_regs->mdio.mdio_ctrl);

	return mdio_ctrl & MDIO_CTRL_MBUSY;
}

static inline void vr9_switch_mdio_poll(void)
{
	while (vr9_switch_mdio_is_busy())
		cpu_relax();
}

static int vr9_switch_mdio_read(struct mii_dev *bus, int phyad, int devad,
					int regad)
{
	u32 mdio_ctrl;
	int retval;

	mdio_ctrl = MDIO_CTRL_OP_READ |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

	vr9_switch_mdio_poll();
	ltq_writel(&switch_regs->mdio.mdio_ctrl, mdio_ctrl);
	vr9_switch_mdio_poll();
	retval = ltq_readl(&switch_regs->mdio.mdio_read);

	return retval;
}

static int vr9_switch_mdio_write(struct mii_dev *bus, int phyad, int devad,
					int regad, u16 val)
{
	u32 mdio_ctrl;

	mdio_ctrl = MDIO_CTRL_OP_WRITE |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

	vr9_switch_mdio_poll();
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
	case 1:
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
		case LTQ_MII_MII_CFG_MIIMODE_RMIIP:
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
	case 1:
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

static int ltq_eth_init(struct eth_device *dev, bd_t *bis)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	struct phy_device *phydev;
	int i;

	for (i = 0; i < LTQ_ETHSW_MAX_GMAC; i++) {
		phydev = priv->phymap[i];
		if (!phydev)
			continue;

		phy_startup(phydev);
		ltq_eth_gmac_update(phydev, i);
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
	case 1:
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

	vr9_switch_sync();
}

static void ltq_eth_pmac_init(void)
{
	/*
	 * WAR: buffer congestion:
	 * - shorten preambel to 1 byte
	 * - set TX IPG to 7 bytes
	 */
#if 1
	ltq_writel(to_mac_ctrl(switch_regs, LTQ_ETHSW_PMAC, 1),
		MAC_CTRL1_SHORTPRE | 7);
#endif

	/*
	 * WAR: systematical concept weakness ACM bug
	 * - set maximum number of used buffer segments to 254
	 * - soft-reset BM FSQM
	 */
#if 1
	ltq_writel(&switch_regs->bm.core.fsqm_gctrl, 253);
	ltq_setbits(&switch_regs->bm.core.gctrl, BM_GCTRL_F_SRES);
	ltq_clrbits(&switch_regs->bm.core.gctrl, BM_GCTRL_F_SRES);
#endif

	/*
	 * WAR: switch MAC drop bug
	 */
#if 1
	ltq_writel(to_pce_tbl_key(switch_regs, 0), 0xf);
	ltq_writel(to_pce_tbl_value(switch_regs, 0), 0x40);
	ltq_writel(&switch_regs->pce.core.tbl_addr, 0x3);
	ltq_writel(&switch_regs->pce.core.tbl_ctrl, 0x902f);
#endif

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

#if 1
	ltq_writel(&switch_regs->pmac.rx_ipg, 0x8b);
#endif

	/*
	 * - enable frame checksum generation
	 * - enable padding of short frames
	 * - disable flow control
	 */
	ltq_writel(to_mac_ctrl(switch_regs, LTQ_ETHSW_PMAC, 0),
		MAC_CTRL0_PADEN | MAC_CTRL0_FCS | MAC_CTRL0_FCON_NONE);

	vr9_switch_sync();
}

static void ltq_eth_hw_init(void)
{
	int i;

	/* Power up ethernet and switch subsystems */
	ltq_pm_enable(LTQ_PM_ETH);

	/* Reset ethernet and switch subsystems */
#if 0
	ltq_reset_once(LTQ_RESET_ETH, 10);
#endif

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

	vr9_switch_sync();

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
	case 1:	/* xMII1 */
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs,
					port->num));
		mii_cfg_reg.bits.en = port->flags ? 1 : 0;

		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_MII:
			if (port->flags & LTQ_ETH_PORT_PHY)
				/* MII MAC mode, connected to external PHY */
				mii_cfg_reg.bits.miimode =
					LTQ_MII_MII_CFG_MIIMODE_MIIM;
			else
				/* MII PHY mode, connected to external MAC */
				mii_cfg_reg.bits.miimode =
					LTQ_MII_MII_CFG_MIIMODE_MIIP;
			setup_gpio = 1;
			break;
		case PHY_INTERFACE_MODE_RMII:
			if (port->flags & LTQ_ETH_PORT_PHY)
				/* RMII MAC mode, connected to external PHY */
				mii_cfg_reg.bits.miimode =
					LTQ_MII_MII_CFG_MIIMODE_RMIIM;
			else
				/* RMII PHY mode, connected to external MAC */
				mii_cfg_reg.bits.miimode =
					LTQ_MII_MII_CFG_MIIMODE_RMIIP;
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
	case 2:	/* internal GPHY0 */
	case 3:	/* internal GPHY0 */
	case 4:	/* internal GPHY1 */
		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_MII:
		case PHY_INTERFACE_MODE_GMII:
			setup_gpio = 1;
			break;
		default:
			break;
		}
		break;
	case 5:	/* internal GPHY1 or xMII2 */
		mii_cfg_reg.val = ltq_readl(to_mii_miicfg(switch_regs,
					port->num));
		mii_cfg_reg.bits.en = port->flags ? 1 : 0;

		switch (port->phy_if) {
		case PHY_INTERFACE_MODE_MII:
			/* MII MAC mode, connected to internal GPHY */
			mii_cfg_reg.bits.miimode =
				LTQ_MII_MII_CFG_MIIMODE_MIIM;
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

	build_check_vr9_registers();

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
	bus->read = vr9_switch_mdio_read;
	bus->write = vr9_switch_mdio_write;
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
