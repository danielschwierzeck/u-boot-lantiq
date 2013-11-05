/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2014 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <common.h>
#include <spi_flash.h>
#include <nand.h>
#include <asm/mipsregs.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/mem.h>
#include <asm/lantiq/spl.h>

/**
 * Test the data bus wiring by performing a walking 1's test at
 * the given offset.
 */
int ltq_mem_test_data_bus(phys_addr_t offset)
{
	u16 data, pattern;
	int ret = 0;

	for (pattern = 1; pattern != 0; pattern <<= 1) {
		sdram_uc_writew(offset, pattern);
		cpu_sync();

		data = sdram_uc_readw(offset);
		if (data != pattern) {
			debug("MEM: data bits error: %04x (pattern %04x)\n",
				data, pattern);
			ret = 1;
		}
	}

	return ret;
}

/**
 * Test the address bus wiring by performing a walking 1's test
 * at each power-of-two address and checking for aliasing. This
 * test will find single-bit address failures such as
 * stuck-high, stuck-low and shorted pins.
 */
int ltq_mem_test_address_bus(phys_size_t dram_size)
{
	const phys_addr_t addr_mask = (dram_size - 1);
	const u8 pattern1 = 0xaa;
	const u8 pattern2 = 0x55;
	phys_addr_t offset, offset_test;
	u8 data;
	int ret = 0;

	/*
	 * Write pattern to each power-of-two offset. Each offset must be
	 * aligned to 32 bit.
	 */
	for (offset = 1; (offset & addr_mask) != 0; offset <<= 1)
		sdram_uc_writeb(offset, pattern1);

	/* Check for address bits stuck high */
	sdram_uc_writeb(0, pattern2);
	cpu_sync();

	for (offset = 1; (offset & addr_mask) != 0; offset <<= 1) {
		data = sdram_uc_readb(offset);
		if (data != pattern1) {
			debug("MEM: %08x: address bits stuck high\n",
				offset);
			ret = 1;
		}
	}

	/* Check for address bits stuck low or shorted */
	sdram_uc_writeb(0, pattern1);
	cpu_sync();

	for (offset_test = 1; (offset_test & addr_mask) != 0; offset_test <<= 1) {
		sdram_uc_writeb(offset_test, pattern2);
		cpu_sync();

		data = sdram_uc_readb(0);
		if (data != pattern1) {
			debug("MEM: %08x: address bits stuck low or shorted\n",
				offset_test);
			ret = 1;
		}

		for (offset = 1; (offset & addr_mask) != 0; offset <<= 1) {
			data = sdram_uc_readb(offset);
			if (data != pattern1 && offset != offset_test) {
				debug("MEM: %08x: address bits stuck low or shorted\n",
					offset);
				ret = 1;
			}
		}

		sdram_uc_writeb(offset_test, pattern1);
		cpu_sync();
	}

	return ret;
}

/**
 * Test SDRAM device in the given region.
 */
int ltq_mem_test_device(phys_addr_t addr, phys_size_t size)
{
	phys_addr_t offset;
	u32 data, pattern;
	int ret = 0;

	/* Write default pattern */
	for (pattern = 1, offset = 0; offset < size; pattern++, offset += 4)
		sdram_uc_writel(offset, pattern);

	cpu_sync();

	/* Check each pattern in first pass */
	for (pattern = 1, offset = 0; offset < size; pattern++, offset += 4) {
		data = sdram_uc_readl(offset);
		if (data != pattern) {
			debug("MEM: %08x: data %08x != pattern %08x\n",
				offset, data, pattern);
			ret = 1;
		}

		sdram_uc_writel(offset, ~pattern);
	}

	cpu_sync();

	/* Check each inverted pattern in second pass */
	for (pattern = 1, offset = 0; offset < size; pattern++, offset += 4) {
		data = sdram_uc_readl(offset);
		if (data != ~pattern) {
			debug("MEM: %08x: data %08x != pattern %08x\n",
				offset, data, ~pattern);
			ret = 1;
		}
	}

	return ret;
}

static const u8 test_pattern_b[] = {
	0x55, 0x00, 0xfe, 0x01,
};

static const u16 test_pattern_w[] = {
	0x5555, 0xffff, 0x8000, 0x7fff,
};

static const u32 test_pattern_l[] = {
	0x5555aaaa, 0xFFFF0000, 0x80000001, 0x7ffffffe,
	0x12345678, 0x9ABCDEF0, 0xc3c3c3c3, 0xffffffff,
};

static unsigned long dcache_line_size(void)
{
	unsigned long conf1, dl;
	conf1 = read_c0_config1();
	dl = (conf1 & MIPS_CONF1_DL) >> MIPS_CONF1_DL_SHIFT;
	if (!dl)
		return 0;
	return 2 << dl;
}

