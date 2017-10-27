/*
Copyright (c) MIPS Technologies, Inc.  All rights reserved.  Unpublished
rights reserved
under the copyright laws of the United States of America and other countries.

Redistribution and use in source and binary forms, with or without
modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <asm/boot.h>
#include <config.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <asm/cps.h>

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
**************************************************************************************/
LEAF(init_cp0)

        // Initialize Status
	li	v1, 0x00400404		// (M_StatusBEV=1 | M_StatusIM | M_StatusERL) - Compatibility Int Mode
	mtc0	v1, CP0_STATUS		// write C0_Status $12

	// Initialize Watch registers if implemented.
	mfc0	v0, CP0_CONFIG,1		// read C0_Config1
	ext     v1, v0, 3, 1		// extract bit 3 WR (Watch registers implemented)
	beq 	v1, zero, done_wr
	li    	v1, 0x7				// (M_WatchHiI | M_WatchHiR | M_WatchHiW)

	// Clear Watch Status bits and disable watch exceptions
	mtc0	v1, CP0_WATCHHI		// write C0_WatchHi0
	mfc0	v0, CP0_WATCHHI		// read C0_WatchHi0
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO	// write C0_WatchLo0

	mtc0	v1, CP0_WATCHHI, 1	// write C0_WatchHi1
	mfc0	v0, CP0_WATCHHI, 1	// read C0_WatchHi1
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 1	// write C0_WatchLo1

	mtc0	v1, CP0_WATCHHI, 2	// write C0_WatchHi2
	mfc0	v0, CP0_WATCHHI, 2	// read C0_WatchHi2
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 2	// write C0_WatchLo2

	mtc0	v1, CP0_WATCHHI, 3	// write C0_WatchHi3
	mfc0	v0, CP0_WATCHHI, 3	// read C0_WatchHi3
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 3	// write C0_WatchLo3

	mtc0	v1, CP0_WATCHHI, 4	// write C0_WatchHi4
	mfc0	v0, CP0_WATCHHI, 4	// read C0_WatchHi4
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 4	// write C0_WatchLo4

	mtc0	v1, CP0_WATCHHI, 5	// write C0_WatchHi5
	mfc0	v0, CP0_WATCHHI, 5	// read C0_WatchHi5
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 5	// write C0_WatchLo5

	mtc0	v1, CP0_WATCHHI, 6	// write C0_WatchHi6
	mfc0	v0, CP0_WATCHHI, 6	// read C0_WatchHi6
	beq 	v0, zero, done_wr
	mtc0	zero, CP0_WATCHLO, 6	// write C0_WatchLo6

	mtc0	v1, CP0_WATCHHI, 7	// write C0_WatchHi7
	mtc0	zero, CP0_WATCHLO, 7	// write C0_WatchLo7

done_wr:

	// Clear WP bit to avoid watch exception upon user code entry, IV, and software interrupts.
	mtc0	zero, CP0_CAUSE		// write C0_Cause: Init AFTER init of CP0 WatchHi/Lo registers.

	// Clear timer interrupt. (Count was cleared at the reset vector to allow timing boot.)
	mtc0	zero, CP0_COMPARE	// write C0_Compare

    jr      ra
	nop
END(init_cp0)

LEAF(init_gic)

    beqz    r11_is_cps, done_gic				// Skip if non-CPS.
    nop

    bnez    r23_cpu_num, done_gic				// Only core0 vpe0 inits shared portion.
    nop

//Only cpu0 = core0+vpe0 to reach here
/*set GIC base address and enable it*/

    li      a1, GCR_CONFIG_ADDR + GCR_GIC_BASE  	// Locate and enable GIC
    li      a0, GIC_P_BASE_ADDR | 1 			// Physical address + enable bit
    sw      a0, 0(a1)				        // a0 = 0x12320001


