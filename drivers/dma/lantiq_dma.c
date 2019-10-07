// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#define DEBUG

#include <common.h>
#include <watchdog.h>
#include <memalign.h>
#include <asm/io.h>
#include <mach/dma.h>

#define DMA_BASE			0x16E00000

#define DMA_CTRL_PKTARB			(1 << 31)
#define DMA_CTRL_MBRSTARB		(1 << 30)
#define DMA_CTRL_MBRSTCNT_SHIFT		16
#define DMA_CTRL_MBRSTCNT_MASK		(0x3ff << DMA_CTRL_MBRSTCNT_SHIFT)
#define DMA_CTRL_DRB			(1 << 8)
#define DMA_CTRL_RESET			(1 << 0)

#define DMA_CPOLL_EN			(1 << 31)
#define DMA_CPOLL_CNT_SHIFT		4
#define DMA_CPOLL_CNT_MASK		(0xFFF << DMA_CPOLL_CNT_SHIFT)

#define DMA_CCTRL_TXWGT_SHIFT		16
#define DMA_CCTRL_TXWGT_MASK		(0x3 << DMA_CCTRL_TXWGT_SHIFT)
#define DMA_CCTRL_CLASS_SHIFT		9
#define DMA_CCTRL_CLASS_MASK		(0x3 << DMA_CCTRL_CLASS_SHIFT)
#define DMA_CCTRL_RST			(1 << 1)
#define DMA_CCTRL_ONOFF			(1 << 0)

#define DMA_PCTRL_TXBL_SHIFT		4
#define DMA_PCTRL_TXBL_2WORDS		(1 << DMA_PCTRL_TXBL_SHIFT)
#define DMA_PCTRL_TXBL_4WORDS		(2 << DMA_PCTRL_TXBL_SHIFT)
#define DMA_PCTRL_TXBL_8WORDS		(3 << DMA_PCTRL_TXBL_SHIFT)
#define DMA_PCTRL_RXBL_SHIFT		2
#define DMA_PCTRL_RXBL_2WORDS		(1 << DMA_PCTRL_RXBL_SHIFT)
#define DMA_PCTRL_RXBL_4WORDS		(2 << DMA_PCTRL_RXBL_SHIFT)
#define DMA_PCTRL_RXBL_8WORDS		(3 << DMA_PCTRL_RXBL_SHIFT)
#define DMA_PCTRL_TXENDI_SHIFT		10
#define DMA_PCTRL_TXENDI_MASK		(0x3 << DMA_PCTRL_TXENDI_SHIFT)
#define DMA_PCTRL_RXENDI_SHIFT		8
#define DMA_PCTRL_RXENDI_MASK		(0x3 << DMA_PCTRL_RXENDI_SHIFT)

#define DMA_DESC_OWN			(1 << 31)
#define DMA_DESC_C			(1 << 30)
#define DMA_DESC_SOP			(1 << 29)
#define DMA_DESC_EOP			(1 << 28)
#define DMA_DESC_TX_OFFSET(x)		((x & 0x1f) << 23)
#define DMA_DESC_RX_OFFSET(x)		((x & 0x3) << 23)
#define DMA_DESC_LENGTH(x)		(x & 0xffff)

#define CGU_BASE			0x16200000
#define CGU_CLKGCR1_A			0x124
#define CGU_CLKGCR1_A_DMA0		BIT(5)

#define DMA_DEBUG			1

