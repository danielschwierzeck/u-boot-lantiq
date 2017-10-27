/*
 * (C) Copyright 2006-2008
 * Stefan Roese, DENX Software Engineering, sr@denx.de.
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
#include <nand.h>
#include <asm/io.h>
#include <asm/boot.h>

#ifndef CONFIG_DRIVER_GRX500
extern void init_ddr(void);
extern void tune_ddr(void);
#endif

#define CONFIG_SYS_NAND_READ_DELAY \
	{ volatile int dummy; int i; for (i=0; i<10000; i++) dummy = i; }

#if defined (CONFIG_DRIVER_GRX500)
static int check_4kec_header(u32 src, u32 *jmp_addr, u32 dst_size)
{
    int image_len;
    u8 *image_start = NULL;
    u32 ret_check, checksum = 0;
    u32 hdr_len, load_addr; 
    image_header_t *pimg_header = (image_header_t *)src;
    
    /* check magic number */
    if (ntohl(pimg_header->ih_magic) != IH_MAGIC)
        return -1;

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
    if (ret_check != checksum)
        return -1;

    asm("sync");
    memcpy((u32 *) load_addr, (u32 *)image_start, image_len);

    return 0; // success
}

#ifdef CONFIG_LTQ_SECURE_BOOT
#define ROLLBACKID_BUFF 0xBF806100
//#define ROLLBACKID_BUFF 0xA0100000

#ifdef CPHYSADDR
	#undef CPHYSADDR
	#define PHYS_ADDR(a) (unsigned long)a<0xb0000000?((((unsigned long)a) & 0x1fffffff) | 0x20000000):(((unsigned long)a) & 0x1fffffff)
	#define CPHYSADDR(a) cpu_is_cps()?(PHYS_ADDR(a)+0xa0000000):(PHYS_ADDR(a))
	#undef KSEG1ADDR
	#define KSEG1ADDR(a) ((unsigned long)a & 0x1fffffff)|KSEG1;
#endif

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

// make sure to put image in 0xa0800000
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

#endif /* CONFIG_DRIVER_GRX500 */

/*
 * NAND command for large page NAND devices (2k)
 */
static int nand_command(struct mtd_info *mtd, int block, int page, int offs, u8 cmd)
{
	struct nand_chip *this = mtd->priv;
	int page_addr = page + block * CONFIG_SYS_NAND_PAGE_COUNT;

	if (this->dev_ready)
		while (!this->dev_ready(mtd))
			;
	else
		CONFIG_SYS_NAND_READ_DELAY;

	/* Emulate NAND_CMD_READOOB */
	if (cmd == NAND_CMD_READOOB) {
		offs += CONFIG_SYS_NAND_PAGE_SIZE;
		cmd = NAND_CMD_READ0;
	}

	/* Begin command latch cycle */
	this->cmd_ctrl(mtd, cmd, NAND_CTRL_CLE | NAND_CTRL_CHANGE);
	/* Set ALE and clear CLE to start address cycle */
	/* Column address */
	this->cmd_ctrl(mtd, offs & 0xff,
		       NAND_CTRL_ALE | NAND_CTRL_CHANGE); /* A[7:0] */
	this->cmd_ctrl(mtd, (offs >> 8) & 0xff, NAND_CTRL_ALE); /* A[11:9] */
	/* Row address */
	this->cmd_ctrl(mtd, (page_addr & 0xff), NAND_CTRL_ALE); /* A[19:12] */
	this->cmd_ctrl(mtd, ((page_addr >> 8) & 0xff),
		       NAND_CTRL_ALE); /* A[27:20] */
#ifdef CONFIG_SYS_NAND_5_ADDR_CYCLE
	/* One more address cycle for devices > 128MiB */
	this->cmd_ctrl(mtd, (page_addr >> 16) & 0x0f,
		       NAND_CTRL_ALE); /* A[31:28] */
#endif
	/* Latch in address */
	this->cmd_ctrl(mtd, NAND_CMD_READSTART,
		       NAND_CTRL_CLE | NAND_CTRL_CHANGE);
	this->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);

	/*
	 * Wait a while for the data to be ready
	 */
	if (this->dev_ready)
		while (!this->dev_ready(mtd))
			;
	else
		CONFIG_SYS_NAND_READ_DELAY;

	return 0;
}