/*initialize IPI for VPE1/core0, VPE0/core1, VPE1/core1*/
    li      a1, GIC_BASE_ADDR		// GIC_BASE_ADDR = 0xb2320000
    // IPI interrupts 20, 21 85  
    li      a0, 0x00300000
    sw      a0, GIC_SH_RMASK31_0(a1)	// (disable     56..59)
    sw      a0, GIC_SH_POL31_0(a1)		// (high/rise   56..59)
    sw      a0, GIC_SH_TRIG31_0(a1)	// (edge        56..59)
    sw      a0, GIC_SH_SMASK31_00(a1)	// (enable      56..59)

    li      a0, 0x00200000
    sw      a0, GIC_SH_RMASK95_64(a1)	// (disable     56..59)
    sw      a0, GIC_SH_POL95_64(a1)		// (high/rise   56..59)
    sw      a0, GIC_SH_TRIG95_64(a1)	// (edge        56..59)
    sw      a0, GIC_SH_SMASK95_64(a1)	// (enable      56..59)
     
 
    li      a0, 1              // set bit 0 for CORE0 or for MT vpe0
    sll     a0, a0, 1          // set bit 1 for CORE1 or for MT vpe1
    sw      a0, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 20) (a1)
    sll     a0, a0, 1          // set bit 2 for CORE2 or for MT vpe2
    sw      a0, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 21) (a1)
    sll     a0, a0, 1          // set bit 3 for CORE3 or for MT vpe3
    sw      a0, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 85) (a1)

done_gic:
    jr      ra
    nop

END(init_gic)

/* Reconfigure IPI interrupts when VPE re-enters IBL after FW exits */
LEAF(ipi_reconfig)
    beqz    r11_is_cps, ipi_done		/* Skip if non-CPS */
    nop

    beqz    r9_vpe_num, ipi_done		/* If VPE0, return */
    nop

	li		a0,	GCR_CONFIG_ADDR + GCR_GIC_BASE
    li      a1, GIC_P_BASE_ADDR | 1 	/* Physical address + enable bit */
    sw      a1, 0(a0)

    li      a0, GIC_BASE_ADDR

	li		t0, 1
	bne		r23_cpu_num, t0, vpe2			/* Check if VPE1 */
	nop

	li		a1,	0x00100000				/* IPI 20 */
	lw		a2,	(GIC_SH_MASK31_00)(a0)	/* Load MASK reg val */
	and		a3, a2, a1 					/* Check bit enabled */ 
	bnez	a3, ipi_done				/* If enabled, we are done */
	nop		
	
    sw      a1, GIC_SH_RMASK31_0(a0)	/* disable */
    sw      a1, GIC_SH_SMASK31_00(a0)	/* enable */
	
    li      a1, 2              /* set bit 1 for CORE1 or for MT vpe1 */
    sw      a1, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 20) (a0)
	b		ipi_done
	nop

vpe2:
	li		t0, 2
	bne		r23_cpu_num, t0, vpe3			/* check if VPE2 */
	nop

	li		a1, 0x00200000				/* IPI 21 */
	lw		a2,	(GIC_SH_MASK31_00)(a0)	/* Load MASK reg */
	and     a3, a2, a1					/* Check bit enabled */
	bnez	a3, ipi_done				/* If enabled, we are done */
	nop
	
	sw      a1, GIC_SH_RMASK31_0(a0)	/* disable */
    sw      a1, GIC_SH_SMASK31_00(a0)	/* enable */
	
    li      a1, 4              			/* set bit 2 for CORE2 or for MT vpe2 */
    sw      a1, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 21) (a0)
	b		ipi_done
	nop

vpe3:
    li      a1, 0x00200000				/* IPI 85 */
	lw		a2, (GIC_SH_MASK95_64)(a0)	/* Load MASK reg */
	and		a3, a2, a1					/* Check bit enabled */
	bnez	a3, ipi_done				/* If enabled, we are done */
	nop
		
    sw      a1, GIC_SH_RMASK95_64(a0)	/* disable */
    sw      a1, GIC_SH_SMASK95_64(a0)	/* enable */
    
	li      a1, 8              			/* set bit 3 for CORE3 or for MT vpe0 */
    sw      a1, GIC_SH_MAP0_VPE31_0 + (GIC_SH_MAP_SPACER * 85)(a0)

ipi_done:
	jr	ra
	nop	
		
END(ipi_reconfig)

