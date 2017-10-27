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

//#include <LzmaWrapper.h>


#define DDR_OFFSET   0xbf401000
#define DDR_CCR00      (DDR_OFFSET + 0x0000 )
#define DDR_CCR01      (DDR_OFFSET + 0x0010 )
#define DDR_CCR02      (DDR_OFFSET + 0x0020 )
#define DDR_CCR03      (DDR_OFFSET + 0x0030 )
#define DDR_CCR04      (DDR_OFFSET + 0x0040 )
#define DDR_CCR05      (DDR_OFFSET + 0x0050 )
#define DDR_CCR06      (DDR_OFFSET + 0x0060 )
#define DDR_CCR07      (DDR_OFFSET + 0x0070 )
#define DDR_CCR08      (DDR_OFFSET + 0x0080 )
#define DDR_CCR09      (DDR_OFFSET + 0x0090 )
#define DDR_CCR10      (DDR_OFFSET + 0x00A0 )
#define DDR_CCR11      (DDR_OFFSET + 0x00B0 )
#define DDR_CCR12      (DDR_OFFSET + 0x00C0 )
#define DDR_CCR13      (DDR_OFFSET + 0x00D0 )
#define DDR_CCR14      (DDR_OFFSET + 0x00E0 )
#define DDR_CCR15      (DDR_OFFSET + 0x00F0 )
#define DDR_CCR16      (DDR_OFFSET + 0x0100 )
#define DDR_CCR17      (DDR_OFFSET + 0x0110 )
#define DDR_CCR18      (DDR_OFFSET + 0x0120 )
#define DDR_CCR19      (DDR_OFFSET + 0x0130 )
#define DDR_CCR20      (DDR_OFFSET + 0x0140 )
#define DDR_CCR21      (DDR_OFFSET + 0x0150 )
#define DDR_CCR22      (DDR_OFFSET + 0x0160 )
#define DDR_CCR23      (DDR_OFFSET + 0x0170 )
#define DDR_CCR24      (DDR_OFFSET + 0x0180 )
#define DDR_CCR25      (DDR_OFFSET + 0x0190 )
#define DDR_CCR26      (DDR_OFFSET + 0x01A0 )
#define DDR_CCR27      (DDR_OFFSET + 0x01B0 )
#define DDR_CCR28      (DDR_OFFSET + 0x01C0 )
#define DDR_CCR29      (DDR_OFFSET + 0x01D0 )
#define DDR_CCR30      (DDR_OFFSET + 0x01E0 )
#define DDR_CCR31      (DDR_OFFSET + 0x01F0 )
#define DDR_CCR32      (DDR_OFFSET + 0x0200 )
#define DDR_CCR33      (DDR_OFFSET + 0x0210 )
#define DDR_CCR34      (DDR_OFFSET + 0x0220 )
#define DDR_CCR35      (DDR_OFFSET + 0x0230 )
#define DDR_CCR36      (DDR_OFFSET + 0x0240 )
#define DDR_CCR37      (DDR_OFFSET + 0x0250 )
#define DDR_CCR38      (DDR_OFFSET + 0x0260 )
#define DDR_CCR39      (DDR_OFFSET + 0x0270 )
#define DDR_CCR40      (DDR_OFFSET + 0x0280 )
#define DDR_CCR41      (DDR_OFFSET + 0x0290 )
#define DDR_CCR42      (DDR_OFFSET + 0x02A0 )
#define DDR_CCR43      (DDR_OFFSET + 0x02B0 )
#define DDR_CCR44      (DDR_OFFSET + 0x02C0 )
#define DDR_CCR45      (DDR_OFFSET + 0x02D0 )
#define DDR_CCR46      (DDR_OFFSET + 0x02E0 )
#define DDR_CCR47      (DDR_OFFSET + 0x02F0 )
#define DDR_CCR48      (DDR_OFFSET + 0x0300 )
#define DDR_CCR49      (DDR_OFFSET + 0x0310 )
#define DDR_CCR50      (DDR_OFFSET + 0x0320 )
#define DDR_CCR51      (DDR_OFFSET + 0x0330 )
#define DDR_CCR52      (DDR_OFFSET + 0x0340 )
#define DDR_CCR53      (DDR_OFFSET + 0x0350 )
#define DDR_CCR54      (DDR_OFFSET + 0x0360 )
#define DDR_CCR55      (DDR_OFFSET + 0x0370 )
#define DDR_CCR56      (DDR_OFFSET + 0x0380 )
#define DDR_CCR57      (DDR_OFFSET + 0x0390 )
#define DDR_CCR58      (DDR_OFFSET + 0x03A0 )
#define DDR_CCR59      (DDR_OFFSET + 0x03B0 )
#define DDR_CCR60      (DDR_OFFSET + 0x03C0 )
#define DDR_CCR61      (DDR_OFFSET + 0x03D0 )
#define DDR_CCR62      (DDR_OFFSET + 0x03E0 )
#define DDR_CCR63      (DDR_OFFSET + 0x03F0 )
#define DDR_CCR64      (DDR_OFFSET + 0x0400 )
#define DDR_CCR65      (DDR_OFFSET + 0x0410 )
#define DDR_CCR66      (DDR_OFFSET + 0x0420 )
#define DDR_CCR67      (DDR_OFFSET + 0x0430 )
#define DDR_CCR68      (DDR_OFFSET + 0x0440 )
#define DDR_CCR69      (DDR_OFFSET + 0x0450 )
#define DDR_CCR70      (DDR_OFFSET + 0x0460 )
#define DDR_CCR71      (DDR_OFFSET + 0x0470 )
#define DDR_CCR72      (DDR_OFFSET + 0x0480 )
#define DDR_CCR73      (DDR_OFFSET + 0x0490 )
#define DDR_CCR74      (DDR_OFFSET + 0x04A0 )
#define DDR_CCR75      (DDR_OFFSET + 0x04B0 )
#define DDR_CCR76      (DDR_OFFSET + 0x04C0 )
#define DDR_CCR77      (DDR_OFFSET + 0x04D0 )
#define DDR_CCR78      (DDR_OFFSET + 0x04E0 )
#define DDR_CCR79      (DDR_OFFSET + 0x04F0 )
#define DDR_CCR80      (DDR_OFFSET + 0x0500 )
#define DDR_CCR81      (DDR_OFFSET + 0x0510 )
#define DDR_CCR82      (DDR_OFFSET + 0x0520 )
#define DDR_CCR83      (DDR_OFFSET + 0x0530 )
#define DDR_CCR84      (DDR_OFFSET + 0x0540 )
#define DDR_CCR85      (DDR_OFFSET + 0x0550 )
#define DDR_CCR86      (DDR_OFFSET + 0x0560 )
#define DDR_CCR87      (DDR_OFFSET + 0x0570 )
#define DDR_CCR88      (DDR_OFFSET + 0x0580 )
#define DDR_CCR89      (DDR_OFFSET + 0x0590 )
#define DDR_CCR90      (DDR_OFFSET + 0x05A0 )
#define DDR_CCR91      (DDR_OFFSET + 0x05B0 )
#define DDR_CCR92      (DDR_OFFSET + 0x05C0 )
#define DDR_CCR93      (DDR_OFFSET + 0x05D0 )
#define DDR_CCR94      (DDR_OFFSET + 0x05E0 )
#define DDR_CCR95      (DDR_OFFSET + 0x05F0 )
#define DDR_CCR96      (DDR_OFFSET + 0x0600 )
#define DDR_CCR97      (DDR_OFFSET + 0x0610 )
#define DDR_CCR98      (DDR_OFFSET + 0x0620 )
#define DDR_CCR99      (DDR_OFFSET + 0x0630 )
#define DDR_CCR100     (DDR_OFFSET + 0x0640 )
#define DDR_CCR101     (DDR_OFFSET + 0x0650 )
#define DDR_CCR102     (DDR_OFFSET + 0x0660 )
#define DDR_CCR103     (DDR_OFFSET + 0x0670 )
#define DDR_CCR104     (DDR_OFFSET + 0x0680 )
#define DDR_CCR105     (DDR_OFFSET + 0x0690 )
#define DDR_CCR106     (DDR_OFFSET + 0x06A0 )
#define DDR_CCR107     (DDR_OFFSET + 0x06B0 )
#define DDR_CCR108     (DDR_OFFSET + 0x06C0 )
#define DDR_CCR109     (DDR_OFFSET + 0x06D0 )
#define DDR_CCR110     (DDR_OFFSET + 0x06E0 )
#define DDR_CCR111     (DDR_OFFSET + 0x06F0 )
#define DDR_CCR112     (DDR_OFFSET + 0x0700 )
#define DDR_CCR113     (DDR_OFFSET + 0x0710 )
#define DDR_CCR114     (DDR_OFFSET + 0x0720 )
#define DDR_CCR115     (DDR_OFFSET + 0x0730 )
#define DDR_CCR116     (DDR_OFFSET + 0x0740 )
#define DDR_CCR117     (DDR_OFFSET + 0x0750 )
#define DDR_CCR118     (DDR_OFFSET + 0x0760 )
#define DDR_CCR119     (DDR_OFFSET + 0x0770 )
#define DDR_CCR120     (DDR_OFFSET + 0x0780 )
#define DDR_CCR121     (DDR_OFFSET + 0x0790 )
#define DDR_CCR122     (DDR_OFFSET + 0x07A0 )
#define DDR_CCR123     (DDR_OFFSET + 0x07B0 )
#define DDR_CCR124     (DDR_OFFSET + 0x07C0 )
#define DDR_CCR125     (DDR_OFFSET + 0x07D0 )
#define DDR_CCR126     (DDR_OFFSET + 0x07E0 )
#define DDR_CCR127     (DDR_OFFSET + 0x07F0 )
#define DDR_CCR128     (DDR_OFFSET + 0x0800 )
#define DDR_CCR129     (DDR_OFFSET + 0x0810 )
#define DDR_CCR130     (DDR_OFFSET + 0x0820 )
#define DDR_CCR131     (DDR_OFFSET + 0x0830 )
#define DDR_CCR132     (DDR_OFFSET + 0x0840 )
#define DDR_CCR133     (DDR_OFFSET + 0x0850 )
#define DDR_CCR134     (DDR_OFFSET + 0x0860 )
#define DDR_CCR135     (DDR_OFFSET + 0x0870 )
#define DDR_CCR136     (DDR_OFFSET + 0x0880 )
#define DDR_CCR137     (DDR_OFFSET + 0x0890 )
#define DDR_CCR138     (DDR_OFFSET + 0x08A0 )
#define DDR_CCR139     (DDR_OFFSET + 0x08B0 )
#define DDR_CCR140     (DDR_OFFSET + 0x08C0 )
#define DDR_CCR141     (DDR_OFFSET + 0x08D0 )
#define DDR_CCR142     (DDR_OFFSET + 0x08E0 )
#define DDR_CCR143     (DDR_OFFSET + 0x08F0 )
#define DDR_CCR144     (DDR_OFFSET + 0x0900 )
#define DDR_CCR145     (DDR_OFFSET + 0x0910 )
#define DDR_CCR146     (DDR_OFFSET + 0x0920 )
#define DDR_CCR147     (DDR_OFFSET + 0x0930 )
#define DDR_CCR148     (DDR_OFFSET + 0x0940 )
#define DDR_CCR149     (DDR_OFFSET + 0x0950 )
#define DDR_CCR150     (DDR_OFFSET + 0x0960 )
#define DDR_CCR151     (DDR_OFFSET + 0x0970 )
#define DDR_CCR152     (DDR_OFFSET + 0x0980 )
#define DDR_CCR153     (DDR_OFFSET + 0x0990 )
#define DDR_CCR154     (DDR_OFFSET + 0x09A0 )
#define DDR_CCR155     (DDR_OFFSET + 0x09B0 )
#define DDR_CCR156     (DDR_OFFSET + 0x09C0 )
#define DDR_CCR157     (DDR_OFFSET + 0x09D0 )
#define DDR_CCR158     (DDR_OFFSET + 0x09E0 )
#define DDR_CCR159     (DDR_OFFSET + 0x09F0 )
#define DDR_CCR160     (DDR_OFFSET + 0x0A00 )
#define DDR_CCR161     (DDR_OFFSET + 0x0A10 )
#define DDR_CCR162     (DDR_OFFSET + 0x0A20 )
#define DDR_CCR163     (DDR_OFFSET + 0x0A30 )
#define DDR_CCR164     (DDR_OFFSET + 0x0A40 )
#define DDR_CCR165     (DDR_OFFSET + 0x0A50 )
#define DDR_CCR166     (DDR_OFFSET + 0x0A60 )
#define DDR_CCR167     (DDR_OFFSET + 0x0A70 )
#define DDR_CCR168     (DDR_OFFSET + 0x0A80 )
#define DDR_CCR169     (DDR_OFFSET + 0x0A90 )
#define DDR_CCR170     (DDR_OFFSET + 0x0AA0 )
#define DDR_CCR171     (DDR_OFFSET + 0x0AB0 )
#define DDR_CCR172     (DDR_OFFSET + 0x0AC0 )
#define DDR_CCR173     (DDR_OFFSET + 0x0AD0 )
#define DDR_CCR174     (DDR_OFFSET + 0x0AE0 )
#define DDR_CCR175     (DDR_OFFSET + 0x0AF0 )
#define DDR_CCR176     (DDR_OFFSET + 0x0B00 )
#define DDR_CCR177     (DDR_OFFSET + 0x0B10 )
#define DDR_CCR178     (DDR_OFFSET + 0x0B20 )
#define DDR_CCR179     (DDR_OFFSET + 0x0B30 )
#define DDR_CCR180     (DDR_OFFSET + 0x0B40 )
#define DDR_CCR181     (DDR_OFFSET + 0x0B50 )
#define DDR_CCR182     (DDR_OFFSET + 0x0B60 )
#define DDR_CCR183     (DDR_OFFSET + 0x0B70 )
#define DDR_CCR184     (DDR_OFFSET + 0x0B80 )
#define DDR_CCR185     (DDR_OFFSET + 0x0B90 )
#define DDR_CCR186     (DDR_OFFSET + 0x0BA0 )
#define DDR_CCR187     (DDR_OFFSET + 0x0BB0 )
#define DDR_CCR188     (DDR_OFFSET + 0x0BC0 )
#define DDR_CCR189     (DDR_OFFSET + 0x0BD0 )
#define DDR_CCR190     (DDR_OFFSET + 0x0BE0 )
#define DDR_CCR191     (DDR_OFFSET + 0x0BF0 )


