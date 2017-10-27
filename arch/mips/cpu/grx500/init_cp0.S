#include <asm/boot.h>
#include <config.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>


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