/**************************************************************************************
**************************************************************************************/
LEAF(init_cm)


	// Allow each core access to the CM registers (they should only access their local registers.)
	li	    a0, 2							// Start building mask for cores in this cps.
    sll     a0, a0, r19_more_cores
    addiu   a0, -1							// Complete mask.
	sw	    a0, GCR_ACCESS(r22_gcr_addr)	// GCR_ACCESS

    // Check to see if this CPS implements an IOCU.
    lw      a0, GCR_CONFIG(r22_gcr_addr)	// Load GCR_CONFIG
    ext	    a0, a0, NUMIOCU, NUMIOCU_S		// Extract NUMIOCU.
    beqz    a0, done_cm_init
    lui	    a0, 0xffff

	// Disable the CM regions if there is an IOCU.
	sw	    a0, GCR_REG0_BASE(r22_gcr_addr)	// GCR_REG0_BASE
	sw	    a0, GCR_REG0_MASK(r22_gcr_addr)	// GCR_REG0_MASK
	sw	    a0, GCR_REG1_BASE(r22_gcr_addr)	// GCR_REG1_BASE
	sw	    a0, GCR_REG1_MASK(r22_gcr_addr)	// GCR_REG1_MASK
	sw	    a0, GCR_REG2_BASE(r22_gcr_addr)	// GCR_REG2_BASE
	sw	    a0, GCR_REG2_MASK(r22_gcr_addr)	// GCR_REG2_MASK
	sw	    a0, GCR_REG3_BASE(r22_gcr_addr)	// GCR_REG3_BASE
	sw	    a0, GCR_REG3_MASK(r22_gcr_addr)	// GCR_REG3_MASK
	sw	    a0, GCR_REG4_BASE(r22_gcr_addr)	// GCR_REG4_BASE
	sw	    a0, GCR_REG4_MASK(r22_gcr_addr)	// GCR_REG4_MASK
	sw	    a0, GCR_REG5_BASE(r22_gcr_addr)	// GCR_REG5_BASE
	sw	    a0, GCR_REG5_MASK(r22_gcr_addr)	// GCR_REG5_MASK

	// program CM CUSTOM
	li       a0, CUS_P_BASE_ADDR | 1
	sw       a0, 0x60(r22_gcr_addr)			// GCR Custom Base Register

    li       a0, 3
    sw       a0, 0x10(r22_gcr_addr)			// GCR Custom Base Register for UMT access to DMA3

done_cm_init:
	jr      ra
	nop
END(init_cm)

/**************************************************************************************
**************************************************************************************/
LEAF(init_cpc)
    li      a0, CPC_P_BASE_ADDR				
    sw      a0, GCR_CPC_BASE(r22_gcr_addr)		
    li      r30_cpc_addr, CPC_BASE_ADDR		
    jr      ra
    nop
END(init_cpc)


LEAF(release_mp)


    // At this point, r30_cpc_addr = 0xb2310000
    // CPS_CORE_LOCAL_CONTROL_BLOCK = 0x2000
    // CPC_OTHERL_REG = 0x010
    // CPS_CORE_OTHER_CONTROL_BLOCK = 0x4000
    // CPC_CMDO_REG = 0x000

powerup_next_core:
    // Send PwrUp command to next core causing execution at their reset exception vector.
    li      a0, 1
    sll     a0, 16
    sw      a0, (CPS_CORE_LOCAL_CONTROL_BLOCK | CPC_OTHERL_REG)(r30_cpc_addr)
    li      a0, PWR_UP							// "PwrUp" power domain command.
    sw      a0, (CPS_CORE_OTHER_CONTROL_BLOCK | CPC_CMDO_REG)(r30_cpc_addr)
1:
    jr      ra
    nop

END(release_mp)

