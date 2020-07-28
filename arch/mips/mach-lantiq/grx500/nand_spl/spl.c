// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2015-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <nand.h>
#include <image.h>
#include <version.h>
#include <linux/lzo.h>
#include <asm/io.h>
#include <asm/mipsregs.h>
#include <mach/grx500.h>
#include <mach/boot.h>

extern void start_interaptiv(u32 addr);
extern void ibl(u32 cpu_num);

DECLARE_GLOBAL_DATA_PTR;

#if defined(CONFIG_LTQ_SPL_REDUND_IMAGES)
#define spl_redund_images	CONFIG_LTQ_SPL_REDUND_IMAGES
#else
#define spl_redund_images	0
#endif
#define spl_has_console		1
#define spl_has_debug		0

#define spl_debug(fmt, args...)			\
	do {					\
		if (spl_has_debug)		\
			printf(fmt, ##args);	\
	} while (0)

#define spl_puts(msg)				\
	do {					\
		if (spl_has_console)		\
			puts(msg);		\
	} while (0)

struct spl_image {
	ulong entry_addr;
	ulong data_size;
	ulong entry_size;
	ulong data_crc;
	u8 comp;
};

static __noreturn void set_core_idle(void)
{
	while (true)
		r4k_wait_irqoff();
}

static bool spl_is_compressed(const struct spl_image *spl)
{
	if (spl->comp == IH_COMP_NONE)
		return false;

	if (spl->comp == IH_COMP_LZO)
		return true;

	spl_puts("SPL: unsupported compression type\n");

	return -1;
}

static void spl_console_init(void)
{
	if (!spl_has_console)
		return;

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
	size_t len = 1 * 1024 * 1024;
	int ret;

	spl_puts("SPL: decompressing U-Boot with LZO\n");

	ret = lzop_decompress(
		(const unsigned char*)addr, spl->data_size,
		(unsigned char *) spl->entry_addr, &len);
	spl->entry_size = len;

	return ret;
}

static int spl_load_nand_flash(struct spl_image *spl)
{
	const image_header_t *hdr;
	const int image_cnt = 1 + spl_redund_images;
	int ret, image_num;
	unsigned long loadaddr = CONFIG_SPL_LOAD_ADDR;
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
	 * for each erase block starting at offset
	 * CONFIG_SYS_NAND_BLOCK_SIZE * image_cnt + image_num *
	 * roundup(CONFIG_SPL_U_BOOT_SIZE, CONFIG_SYS_NAND_BLOCK_SIZE):
	 *
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl_puts("SPL: loading U-Boot to RAM\n");

	eb_size = CONFIG_SYS_NAND_BLOCK_SIZE;
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

void __noreturn nand_boot(void)
{
	void (*uboot)(void) __noreturn;
	struct spl_image spl;
	int ret;

	spl_console_init();
	board_early_init_f();

	spl_puts("SPL: initializing NAND flash\n");
	nand_init();

	memset(&spl, 0, sizeof(spl));
	ret = spl_load_nand_flash(&spl);
	if (ret)
		goto hang;

	flush_cache(spl.entry_addr, spl.entry_size);

	spl_debug("SPL: U-Boot entry %08lx\n", spl.entry_addr);
	spl_puts("SPL: jumping to U-Boot\n");

	uboot = (void *) spl.entry_addr;
	uboot();

hang:
	spl_puts("SPL: cannot start U-Boot\n");

	for (;;)
		;
}

void main(u32 cpu_num)
{
	int i;

	switch (cpu_num) {
	case 8:
#if 0
		/* fix FMT registers */
		REG32(0xB49001D0) = 0xF8002000;
		REG32(0xB49001D4) = 0xF8002800;
		REG32(0xB49001D8) = 0xFE00A000;
#endif

#if 1
		REG32(SRAMFLAG) = 0;
		start_interaptiv(CONFIG_SPL_TEXT_BASE);

		while (true)
			r4k_wait_irqoff();
#else
		nand_boot();
#endif
		break;

	case 0:
		for (i = 0; i < 4; i++) {
			REG32(CPUMSG + 4 * i) = 0;
			REG32(INTMSG + 4 * i) = 0;
			REG32(JMPMSG + 4 * i) = 0;
		}

		REG32(CPUMSG) += 1;
		nand_boot();
		break;
	default:
		ibl(cpu_num);
		break;
	}
}