static int nand_is_bad_block(struct mtd_info *mtd, int block)
{

	return 0;
}

static int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst)
{
	struct nand_chip *this = mtd->priv;
	nand_command(mtd, block, page, 0, NAND_CMD_READ0);
    this->ecc.read_page(mtd, this, dst, page);
							
	return 0;
}

static int nand_load(struct mtd_info *mtd, unsigned int offs,
		     unsigned int uboot_size, uchar *dst)
{
	unsigned int block, lastblock;
	unsigned int page;

	/*
	 * offs has to be aligned to a page address!
	 */
	block = offs / CONFIG_SYS_NAND_BLOCK_SIZE;
	lastblock = (offs + uboot_size - 1) / CONFIG_SYS_NAND_BLOCK_SIZE;
	page = (offs % CONFIG_SYS_NAND_BLOCK_SIZE) / CONFIG_SYS_NAND_PAGE_SIZE;

	while (block <= lastblock) {
		if (!nand_is_bad_block(mtd, block)) {
			/*
			 * Skip bad blocks
			 */
			while (page < CONFIG_SYS_NAND_PAGE_COUNT) {
				nand_read_page(mtd, block, page, dst);
				dst += CONFIG_SYS_NAND_PAGE_SIZE;
				page++;
			}

			page = 0;
		} else {
			lastblock++;
		}

		block++;
	}

	return 0;
}

/*
 * The main entry for NAND booting. It's necessary that SDRAM is already
 * configured and available since this code loads the main U-Boot image
 * from NAND into SDRAM and starts it from there.
 */
void nand_boot(void)
{
	struct nand_chip nand_chip;
	nand_info_t nand_info;
	int ret;
	int i;
	ulong  ecc;
        ulong  buffer[8];
        ulong ddr_magic=0x88888888;
	__attribute__((noreturn)) void (*uboot)(void);
    
#if defined(CONFIG_LTQ_SECURE_BOOT) && (!CONFIG_DRIVER_GRX500)
        unsigned char aes_key[32];
        unsigned char iv[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        unsigned char* masked_key=(unsigned char*)(CONFIG_NAND_SPL_TEXT_BASE+0x6000);
#endif

#if defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
	/* Since IAP has already initialised the H/W, we do not want to 
	 * reset the nand datapath when 4kec boots. Otherwise, there will
	 * be a write hang issue 
     */
	if (!cpu_is_cps())
		goto cpy_bootcore;
#endif
    	
	/*
	 * Init board specific nand support
	 */
	nand_info.priv = &nand_chip;
	nand_chip.IO_ADDR_R = nand_chip.IO_ADDR_W = (void  __iomem *)CONFIG_SYS_NAND_BASE;
	nand_chip.dev_ready = NULL;	/* preset to NULL */
	board_nand_init(&nand_chip);

	if (nand_chip.select_chip)
		nand_chip.select_chip(&nand_info, 0);
  
    NAND_WRITE(WRITE_CMD, 0xff);
    while(!NAND_READY){}
  
    nand_info.erasesize = CONFIG_NAND_BLOCK_SIZE; 
    nand_info.writesize = CONFIG_NAND_PAGE_SIZE;
    nand_chip.onfi_version = 1;
#ifndef CONFIG_DRIVER_GRX500
    init_ddr();
#endif
#ifdef CONFIG_TUNE_DDR    
    nand_load(&nand_info, IFX_CFG_FLASH_DDR_CFG_END_ADDR+1-CONFIG_SYS_NAND_PAGE_SIZE, CONFIG_SYS_NAND_PAGE_SIZE, (u8*)0xa0100000);
    buffer[0] = 0;
    for(i=0;i<8;i++){
    buffer[i] = *(volatile u32*)((u8*)0xa0100000+CONFIG_NAND_PAGE_SIZE-32+i*4); 
     }
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
          REG32(0xBF801000) = 0x0 ; 	    
          REG32(0xBF8014C0) = buffer[1]; /*PHYR6*/
          REG32(0xBF8014D0) = buffer[2]; /*PHYR8*/
          REG32(0xBF8014E0) = buffer[3]; /*PHYR7*/
          REG32(0xBF8014F0) = buffer[4]; /*PHYR9*/
          REG32(CSS_DDR_ECHO_DLL0) = buffer[5];
          REG32(CSS_DDR_ECHO_DLL1) = buffer[6];
          REG32(0xBF801000) = 0x401;
          mdelay(1);
      }
    tune_ddr();
#endif	

#if defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
cpy_bootcore:
	if (!cpu_is_cps()) { /* 4Kec only */
		ulong load_address;
		ulong jump_address;
		ulong ddr_address, bootcore_size;
		asm("sync");

		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);	 /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/* reuse ddr loc only */
		bootrom_auth((u32)ddr_address);

		/* safeguard , but shall never come here in first place*/
		while(1);
		#else /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
		/* copy bootcore image */ 
		memcpy((unsigned char *) load_address,
				(unsigned char *) ddr_address,
				bootcore_size);

		ret = check_4kec_header(load_address,
							&jump_address,
							bootcore_size);
        if (ret)
            while(1); // if img is bad, we prevent 4kec from loading it

		uboot = (void*)jump_address;
		(*uboot)();
		#endif /*  defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
	} 
