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
	
        /* Initialize GOT pointer.
        */
        bal     1f
        nop
        .word   _GLOBAL_OFFSET_TABLE_
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
	li	t0, 0xa0400000
	
	la	sp, 0(t0)

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

	.globl	relocate_code
	.ent	relocate_code
relocate_code:
	move	sp, a0		/* Set new stack pointer		*/

	li	t0, CONFIG_SYS_MONITOR_BASE
	la	t3, in_ram
	lw	t2, -12(t3)	/* t2 <-- uboot_end_data	*/
	move	t1, a2

	/*
	 * Fix GOT pointer:
	 *
	 * New GOT-PTR = (old GOT-PTR - CFG_MONITOR_BASE) + Destination Address
	 */
	move	t6, gp
	sub	gp, CONFIG_SYS_MONITOR_BASE
	add	gp, a2			/* gp now adjusted		*/
	sub	t6, gp, t6		/* t6 <-- relocation offset	*/


	sub	t4, t2, t0
	move    t5, t1
	/*
	 * t0 = source address
	 * t1 = target address
	 * t2 = source end address
	 * t4 = content length
	 */

1:
	lw	t3, 0(t0)
	sw	t3, 0(t1)
    addu	t0, 4
	ble	t0, t2, 1b
	addu	t1, 4			/* delay slot			*/


	/* Jump to where we've relocated ourselves.
	 */
	addi	t0, a2, in_ram - _start
	j	t0
	nop

	.word	uboot_end_data
	.word	uboot_end
	.word	num_got_entries

in_ram:
	/* Now we want to update GOT.
	 */
	lw	t3, -4(t0)	/* t3 <-- num_got_entries	*/
	addi	t4, gp, 8	/* Skipping first two entries.	*/
	li	t2, 2
1:
	lw	t1, 0(t4)
	beqz	t1, 2f
	add	t1, t6
	sw	t1, 0(t4)
2:
	addi	t2, 1
	blt	t2, t3, 1b
	addi	t4, 4		/* delay slot			*/
clear_bss:
	/* Clear BSS.
	 */
	lw	t1, -12(t0)	/* t1 <-- uboot_end_data	*/
	lw	t2, -8(t0)	/* t2 <-- uboot_end		*/
	add	t1, t6		/* adjust pointers		*/
	add	t2, t6

	sub	t1, 4
1:	addi	t1, 4
	bltl	t1, t2, 1b
	sw	zero, 0(t1)	/* delay slot			*/

	move	a0, a1
	la	t9, board_init_r
	j	t9
	move	a1, a2		/* delay slot			*/
	.end	relocate_code

	/* Exception handlers.
	 */
romReserved:
	b romReserved

romExcHandle:
	b romExcHandle