#define MC_MODUL_BASE		0xBF800000
#define MC_ERRCAUSE   	MC_MODUL_BASE+0x0010
#define MC_ERRADDR     	MC_MODUL_BASE+0x0020
#define MC_CON		      MC_MODUL_BASE+0x0060
#define MC_SRAM_ENABLE		0x00000004
#define MC_SDRAM_ENABLE		0x00000002
#define MC_DDRRAM_ENABLE	0x00000001
#define MC_DDR_MODUL_BASE	0xBF801000

#define MC_DC03		MC_DDR_MODUL_BASE+0x0030
#define MC_DC15   MC_DDR_MODUL_BASE+0x00F0
#define MC_DC21		MC_DDR_MODUL_BASE+0x0150
#define MC_DC22		MC_DDR_MODUL_BASE+0x0160
#define MC_DC24		MC_DDR_MODUL_BASE+0x0180

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
#define CMD_S25FLXX_READ   0x03 


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


void board_init_f(ulong bootflag)
{
	gd_t gd_data, *id;
	bd_t *bd;
	ulong *s;
	ulong lzmaImageaddr  = 0;
        ulong  buffer[8];
        ulong ddr_magic=0x88888888;
	ulong erase_addr1=0, erase_addr2=0; 
	ulong  ecc;
	int i;
        u8  cmd = CMD_MX25L_READ;
        size_t  addr_len = 3;
  
	erase_addr1 = IFX_CFG_FLASH_DDR_CFG_START_ADDR; 
	erase_addr2 = IFX_CFG_FLASH_DDR_CFG_START_ADDR + IFX_CFG_FLASH_DDR_CFG_SIZE;
	
         asm("sync");
	 serial_init();
	 asm("sync");
	 
	
   
         asm("sync");
         mem_malloc_init (0xbe230000, 200);
	 asm("sync");
         sf_read(cmd,(ulong)IFX_CFG_FLASH_DDR_CFG_START_ADDR,addr_len,(u8*)&buffer,32);
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

   REG32(DDR_CCR07) = 0; /*put DDR controller inactive*/
   asm("sync");
	 if(REG32(CONFIG_TUNING_STATUS)==0xff){ 
	      REG32(DDR_CCR39)= REG32(DDR_CCR39) & 0xffff00ff;
	      REG32(DDR_CCR40)= REG32(DDR_CCR40) & 0xffff00ff;
	      REG32(0xBF400430) = 0x04;
	    }else{
	      REG32(DDR_CCR39)= buffer[1];
	      REG32(DDR_CCR40)= buffer[2];
              REG32(DDR_CCR43)= buffer[3];
	      REG32(DDR_CCR44)= buffer[4];
              REG32(CSS_DDR_ECHO_DLL0)= buffer[5];
              REG32(CSS_DDR_ECHO_DLL1)= buffer[6];
      }
   asm("sync");   
   REG32(DDR_CCR07) = 0x1010100; /*put DDR controller active*/
   while(!(REG32(DDR_CCR47) & 0x01));
   while(!(REG32(DDR_CCR48) & 0x01)); 

	 asm("sync");
#ifdef CONFIG_TUNE_DDR
	 tune_ddr();
#endif

   sf_read(cmd,(ulong)0x5000,addr_len,(u8*)0xa0100000,0x10000);  /*copy u-boot image*/
   sf_read(cmd,(ulong)0x10000,addr_len,(u8*)0xa0110000,0x20000);  /*copy gphy firmware*/

   uncompress_image(0xa0100000);
 
 
   
	/* NOTREACHED - relocate_code() does not return */
}
