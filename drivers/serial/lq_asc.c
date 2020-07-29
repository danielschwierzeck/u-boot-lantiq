#include <common.h>
#include <serial.h>
#include <asm/addrspace.h>
#include <mach/lq_asc.h>
#include <mach/grx500.h>
#include <watchdog.h>
#include <debug_uart.h>

#define SET_BIT(reg, mask) reg |= (mask)
#define CLEAR_BIT(reg, mask) reg &= (~mask)
#define CLEAR_BITS(reg, mask) CLEAR_BIT(reg, mask)
#define SET_BITS(reg, mask) SET_BIT(reg, mask)
#define SET_BITFIELD(reg, mask, off, val)                                      \
	{                                                                      \
		reg &= (~mask);                                                \
		reg |= (val << off);                                           \
	}

static volatile IFX_Asc_t *pAsc = (IFX_Asc_t *)ASC_BASE;
static void lq_serial_setbrg(void);
extern unsigned int get_fpi_clk(void);

typedef struct {
	u16 fdv; /* 0~511 fractional divider value*/
	u16 reload; /* 13 bit reload value*/
} ifx_asc_baud_reg_t;

static int lq_serial_init(void)
{
	/* and we have to set CLC register*/
	CLEAR_BIT(pAsc->asc_clc, ASCCLC_DISS);
	SET_BITFIELD(pAsc->asc_clc, ASCCLC_RMCMASK, ASCCLC_RMCOFFSET, 0x0001);

	/* initialy we are in async mode */
	pAsc->asc_con = ASCCON_M_8ASYNC;

	/* select input port */
	pAsc->asc_pisel = (CONSOLE_TTY & 0x1);

	/* TXFIFO's filling level */
	SET_BITFIELD(pAsc->asc_txfcon, ASCTXFCON_TXFITLMASK,
		     ASCTXFCON_TXFITLOFF, DANUBEASC_TXFIFO_FL);
	/* enable TXFIFO */
	SET_BIT(pAsc->asc_txfcon, ASCTXFCON_TXFEN);

	/* RXFIFO's filling level */
	SET_BITFIELD(pAsc->asc_txfcon, ASCRXFCON_RXFITLMASK,
		     ASCRXFCON_RXFITLOFF, DANUBEASC_RXFIFO_FL);
	/* enable RXFIFO */
	SET_BIT(pAsc->asc_rxfcon, ASCRXFCON_RXFEN);

	/* set baud rate */
	lq_serial_setbrg();

	/* enable error signals &  Receiver enable  */
	SET_BIT(pAsc->asc_whbstate,
		ASCWHBSTATE_SETREN | ASCCON_FEN | ASCCON_TOEN | ASCCON_ROEN);

	return 0;
}

static void serial_divs(u32 baudrate, u32 fasc, u32 *pfdv, u32 *preload)
{
	u32 clock = fasc / 16;

	u32 fdv; /* best fdv */
	u32 reload = 0; /* best reload */
	u32 diff; /* smallest diff */
	u32 idiff; /* current diff */
	u32 ireload; /* current reload */
	u32 i; /* current fdv */
	u32 result; /* current resulting baudrate */

	if (clock > 0x7FFFFF)
		clock /= 512;
	else
		baudrate *= 512;

	fdv = 512; /* start with 1:1 fraction */
	diff = baudrate; /* highest possible */

	/* i is the test fdv value -- start with the largest possible */
	for (i = 512; i > 0; i--) {
		ireload = (clock * i) / baudrate;
		if (ireload < 1)
			break; /* already invalid */
		result = (clock * i) / ireload;

		idiff = (result > baudrate) ? (result - baudrate) :
					      (baudrate - result);
		if (idiff == 0) {
			fdv = i;
			reload = ireload;
			break; /* can't do better */
		} else if (idiff < diff) {
			fdv = i; /* best so far */
			reload = ireload;
			diff = idiff; /* update lowest diff*/
		}
	}

	*pfdv = (fdv == 512) ? 0 : fdv;
	*preload = reload - 1;
}

static void lq_serial_setbrg(void)
{
	u32 uiReloadValue = 0;
	u32 fdv = 0;

	serial_divs(CONFIG_BAUDRATE, get_fpi_clk(), &fdv, &uiReloadValue);
	/* Disable Baud Rate Generator; BG should only be written when R=0 */
	CLEAR_BIT(pAsc->asc_con, ASCCON_R);

	/* Enable Fractional Divider */
	SET_BIT(pAsc->asc_con, ASCCON_FDE); /* FDE = 1 */

	/* Set fractional divider value */
	pAsc->asc_fdv = fdv & ASCFDV_VALUE_MASK;

	/* Set reload value in BG */
	pAsc->asc_bg = uiReloadValue;

	/* Enable Baud Rate Generator */
	SET_BIT(pAsc->asc_con, ASCCON_R); /* R = 1 */
}

static void lq_serial_putc(const char c)
{
	u32 txFl = 0;

	if (c == '\n')
		lq_serial_putc('\r');

	/* check do we have a free space in the TX FIFO */
	/* get current filling level */
	do {
		txFl = (pAsc->asc_fstat & ASCFSTAT_TXFFLMASK) >>
		       ASCFSTAT_TXFFLOFF;
		WATCHDOG_RESET();
	} while (txFl == DANUBEASC_TXFIFO_FULL);

	pAsc->asc_tbuf = c; /* write char to Transmit Buffer Register */

	/* check for errors */
	if (pAsc->asc_state & ASCSTATE_TOE) {
		SET_BIT(pAsc->asc_whbstate, ASCWHBSTATE_CLRTOE);
		return;
	}
}

static void lq_serial_puts(const char *s)
{
	while (*s)
		lq_serial_putc(*s++);
}

static int lq_serial_getc(void)
{
	char c;
	while ((pAsc->asc_fstat & ASCFSTAT_RXFFLMASK) == 0)
		WATCHDOG_RESET();

	c = (char)(pAsc->asc_rbuf & 0xff);

	return c;
}

static int lq_serial_tstc(void)
{
	int res = 1;

	if ((pAsc->asc_fstat & ASCFSTAT_RXFFLMASK) == 0)
		res = 0;

	return res;
}

static struct serial_device lq_serial_drv = {
	.name = "lq_serial",
	.start = lq_serial_init,
	.setbrg = lq_serial_setbrg,
	.putc = lq_serial_putc,
	.puts = lq_serial_puts,
	.getc = lq_serial_getc,
	.tstc = lq_serial_tstc
};

struct serial_device *default_serial_console(void)
{
	return &lq_serial_drv;
}

void lq_serial_initialize(void)
{
	serial_register(&lq_serial_drv);
}

#ifdef CONFIG_DEBUG_UART_LANTIQ
static void _debug_uart_init(void)
{
	lq_serial_init();
}

static inline void _debug_uart_putc(int ch)
{
	u32 txFl = 0;

	do {
		txFl = (pAsc->asc_fstat & ASCFSTAT_TXFFLMASK) >>
		       ASCFSTAT_TXFFLOFF;
	} while (txFl == DANUBEASC_TXFIFO_FULL);

	pAsc->asc_tbuf = ch;
}

DEBUG_UART_FUNCS
#endif
