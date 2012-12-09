/*
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>

static void *ltq_mc_ddr_base = (void *) CKSEG1ADDR(LTQ_MC_DDR_BASE);

static inline u32 ltq_mc_dc_read(u32 index)
{
	return ltq_readl(ltq_mc_ddr_base + LTQ_MC_DDR_DC_OFFSET(index));
}

phys_size_t initdram(int board_type)
{
	u32 col, row, dc04, dc19, dc20;

	dc04 = ltq_mc_dc_read(4);
	dc19 = ltq_mc_dc_read(19);
	dc20 = ltq_mc_dc_read(20);

	row = (dc04 & 0xF) - ((dc19 & 0x700) >> 8);
	col = ((dc04 & 0xF00) >> 8) - (dc20 & 0x7);

	return (1 << (row + col)) * 4 * 2;
}
