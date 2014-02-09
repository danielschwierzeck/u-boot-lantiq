/*
 * Copyright (C) 2014 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * based on Linux kernel firmware loader
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#define DEBUG

#include <common.h>
#include <malloc.h>
#include <firmware.h>

extern struct builtin_fw __start_builtin_fw[];
extern struct builtin_fw __end_builtin_fw[];

static int fw_get_builtin_firmware(struct firmware *fw, const char *name)
{
	struct builtin_fw *b_fw;

	for (b_fw = __start_builtin_fw; b_fw != __end_builtin_fw; b_fw++) {
		if (strcmp(name, b_fw->name) == 0) {
			fw->size = b_fw->size;
			fw->data = b_fw->data;
			return 0;
		}
	}

	return -ENODATA;
}

int request_firmware(const struct firmware **fw, const char *name)
{
	struct firmware *firmware;
	int ret;

	if (!fw)
		return -EINVAL;

	firmware = malloc(sizeof(*firmware));
	if (!firmware) {
		debug("%s: malloc(struct firmware) failed\n", __func__);
		return -ENOMEM;
	}

	debug("firmware: using built-in firmware %s\n", name);

	ret = fw_get_builtin_firmware(firmware, name);
	if (ret) {
		debug("%s: fw_get_builtin_firmware failed\n", __func__);
		goto err;
	}

	*fw = firmware;

	return 0;

err:
	free(firmware);

	return ret;
}

void release_firmware(const struct firmware *fw)
{
	if (fw)
		free((struct firmware *) fw);
}
