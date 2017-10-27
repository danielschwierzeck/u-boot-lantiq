#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/cps.h>

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
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
done_cm_init:
	jr      ra
	nop
END(init_cm)
