/*
 *  Startup Code for MIPS32 CPU-core
 *
 *  Copyright (c) 2003	Wolfgang Denk <wd@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/cacheops.h>
#include <asm/addrspace.h>
#include <asm/yamon.h>
#include <asm/boot.h>
#include <asm/yamon.h>
#include <asm-offsets.h>

/*****************************************************************************
 * Local assembler register definitions
 *****************************************************************************/
#define C0_EBASe     $15,1

#define S_EBASeExpBase     12       /* Exception Base */
#define M_EBASeExpBase     (0x3ffff << S_EBASeExpBase)
#define S_EBASeCPUNum      0        /* CPU Number */
#define M_EBASeCPUNum      (0x1ff << S_EBASeCPUNum)

/*
 * Values in the CPU Number field
 */
#define K_EBASeCPUNum_Host 0
#define K_EBASeCPUNum_Voice 1

/* C0_EBASE register encoding */
#define CO_EBASE_EXPBASE_SHF     S_EBASeExpBase
#define CO_EBASE_EXPBASE_MSK     M_EBASeExpBase

#define CO_EBASE_CPUNUM_SHF      S_EBASeCPUNum
#define CO_EBASE_CPUNUM_MSK      M_EBASeCPUNum

#define CO_EBASE_CPU_HOST     K_EBASeCPUNum_Host
#define CO_EBASE_CPU_VOICE    K_EBASeCPUNum_Voice

#ifdef CONFIG_32BIT
# define MIPS_RELOC	3
# define STATUS_SET	0
#endif

    .set noreorder
/*	  .option pic0*/
   	.globl _start
   	.globl __exception_vector_tlb_refill
   	.globl __exception_vector_xtlb_refill
   	.globl __exception_vector_general
   	.globl __exception_vector_int
   	.text
_start:
	/* RESET entry */
   	b     reset
   	nop
   	nop
   	nop

reset:
        mtc0    zero, CP0_WATCHLO
        mtc0    zero, CP0_WATCHHI
        mtc0    zero, CP0_CAUSE
	
	/* unlock EJTAG access */
	li	t1, 0xb6080000
	sw	zero, 0x124(t1)

        /* Initialize GOT pointer.
        */
        bal     1f
        nop
        //.word   _GLOBAL_OFFSET_TABLE_
		.word	_gp
1:
        move    gp, ra
        lw      t1, 0(ra)
        move    gp, t1


        la      a2,  set_gpr_boot_values             // Fill register file boot info. r23_cpu_num = 8 for 4KEc
        jalr    a2
        nop

        la          a2, init_cp0                    // Init CP0 Status, Count, Compare, Watch*, and Cause.
        jalr        a2
        nop

init_core_resources:                            // All Cores (VPE0).

        la          a2, disable_L23                 // Disable L2/L3 caches
        jalr        a2
        nop

        la          a2, sys_init_icache                 // Initialize the L1 instruction cache. (Executing using I$ on return.)
        jalr        a2
        nop


        la          a2, change_k0_cca
        jalr        a2
        nop

        la          a2, sys_init_dcache                 // Initialize the L1 data cache
        jalr        a2
        nop


        li              k0, 8
        beq             k0, r23_cpu_num, init_sys_resources_done     // CPUNum = 8 = 4KEc, bypass the EVA setup
        nop


init_sys_resources:
        la          a2, init_cpc                    // Initialize the CPS CPC (Cluster Power Controller.)
        jalr        a2
        nop

        la          a2, init_cm                             // Initialize the CPS CM (Coherence Manager.)
        jalr        a2
        nop
 

        la          a2, init_L23                    // Initialize the unified L2 and L3 caches
        jalr        a2
        nop

init_sys_resources_done:

lowlevel_init_done:

	/* Set up temporary stack.
	 */
	li	t0, -16
	li	t1, 0xa0400000
	
	move	sp, t1
	sub		sp, sp, GD_SIZE
	and		sp, sp, t0				# mem align
	move	k0, sp					# backup sp

	li		t2, 0xa000	
	subu	sp, sp, t2				# alloc space
	and		sp, sp, t0				# mem align

	move	fp, sp

	/* Clear gd*/
	move	t0, k0
2:
	sw		zero, 0(t0)
	blt		t0, t1, 2b
	addiu	t0, PTRSIZE

	sw		sp, GD_MALLOC_BASE(k0)	# gd->malloc_base offset		
	
	move	a0, zero		# a0 <-- boot_flags = 0
	la	t9, board_init_f

	j	t9
	nop
        

