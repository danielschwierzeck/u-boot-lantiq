/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <image.h>
#include <version.h>
#include <spi_flash.h>
#include <nand.h>
#include <linux/compiler.h>
#include <lzma/LzmaTools.h>
#include <linux/lzo.h>
#include <asm/mipsregs.h>
#include <asm/lantiq/spl.h>
#include <asm/lantiq/cpu.h>
#include <asm/lantiq/mem.h>

struct spl_image {
	ulong entry_addr;
	ulong data_size;
	ulong entry_size;
	ulong data_crc;
	u8 comp;
};

DECLARE_GLOBAL_DATA_PTR;
static struct spi_flash spl_spi_flash;

#if spl_boot_nand_flash || spl_boot_hsnand_flash
static u8 spl_mc_tune_buf[CONFIG_SYS_NAND_PAGE_SIZE];
#else
static u8 spl_mc_tune_buf[sizeof(struct mc_tune_cfg)];
#endif

static int spl_is_compressed(const struct spl_image *spl)
{
	if (spl->comp == IH_COMP_NONE)
		return 0;

#if defined(CONFIG_LTQ_SPL_COMP_LZO)
	return spl->comp == IH_COMP_LZO;
#elif defined(CONFIG_LTQ_SPL_COMP_LZMA)
	return spl->comp == IH_COMP_LZMA;
#endif

	spl_puts("SPL: unsupported compression type\n");

	return -1;
}

static void spl_console_init(void)
{
	if (!spl_has_console)
		return;

	gd->flags |= GD_FLG_RELOC;
	gd->baudrate = CONFIG_BAUDRATE;

	serial_init();

	gd->have_console = 1;

	spl_puts("\nU-Boot SPL " PLAIN_VERSION " (" U_BOOT_DATE " - " \
		U_BOOT_TIME ")\n");
}

static int spl_parse_image(const image_header_t *hdr, struct spl_image *spl)
{
	spl_puts("SPL: checking U-Boot image\n");

	if (!image_check_magic(hdr)) {
		spl_puts("SPL: invalid magic\n");
		return -1;
	}

        if (!image_check_hcrc(hdr)) {
		spl_puts("SPL: invalid header CRC\n");
		return -1;
	}

	spl->entry_addr = image_get_load(hdr);
	spl->data_size = image_get_data_size(hdr);
	spl->data_crc = image_get_dcrc(hdr);
	spl->comp = image_get_comp(hdr);

	spl_debug("SPL: size %lu, entry %08lx, comp %u\n",
		spl->data_size, spl->entry_addr, spl->comp);

	return 0;
}

static int spl_check_data(const struct spl_image *spl, unsigned long addr)
{
	ulong dcrc = crc32(0, (unsigned char *)addr, spl->data_size);

	if (dcrc != spl->data_crc) {
		spl_puts("SPL: invalid data CRC\n");
		return 0;
	}

	return 1;
}

static int spl_copy_image(struct spl_image *spl, unsigned long addr)
{
	spl_puts("SPL: copying U-Boot to RAM\n");

	memcpy((void *) spl->entry_addr, (const void *)addr, spl->data_size);
	spl->entry_size = spl->data_size;

	return 0;
}

static int spl_uncompress(struct spl_image *spl, unsigned long addr)
{
	size_t len = CONFIG_SYS_LOAD_SIZE;
	int ret;

#if defined(CONFIG_LTQ_SPL_COMP_LZO)
	spl_puts("SPL: decompressing U-Boot with LZO\n");

	ret = lzop_decompress(
		(const unsigned char*)addr, spl->data_size,
		(unsigned char *) spl->entry_addr, &len);

#elif defined(CONFIG_LTQ_SPL_COMP_LZMA)
	spl_puts("SPL: decompressing U-Boot with LZMA\n");

	ret = lzmaBuffToBuffDecompress(
		(unsigned char *)spl->entry_addr, &len,
		(unsigned char *)addr, spl->data_size);

#endif
	spl->entry_size = len;

	return ret;
}

static int spl_load_spi_flash(struct spl_image *spl)
{
	image_header_t hdr;
	int ret;
	unsigned long loadaddr;
	unsigned long addr = CONFIG_SPL_U_BOOT_OFFS;

	/*
	 * Image format:
	 *
	 * - 20 byte non-volatile bootstrap header
	 * - SPL binary
	 * - 12 byte non-volatile bootstrap header
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl_debug("SPL: reading image header at offset %lx\n", addr);
	ret = spi_flash_read(&spl_spi_flash, addr, sizeof(hdr), &hdr);
	if (ret)
		return ret;

	ret = spl_parse_image(&hdr, spl);
	if (ret)
		return ret;

	if (spl_is_compressed(spl))
		loadaddr = CONFIG_LOADADDR;
	else
		loadaddr = spl->entry_addr;

	spl_puts("SPL: loading U-Boot to RAM\n");

	/* skip U-Boot mkimage header */
	addr += image_get_header_size();
	ret = spi_flash_read(&spl_spi_flash, addr, spl->data_size,
		(void *)loadaddr);
	if (ret)
		return ret;

	if (!spl_check_data(spl, loadaddr))
		return -1;

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, loadaddr);

	return ret;
}