#endif /* CONFIG_DRIVER_GRX500 && !CONFIG_GRX500_BOOT_4KEC_ONLY */

	/*
	 * Load U-Boot image from NAND into RAM
	 */
    #if defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_MANUBOOT)
    ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
                    (uchar *)0xa0800000);
    #else
	ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
			(uchar *)CONFIG_SYS_NAND_U_BOOT_DST);
    #endif /* defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_MANUBOOT) */

#ifdef CONFIG_NAND_ENV_DST
	nand_load(&nand_info, CONFIG_ENV_OFFSET, CONFIG_ENV_SIZE,
		  (uchar *)CONFIG_NAND_ENV_DST);

#ifdef CONFIG_ENV_OFFSET_REDUND
	nand_load(&nand_info, CONFIG_ENV_OFFSET_REDUND, CONFIG_ENV_SIZE,
		  (uchar *)CONFIG_NAND_ENV_DST + CONFIG_ENV_SIZE);
#endif
#endif
	if (nand_chip.select_chip)
		nand_chip.select_chip(&nand_info, -1);

#ifndef CONFIG_MANUBOOT
#ifdef CONFIG_LTQ_SECURE_BOOT
#ifndef CONFIG_DRIVER_GRX500
#include "mask.h"
extern secure_decrypt(u8 *key, u8 *iv, u8 *src, u8 *dst, u32 nbytes);
extern void flush_dcache_range(ulong start_addr, ulong stop);
       for(i=0;i<32;i++){
           aes_key[i]=masked_key[i]^mask[i];
           masked_key[i]=mask[i]=0xff;
    			          }
	   secure_decrypt(aes_key, iv,(u8*)CONFIG_STAGE2_LOADADDR,\
	                 (u8*)CONFIG_STAGE2_LOADADDR, CONFIG_STAGE2_SIZE);
	   flush_dcache_range((ulong)CONFIG_STAGE2_LOADADDR,\
	                      (ulong)(CONFIG_STAGE2_LOADADDR+CONFIG_STAGE2_SIZE));
#else
    #if defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
    bootrom_auth(0xa0800000);
    #else /* defined(CONFIG_GRX500_BOOT_4KEC_ONLY) */
    /* Inform 4kec , to auth img */
    REG32(SRAMFLAG) = IPCMAGIC;
    /* wait for reply , assume during delay, SRAMFLAG will be cleared by 4kec */
    mdelay(200);
    while (REG32(SRAMFLAG) != (~IPCMAGIC));
    REG32(SRAMFLAG) = 0;
    asm("sync");
    #endif /* defined(CONFIG_GRX500_BOOT_4KEC_ONLY) */
#endif
#endif
#endif /* CONFIG_MANUBOOT */

	/*
	 * Jump to U-Boot image
	 */
	uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
	(*uboot)();
}
