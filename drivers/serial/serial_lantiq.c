/*
 * Copyright (C) 2010 Thomas Langer <thomas.langer@lantiq.com>
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <serial.h>
#include <asm/errno.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/io.h>

#if CONFIG_CONSOLE_ASC == 0
#define LTQ_ASC_BASE			LTQ_ASC0_BASE
#else
#define LTQ_ASC_BASE			LTQ_ASC1_BASE
#endif

#define LTQ_ASC_ID_TXFS_SHIFT		24
#define LTQ_ASC_ID_TXFS_MASK		(0x3F << LTQ_ASC_ID_TXFS_SHIFT)
#define LTQ_ASC_ID_RXFS_SHIFT		16
#define LTQ_ASC_ID_RXFS_MASK		(0x3F << LTQ_ASC_ID_RXFS_SHIFT)

#define LTQ_ASC_MCON_R			(1 << 15)
#define LTQ_ASC_MCON_FDE		(1 << 9)

#define LTQ_ASC_WHBSTATE_SETREN		(1 << 1)
#define LTQ_ASC_WHBSTATE_CLRREN		(1 << 0)

#define LTQ_ASC_RXFCON_RXFITL_SHIFT	8
#define LTQ_ASC_RXFCON_RXFITL_MASK	(0x3F << LTQ_ASC_RXFCON_RXFITL_SHIFT)
#define LTQ_ASC_RXFCON_RXFITL_RXFFLU	(1 << 1)
#define LTQ_ASC_RXFCON_RXFITL_RXFEN	(1 << 0)

#define LTQ_ASC_TXFCON_TXFITL_SHIFT	8
#define LTQ_ASC_TXFCON_TXFITL_MASK	(0x3F << LTQ_ASC_TXFCON_TXFITL_SHIFT)
#define LTQ_ASC_TXFCON_TXFITL_TXFFLU	(1 << 1)
#define LTQ_ASC_TXFCON_TXFITL_TXFEN	(1 << 0)

#define LTQ_ASC_FSTAT_TXFREE_SHIFT	24
#define LTQ_ASC_FSTAT_TXFREE_MASK	(0x3F << LTQ_ASC_FSTAT_TXFREE_SHIFT)
#define LTQ_ASC_FSTAT_RXFREE_SHIFT	16
#define LTQ_ASC_FSTAT_RXFREE_MASK	(0x3F << LTQ_ASC_FSTAT_RXFREE_SHIFT)
#define LTQ_ASC_FSTAT_TXFFL_SHIFT	8
#define LTQ_ASC_FSTAT_TXFFL_MASK	(0x3F << LTQ_ASC_FSTAT_TXFFL_SHIFT)
#define LTQ_ASC_FSTAT_RXFFL_MASK	0x3F

#ifdef __BIG_ENDIAN
#define LTQ_ASC_RBUF_OFFSET		3
#define LTQ_ASC_TBUF_OFFSET		3
#else
#define LTQ_ASC_RBUF_OFFSET		0
#define LTQ_ASC_TBUF_OFFSET		0
#endif

struct ltq_asc_regs {
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

DECLARE_GLOBAL_DATA_PTR;

static struct ltq_asc_regs *ltq_asc_regs =
	(struct ltq_asc_regs *) CKSEG1ADDR(LTQ_ASC_BASE);

static int ltq_serial_init(void)
{
	/* Set clock divider for normal run mode to 1 and enable module */
	ltq_writel(&ltq_asc_regs->clc, 0x100);

	/* Reset MCON register */
	ltq_writel(&ltq_asc_regs->mcon, 0);

	/* Use Port A as receiver input */
	ltq_writel(&ltq_asc_regs->pisel, 0);

	/* Enable and flush RX/TX FIFOs */
	ltq_setbits(&ltq_asc_regs->rxfcon,
		LTQ_ASC_RXFCON_RXFITL_RXFFLU | LTQ_ASC_RXFCON_RXFITL_RXFEN);
	ltq_setbits(&ltq_asc_regs->txfcon,
		LTQ_ASC_TXFCON_TXFITL_TXFFLU | LTQ_ASC_TXFCON_TXFITL_TXFEN);

	serial_setbrg();

	/* Disable error flags, enable receiver */
	ltq_writel(&ltq_asc_regs->whbstate, LTQ_ASC_WHBSTATE_SETREN);

	return 0;
}

