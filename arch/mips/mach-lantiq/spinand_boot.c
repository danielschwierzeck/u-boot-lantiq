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
#include <asm/boot.h>
#include <spinand.h>
#include <lantiq.h>
#include <asm/reboot.h>

extern int cpu_is_cps(void);
unsigned char oob_buf[64];
DECLARE_GLOBAL_DATA_PTR;

#define MAX_BOOTCORE_SIZE	0xA00000
#define CONFIG_SYS_NAND_READ_DELAY \
	{ volatile int dummy; int i; for (i=0; i<10000; i++) dummy = i; }

/* Check MACROS */
#if defined(CONFIG_DRIVER_GRX500) || defined(CONFIG_DRIVER_PRX300)
#define XRX500_PRX300_DRIVER
#endif

#if defined(CONFIG_GRX500_BOOT_4KEC_ONLY) || defined (CONFIG_PRX300_BOOT_4KEC_ONLY)
#define BOOT_4KEC_ONLY
#endif

#ifdef XRX500_PRX300_DRIVER
 #if defined (CONFIG_NAND_ECC_SOFT)
 static int nand_ecc_pos[] = CONFIG_SYS_NAND_ECCPOS;
 #elif defined (CONFIG_NAND_ECC_BCH)
 static int *nand_ecc_pos;
 #endif
#else
 static int nand_ecc_pos[] = CONFIG_SYS_NAND_ECCPOS;
 #define CONFIG_NAND_SPL_OOBSIZE		CONFIG_SYS_NAND_OOBSIZE
#endif /* XRX500_PRX300_DRIVER */

#if defined (XRX500_PRX300_DRIVER) && !defined(CONFIG_LTQ_SECURE_BOOT)
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

#endif /* XRX500_PRX300_DRIVER */

#ifdef CONFIG_LTQ_SECURE_BOOT

#define BOOTCORE_LINUX_JUMP_ADDR 0x88000000

#ifdef CONFIG_DRIVER_GRX500
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
		pTmp = ROLLBACKID_BUFF + 8 + i;
		word = *pTmp++;
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
	REG32(0xbe000010) = CPHYSADDR(ROLLBACKID_BUFF + 136);
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
	REG32(0xbe00000C) = CPHYSADDR(ROLLBACKID_BUFF + 196);
	REG32(0xbe000010) = 0x00000040;
	REG32(0xbe000014) = 0x00000000;
	REG32(0xbe000018) = CPHYSADDR(ROLLBACKID_BUFF + 196);
	REG32(0xbe00001C) = 0x00000040;
	REG32(0xbe000020) = 0x00000000;
	REG32(0xbe000028) = 0x00030110;
	for (i = 0; i < 16; i += 4) {
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
		if(*((u32*)(ROLLBACKID_BUFF+196+i)) == 0)
		    break;

		if(*((u32*)(ROLLBACKID_BUFF+196+i)) == 2) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
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
	if ((REG32(0xbe000000) & 0x80000000) != 0) {
		REG32(0xbe003f00) = 0x00000002;
		return;
	}
	#endif
	REG32(0xbe003f00) = 0x00000002;

	memset((void*)ROLLBACKID_BUFF, 0, (size_t)264);

rst:
	if (reset)
		REG32(0xb6000010) |= 0x40000000;

	return;
}
#endif /* CONFIG_DRIVER_GRX500 */

#ifdef CONFIG_DRIVER_PRX300
u32 get_rbid_uboot(void);
#endif /* CONFIG_DRIVER_PRX300 */