#define ltq_dma_debug(dev, fmt, args...)	\
	debug_cond(DMA_DEBUG && dev->debug, fmt, ##args)

struct ltq_dma_regs {
	u32	clc;		/* Clock control */
	u32	rsvd0;
	u32	id;		/* Identification */
	u32	rsvd1;
	u32	ctrl;		/* Control */
	u32	cpoll;		/* Channel polling */
	u32	cs;		/* Channel select */
	u32	cctrl;		/* Channel control */
	u32	cdba;		/* Channel descriptor base address */
	u32	cdlen;		/* Channel descriptor length */
	u32	cis;		/* Channel interrupt status */
	u32	cie;		/* Channel interrupt enable */
	u32	cgbl;		/* Channel global buffer length */
	u32	cdptnrd;	/* Current descriptor pointer */
	u32	cdptnrd1;	/* Current descriptor pointer 1 */
	u32	rsvd2;
	u32	ps;		/* Port select */
	u32	pctrl;		/* Port control */
	u32	rsvd3[43];
	u32	irnen;		/* Interrupt node enable */
	u32	irncr;		/* Interrupt node control */
	u32	irnicr;		/* Interrupt capture */
};

static struct ltq_dma_regs *ltq_dma_regs =
	(struct ltq_dma_regs *) CKSEG1ADDR(DMA_BASE);

/* TODO: move to clock driver */
static inline void ltq_dma_clk_init(void)
{
	void *cgu_base = (void *)CKSEG1ADDR(CGU_BASE);

	setbits_32(cgu_base + CGU_CLKGCR1_A, CGU_CLKGCR1_A_DMA0);
}

static inline u32 ltq_virt_to_dma_addr(const void *addr)
{
	return CPHYSADDR(addr);
}

static inline int ltq_dma_burst_align(enum ltq_dma_burst_len burst_len)
{
	switch (burst_len) {
	case LTQ_DMA_BURST_2WORDS:
		return 2 * 4;
	case LTQ_DMA_BURST_4WORDS:
		return 4 * 4;
	case LTQ_DMA_BURST_8WORDS:
		return 8 * 4;
	}

	return 0;
}

static inline void ltq_dma_dcache_wb_inv(const void *ptr, size_t size)
{
	unsigned long addr = (unsigned long) ptr;

	flush_dcache_range(addr, addr + size);
}

static inline void ltq_dma_dcache_inv(const void *ptr, size_t size)
{
	unsigned long addr = (unsigned long) ptr;

	invalidate_dcache_range(addr, addr + size);
}

void ltq_dma_init(void)
{
	static int init = 0;

	if (init)
		return;

	init = 1;

	ltq_dma_clk_init();

	/* Reset DMA */
	setbits_32(&ltq_dma_regs->ctrl, DMA_CTRL_RESET);

	/* Enable polling for descriptor fetching for all channels */
	writel(DMA_CPOLL_EN | (4 << DMA_CPOLL_CNT_SHIFT),
		&ltq_dma_regs->cpoll);
}

static void ltq_dma_channel_reset(struct ltq_dma_channel *chan)
{
	writel(chan->chan_no, &ltq_dma_regs->cs);
	setbits_32(&ltq_dma_regs->cctrl, DMA_CCTRL_RST);
	memset(chan->mem_base, 0, chan->size);
	ltq_dma_dcache_wb_inv(chan->mem_base, chan->size);
}

static void ltq_dma_channel_enable(struct ltq_dma_channel *chan)
{
	writel(chan->chan_no, &ltq_dma_regs->cs);
	setbits_32(&ltq_dma_regs->cctrl, DMA_CCTRL_ONOFF);
}

static void ltq_dma_channel_disable(struct ltq_dma_channel *chan)
{
	writel(chan->chan_no, &ltq_dma_regs->cs);
	clrbits_32(&ltq_dma_regs->cctrl, DMA_CCTRL_ONOFF);
}

static void ltq_dma_port_init(struct ltq_dma_device *dev)
{
	u32 pctrl;

	pctrl = dev->tx_endian_swap << DMA_PCTRL_TXENDI_SHIFT;
	pctrl |= dev->rx_endian_swap << DMA_PCTRL_RXENDI_SHIFT;
	pctrl |= dev->tx_burst_len << DMA_PCTRL_TXBL_SHIFT;
	pctrl |= dev->rx_burst_len << DMA_PCTRL_RXBL_SHIFT;

	writel(dev->port, &ltq_dma_regs->ps);
	writel(pctrl, &ltq_dma_regs->pctrl);
}

static int ltq_dma_alloc_descriptors(struct ltq_dma_device *dev,
					struct ltq_dma_channel *chan)
{
	const size_t size = sizeof(struct ltq_dma_desc) * chan->num_desc;
#ifdef CONFIG_SPL_BUILD
	const size_t offset = 0x100 * chan->chan_no;

	chan->mem_base = (void *)(CONFIG_SYS_SDRAM_BASE + offset);
#else
	chan->mem_base = malloc_cache_aligned(size);
	if (!chan->mem_base)
		return 1;
#endif

	chan->size = size;
	memset(chan->mem_base, 0, chan->size);
	ltq_dma_dcache_wb_inv(chan->mem_base, chan->size);

	/* Align descriptor base to 8 bytes */
	chan->desc_base = (void *) CKSEG1ADDR(chan->mem_base);
	chan->dma_addr = ltq_virt_to_dma_addr(chan->mem_base);
	chan->dev = dev;

	ltq_dma_debug(dev, "DMA: mem_base %p, desc_base %p, size %u\n",
		chan->mem_base ,chan->desc_base, size);

	/* Configure hardware with location of descriptor list */
	writel(chan->chan_no, &ltq_dma_regs->cs);
	writel(chan->dma_addr, &ltq_dma_regs->cdba);
	writel(chan->num_desc, &ltq_dma_regs->cdlen);
	writel((3 << DMA_CCTRL_TXWGT_SHIFT) |
		(chan->class << DMA_CCTRL_CLASS_SHIFT), &ltq_dma_regs->cctrl);
	writel(DMA_CCTRL_RST, &ltq_dma_regs->cctrl);

	return 0;
}

static void ltq_dma_free_descriptors(struct ltq_dma_channel *chan)
{
	writel(chan->chan_no, &ltq_dma_regs->cs);
	writel(0, &ltq_dma_regs->cdba);
	writel(0, &ltq_dma_regs->cdlen);

	ltq_dma_channel_reset(chan);

#ifndef CONFIG_SPL_BUILD
	free(chan->mem_base);
#endif
}

int ltq_dma_register(struct ltq_dma_device *dev)
{
	int ret;

	ltq_dma_port_init(dev);

	ret = ltq_dma_alloc_descriptors(dev, &dev->rx_chan);
	if (ret)
		return ret;

	ret = ltq_dma_alloc_descriptors(dev, &dev->tx_chan);
	if (ret) {
		ltq_dma_free_descriptors(&dev->rx_chan);
		return ret;
	}

	return 0;
}

void ltq_dma_unregister(struct ltq_dma_device *dev)
{
	ltq_dma_free_descriptors(&dev->rx_chan);
	ltq_dma_free_descriptors(&dev->tx_chan);
}

void ltq_dma_reset(struct ltq_dma_device *dev)
{
	ltq_dma_channel_reset(&dev->rx_chan);
	ltq_dma_channel_reset(&dev->tx_chan);
}

void ltq_dma_enable(struct ltq_dma_device *dev)
{
	ltq_dma_channel_enable(&dev->rx_chan);
	ltq_dma_channel_enable(&dev->tx_chan);
}

void ltq_dma_disable(struct ltq_dma_device *dev)
{
	ltq_dma_channel_disable(&dev->rx_chan);
	ltq_dma_channel_disable(&dev->tx_chan);
}

int ltq_dma_rx_map(struct ltq_dma_device *dev, int index, void *data, int len)
{
	struct ltq_dma_channel *chan = &dev->rx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];
	u32 dma_addr = ltq_virt_to_dma_addr(data);
	unsigned int offset;

	offset = dma_addr % ltq_dma_burst_align(dev->rx_burst_len);

	ltq_dma_dcache_inv(data, len);

	ltq_dma_debug(dev, "%s: index %d, data %p, dma_addr %08x, offset %u, len %d\n",
		__func__, index, data, dma_addr, offset, len);

	desc->addr = dma_addr - offset;
	desc->ctl = DMA_DESC_OWN | DMA_DESC_RX_OFFSET(offset) |
			DMA_DESC_LENGTH(len);

	ltq_dma_debug(dev, "%s: index %d, desc %p, desc->ctl %08x\n",
		__func__, index, desc, desc->ctl);

	return 0;
}

