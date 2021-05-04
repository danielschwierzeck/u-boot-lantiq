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
#include <image.h>
#include <malloc.h>
#include <asm/boot.h>

extern int cpu_is_cps(void);
extern struct nand_bch_control *nand_bch_init(struct mtd_info *mtd);

#ifdef CONFIG_NAND_SPL_BBT
static int bbt_valid=0;
#endif

DECLARE_GLOBAL_DATA_PTR;

#define MAX_BOOTCORE_SIZE	0xA00000
#define CONFIG_SYS_NAND_READ_DELAY \
	{ volatile int dummy = 0; int i; for (i=0; i<10000; i++) dummy += i; }

#ifdef CONFIG_DRIVER_GRX500
 #if defined (CONFIG_NAND_ECC_SOFT)
 static int nand_ecc_pos[] = CONFIG_SYS_NAND_ECCPOS;
 #elif defined (CONFIG_NAND_ECC_BCH)
 static int *nand_ecc_pos;
 #endif
#else
 static int nand_ecc_pos[] = CONFIG_SYS_NAND_ECCPOS;
 #define CONFIG_NAND_SPL_OOBSIZE		CONFIG_SYS_NAND_OOBSIZE
#endif /* CONFIG_DRIVER_GRX500 */

#if defined (CONFIG_DRIVER_GRX500) && !defined(CONFIG_LTQ_SECURE_BOOT)
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