void bootrom_auth(u32 addr)
{
	ulong *img_p = (ulong *)addr;
	int image_len;
	int certnum;
	#if defined(CONFIG_DRIVER_PRX300)
	u32 ver_rollback_img, ver_rollback_soc;
	int ret = -1;

	int (*auth)(u32 addr, int len,u32* entry_p, u32* target_p, u32* ver_rollback_img_p, u32* ver_rollback_soc_p) = (void*)0x9fc1df11;
	#elif defined(CONFIG_DRIVER_GRX500)
	void (*auth)(u32 addr, int len, u32* entry_p, u32* target_p) = (void*)0x9fc1a001;
	#endif /* defined(CONFIG_DRIVER_PRX300) | defined(CONFIG_DRIVER_GRX500)*/

	certnum   = (int)(*(img_p+65));
	image_len = 66*4+128*certnum+(int)(*(img_p+48));

	asm("sync");

	#if defined(CONFIG_DRIVER_PRX300)
	ret = auth((u32)img_p, image_len, NULL, NULL, &ver_rollback_img, &ver_rollback_soc);

	/* safeguard, reset if fail */
	if (0 != ret)
		_machine_restart();

	/* rollback id check if you want */
	/* !<WW: TODO : if otp 2x32bits antirollback are partitioned */
	/* then it is advised to discard ver_rollback_soc return from api */
	/* you will want to read manually the rollback and parse according to new requirement */
	/* !<WW[13-Dec-2019]: replace soc rollbackid with new TMR example on OTP rollback value bit 0:15 for uboot*/
	ver_rollback_soc = get_rbid_uboot();
	if (ver_rollback_img < ver_rollback_soc)
		_machine_restart();

	#elif defined(CONFIG_DRIVER_GRX500)
	rollback_id_chk_pre(addr);
	rollback_id_chk_do();
	auth((u32)img_p, image_len, NULL, NULL);
	// rollback_id_chk_do(); //safer after auth but cant check bootcore if put here
	#endif /* defined(CONFIG_DRIVER_PRX300) | defined(CONFIG_DRIVER_GRX500)*/

	return;
}

#ifdef CONFIG_DRIVER_PRX300

u32 get_rbid_uboot(void);
u32 get_rbid_tos(void);

/* added specific bootrom_auth_tos , since bootcore linux will need to check */
/* different rollback id bits in upper word bits 16:31*/
void bootrom_auth_tos(u32 addr)
{
	ulong *img_p = (ulong *)addr;
	int image_len;
	int certnum;
	#if defined(CONFIG_DRIVER_PRX300)
	u32 ver_rollback_img, ver_rollback_soc;
	int ret = -1;

	int (*auth)(u32 addr, int len,u32* entry_p, u32* target_p, u32* ver_rollback_img_p, u32* ver_rollback_soc_p) = (void*)0x9fc1df11;
	#elif defined(CONFIG_DRIVER_GRX500)
	void (*auth)(u32 addr, int len, u32* entry_p, u32* target_p) = (void*)0x9fc1a001;
	#endif /* defined(CONFIG_DRIVER_PRX300) | defined(CONFIG_DRIVER_GRX500)*/

	certnum   = (int)(*(img_p+65));
	image_len = 66*4+128*certnum+(int)(*(img_p+48));

	asm("sync");

	#if defined(CONFIG_DRIVER_PRX300)
	ret = auth((u32)img_p, image_len, NULL, NULL, &ver_rollback_img, &ver_rollback_soc);

	/* safeguard, reset if fail */
	if (0 != ret)
		_machine_restart();

	/* rollback id check if you want */
	/* !<WW: TODO : if otp 2x32bits antirollback are partitioned */
	/* then it is advised to discard ver_rollback_soc return from api */
	/* you will want to read manually the rollback and parse according to new requirement */
	/* !<WW[13-Dec-2019]: replace soc rollbackid with new TMR example on OTP rollback value bit 16:31 for tos*/
	ver_rollback_soc = get_rbid_tos();
	if (ver_rollback_img < ver_rollback_soc)
		_machine_restart();

	#elif defined(CONFIG_DRIVER_GRX500)
	rollback_id_chk_pre(addr);
	rollback_id_chk_do();
	auth((u32)img_p, image_len, NULL, NULL);
	// rollback_id_chk_do(); //safer after auth but cant check bootcore if put here
	#endif /* defined(CONFIG_DRIVER_PRX300) | defined(CONFIG_DRIVER_GRX500)*/

	return;
}

#endif /* CONFIG_DRIVER_PRX300 */

#endif /* CONFIG_LTQ_SECURE_BOOT */

