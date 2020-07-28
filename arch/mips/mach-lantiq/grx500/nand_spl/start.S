/*
 *  Startup Code for MIPS32 CPU-core
 *
 *  Copyright (c) 2003	Wolfgang Denk <wd@denx.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm-offsets.h>
#include <config.h>
#include <asm/asm.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>

#include <asm/cps.h>
#include <mach/boot.h>

	.set noreorder

ENTRY(_start)
	/* RESET entry */
	b     reset
	 nop
	 nop
	 nop

	.org 0x200	/* General exception. */
	li	k0, (GIC_SH_WEDGE | GIC_BASE_ADDR)
	mfc0	k1, CP0_EBASE		// Get cp0 EBase = $15
	ext	k1, k1, 0, 10		// Extract CPUNum
	li	v0, 1
	li	v1, 1
	bne	k1, v0, 1f
	 add	v0, v1
	li	k1, 20
	b	ipi_calculation_done
	 nop

1:	bne	k1, v0, 1f
	add	v0, v1
	li	k1, 21
	b	ipi_calculation_done
	 nop

1:	li	k1, 85
	b	ipi_calculation_done
	 nop

ipi_calculation_done:
	sw	k1, 0(k0)		// Clear this IPI.
	li	k0, INTMSG
	mfc0	k1, CP0_EBASE		// Get cp0 EBase
	ext	k1, k1, 0, 10		// Extract CPUNum
	sll	k1, k1, 2		// k1 = k1*4
	addu	k0, k0, k1		// index into CMP global "C" variable start_test
	li	k1, 1
	sw	k1, 0(k0)		// Release "cpu"/vpe to execute "C" test code.
	eret
	 nop

	.org 0x300	/* Cache error exception */
	sdbbp
	 nop
1:	b	1b
	 nop

	.org 0x480	/* EJTAG debug exception */
1:	b	1b
	 nop

	.org 0x500
reset:
	/* unlock EJTAG access */
	li	t1, 0xb6080000
	sw	zero, 0x124(t1)

	/*
	 * Initialize $gp, force pointer sized alignment of bal instruction to
	 * forbid the compiler to put nop's between bal and _gp. This is
	 * required to keep _gp and ra aligned to 8 byte.
	 */
	.align	PTRLOG
	bal	1f
	 nop
	PTR	_gp
1:	PTR_L	gp, 0(ra)

	/* Only set GOT for IAP Core 1 and abv */
	mfc0	k1, CP0_PRID
	ext	k1, k1, 8, 16
	li	k0, 0x0190		/* 4Kec ID*/
	beq	k0, k1, start_init
	 nop

	/* CPU core 0, we shall ignore and jmp away */
	mfc0	k0, CP0_EBASE
	ext	k1, k0, 0, 4
	beq	k1, 0, start_init
	 nop

	/* Check if the core is in EVA mode */
	mfc0	v0, CP0_CONFIG5
	li	v1, 0x40000000
	and	v0, v0, v1
	beqz	v0, start_init		/* if EVA bit is not set, we are in legacy mode. hence no need */
	 nop				/* to change the GOT table location */

	/* Re-adjust GOT when in EVA mode */
	bal	1f
	nop
	.word	got_size

1:	lw	t1, 0(ra)
	move	t0, gp
	add	t1, t0, t1
	addiu	t0, t0, 8		/*skip first 2 entries*/

	/* Check if we need to add the GOT back to 0xA0000000 range */
	lw	t2, 0(t0)
	and	t2, t2, 0x70000000	/* mask value */
	bnez	t2, start_init		/* if GOT already in 0xA000000 range, skip */
	 nop

	/* Remap GOT table to 0xA000XXXX region */
2:	lw	t2, 0(t0)
	addu	t2, t2, 0x20000000
	sw	t2, 0(t0)
	addiu	t0, t0, PTRSIZE
	bne	t0, t1, 2b
	 nop

start_init:
	la	a2, set_gpr_boot_values
	jalr	a2
	 nop

	la	a2, init_cp0
	jalr	a2
	 nop

	li	k0, 8
	beq	k0, r23_cpu_num, init_done
	 nop

	la	a2, init_gic
	jalr	a2
	 nop

	la	a2, init_exception
	jalr	a2
	 nop

	la	a2, ipi_reconfig
	jalr	a2
	 nop

	bnez	r9_vpe_num, init_done
	 nop

	la	a2, disable_L23
	jalr	a2
	 nop

	la	a2, sys_init_icache
	jalr	a2
	 nop

	la	a2, change_k0_cca
	jalr	a2
	 nop

	la	a2, sys_init_dcache
	jalr	a2
	 nop

	li	k0, 8
	beq	k0, r23_cpu_num, init_done
	 nop

	bgtz	r23_cpu_num, init_sys_resources_done
	 nop

init_sys_resources:
	la	a2, init_cpc
	jalr	a2
	 nop

	la	a2, init_cm
	jalr	a2
	 nop

	la	a2, init_L23
	jalr	a2
	 nop

	la	a2, release_mp
	jalr	a2
	 nop

init_sys_resources_done:
	la	a2, join_domain
	jalr	a2
	 nop

	la	a2, init_vpe1
	jalr	a2
	 nop

init_done:
	la	a2, init_legacy
	jalr	a2
	 nop

	/* Set up temporary stack */
	li	k1, (CONFIG_SPL_TEXT_BASE | 0x8000)
	li	k0, 8
	beq	k0, r23_cpu_num, change_got_table
	 nop

	addiu	k1, 0x2000
	ins	k1, r23_cpu_num, STACK_SIZE_LOG2, 2

	b	change_got_table_done
	 nop

change_got_table:
	bal	1f
	 nop
	.word	got_size
1:
	move	t1, ra
	lw	t1, 0(t1)

	move	t0, gp
	add	t1, t0, t1
	addi	t0, 8 /*skip first 2 entries*/
2:
	lw	t2, 0(t0)
	subu	t2, 0x20000000
	sw	t2, 0(t0)
	bne	t0, t1, 2b
	 addi	t0, t0, 4

	subu	gp, 0x20000000

change_got_table_done:
	move	sp, k1			# different stack base for each CPU core
	subu	sp, sp, GD_SIZE		# reserve space for gd
	li	t0, -16
	and	sp, sp, t0		# force 16 byte alignment
	move	k0, sp			# save gd pointer

	move	fp, sp

	/* Clear gd */
	move	t0, k0
1:
	sw	zero, 0(t0)
	addiu	t0, PTRSIZE
	blt	t0, k1, 1b
	 nop

jmp_main:
	move    a0, r23_cpu_num
	la	t9, main
	jr	t9
	 move	ra, zero

	END(_start)
