/*
 * Copyright (C) 2011 Lantiq Asia Pacific, Ltd.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 */
    
#include <config.h>
#include <version.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
#include <asm/cacheops.h>
#include <asm/addrspace.h>
#include <asm/yamon.h>
	.set mips32
    .set noreorder
	.globl _start
	.text
_start:
			  
	/* Disable interrupts */
	mtc0	zero, CP0_STATUS

    /* Disable watch exception. */
    mtc0    zero, CP0_WATCHLO
    mtc0    zero, CP0_WATCHHI


	/* set up stack */
	li	sp, 0xbe1a0000 + 0x4000 - 0x400

/* Initialize GOT pointer.
    */
    bal     1f
    nop
   .word   _GLOBAL_OFFSET_TABLE_
1:
    move    gp, ra
    lw      t1, 0(ra)
    move    gp, t1
							
    la      t9, lowlevel_init
    jalr    t9
	nop
		

	/* jump to main */
	jal	init_icache
	nop
			
    jal init_dcache
	nop

#if 1
change_got_table:
    bal     1f
    nop
    .word   got_size
1:
    move    t1, ra
    lw      t1, 0(t1)
    move    t0, gp
    add     t1, t0, t1
    addi    t0, 8 /*skip first 2 entries*/
2:
    lw      t2, 0(t0)
    subu    t2, 0x20000000
    sw      t2, 0(t0)
    bne     t0, t1, 2b
    addi    t0, t0, 4
    subu    gp, 0x20000000
#endif

    jal ether_board_init
	nop

    li   t9, 0xa0100000
	jr   t9 
   
	b   loop
	nop

loop:
	j	loop
	nop

