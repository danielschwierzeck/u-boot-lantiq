#include <cp0regdef.h>
#include <asm.h>
#include <regdef.h>
#include <cacheops.h>
#include <addrspace.h>
#include <stackframe.h>
#include <autoconf.h>

    .set noreorder

	.globl _start
	.text
_start:
	b     reset
        nop

reset:		  
	/* Disable interrupts */
	mtc0	zero, CP0_STATUS

        /* Disable watch exception. */
        mtc0    zero, CP0_WATCHLO
        mtc0    zero, CP0_WATCHHI


	/* set up stack */
	li	sp, 0x82000000-0x100000 

 /* We are in PIC mode, so need to initialize GOT pointer */

    bal     1f
    nop
    .word   _GLOBAL_OFFSET_TABLE_
1:
     move    gp, ra
     lw      t1, 0(ra)
     move    gp, t1


	/* jump to main */
	jal	main
	nop		
loop:
	j	loop
	nop


