#include "asm/m32c0.h"
#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>


	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
init_tlb.S will initialize the Translation Look aside Buffer (TLB) if present. 
The TLB needs to be initialized so that there are no random translations in it.
**************************************************************************************/
LEAF(init_tlb)

check_for_tlb:
	// Determine if we have a TLB
	mfc0    v1, C0_CONFIG			// read C0_Config
	ext	    v1, v1, 7, 3			// extract MT field
	li	    a3, 0x1					// load a 1 to check against
	bne	    v1, a3, done_init_tlb
	nop

start_init_tlb:
	mfc0    v0, C0_CONFIG1			// C0_Config1

	// Config1MMUSize == Number of TLB entries - 1
	ext     v1, v0, CFG1_MMUSSHIFT, 6 // extract MMU Size, v1 = 1f initially

	mtc0    zero, C0_ENTRYLO0		// write C0_EntryLo0
	mtc0    zero, C0_ENTRYLO1		// write C0_EntryLo1
	mtc0    zero, C0_PAGEMASK		// write C0_PageMask
	mtc0    zero, C0_WIRED			// write C0_Wired
	li	    a0, 0x80000000

next_tlb_entry_pair:
	mtc0    v1, C0_INDEX			// write C0_Index
	mtc0	a0, C0_ENTRYHI			// write C0_EntryHi
	ehb
	tlbwi
	add	    a0, (2<<13)				// Add 16K to the address to avoid TLB conflict with previous entry

	bne		v1, zero, next_tlb_entry_pair
	add	    v1, -1

done_init_tlb:
    jr      ra
    nop
END(init_tlb)
