// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2012-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <serial.h>
#include <errno.h>
#include <clk.h>
#include <debug_uart.h>
#include <dm.h>

#define CLC_RMC_S		8
#define MCON_R			(1 << 15)
#define MCON_FDE		(1 << 9)
#define WHBSTATE_SETREN		(1 << 1)
#define WHBSTATE_CLRREN		(1 << 0)
#define RXFCON_RXFITL_S		8
#define RXFCON_RXFITL_M		(0x3F << RXFCON_RXFITL_S)
#define RXFCON_RXFITL_RXFFLU	(1 << 1)
#define RXFCON_RXFITL_RXFEN	(1 << 0)
#define TXFCON_TXFITL_S		8
#define TXFCON_TXFITL_M		(0x3F << TXFCON_TXFITL_S)
#define TXFCON_TXFITL_TXFFLU	(1 << 1)
#define TXFCON_TXFITL_TXFEN	(1 << 0)
#define FSTAT_TXFREE_S		24
#define FSTAT_TXFREE_M		(0x3F << FSTAT_TXFREE_S)
#define FSTAT_RXFREE_S		16
#define FSTAT_RXFREE_M		(0x3F << FSTAT_RXFREE_S)
#define FSTAT_TXFFL_S		8
#define FSTAT_TXFFL_M		(0x3F << FSTAT_TXFFL_S)
#define FSTAT_RXFFL_M		0x3F

#ifdef __BIG_ENDIAN
#define RBUF_OFFSET		3
#define TBUF_OFFSET		3
#else
#define RBUF_OFFSET		0
#define TBUF_OFFSET		0
#endif

struct xway_asc {
	u32	clc;
	u32	pisel;
	u32	id;
	u32	rsvd0;
	u32	mcon;
	u32	state;
	u32	whbstate;
	u32	rsvd1;
	u8	tbuf[4];
	u8	rbuf[4];
	u32	rsvd2[2];
	u32	abcon;
	u32	abstat;
	u32	whbabcon;
	u32	whbabstat;
	u32	rxfcon;
	u32	txfcon;
	u32	fstat;
	u32	rsvd3;
	u32	bg;
	u32	bg_timer;
	u32	fdv;
	u32	pmw;
	u32	modcon;
	u32	modstat;
};

struct xway_uart_priv {
	struct xway_asc *regs;
	struct clk asc_clk;
};

static unsigned int xway_uart_tx_free(struct xway_asc *regs)
{
	u32 fstat = readl(&regs->fstat);

	return (fstat & FSTAT_TXFREE_M) >> FSTAT_TXFREE_S;
}

static unsigned int xway_uart_tx_filled(struct xway_asc *regs)
{
	u32 fstat = readl(&regs->fstat);

	return (fstat & FSTAT_TXFFL_M) >> FSTAT_TXFFL_S;
}

static unsigned int xway_uart_rx_filled(struct xway_asc *regs)
{
	u32 fstat = readl(&regs->fstat);

	return fstat & FSTAT_RXFFL_M;
}

static unsigned long xway_uart_calc_divisor(unsigned long clk, int baudrate)
{
	unsigned long divisor;

	/*
	 *               uart_clk
	 * Baudrate = -------------
	 *            32 * (bg + 1)
	 */
	divisor = DIV_ROUND_CLOSEST(clk, 32 * baudrate);
	return divisor - 1;
}

static inline void xway_uart_init(struct xway_asc *regs)
{
	/* Set clock divider for normal run mode to 1 and enable module */
	writel(1 << CLC_RMC_S, &regs->clc);

	/* Reset MCON register */
	writel(0, &regs->mcon);

	/* Use Port A as receiver input */
	writel(0, &regs->pisel);

	/* Enable and flush RX/TX FIFOs */
	setbits_32(&regs->rxfcon, RXFCON_RXFITL_RXFFLU | RXFCON_RXFITL_RXFEN);
	setbits_32(&regs->txfcon, TXFCON_TXFITL_TXFFLU | TXFCON_TXFITL_TXFEN);

	/* Disable error flags, enable receiver */
	writel(WHBSTATE_SETREN, &regs->whbstate);
}

static void xway_uart_baud_init(struct xway_asc *regs, unsigned long bg)
{
	/* Disable baudrate generator */
	clrbits_32(&regs->mcon, MCON_R);

	writel(bg, &regs->bg);

	/* Enable baudrate generator */
	setbits_32(&regs->mcon, MCON_R);
}

static int xway_uart_setbrg(struct udevice *dev, int baudrate)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);
	unsigned long bg, asc_clk;

	asc_clk = clk_get_rate(&priv->asc_clk);
	bg = xway_uart_calc_divisor(asc_clk, baudrate);
	xway_uart_baud_init(priv->regs, bg);
	return 0;
}

static int xway_uart_getc(struct udevice *dev)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);

	if (!xway_uart_rx_filled(priv->regs))
		return -EAGAIN;

	return readb(&priv->regs->rbuf[RBUF_OFFSET]);
}

static int xway_uart_putc(struct udevice *dev, const char c)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);

	if (!xway_uart_tx_free(priv->regs))
		return -EAGAIN;

	writeb(c, &priv->regs->tbuf[TBUF_OFFSET]);
	return 0;
}

static int xway_uart_pending(struct udevice *dev, bool input)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);

	if (input)
		return xway_uart_tx_filled(priv->regs);
	else
		return xway_uart_rx_filled(priv->regs);
}

static int xway_uart_clear(struct udevice *dev)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);

	setbits_32(&priv->regs->rxfcon, RXFCON_RXFITL_RXFFLU);
	setbits_32(&priv->regs->txfcon, TXFCON_TXFITL_TXFFLU);
	return 0;
}

#ifdef CONFIG_DEBUG_UART_INTEL_XWAY
static void _debug_uart_init(void)
{
	struct xway_asc *regs = (struct xway_asc *)CONFIG_DEBUG_UART_BASE;
	unsigned long bg;

	xway_uart_init(regs);
	bg = xway_uart_calc_divisor(CONFIG_DEBUG_UART_CLOCK, CONFIG_BAUDRATE);
	xway_uart_baud_init(regs, bg);
}

static inline void _debug_uart_putc(int ch)
{
	struct xway_asc *regs = (struct xway_asc *)CONFIG_DEBUG_UART_BASE;

	while (!xway_uart_tx_free(regs))
		;

	writeb(ch, &regs->tbuf[TBUF_OFFSET]);
}

DEBUG_UART_FUNCS
#endif

static int xway_uart_probe(struct udevice *dev)
{
	struct xway_uart_priv *priv = dev_get_priv(dev);
	int err;

	priv->regs = dev_remap_addr(dev);

	err = clk_get_by_index(dev, 0, &priv->asc_clk);
	if (err < 0)
		return err;

	xway_uart_init(priv->regs);

	return 0;
}

static const struct udevice_id xway_uart_of_match[] = {
	{ .compatible = "intel,xway-uart" },
	{ /* sentinel */ }
};

static const struct dm_serial_ops xway_uart_ops = {
	.setbrg = xway_uart_setbrg,
	.getc = xway_uart_getc,
	.putc = xway_uart_putc,
	.pending = xway_uart_pending,
	.clear = xway_uart_clear,
};

U_BOOT_DRIVER(xway_serial) = {
	.name = "intel-xway-uart",
	.id = UCLASS_SERIAL,
	.of_match = xway_uart_of_match,
	.probe = xway_uart_probe,
	.priv_auto_alloc_size = sizeof(struct xway_uart_priv),
	.ops = &xway_uart_ops,
};
