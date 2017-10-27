#include <asm/boot.h>
#include <config.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>
#include <asm/cps.h>

#define C0_MVPCTL $0, 1
#define C0_MVPCONF0 $0, 2
#define C0_VPECTL $1, 1
#define C0_VPECONF0 $1, 2
#define C0_TCSTATUS $2, 1
#define C0_TCRESTART $2, 3
#define C0_TCHALT $2, 4
#define C0_TCBIND $2, 2

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
**************************************************************************************/
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
