#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/cps.h>

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
After the first processor in an MP system has completed the boot code, 
it can release the remaining processors to execute the boot code.
**************************************************************************************/
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
