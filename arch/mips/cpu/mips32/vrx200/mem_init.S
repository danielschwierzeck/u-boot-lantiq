/*
 * Copyright (C) 2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
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

#define LTQ_MC_DDR_START		(1 << 8)
#define LTQ_MC_DDR_DLL_LOCK_IND	1

#define CCS_ALWAYS_LAST			0x0430
#define CCS_AHBM_CR_BURST_EN		(1 << 2)
#define CCS_FPIM_CR_BURST_EN		(1 << 1)

#define CCR03_EIGHT_BANK_MODE		(1 << 0)

	/* Store given value in MC DDR CCRx register */
	.macro ccr_sw num, val
	li	t1, \val
	sw	t1, LTQ_MC_DDR_CCR_OFFSET(\num)(t0)
	.endm

LEAF(ltq_mem_init)
	/* Load MC DDR module base */
	li	t0, (LTQ_MC_DDR_BASE | KSEG1)

	/* Put memory controller in inactive mode */
	sw	zero, LTQ_MC_DDR_CCR_OFFSET(7)(t0)

	/* Init MC DDR CCR registers with values from ddr_settings.h */
	ccr_sw	0, MC_CCR00_VALUE
	ccr_sw	1, MC_CCR01_VALUE
	ccr_sw	2, MC_CCR02_VALUE
	ccr_sw	3, MC_CCR03_VALUE
	ccr_sw	4, MC_CCR04_VALUE
	ccr_sw	5, MC_CCR05_VALUE
	ccr_sw	6, MC_CCR06_VALUE
	ccr_sw	7, MC_CCR07_VALUE
	ccr_sw	8, MC_CCR08_VALUE
	ccr_sw	9, MC_CCR09_VALUE

	ccr_sw	10, MC_CCR10_VALUE
	ccr_sw	11, MC_CCR11_VALUE
	ccr_sw	12, MC_CCR12_VALUE
	ccr_sw	13, MC_CCR13_VALUE
	ccr_sw	14, MC_CCR14_VALUE
	ccr_sw	15, MC_CCR15_VALUE
	ccr_sw	16, MC_CCR16_VALUE
	ccr_sw	17, MC_CCR17_VALUE
	ccr_sw	18, MC_CCR18_VALUE
	ccr_sw	19, MC_CCR19_VALUE

	ccr_sw	20, MC_CCR20_VALUE
	ccr_sw	21, MC_CCR21_VALUE
	ccr_sw	22, MC_CCR22_VALUE
	ccr_sw	23, MC_CCR23_VALUE
	ccr_sw	24, MC_CCR24_VALUE
	ccr_sw	25, MC_CCR25_VALUE
	ccr_sw	26, MC_CCR26_VALUE
	ccr_sw	27, MC_CCR27_VALUE
	ccr_sw	28, MC_CCR28_VALUE
	ccr_sw	29, MC_CCR29_VALUE

	ccr_sw	30, MC_CCR30_VALUE
	ccr_sw	31, MC_CCR31_VALUE
	ccr_sw	32, MC_CCR32_VALUE
	ccr_sw	33, MC_CCR33_VALUE
	ccr_sw	34, MC_CCR34_VALUE
	ccr_sw	35, MC_CCR35_VALUE
	ccr_sw	36, MC_CCR36_VALUE
	ccr_sw	37, MC_CCR37_VALUE
	ccr_sw	38, MC_CCR38_VALUE
	ccr_sw	39, MC_CCR39_VALUE

	ccr_sw	40, MC_CCR40_VALUE
	ccr_sw	41, MC_CCR41_VALUE
	ccr_sw	42, MC_CCR42_VALUE
	ccr_sw	43, MC_CCR43_VALUE
	ccr_sw	44, MC_CCR44_VALUE
	ccr_sw	45, MC_CCR45_VALUE
	ccr_sw	46, MC_CCR46_VALUE

	ccr_sw	52, MC_CCR52_VALUE
	ccr_sw	53, MC_CCR53_VALUE
	ccr_sw	54, MC_CCR54_VALUE
	ccr_sw	55, MC_CCR55_VALUE
	ccr_sw	56, MC_CCR56_VALUE
	ccr_sw	57, MC_CCR57_VALUE
	ccr_sw	58, MC_CCR58_VALUE
	ccr_sw	59, MC_CCR59_VALUE

	ccr_sw	60, MC_CCR60_VALUE
	ccr_sw	61, MC_CCR61_VALUE

	/* Disable bursts between FPI Master bus and XBAR bus */
	li	t4, (LTQ_MC_GLOBAL_BASE | KSEG1)
	li	t5, CCS_AHBM_CR_BURST_EN
	sw	t5, CCS_ALWAYS_LAST(t4)

	/* Init abort condition for DRAM probe */
	move	t4, zero

	/*
	 * Put memory controller in active mode and start initialitation
	 * sequence for connected DDR-SDRAM device
	 */
