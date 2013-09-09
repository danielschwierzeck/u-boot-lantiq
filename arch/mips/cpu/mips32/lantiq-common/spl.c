/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <image.h>
#include <version.h>
#include <spi_flash.h>
#include <linux/compiler.h>
#include <lzma/LzmaDec.h>
#include <linux/lzo.h>
#include <asm/mipsregs.h>

#if defined(CONFIG_LTQ_SPL_CONSOLE)
#define spl_has_console		1

#if defined(CONFIG_LTQ_SPL_DEBUG)
#define spl_has_debug		1
#else
#define spl_has_debug		0
#endif

#else
#define spl_has_console		0
#define spl_has_debug		0
#endif

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

#if defined(CONFIG_LTQ_SUPPORT_SPL_SPI_FLASH) && defined(CONFIG_SYS_BOOT_SFSPL)
#define spl_boot_spi_flash	1
#else
#define spl_boot_spi_flash	0
#ifndef CONFIG_SPL_SPI_BUS
#define CONFIG_SPL_SPI_BUS	0
#endif
#ifndef CONFIG_SPL_SPI_CS
#define CONFIG_SPL_SPI_CS	0
#endif
#ifndef CONFIG_SPL_SPI_MAX_HZ
#define CONFIG_SPL_SPI_MAX_HZ	0
#endif
#ifndef CONFIG_SPL_SPI_MODE
#define CONFIG_SPL_SPI_MODE	0
#endif
#endif

#if defined(CONFIG_LTQ_SUPPORT_SPL_NOR_FLASH) && defined(CONFIG_SYS_BOOT_NORSPL)
#define spl_boot_nor_flash	1
#else
#define spl_boot_nor_flash	0
#endif

#define spl_sync()	__asm__ __volatile__("sync");

struct spl_image {
	ulong data_addr;
	ulong entry_addr;
	ulong data_size;
	ulong entry_size;
	ulong data_crc;
	u8 comp;
};

DECLARE_GLOBAL_DATA_PTR;

/* Emulated malloc area needed for LZMA allocator in BSS */
static u8 *spl_mem_ptr __maybe_unused;
static size_t spl_mem_size __maybe_unused;

static int spl_is_comp_lzma(const struct spl_image *spl)
{
#if defined(CONFIG_LTQ_SPL_COMP_LZMA)
	return spl->comp == IH_COMP_LZMA;
#else
	return 0;
#endif
}

static int spl_is_comp_lzo(const struct spl_image *spl)
{
#if defined(CONFIG_LTQ_SPL_COMP_LZO)
	return spl->comp == IH_COMP_LZO;
#else
	return 0;
#endif
}

static int spl_is_compressed(const struct spl_image *spl)
{
	if (spl_is_comp_lzma(spl))
		return 1;

	if (spl_is_comp_lzo(spl))
		return 1;

	return 0;
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

	spl->data_addr += image_get_header_size();
	spl->entry_addr = image_get_load(hdr);
	spl->data_size = image_get_data_size(hdr);
	spl->data_crc = image_get_dcrc(hdr);
	spl->comp = image_get_comp(hdr);

	spl_debug("SPL: data %08lx, size %lu, entry %08lx, comp %u\n",
		spl->data_addr, spl->data_size, spl->entry_addr, spl->comp);

	return 0;
}

static int spl_check_data(const struct spl_image *spl, ulong loadaddr)
{
	ulong dcrc = crc32(0, (unsigned char *)loadaddr, spl->data_size);

	if (dcrc != spl->data_crc) {
		spl_puts("SPL: invalid data CRC\n");
		return 0;
	}

	return 1;
}

static void *spl_lzma_alloc(void *p, size_t size)
{
	u8 *ret;

	if (size > spl_mem_size)
		return NULL;

	ret = spl_mem_ptr;
	spl_mem_ptr += size;
	spl_mem_size -= size;

	return ret;
}

static void spl_lzma_free(void *p, void *addr)
{
}

static int spl_copy_image(struct spl_image *spl)
{
	spl_puts("SPL: copying U-Boot to RAM\n");

	memcpy((void *) spl->entry_addr, (const void *) spl->data_addr,
		spl->data_size);

	spl->entry_size = spl->data_size;

	return 0;
}

static int spl_uncompress_lzma(struct spl_image *spl, unsigned long loadaddr)
{
	SRes res;
	const Byte *prop = (const Byte *) loadaddr;
	const Byte *src = (const Byte *) loadaddr + LZMA_PROPS_SIZE +
							sizeof(uint64_t);
	Byte *dest = (Byte *) spl->entry_addr;
	SizeT dest_len = 0xFFFFFFFF;
	SizeT src_len = spl->data_size - LZMA_PROPS_SIZE;
	ELzmaStatus status = 0;
	ISzAlloc alloc;

	spl_puts("SPL: decompressing U-Boot with LZMA\n");

	alloc.Alloc = spl_lzma_alloc;
	alloc.Free = spl_lzma_free;
	spl_mem_ptr = (u8 *) CONFIG_SPL_MALLOC_BASE;
	spl_mem_size = CONFIG_SPL_MALLOC_MAX_SIZE;

	res = LzmaDecode(dest, &dest_len, src, &src_len, prop, LZMA_PROPS_SIZE,
		LZMA_FINISH_ANY, &status, &alloc);
	if (res != SZ_OK)
		return 1;

	spl->entry_size = dest_len;

	return 0;
}

