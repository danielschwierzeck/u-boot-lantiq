/*
 * Copyright (C) 1994 - 2000, 2001, 2003 Ralf Baechle
 * Copyright (C) 1999, 2000 Silicon Graphics, Inc.
 * Copyright (C) 2002, 2007  Maciej W. Rozycki
 * Copyright (C) 2001, 2012 MIPS Technologies, Inc.  All rights reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/asm.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/asm-offsets.h>

	/*
	 * Macros copied and adapted from Linux MIPS
	 */
	.macro	SAVE_AT
	.set	push
	.set	noat
	LONG_S	$1, PT_R1(sp)
	.set	pop
	.endm

	.macro	SAVE_TEMP
	mfhi	v1
#ifdef CONFIG_32BIT
	LONG_S	$8, PT_R8(sp)
	LONG_S	$9, PT_R9(sp)
#endif
	LONG_S	$10, PT_R10(sp)
	LONG_S	$11, PT_R11(sp)
	LONG_S	$12, PT_R12(sp)

	LONG_S	v1, PT_HI(sp)
	mflo	v1

	LONG_S	$13, PT_R13(sp)
	LONG_S	$14, PT_R14(sp)
	LONG_S	$15, PT_R15(sp)
	LONG_S	$24, PT_R24(sp)

	LONG_S	v1, PT_LO(sp)

	.endm

	.macro	SAVE_STATIC
	LONG_S	$16, PT_R16(sp)
	LONG_S	$17, PT_R17(sp)
	LONG_S	$18, PT_R18(sp)
	LONG_S	$19, PT_R19(sp)
	LONG_S	$20, PT_R20(sp)
	LONG_S	$21, PT_R21(sp)
	LONG_S	$22, PT_R22(sp)
	LONG_S	$23, PT_R23(sp)
	LONG_S	$30, PT_R30(sp)
	.endm

	.macro	SAVE_SOME
	.set	push
	.set	noat
	.set	reorder

	/*
	 * Save sp in pt_regs without utilizing k0. k0 may not be
	 * altered because it holds the address of gd data.
	 */
	move	k1, sp
	PTR_SUBU k1, PT_SIZE
	LONG_S	sp, PT_R29(k1)
	move	sp, k1

	LONG_S	$3, PT_R3(sp)
	LONG_S	$0, PT_R0(sp)
	mfc0	v1, CP0_STATUS
	LONG_S	$2, PT_R2(sp)
	LONG_S	v1, PT_STATUS(sp)
	LONG_S	$4, PT_R4(sp)
	mfc0	v1, CP0_CAUSE
	LONG_S	$5, PT_R5(sp)
	LONG_S	v1, PT_CAUSE(sp)
	LONG_S	$6, PT_R6(sp)
	MFC0	v1, CP0_EPC
	LONG_S	$7, PT_R7(sp)
#ifdef CONFIG_64BIT
	LONG_S	$8, PT_R8(sp)
	LONG_S	$9, PT_R9(sp)
#endif
	LONG_S	v1, PT_EPC(sp)
	LONG_S	$25, PT_R25(sp)
	LONG_S	$28, PT_R28(sp)
	LONG_S	$31, PT_R31(sp)
	.set	pop
	.endm

	.set	noreorder

NESTED(except_vec3_generic, 0, sp)
	PTR_LA	k1, handle_reserved
	jr	k1
	 nop
	END(except_vec3_generic)

NESTED(handle_reserved, PT_SIZE, sp)
	SAVE_SOME
	SAVE_AT
	SAVE_TEMP
	SAVE_STATIC
	PTR_LA	t9, do_reserved
	jr	t9
	 move	a0, sp
	END(handle_reserved)
