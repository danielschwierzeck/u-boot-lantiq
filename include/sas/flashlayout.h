/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_FLASHLAYOUT_H__
#define __SAS_FLASHLAYOUT_H__

enum sas_flash_layout_type {
	SAS_LAYOUT_BASIC = 0,
	SAS_LAYOUT_PLATFORM_ONLY_SINGLE,
	SAS_LAYOUT_PLATFORM_ONLY_MIRRORED,
	SAS_LAYOUT_PLATFORM_SERVICE_SINGLE,
	SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED,
	SAS_LAYOUT_PLATFORM_ONLY_SINGLE_DATA,
	SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA,
	SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA,
	SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA,
	SAS_LAYOUT_UBI_SQFS,
	SAS_LAYOUT_UBI_SQFS_DATA,
	SAS_LAYOUT_INVALID
};

struct mtd_info;

int sas_flash_layout_static_init(int init_flash_minimal);
int sas_flash_layout_dynamic_init(void);
int sas_flash_layout_ubi_init(void);

void sas_flash_layout_print(void);

loff_t sas_flash_layout_dynamic_offset(void);

static inline int
sas_flash_layout_is_bootable(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_BASIC:
	case SAS_LAYOUT_INVALID:
		return 0;
	default:
		return 1;
	}
}

static inline int
sas_flash_layout_is_mirrored(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
	case SAS_LAYOUT_UBI_SQFS:
	case SAS_LAYOUT_UBI_SQFS_DATA:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_has_image_parts(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_image_part_cnt(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE:
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA:
		return 1;
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
	case SAS_LAYOUT_UBI_SQFS:
	case SAS_LAYOUT_UBI_SQFS_DATA:
		return 2;
	default:
		return 0;
	}
}

static inline int sas_flash_layout_max_image_parts(void)
{
	return 3;
}

static inline int
sas_flash_layout_has_sysconfig_part(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_has_platform_images(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_has_service_images(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_has_data_part(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_PLATFORM_ONLY_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_SINGLE_DATA:
	case SAS_LAYOUT_PLATFORM_ONLY_MIRRORED_DATA:
	case SAS_LAYOUT_PLATFORM_SERVICE_MIRRORED_DATA:
	case SAS_LAYOUT_UBI_SQFS_DATA:
		return 1;
	default:
		return 0;
	}
}

static inline int
sas_flash_layout_is_ubi(enum sas_flash_layout_type layout)
{
	switch (layout) {
	case SAS_LAYOUT_UBI_SQFS:
	case SAS_LAYOUT_UBI_SQFS_DATA:
		return 1;
	default:
		return 0;
	}
}

struct sas_flash_partition *
sas_flash_layout_image_partition(unsigned int index);

enum sas_flash_layout_type sas_flash_layout_current(void);

const char* sas_flash_layout_name(enum sas_flash_layout_type layout);

const char* sas_flash_layout_str(enum sas_flash_layout_type layout);

enum sas_flash_layout_type sas_flash_layout_parse(const char *str);

#endif /* __SAS_FLASHLAYOUT_H__ */
