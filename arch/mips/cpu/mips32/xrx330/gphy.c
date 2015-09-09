/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <firmware.h>
#include <asm/lantiq/io.h>
#include <asm/arch/soc.h>
#include <asm/arch/gphy.h>

static void ltq_fw_load(const char *name, void *dst_addr)
{
	struct firmware fw;
	int err;

	err = request_firmware(&fw, name);
	if (err)
		return;

	memcpy(dst_addr, fw.data, fw.size);
	flush_cache((ulong)dst_addr, fw.size);
}

void ltq_gphy_phy11g_a21_load(void *addr)
{
	ltq_fw_load("lantiq/xrx300_phy11g_a21.fw", addr);
}

void ltq_gphy_phy22f_a21_load(void *addr)
{
	ltq_fw_load("lantiq/xrx300_phy22f_a21.fw", addr);
}

void *ltq_gphy_alloc(void)
{
	return memalign(LTQ_GPHY_FW_ALIGN, LTQ_GPHY_FW_SIZE);
}