static int spl_load_nor_flash(struct spl_image *spl)
{
	image_header_t hdr;
	int ret;
	unsigned long addr = CONFIG_SPL_U_BOOT_OFFS;

#if spl_boot_nor_flash
	addr += CONFIG_SYS_FLASH_BASE;
#endif

	/*
	 * Image format:
	 *
	 * - SPL binary
	 * - TPL binary
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl_debug("SPL: reading image header at offset %lx\n", addr);
	memcpy(&hdr, (const void *)addr, sizeof(hdr));

	ret = spl_parse_image(&hdr, spl);
	if (ret)
		return ret;

	spl_puts("SPL: loading U-Boot to RAM\n");

	/* skip U-Boot mkimage header */
	addr += image_get_header_size();

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, addr);
	else
		ret = spl_copy_image(spl, addr);

	return ret;
}

static int spl_load_nand_flash(struct spl_image *spl)
{
	const image_header_t *hdr;
	int ret;
	unsigned long loadaddr = CONFIG_LOADADDR;

	/*
	 * Image format:
	 *
	 * - 20 byte non-volatile bootstrap header
	 * - SPL binary
	 * - 12 byte non-volatile bootstrap header
	 * - padding bytes up to CONFIG_SYS_NAND_TPL_OFFS
	 * - TPL binary
	 * - padding bytes up to CONFIG_SYS_NAND_U_BOOT_OFFS
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl_puts("SPL: loading U-Boot to RAM\n");

	nand_spl_load_image(CONFIG_SPL_U_BOOT_OFFS,
		CONFIG_SPL_U_BOOT_SIZE, (void *)loadaddr);

	hdr = (const image_header_t *)loadaddr;
	ret = spl_parse_image(hdr, spl);
	if (ret)
		return ret;

	/* skip U-Boot mkimage header */
	loadaddr += image_get_header_size();

	if (!spl_check_data(spl, loadaddr))
		return 1;

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, loadaddr);
	else
		ret = spl_copy_image(spl, loadaddr);

	return ret;
}

static int spl_load_hsnand_flash(struct spl_image *spl)
{
	const image_header_t *hdr;
	const int image_cnt = 1 + spl_redund_images;
	int ret, image_num;
	unsigned long loadaddr = CONFIG_LOADADDR;
	unsigned long addr, eb_size = 0;

	/*
	 * Image format:
	 *
	 * image_cnt = 1 + CONFIG_LTQ_SPL_REDUND_IMAGES
	 * image_num = [0 .. (image_cnt - 1)]
	 *
	 * for each erase block starting at offset
	 * image_num * CONFIG_SYS_NAND_BLOCK_SIZE:
	 *
	 * - SPL binary (32 KiB with checksum)
	 * - SPL binary (32 KiB with checksum)
	 * - SPL binary (32 KiB with checksum)
	 * - padding bytes up to CONFIG_SYS_NAND_BLOCK_SIZE
	 *
	 * for each erase block starting at offset
	 * CONFIG_SYS_NAND_BLOCK_SIZE * image_cnt + image_num *
	 * roundup(CONFIG_SPL_U_BOOT_SIZE, CONFIG_SYS_NAND_BLOCK_SIZE):
	 *
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl_puts("SPL: loading U-Boot to RAM\n");
#if spl_boot_hsnand_flash
	eb_size = CONFIG_SYS_NAND_BLOCK_SIZE;
#endif
	addr = image_cnt * eb_size;
	hdr = (const image_header_t *)loadaddr;

	for (image_num = 0; image_num < image_cnt; image_num++) {
		spl_debug("SPL: reading U-Boot image at offset %lx\n", addr);

		ret = nand_spl_load_image(addr, CONFIG_SPL_U_BOOT_SIZE,
			(void *)loadaddr);

		addr += round_up(CONFIG_SPL_U_BOOT_SIZE, eb_size);

		if (ret) {
			spl_puts("SPL: ECC error\n");
			continue;
		}

		ret = spl_parse_image(hdr, spl);
		if (ret)
			continue;

		if (spl_check_data(spl, loadaddr + image_get_header_size())) {
			ret = 0;
			break;
		} else {
			ret = -1;
			continue;
		}
	}

	/* return if no valid image could be found */
	if (ret)
		return 1;

	/* skip U-Boot mkimage header */
	loadaddr += image_get_header_size();

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, loadaddr);
	else
		ret = spl_copy_image(spl, loadaddr);

	return ret;
}