#ifdef CONFIG_QSPI_NAND_LANTIQ
/* idx:  Index
 * v_a:  Virtual address mapping
 * p_a:  Physical address to be mapped
 * pm:	 Page Mask
 * at:	 C, D, V, G Values
 * asid: Address Space Identifier
*/
void config_tlb(u32 idx, u32 v_a, u32 p_a, u32 pm, u32 at, u32 asid)
{
	u32 entry_hi;
	u32 entry_lo0, entry_lo1;
	entry_hi = v_a | asid;
	entry_lo0 = ((p_a >> 6) & (~0x3f)) | at;  //page 0
	entry_lo1 = ((p_a >> 6) & (~0x3f)) | at; //page 1 = page 0

	write_c0_entryhi(entry_hi);
	asm volatile ("tlbwi");
	asm volatile ("ehb") ;

	write_c0_index(idx);
	write_c0_pagemask(pm);
	write_c0_entrylo0(entry_lo0);
	write_c0_entrylo1(entry_lo1);
	asm volatile ("tlbwi");
	asm volatile ("ehb") ;
}
#endif /* CONFIG_QSPI_NAND_LANTIQ */

static int nand_load(struct mtd_info *mtd, unsigned int offs,
		     unsigned int uboot_size, uchar *dst)
{
	unsigned int block, lastblock;
	unsigned int page;
	struct nand_chip *chip = mtd_to_nand(mtd);

	/*
	 * offs has to be aligned to a page address!
	 */
	block = offs / CONFIG_SYS_NAND_BLOCK_SIZE;
	lastblock = (offs + uboot_size - 1) / CONFIG_SYS_NAND_BLOCK_SIZE;
	page = (offs % CONFIG_SYS_NAND_BLOCK_SIZE) / CONFIG_SYS_NAND_PAGE_SIZE;

	while (block <= lastblock) {
		if (!chip->block_bad(mtd, offs)) {
			/*
			 * Skip bad blocks
			 */
			while (page < CONFIG_SYS_NAND_PAGE_COUNT) {
				chip->ecc.read_page(mtd, chip,
						dst, 0, (block * CONFIG_SYS_NAND_PAGE_COUNT + page));
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

#if defined(XRX500_PRX300_DRIVER) && !defined(BOOT_4KEC_ONLY)
    /* Since IAP has already initialised the H/W, we do not want to
     * reset the nand datapath when 4kec boots. Otherwise, there will
     * be an unknown state for the controller when IAP access the EBU bus
     */
    if (!cpu_is_cps())
        goto cpy_bootcore;
#endif

	memset(&nand_chip, 0, sizeof(struct nand_chip));

#ifdef CONFIG_SYS_MALLOC_F_LEN
	gd->malloc_base = CONFIG_SYS_SPL_MALLOC_START;
	gd->malloc_ptr = 0;
	gd->malloc_limit = CONFIG_SYS_SPL_MALLOC_START +
				CONFIG_SYS_MALLOC_F_LEN;
#endif

	mem_malloc_init(CONFIG_SYS_SPL_MALLOC_START,
			CONFIG_SYS_MALLOC_F_LEN);

	/*
	 * Init board specific nand support
	 */
	mtd_data->priv = &nand_chip;
	board_nand_init(&nand_chip);

	if (nand_chip.select_chip)
		nand_chip.select_chip(mtd_data, 0);

#ifdef CONFIG_QSPI_NAND_LANTIQ
	/* Map 0xb0000000 to VA 0x00000000 */
	config_tlb(16, 0x00000000, 0xb0000000, 0x7FFE000, 0x16, 0x08);
#endif /* CONFIG_QSPI_NAND_LANTIQ */

#ifdef CONFIG_GIGA_DEVICE_SPINAND
        struct  spinand_info *spinand_info = (struct spinand_info*) nand_chip.priv;
        spinand_info->options |= GIGADEVICE_DUMMY_TYPE;
#endif

	/* Send the command for reading device ID */
	nand_chip.cmdfunc(mtd_data, NAND_CMD_READID, 0x00, -1);

	/* Set the internal flash config. This enables the
	 * different modes the flash is allowed to operate in.
	 */
	nand_chip.cmdfunc(mtd_data, NAND_CMD_SET_CONFIG, -1, -1);

	mtd_data->size = CONFIG_NAND_FLASH_SIZE * (1 << 20);
	mtd_data->erasesize = CONFIG_NAND_BLOCK_SIZE;
	mtd_data->writesize = CONFIG_NAND_PAGE_SIZE;
	mtd_data->oobsize = 64;
	nand_chip.page_shift = ffs(mtd_data->writesize)-1;
	nand_chip.bbt_erase_shift = ffs(mtd_data->erasesize)-1;
	nand_chip.numchips = 1;
	nand_chip.chipsize = mtd_data->size;
	nand_chip.oob_poi = (uint8_t *) &oob_buf;

cpy_bootcore:
#if !defined(BOOT_4KEC_ONLY) && defined(XRX500_PRX300_DRIVER)
    if (cpu_is_cps()) {
#endif /* BOOT_4KEC_ONLY && XRX500_PRX300_DRIVER */

    /*
	 * Load U-Boot image from NAND into RAM
	 */
#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(XRX500_PRX300_DRIVER) && !defined(CONFIG_MANUBOOT)
        ret = nand_load(mtd_data, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
                        (uchar *)0xa0800000);
#else
        ret = nand_load(mtd_data, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
						(uchar *)CONFIG_SYS_NAND_U_BOOT_DST);
#endif /* CONFIG_LTQ_SECURE_BOOT && XRX500_PRX300_DRIVER */
	if (ret)
		while(1);

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

#ifndef CONFIG_MANUBOOT
#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(XRX500_PRX300_DRIVER)
    #if defined(BOOT_4KEC_ONLY)
	bootrom_auth(0xa0800000);
    #else /* defined(CONFIG_GRX500_BOOT_4KEC_ONLY) */
	/* Inform 4kec , to auth img */
	REG32(SRAMFLAG) = IPCMAGIC;
	/* wait for reply , assume during delay, SRAMFLAG will be cleared by 4kec */
	mdelay(200);
	while (REG32(SRAMFLAG) != (~IPCMAGIC));
	REG32(SRAMFLAG) = 0;
	asm("sync");
    #endif /* defined(BOOT_4KEC_ONLY) */
#endif /* CONFIG_LTQ_SECURE_BOOT && XRX500_PRX300_DRIVER */
#endif /* CONFIG_MANUBOOT */
	/*
	 * Jump to U-Boot image
	 */
	uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
	(*uboot)();

#if !defined(BOOT_4KEC_ONLY) && defined(XRX500_PRX300_DRIVER)
	} else {
		ulong load_address;
		ulong ddr_address, bootcore_size;

		asm("sync");
		load_address = REG32(MPS_LOAD_ADDR); /* 4Kec load addr */
		ddr_address = REG32(MPS_DDR_LOC);	 /* ddr where TOS is copied to */
		bootcore_size = REG32(MPS_SIZE_LOC); /* size of TOS/bootcore img */

		if (bootcore_size > MAX_BOOTCORE_SIZE)
			while(1);

		#if defined(CONFIG_LTQ_SECURE_BOOT)
		/* reuse ddr loc only */
		#ifdef CONFIG_DRIVER_PRX300
		bootrom_auth_tos((u32)ddr_address);
		#else /* CONFIG_DRIVER_PRX300 */
		bootrom_auth((u32)ddr_address);
		#endif /* CONFIG_DRIVER_PRX300 */

		/* clear load address and size */
		load_address ^= load_address;
		bootcore_size ^= bootcore_size;

		/* in case we come here, the bootcore is signed with no jump attr */
		/* the correct way is to sign with dump entry/target attr but we just */
		/* have to assume here. force jump to predefined address 0x88000000 */
		uboot = (void *)BOOTCORE_LINUX_JUMP_ADDR;
		(*uboot)();
		#else /* defined(CONFIG_LTQ_SECURE_BOOT) */
		ulong jump_address;

		memcpy((unsigned char *) load_address,
				(unsigned char *)ddr_address,
				bootcore_size);

		ret = check_4kec_header(load_address,
					(u32 *) &jump_address,
					bootcore_size);
		if (ret)
			while(1); // if img is bad, we prevent 4kec from loading it

		uboot = (void*)jump_address;
		(*uboot)();
		#endif /* defined(CONFIG_LTQ_SECURE_BOOT)*/
	}
#endif /* BOOT_4KEC_ONLY  && XRX500_PRX300_DRIVER */
}
