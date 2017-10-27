/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <version.h>
#include <net.h>
#include <environment.h>


#include "ddr.h"


DECLARE_GLOBAL_DATA_PTR;

#define	TOTAL_MALLOC_LEN	CONFIG_SYS_MALLOC_LEN


ulong monitor_flash_len;

const char version_string[] =
	U_BOOT_VERSION" (" __DATE__ " - " __TIME__ ")";

static char *failed = "*** failed ***\n";


#include <spi.h>
#include <asm/ifx_ssc.h>

#ifndef CONFIG_ENV_SPI_BUS
# define CONFIG_ENV_SPI_BUS 0
#endif
#ifndef CONFIG_ENV_SPI_CS
# define CONFIG_ENV_SPI_CS      0
#endif
#ifndef CONFIG_ENV_SPI_MAX_HZ
# define CONFIG_ENV_SPI_MAX_HZ  1000000
#endif
#ifndef CONFIG_ENV_SPI_MODE
# define CONFIG_ENV_SPI_MODE    SPI_MODE_3
#endif

#define CMD_MX25L_READ     0x03

#define SRC_OFFSET  0x00001000
#define DST_ADDRESS 0xbe221000
#define DATA_SIZE   0x4000

												
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


#ifdef CONFIG_SPI_FLASH_WINBOND
/*
 * Assemble the address part of a command for Winbond devices in
 * non-power-of-two page size mode.
 */
static void winbond_build_address(size_t offset, int l2_page_size, u8* cmd)
{
  unsigned long page_addr;
  unsigned long byte_addr;
  unsigned long page_size;
  unsigned int page_shift;

  /*
   * The "extra" space per page is the power-of-two page size
   * divided by 32.
   */
  page_shift = l2_page_size;
  page_size = (1 << page_shift);
  page_addr = offset / page_size;
  byte_addr = offset % page_size;
  cmd[0] = page_addr >> (16 - page_shift);
  cmd[1] = page_addr << (page_shift - 8) | (byte_addr >> 8);
  cmd[2] = byte_addr;
}
#endif