/*
 *             fdv       asc_clk
 * Baudrate = ----- * -------------
 *             512    16 * (bg + 1)
 */
static void ltq_serial_calc_br_fdv(unsigned long asc_clk,
					unsigned long baudrate, u16 *fdv,
					u16 *bg)
{
	const u32 c = asc_clk / (16 * 512);
	u32 diff1, diff2;
	u32 bg_calc, br_calc, i;

	diff1 = baudrate;
	for (i = 512; i > 0; i--) {
		/* Calc bg for current fdv value */
		bg_calc = i * c / baudrate;

		/* Impossible baudrate */
		if (!bg_calc)
			return;

		/*
		 * Calc diff to target baudrate dependent on current
		 * bg and fdv values
		 */
		br_calc = i * c / bg_calc;
		if (br_calc > baudrate)
			diff2 = br_calc - baudrate;
		else
			diff2 = baudrate - br_calc;

		/* Perfect values found */
		if (diff2 == 0) {
			*fdv = i;
			*bg = bg_calc - 1;
			return;
		}

		if (diff2 < diff1) {
			*fdv = i;
			*bg = bg_calc - 1;
			diff1 = diff2;
		}
	}
}

static void ltq_serial_setbrg(void)
{
	unsigned long asc_clk, baudrate;
	u16 bg = 0;
	u16 fdv = 511;

	/* ASC clock is same as FPI clock with CLC.RMS = 1 */
	asc_clk = ltq_get_bus_clock();
	baudrate = gd->baudrate;

	/* Calculate FDV and BG values */
	ltq_serial_calc_br_fdv(asc_clk, baudrate, &fdv, &bg);

	/* Disable baudrate generator */
	ltq_clrbits(&ltq_asc_regs->mcon, LTQ_ASC_MCON_R);

	/* Enable fractional divider */
	ltq_setbits(&ltq_asc_regs->mcon, LTQ_ASC_MCON_FDE);

	/* Set fdv and bg values */
	ltq_writel(&ltq_asc_regs->fdv, fdv);
	ltq_writel(&ltq_asc_regs->bg, bg);

	/* Enable baudrate generator */
	ltq_setbits(&ltq_asc_regs->mcon, LTQ_ASC_MCON_R);
}

static unsigned int ltq_serial_tx_free(void)
{
	unsigned int txfree;

	txfree = (ltq_readl(&ltq_asc_regs->fstat) &
			LTQ_ASC_FSTAT_TXFREE_MASK) >>
			LTQ_ASC_FSTAT_TXFREE_SHIFT;

	return txfree;
}

static unsigned int ltq_serial_rx_fill(void)
{
	unsigned int rxffl;

	rxffl = ltq_readl(&ltq_asc_regs->fstat) & LTQ_ASC_FSTAT_RXFFL_MASK;

	return rxffl;
}

static void ltq_serial_tx(const char c)
{
	ltq_writeb(&ltq_asc_regs->tbuf[LTQ_ASC_TBUF_OFFSET], c);
}

static u8 ltq_serial_rx(void)
{
	return ltq_readb(&ltq_asc_regs->rbuf[LTQ_ASC_RBUF_OFFSET]);
}

static void ltq_serial_putc(const char c)
{
	if (c == '\n')
		ltq_serial_putc('\r');

	while (!ltq_serial_tx_free())
		;

	ltq_serial_tx(c);
}

static int ltq_serial_getc(void)
{
	while (!ltq_serial_rx_fill())
		;

	return ltq_serial_rx();
}

static int ltq_serial_tstc(void)
{
	return (0 != ltq_serial_rx_fill());
}

static struct serial_device ltq_serial_drv = {
	.name	= "ltq_serial",
	.start	= ltq_serial_init,
	.stop	= NULL,
	.setbrg	= ltq_serial_setbrg,
	.putc	= ltq_serial_putc,
	.puts	= default_serial_puts,
	.getc	= ltq_serial_getc,
	.tstc	= ltq_serial_tstc,
};

void ltq_serial_initialize(void)
{
	serial_register(&ltq_serial_drv);
}

__weak struct serial_device *default_serial_console(void)
{
	return &ltq_serial_drv;
}
