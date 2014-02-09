/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * based on Linux kernel firmware loader
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _FIRMWARE_H
#define _FIRMWARE_H

#include <linux/types.h>
#include <errno.h>

struct firmware {
	size_t size;
	const u8 *data;
};

struct builtin_fw {
	char *name;
	void *data;
	unsigned long size;
};

#if defined(CONFIG_FW_LOADER)
int request_firmware(const struct firmware **fw, const char *name);

void release_firmware(const struct firmware *fw);
#else
static inline int request_firmware(const struct firmware **fw,
					const char *name)
{
	return -EINVAL;
}

static inline void release_firmware(const struct firmware *fw)
{
}
#endif

#endif
