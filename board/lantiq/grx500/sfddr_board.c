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
#include <asm/mipsmtregs.h>
#include <asm/boot.h>
#include <mapmem.h>
#include <spi.h>
#include <lq_spi.h>

DECLARE_GLOBAL_DATA_PTR;

#define	TOTAL_MALLOC_LEN	CONFIG_SYS_MALLOC_LEN
#define U_BOOT_OFFSET		CONFIG_SPI_SPL_SIZE
#define U_BOOT_LOAD_ADDR	0x80200000
#define U_BOOT_SIZE			0x20000
#define FIRMWARE_OFFSET		CONFIG_SPI_SPL_SIZE + 0x20000
#define FIRMWARE_LOAD_ADDR	0x80220000
#define	FIRMWARE_SIZE		0x10000

#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
// DDR temporary placeholder before secure boot authentication put it in right place
#define SECBOOT_TMP_ADDR	0xa0800000
#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
#if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
extern int otp_prog_execute(void);
#endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) */

ulong monitor_flash_len;

extern int lzma_inflate(unsigned char *source, int s_len, unsigned char *dest, int *d_len);

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

static int initr_malloc(void)
{
	gd->malloc_base = CONFIG_SYS_SPL_MALLOC_START;
	gd->malloc_ptr = 0;
	gd->malloc_limit = CONFIG_SYS_SPL_MALLOC_START +
				CONFIG_SYS_MALLOC_F_LEN;

	return 0;
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

   initr_malloc();
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

#ifdef CONFIG_LTQ_SECURE_BOOT

#define ROLLBACKID_BUFF 0xBF806100
//#define ROLLBACKID_BUFF 0xA0100000

#ifdef CPHYSADDR
	#undef CPHYSADDR
#endif
	#define PHYS_ADDR(a) (unsigned long)a<0xb0000000?((((unsigned long)a) & 0x1fffffff) | 0x20000000):(((unsigned long)a) & 0x1fffffff)
	#define CPHYSADDR(a) cpu_is_cps()?(PHYS_ADDR(a)+0xa0000000):(PHYS_ADDR(a))
#ifdef KSEG1ADDR
	#undef KSEG1ADDR
#endif
	#define KSEG1ADDR(a) ((unsigned long)a & 0x1fffffff)|KSEG1;

void rollback_id_chk_pre(u32 addr)
{
    memcpy((void*)ROLLBACKID_BUFF, (const void*)addr, (size_t)264);
    return;
}

void rollback_id_chk_do()
{
    u32 val   = 0;
    u32 a6    = 0;
    u32 akek  = 0;
    u32 i     = 0;
    u8  *pTmp = 0;
    u32 word  = 0;
    u32 aw    = 0;
    u32 id    = 0;
    u32 cid   = 0;
    u32 reset = 0;

    REG32(0xbe003f00) = 0x00000004;

    REG32(0xbe000000) = 0x07000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe00000C) = 0x00068000;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rst;
    }
    a6 = REG32(0xbe000004);
    REG32(0xbe003f00) = 0x00000002;

    REG32(0xbe000000) = 0x07000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = 0x00003001;
    REG32(0xbe00000C) = 0x00000020;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rst;
    }
    akek = REG32(0xbe000004);
    REG32(0xbe003f00) = 0x00000002;

    REG32(0xbe000000) = 0x17000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = akek;
    REG32(0xbe00000C) = 0x01400000;
    REG32(0xbe00001C) = a6;
    for (i=0; i<64; i+=4)
    {
        pTmp  = ROLLBACKID_BUFF+8+i;
        word  = *pTmp++;
        word |= (*pTmp++) << 8;
        word |= (*pTmp++) << 16;
        word |= (*pTmp++) << 24;
        REG32(0xbe000020+i) = word;
    }
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rm_akek;
    }
    REG32(0xbe003f00) = 0x00000002;

    REG32(0xbe000000) = 0x07000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = 0x00003001;
    REG32(0xbe00000C) = 0x00000020;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rm_akek;
    }
    aw = REG32(0xbe000004);
    REG32(0xbe003f00) = 0x00000002;

    REG32(0xbe000000) = 0x17000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = aw;
    REG32(0xbe00000C) = 0x10000028;
    REG32(0xbe000010) = CPHYSADDR(ROLLBACKID_BUFF+136);
    #if 0
     REG32(0xbe000014) = 0xAAAAAAAA;
     REG32(0xbe000018) = 0xAAAAAAAA;
    #endif
    REG32(0xbe00001C) = akek;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rm_aw;
    }
    REG32(0xbe003f00) = 0x00000002;

    REG32(0xbe000000) = 0x0100BABE;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = 0x00000040;
    REG32(0xbe00000C) = CPHYSADDR(ROLLBACKID_BUFF+196);
    REG32(0xbe000010) = 0x00000040;
    REG32(0xbe000014) = 0x00000000;
    REG32(0xbe000018) = CPHYSADDR(ROLLBACKID_BUFF+196);
    REG32(0xbe00001C) = 0x00000040;
    REG32(0xbe000020) = 0x00000000;
    REG32(0xbe000028) = 0x00030110;
    for (i=0; i<16; i+=4)
    {
        pTmp  = ROLLBACKID_BUFF+176+i;
        word  = *pTmp++;
        word |= (*pTmp++) << 8;
        word |= (*pTmp++) << 16;
        word |= (*pTmp++) << 24;
        REG32(0xbe000030+i) = word;
    }
    REG32(0xbe000040) = aw;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    if (REG32(0xbe000000) != 0x0000BABE)
    {
        REG32(0xbe003f00) = 0x00000002;
        reset = 1;
        goto rm_aw;
    }
    REG32(0xbe003f00) = 0x00000002;

    for (i=0; i<64; i+=8)
    {
        if(*((u32*)(ROLLBACKID_BUFF+196+i)) == 0)
            break;

        if(*((u32*)(ROLLBACKID_BUFF+196+i)) == 2)
        {
            id = *((u32*)(ROLLBACKID_BUFF+196+i+4));
            break;
        }
    }
    if (REG32(0xb6080304) == 0xFFFFFFFFUL)
        cid = 32; // safety against undefine ffz when no 0
    else
        /* the index of first zero coincidentally also count the number of consecutive trailing bit 1 */
        cid = ffz(REG32(0xb6080304));

    if (id < cid)
        reset = 1;

    rm_aw:
    REG32(0xbe000000) = 0x37000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = aw;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    #if 0
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        return;
    }
    #endif
    REG32(0xbe003f00) = 0x00000002;

    rm_akek:
    REG32(0xbe000000) = 0x37000000;
    REG32(0xbe000004) = 0x4011BA23;
    REG32(0xbe000008) = akek;
    REG32(0xbe003f00) = 0x00000001;
    val = REG32(0xbe003f00);
    while( (val & 0x00000002) != 2)
        val = REG32(0xbe003f00);
    #if 0
    if ((REG32(0xbe000000) & 0x80000000) != 0)
    {
        REG32(0xbe003f00) = 0x00000002;
        return;
    }
    #endif
    REG32(0xbe003f00) = 0x00000002;

    memset((void*)ROLLBACKID_BUFF,0,(size_t)264);

    rst:
    if(reset)
        REG32(0xb6000010) |= 0x40000000;

    return;
}

