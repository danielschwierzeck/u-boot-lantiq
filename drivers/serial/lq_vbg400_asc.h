
#ifndef __VBG400UART
#define __VBG400UART

typedef struct {

           unsigned UartOverRunIntrpt:1;
           unsigned UartFramingIntrpt:1;
           unsigned UartParityIntrpt:1;
           unsigned UartRXFIFOCollapseIntrpt:1;
           unsigned UartTxFIFOCollapseIntrpt:1;
           unsigned UartRxWaterLevelIntrpt:1;
           unsigned UartTxWaterLevelIntrpt:1;
           unsigned UartIdleIntrpt:1;

}MT_UART_STATUS;

typedef struct {
           unsigned UartTxOutEnable:1;
           unsigned UartRxParity:2;
           unsigned UartTxParity:2;
           unsigned UartTxStopBits:1;
           unsigned UartRxStopBits:1;
           unsigned UartTxLogic:1;
           unsigned UartRxLogic:1;
           unsigned UartLoopBack: 1;

           unsigned char UartRxIdle;

           unsigned UartTxWaterLevel:4;
           unsigned UartRxWaterLevel:4;


           MT_UART_STATUS Status;

           unsigned long UartRate;

           unsigned UartReset:1;
           unsigned UartClockOnOff:1;
           unsigned UartEnableHostIntrpt:1;

           unsigned reserve1:5;

           unsigned reserve2:8;        /* Align to word boundry */
} MT_UART_CNFG;



/*=============== Parity =======================*/
#define UART_PARITY_NONE           0           
#define UART_PARITY_ODD            1
#define UART_PARITY_EVEN		   3
#define UART_PARITY_DEFAULT        UART_PARITY_NONE
#define UART_PARITY_RX_SHIFT	   1 
#define UART_PARITY_TX_SHIFT	   3
	   
/*=============== Num of stop bits ==============*/
#define UART_STOP_ONEBIT           0
#define UART_STOP_TWOBIT           1
#define UART_STOP_DEFAULT          UART_STOP_ONEBIT
#define	UART_STOP_BIT_RX_SHIFT	   9
#define	UART_STOP_BIT_TX_SHIFT	   10
/*=============== Invert output siganl============*/
#define UART_SIGNAL_NO_INVERT      0
#define UART_SIGNAL_INVERT         1
#define UART_SIGNAL_DEFAULT        UART_SIGNAL_NO_INVERT

/*=============== Loop back on off ============*/
#define UART_LOOPBACK_ON           1
#define UART_LOOPBACK_OFF          0
#define UART_LOOPBACK_SHIFT		   11
/*=============== Reset uart ==================*/
#define UART_RESET_YES             1
#define UART_RESET_NO              0

/*=============== Enable disable uart cloocking */
#define UART_CLOCK_ON              1
#define UART_CLOCK_OFF             0

/*=============== Enable/Disable host interrupts from uart */
#define UART_HOST_INTRPT_ENABLE    0
#define UART_HOST_INTRPT_DISABLE   1

/* channel operating modes */
#define	ASCOPT_CSIZE	0x00000003
#define	ASCOPT_CS7	0x00000001
#define UART_TX_OUT_ENABLE_NO      0
#define UART_TX_OUT_ENABLE_YES     1
#define UART_TX_OUT_ENABLE_SHIFT   0

/*=============== Baud rate ====================*/
#define UART_RATE_9600             9600UL
#define UART_RATE_19200            19200UL
#define UART_RATE_38400            38400UL
#define UART_RATE_57600            57600UL
#define UART_RATE_115200           115200UL
#define UART_RATE_MAX              UART_RATE_115200
#define UART_RATE_DEFAULT          UART_RATE_9600

/* The ratio between the trunk clock after the UART divider
   and the uart baud rate */
/*#define UART_SYS_CLK            240000000 */    /* Clock rate is set according to platform type (FPGA or chip) */
#define UART_BAUD_RATIO_DIV     16

