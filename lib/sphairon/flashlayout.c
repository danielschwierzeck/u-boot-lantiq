// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <linux/list.h>
#include <linux/mtd/mtd.h>

#include <sas/flashlayout.h>
#include <sas/util.h>
#include <sas/flash.h>
#include <sas/etl.h>

#if defined(CONFIG_ENV_OFFSET) && defined(CONFIG_ENV_SECT_SIZE)
#define UBOOT_ENV_OFFSET		CONFIG_ENV_OFFSET
#define UBOOT_ENV_SECT_SIZE		CONFIG_ENV_SECT_SIZE
#else
#define UBOOT_ENV_OFFSET		0
#define UBOOT_ENV_SECT_SIZE		0
#endif

#if defined(CONFIG_SPHAIRON_UGW_CALIBRATION)
#define init_ugw_calibration		1
#else
#define init_ugw_calibration		0
#endif

#if defined(CONFIG_SPHAIRON_MSTC_UBISQD)
#define init_mstc_ubisqd		1
#else
#define init_mstc_ubisqd		0
#endif

#if defined(CONFIG_SPHAIRON_MSTC_UBISQ)
#define init_mstc_ubisq			1
#else
#define init_mstc_ubisq			0
#endif

#define SYSCFG_MIN_SIZE			(512 * 1024)

struct sas_layout_map {
	const char name[7];
	const char desc[48];
};

static enum sas_flash_layout_type sas_flash_layout;

static int sas_flash_layout_static_part_init(enum sas_flash_part_type type)
{
	struct sas_flash_partition *part;
	int err;

	part = sas_flash_part_create(type);
	if (!part)
		return 1;

	err = sas_flash_part_mtdparts_sync(part);
	if (err)
		return 1;

	err = sas_flash_part_mtd_register(part);
	if (err)
		return 1;

	sas_flash_part_add(part);

	return 0;
}

int sas_flash_layout_static_init(int init_flash_minimal)
{
	struct mtd_info *storage_mtd;
	int err;

	sas_flash_layout = SAS_LAYOUT_BASIC;

	err = sas_flash_layout_static_part_init(SAS_PART_UBOOT_FIX);
	if (err)
		return 1;

	if (init_flash_minimal)
		return 0;

	if (UBOOT_ENV_OFFSET) {
		err = sas_flash_layout_static_part_init(SAS_PART_UBOOT_CFG);
		if (err)
			return 1;
	}

	if (init_mstc_ubisq) {
		err = sas_flash_layout_static_part_init(SAS_PART_DATA);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_RESERVED);
		if (err)
			return 1;
	}

	if (init_mstc_ubisq || init_ugw_calibration) {
		err = sas_flash_layout_static_part_init(SAS_PART_CALIBRATION);
		if (err)
			return 1;
	}

	if (sas_flash_ubi_support()) {
		err = sas_flash_layout_static_part_init(SAS_PART_UBI);
		if (err)
			return 1;
	}

	if (init_mstc_ubisqd) {
		err = sas_flash_layout_static_part_init(SAS_PART_RESERVED);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_CALIBRATION);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_DATA);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_SYSCFG);
		if (err)
			return 1;
	}

	if (init_mstc_ubisq || init_mstc_ubisqd) {
		err = sas_flash_layout_static_part_init(SAS_PART_ROMD);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_MRDCERT1);
		if (err)
			return 1;

		err = sas_flash_layout_static_part_init(SAS_PART_MRDCERT2);
		if (err)
			return 1;
	}

	storage_mtd = sas_flash_storage_device();
	if (storage_mtd) {
		err = sas_flash_layout_static_part_init(SAS_PART_STORAGE);
		if (err)
			return 1;
	}

	return 0;
}

static int sas_flash_layout_dynamic_part_add(struct mtd_info *mtd,
						enum sas_flash_part_type type,
						unsigned long offset,
						size_t size)
{
	struct sas_flash_partition *part;
	int err;

	debug("%s: mtd %s, type %s, offset %08lx, size %08zx\n", __func__,
		mtd->name, sas_flash_partition_str(type), offset, size);

	part = sas_flash_part_create(type);
	if (!part)
		return 1;

	err = sas_flash_part_mtdparts_add(mtd, part, size, offset);
	if (err)
		return 1;

	err = sas_flash_part_mtd_register(part);
	if (err)
		return 1;

	sas_flash_part_add(part);

	return 0;
}