void bootrom_auth(u32 addr)
{
    ulong *img_p = (ulong *)addr;
    int    image_len;
    int    certnum;

    void (*auth)(u32 addr, int len, u32* entry_p, u32* target_p) = (void*)0x9fc1a001;

    certnum   = (int)(*(img_p+65));
    image_len = 66*4+128*certnum+(int)(*(img_p+48));

    asm("sync");

    rollback_id_chk_pre(addr);
    rollback_id_chk_do();
    auth((u32)img_p, image_len, NULL, NULL);
    // rollback_id_chk_do(); //safer after auth but cant check bootcore if put here

    return;
}
#endif /* CONFIG_LTQ_SECURE_BOOT */

#if defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT)
void enable_eip123_iap_access()
{
   u32 reg_val = 0;

   // i=0;
   // i += permission_wr(0xbff80058, 0x1f);
   // i += permission_wr(0xbff80050, 0x1f);

   REG32(0xb608004c) &=~(1<<3);
   REG32(0xb608005c) |= 0xdfffff;

   reg_val = REG32(0xbe003F10);
   REG32(0xbe003F10) = reg_val & 0xFFFFFF00;
}
#endif /* defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT) */

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

			lq_serial_init();
			spi_gpio_init();
			spi_init();
			asm("sync");
			#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
			sf_read(cmd,(ulong)U_BOOT_OFFSET,addr_len,(u8*)SECBOOT_TMP_ADDR,(U_BOOT_SIZE+FIRMWARE_SIZE));
			asm("sync");
			/* Inform 4kec , to auth img */
			REG32(SRAMFLAG) = IPCMAGIC;
			/* wait for reply , assume during delay, SRAMFLAG will be cleared by 4kec */
			mdelay(200);
			while (REG32(SRAMFLAG) != (~IPCMAGIC));
			REG32(SRAMFLAG) = 0;
			asm("sync");
			#else /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
			sf_read(cmd,(ulong) U_BOOT_OFFSET, addr_len, 
						(u8*) U_BOOT_LOAD_ADDR, U_BOOT_SIZE);
			sf_read(cmd,(ulong) FIRMWARE_OFFSET, addr_len,
						(u8*) FIRMWARE_LOAD_ADDR, FIRMWARE_SIZE);
			#endif /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
			flush_cache(FIRMWARE_LOAD_ADDR, FIRMWARE_SIZE);
			uncompress_image(U_BOOT_LOAD_ADDR);
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
		lq_serial_init();
		spi_gpio_init();
		spi_init();
		asm("sync");
		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		sf_read(cmd,(ulong)U_BOOT_OFFSET,addr_len,(u8*)SECBOOT_TMP_ADDR,(U_BOOT_SIZE+FIRMWARE_SIZE));
		bootrom_auth(SECBOOT_TMP_ADDR);
		#else /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
		sf_read(cmd,(ulong) U_BOOT_OFFSET, addr_len, 
					(u8*) U_BOOT_LOAD_ADDR, U_BOOT_SIZE);
		sf_read(cmd,(ulong) FIRMWARE_OFFSET, addr_len,
					(u8*) FIRMWARE_LOAD_ADDR, FIRMWARE_SIZE);
		#endif /*defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)*/
		asm("sync");
		uncompress_image(U_BOOT_LOAD_ADDR);
