/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>

#define LTQ_CCR03_EIGHT_BANK_MODE	(1 << 0)
#define LTQ_CCR08_CS_MAP_SHIFT		24
#define LTQ_CCR08_CS_MAP_MASK		(0x3 << LTQ_CCR08_CS_MAP_SHIFT)
#define LTQ_CCR11_COLUMN_SIZE_SHIFT	24
#define LTQ_CCR11_COLUMN_SIZE_MASK	(0x7 << LTQ_CCR11_COLUMN_SIZE_SHIFT)
#define LTQ_CCR11_ADDR_PINS_MASK	0x7
#define LTQ_CCR15_MAX_COL_REG_SHIFT	24
#define LTQ_CCR15_MAX_COL_REG_MASK	(0xF << LTQ_CCR15_MAX_COL_REG_SHIFT)
#define LTQ_CCR16_MAX_ROW_REG_MASK	0xF

static void *ltq_mc_ddr_base = (void *) CKSEG1ADDR(LTQ_MC_DDR_BASE);

static inline u32 ltq_mc_ccr_read(u32 index)
{
	return ltq_readl(ltq_mc_ddr_base + LTQ_MC_DDR_CCR_OFFSET(index));
}

phys_size_t initdram(int board_type)
{
	u32 max_col_reg, max_row_reg, column_size, addr_pins;
	u32 banks, cs_map;
	phys_size_t size;

	banks = (ltq_mc_ccr_read(3) & LTQ_CCR03_EIGHT_BANK_MODE) ? 8 : 4;

	cs_map = (ltq_mc_ccr_read(8) & LTQ_CCR08_CS_MAP_MASK) >>
		LTQ_CCR08_CS_MAP_SHIFT;

	column_size = (ltq_mc_ccr_read(11) & LTQ_CCR11_COLUMN_SIZE_MASK) >>
		LTQ_CCR11_COLUMN_SIZE_SHIFT;

	addr_pins = ltq_mc_ccr_read(11) & LTQ_CCR11_ADDR_PINS_MASK;

	max_col_reg = (ltq_mc_ccr_read(15) & LTQ_CCR15_MAX_COL_REG_MASK) >>
		LTQ_CCR15_MAX_COL_REG_SHIFT;

	max_row_reg = ltq_mc_ccr_read(16) & LTQ_CCR16_MAX_ROW_REG_MASK;

	/*
	 * size (bytes) = 2 ^ rowsize * 2 ^ colsize * banks * chipselects
	 *                 * datawidth (bytes)
	 */
	size = (2 << (max_col_reg - column_size - 1)) *
		(2 << (max_row_reg - addr_pins - 1)) * banks * cs_map * 2;

	return size;
}
