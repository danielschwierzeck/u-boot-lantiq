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
#include <asm/cps.h>
/*****************************************************************************
 * Local assembler register definitions
 *****************************************************************************/
#define C0_EBASe     $15,1
#define C0_SEGCTL0  $5,2
#define C0_SEGCTL1  $5,3
#define C0_SEGCTL2  $5,4
#define C0_CONFIG5  $16,5


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
LEAF(__reset_vector)
_start:
	/* RESET entry */
   	b     reset
   	nop
   	nop
   	nop
END(__reset_vector)
.org 0x200 /* General exception. */
    li      k0, (GIC_SH_WEDGE | GIC_BASE_ADDR)
    mfc0    k1, CP0_EBASE                // Get cp0 EBase = $15
    ext     k1, k1, 0, 10                               // Extract CPUNum
    li      v0, 1
    li      v1, 1
    bne     k1, v0, 1f
    add     v0, v1
    li      k1, 20
    b       ipi_calculation_done
    nop

1:  bne     k1, v0, 1f
    add     v0, v1
    li      k1, 21
    b       ipi_calculation_done
    nop

1:  li      k1, 85
    b       ipi_calculation_done
    nop

ipi_calculation_done:
    sw      k1, 0(k0)                                   // Clear this IPI.
    

    li      k0, INTMSG
    mfc0    k1, CP0_EBASE                                // Get cp0 EBase
    ext     k1, k1, 0, 10                               // Extract CPUNum
    sll     k1, k1, 2                                   // k1 = k1*4
    addu    k0, k0, k1                                  // index into CMP global "C" variable start_test
    li      k1, 1
    sw      k1, 0(k0)                                   // Release "cpu"/vpe to execute "C" test code.
    eret
    nop

reset:
        /* Initialize GOT pointer.
        */
        bal     1f
        nop
        .word   _GLOBAL_OFFSET_TABLE_
1:
        move    gp, ra
        lw      t1, 0(ra)
        move    gp, t1

    	/* Only set GOT for IAP Core 1 and abv */
	    mfc0    k1, CP0_PRID             
	    ext     k1, k1, 8, 16       /* Company ID & Processor ID */
	    li      k0, 0x0190          /* 4Kec ID*/
    	beq     k0, k1, start_init	/* jmp if 4Kec */
	    nop

		/* CPU core 0, we shall ignore and jmp away */
	    mfc0    k0, CP0_EBASE       // Read CP0 EBase
	    ext     k1, k0, 0, 4        // Extract CPUNum
    	beq     k1, 0, start_init	/* jmp if core 0 */
    	nop	

		/* Check if the core is in EVA mode */
    	mfc0	v0, CP0_CONFIG5	
		li      v1, 0x40000000
		and		v0, v0, v1
		beqz	v0, start_init		/* if EVA bit is not set, we are in legacy mode. hence no need 	*/
		nop							/* to change the GOT table location							 	*/

		/* Re-adjust GOT when in EVA mode */
        bal     1f
        nop
        .word   got_size
1:
        move    t1, ra
        lw      t1, 0(t1)

        move    t0, gp
        add     t1, t0, t1
        addi    t0, 8 /*skip first 2 entries*/
		
		/* Check if we need to add the GOT back to 0xA0000000 range */
		lw		t2, 0(t0)
		and		t2, t2, 0x70000000	/* mask value */
		bnez	t2, start_init		/* if GOT already in 0xA000000 range, skip */
		nop
		
		/* Remap GOT table to 0xA000XXXX region */
2:
        lw      t2, 0(t0)
        addu    t2, 0x20000000
        sw      t2, 0(t0)
        bne     t0, t1, 2b
        addi    t0, t0, 4

start_init:
        la      a2,  set_gpr_boot_values             // Fill register file boot info. r23_cpu_num = 8 for 4KEc
        jalr    a2
        nop

        la          a2, init_cp0                    // Init CP0 Status, Count, Compare, Watch*, and Cause.
        jalr        a2
        nop

#ifdef CONFIG_LTQ_SECURE_BOOT 
        li              k0, 8
        beq             k0, r23_cpu_num, init_done     // CPUNum = 8 = 4KEc
        nop
#endif        
        la          a2, init_gic                    // Configure the global interrupt controller.
        jalr        a2
        nop
        
        la          a2, init_exception
        jalr        a2
        nop

        la			a2,	ipi_reconfig			// reconfigure IPI interrupts for VPE1-VPE3
        jalr		a2
        nop
        
        bnez        r9_vpe_num, init_done   // If we are not vpe0 then we are done.
        nop

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
        beq             k0, r23_cpu_num, init_done     // CPUNum = 8 = 4KEc
        nop

        bgtz            r23_cpu_num, init_sys_resources_done
        nop

init_sys_resources:
        /*interAptiv start to initialize system resources*/
        la          a2, init_cpc                    // Initialize the CPS CPC (Cluster Power Controller.)
        jalr        a2
        nop

        la          a2, init_cm                             // Initialize the CPS CM (Coherence Manager.)
        jalr        a2
        nop

        la          a2, init_L23                    // Initialize the unified L2 and L3 caches
        jalr        a2
        nop
        
        la          a2, release_mp                  // Release other cores to execute this boot code.
        jalr        a2
        nop
init_sys_resources_done:
        la          a2, join_domain                 // Join the Coherence  domain. (OK to use D$ on return.)
        jalr        a2
        nop

        la          a2, init_vpe1                   // Set up MT ASE vpe1 to execute this boot code also.
        jalr        a2
        nop

init_done:
        la          a2, init_legacy                 // init cpu into non-eva mode
        jalr        a2
        nop

	/* Set up temporary stack.
	 */

        li              k1, (CONFIG_NAND_SPL_TEXT_BASE | 0x8000)
        li              k0, 8
        beq             k0, r23_cpu_num, change_got_table
        nop
        addi            k1, 0x2000
        ins             k1, r23_cpu_num, STACK_SIZE_LOG2, 2 
        b               change_got_table_done
        nop
               
change_got_table:
        bal     1f
              nop
        .word   got_size
1:
        move    t1, ra
        lw      t1, 0(t1)

        move    t0, gp
        add     t1, t0, t1
        addi    t0, 8 /*skip first 2 entries*/
2:
        lw      t2, 0(t0)
        subu    t2, 0x20000000
        sw      t2, 0(t0)
        bne     t0, t1, 2b
        addi    t0, t0, 4

        subu    gp, 0x20000000

change_got_table_done:
#if defined(CONFIG_LTQ_SECURE_BOOT)
        li      k0, 8
        bne     k0, r23_cpu_num, iap_stack     // CPUNum = 8 = 4KEc
        nop
        li      sp, 0x9fc87ff0
        j       stack_done
        nop
iap_stack:
#endif
        la      sp, 0(k1)
#if defined(CONFIG_LTQ_SECURE_BOOT)
stack_done:
#endif

    move    a0, r23_cpu_num                     // main(arg0) is the "cpu" number (cp0 EBase[CPUNUM].)
    move    a1, r8_core_num                     // main(arg1) is the core number.
    move    a2, r9_vpe_num                      // main(arg2) is the vpe number.
	la	t9, main

	j	t9
	nop
     

