#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/cps.h>

	.set	noreorder           
	.set	noat                

/**************************************************************************************
**************************************************************************************/
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