void sf_read(const u8 cmd, ulong src_addr, 
		size_t addr_len, u8 *data, size_t data_len)
{
	  int i;
	  u8 offset[5];
#ifdef CONFIG_SPI_FLASH_WINBOND
          winbond_build_address((size_t)src_addr, 8, &offset);
#elif defined(CONFIG_SPI_FLASH_MXIC)
          for(i=0;i<addr_len;i++){
          offset[i]= (u8)((src_addr >>((addr_len-i-1)*8)) & 0xff);
          }
#endif
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





/*
 * Begin and End of memory area for malloc(), and current "brk"
 */

static ulong mem_malloc_start;
static ulong mem_malloc_end;
static ulong mem_malloc_brk;


/*
 * The Malloc area is immediately below the monitor copy in DRAM
 */
static void mem_malloc_init (ulong dest_addr, ulong size)
{
//  ulong dest_addr = BOOTSTRAP_CFG_MONITOR_BASE + gd->reloc_off;

    mem_malloc_end = dest_addr;
    mem_malloc_start = dest_addr - size;
    mem_malloc_brk = mem_malloc_start;

    memset ((void *) mem_malloc_start,
        0,
        mem_malloc_end - mem_malloc_start);
}

void *malloc(unsigned int size)
{
    if(size < (mem_malloc_end - mem_malloc_start))
    {
        mem_malloc_start += size;
        return (void *)(mem_malloc_start - size);
    }
    return NULL;
}

void *realloc(void *src,unsigned int size)
{
    return NULL;
}

void free(void *src)
{
    return;
}

void * calloc(
    size_t nelem,
    size_t size)
{
   return;
}

void *sbrk (ptrdiff_t increment)
{
    ulong old = mem_malloc_brk;
    ulong new = old + increment;

    if ((new < mem_malloc_start) || (new > mem_malloc_end)) {
        return (NULL);
    }
    mem_malloc_brk = new;
    return ((void *) old);
}


static int init_baudrate (void)
{

	gd->baudrate = CONFIG_BAUDRATE;

	return (0);
}

void uncompress_image(ulong image_addr)
{

   ulong   addr;
   ulong   data, len, checksum;
   ulong  *len_ptr;
   unsigned int destLen;
   image_header_t header;
   image_header_t *hdr = &header;
   int (*fn)();

   mem_malloc_init(0x82000000, TOTAL_MALLOC_LEN);
   addr = image_addr;
   memmove (&header, (char *)addr, sizeof(image_header_t));

   if (ntohl(hdr->ih_magic) != IH_MAGIC) {
           return;
                            		       }

   data = (ulong)&header;
   len  = sizeof(image_header_t);

   checksum = ntohl(hdr->ih_hcrc);
   hdr->ih_hcrc = 0;
   asm("sync");
   if (crc32 (0, (char *)data, len) != checksum) {
		         return;
						     }

   asm("sync");

   data = addr + sizeof(image_header_t);

   asm("sync");

   len  = ntohl(hdr->ih_size);
   asm("sync");

   len_ptr = (ulong *)data;
   asm("sync");

   destLen = 0x0;

   lzma_inflate ((unsigned char *)data, len, (unsigned char*)ntohl(hdr->ih_load), &destLen);
   fn = ntohl(hdr->ih_load);

   (*fn)();

}




void init_ddr(void)
{
    int i;
    REG32(0xBF106c98) = 0x94; /*interdcdc 1v8*/		
   
    
	REG32(0xBF801000) =	0x0	; /*Put DDR controller inactive*/
	for(i=0;i<66;i++){
        REG32(ddr[i].addr)=ddr[i].value;
	}
	/*Enable memory controller*/ 	
	REG32(0xBF801000) =	0x401;
    //mdelay(1);
	while(!(REG32(0xBF8014B0)&0x1) || !(REG32(0xBF8014E0)&0x1));

    /*prioritize WLAN DDR access to highest in DDR placement logic design*/
    REG32(0xBF8001D0) = 0xFCF;
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

        /*set chip select pin*/
        //*SPI_GPOCON =1<<(spi.cs+8); /*boot from SPI, chip select already set by bootrom*/

		*SPI_BRT = (((F_SSC_CLK>>1) + CONFIG_ENV_SPI_MAX_HZ/2)/(CONFIG_ENV_SPI_MAX_HZ) - 1) & 0xffff;
        /*enable and flush RX/TX FIFO*/
        *SPI_RXFCON = 0xF03;
        *SPI_TXFCON = 0xF03;
        /* set CON, TX off , RX off, ENBV=0, BM=7(8
         * bit valid) HB=1(MSB first), PO=0,PH=1(SPI
         * Mode 0)*/
        *SPI_CON = 0x00070033;
        asm("SYNC");
        /*Set Master mode and  Enable
         * SSC */
        *SPI_WHBSTATE = 0xA;
        asm("SYNC");
}


void board_init_f(ulong bootflag)
{
	gd_t gd_data, *id;
	bd_t *bd;
	ulong *s;
	ulong lzmaImageaddr  = 0;
	ulong  ecc;
	ulong  buffer[8];
	ulong ddr_magic=0x88888888;
	   
	int i;
	int (*fn)();
        u8  cmd = CMD_MX25L_READ;
        size_t  addr_len = 3;
        serial_init();
        spi_init();
     
#ifdef CONFIG_TUNE_DDR  
   sf_read(cmd,(ulong)IFX_CFG_FLASH_DDR_CFG_START_ADDR,addr_len,(u8*)&buffer,IFX_CFG_FLASH_DDR_CFG_SIZE);

    if(buffer[0]==ddr_magic)
       {
             ecc=buffer[1]^buffer[2]^buffer[3]^buffer[4]^buffer[5]^buffer[6];
               if(ecc!=buffer[7]){
                  REG32(CONFIG_TUNING_STATUS)=0xff;
                }else{
                    REG32(CONFIG_TUNING_STATUS)=0;
                }
         }
     else{
        REG32(CONFIG_TUNING_STATUS)=0xff;
    }

    if(REG32(CONFIG_TUNING_STATUS)!=0xff){
          ddr[62].value = buffer[1]; /*PHYR6*/
          ddr[64].value = buffer[2]; /*PHYR8*/
          ddr[63].value = buffer[3]; /*PHYR7*/
          ddr[65].value = buffer[4]; /*PHYR9*/
          REG32(CSS_DDR_ECHO_DLL0) = buffer[5];
          REG32(CSS_DDR_ECHO_DLL1) = buffer[6];
      }
      asm("sync");
#endif     
     init_ddr();
#ifdef CONFIG_TUNE_DDR	 
     tune_ddr();
#endif	   
     sf_read(cmd,(ulong)0x5000,addr_len,(u8*)0xa0100000,0x10000);
     sf_read(cmd,(ulong)0x10000,addr_len,(u8*)0xa0110000,0x10000);
     uncompress_image(0xa0100000);
}