static int spl_uncompress_lzo(struct spl_image *spl, unsigned long loadaddr)
{
	size_t len;
	int ret;

	spl_puts("SPL: decompressing U-Boot with LZO\n");

	ret = lzop_decompress(
		(const unsigned char*) loadaddr, spl->data_size,
		(unsigned char *) spl->entry_addr, &len);

	spl->entry_size = len;

	return ret;
}

static int spl_uncompress(struct spl_image *spl, unsigned long loadaddr)
{
	int ret;

	if (spl_is_comp_lzma(spl))
		ret = spl_uncompress_lzma(spl, loadaddr);
	else if (spl_is_comp_lzo(spl))
		ret = spl_uncompress_lzo(spl, loadaddr);
	else
		ret = 1;

	return ret;
}

static int spl_load_spi_flash(struct spl_image *spl)
{
	struct spi_flash sf = { 0 };
	image_header_t hdr;
	int ret;
	unsigned long loadaddr;

	/*
	 * Image format:
	 *
	 * - 12 byte non-volatile bootstrap header
	 * - SPL binary
	 * - 12 byte non-volatile bootstrap header
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl->data_addr = image_copy_end() - CONFIG_SPL_TEXT_BASE + 24;

	spl_puts("SPL: probing SPI flash\n");

	spi_init();
	ret = spl_spi_flash_probe(&sf);
	if (ret)
		return ret;

	spl_debug("SPL: reading image header at offset %lx\n", spl->data_addr);

	ret = spi_flash_read(&sf, spl->data_addr, sizeof(hdr), &hdr);
	if (ret)
		return ret;

	spl_debug("SPL: checking image header at offset %lx\n", spl->data_addr);

	ret = spl_parse_image(&hdr, spl);
	if (ret)
		return ret;

	if (spl_is_compressed(spl))
		loadaddr = CONFIG_LOADADDR;
	else
		loadaddr = spl->entry_addr;

	spl_puts("SPL: loading U-Boot to RAM\n");

	ret = spi_flash_read(&sf, spl->data_addr, spl->data_size,
				(void *) loadaddr);

	if (!spl_check_data(spl, loadaddr))
		return -1;

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, loadaddr);

	return ret;
}

static int spl_load_nor_flash(struct spl_image *spl)
{
	const image_header_t *hdr;
	int ret;

	/*
	 * Image format:
	 *
	 * - SPL binary
	 * - 64 byte U-Boot mkimage header
	 * - U-Boot binary
	 */
	spl->data_addr = image_copy_end();
	hdr = (const image_header_t *) image_copy_end();

	spl_debug("SPL: checking image header at address %p\n", hdr);

	ret = spl_parse_image(hdr, spl);
	if (ret)
		return ret;

	if (spl_is_compressed(spl))
		ret = spl_uncompress(spl, spl->data_addr);
	else
		ret = spl_copy_image(spl);

	return ret;
}

static int spl_load(struct spl_image *spl)
{
	int ret;

	if (spl_boot_spi_flash)
		ret = spl_load_spi_flash(spl);
	else if (spl_boot_nor_flash)
		ret = spl_load_nor_flash(spl);
	else
		ret = 1;

	return ret;
}

void __noreturn spl_lantiq_init(void)
{
	void (*uboot)(void) __noreturn;
	struct spl_image spl;
	gd_t gd_data;
	int ret;

	gd = &gd_data;
	barrier();
	memset((void *)gd, 0, sizeof(gd_t));

	spl_console_init();

	spl_debug("SPL: initializing\n");

#if 0
	spl_debug("CP0_CONFIG:   %08x\n", read_c0_config());
	spl_debug("CP0_CONFIG1:  %08x\n", read_c0_config1());
	spl_debug("CP0_CONFIG2:  %08x\n", read_c0_config2());
	spl_debug("CP0_CONFIG3:  %08x\n", read_c0_config3());
	spl_debug("CP0_CONFIG6:  %08x\n", read_c0_config6());
	spl_debug("CP0_CONFIG7:  %08x\n", read_c0_config7());
	spl_debug("CP0_STATUS:   %08x\n", read_c0_status());
	spl_debug("CP0_PRID:     %08x\n", read_c0_prid());
#endif

	board_early_init_f();
	timer_init();

	memset(&spl, 0, sizeof(spl));

	ret = spl_load(&spl);
	if (ret)
		goto hang;

	spl_debug("SPL: U-Boot entry %08lx\n", spl.entry_addr);
	spl_puts("SPL: jumping to U-Boot\n");

	flush_cache(spl.entry_addr, spl.entry_size);
	spl_sync();

	uboot = (void *) spl.entry_addr;
	uboot();

hang:
	spl_puts("SPL: cannot start U-Boot\n");

	for (;;)
		;
}
