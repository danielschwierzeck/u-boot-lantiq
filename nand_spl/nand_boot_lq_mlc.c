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

extern void init_ddr(void);
extern void tune_ddr(void);

#define CONFIG_SYS_NAND_READ_DELAY \
	{ volatile int dummy; int i; for (i=0; i<10000; i++) dummy = i; }

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

#ifdef CONFIG_LTQ_SECURE_BOOT
        unsigned char aes_key[32];
        unsigned char iv[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        unsigned char* masked_key=(unsigned char*)(CONFIG_NAND_SPL_TEXT_BASE+0x6000);
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
    init_ddr();
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
	/*
	 * Load U-Boot image from NAND into RAM
	 */
	ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
			(uchar *)CONFIG_SYS_NAND_U_BOOT_DST);

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

#ifdef CONFIG_LTQ_SECURE_BOOT
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
#endif



	/*
	 * Jump to U-Boot image
	 */
	uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
	(*uboot)();
}
