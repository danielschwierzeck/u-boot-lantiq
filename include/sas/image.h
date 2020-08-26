/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_IMAGE_H__
#define __SAS_IMAGE_H__

#include <image.h>

enum sas_image_type
{
	SAS_IMG_FDT = 0,
	SAS_IMG_KERNEL,
	SAS_IMG_ROOTFS,
	SAS_IMG_SERVICEFS,
	SAS_IMG_DEFCONFIG,
	SAS_IMG_UNSPECIFIED,
	SAS_IMG_UBOOT,
	SAS_IMG_INVALID,
};

#define SAS_IMAGE_NAME_LEN	64

struct sas_image {
	int format;
	enum sas_image_type type;
	size_t size;
	char name[SAS_IMAGE_NAME_LEN];
};

#define SAS_UBOOT_BIN		"u-boot.bin"
#define SAS_UBOOT_IMAGE		"u-boot.img"
#define SAS_UBOOT_LZO_IMAGE	"u-boot.lzo.img"
#define SAS_UBOOT_LZO_SFSPL	"u-boot.ltq.lzo.sfspl"
#define SAS_UBOOT_LZO_NANDSPL	"u-boot.ltq.lzo.nandspl"
#define SAS_UBOOT_LZO_NANDHWSPL	"u-boot.ltq.lzo.nandhwspl"
#define SAS_UBOOT_LZO_UBI_IMAGE "u-boot-lzo.img"
#define SAS_TYPELABEL_BIN	"typelabel.bin"
#define SAS_KERNEL_IMAGE	"uImage"
#define SAS_ROOTFS_IMAGE	"rootfs.img"
#define SAS_SERVICEFS_IMAGE	"servicefs.img"
#define SAS_CONFIGFS_IMAGE	"configfs.img"
#define SAS_UBI_IMAGE		"ubi.img"

static inline size_t sas_image_hdr_size(void)
{
#if CONFIG_IS_ENABLED(FIT) || CONFIG_IS_ENABLED(OF_LIBFDT)
	return max(sizeof(struct fdt_header), sizeof(struct image_header));
#else
	return sizeof(struct image_header);
#endif
}

int sas_image_parse(const void *addr, struct sas_image *img);
int sas_image_check_data(const struct sas_image *img);
const char* sas_image_type_str(enum sas_image_type type);

#endif /* __SAS_IMAGE_H__ */