#endif /* CONFIG_DRIVER_GRX500 */

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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	for (i = 0; i < 64; i += 4) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	for (i=0; i<16; i+=4) {
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
	if (REG32(0xbe000000) != 0x0000BABE) {
		REG32(0xbe003f00) = 0x00000002;
		reset = 1;
		goto rm_aw;
	}
	REG32(0xbe003f00) = 0x00000002;

	for (i=0; i<64; i+=8) {
		if (*((u32*)(ROLLBACKID_BUFF+196+i)) == 0)
		    break;

		if (*((u32*)(ROLLBACKID_BUFF+196+i)) == 2) {
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

#if (CONFIG_SYS_NAND_PAGE_SIZE <= 512)
/*
 * NAND command for small page NAND devices (512)
 */
static int nand_command(struct mtd_info *mtd, int block, int page, int offs, u8 cmd)
{
	struct nand_chip *this = mtd_to_nand(mtd);
	int page_addr = page + block * CONFIG_SYS_NAND_PAGE_COUNT;

	if (this->dev_ready)
		while (!this->dev_ready(mtd))
			;
	else
		CONFIG_SYS_NAND_READ_DELAY;

	/* Begin command latch cycle */
	this->cmd_ctrl(mtd, cmd, NAND_CTRL_CLE | NAND_CTRL_CHANGE);
	/* Set ALE and clear CLE to start address cycle */
	/* Column address */
	this->cmd_ctrl(mtd, offs, NAND_CTRL_ALE | NAND_CTRL_CHANGE);
	this->cmd_ctrl(mtd, page_addr & 0xff, NAND_CTRL_ALE); /* A[16:9] */
	this->cmd_ctrl(mtd, (page_addr >> 8) & 0xff,
		       NAND_CTRL_ALE); /* A[24:17] */
#ifdef CONFIG_SYS_NAND_4_ADDR_CYCLE
	/* One more address cycle for devices > 32MiB */
	this->cmd_ctrl(mtd, (page_addr >> 16) & 0x0f,
		       NAND_CTRL_ALE); /* A[28:25] */
#endif
	/* Latch in address */
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
#else
/*
 * NAND command for large page NAND devices (2k)
 */
static int nand_command(struct mtd_info *mtd, int block, int page, int offs, u8 cmd)
{
	struct nand_chip *this = mtd_to_nand(mtd);
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
#endif

static int nand_is_bad_block(struct mtd_info *mtd, int block)
{
	struct nand_chip *this = mtd_to_nand(mtd);
#ifdef CONFIG_NAND_SPL_BBT
	if(bbt_valid){
      return nand_isbad_bbt(mtd, block<<this->bbt_erase_shift, 1);
	}else{
#endif
	 nand_command(mtd, block, 0, CONFIG_SYS_NAND_BAD_BLOCK_POS, NAND_CMD_READOOB);

	 /*
	 * Read one byte
	 */
	if (readb(this->IO_ADDR_R) != 0xff)
		return 1;
#ifdef CONFIG_NAND_SPL_BBT
	}
#endif
	return 0;
}

#ifndef CONFIG_NAND_BENAND
#ifdef CONFIG_NAND_SPL_BBT
int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst)
#else
static int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst)
#endif
{
	struct nand_chip *this = mtd_to_nand(mtd);
	u_char *ecc_calc;
	u_char *ecc_code;
	u_char *oob_data;
	int i;
	int eccsize = CONFIG_SYS_NAND_ECCSIZE;
	int eccbytes = CONFIG_SYS_NAND_ECCBYTES;
	int eccsteps = CONFIG_SYS_NAND_ECCSTEPS;

	uint8_t *p = dst;
	int stat;

	nand_command(mtd, block, page, 0, NAND_CMD_READ0);

	/* No malloc available for now, just use some temporary locations
	 * in SDRAM

	 */
	ecc_calc = (u_char *)(CONFIG_SYS_SDRAM_BASE + 0x10000);
	ecc_code = ecc_calc + 0x10000;
	oob_data = ecc_calc + 0x20000;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		this->ecc.hwctl(mtd, NAND_ECC_READ);
		this->read_buf(mtd, p, eccsize);
		this->ecc.calculate(mtd, p, &ecc_calc[i]);
	}
	this->read_buf(mtd, oob_data, CONFIG_NAND_SPL_OOBSIZE);

	/* Pick the ECC bytes out of the oob data */
	for (i = 0; i < CONFIG_SYS_NAND_ECCTOTAL; i++) {
		ecc_code[i] = oob_data[nand_ecc_pos[i]];
	}

	eccsteps = this->ecc.steps;
	p = dst;

	for (i = 0; eccsteps > 0; eccsteps--, i += eccbytes, p += eccsize) {
		/* No chance to do something with the possible error message
		 * from correct_data(). We just hope that all possible errors
		 * are corrected by this routine.
		 */
		stat = this->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
		if (stat < 0)
			goto error;
	}
	return 0;

error:
	return stat;
}
#else
static int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst)
{
	struct nand_chip *this = mtd_to_nand(mtd);
	this->oob_poi = (u_char *)(CONFIG_SYS_SDRAM_BASE + 0x10000);
	int err = 0;

	nand_command(mtd, block, page, 0, NAND_CMD_READ0);
	/* ecc is handled by benand */
	err = this->ecc.read_page(mtd, this, dst, 1, page);

	return err;
}
#endif /* CONFIG_NAND_BENAND */

#ifdef CONFIG_NAND_SPL_BBT
int scan_read_raw(struct mtd_info *mtd, uint8_t *buf, loff_t offs, size_t len)
{
	 struct nand_chip *this = mtd_to_nand(mtd);
	 int block,page;
	 block=offs>>this->bbt_erase_shift;
	 page=0;/*always the first page for bbt*/

	 nand_command(mtd, block, page, 0, NAND_CMD_READ0);
	 this->read_buf(mtd, buf, mtd->writesize+mtd->oobsize);
}
#endif

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
		if (!nand_is_bad_block(mtd,block)){
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
	struct mtd_info *mtd_data = nand_to_mtd(&nand_chip);
	int ret;
	__attribute__((noreturn)) void (*uboot)(void);

#if defined(CONFIG_LTQ_SECURE_BOOT) && !CONFIG_DRIVER_GRX500
    int i;
    unsigned char aes_key[32];
    unsigned char iv[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	unsigned char* masked_key=(unsigned char*)(CONFIG_NAND_SPL_TEXT_BASE+0x6000);
#endif

#if defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
	/* Since IAP has already initialised the H/W, we do not want to
	* reset the nand datapath when 4kec boots. Otherwise, there will
	* be an unknown state for the controller when IAP access the EBU bus
	*/
	if (!cpu_is_cps())
		goto cpy_bootcore;
#endif

	memset(&nand_chip, 0, sizeof(struct nand_chip));
	/*
	 * Init board specific nand support
	 */
	mtd_data->priv = &nand_chip;

	nand_chip.IO_ADDR_R = nand_chip.IO_ADDR_W = (void  __iomem *)CONFIG_SYS_NAND_BASE;
	nand_chip.dev_ready = NULL;	/* preset to NULL */
	board_nand_init(&nand_chip);

	if (nand_chip.select_chip)
		nand_chip.select_chip(mtd_data, 0);
#ifdef CONFIG_NAND_SPL_BBT
	/*search and setup bbt in the memory*/

	mtd_data->size=CONFIG_NAND_FLASH_SIZE*(1<<20);
	mtd_data->erasesize=CONFIG_NAND_BLOCK_SIZE;
	mtd_data->writesize=CONFIG_NAND_PAGE_SIZE;
	mtd_data->oobsize=64;
	nand_chip.page_shift=ffs(mtd_data->writesize)-1;
	nand_chip.bbt_erase_shift=ffs(mtd_data->erasesize)-1;
	nand_chip.numchips=1;
	nand_chip.bbt_td=NULL;
	nand_chip.bbt_md=NULL;
	nand_chip.chipsize=mtd_data->size;
	nand_chip.badblock_pattern=NULL;

	if(nand_default_bbt(mtd_data)){
		bbt_valid = 1;
	} else{
		bbt_valid = 0;
	}
#endif

#ifdef CONFIG_NAND_BENAND
	mtd_data->writesize = CONFIG_SYS_NAND_PAGE_SIZE;
	mtd_data->oobsize = (CONFIG_SYS_NAND_PAGE_SIZE == 0x1000) ? 128 : 64;
#endif

#if  defined(CONFIG_NAND_ECC_BCH) && defined(CONFIG_DRIVER_GRX500)
	struct nand_ecclayout *ecc;
	struct nand_ecc_ctrl *ctrl;

#ifdef CONFIG_SYS_MALLOC_F_LEN
	gd->malloc_base = CONFIG_SYS_SPL_MALLOC_START;
	gd->malloc_ptr = 0;
	gd->malloc_limit = CONFIG_SYS_SPL_MALLOC_START +
				CONFIG_SYS_MALLOC_F_LEN;
#endif

	mem_malloc_init(CONFIG_SYS_SPL_MALLOC_START,
			CONFIG_SYS_MALLOC_F_LEN);

	mtd_data->size=CONFIG_NAND_FLASH_SIZE*(1<<20);
	mtd_data->erasesize=CONFIG_NAND_BLOCK_SIZE;
	mtd_data->writesize=CONFIG_NAND_PAGE_SIZE;
	mtd_data->oobsize=CONFIG_NAND_SPL_OOBSIZE;
	nand_chip.page_shift=ffs(mtd_data->writesize)-1;
	nand_chip.bbt_erase_shift=ffs(mtd_data->erasesize)-1;
	nand_chip.numchips=1;
	nand_chip.bbt_td=NULL;
	nand_chip.bbt_md=NULL;
	nand_chip.chipsize=mtd_data->size;
	nand_chip.badblock_pattern=NULL;

	nand_chip.ecc.size = CONFIG_SYS_NAND_ECCSIZE;
	nand_chip.ecc.bytes = CONFIG_SYS_NAND_ECCBYTES;
	nand_chip.ecc.steps = CONFIG_SYS_NAND_ECCSTEPS;
	nand_chip.ecc.strength =  DIV_ROUND_UP(
                	nand_chip.ecc.bytes * fls(8 * nand_chip.ecc.size), 8);

	nand_chip.ecc.priv = nand_bch_init(mtd_data);

	ctrl = &nand_chip.ecc;
	ecc = ctrl->layout;
	nand_ecc_pos = (int *) &ecc->eccpos;
#endif

cpy_bootcore:
#if !defined(CONFIG_GRX500_BOOT_4KEC_ONLY) && defined(CONFIG_DRIVER_GRX500)
    if (cpu_is_cps()) {
#endif /* CONFIG_GRX500_BOOT_4KEC_ONLY && CONFIG_DRIVER_GRX500 */

	/*
	 * Load U-Boot image from NAND into RAM
	 */
#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_GRX500) && !defined(CONFIG_MANUBOOT)
        ret = nand_load(mtd_data, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
                        (uchar *)0xa0800000);
#else
        ret = nand_load(mtd_data, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
			(uchar *)CONFIG_SYS_NAND_U_BOOT_DST);
#endif /* CONFIG_LTQ_SECURE_BOOT && CONFIG_DRIVER_GRX500 */

#ifdef CONFIG_NAND_ENV_DST
	nand_load(mtd_data, CONFIG_ENV_OFFSET, CONFIG_ENV_SIZE,
		  (uchar *)CONFIG_NAND_ENV_DST);

#ifdef CONFIG_ENV_OFFSET_REDUND
	nand_load(mtd_data, CONFIG_ENV_OFFSET_REDUND, CONFIG_ENV_SIZE,
		  (uchar *)CONFIG_NAND_ENV_DST + CONFIG_ENV_SIZE);
#endif /* CONFIG_ENV_OFFSET_REDUND */
#endif /* CONFIG_NAND_ENV_DST */

	if (nand_chip.select_chip)
		nand_chip.select_chip(mtd_data, -1);

       asm("sync");

#if defined(CONFIG_LTQ_SECURE_BOOT) && (!CONFIG_DRIVER_GRX500)
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

#ifndef CONFIG_MANUBOOT
#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_GRX500)
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
#endif /* CONFIG_LTQ_SECURE_BOOT && CONFIG_DRIVER_GRX500 && CONFIG_GRX500_A21 */
#endif /* CONFIG_MANUBOOT */
		/*
		 * Jump to U-Boot image
		 */
		uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
		(*uboot)();

#if !defined(CONFIG_GRX500_BOOT_4KEC_ONLY) && defined(CONFIG_DRIVER_GRX500)
    } else {
		ulong load_address;
		ulong jump_address;
		ulong ddr_address, bootcore_size;

		asm("sync");
		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);	 /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		if (bootcore_size > MAX_BOOTCORE_SIZE)
			while(1);

	#if defined(CONFIG_LTQ_SECURE_BOOT)
		/* reuse ddr loc only */
		bootrom_auth((u32)ddr_address);

		/* safeguard , but shall never come here in first place*/
		while(1);
	#else /* defined(CONFIG_LTQ_SECURE_BOOT) */
		memcpy((unsigned char *) load_address,
				(unsigned char *) ddr_address,
				bootcore_size);

		ret = check_4kec_header(load_address,
					(u32 *) &jump_address,
					bootcore_size);
		if (ret)
			while(1); // if img is bad, we prevent 4kec from loading it

		uboot = (void*)jump_address;
		(*uboot)();
	#endif /* defined(CONFIG_LTQ_SECURE_BOOT) */
    }
#endif /* CONFIG_GRX500_BOOT_4KEC_ONLY  && CONFIG_DRIVER_GRX500 */
}