int ltq_mem_test_tune(phys_size_t sdram_size, unsigned int slice,
				int quick)
{
	unsigned int j, k, l;
	phys_addr_t offset;
	u8 data_b, pattern_b;
	u16 mask_w, data_w, pattern_w;
	u32 mask_l, data_l, pattern_l;
	const unsigned long dcache_lsize = dcache_line_size();

	if (slice) {
		mask_w = 0xff00;
		mask_l = 0xff00ff00;
	} else {
		mask_w = 0x00ff;
		mask_l = 0x00ff00ff;
	}

	for (j = 0; j < 8; j++) {
		for (k = 0; k < 0x20; k += 4) {
			offset = (j << 16) + k;
			pattern_l = test_pattern_l[j];
			sdram_uc_writel(offset, pattern_l);

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_l = ~test_pattern_l[j];
			sdram_uc_writel(offset, pattern_l);
		}
	}

	cpu_sync();

	for (j = 0; j < 8; j++) {
		for (k = 0; k < 0x20; k += 4) {
			offset = (j << 16) + k;
			pattern_l = test_pattern_l[j];
			data_l = sdram_uc_readl(offset);
			if ((data_l & mask_l) != (pattern_l & mask_l)) {
				debug("MEM: %08x: data %08x != pattern %08x, mask %08x\n",
					offset, data_l, pattern_l, mask_l);
				return 1;
			}

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_l = ~test_pattern_l[j];
			data_l = sdram_uc_readl(offset);
			if ((data_l & mask_l) != (pattern_l & mask_l)) {
				debug("MEM: %08x: data %08x != pattern %08x, mask %08x\n",
					offset, data_l, pattern_l, mask_l);
				return 1;
			}
		}
	}

	if (quick)
		return 0;

	for (j = 0; j < 4; j++) {
		for (k = 0; k < 0x40; k += 2) {
			offset = (j << 16) + k;
			pattern_w = test_pattern_w[j];
			sdram_uc_writew(offset, pattern_w);

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_w = ~test_pattern_w[j] & 0xffff;
			sdram_uc_writew(offset, pattern_w);
		}
	}

	cpu_sync();

	for (j = 0; j < 4; j++) {
		for (k = 0; k < 0x40; k += 2) {
			offset = (j << 16) + k;
			pattern_w = test_pattern_w[j];
			data_w = sdram_uc_readw(offset);
			if ((data_w & mask_w) != (pattern_w & mask_w)) {
				debug("MEM: %08x: data %04x != pattern %04x, mask %04x\n",
					offset, data_w, pattern_w, mask_w);
				return 1;
			}

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_w = ~test_pattern_w[j] & 0xffff;
			data_w = sdram_uc_readw(offset);
			if ((data_w & mask_w) != (pattern_w & mask_w)) {
				debug("MEM: %08x: data %04x != pattern %04x, mask %04x\n",
					offset, data_w, pattern_w, mask_w);
				return 1;
			}
		}
	}

	for (j = 0; j < 4; j++) {
		for (k = 0; k < 0x80; k += 1) {
			offset = (j << 16) + k + slice;
			pattern_b = test_pattern_b[j];
			sdram_uc_writeb(offset, pattern_b);

			offset = (j << 16) + k + (sdram_size >> 1) + slice;
			pattern_b = ~test_pattern_b[j] & 0xff;
			sdram_uc_writeb(offset, pattern_b);
		}
	}

	cpu_sync();

	for (j = 0; j < 4; j++) {
		for (k = 0; k < 0x80; k += 1) {
			offset = (j << 16) + k + slice;
			pattern_b = test_pattern_b[j];
			data_b = sdram_uc_readb(offset);
			if (data_b != pattern_b) {
				debug("MEM: %08x: data %02x != pattern %02x\n",
					offset, data_b, pattern_b);
				return 1;
			}

			offset = (j << 16) + k + (sdram_size >> 1) + slice;
			pattern_b = ~test_pattern_b[j] & 0xff;
			data_b = sdram_uc_readb(offset);
			if (data_b != pattern_b) {
				debug("MEM: %08x: data %02x != pattern %02x\n",
					offset, data_b, pattern_b);
				return 1;
			}
		}
	}

	for (j = 0; j < 8; j++) {
		for (k = 0; k < 0x400; k += 4) {
			l = (j + (k >> 2) + 2) % 8;
			offset = (j << 16) + k;
			pattern_l = test_pattern_l[l];
			sdram_writel(offset, pattern_l);

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_l = ~test_pattern_l[l];
			sdram_writel(offset, pattern_l);

			if ((k % dcache_lsize) == 0)
				sdram_flush_dcache_line(j << 16, dcache_lsize);
		}
	}

	for (j = 0; j < 8; j++) {
		for (k = 0; k < 0x400; k += 4) {
			l = (j + (k >> 2) + 2) % 8;
			offset = (j << 16) + k;
			pattern_l = test_pattern_l[l];
			data_l = sdram_readl(offset);
			if ((data_l & mask_l) != (pattern_l & mask_l)) {
				debug("MEM: %08x (cached): data %08x != pattern %08x, mask %08x\n",
					offset, data_l, pattern_l, mask_l);
				return 1;
			}

			offset = (j << 16) + k + (sdram_size >> 1);
			pattern_l = ~test_pattern_l[l];
			data_l = sdram_readl(offset);
			if ((data_l & mask_l) != (pattern_l & mask_l)) {
				debug("MEM: %08x (cached): data %08x != pattern %08x, mask %08x\n",
					offset, data_l, pattern_l, mask_l);
				return 1;
			}
		}
	}

	return 0;
}

