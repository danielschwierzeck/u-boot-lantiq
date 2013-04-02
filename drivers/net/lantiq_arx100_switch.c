/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011 Daniel Schwierzeck, daniel.schwierzeck@googlemail.com
 */
#define DEBUG
#include <common.h>
#include <malloc.h>
#include <netdev.h>
#include <miiphy.h>
#include <switch.h>
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

struct ltq_eth_priv {
	struct ltq_dma_device dma_dev;
	struct mii_dev *bus;
	struct eth_device *dev;
	int rx_num;
	int tx_num;
};

static struct ar9_switch_regs *switch_regs =
	(struct ar9_switch_regs *) CKSEG1ADDR(LTQ_SWITCH_BASE);

static int ltq_mdio_is_busy(void)
{
	u32 mdio_ctrl = ltq_readl(&switch_regs->mdio_ctrl);

	return mdio_ctrl & MDIO_CTRL_MBUSY;
}

static void ltq_mdio_poll(void)
{
	while (ltq_mdio_is_busy())
		cpu_relax();

	__udelay(1000);
}

static int ltq_mdio_read(struct mii_dev *bus, int phyad, int devad,
					int regad)
{
	u32 mdio_ctrl;
	int retval;

	mdio_ctrl = MDIO_CTRL_MBUSY | MDIO_CTRL_OP_READ |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

	ltq_mdio_poll();
	ltq_writel(&switch_regs->mdio_ctrl, mdio_ctrl);
	ltq_mdio_poll();
	retval = ltq_readl(&switch_regs->mdio_data);
	ltq_writel(&switch_regs->mdio_data, 0xFFFF);

	debug("%s: phyad %02x, regad %02x, val %02x\n", __func__, phyad, regad, retval);

	return retval;
}

static int ltq_mdio_write(struct mii_dev *bus, int phyad, int devad,
					int regad, u16 val)
{
	u32 mdio_ctrl;

	debug("%s: phyad %02x, regad %02x, val %02x\n", __func__, phyad, regad, val);

	mdio_ctrl = (val << MDIO_CTRL_WD_SHIFT) | MDIO_CTRL_MBUSY |
		MDIO_CTRL_OP_WRITE |
		((phyad << MDIO_CTRL_PHYAD_SHIFT) & MDIO_CTRL_PHYAD_MASK) |
		(regad & MDIO_CTRL_REGAD_MASK);

	ltq_mdio_poll();
	ltq_writel(&switch_regs->mdio_ctrl, mdio_ctrl);

	return 0;
}

static inline u8 *ltq_eth_rx_packet_align(int rx_num)
{
	u8 *packet = (u8 *) NetRxPackets[rx_num];

	return packet + LTQ_ETH_IP_ALIGN;
}

static int ltq_eth_init(struct eth_device *dev, bd_t *bis)
{
	struct ltq_eth_priv *priv = dev->priv;
	struct ltq_dma_device *dma_dev = &priv->dma_dev;
	int i;

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
	/* Power up ethernet subsystems */
	ltq_pm_enable(LTQ_PM_ETH);

	/* Reset ethernet subsystems */
#if 0
	ltq_reset_once(LTQ_RESET_ETH, 1);
#endif

	/* MII/MDIO */
	gpio_set_altfunc(42, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* MII/MDC */
	gpio_set_altfunc(43, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);

	build_check_ar9_registers();
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
