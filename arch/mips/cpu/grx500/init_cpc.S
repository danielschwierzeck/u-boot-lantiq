#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/cps.h>

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.

/**************************************************************************************
**************************************************************************************/
LEAF(init_cpc)
    li      a0, CPC_P_BASE_ADDR				
    sw      a0, GCR_CPC_BASE(r22_gcr_addr)		
    li      r30_cpc_addr, CPC_BASE_ADDR		
    jr      ra
    nop
END(init_cpc)