int ltq_dma_rx_poll(struct ltq_dma_device *dev, int index)
{
	struct ltq_dma_channel *chan = &dev->rx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];

	ltq_dma_debug(dev, "%s: index %d, desc %p, desc->ctl %08x\n",
		__func__, index, desc, desc->ctl);

	if (desc->ctl & DMA_DESC_OWN)
		return 0;

	if (desc->ctl & DMA_DESC_C)
		return 1;

	return 0;
}

int ltq_dma_rx_length(struct ltq_dma_device *dev, int index)
{
	struct ltq_dma_channel *chan = &dev->rx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];

	return DMA_DESC_LENGTH(desc->ctl);
}

int ltq_dma_rx_wait(struct ltq_dma_device *dev, int index,
			unsigned long timeout)
{
	struct ltq_dma_channel *chan = &dev->rx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];
	unsigned long timebase = get_timer(0);

	while ((desc->ctl & (DMA_DESC_OWN | DMA_DESC_C)) != DMA_DESC_C) {
		WATCHDOG_RESET();

		if (get_timer(timebase) >= timeout) {
			ltq_dma_debug(dev, "%s: timeout: index %d, desc %p, desc->ctl %08x\n",
				__func__, index, desc, desc->ctl);
			return -ETIMEDOUT;
		}
	}

	return 0;
}

