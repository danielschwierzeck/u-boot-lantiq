// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <libfdt.h>
#include <sas/image.h>

static const char sas_image_strings[][8] = {
	"fdt",
	"kernel",
	"rootfs",
	"servfs",
	"defcfg",
	"unspec",
	"u-boot",
	"invalid"
};

static enum sas_image_type sas_image_type_parse(const char *name)
{
	int i;

	for (i = 0; i < SAS_IMG_INVALID; i++) {
		if (0 == strncmp(sas_image_strings[i], name, 6))
			return i;
	}

	return SAS_IMG_INVALID;
}

static int sas_image_parse_legacy(const void *addr, struct sas_image *img)
{
	const image_header_t *hdr = (const image_header_t *) addr;
	const char *name;

	name = image_get_name(hdr);
	if (name[6] != '#')
		return -1;

	img->type = sas_image_type_parse(name);
	if (img->type == SAS_IMG_INVALID)
		return -1;

	img->size = image_get_image_size(hdr);
	sprintf(img->name, "%.*s", IH_NMLEN, name);

	return 0;
}

#if defined(CONFIG_OF_LIBFDT)
static int sas_image_parse_fit(const void *addr, struct sas_image *img)
{
	int ret;
	char *desc;

	ret = fdt_check_header(addr);
	if (ret != 0)
		return -1;

	ret = fit_get_desc(addr, 0, &desc);
	if (ret)
		sprintf(img->name, "kernel#FIT");
	else
		sprintf(img->name, "%.*s", SAS_IMAGE_NAME_LEN, desc);

	img->type = SAS_IMG_KERNEL;
	img->size = fit_get_size(addr);

	return 0;
}
#endif

int sas_image_parse(const void *addr, struct sas_image *img)
{
	img->format = genimg_get_format((void *) addr);

	switch (img->format) {
	case IMAGE_FORMAT_LEGACY:
		return sas_image_parse_legacy(addr, img);
		break;
#if defined(CONFIG_OF_LIBFDT)
	case IMAGE_FORMAT_FIT:
		return sas_image_parse_fit(addr, img);
		break;
#endif
	default:
		break;
	}

	return -1;
}

int sas_image_check_data(const struct sas_image *img)
{
	return 0;
}

const char* sas_image_type_str(enum sas_image_type type)
{
	assert(type <= SAS_IMG_INVALID);

	return sas_image_strings[type];
}
