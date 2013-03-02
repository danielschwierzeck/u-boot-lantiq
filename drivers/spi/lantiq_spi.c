/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <common.h>
#include <spi.h>
#include <malloc.h>
#include <watchdog.h>
#include <asm/gpio.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/pm.h>
#include <asm/arch/soc.h>

#define LTQ_SPI_CLC_RMC_SHIFT		8
#define LTQ_SPI_CLC_RMC_MASK		(0xFF << LTQ_SPI_CLC_RMC_SHIFT)
#define LTQ_SPI_CLC_DISS		(1 << 1)
#define LTQ_SPI_CLC_DISR		1

#define LTQ_SPI_ID_TXFS_SHIFT		24
#define LTQ_SPI_ID_TXFS_MASK		(0x3F << LTQ_SPI_ID_TXFS_SHIFT)
#define LTQ_SPI_ID_RXFS_SHIFT		16
#define LTQ_SPI_ID_RXFS_MASK		(0x3F << LTQ_SPI_ID_RXFS_SHIFT)

#define LTQ_SPI_CON_ENBV		(1 << 22)
#define LTQ_SPI_CON_BM_SHIFT		16
#define LTQ_SPI_CON_BM_MASK		(0x1F << LTQ_SPI_CON_BM_SHIFT)
#define LTQ_SPI_CON_LB			(1 << 7)
#define LTQ_SPI_CON_PO			(1 << 6)
#define LTQ_SPI_CON_PH			(1 << 5)
#define LTQ_SPI_CON_HB			(1 << 4)
#define LTQ_SPI_CON_RXOFF		(1 << 1)
#define LTQ_SPI_CON_TXOFF		1

#define LTQ_SPI_STAT_RXBV_SHIFT		28
#define LTQ_SPI_STAT_RXBV_MASK		(0x7 << LTQ_SPI_STAT_RXBV_SHIFT)
#define LTQ_SPI_STAT_BSY		(1 << 13)

#define LTQ_SPI_WHBSTATE_SETMS		(1 << 3)
#define LTQ_SPI_WHBSTATE_CLRMS		(1 << 2)
#define LTQ_SPI_WHBSTATE_SETEN		(1 << 1)
#define LTQ_SPI_WHBSTATE_CLREN		1

#define LTQ_SPI_TXFCON_TXFLU		(1 << 1)
#define LTQ_SPI_TXFCON_TXFEN		1

#define LTQ_SPI_RXFCON_RXFLU		(1 << 1)
#define LTQ_SPI_RXFCON_RXFEN		1

#define LTQ_SPI_FSTAT_RXFFL_MASK	0x3f
#define LTQ_SPI_FSTAT_TXFFL_SHIFT	8
#define LTQ_SPI_FSTAT_TXFFL_MASK	(0x3f << LTQ_SPI_FSTAT_TXFFL_SHIFT)

#define LTQ_SPI_RXREQ_RXCNT_MASK	0xFFFF
#define LTQ_SPI_RXCNT_TODO_MASK		0xFFFF

#define LTQ_SPI_GPIO_DIN		16
#define LTQ_SPI_GPIO_DOUT		17
#define LTQ_SPI_GPIO_CLK		18

struct ltq_spi_regs {
	u32	clc;		/* Clock control */
	u32	pisel;		/* Port input select */
	u32	id;		/* Identification */
	u32	rsvd0;
	u32	con;		/* Control */
	u32	stat;		/* Status */
	u32	whbstate;	/* Write HW modified state */
	u32	rsvd1;
	u32	tb;		/* Transmit buffer */
	u32	rb;		/* Receive buffer */
	u32	rsvd2[2];
	u32	rxfcon;		/* Recevie FIFO control */
	u32	txfcon;		/* Transmit FIFO control */
	u32	fstat;		/* FIFO status */
	u32	rsvd3;
	u32	brt;		/* Baudrate timer */
	u32	brstat;		/* Baudrate timer status */
	u32	rsvd4[6];
	u32	sfcon;		/* Serial frame control */
	u32	sfstat;		/* Serial frame status */
	u32	rsvd5[2];
	u32	gpocon;		/* General purpose output control */
	u32	gpostat;	/* General purpose output status */
	u32	fgpo;		/* Force general purpose output */
	u32	rsvd6;
	u32	rxreq;		/* Receive request */
	u32	rxcnt;		/* Receive count */
	u32	rsvd7[25];
	u32	dmacon;		/* DMA control */
};

