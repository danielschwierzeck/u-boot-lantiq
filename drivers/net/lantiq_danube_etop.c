/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <netdev.h>
#include <miiphy.h>
#include <switch.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/pm.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/dma.h>
#include <asm/arch/soc.h>

#define LTQ_PPE_ETOP_MDIO_ACC_RA	(1 << 31)
#define LTQ_PPE_ETOP_MDIO_CFG_UMM1	(1 << 2)
#define LTQ_PPE_ETOP_MDIO_CFG_UMM0	(1 << 1)

#define LTQ_PPE_ETOP_CFG_TCKINV1	(1 << 11)
#define LTQ_PPE_ETOP_CFG_TCKINV0	(1 << 10)
#define LTQ_PPE_ETOP_CFG_FEN1		(1 << 9)
#define LTQ_PPE_ETOP_CFG_FEN0		(1 << 8)
#define LTQ_PPE_ETOP_CFG_SEN1		(1 << 7)
#define LTQ_PPE_ETOP_CFG_SEN0		(1 << 6)
#define LTQ_PPE_ETOP_CFG_TURBO1		(1 << 5)
#define LTQ_PPE_ETOP_CFG_REMII1		(1 << 4)
#define LTQ_PPE_ETOP_CFG_OFF1		(1 << 3)
#define LTQ_PPE_ETOP_CFG_TURBO0		(1 << 2)
#define LTQ_PPE_ETOP_CFG_REMII0		(1 << 1)
#define LTQ_PPE_ETOP_CFG_OFF0		(1 << 0)

#define LTQ_PPE_ENET0_MAC_CFG_CGEN	(1 << 11)
#define LTQ_PPE_ENET0_MAC_CFG_DUPLEX	(1 << 2)
#define LTQ_PPE_ENET0_MAC_CFG_SPEED	(1 << 1)
#define LTQ_PPE_ENET0_MAC_CFG_LINK	(1 << 0)

#define LTQ_PPE_ENETS0_CFG_FTUC		(1 << 28)

#define LTQ_ETH_RX_BUFFER_CNT		PKTBUFSRX
#define LTQ_ETH_TX_BUFFER_CNT		8
#define LTQ_ETH_RX_DATA_SIZE		PKTSIZE_ALIGN
#define LTQ_ETH_IP_ALIGN		2

#define LTQ_MDIO_DRV_NAME		"ltq-mdio"
#define LTQ_ETH_DRV_NAME		"ltq-eth"

struct ltq_ppe_etop_regs {
	u32	mdio_cfg;		/* MDIO configuration */
	u32	mdio_acc;		/* MDIO access */
	u32	cfg;			/* ETOP configuration */
	u32	ig_vlan_cos;		/* IG VLAN priority CoS mapping */
	u32	ig_dscp_cos3;		/* IG DSCP CoS mapping 3 */
	u32	ig_dscp_cos2;		/* IG DSCP CoS mapping 2 */
	u32	ig_dscp_cos1;		/* IG DSCP CoS mapping 1 */
	u32	ig_dscp_cos0;		/* IG DSCP CoS mapping 0 */
	u32	ig_plen_ctrl;		/* IG frame length control */
	u32	rsvd0[3];
	u32	vpid;			/* VLAN protocol ID */
};

struct ltq_ppe_enet_regs {
	u32	mac_cfg;		/* MAC configuration */
	u32	rsvd0[3];
	u32	ig_cfg;			/* Ingress configuration */
	u32	ig_pgcnt;		/* Ingress buffer used page count */
	u32	rsvd1;
	u32	ig_buf_ctrl;		/* Ingress buffer backpressure ctrl */
	u32	cos_cfg;		/* Classification configuration */
	u32	ig_drop;		/* Total ingress drop frames */
	u32	ig_err;			/* Total ingress error frames */
	u32	mac_da0;		/* Ingress MAC address 0 */
	u32	mac_da1;		/* Ingress MAC address 1 */
	u32	rsvd2[22];
	u32	pgcnt;			/* Page counter */
	u32	rsvd3;
	u32	hf_ctrl;		/* Half duplex control */
	u32	tx_ctrl;		/* Transmit control */
	u32	rsvd4;
	u32	vlcos0;			/* VLAN insertion config CoS 0 */
	u32	vlcos1;			/* VLAN insertion config CoS 1 */
	u32	vlcos2;			/* VLAN insertion config CoS 2 */
	u32	vlcos3;			/* VLAN insertion config CoS 3 */
	u32	eg_col;			/* Total egress collision frames */
	u32	eg_drop;		/* Total egress drop frames */
};

