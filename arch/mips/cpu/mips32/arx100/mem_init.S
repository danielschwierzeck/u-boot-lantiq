/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <asm/asm.h>
#include <asm/regdef.h>
#include <asm/addrspace.h>
#include <asm/arch/soc.h>

/* Must be configured in BOARDDIR */
#include <ddr_settings.h>

#define LTQ_MC_GEN_ERRCAUSE		0x0010
#define LTQ_MC_GEN_ERRADDR		0x0020
#define LTQ_MC_GEN_CON			0x0060
#define LTQ_MC_GEN_STAT			0x0070
#define LTQ_MC_GEN_CON_SRAM_DDR_ENABLE	0xD
#define LTQ_MC_GEN_STAT_DLCK_PWRON	0xC

#define LTQ_MC_DDR_DC03_MC_START	0x100

	/* Store given value in MC DDR CCRx register */
	.macro dc_sw num, val
	li	t2, \val
	sw	t2, LTQ_MC_DDR_DC_OFFSET(\num)(t1)
	.endm

LEAF(ltq_mem_init)
	/* Load MC General and MC DDR module base */
	li	t0, (LTQ_MC_GEN_BASE | KSEG1)
	li	t1, (LTQ_MC_DDR_BASE | KSEG1)

	/* Clear access error log registers */
	sw	zero, LTQ_MC_GEN_ERRCAUSE(t0)
	sw	zero, LTQ_MC_GEN_ERRADDR(t0)

	/* Enable DDR and SRAM module in memory controller */
	li	t2, LTQ_MC_GEN_CON_SRAM_DDR_ENABLE
	sw	t2, LTQ_MC_GEN_CON(t0)

	/* Clear start bit of DDR memory controller */
	sw	zero, LTQ_MC_DDR_DC_OFFSET(3)(t1)

	/* Init memory controller registers with values ddr_settings.h */
	dc_sw	0, MC_DC00_VALUE
	dc_sw	1, MC_DC01_VALUE
	dc_sw	2, MC_DC02_VALUE
	dc_sw	4, MC_DC04_VALUE
	dc_sw	5, MC_DC05_VALUE
	dc_sw	6, MC_DC06_VALUE
	dc_sw	7, MC_DC07_VALUE
	dc_sw	8, MC_DC08_VALUE
	dc_sw	9, MC_DC09_VALUE

	dc_sw	10, MC_DC10_VALUE
	dc_sw	11, MC_DC11_VALUE
	dc_sw	12, MC_DC12_VALUE
	dc_sw	13, MC_DC13_VALUE
	dc_sw	14, MC_DC14_VALUE
	dc_sw	15, MC_DC15_VALUE
	dc_sw	16, MC_DC16_VALUE
	dc_sw	17, MC_DC17_VALUE
	dc_sw	18, MC_DC18_VALUE
	dc_sw	19, MC_DC19_VALUE

	dc_sw	20, MC_DC20_VALUE
	dc_sw	21, MC_DC21_VALUE
	dc_sw	22, MC_DC22_VALUE
	dc_sw	23, MC_DC23_VALUE
	dc_sw	24, MC_DC24_VALUE
	dc_sw	25, MC_DC25_VALUE
	dc_sw	26, MC_DC26_VALUE
	dc_sw	27, MC_DC27_VALUE
	dc_sw	28, MC_DC28_VALUE
	dc_sw	29, MC_DC29_VALUE

	dc_sw	30, MC_DC30_VALUE
	dc_sw	31, MC_DC31_VALUE
	dc_sw	32, MC_DC32_VALUE
	dc_sw	33, MC_DC33_VALUE
	dc_sw	34, MC_DC34_VALUE
	dc_sw	35, MC_DC35_VALUE
	dc_sw	36, MC_DC36_VALUE
	dc_sw	37, MC_DC37_VALUE
	dc_sw	38, MC_DC38_VALUE
	dc_sw	39, MC_DC39_VALUE

	dc_sw	40, MC_DC40_VALUE
	dc_sw	41, MC_DC41_VALUE
	dc_sw	42, MC_DC42_VALUE
	dc_sw	43, MC_DC43_VALUE
	dc_sw	44, MC_DC44_VALUE
	dc_sw	45, MC_DC45_VALUE
	dc_sw	46, MC_DC46_VALUE

	/* Set start bit of DDR memory controller */
	li	t2, LTQ_MC_DDR_DC03_MC_START
	sw	t2, LTQ_MC_DDR_DC_OFFSET(3)(t1)

	/* Wait until DLL has locked and core is ready for data transfers */
wait_ready:
	lw	t2, LTQ_MC_GEN_STAT(t0)
	li	t3, LTQ_MC_GEN_STAT_DLCK_PWRON
	and	t2, t3
	bne	t2, t3, wait_ready

finished:
	jr	ra

	END(ltq_mem_init)
