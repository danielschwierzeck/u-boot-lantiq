
#include <config.h>

#if defined(CONFIG_PURPLE) || defined(CONFIG_DRIVER_VBG400)

#ifdef CONFIG_PURPLE
#define	serial_init	asc_serial_init
#define	serial_putc	asc_serial_putc
#define	serial_puts	asc_serial_puts
#define	serial_getc	asc_serial_getc
#define	serial_tstc	asc_serial_tstc
#define	serial_setbrg	asc_serial_setbrg
#endif

#include <common.h>
#include "lq_vbg400_asc.h"

#ifdef CONFIG_PURPLE

#undef ASC_FIFO_PRESENT
#define TOUT_LOOP	100000

/* Set base address for second FPI interrupt control register bank */
#define SFPI_INTCON_BASEADDR	0xBF0F0000

/* Register offset from base address */
#define FBS_ISR		0x00000000	/* Interrupt status register */
#define FBS_IMR		0x00000008	/* Interrupt mask register */
#define FBS_IDIS	0x00000010	/* Interrupt disable register */

/* Interrupt status register bits */
#define FBS_ISR_AT	0x00000040	/* ASC transmit interrupt */
#define FBS_ISR_AR 	0x00000020	/* ASC receive interrupt */
#define FBS_ISR_AE	0x00000010	/* ASC error interrupt */
#define FBS_ISR_AB	0x00000008	/* ASC transmit buffer interrupt */
#define FBS_ISR_AS      0x00000004 	/* ASC start of autobaud detection interrupt */
#define FBS_ISR_AF	0x00000002	/* ASC end of autobaud detection interrupt */

#else

#define ASC_FIFO_PRESENT

#endif


#define SET_BIT(reg, mask)                  reg |= (mask)
#define CLEAR_BIT(reg, mask)                reg &= (~mask)
#define CLEAR_BITS(reg, mask)               CLEAR_BIT(reg, mask)
#define SET_BITS(reg, mask)                 SET_BIT(reg, mask)
#define SET_BITFIELD(reg, mask, off, val)   {reg &= (~mask); reg |= (val << off);}

static int serial_setopt (void);
void MT_UARTConfig(unsigned long,MT_UART_CNFG *);

extern void ReadModWriteReg(unsigned long , unsigned long , unsigned long, unsigned long );
extern void WriteReg(unsigned long , unsigned long , unsigned long ) ;
extern unsigned long ReadReg (unsigned long , unsigned long );

/* pointer to ASC register base address */
static UART_CONTROL asUartControl ;

void serial_setbrg (void) {}
#endif
unsigned long UART_Clk_Rate[] = 
{
	115200,
	38400,
	19200,
	9600 
};


/******************************************************************************
*
* serial_init - initialize a tty channel
*
* This routine initializes the number of data bits, parity
* and set the selected baud rate. Interrupts are disabled.
* Set the modem control signals if the option is selected.
*
* RETURNS: N/A
*/
int serial_init (void)
{
	MT_UART_CNFG UartConfig;

  	/* Set water level for RX and TX */
  	UartConfig.UartTxWaterLevel=0;
  	UartConfig.UartRxWaterLevel=7; /* 4 is default on the register*/

  	/* Set parity Rx and TX */
  	UartConfig.UartTxParity=UART_PARITY_NONE;
  	UartConfig.UartRxParity=UART_PARITY_NONE;

  	/* Set stop bits Rx and TX */
  	UartConfig.UartTxStopBits=UART_STOP_ONEBIT;
  	UartConfig.UartRxStopBits=UART_STOP_ONEBIT;

  	/* Set ouput logic */
  	UartConfig.UartRxLogic =UART_SIGNAL_NO_INVERT;
  	UartConfig.UartTxLogic =UART_SIGNAL_NO_INVERT;

  	/* Set the baud rate */
  	UartConfig.UartRate= (SYS_CLOCK_RATE/(UART_BAUD_RATIO_DIV*UART_Clk_Rate[UART_BAUD115200/*UART_BAUD38400*/])) - 1;        


  	UartConfig.UartTxOutEnable=UART_TX_OUT_ENABLE_YES;

  	/* Set idle duration to 10 times of one byte duration */
  	UartConfig.UartRxIdle=(8+1)*10 ;//10*(8+1+2+1);


  	/* On fisrt time reset Uart */
  	UartConfig.UartReset=UART_RESET_YES;

  	/* Enable clock to the UART */
  	UartConfig.UartClockOnOff=UART_CLOCK_ON;

  	UartConfig.UartLoopBack=UART_LOOPBACK_OFF;

  	/* Enable Uart interrupt to the v186 */
  //	UartConfig.UartEnableHostIntrpt= UART_HOST_INTRPT_ENABLE;

  	/* Select Uart events to cause interrupt to the host*/
  	UartConfig.Status.UartOverRunIntrpt 		= UART_DISABLE_INTRPT; 
  	UartConfig.Status.UartFramingIntrpt 		= UART_DISABLE_INTRPT; //UART_DISABLE_INTRPT;
  	UartConfig.Status.UartParityIntrpt  		= UART_DISABLE_INTRPT; 
  	UartConfig.Status.UartRXFIFOCollapseIntrpt 	= UART_DISABLE_INTRPT; //UART_DISABLE_INTRPT;
  	UartConfig.Status.UartTxFIFOCollapseIntrpt 	= UART_DISABLE_INTRPT; //UART_DISABLE_INTRPT;
  	UartConfig.Status.UartRxWaterLevelIntrpt   	= UART_DISABLE_INTRPT;
  	UartConfig.Status.UartTxWaterLevelIntrpt   	= UART_DISABLE_INTRPT;
  	UartConfig.Status.UartIdleIntrpt           	= UART_DISABLE_INTRPT;

	MT_UARTConfig(0 , &UartConfig);

	UART_CONTROL *psUart = &asUartControl;


    	psUart->pu8TxHead = psUart->pu8TxTail = &psUart->au8TxBuffer[0];
    	psUart->boTxBusy = 0;    /* FALSE */

    	/* OK, we're ready to go */
serial_puts("serial_init finished :-)\n");

    	return 0;
}