struct ltq_eth_priv {
	struct ltq_dma_device dma_dev;
	struct mii_dev *bus;
	struct eth_device *dev;
	int rx_num;
	int tx_num;
};

struct ltq_mdio_access {
	union {
		struct {
			unsigned ra:1;
			unsigned rw:1;
			unsigned rsvd:4;
			unsigned phya:5;
			unsigned rega:5;
			unsigned phyd:16;
		} reg;
		u32 val;
	};
};

static struct ltq_ppe_etop_regs *ltq_ppe_etop_regs =
	(struct ltq_ppe_etop_regs *) CKSEG1ADDR(LTQ_PPE_ETOP_BASE);

static struct ltq_ppe_enet_regs *ltq_ppe_enet0_regs =
	(struct ltq_ppe_enet_regs *) CKSEG1ADDR(LTQ_PPE_ENET0_BASE);

static inline int ltq_mdio_poll(void)
{
	struct ltq_mdio_access acc;
	unsigned cnt = 10000;

	while (likely(cnt--)) {
		acc.val = ltq_readl(&ltq_ppe_etop_regs->mdio_acc);
		if (!acc.reg.ra)
			return 0;
	}

	return 1;
}

static int ltq_mdio_read(struct mii_dev *bus, int addr, int dev_addr,
				int regnum)
{
	struct ltq_mdio_access acc;
	int ret;

	acc.val = 0;
	acc.reg.ra = 1;
	acc.reg.rw = 1;
	acc.reg.phya = addr;
	acc.reg.rega = regnum;

	ret = ltq_mdio_poll();
	if (ret)
		return ret;

	ltq_writel(&ltq_ppe_etop_regs->mdio_acc, acc.val);

	ret = ltq_mdio_poll();
	if (ret)
		return ret;

	acc.val = ltq_readl(&ltq_ppe_etop_regs->mdio_acc);

	return acc.reg.phyd;
}

static int ltq_mdio_write(struct mii_dev *bus, int addr, int dev_addr,
				int regnum, u16 val)
{
	struct ltq_mdio_access acc;
	int ret;

	acc.val = 0;
	acc.reg.ra = 1;
	acc.reg.rw = 0;
	acc.reg.phya = addr;
	acc.reg.rega = regnum;
	acc.reg.phyd = val;

	ret = ltq_mdio_poll();
	if (ret)
		return ret;

	ltq_writel(&ltq_ppe_etop_regs->mdio_acc, acc.val);

	return 0;
}

static inline void ltq_eth_write_hwaddr(const struct eth_device *dev)
{
	u32 da0, da1;

	da0 = (dev->enetaddr[0] << 24) + (dev->enetaddr[1] << 16) +
		(dev->enetaddr[2] << 8) + dev->enetaddr[3];
	da1 = (dev->enetaddr[4] << 24) + (dev->enetaddr[5] << 16);

	ltq_writel(&ltq_ppe_enet0_regs->mac_da0, da0);
	ltq_writel(&ltq_ppe_enet0_regs->mac_da1, da1);
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
	int i;

	ltq_eth_write_hwaddr(dev);

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

	ltq_dma_reset(dma_dev);
}

static int ltq_eth_send(struct eth_device *dev, void *packet, int length)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	int err;

	/* Minimum payload length w/ CRC is 60 bytes */
	if (length < 60)
		length = 60;

	err = ltq_dma_tx_map(dma_dev, priv->tx_num, packet, length, 10);
	if (err) {
		puts("NET: timeout on waiting for TX descriptor\n");
		return -1;
	}

	priv->tx_num = (priv->tx_num + 1) % LTQ_ETH_TX_BUFFER_CNT;

	return err;
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