int sas_flash_layout_dynamic_init(void)
{
	struct mtd_info *boot_mtd, *nand_mtd;
	struct mtd_info *data_mtd = NULL;
	const enum sas_flash_layout_type layout = sas_etl_flash_layout();
	size_t size, data_size = 0;
	loff_t offset, data_offset = 0;
	uint64_t available_size;
	uint32_t n;
	int err;

	boot_mtd = sas_flash_boot_device();
	nand_mtd = sas_flash_nand_device();

	debug("%s: boot_mtd %s, nand_mtd %s, layout %s\n",
		__func__, boot_mtd->name, nand_mtd ? nand_mtd->name : "none",
		sas_flash_layout_str(layout));

	offset = sas_flash_layout_dynamic_offset();

	if (sas_flash_layout_has_sysconfig_part(layout)) {
		size = SYSCFG_MIN_SIZE;

		err = sas_flash_layout_dynamic_part_add(boot_mtd,
			SAS_PART_SYSCFG1, offset, size);
		if (err)
			return 1;

		offset += size;

		if (sas_flash_layout_is_mirrored(layout)) {
			err = sas_flash_layout_dynamic_part_add(boot_mtd,
				SAS_PART_SYSCFG2, offset, size);
			if (err)
				return 1;

			offset += size;
		}
	}

	switch (sas_etl_data_part_loc()) {
	case DATA_PART_LOC_BOOT:
		if (sas_flash_layout_has_data_part(layout)) {
			data_mtd = boot_mtd;
			data_size = sas_etl_data_part_size();
			data_offset = offset;
			offset += data_size;
		}
		break;
	case DATA_PART_LOC_NAND:
		if (!nand_mtd)
			return 1;

		if (sas_flash_layout_has_data_part(layout)) {
			data_mtd = nand_mtd;
			data_size = nand_mtd->size;
			data_offset = 0;
		}
		break;
	case DATA_PART_LOC_AUTO:
		if (nand_mtd) {
			data_mtd = nand_mtd;
			data_size = nand_mtd->size;
			data_offset = 0;
		} else if (sas_flash_layout_has_data_part(layout)) {
			data_mtd = boot_mtd;
			data_size = sas_etl_data_part_size();
			data_offset = offset;
			offset += data_size;
		}
		break;
	default:
		return 1;
	}

	if (data_mtd) {
		err = sas_flash_layout_dynamic_part_add(data_mtd, SAS_PART_DATA,
			data_offset, data_size);
		if (err)
			return 1;
	}

	if (sas_flash_layout_has_image_parts(layout)) {
		available_size = boot_mtd->size - offset;

		if (sas_flash_layout_is_mirrored(layout)) {
			n = mtd_div_by_eb(available_size, boot_mtd);
			n >>= 1;
			size = n * boot_mtd->erasesize;
		}
		else
			size = available_size;

		err = sas_flash_layout_dynamic_part_add(boot_mtd,
			SAS_PART_IMAGES1, offset, size);
		if (err)
			return 1;

		if (sas_flash_layout_is_mirrored(layout)) {
			offset += size;

			err = sas_flash_layout_dynamic_part_add(boot_mtd,
				SAS_PART_IMAGES2, offset, size);
			if (err)
				return 1;
		}
	}

	sas_flash_layout = layout;

	return 0;
}

int sas_flash_layout_ubi_init(void)
{
	const enum sas_flash_layout_type layout = sas_etl_flash_layout();

	if (!sas_flash_layout_is_ubi(layout)) {
		puts("invalid UBI flash layout configured in ETL\n");
		return 1;
	}

	sas_flash_layout = layout;

	return 0;
}

void sas_flash_layout_print(void)
{
	sas_banner_header_print("Flash partition info");
	sas_banner_content_print("%-25s%-s ", "Used layout",
		sas_flash_layout_str(sas_flash_layout));
	sas_banner_line_print();
	sas_flash_partition_print();
	if (sas_flash_ubi_support())
		sas_flash_ubi_volume_print();
	sas_banner_footer_print();
}

loff_t sas_flash_layout_dynamic_offset(void)
{
	loff_t offset = UBOOT_ENV_OFFSET + UBOOT_ENV_SECT_SIZE;
	return offset;
}

struct sas_flash_partition *sas_flash_layout_image_partition(unsigned int index)
{
	const enum sas_flash_part_type type = index ?
					SAS_PART_IMAGES2 : SAS_PART_IMAGES1;

	return sas_flash_part_find(type);
}

enum sas_flash_layout_type sas_flash_layout_current(void)
{
	return sas_flash_layout;
}

static const struct sas_layout_map sas_flash_layout_strings[] = {
	{ "bas", "Basic" },
	{ "pos", "Platform only - single" },
	{ "pom", "Platform only - mirrored" },
	{ "pss", "Platform/Service - single" },
	{ "psm", "Platform/Service - mirrored" },
	{ "posd", "Platform only/Data - single" },
	{ "pomd", "Platform only/Data - mirrored" },
	{ "pssd", "Platform/Service/Data - single" },
	{ "psmd", "Platform/Service/Data - mirrored" },
	{ "ubisq", "UBI volumes with SquashFS images" },
	{ "ubisqd", "UBI Squashfs volumes/Data" },
	{ "", "invalid" }
};

const char* sas_flash_layout_name(enum sas_flash_layout_type layout)
{
	assert(layout <= SAS_LAYOUT_INVALID);

	return sas_flash_layout_strings[layout].name;
}

const char* sas_flash_layout_str(enum sas_flash_layout_type layout)
{
	assert(layout <= SAS_LAYOUT_INVALID);

	return sas_flash_layout_strings[layout].desc;
}

enum sas_flash_layout_type sas_flash_layout_parse(const char *str)
{
	unsigned int i;
	const char *name;

	if (!str)
		return SAS_LAYOUT_INVALID;

	for (i = 0; i < SAS_LAYOUT_INVALID; i++) {
		name = sas_flash_layout_strings[i].name;

		if (strcmp(name, str) == 0)
			return i;
	}

	return SAS_LAYOUT_INVALID;
}
