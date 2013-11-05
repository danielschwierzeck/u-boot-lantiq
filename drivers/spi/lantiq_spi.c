/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
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
#define LTQ_SPI_CON_IDLE		(1 << 23)
#define LTQ_SPI_CON_RUEN		(1 << 12)
#define LTQ_SPI_CON_AEN			(1 << 10)
#define LTQ_SPI_CON_REN			(1 << 9)
#define LTQ_SPI_CON_TEN			(1 << 8)
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
#define LTQ_SPI_WHBSTATE_CLR_ERRORS	0x0F50

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
	__be32	clc;		/* Clock control */
	__be32	pisel;		/* Port input select */
	__be32	id;		/* Identification */
	__be32	rsvd0;
	__be32	con;		/* Control */
	__be32	stat;		/* Status */
	__be32	whbstate;	/* Write HW modified state */
	__be32	rsvd1;
	__be32	tb;		/* Transmit buffer */
	__be32	rb;		/* Receive buffer */
	__be32	rsvd2[2];
	__be32	rxfcon;		/* Recevie FIFO control */
	__be32	txfcon;		/* Transmit FIFO control */
	__be32	fstat;		/* FIFO status */
	__be32	rsvd3;
	__be32	brt;		/* Baudrate timer */
	__be32	brstat;		/* Baudrate timer status */
	__be32	rsvd4[6];
	__be32	sfcon;		/* Serial frame control */
	__be32	sfstat;		/* Serial frame status */
	__be32	rsvd5[2];
	__be32	gpocon;		/* General purpose output control */
	__be32	gpostat;	/* General purpose output status */
	__be32	fgpo;		/* Force general purpose output */
	__be32	rsvd6;
	__be32	rxreq;		/* Receive request */
	__be32	rxcnt;		/* Receive count */
	__be32	rsvd7[25];
	__be32	dmacon;		/* DMA control */
	__be32	rsvd8;
	__be32	irnen;		/* Interrupt node enable */
	__be32	irnicr;		/* Interrupt node interrupt capture */
	__be32	irncr;		/* Interrupt node control */
};

struct ltq_spi_drv_data {
	struct ltq_spi_regs __iomem *regs;

	struct spi_slave slave;
	unsigned int max_hz;
	unsigned int mode;
	unsigned int tx_todo;
	unsigned int rx_todo;
	unsigned int rx_req;
	unsigned int bits_per_word;
	unsigned int speed_hz;
	const u8 *tx;
	u8 *rx;
	int status;
};

static struct ltq_spi_drv_data *to_ltq_spi_slave(struct spi_slave *slave)
{
	return container_of(slave, struct ltq_spi_drv_data, slave);
}

#ifdef CONFIG_SPL_BUILD
/*
 * We do not have or want malloc in a SPI flash SPL.
 * Neither we have to support multiple SPI slaves. Thus we put the
 * SPI slave context in BSS for SPL builds.
 */
static struct ltq_spi_drv_data ltq_spi_slave;

static struct ltq_spi_drv_data *ltq_spi_slave_alloc(unsigned int bus,
							unsigned int cs)
{
	ltq_spi_slave.slave.bus = bus;
	ltq_spi_slave.slave.cs = cs;

	return &ltq_spi_slave;
}

static void ltq_spi_slave_free(struct spi_slave *slave)
{
}
#else
static struct ltq_spi_drv_data *ltq_spi_slave_alloc(unsigned int bus,
							unsigned int cs)
{
	return spi_alloc_slave(struct ltq_spi_drv_data, bus, cs);
}

static void ltq_spi_slave_free(struct spi_slave *slave)
{
	struct ltq_spi_drv_data *drv;

	if (slave) {
		drv = to_ltq_spi_slave(slave);
		free(drv);
	}
}
#endif

static unsigned int tx_fifo_size(struct ltq_spi_drv_data *drv)
{
	u32 id = ltq_readl(&drv->regs->id);

	return (id & LTQ_SPI_ID_TXFS_MASK) >> LTQ_SPI_ID_TXFS_SHIFT;
}

static unsigned int rx_fifo_size(struct ltq_spi_drv_data *drv)
{
	u32 id = ltq_readl(&drv->regs->id);

	return (id & LTQ_SPI_ID_RXFS_MASK) >> LTQ_SPI_ID_RXFS_SHIFT;
}

static unsigned int tx_fifo_level(struct ltq_spi_drv_data *drv)
{
	u32 fstat = ltq_readl(&drv->regs->fstat);

	return (fstat & LTQ_SPI_FSTAT_TXFFL_MASK) >> LTQ_SPI_FSTAT_TXFFL_SHIFT;
}

