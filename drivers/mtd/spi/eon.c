/*
 * (C) Copyright 2010, ucRobotics Inc.
 * Author: Chong Huang <chuang@ucrobotics.com>
 * Licensed under the GPL-2 or later.
 */

#include <common.h>
#include <malloc.h>
#include <spi_flash.h>

#include "spi_flash_internal.h"

#define EN25XX_EN4B		0xb7	/* Enter 4-byte mode */

struct eon_spi_flash_params {
	u16 idcode;
	u16 nr_sectors;
	const char *name;
};

static const struct eon_spi_flash_params eon_spi_flash_table[] = {
	{
		.idcode = 0x3016,
		.nr_sectors = 1024,
		.name = "EN25Q32B",
	},
	{
		.idcode = 0x3018,
		.nr_sectors = 4096,
		.name = "EN25Q128",
	},
	{
		.idcode = 0x7019,
		.nr_sectors = 8192,
		.name = "EN25QH256",
	},
};

static __maybe_unused int eon_set_4byte_mode(struct spi_flash *flash)
{
	struct spi_slave *spi = flash->spi;

	return spi_flash_cmd(spi, EN25XX_EN4B, NULL, 0);
}

int spi_flash_probe_eon(struct spi_flash *flash, u8 *idcode)
{
	const struct eon_spi_flash_params *params;
	unsigned int i;
	u16 id = idcode[2] | idcode[1] << 8;

	for (i = 0; i < ARRAY_SIZE(eon_spi_flash_table); ++i) {
		params = &eon_spi_flash_table[i];
		if (params->idcode == id)
			break;
	}

	if (i == ARRAY_SIZE(eon_spi_flash_table)) {
		debug("SF: Unsupported EON ID %02x\n", idcode[1]);
		return 0;
	}

	flash->priv = (void *)params;
	flash->name = params->name;

	flash->write = spi_flash_cmd_write_multi;
	flash->erase = spi_flash_cmd_erase;
	flash->read = spi_flash_cmd_read_fast;
	flash->page_size = 256;
	flash->sector_size = 256 * 16 * 16;
	flash->size = 256 * 16
	    * params->nr_sectors;

#ifdef CONFIG_SPI_FLASH_4BYTE_MODE
	if (flash->size > (1 << 24))
		flash->set_4byte_mode = eon_set_4byte_mode;
#endif

	return 1;
}
