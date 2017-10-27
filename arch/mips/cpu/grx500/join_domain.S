#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/cps.h>

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.

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
