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
#include <environment.h>
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

#define MC_MODUL_BASE       0xBF800000
#define MC_ERRCAUSE     MC_MODUL_BASE+0x0010
#define MC_ERRADDR      MC_MODUL_BASE+0x0020
#define MC_CON            MC_MODUL_BASE+0x0060
#define MC_SRAM_ENABLE      0x00000004
#define MC_SDRAM_ENABLE     0x00000002
#define MC_DDRRAM_ENABLE    0x00000001
#define MC_DDR_MODUL_BASE   0xBF801000

#define MC_DC03     MC_DDR_MODUL_BASE+0x0030
#define MC_DC15   MC_DDR_MODUL_BASE+0x00F0
#define MC_DC21     MC_DDR_MODUL_BASE+0x0150
#define MC_DC22     MC_DDR_MODUL_BASE+0x0160
#define MC_DC24     MC_DDR_MODUL_BASE+0x0180



DECLARE_GLOBAL_DATA_PTR;

#define	TOTAL_MALLOC_LEN	CONFIG_SYS_MALLOC_LEN


ulong monitor_flash_len;

const char version_string[] =
	U_BOOT_VERSION" (" __DATE__ " - " __TIME__ ")";

static char *failed = "*** failed ***\n";


#define CMD_MX25L_READ     0x03

#define SRC_OFFSET  0x00001000
#define DST_ADDRESS 0xbe221000
#define DATA_SIZE   0x4000

static inline void
SPI_ON(unsigned int cs)
{
    ssc_cs_clr(cs);
}

static inline void	SPI_OFF(unsigned int cs)
{
    ssc_cs_set(cs);
}

static void spi_write_byte(uint8_t transmit)
{
    asm("sync");
    ssc_tx_only();
    ssc_write(transmit);
    asm("sync");
    return;
}
/*
static uint8_t	spi_read_byte(void)
{
    ssc_rx_only();
    return ssc_read();
}
*/

static void sf_read(const u8 cmd, ulong src_addr, 
		size_t addr_len, u8 *data, size_t data_len)
{
	  int i;
	  u8 offset[5];
	  for(i=0;i<addr_len;i++){
      offset[i]= (u8)((src_addr >>((addr_len-i-1)*8)) & 0xff);
    }
	  SPI_ON(CONFIG_ENV_SPI_CS);
	  spi_write_byte(cmd);
	  for(i=0;i<addr_len;i++){
	  	spi_write_byte(*(offset+i));
	  }
	  ssc_rx_only();
	  for(i=0;i<data_len;i++){
	  	*(data+i)=ssc_read();
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
void mem_malloc_init(ulong start, ulong size)
{
	 mem_malloc_end = start + size;
   mem_malloc_start = start;
   mem_malloc_brk = start;

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



void board_init_f(ulong bootflag)
{

	gd_t gd_data, *id;
	bd_t *bd;
	ulong *s;
	ulong lzmaImageaddr  = 0;
  ulong  buffer[6];
  ulong ddr_magic=0x88888888;
	ulong erase_addr1=0, erase_addr2=0; 
	ulong  ecc;
	int i;
	int (*fn)();

#ifdef CONFIG_SPI_FLASH_MXIC
  u8  cmd = CMD_MX25L_READ;
  size_t  addr_len = 3;
#endif	
#if 1	  
	erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
	
   asm("sync");
	 serial_init();
	 asm("sync");
	 
   asm("sync");
   
   mem_malloc_init(0x82000000-TOTAL_MALLOC_LEN, TOTAL_MALLOC_LEN);
	 asm("sync");
   sf_read(cmd,(ulong)IFX_CFG_FLASH_DDR_CFG_START_ADDR,addr_len,(u8*)&buffer,24);
	 
	 if(buffer[0]==ddr_magic)
       {
             ecc=buffer[1]^buffer[2]^buffer[3]^buffer[4];
               if(ecc!=buffer[5]){
                  REG32(0xBe1a7f20)=0xff;
                }else{
                    REG32(0xBe1a7f20)=0;
                }
         }
     else{
        REG32(0xBe1a7f20)=0xff;
    }

        /* Clear Error log registers */
        REG32(MC_ERRCAUSE)= 0;
        REG32(MC_ERRADDR) = 0;
      asm("sync");
        /* Enable DDR module in memory controller */
        REG32(MC_CON)= REG32(MC_CON)|MC_DDRRAM_ENABLE;
        asm("sync");
        if(REG32(0xBe1a7f20)==0xff){
          REG32(MC_DC21)= 0;
          REG32(MC_DC22)=0;
        }else{
          REG32(MC_DC15)= buffer[1];
          REG32(MC_DC21)= buffer[2];
          REG32(MC_DC22)= buffer[3];
          REG32(MC_DC24)= buffer[4];
      }
      asm("sync");
      REG32(MC_DC03) = 0x00000100;
      while((REG32(0xbf800070)& 0x08)!=0x08);

     asm("sync");
     tune_ddr();

#endif
   sf_read(cmd,(ulong)0x3c00,addr_len,(u8*)CONFIG_BOOTSTRAP_TEXT_BASE,0x10000);  /*copy u-boot image*/
  
   fn = CONFIG_BOOTSTRAP_TEXT_BASE;

   (*fn)();

}