static unsigned int rx_fifo_level(struct ltq_spi_drv_data *drv)
{
	u32 fstat = ltq_readl(&drv->regs->fstat);

	return fstat & LTQ_SPI_FSTAT_RXFFL_MASK;
}

static unsigned int tx_fifo_free(struct ltq_spi_drv_data *drv)
{
	return tx_fifo_size(drv) - tx_fifo_level(drv);
}

static void hw_power_on(struct ltq_spi_drv_data *drv)
{
	u32 clc;

	/* Power-up mdule */
	ltq_pm_enable(LTQ_PM_SPI);

	/*
	 * Set clock divider for run mode to 1 to
	 * run at same frequency as FPI bus
	 */
	clc = (1 << LTQ_SPI_CLC_RMC_SHIFT);
	ltq_writel(&drv->regs->clc, clc);
}

static void hw_reset_fifos(struct ltq_spi_drv_data *drv)
{
	u32 val;

	val = LTQ_SPI_TXFCON_TXFEN | LTQ_SPI_TXFCON_TXFLU;
	ltq_writel(&drv->regs->txfcon, val);

	val = LTQ_SPI_RXFCON_RXFEN | LTQ_SPI_RXFCON_RXFLU;
	ltq_writel(&drv->regs->rxfcon, val);
}

static int hw_is_busy(struct ltq_spi_drv_data *drv)
{
	u32 stat = ltq_readl(&drv->regs->stat);

	return stat & LTQ_SPI_STAT_BSY;
}

static void hw_enter_config_mode(struct ltq_spi_drv_data *drv)
{
	ltq_writel(&drv->regs->whbstate, LTQ_SPI_WHBSTATE_CLREN);
}

static void hw_enter_active_mode(struct ltq_spi_drv_data *drv)
{
	ltq_writel(&drv->regs->whbstate, LTQ_SPI_WHBSTATE_SETEN);
}

static void hw_setup_speed_hz(struct ltq_spi_drv_data *drv,
				unsigned int max_speed_hz)
{
	unsigned int spi_hz, speed_hz, brt;

	/*
	 * SPI module clock is derived from FPI bus clock dependent on
	 * divider value in CLC.RMS which is always set to 1.
	 *
	 *                 f_SPI
	 * baudrate = --------------
	 *             2 * (BR + 1)
	 */
	spi_hz = ltq_get_bus_clock() / 2;

	/* TODO: optimize baudrate calculation */
	for (brt = 0; brt < 0xFFFF; brt++) {
		speed_hz = spi_hz / (brt + 1);
		if (speed_hz <= max_speed_hz)
			break;
	}

	ltq_writel(&drv->regs->brt, brt);
}

static void hw_setup_bits_per_word(struct ltq_spi_drv_data *drv,
					unsigned int bits_per_word)
{
	u32 bm;

	/* CON.BM value = bits_per_word - 1 */
	bm = (bits_per_word - 1) << LTQ_SPI_CON_BM_SHIFT;

	ltq_clrsetbits(&drv->regs->con, LTQ_SPI_CON_BM_MASK, bm);
}

static void hw_setup_clock_mode(struct ltq_spi_drv_data *drv, unsigned int mode)
{
	u32 con_set = 0, con_clr = 0;

	/*
	 * SPI mode mapping in CON register:
	 * Mode CPOL CPHA CON.PO CON.PH
	 *  0    0    0      0      1
	 *  1    0    1      0      0
	 *  2    1    0      1      1
	 *  3    1    1      1      0
	 */
	if (mode & SPI_CPHA)
		con_clr |= LTQ_SPI_CON_PH;
	else
		con_set |= LTQ_SPI_CON_PH;

	if (mode & SPI_CPOL)
		con_set |= LTQ_SPI_CON_PO | LTQ_SPI_CON_IDLE;
	else
		con_clr |= LTQ_SPI_CON_PO | LTQ_SPI_CON_IDLE;

	/* Set heading control */
	if (mode & SPI_LSB_FIRST)
		con_clr |= LTQ_SPI_CON_HB;
	else
		con_set |= LTQ_SPI_CON_HB;

	/* Set loopback mode */
	if (mode & SPI_LOOP)
		con_set |= LTQ_SPI_CON_LB;
	else
		con_clr |= LTQ_SPI_CON_LB;

	ltq_clrsetbits(&drv->regs->con, con_clr, con_set);
}

static void hw_set_rxtx(struct ltq_spi_drv_data *drv)
{
	u32 con;

	/* Configure transmitter and receiver */
	con = ltq_readl(&drv->regs->con);
	if (drv->tx)
		con &= ~LTQ_SPI_CON_TXOFF;
	else
		con |= LTQ_SPI_CON_TXOFF;

	if (drv->rx)
		con &= ~LTQ_SPI_CON_RXOFF;
	else
		con |= LTQ_SPI_CON_RXOFF;

	ltq_writel(&drv->regs->con, con);
}