struct ltq_spi_slave {
	struct spi_slave slave;
	unsigned int max_hz;
	unsigned int mode;
	unsigned int len;
	unsigned int brt;
	unsigned int tx_cnt;
	unsigned int rx_cnt;
	unsigned int rx_req;
	const u8 *tx;
	u8 *rx;
	u8 txfs;
	u8 rxfs;
};

static inline struct ltq_spi_slave *to_ltq_spi_slave(struct spi_slave *slave)
{
	return container_of(slave, struct ltq_spi_slave, slave);
}

#ifdef CONFIG_SPL_BUILD
/*
 * We do not have or want malloc in a SPI flash SPL.
 * Neither we have to support multiple SPI slaves. Thus we put the
 * SPI slave context in BSS for SPL builds.
 */
static struct ltq_spi_slave ltq_spi_slave;

static inline struct ltq_spi_slave *ltq_spi_slave_alloc(void)
{
	return &ltq_spi_slave;
}

static inline void ltq_spi_slave_free(struct spi_slave *slave)
{
}
#else
static inline struct ltq_spi_slave *ltq_spi_slave_alloc(void)
{
	return malloc(sizeof(struct ltq_spi_slave));
}

static inline void ltq_spi_slave_free(struct spi_slave *slave)
{
	struct ltq_spi_slave *sl;

	if (slave) {
		sl = to_ltq_spi_slave(slave);
		free(sl);
	}
}
#endif

static struct ltq_spi_regs *ltq_spi_regs =
	(struct ltq_spi_regs *) CKSEG1ADDR(LTQ_SPI_BASE);

