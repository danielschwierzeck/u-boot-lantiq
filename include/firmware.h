/*
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

#if defined(CONFIG_FIRMWARE_LOADER)
int request_firmware(struct firmware *fw, const char *name);
#else
static inline int request_firmware(struct firmware *fw, const char *name)
{
	return -EINVAL;
}
#endif

#endif