static int spl_load(struct spl_image *spl)
{
	if (spl_boot_spi_flash)
		return spl_load_spi_flash(spl);

	if (spl_boot_nor_flash)
		return spl_load_nor_flash(spl);

	if (spl_boot_nand_flash)
		return spl_load_nand_flash(spl);

	if (spl_boot_hsnand_flash)
		return spl_load_hsnand_flash(spl);

	return 1;
}

static int spl_load_mem_ctrl_cfg(void)
{
	struct mc_tune_cfg *cfg = (struct mc_tune_cfg *)spl_mc_tune_buf;
	int err = 0;

	if (spl_boot_hsnand_flash)
		return 1;

	spl_debug("SPL: loading MC tune data from flash\n");

#if spl_boot_spi_flash && spl_mc_tune
	spi_flash_read(&spl_spi_flash, CONFIG_SPL_MC_TUNE_OFFS,
		sizeof(*cfg), spl_mc_tune_buf);
#endif

#if spl_boot_nor_flash && spl_mc_tune
	memcpy(spl_mc_tune_buf, (const void *)(CONFIG_SPL_MC_TUNE_OFFS +
		CONFIG_SYS_FLASH_BASE), sizeof(*cfg));
#endif

#if spl_boot_nand_flash && spl_mc_tune
	nand_spl_load_image(CONFIG_SPL_MC_TUNE_OFFS,
		CONFIG_SYS_NAND_PAGE_SIZE, spl_mc_tune_buf);
#endif

	err = mc_tune_check(cfg);
	if (err)
		return 1;

	if (cfg->state != MC_TUNE_VALID_STORED)
		return 1;

	return 0;
}

void __noreturn spl_lantiq_init(void)
{
	void (*uboot)(void) __noreturn;
	struct spl_image spl;
	struct mc_tune_cfg *mc_tune_cfg;
	gd_t gd_data;
	int ret;

	gd = &gd_data;
	barrier();
	memset((void *)gd, 0, sizeof(gd_t));

	ltq_cgu_init();
	ltq_mem_init();
	mips_cache_reset();
	spl_console_init();
	board_early_init_f();

#if spl_boot_spi_flash
	spl_debug("SPL: probing SPI flash\n");
	spi_init();
	spl_spi_flash_probe(&spl_spi_flash);
#endif

#if spl_boot_nand_flash
	spl_debug("SPL: initializing NAND flash\n");
	nand_init();
#endif

	if (spl_mc_tune) {
		mc_tune_cfg = (struct mc_tune_cfg *)spl_mc_tune_buf;
		ret = spl_load_mem_ctrl_cfg();
		if (ret) {
			spl_puts("SPL: tuning DDR SDRAM\n");
			ret = mc_tune_perform(mc_tune_cfg);
		} else {
			spl_puts("SPL: applying tuned DDR SDRAM settings\n");
			mc_tune_apply(mc_tune_cfg);
		}
		if (!ret) {
			mc_tune_dump(mc_tune_cfg);
			mc_tune_store_ram(mc_tune_cfg);
		}
	}

#if spl_boot_hsnand_flash
	spl_debug("SPL: initializing NAND flash\n");
	nand_init();
#endif

#ifdef CONFIG_SYS_SPL_MALLOC_START
	mem_malloc_init(CONFIG_SYS_SPL_MALLOC_START,
			CONFIG_SYS_SPL_MALLOC_SIZE);
#endif

	memset(&spl, 0, sizeof(spl));

	ret = spl_load(&spl);
	if (ret)
		goto hang;

	spl_debug("SPL: U-Boot entry %08lx\n", spl.entry_addr);
	spl_puts("SPL: jumping to U-Boot\n");

	flush_cache(spl.entry_addr, spl.entry_size);

	uboot = (void *) spl.entry_addr;
	uboot();

hang:
	spl_puts("SPL: cannot start U-Boot\n");

	for (;;)
		;
}

#if defined(CONFIG_TPL)
void __noreturn tpl_load_image(void)
{
	void (*tpl)(void) __noreturn;

#if spl_boot_nor_flash
	memcpy((void *)CONFIG_TPL_TEXT_BASE,
		(const void *)(CONFIG_SYS_FLASH_BASE + CONFIG_SPL_TPL_OFFS),
		CONFIG_SPL_TPL_SIZE);
#endif
#if spl_boot_nand_flash
	nand_init();
	nand_spl_load_image(CONFIG_SPL_TPL_OFFS, CONFIG_SPL_TPL_SIZE,
		(void *)CONFIG_TPL_TEXT_BASE);
#endif

	tpl = (void *)CONFIG_TPL_TEXT_BASE;
	tpl();
}
#endif