/* avoid usage of printf in SPL */
static void mc_tune_print(u8 a, u8 b)
{
	const char digits[] = "0123456789abcdef";
	char tmp[8];

	tmp[0] = digits[a >> 4];
	tmp[1] = digits[a & 0xf];
	tmp[2] = '/';
	tmp[3] = digits[b >> 4];
	tmp[4] = digits[b & 0xf];
	tmp[5] = '\n';
	tmp[6]= '\0';

	puts(tmp);
}

void mc_tune_dump(const struct mc_tune_cfg *cfg)
{
	if (spl_has_console) {
		puts("MEM: DDR Echo DLL delay:  ");
		mc_tune_print(cfg->gate_echo_dll_l, cfg->gate_echo_dll_u);
		puts("MEM: DDR Write DQS delay: ");
		mc_tune_print(cfg->write_dqs_delay_l, cfg->write_dqs_delay_u);
		puts("MEM: DDR Read DQS delay:  ");
		mc_tune_print(cfg->read_dqs_delay_l, cfg->read_dqs_delay_u);
	}
}

int mc_tune_check(const struct mc_tune_cfg *cfg)
{
	u32 crc;

	if (cfg->magic != MC_TUNE_MAGIC)
		return -1;

	crc = crc32(0, &cfg->state, sizeof(*cfg) -
		offsetof(struct mc_tune_cfg, state));
	if (crc != cfg->crc)
		return -1;

	return 0;
}

int mc_tune_load_ram(struct mc_tune_cfg *cfg)
{
	const void *addr = (const void *)CONFIG_SPL_MC_TUNE_BASE;

	memcpy(cfg, addr, sizeof(*cfg));
	return mc_tune_check(cfg);
}

void mc_tune_store_ram(struct mc_tune_cfg *cfg)
{
	void *addr = (void *)CONFIG_SPL_MC_TUNE_BASE;

	cfg->magic = MC_TUNE_MAGIC;
	cfg->crc = crc32(0, &cfg->state, sizeof(*cfg) -
		offsetof(struct mc_tune_cfg, state));

	memcpy(addr, cfg, sizeof(*cfg));
}

#if defined(CONFIG_LTQ_SPL_MC_TUNE)
int mc_tune_store_flash(void)
{
	struct mc_tune_cfg cfg;
	int err;

	err = mc_tune_load_ram(&cfg);
	if (err) {
		debug("MEM:   invalid MC tune data in RAM\n");
		return 0;
	}

	if (cfg.state == MC_TUNE_VALID_STORED) {
		debug("MEM:   MC tune data already stored in flash\n");
		return 0;
	}

	debug("MEM:   storing MC tune data to flash\n");

	cfg.state = MC_TUNE_VALID_STORED;
	cfg.crc = crc32(0, &cfg.state, sizeof(cfg) -
		offsetof(struct mc_tune_cfg, state));

#if spl_boot_spi_flash
	struct spi_flash sf;

	err = spl_spi_flash_probe(&sf);
	if (err)
		return 0;

	spi_flash_write(&sf, CONFIG_SPL_MC_TUNE_OFFS,
		sizeof(cfg), &cfg);
#endif

#if spl_boot_nand_flash
	nand_info_t *nand = &nand_info[0];
	size_t len = sizeof(cfg);

	nand_write(nand, CONFIG_SPL_MC_TUNE_OFFS, &len, (u_char *)&cfg);
#endif

#if spl_boot_nor_flash
	flash_write((char *)&cfg, CONFIG_SYS_FLASH_BASE +
		CONFIG_SPL_MC_TUNE_OFFS, sizeof(cfg));
#endif

	return 0;
}
#endif
