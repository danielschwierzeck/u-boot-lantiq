/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_BOOT_H__
#define __SAS_BOOT_H__

#include <linux/list.h>
#include <sas/image.h>
#include <sas/flashlayout.h>

enum sas_boot_state
{
	SAS_BOOT_NOTAVAILABLE = 0,
	SAS_BOOT_AVAILABLE,
	SAS_BOOT_ACTIVEWORKING,
	SAS_BOOT_INACTIVEWORKING,
	SAS_BOOT_NOTWORKING,
	SAS_BOOT_IGNORED,
	SAS_BOOT_INVALID
};

struct mtd_info;
struct sas_flash_partition;

void sas_boot_init(void);

int sas_boot_scan_images(int *save_env);

int sas_boot_has_platform_images(const struct sas_flash_partition *part);

int sas_boot_has_service_images(const struct sas_flash_partition *part);

void sas_boot_invalidate_image_state(unsigned int active_image);

int sas_boot_invalidate_platform_images(const struct sas_flash_partition *part);

int sas_boot_invalidate_service_images(const struct sas_flash_partition *part);

int sas_boot_layout_platform(const struct sas_flash_partition *part,
				size_t uimage_size, size_t rootfs_size,
				ulong *uimage_addr, ulong *rootfs_addr,
				size_t *erase_len);

int sas_boot_layout_service(const struct sas_flash_partition *part,
				size_t servicefs_size, size_t configfs_size,
				ulong *servicefs_addr, ulong *configfs_addr,
				size_t *erase_len);

int sas_boot_init_platform_mtdparts(int active_image,
					enum sas_flash_layout_type layout);

int sas_boot_init_service_mtdparts(int active_image,
					enum sas_flash_layout_type layout);

int sas_boot_init_sysconfig_mtdparts(int active_image,
					enum sas_flash_layout_type layout);

int sas_boot_init_ubi_mtdparts(int active_image,
				enum sas_flash_layout_type layout);

int sas_boot_find_working_image(enum sas_flash_layout_type layout);

int sas_boot_update_states(int active_image, int *retry, int *save_env);

int sas_boot_load_image(const struct sas_flash_partition *part,
				enum sas_image_type type, ulong addr);

void sas_boot_print(void);

const char* sas_boot_state_str(enum sas_boot_state state);

#endif /* __SAS_BOOT_H__ */