void spi_init(void)
{
	/* Power up SPI subsystem */
	ltq_pm_enable(LTQ_PM_SPI);

	/* Enable module and set clock divider to 1 */
	ltq_writel(&ltq_spi_regs->clc, 1 << LTQ_SPI_CLC_RMC_SHIFT);

	/* SPI/DIN input */
	gpio_set_altfunc(16, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_IN);
	/* SPI/DOUT output */
	gpio_set_altfunc(17, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* SPI/CLK output */
	gpio_set_altfunc(18, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
}

static inline u32 ltq_spi_calc_br(unsigned int max_hz)
{
	u32 speed_hz, spi_hz;
	u16 brt;

	/* SPI module clock is same as FPI bus clock */
	spi_hz = ltq_get_bus_clock();

	/*
	 *                 f_SPI
	 * baudrate = --------------
	 *             2 * (BR + 1)
	 */
	spi_hz /= 2;

	for (brt = 0; brt < 0xFFFF; brt++) {
		speed_hz = spi_hz / (brt + 1);
		if (speed_hz <= max_hz)
			break;
	}

	return brt;
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
				  unsigned int max_hz, unsigned int mode)
{
	u32 id;
	struct ltq_spi_slave *sl;

	if (!spi_cs_is_valid(bus, cs))
		return NULL;

	sl = ltq_spi_slave_alloc();
	if (!sl)
		return NULL;

	/* Read HW capabilities */
	id = ltq_readl(&ltq_spi_regs->id);
	sl->txfs = (id & LTQ_SPI_ID_TXFS_MASK) >> LTQ_SPI_ID_TXFS_SHIFT;
	sl->rxfs = (id & LTQ_SPI_ID_RXFS_MASK) >> LTQ_SPI_ID_RXFS_SHIFT;

	sl->slave.bus = bus;
	sl->slave.cs = cs;
	sl->max_hz = max_hz;
	sl->mode = mode;

	sl->brt = ltq_spi_calc_br(max_hz);

	return &sl->slave;
}

void spi_free_slave(struct spi_slave *slave)
{
	ltq_spi_slave_free(slave);
}

static int ltq_spi_wait_ready(struct ltq_spi_slave *sl)
{
	u32 stat;
	const unsigned long timeout = 20000;
	unsigned long timebase;

	timebase = get_timer(0);

	do {
		WATCHDOG_RESET();

		stat = ltq_readl(&ltq_spi_regs->stat);

		if (!(stat & LTQ_SPI_STAT_BSY))
			return 0;
	} while (get_timer(timebase) < timeout);

	return 1;
}

int spi_claim_bus(struct spi_slave *slave)
{
	struct ltq_spi_slave *sl = to_ltq_spi_slave(slave);
	u32 con;
	int ret;

	/* Put module in configuration mode */
	ltq_setbits(&ltq_spi_regs->whbstate, LTQ_SPI_WHBSTATE_CLREN);

	/* Enable and flush RX and TX FIFOs */
	ltq_setbits(&ltq_spi_regs->txfcon,
			LTQ_SPI_TXFCON_TXFLU | LTQ_SPI_TXFCON_TXFEN);
	ltq_setbits(&ltq_spi_regs->rxfcon,
			LTQ_SPI_RXFCON_RXFLU | LTQ_SPI_RXFCON_RXFEN);

	ret = ltq_spi_wait_ready(sl);
	if (ret)
		return ret;

	/* Set baudrate */
	ltq_writel(&ltq_spi_regs->brt, sl->brt);

	/*
	 * Disable byte valid control (ENBV = 0) and
	 * set data width to 8 bit (BM = 7)
	 */
	con = (7 << LTQ_SPI_CON_BM_SHIFT);

	/* Disable transmitter and receiver */
	con |= (LTQ_SPI_CON_RXOFF | LTQ_SPI_CON_TXOFF);

	/* Set SPI mode
	 * Mapping: Mode CPOL CPHA CON.PO CON.PH
	 *            0    0    0      0      1
	 *            1    0    1      0      0
	 *            2    1    0      1      1
	 *            3    1    1      1      0
	 */
	if (sl->mode & SPI_CPHA)
		con &= ~LTQ_SPI_CON_PH;
	else
		con |= LTQ_SPI_CON_PH;

	if (sl->mode & SPI_CPOL)
		con |= LTQ_SPI_CON_PO;
	else
		con &= ~LTQ_SPI_CON_PO;

	/* Set heading control */
	if (sl->mode & SPI_LSB_FIRST)
		con &= ~LTQ_SPI_CON_HB;
	else
		con |= LTQ_SPI_CON_HB;

	/* Set loopback control */
	if (sl->mode & SPI_LOOP)
		con |= LTQ_SPI_CON_LB;
	else
		con &= ~LTQ_SPI_CON_LB;

	ltq_writel(&ltq_spi_regs->con, con);

	/* Set SPI master mode and enable SPI */
	ltq_setbits(&ltq_spi_regs->whbstate,
			LTQ_SPI_WHBSTATE_SETEN | LTQ_SPI_WHBSTATE_SETMS);

	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	/* Put module in configuration mode */
	ltq_setbits(&ltq_spi_regs->whbstate, LTQ_SPI_WHBSTATE_CLREN);

	/* Flush RX and TX FIFOs */
	ltq_setbits(&ltq_spi_regs->txfcon, LTQ_SPI_TXFCON_TXFLU);
	ltq_setbits(&ltq_spi_regs->rxfcon, LTQ_SPI_RXFCON_RXFLU);
}

static inline void ltq_spi_txfifo_write(struct ltq_spi_slave *sl)
{
	u32 fstat, tb;
	u16 fifo_space;

	fstat = ltq_readl(&ltq_spi_regs->fstat);
	fifo_space = sl->txfs - ((fstat & LTQ_SPI_FSTAT_TXFFL_MASK) >>
			LTQ_SPI_FSTAT_TXFFL_SHIFT);

	while (sl->tx_cnt < sl->len && fifo_space) {
		tb = *sl->tx++;
		ltq_writel(&ltq_spi_regs->tb, tb);
		fifo_space--;
		sl->tx_cnt++;
	}
}

static inline void ltq_spi_rx_request(struct ltq_spi_slave *sl)
{
	u32 rxreq, rxreq_max;

	/*
	 * In RX-only mode the serial clock is activated only after writing
	 * the expected amount of RX bytes into RXREQ register.
	 * To avoid receive overflows at high clocks it is better to request
	 * only the amount of bytes that fits into all FIFOs. This value
	 * depends on the FIFO size implemented in hardware.
	 */
	rxreq = sl->len - sl->rx_cnt;
	rxreq_max = sl->rxfs << 2;
	rxreq = min(rxreq_max, rxreq);

	if (!sl->rx_req && rxreq && sl->rx_cnt < sl->len) {
		ltq_writel(&ltq_spi_regs->rxreq, rxreq);
		sl->rx_req = rxreq;
	}
}

static void ltq_spi_rxfifo_read(struct ltq_spi_slave *sl)
{
	u32 fstat, data, *rx32;
	u16 fifo_fill;
	u8 rxbv, shift, *rx8;

	/* Determine how much FIFOs are filled with RX data */
	fstat = ltq_readl(&ltq_spi_regs->fstat);
	fifo_fill = fstat & LTQ_SPI_FSTAT_RXFFL_MASK;

	/*
	 * The 32 bit FIFO is always used completely independent from the
	 * bits_per_word value. Thus four bytes have to be read at once
	 * per FIFO.
	 */
	rx32 = (u32 *) sl->rx;
	while (sl->len - sl->rx_cnt >= 4 && fifo_fill) {
		data = ltq_readl(&ltq_spi_regs->rb);
		*rx32++ = data;
		sl->rx_cnt += 4;
		sl->rx_req -= 4;
		sl->rx += 4;
		fifo_fill--;
	}

	/*
	 * If there are remaining bytes, read byte count from STAT.RXBV
	 * register and read the data byte-wise.
	 */
	while (fifo_fill && sl->rx_cnt < sl->len) {
		fstat = ltq_readl(&ltq_spi_regs->stat);
		rxbv = (fstat & LTQ_SPI_STAT_RXBV_MASK) >>
			LTQ_SPI_STAT_RXBV_SHIFT;

		if (!rxbv)
			break;

		data = ltq_readl(&ltq_spi_regs->rb);

		shift = (rxbv - 1) * 8;
		rx8 = sl->rx;

		while (rxbv) {
			*rx8++ = (data >> shift) & 0xFF;
			rxbv--;
			shift -= 8;
			sl->rx_cnt++;
			sl->rx_req--;
			sl->rx++;
		}

		fifo_fill--;
	}
}

int spi_xfer(struct spi_slave *slave, unsigned int bitlen,
	     const void *dout, void *din, unsigned long flags)
{
	struct ltq_spi_slave *sl = to_ltq_spi_slave(slave);
	int ret;

	if (bitlen % 8)
		return 1;

	if (!bitlen) {
		ret = 0;
		goto done;
	}

	sl->len = bitlen / 8;
	sl->tx = dout;
	sl->rx = din;
	sl->tx_cnt = 0;
	sl->rx_cnt = 0;
	sl->rx_req = 0;

	if (flags & SPI_XFER_BEGIN)
		spi_cs_activate(slave);

	/* Enable transmitter */
	if (sl->tx)
		ltq_clrbits(&ltq_spi_regs->con, LTQ_SPI_CON_TXOFF);

	/* Enable receiver */
	if (sl->rx)
		ltq_clrbits(&ltq_spi_regs->con, LTQ_SPI_CON_RXOFF);

	if (sl->tx)
		ltq_spi_txfifo_write(sl);
	else if (sl->rx)
		ltq_spi_rx_request(sl);

	while (sl->tx_cnt != sl->len && sl->rx_cnt != sl->len) {
		if (sl->rx) {
			ltq_spi_rxfifo_read(sl);

			if (sl->tx)
				ltq_spi_txfifo_write(sl);
			else
				ltq_spi_rx_request(sl);
		} else if (sl->tx)
			ltq_spi_txfifo_write(sl);
	}

	ret = ltq_spi_wait_ready(sl);

done:
	/* Disable transmitter and receiver */
	ltq_setbits(&ltq_spi_regs->con, LTQ_SPI_CON_TXOFF | LTQ_SPI_CON_RXOFF);

	if (flags & SPI_XFER_END)
		spi_cs_deactivate(slave);

	return ret;
}