static void ltq_eth_hw_init(const struct ltq_eth_port_config *port)
{
	u32 data;

	/* Power up ethernet subsystems */
	ltq_pm_enable(LTQ_PM_ETH);

	/* Reset ethernet subsystems */
	ltq_reset_once(LTQ_RESET_ETH, 1);

	/* Disable MDIO auto-detection */
	ltq_clrbits(&ltq_ppe_etop_regs->mdio_cfg, LTQ_PPE_ETOP_MDIO_CFG_UMM1 |
			LTQ_PPE_ETOP_MDIO_CFG_UMM0);

	/* Enable CRC generation, Full Duplex, 100Mbps, Link up */
	ltq_writel(&ltq_ppe_enet0_regs->mac_cfg, LTQ_PPE_ENET0_MAC_CFG_CGEN |
			LTQ_PPE_ENET0_MAC_CFG_DUPLEX |
			LTQ_PPE_ENET0_MAC_CFG_SPEED |
			LTQ_PPE_ENET0_MAC_CFG_LINK);

	/* Reset ETOP cfg and disable all */
	data = LTQ_PPE_ETOP_CFG_OFF0 | LTQ_PPE_ETOP_CFG_OFF1;

	/* Enable ENET0, enable store and fetch */
	data &= ~LTQ_PPE_ETOP_CFG_OFF0;
	data |= LTQ_PPE_ETOP_CFG_SEN0 | LTQ_PPE_ETOP_CFG_FEN0;

	if (port->phy_if == PHY_INTERFACE_MODE_RMII)
		data |= LTQ_PPE_ETOP_CFG_REMII0;
	else
		data &= ~LTQ_PPE_ETOP_CFG_REMII0;

	ltq_writel(&ltq_ppe_etop_regs->cfg, data);

	/* Set allowed packet length from 64 bytes to 1518 bytes */
	ltq_writel(&ltq_ppe_etop_regs->ig_plen_ctrl, (64 << 16) | 1518);

	/* Enable filter for unicast packets */
	ltq_setbits(&ltq_ppe_enet0_regs->ig_cfg, LTQ_PPE_ENETS0_CFG_FTUC);
}

int ltq_eth_initialize(const struct ltq_eth_board_config *board_config)
{
	struct eth_device *dev;
	struct mii_dev *bus;
	struct ltq_eth_priv *priv;
	struct ltq_dma_device *dma_dev;
	const struct ltq_eth_port_config *port = &board_config->ports[0];
	struct phy_device *phy;
	struct switch_device *sw;
	int ret;

	ltq_dma_init();
	ltq_eth_hw_init(port);

	dev = calloc(1, sizeof(*dev));
	if (!dev)
		return -1;

	priv = calloc(1, sizeof(*priv));
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
	bus->read = ltq_mdio_read;
	bus->write = ltq_mdio_write;
	bus->priv = priv;

	dma_dev = &priv->dma_dev;
	dma_dev->port = 0;
	dma_dev->rx_chan.chan_no = 6;
	dma_dev->rx_chan.class = 3;
	dma_dev->rx_chan.num_desc = LTQ_ETH_RX_BUFFER_CNT;
	dma_dev->rx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev->rx_burst_len = LTQ_DMA_BURST_2WORDS;
	dma_dev->tx_chan.chan_no = 7;
	dma_dev->tx_chan.class = 3;
	dma_dev->tx_chan.num_desc = LTQ_ETH_TX_BUFFER_CNT;
	dma_dev->tx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev->tx_burst_len = LTQ_DMA_BURST_2WORDS;

	priv->bus = bus;
	priv->dev = dev;

	ret = ltq_dma_register(dma_dev);
	if (ret)
		return ret;

	ret = mdio_register(bus);
	if (ret)
		return ret;

	ret = eth_register(dev);
	if (ret)
		return ret;

	if (port->flags & LTQ_ETH_PORT_SWITCH) {
		sw = switch_connect(bus);
		if (!sw)
			return -1;

		switch_setup(sw);
	}

	if (port->flags & LTQ_ETH_PORT_PHY) {
		phy = phy_connect(bus, port->phy_addr, dev, port->phy_if);
		if (!phy)
			return -1;

		phy_config(phy);
	}

	return 0;
}
