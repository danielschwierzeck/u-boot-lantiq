/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <firmware.h>
#include <asm/lantiq/io.h>
#include <asm/arch/soc.h>
#include <asm/arch/gphy.h>

static void ltq_fw_load(const char *name, ulong dst_addr)
{
	struct firmware fw;
	int err;

	err = request_firmware(&fw, name);
	if (err)
		return;

	memcpy((void *) dst_addr, fw.data, fw.size);
	flush_cache(dst_addr, fw.size);
}

void ltq_gphy_phy11g_a1x_load(ulong addr)
{
	ltq_fw_load("lantiq/vrx200_phy11g_a1x.fw", addr);
}

void ltq_gphy_phy11g_a2x_load(ulong addr)
{
	ltq_fw_load("lantiq/vrx200_phy11g_a2x.fw", addr);
}

void ltq_gphy_phy22f_a1x_load(ulong addr)
{
	ltq_fw_load("lantiq/vrx200_phy22f_a1x.fw", addr);
}

void ltq_gphy_phy22f_a2x_load(ulong addr)
{
	ltq_fw_load("lantiq/vrx200_phy22f_a2x.fw", addr);
}