int ltq_dma_tx_map(struct ltq_dma_device *dev, int index, const void *data,
			int len, unsigned long timeout)
{
	struct ltq_dma_channel *chan = &dev->tx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];
	unsigned int offset;
	unsigned long timebase = get_timer(0);
	u32 dma_addr = ltq_virt_to_dma_addr(data);

	while (desc->ctl & DMA_DESC_OWN) {
		WATCHDOG_RESET();

		if (get_timer(timebase) >= timeout) {
			ltq_dma_debug(dev, "%s: timeout: index %d, desc %p, desc->ctl %08x\n",
				__func__, index, desc, desc->ctl);
			return -ETIMEDOUT;
		}
	}

	offset = dma_addr % ltq_dma_burst_align(dev->rx_burst_len);

	ltq_dma_debug(dev, "%s: index %d, desc %p, data %p, dma_addr %08x, offset %u, len %d\n",
		__func__, index, desc, data, dma_addr, offset, len);

	ltq_dma_dcache_wb_inv(data, len);

	desc->addr = dma_addr - offset;
	desc->ctl = DMA_DESC_OWN | DMA_DESC_SOP | DMA_DESC_EOP |
			DMA_DESC_TX_OFFSET(offset) | DMA_DESC_LENGTH(len);

	ltq_dma_debug(dev, "%s: index %d, desc %p, desc->ctl %08x\n",
		__func__, index, desc, desc->ctl);

	return 0;
}

int ltq_dma_tx_wait(struct ltq_dma_device *dev, int index,
			unsigned long timeout)
{
	struct ltq_dma_channel *chan = &dev->tx_chan;
	struct ltq_dma_desc *desc = &chan->desc_base[index];
	unsigned long timebase = get_timer(0);

	while ((desc->ctl & (DMA_DESC_OWN | DMA_DESC_C)) != DMA_DESC_C) {
		WATCHDOG_RESET();

		if (get_timer(timebase) >= timeout)
			return -ETIMEDOUT;
	}

	return 0;
}
