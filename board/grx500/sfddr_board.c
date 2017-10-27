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
#include <asm/mipsregs.h>
#include <asm/boot.h>


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
# define CONFIG_ENV_SPI_CS      1
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


extern void start_interaptiv(u32 addr);

extern u32 get_cpu_id(void);

int cpu_is_cps(void)
{
    int ret=0;
    if(get_cpu_id()==0xa1) ret=1;
    return ret;
}

int check_4kec_spi_header(u32 src, u32 *jmp_addr, u32 dst_size)
{       
    int image_len;
    u8 *image_start = NULL;
    u32 ret_check, checksum = 0;
    u32 hdr_len, load_addr;
    image_header_t *pimg_header = (image_header_t *)src;
        
    /* check magic number */    
    if (ntohl(pimg_header->ih_magic) != IH_MAGIC) {
        return -1;
	}
            
    asm("sync");
    /* mkimage type kernel without the 8B offset */
    image_start = (u8 *)pimg_header + sizeof(image_header_t);
    image_len = ntohl(pimg_header->ih_size);
    load_addr = ntohl(pimg_header->ih_load);
    *jmp_addr = load_addr;
    asm("sync");

    hdr_len = sizeof(image_header_t);
    checksum = ntohl(pimg_header->ih_hcrc);
    pimg_header->ih_hcrc = 0;

    asm("sync");
    ret_check = crc32(0, (unsigned char *) src, hdr_len);
    if (ret_check != checksum) {
        return -1;
	}

    asm("sync");
    memcpy((u32 *) load_addr, (u32 *)image_start, image_len);

    return 0; // success
}
											
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


void sf_read(const u8 cmd, ulong src_addr, 
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


int spi_gpio_init(void)
{
     /*Enable SPI0 clock*/
     REG32(CGU_CLKGCR1_A)|= CGU_CLKGCR1_A_SPI0_MASK;
     //while(!(REG32(CGU_CLKGSR1) & CGU_CLKGCR1_A_SPI0_MASK))

     /*GPIO 18, SPI0 CLK*/
     REG32(GPIO_PAD_CTRL_PORTMUXC18) = 0x1;
     REG32(GPIO_PAD_CTRL_PORTMUXC15) = 0x1;
     REG32(GPIO_PAD_CTRL_PORTMUXC10) = 0x2;
     REG32(GPIO_PAD_CTRL_PORTMUXC11) = 0x3;
     REG32(GPIO_PAD_CTRL_PORTMUXC17) = 0x1;
     REG32(GPIO_PAD_CTRL_PORTMUXC16) = 0x1;
     return 1;
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
	u8  cmd = CMD_MX25L_READ;
	u32 reg;
	size_t  addr_len = 3;
	int i, cpu_num, vpe_num, ret;
	__attribute__((noreturn)) void (*uboot)(void);

	asm("sync");
	if (cpu_is_cps()) {
		/*
		REG32(0xb23f0014) = 2;
		for (i=0; i<32; i++) {
			REG32(0xb23f0018 + i*4) = 5;
		}
		*/
		reg = read_c0_ebase();
		cpu_num = reg & 0x1ff;
		switch (cpu_num) {
		case 0:
			for (i=0; i<4; i++){                            //Reset All MSG
                REG32(CPUMSG + 4*i) = 0;
                REG32(INTMSG + 4*i) = 0;
                REG32(JMPMSG + 4*i) = 0;
            }

            REG32(CPUMSG)+=1;

			serial_init();
			spi_gpio_init();
			spi_init();
			asm("sync");
			sf_read(cmd,(ulong)0x6000,addr_len,(u8*)0x80200000,0x19000);
			sf_read(cmd,(ulong)0x20000,addr_len,(u8*)0x80220000,0x10000);
			asm("sync");
			uncompress_image(0x80200000);
		break;
		default:
			reg = read_c0_tcbind();
			vpe_num = reg & 0xf;

			ibl(cpu_num, cpu_num, vpe_num);
			break;	
		}
	} else {
		ulong load_address;
		ulong jump_address;
		ulong ddr_address, bootcore_size;

#if defined(CONFIG_GRX500_BOOT_4KEC_ONLY) 
		REG32(0xb49001d4) = CONFIG_FMT1_REG;
		serial_init();
		spi_gpio_init();
		spi_init();
		asm("sync");
		sf_read(cmd,(ulong)0x6000,addr_len,(u8*)0x80200000,0x19000);
		sf_read(cmd,(ulong)0x20000,addr_len,(u8*)0x80220000,0x10000);
		asm("sync");
		uncompress_image(0x80200000);
#else
		/* Initialize flag */
		REG32(SRAMFLAG) = 0;
		/* trigger IAP to run */
		start_interaptiv(CONFIG_SFDDR_TEXT_BASE);
		while (REG32(SRAMFLAG) != IPCMAGIC);
		mdelay(300);	

		REG32(0xb49001d4) = CONFIG_FMT1_REG;

		asm("sync");
		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);    /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		memcpy((unsigned char *) load_address,
				 (unsigned char *) ddr_address,
				 bootcore_size);

		ret = check_4kec_spi_header(load_address,
									&jump_address,
									bootcore_size);
		if (ret)
			while(1); // if img is bad, we prevent 4kec from loading it

		uboot = (void*)jump_address;
		(*uboot)();
#endif
	}
}