/**************************************************************************************
**************************************************************************************/
LEAF(join_domain)


	// Enable coherence and allow interventions from all other cores.
	// (Write access enabled via GCR_ACCESS by core 0.)
	// r22_gcr_addr = 0xbfbf8000
	// CORE_LOCAL_CONTROL_BLOCK = 0x2000
	// GCR_CL_COHERENCE = 0x008
	// GCR_CL_OTHER = 0x018

	// Next command, 0x0f for 1004K, 0x03 for GRX500(2 cores) and 0x33 for GRX500(2x cores + 2x iocu)


	li	    a0, 0x33					   // Set Coherent domain enable for all cores
	sw	    a0, (CORE_LOCAL_CONTROL_BLOCK | GCR_CL_COHERENCE)(r22_gcr_addr)	// GCR_CL_COHERENCE
	ehb

	// Cores other than core 0 can relinquish write access to CM regs here.

    move    a3, zero
	li	 	t0, CORE_ON

next_coherent_core:
    sll     a0, a3, 16
    sw      a0, (CORE_LOCAL_CONTROL_BLOCK | GCR_CL_OTHER)(r22_gcr_addr) 	// GCR_CL_OTHER[CoreNum]

busy_wait_coherent_core:
    lw      a0, (CORE_OTHER_CONTROL_BLOCK | GCR_CO_COHERENCE)(r22_gcr_addr) // GCR_CO_COHERENCE
    beqz    a0, busy_wait_coherent_core   									// Busy wait on cores joining.
    nop

//  bne     a3, r19_more_cores, next_coherent_core
    addiu   a3, 1

    bne     a3, t0, next_coherent_core
	nop

done_join_domain:
	jr      ra
	nop
END(join_domain)

#define C0_MVPCTL $0, 1
#define C0_MVPCONF0 $0, 2
#define C0_VPECTL $1, 1
#define C0_VPECONF0 $1, 2
#define C0_TCSTATUS $2, 1
#define C0_TCRESTART $2, 3
#define C0_TCHALT $2, 4
#define C0_TCBIND $2, 2

LEAF(set_gpr_boot_values)

    li      r1_all_ones, 0xffffffff             // Simplify code and improve clarity
    
    mfc0    k1, CP0_PRID             
    ext     k1, k1, 8, 16						// Company ID & Processor ID
    li	    k0, 0x0190							// 4KEc
    beq     k0, k1, is_not_interAptiv
    li 	    r23_cpu_num, 8						// Assign 8=CPUNum for 4KEc
    
    mfc0    a0, CP0_EBASE                		// Read CP0 EBase
    li      r11_is_cps, 1
    ext	    r23_cpu_num, a0, 0, 4     			// Extract CPUNum
    li      r10_has_mt_ase, 1

    // Every vpe will set up the following to simplify resource initialization.
    mfc0    a0, C0_TCBIND						// Read CP0 TCBind
    ext	    r9_vpe_num, a0,  0, 4				// Extract CurVPE
    ext	    r18_tc_num, a0, 21, 8				// Extract CurTC
    mfc0    a0, C0_MVPCONF0						// C0_MVPConf0
    ext	    r21_more_tcs, a0, 0, 8   			// Extract PTC
    ext	    r20_more_vpes, a0, 10, 4			// Extract VPE

    li      r22_gcr_addr, GCR_CONFIG_ADDR
    lw      r8_core_num, (CORE_LOCAL_CONTROL_BLOCK + GCR_CL_ID) (r22_gcr_addr) // Load GCR_CL_ID
    lw      a0, GCR_CONFIG(r22_gcr_addr)                // Load GCR_CONFIG
    ext     r19_more_cores, a0, PCORES, PCORES_S        // Extract PCORES (r19_more_cores=1 from core 0)
    
    b       done_init_gpr
    nop

is_not_interAptiv: 	// This processor is not a InterAptiv Core. Set up defaults for 4Kc.
    li      r11_is_cps, 0
    li      r8_core_num, 0
    li      r9_vpe_num, 0
    li      r18_tc_num, 0
    li      r20_more_vpes, 0
    li      r21_more_tcs, 0
    li      r19_more_cores, 0
        
	
done_init_gpr:
    jr     ra
    nop
END(set_gpr_boot_values)

LEAF(init_legacy)
	mfc0	v0, CP0_CONFIG5
	li		v1, 0x2fffffff
	and		v0, v0, v1
	mtc0	v0, CP0_CONFIG5
	jr		ra
	nop
END(init_legacy)

