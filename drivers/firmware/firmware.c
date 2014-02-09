/*
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <firmware.h>

DECLARE_GLOBAL_DATA_PTR;

struct builtin_fw {
	char *name;
	void *data;
	unsigned long size;
};

static struct builtin_fw *lookup_firmware(const char *name)
{
	struct builtin_fw *fw;
	struct builtin_fw *fw_start =
		ll_entry_start(struct builtin_fw, builtin_fw);
	const int fw_entries = ll_entry_count(struct builtin_fw, builtin_fw);
	int len;

	if (!fw_start || !fw_entries)
		return NULL;

	len = strlen(name);

	for (fw = fw_start; fw != fw_start + fw_entries; fw++) {
		if (strncmp(name, fw->name, len))
			continue;

		if (len == strlen(fw->name))
			return fw;
	}

	return NULL;
}

int request_firmware(struct firmware *fw, const char *name)
{
	struct builtin_fw *builtin_fw;

	if (!fw)
		return -EINVAL;

	debug("firmware: using built-in firmware %s\n", name);

	builtin_fw = lookup_firmware(name);
	if (!builtin_fw) {
		debug("%s: lookup_firmware failed\n", __func__);
		return -ENODATA;
	}

	fw->data = builtin_fw->data + gd->reloc_off;
	fw->size = builtin_fw->size;

	return 0;
}