typedef enum  _UART_BAUD{
   UART_BAUD115200,
   UART_BAUD38400,
   UART_BAUD19200,
   UART_BAUD9600
} _UART_BAUD;

#define MT_UARTRXIDLE ()

#define UART_ENABLE_INTRPT   1
#define UART_DISABLE_INTRPT  0

#define UART_BASE	 			0xa7000000

#define REG_UART_CONTROL  			0x20
#define REG_UART_CLOCK_DIVISION_RATIO 		0x14
#define REG_UART_RX_FIFO_WATER_LEVEL 		0x18
#define REG_UART_INT 				0x1c
#define REG_UART_RX_IDLE_COUNTER 		0x28
#define ENET_UART_WAITING_MASK 			0
#define WR_ADDR					0x0c

#define REG_UART_CONTROL_ENABLE_BIT  		0x1
#define REG_UART_CONTROL_MUX_MPU_BIT  		0x100


/* If debug output is defined, it uses the USART port 1 */
#define UART_TX_BUFFER_SIZE    /*512*/ /*1536*/ 4096

typedef struct UART_CONTROL
{
    unsigned char       *pu8TxHead, *pu8TxTail;
    unsigned char       au8TxBuffer[ UART_TX_BUFFER_SIZE];
    char       		au8RxBuff[ENET_UART_WAITING_MASK+1];
    int        		boTxBusy;
    unsigned char       u8PaddUnusedByte1;
    unsigned short      u16Stream; /* Stream this port is used for */
} UART_CONTROL;


#define MT_UART_MCOR_RX_DATA_READY \
        ( (ReadReg (UART_BASE , 0x1c) & UART_INT_MCOR_IDLE) | \
          (ReadReg (UART_BASE , 0x1c) & MT_UART_MCOR_RX_WATER_LEVEL) )


#define REG_UART_WRITE_FIFO_WATER_LEVEL_IRQ                     0x1c
#define UART_INT_MCOR_IDLE                                      0x00008000
#define MT_UART_MCOR_RX_WATER_LEVEL                             0x00002000
#define REG_UART_BYTES_IN_RX_FIFO                               0x2c
#define MCOR_UART_RX_NUM_MASK                                   0x1F

#define MCOR_UART_TX_NUM_MASK                                   0x000003e0

#define UART_CLK_ENABLE_REG_VAL                                 0x0000001f
#define UART_CLK_ENABLE_REG_MASK                                0x0000001f




#define	ASCOPT_CS8	0x00000002
#define	ASCOPT_PARENB	0x00000004
#define	ASCOPT_STOPB	0x00000008
#define	ASCOPT_PARODD	0x00000010
#define	ASCOPT_CREAD	0x00000020



#define ASC_OPTIONS		(ASCOPT_CREAD | ASCOPT_CS8)

/* ASC input select (0 or 1) */
#define CONSOLE_TTY	0

/* use fractional divider for baudrate settings */

/* interrupt lines masks for the ASC device interrupts*/
/* change these macroses if it's necessary */

/* CLC register's bits and bitfields */
#define ASCCLC_DISR        0x00000001
#define ASCCLC_DISS        0x00000002
#define ASCCLC_RMCMASK     0x0000FF00
#define ASCCLC_RMCOFFSET   8

/* CON register's bits and bitfields */
#define ASCCON_MODEMASK 0x0007
    #define ASCCON_M_8SYNC          0x0
    #define ASCCON_M_8ASYNC         0x1
    #define ASCCON_M_8IRDAASYNC     0x2
    #define ASCCON_M_7ASYNCPAR      0x3
    #define ASCCON_M_9ASYNC         0x4
    #define ASCCON_M_8WAKEUPASYNC   0x5
    #define ASCCON_M_8ASYNCPAR      0x7