static void hw_init(struct ltq_spi_drv_data *drv)
{
	hw_power_on(drv);

	/* Put controller into config mode */
	hw_enter_config_mode(drv);

	/* Disable all interrupts */
	ltq_writel(&drv->regs->irnen, 0);

	/* Clear error flags */
	ltq_clrsetbits(&drv->regs->whbstate, 0, LTQ_SPI_WHBSTATE_CLR_ERRORS);

	/* Enable error checking, disable TX/RX */
	ltq_writel(&drv->regs->con, LTQ_SPI_CON_RUEN | LTQ_SPI_CON_AEN |
			LTQ_SPI_CON_TEN | LTQ_SPI_CON_REN | LTQ_SPI_CON_TXOFF |
			LTQ_SPI_CON_RXOFF);

	/* Setup default SPI mode */
	drv->bits_per_word = 8;
	drv->speed_hz = 0;
	hw_setup_bits_per_word(drv, drv->bits_per_word);
	hw_setup_clock_mode(drv, SPI_MODE_0);

	/* Enable master mode and clear error flags */
	ltq_writel(&drv->regs->whbstate, LTQ_SPI_WHBSTATE_SETMS |
			LTQ_SPI_WHBSTATE_CLR_ERRORS);

	/* Reset GPIO/CS registers */
	ltq_writel(&drv->regs->gpocon, 0);
	ltq_writel(&drv->regs->fgpo, 0xFF00);

	/* Enable and flush FIFOs */
	hw_reset_fifos(drv);

	/* SPI/DIN input */
	gpio_set_altfunc(16, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_IN);
	/* SPI/DOUT output */
	gpio_set_altfunc(17, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
	/* SPI/CLK output */
	gpio_set_altfunc(18, GPIO_ALTSEL_SET, GPIO_ALTSEL_CLR, GPIO_DIR_OUT);
}

static void tx_fifo_write(struct ltq_spi_drv_data *drv)
{
	const u8 *tx8;
	const u16 *tx16;
	const u32 *tx32;
	u32 data;
	unsigned int tx_free = tx_fifo_free(drv);

	while (drv->tx_todo && tx_free) {
		switch (drv->bits_per_word) {
		case 8:
			tx8 = drv->tx;
			data = *tx8;
			drv->tx_todo--;
			drv->tx++;
			break;
		case 16:
			tx16 = (u16 *) drv->tx;
			data = *tx16;
			drv->tx_todo -= 2;
			drv->tx += 2;
			break;
		case 32:
			tx32 = (u32 *) drv->tx;
			data = *tx32;
			drv->tx_todo -= 4;
			drv->tx += 4;
			break;
		default:
			return;
		}

		ltq_writel(&drv->regs->tb, data);
		tx_free--;
	}
}

static void rx_fifo_read_full_duplex(struct ltq_spi_drv_data *drv)
{
	u8 *rx8;
	u16 *rx16;
	u32 *rx32;
	u32 data;
	unsigned int rx_fill = rx_fifo_level(drv);

	while (rx_fill) {
		data = ltq_readl(&drv->regs->rb);

		switch (drv->bits_per_word) {
		case 8:
			rx8 = drv->rx;
			*rx8 = data;
			drv->rx_todo--;
			drv->rx++;
			break;
		case 16:
			rx16 = (u16 *) drv->rx;
			*rx16 = data;
			drv->rx_todo -= 2;
			drv->rx += 2;
			break;
		case 32:
			rx32 = (u32 *) drv->rx;
			*rx32 = data;
			drv->rx_todo -= 4;
			drv->rx += 4;
			break;
		default:
			return;
		}

		rx_fill--;
	}
}

static void rx_fifo_read_half_duplex(struct ltq_spi_drv_data *drv)
{
	u32 data, *rx32;
	u8 *rx8;
	unsigned int rxbv, shift;
	unsigned int rx_fill = rx_fifo_level(drv);

	/*
	 * In RX-only mode the bits per word value is ignored by HW. A value
	 * of 32 is used instead. Thus all 4 bytes per FIFO must be read.
	 * If remaining RX bytes are less than 4, the FIFO must be read
	 * differently. The amount of received and valid bytes is indicated
	 * by STAT.RXBV register value.
	 */
	while (rx_fill) {
		if (drv->rx_todo < 4) {
			rxbv = (ltq_readl(&drv->regs->stat) &
				LTQ_SPI_STAT_RXBV_MASK) >>
				LTQ_SPI_STAT_RXBV_SHIFT;
			data = ltq_readl(&drv->regs->rb);

			shift = (rxbv - 1) * 8;
			rx8 = drv->rx;

			while (rxbv) {
				*rx8++ = (data >> shift) & 0xFF;
				rxbv--;
				shift -= 8;
				drv->rx_todo--;
				drv->rx++;

				if (drv->rx_req)
					drv->rx_req --;
			}
		} else {
			data = ltq_readl(&drv->regs->rb);
			rx32 = (u32 *) drv->rx;

			*rx32++ = data;
			drv->rx_todo -= 4;
			drv->rx += 4;

			if (drv->rx_req >= 4)
				drv->rx_req -= 4;
		}
		rx_fill--;
	}
}

static void rx_request(struct ltq_spi_drv_data *drv)
{
	unsigned int rxreq, rxreq_max;

	if (drv->rx_req)
		return;

	/*
	 * To avoid receive overflows at high clocks it is better to request
	 * only the amount of bytes that fits into all FIFOs. This value
	 * depends on the FIFO size implemented in hardware.
	 */
	rxreq = drv->rx_todo;
	rxreq_max = rx_fifo_size(drv) * 4;
	if (rxreq > rxreq_max)
		rxreq = rxreq_max;

	drv->rx_req = rxreq;
	ltq_writel(&drv->regs->rxreq, rxreq);
}

void spi_init(void)
{
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
				  unsigned int max_hz, unsigned int mode)
{
	struct ltq_spi_drv_data *drv;

	if (!spi_cs_is_valid(bus, cs))
		return NULL;

	drv = ltq_spi_slave_alloc(bus, cs);
	if (!drv)
		return NULL;

	drv->regs = (struct ltq_spi_regs *) CKSEG1ADDR(LTQ_SPI_BASE);

	hw_init(drv);

	drv->max_hz = max_hz;
	drv->mode = mode;

	return &drv->slave;
}

void spi_free_slave(struct spi_slave *slave)
{
	ltq_spi_slave_free(slave);
}

static int ltq_spi_wait_ready(struct ltq_spi_drv_data *drv)
{
	const unsigned long timeout = 20000;
	unsigned long timebase;

	timebase = get_timer(0);

	do {
		WATCHDOG_RESET();

		if (!hw_is_busy(drv))
			return 0;
	} while (get_timer(timebase) < timeout);

	return 1;
}

int spi_claim_bus(struct spi_slave *slave)
{
	struct ltq_spi_drv_data *drv = to_ltq_spi_slave(slave);
	int ret;

	ret = ltq_spi_wait_ready(drv);
	if (ret) {
		debug("cannot claim bus\n");
		return ret;
	}

	hw_enter_config_mode(drv);
	hw_setup_clock_mode(drv, drv->mode);
	hw_setup_speed_hz(drv, drv->max_hz);
	hw_setup_bits_per_word(drv, drv->bits_per_word);
	hw_enter_active_mode(drv);

	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	struct ltq_spi_drv_data *drv = to_ltq_spi_slave(slave);

	hw_enter_config_mode(drv);
}

int spi_xfer(struct spi_slave *slave, unsigned int bitlen,
		const void *dout, void *din, unsigned long flags)
{

	struct ltq_spi_drv_data *drv = to_ltq_spi_slave(slave);
	int ret = 0;

	if (bitlen % 8)
		return 1;

	if (!bitlen) {
		ret = 0;
		goto done;
	}

	if (flags & SPI_XFER_BEGIN)
		spi_cs_activate(slave);

	drv->tx = dout;
	drv->tx_todo = 0;
	drv->rx = din;
	drv->rx_todo = 0;
	hw_set_rxtx(drv);

	if (drv->tx) {
		drv->tx_todo = bitlen / 8;

		tx_fifo_write(drv);
	}

	if (drv->rx) {
		drv->rx_todo = bitlen / 8;

		if (!drv->tx)
			rx_request(drv);
	}

	for (;;) {
		if (drv->tx) {
			if (drv->rx && drv->rx_todo)
				rx_fifo_read_full_duplex(drv);

			if (drv->tx_todo)
				tx_fifo_write(drv);
			else
				goto done;
		} else if (drv->rx) {
			if (drv->rx_todo) {
				rx_fifo_read_half_duplex(drv);

				if (drv->rx_todo)
					rx_request(drv);
				else
					goto done;
			} else {
				goto done;
			}
		}
	}

done:
	ret = ltq_spi_wait_ready(drv);

	drv->rx = NULL;
	drv->tx = NULL;
	hw_set_rxtx(drv);

	if (flags & SPI_XFER_END)
		spi_cs_deactivate(slave);

	return ret;
}