/**************************************************************
  *
  * Function Name:  MT_UARTConfig 
  * Description:   config  parameter of UART
  * Input Parameters:  none
  * Return Values: none
  *
  *************************************************************/

void MT_UARTConfig(unsigned long u32Port, MT_UART_CNFG *UartCnfg)
{

	unsigned long temp;

  	/*============ Set Baud rate ======================================== */	
	temp = (SYS_CLOCK_RATE/(UART_BAUD_RATIO_DIV*UART_Clk_Rate[UART_BAUD115200/*UART_BAUD38400*/])) - 1; //app 13
	WriteReg(UART_BASE,REG_UART_CLOCK_DIVISION_RATIO, temp);

	/* Write to REG_UART_CONTROL  output enable and configure Serial to be connected to MPU  (Mux) */  	
	temp = REG_UART_CONTROL_ENABLE_BIT | REG_UART_CONTROL_MUX_MPU_BIT;
  	WriteReg(UART_BASE ,REG_UART_CONTROL,temp);	

  	 /*============ Set TX AND RX WATER_ to 0x21 rec= 1 tx = 1 ================ */
	temp = 0x21;
	WriteReg(UART_BASE,REG_UART_RX_FIFO_WATER_LEVEL,temp);	

	/* Enable clocks: 0-rx, 1-rx fifo, 2-tx, 3-tx fifo, 4-cdiv */
	temp = UART_CLK_ENABLE_REG_VAL;
	ReadModWriteReg(UART_BASE, 0/*?*/, temp, UART_CLK_ENABLE_REG_MASK);
	/*============ Enable interrupts ==================================== */
	temp=0x60;
	WriteReg(UART_BASE ,REG_UART_INT,temp);	
  	
  	
  	/*============ Set RX Idle ==================================== */
  	temp=0;
   	WriteReg(UART_BASE ,REG_UART_RX_IDLE_COUNTER,temp);
}

void serial_putc (const char c)
{
	if (c == '\n') serial_putc ('\r');

	while (ReadReg(UART_BASE , 0x2c) & MCOR_UART_TX_NUM_MASK)
		__udelay (10) ;

	WriteReg(UART_BASE ,WR_ADDR, (volatile unsigned long ) c);
}
		
	
void serial_puts (const char *s)
{
    while (*s)
    {
	serial_putc (*s++);
    }
}

/* Fifo for console: use exactly 256 bytes so that unsigned char data type will handle the wraparounds automatically */
char ascFifo[0xFF];
unsigned char inFifo = 0;
unsigned char outFifo = 0;

int serial_getc (void)
{
    while ((!serial_tstc()) && (inFifo==outFifo));
    /*there is data in hw bufer*/
    while (serial_tstc()) { /*do as long as data in buffer*/
        ascFifo[inFifo] = ReadReg(UART_BASE , 0x10) & 0x000000ff;
        inFifo++;
    }
    /*read data from buffer*/
    return ascFifo[outFifo++];

}

inline int  serial_tstc (void)
{
/* TODO ? 
   if interrupts enabled, need to test also the SW buffer (diff prev to current).
   because, for new chars comming in there may be interrpt (crossing the level)
   and RX fifo would be 0 on test.
*/
#define OK_FOR_READ	1
#define LOOP		0
#define UART_MCOR_RD_RX_BYTES ((unsigned char )((ReadReg (UART_BASE , REG_UART_BYTES_IN_RX_FIFO) & MCOR_UART_RX_NUM_MASK)))

	return UART_MCOR_RD_RX_BYTES;
}