/*
 * void relocate_code (addr_sp, gd, addr_moni)
 *
 * This "function" does not return, instead it continues in RAM
 * after relocating the monitor code.
 *
 * a0 = addr_sp
 * a1 = gd
 * a2 = destination address
 */
ENTRY(relocate_code)
	move	sp, a0			# set new stack pointer
	move	fp, sp

	move	s0, a1			# save gd in s0
	move	s2, a2			# save destination address in s2

	PTR_LI	t0, CONFIG_SYS_MONITOR_BASE
	PTR_SUB	s1, s2, t0		# s1 <-- relocation offset

	PTR_LA	t3, in_ram
	PTR_L	t2, -(3 * PTRSIZE)(t3)	# t2 <-- __image_copy_end
	move	t1, a2

	PTR_ADD	gp, s1			# adjust gp

	/*
	 * t0 = source address
	 * t1 = target address
	 * t2 = source end address
	 */
1:
	PTR_L	t3, 0(t0)
	PTR_S	t3, 0(t1)
	PTR_ADDU t0, PTRSIZE
	blt	t0, t2, 1b
	PTR_ADDU t1, PTRSIZE

	/* Jump to where we've relocated ourselves */
	PTR_ADDI t0, s2, in_ram - _start
	jr	t0
	 nop

	PTR	__rel_dyn_end
	PTR	__rel_dyn_start
	PTR	__image_copy_end
	PTR	_GLOBAL_OFFSET_TABLE_
	PTR	num_got_entries

in_ram:
	/*
	 * Now we want to update GOT.
	 *
	 * GOT[0] is reserved. GOT[1] is also reserved for the dynamic object
	 * generated by GNU ld. Skip these reserved entries from relocation.
	 */
	PTR_L	t3, -(1 * PTRSIZE)(t0)	# t3 <-- num_got_entries
	PTR_L	t8, -(2 * PTRSIZE)(t0)	# t8 <-- _GLOBAL_OFFSET_TABLE_
	PTR_ADD	t8, s1			# t8 now holds relocated _G_O_T_
	PTR_ADDI t8, t8, 2 * PTRSIZE	# skipping first two entries
	PTR_LI	t2, 2
1:
	PTR_L	t1, 0(t8)
	beqz	t1, 2f
	 PTR_ADD t1, s1
	PTR_S	t1, 0(t8)
2:
	PTR_ADDI t2, 1
	blt	t2, t3, 1b
	 PTR_ADDI t8, PTRSIZE

	/* Update dynamic relocations */
	PTR_L	t1, -(4 * PTRSIZE)(t0)	# t1 <-- __rel_dyn_start
	PTR_L	t2, -(5 * PTRSIZE)(t0)	# t2 <-- __rel_dyn_end

	b	2f			# skip first reserved entry
	 PTR_ADDI t1, 2 * PTRSIZE

1:
	lw	t8, -4(t1)		# t8 <-- relocation info

	PTR_LI	t3, MIPS_RELOC
	bne	t8, t3, 2f		# skip non-MIPS_RELOC entries
	 nop

	PTR_L	t3, -(2 * PTRSIZE)(t1)	# t3 <-- location to fix up in FLASH

	PTR_L	t8, 0(t3)		# t8 <-- original pointer
	PTR_ADD	t8, s1			# t8 <-- adjusted pointer

	PTR_ADD	t3, s1			# t3 <-- location to fix up in RAM
	PTR_S	t8, 0(t3)

2:
	blt	t1, t2, 1b
	 PTR_ADDI t1, 2 * PTRSIZE	# each rel.dyn entry is 2*PTRSIZE bytes

	/*
	 * Clear BSS
	 *
	 * GOT is now relocated. Thus __bss_start and __bss_end can be
	 * accessed directly via $gp.
	 */
	PTR_LA	t1, __bss_start		# t1 <-- __bss_start
	PTR_LA	t2, __bss_end		# t2 <-- __bss_end

1:
	PTR_S	zero, 0(t1)
	blt	t1, t2, 1b
	 PTR_ADDI t1, PTRSIZE

	move	a0, s0			# a0 <-- gd
	move	a1, s2
	PTR_LA	t9, board_init_r
	jr	t9
	 move	ra, zero

	END(relocate_code)

	/* Exception handlers.
	 */
romReserved:
	b romReserved

romExcHandle:
	b romExcHandle


