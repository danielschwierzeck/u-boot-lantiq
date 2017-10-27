#include <common.h>
#include <spi.h>
#include <asm/ifx_ssc.h>

 /* Updated for HN1 by Andrei Toma */
 
#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS 0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS      0
#endif
#ifdef CONFIG_SF_DEFAULT_SPEED
#define CONFIG_ENV_SPI_MAX_HZ  CONFIG_SF_DEFAULT_SPEED
#else
#define CONFIG_ENV_SPI_MAX_HZ  1000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE    SPI_MODE_3
#endif

#define CMD_MX25L_READ     0x03

#define SRC_OFFSET  0x00000500
#define DST_ADDRESS 0xbf280500
#define DATA_SIZE   0x5000


												
static void
SPI_ON(unsigned int cs)
{
    ssc_cs_clr(cs);
}

static void	SPI_OFF(unsigned int cs)
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


void sf_read(const u8 cmd, u8 *offset, 
		size_t addr_len, u8 *data, size_t data_len)
{
	  int i;
	  SPI_ON(CONFIG_ENV_SPI_CS);
	  spi_write_byte(cmd);
	  for(i=0;i<addr_len;i++){
	  	spi_write_byte(*(offset+i));
	  }
	  for(i=0;i<data_len;i++){
	  	*(data+i)=spi_read_byte();
	  }
	  SPI_OFF(CONFIG_ENV_SPI_CS);
}		

void sf_init(void)
{
	  u8 cmd=0;
	  u8 offset[5]={0};
	  size_t addr_len=0;
	  int i;
	  int (*fn)();
//AT: was only for MXIC chips #ifdef CONFIG_SPI_FLASH_MXIC
    cmd = CMD_MX25L_READ;
    addr_len = 3;
//AT: was only for MXIC chips #endif

//AT: Note: we skip GPIO configuration for SFLASH here, because it was already done by the bootROM.

    for(i=0;i<addr_len;i++){
      offset[i]= (u8)((SRC_OFFSET >>((addr_len-i-1)*8)) & 0xff);
    }
    asm("sync");
	  sf_read(cmd,(u8*)&offset,addr_len,(u8*)(DST_ADDRESS),DATA_SIZE);
	  fn=DST_ADDRESS;
	  (*fn)();
}