#else
		/* Initialize flag */
		REG32(SRAMFLAG) = 0;
		/* trigger IAP to run */
		start_interaptiv(CONFIG_SFDDR_TEXT_BASE);
		#if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
		wait:
		#endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT)*/
		while (REG32(SRAMFLAG) != IPCMAGIC);
		mdelay(300);	

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/*auth uboot , agree on 0xa0800000 */
		bootrom_auth(SECBOOT_TMP_ADDR);
		/* inform iap done */
		REG32(SRAMFLAG)= (~IPCMAGIC);
		asm("sync");
		#ifdef CONFIG_LTQ_EIP123_IAP_ACCESS
		/* need to do it after bootrom img auth, since they reset eip123 again */
		enable_eip123_iap_access();
		#endif /* CONFIG_LTQ_EIP123_IAP_ACCESS */
		/* next round of wait, tos command */
		mdelay(200);
		while (REG32(SRAMFLAG) != IPCMAGIC);
		mdelay(300);
		#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */

		#if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
		/* this render the tos command become otp programming in manufacturing boot */
		/* and break the ability to load bootcore when RoT */
		otp_prog_execute();
		goto wait; /* back to wait magic */
		#endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) */

		REG32(0xb49001d4) = CONFIG_FMT1_REG;

		asm("sync");
		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);    /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/* reuse ddr loc only */
		bootrom_auth((u32)ddr_address);

		/* safeguard , but shall never come here in first place*/
		while(1);
		#else /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
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
		#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
#endif
	}
}