mc_start:
	lw	t1, LTQ_MC_DDR_CCR_OFFSET(7)(t0)
	li	t2, LTQ_MC_DDR_START
	or	t1, t1, t2
	sw	t1, LTQ_MC_DDR_CCR_OFFSET(7)(t0)

	/*
	 * Wait until DLL has locked and core is ready for data transfers.
	 * DLL lock indication is in register CCR47 and CCR48
	 */
wait_ready:
	li	t1, LTQ_MC_DDR_DLL_LOCK_IND
	lw	t2, LTQ_MC_DDR_CCR_OFFSET(47)(t0)
	and	t2, t2, t1
	bne	t1, t2, wait_ready

	lw	t2, LTQ_MC_DDR_CCR_OFFSET(48)(t0)
	and	t2, t2, t1
	bne	t1, t2, wait_ready

#ifdef CONFIG_SYS_DRAM_PROBE
dram_probe:
	/* Initialization is finished after the second MC start */
	bnez	t4, mc_finished

	/*
	 * Preload register values for CCR03 and CCR11. Initial settings
	 * are 8-bank mode enabled, 14 use address row bits, 10 used
	 * column address bits.
	 */
	li	t1, CONFIG_SYS_SDRAM_BASE_UC
	li	t5, MC_CCR03_VALUE
	li	t6, MC_CCR11_VALUE
	addi	t4, t4, 1

	/*
	 * Store test values to DRAM at offsets 0 and 2^13 (bit 2 in bank select
	 * address BA[3]) and read back the value at offset 0. If the resulting
	 * value is equal to 1 we can skip to the next test. Otherwise
	 * the 8-bank mode does not work with the current DRAM device,
	 * thus we need to clear the according bit in register CCR03.
	 */
	li	t2, 1
	sw	t2, 0x0(t1)
	li	t3, (1 << 13)
	add	t3, t3, t1
	sw	zero, 0(t3)
	lw	t3, 0(t1)
	bnez	t3, row_col_test

	/* Clear CCR03.EIGHT_BANK_MODE */
	li	t3, ~CCR03_EIGHT_BANK_MODE
	and	t5, t5, t3

row_col_test:
	/*
	 * Store test values to DRAM at offsets 0, 2^27 (bit 13 of row address
	 * RA[14]) and 2^26 (bit 12 of RA[14]). The chosen test values
	 * represent the difference between max. row address bits (14) and used
	 * row address bits. Then the read back value at offset 0 indicates
	 * the useable row address bits with the current DRAM device. This
	 * value must be set in the CCR11 register.
	 */
	sw	zero, 0(t1)

	li	t2, 1
	li	t3, (1 << 27)
	add	t3, t3, t1
	sw	t2, 0(t3)

	li	t2, 2
	li	t3, (1 << 26)
	add	t3, t3, t1
	sw	t2, 0(t3)

	/* Update CCR11.ADDR_PINS */
	lw	t3, 0(t1)
	add	t6, t6, t3

	/*
	 * Store test values to DRAM at offsets 0, 2^10 (bit 9 of column address
	 * CA[10]) and 2^9 (bit 8 of CA[10]). The chosen test values represent
	 * the difference between max. column address bits (12) and used
	 * column address bits. Then the read back value at offset 0 indicates
	 * the useable column address bits with the current DRAM device. This
	 * value must be set in the CCR11 register.
	 */
	sw	zero, 0(t1)

	li	t2, 1
	li	t3, (1 << 10)
	add	t3, t3, t1
	sw	t2, 0(t3)

	li	t2, 2
	li	t3, (1 << 9)
	add	t3, t3, t1
	sw	t2, 0(t3)

	/* Update CCR11.COLUMN_SIZE */
	lw	t3, 0(t1)
	sll	t3, t3, 24
	add	t6, t6, t3

	/* Put memory controller in inactive mode */
	sw	zero, LTQ_MC_DDR_CCR_OFFSET(7)(t0)

	/* Update CCR03 and CCR11 and restart memory controller initialiation */
	sw	t5, LTQ_MC_DDR_CCR_OFFSET(3)(t0)
	sw	t6, LTQ_MC_DDR_CCR_OFFSET(11)(t0)
	b	mc_start

mc_finished:
#endif /* CONFIG_SYS_DRAM_PROBE */

	jr	ra

	END(ltq_mem_init)
