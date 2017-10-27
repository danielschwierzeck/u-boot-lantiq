/*
 *  Infineon SPI interface driver
 *  Revision history
 *
 *  15 May, 2009 Wu Qi Ming, Initial version
 */

#include <common.h>
#include <spi.h>
#include <asm/ifx_ssc.h>
#include <malloc.h>

/*-----------------------------------------------------------------------
 * Definitions
 */

#ifdef DEBUG_SPI
#define PRINTD(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTD(fmt,args...)
#endif
/*---------------------------------------------------------------------*/
/*                         Public Functions                            */
/*=====================================================================*/

/*-----------------------------------------------------------------------
 * Initialization
 */


//extern int amazon_s_get_fpiclk(void);
extern int spi_gpio_init(unsigned int cs);
/*global variable*/
struct spi_slave spi;
unsigned int spi_baudrate;
unsigned int spi_mode;

/* Brief: initialize SSC1 module
 * Parameter:   baudrate FPI/clock ~ FPI/clock/2^16
  */
int ssc_init(u32 baudrate)
{
   return 0;
}

static inline void
SPI_ON(unsigned int cs)
{
    ssc_cs_clr(cs);
}

static inline void	SPI_OFF(unsigned int cs)
{
    ssc_cs_set(cs);
}

void spi_write_byte(uint8_t transmit)
{
    asm("sync");
    ssc_tx_only();
    ssc_write(transmit);
    asm("sync");
    return;
}

static uint8_t	spi_read_byte(void)
{
    ssc_rx_only();
    return ssc_read();
}
									



void spi_init (void)
{
        /* Clock Control Register */
        /* DISS OFF and RMC = 1 */
	//CLC
	*SPI_CLC = 0x0100;
	/* Disable SSC to get access to the control bits */
	*SPI_WHBSTATE = 0x1;
	asm("SYNC");
        
        /*clear all chip select pins*/
        *SPI_FGPO = 0xff00;
	
        /*set chip select pin*/
	*SPI_GPOCON =1<<(spi.cs+8);

        *SPI_BRT = (((F_SSC_CLK>>1) + spi_baudrate/2)/(spi_baudrate) - 1) & 0xffff;
        /*enable and flush RX/TX FIFO*/
        *SPI_RXFCON = 0xF03;
        *SPI_TXFCON = 0xF03;
	/* set CON, TX off , RX off, ENBV=0, BM=7(8
	 * bit valid) HB=1(MSB first), PO=0,PH=1(SPI
	 * Mode 0)*/
#ifdef CONFIG_DRIVER_GRX500
	*SPI_CON = 0xA0070033; /*set LTCLKDEL to 5 clk cycles for high speed*/
#else
        *SPI_CON = 0x00070033;
#endif
	asm("SYNC");
	/*Set Master mode and  Enable
	 * SSC */
        *SPI_WHBSTATE = 0xA;
        asm("SYNC");
}

#ifdef CONFIG_DRIVER_VBG400
/* in vbg400 this ptr is not in use*/
int dummy_spi_ptr;
#endif    
struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
		unsigned int max_hz, unsigned int mode)
{
#ifdef CONFIG_DRIVER_VBG400
	 return (struct spi_slave *)&dummy_spi_ptr;
#else
        u8 tmp;
	int i;
	if(!spi_gpio_init(cs)) return NULL;
        spi.bus=0;
	spi.cs =cs;
        spi_baudrate=max_hz;
	spi_mode=mode;
	spi_init();
	return &spi;
#endif    
}

void spi_free_slave(struct spi_slave *slave)
{
}

int spi_claim_bus(struct spi_slave *slave)
{

	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	/* Nothing to do */
}

/*-----------------------------------------------------------------------
 * SPI transfer
 *
 * This writes "bitlen" bits out the SPI MOSI port and simultaneously clocks
 * "bitlen" bits in the SPI MISO port.  That's just the way SPI works.
 *
 * The source of the outgoing bits is the "dout" parameter and the
 * destination of the input bits is the "din" parameter.  Note that "dout"
 * and "din" can point to the same memory location, in which case the
 * input data overwrites the output data (since both are buffered by
 * temporary variables, this is OK).
 */
int  spi_xfer(struct spi_slave *slave, unsigned int bitlen,
		const void *dout, void *din, unsigned long flags)
{
   u8 tmp;
   int bytelen;
   int ret;
   int i;
   ret = 0;
   if (bitlen == 0)
    /* Finish any previously submitted transfers */
        goto out;

    if (bitlen % 8) {
	/* Errors always terminate an ongoing transfer */
	    flags |= SPI_XFER_END;
		goto out;
	 }
    
	bytelen=bitlen/8;
    if(flags & SPI_XFER_BEGIN)
	 { 
	   SPI_ON(slave->cs);

	 }
	
	for(i=0;i<bytelen;i++){
        if(dout && !din){
		     spi_write_byte(*(u8*)(dout+i)); 
			 ssc_sync();	
			 
	     }
	    else if(!dout && din){
             asm("sync");
			 *(u8*)(din+i)=spi_read_byte();
			 asm("sync");
	     }
	    else if(dout && din){

	    }
	    else{


	    }
    }
out:
    asm("sync");
    if(flags & SPI_XFER_END){
	  SPI_OFF(slave->cs);
    }
					 
	return(0);
}