#define ASCCON_STP      0x0008
#define ASCCON_REN      0x0010
#define ASCCON_PEN      0x0020
#define ASCCON_FEN      0x0040
#define ASCCON_OEN      0x0080
#define ASCCON_PE       0x0100
#define ASCCON_FE       0x0200
#define ASCCON_OE       0x0400
#define ASCCON_FDE      0x0800
#define ASCCON_ODD      0x1000
#define ASCCON_BRS      0x2000
#define ASCCON_LB       0x4000
#define ASCCON_R        0x8000

/* WHBCON register's bits and bitfields */
#define ASCWHBCON_CLRREN    0x0010
#define ASCWHBCON_SETREN    0x0020
#define ASCWHBCON_CLRPE     0x0100
#define ASCWHBCON_CLRFE     0x0200
#define ASCWHBCON_CLROE     0x0400
#define ASCWHBCON_SETPE     0x0800
#define ASCWHBCON_SETFE     0x1000
#define ASCWHBCON_SETOE     0x2000

/* ABCON register's bits and bitfields */
#define ASCABCON_ABEN       0x0001
#define ASCABCON_AUREN      0x0002
#define ASCABCON_ABSTEN     0x0004
#define ASCABCON_ABDETEN    0x0008
#define ASCABCON_FCDETEN    0x0010
#define ASCABCON_EMMASK     0x0300
    #define ASCABCON_EMOFF          8
	#define ASCABCON_EM_DISAB       0x0
	#define ASCABCON_EM_DURAB       0x1
	#define ASCABCON_EM_ALWAYS      0x2
#define ASCABCON_TXINV      0x0400
#define ASCABCON_RXINV      0x0800

/* FDV register mask, offset and bitfields*/
#define ASCFDV_VALUE_MASK     0x000001FF

/* WHBABCON register's bits and bitfields */
#define ASCWHBABCON_SETABEN     0x0001
#define ASCWHBABCON_CLRABEN     0x0002

/* ABSTAT register's bits and bitfields */
#define ASCABSTAT_FCSDET    0x0001
#define ASCABSTAT_FCCDET    0x0002
#define ASCABSTAT_SCSDET    0x0004
#define ASCABSTAT_SCCDET    0x0008
#define ASCABSTAT_DETWAIT   0x0010

/* WHBABSTAT register's bits and bitfields */
#define ASCWHBABSTAT_CLRFCSDET  0x0001
#define ASCWHBABSTAT_SETFCSDET  0x0002
#define ASCWHBABSTAT_CLRFCCDET  0x0004
#define ASCWHBABSTAT_SETFCCDET  0x0008
#define ASCWHBABSTAT_CLRSCSDET  0x0010
#define ASCWHBABSTAT_SETSCSDET  0x0020
#define ASCWHBABSTAT_SETSCCDET  0x0040
#define ASCWHBABSTAT_CLRSCCDET  0x0080
#define ASCWHBABSTAT_CLRDETWAIT 0x0100
#define ASCWHBABSTAT_SETDETWAIT 0x0200

/* TXFCON register's bits and bitfields */
#define ASCTXFCON_TXFEN         0x0001
#define ASCTXFCON_TXFFLU        0x0002
#define ASCTXFCON_TXTMEN        0x0004
#define ASCTXFCON_TXFITLMASK    0x3F00
#define ASCTXFCON_TXFITLOFF     8

/* RXFCON register's bits and bitfields */
#define ASCRXFCON_RXFEN         0x0001
#define ASCRXFCON_RXFFLU        0x0002
#define ASCRXFCON_RXTMEN        0x0004
#define ASCRXFCON_RXFITLMASK    0x3F00
#define ASCRXFCON_RXFITLOFF     8

/* FSTAT register's bits and bitfields */
#define ASCFSTAT_RXFFLMASK      0x003F
#define ASCFSTAT_TXFFLMASK      0x3F00
#define ASCFSTAT_TXFFLOFF       8

#endif /* __VBG400UART */
