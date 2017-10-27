##
## Redundancy fix loading and Memories' read margin loading from efuse
## Written by Amir Rosenblum, Jul. 2011
##
## Structure in efuse array:
##
## Offset  2 = Shared RAM block 0 - Select address = 0xA01F_019C, selector = 0x00, load fix into 0xA01F_0178
## Offset  3 = Shared RAM block 1 - Select address = 0xA01F_019C, selector = 0x02, load fix into 0xA01F_0178
## Offset  4 = Shared RAM block 2 - Select address = 0xA01F_019C, selector = 0x04, load fix into 0xA01F_0178
## Offset  5 = Shared RAM block 3 - Select address = 0xA01F_019C, selector = 0x06, load fix into 0xA01F_0178
## Offset  6 = IRAM block 0       - Select address = 0xA018_00E0, selector = 0x10, load fix into 0xA018_00EC
## Offset  7 = IRAM block 1       - Select address = 0xA018_00E0, selector = 0x12, load fix into 0xA018_00EC
## Offset  8 = IRAM block 2       - Select address = 0xA018_00E0, selector = 0x14, load fix into 0xA018_00EC
## Offset  9 = IRAM block 3       - Select address = 0xA018_00E0, selector = 0x16, load fix into 0xA018_00EC
## Offset 10 = IRAM block 4       - Select address = 0xA018_00E0, selector = 0x18, load fix into 0xA018_00EC
## Offset 11 = IRAM block 5       - Select address = 0xA018_00E0, selector = 0x1a, load fix into 0xA018_00EC
## Offset 12 = IRAM block 6       - Select address = 0xA018_00E0, selector = 0x1c, load fix into 0xA018_00EC
## Offset 13 = IRAM block 7       - Select address = 0xA018_00E0, selector = 0x1e, load fix into 0xA018_00EC
## Offset 14 = IRAM block 8       - Select address = 0xA018_00E0, selector = 0x20, load fix into 0xA018_00EC
## Offset 15 = IRAM block 9       - Select address = 0xA018_00E0, selector = 0x22, load fix into 0xA018_00EC
## Offset 16 = IRAM block 10      - Select address = 0xA018_00E0, selector = 0x24, load fix into 0xA018_00EC
## Offset 17 = DCACHE0            - Select address = 0xA018_00E0, selector = 0x08/0x09, load fix into 0xA018_00EC (bits[31: 0] / bits [63:32])
## Offset 18 = DCACHE1            - Select address = 0xA018_00E0, selector = 0x0a/0x0b, load fix into 0xA018_00EC (bits[31: 0] / bits [63:32])
## Offset 19 = ICACHE             - Select address = 0xA018_00E0, selector = 0x00/0x01/0x02/0x03, load fix into 0xA018_00EC (bits[31: 0] / bits[63: 32] / bits[95: 64] / bits[127: 96])
	

	.equ	SHARED_REG_BASE,	0xa71c0000

	.equ    EFUSE_DATA,		0x0120
	.equ    EFUSE_ADDRESS,          0x0124
	.equ    EFUSE_CONTROL,          0x0128
	.equ    EFUSE_STATUS,           0x012c
	.equ    EFUSE_TIMER_CONFIG1,    0x0130
	.equ    EFUSE_TIMER_CONFIG2,    0x0134

	.equ	EFUSE_BUSY,		0x1
	.equ	EFUSE_INIT_DONE,	0x2

		
	.equ	SYS_IF_BASE,		0xa0180000
	.equ	CPU_SELECT_OFFSET,	0x00e0
	.equ	CPU_LOAD_OFFSET,	0x00ec

		
	.equ	HT_EXT_BASE,		0xa01f0000
	.equ	MAC_SELECT_OFFSET,	0x019c
	.equ	MAC_LOAD_OFFSET,	0x0178
	

	.equ	RED_FIX_START_MAC_ADDR,	0x2<<3
	.equ	RED_FIX_START_CPU_ADDR, 0x6<<3
	.equ	RED_FIX_START_DCACHE,   0x11<<3
	.equ	RED_FIX_END_ADDR_PLUS1,	0x14<<3

	li	$10,SHARED_REG_BASE

	li	$20,RED_FIX_START_MAC_ADDR
	li	$23,RED_FIX_START_CPU_ADDR
	li	$24,HT_EXT_BASE
	li	$25,0x0 /* Used to set fix selector, SHRAM block 0 selector is 0x00 */
	/* Start process only when machine is ready */
wait_if_busy_pre_start:	
	lw	$21,EFUSE_STATUS($10)
	andi	$21,EFUSE_BUSY
	bne	$21,$0,wait_if_busy_pre_start

#     #    ##    ###  #    #
##   ##   #  #    #   #    #
# # # #  #    #   #   ##   #
#  #  #  #    #   #   # #  #
#     #  #    #   #   #  # #
#     #  ######   #   #   ##
#     #  #    #   #   #    #
#     #  #    #   #   #    #
#     #  #    #  ###  #    #

	/* Main loop starts here */
	/* Currently, handling Shared RAM */
efuse_start_shram_loop:	
	bal	do_read_from_efuse

	beq	$22,$0,read_next_byte_shram

	/* Fix is required */
	sw	$25,MAC_SELECT_OFFSET($24)
	addiu	$22,-1 /* Subtract 1 from efuse read value - we add 1 to the fix vector value as a flag that a fix is needed */
	li	$26,1
	sllv	$26,$26,$22 /* Create the one-hot fix value */
	sw	$26,MAC_LOAD_OFFSET($24)
	
read_next_byte_shram:
	addiu	$20,+8
	addiu	$25,+2 /* Set selector for next RAM block */
	bne	$20,$23,efuse_start_shram_loop /* At this point, $23 points to start of CPU */

	/* Shared RAM is done, start with IRAM */
	li	$24,SYS_IF_BASE
	li	$23,RED_FIX_START_DCACHE
	li	$25,0x10 /* Used to set fix selector, IRAM block 0 selector is 0x10 */

efuse_start_iram_loop:		
	bal	do_read_from_efuse

	beq	$22,$0,read_next_byte_iram

	/* Fix is required */
	sw	$25,CPU_SELECT_OFFSET($24)
	addiu	$22,-1 /* Subtract 1 from efuse read value - we add 1 to the fix vector value as a flag that a fix is needed */
	li	$26,1
	sllv	$26,$26,$22 /* Create the one-hot fix value */
	sw	$26,CPU_LOAD_OFFSET($24)
	
read_next_byte_iram:
	addiu	$20,+8
	addiu	$25,+2 /* Set selector for next RAM block */
	bne	$20,$23,efuse_start_iram_loop /* At this point, $23 points to start of DCACHE */

	/* IRAM is done, move to DCACHE */
	bal	do_read_from_efuse

	beq	$22,$0, test_dcache1
	
	/* DCACHE0 needs fixing */	
	li	$26,0x1
	addiu	$22,-1
	li	$25,0x20
	sub	$25,$22,$25
	bgez    $25,fix_dc0_bits63to32
	
	/* Fix is needed for bits[31:0] */
	li	$25,0x8
	sw	$25,CPU_SELECT_OFFSET($24)
	sllv	$26,$26,$22
	sw	$26,CPU_LOAD_OFFSET($24)
	b	test_dcache1

	/* Fix is needed for bits[63:32] */
fix_dc0_bits63to32: /* In this case, $25 holds the fix vector minus 0x20. Manipulate unused $22 instead of $25 */
	li	$22,0x9
	sw	$22,CPU_SELECT_OFFSET($24)
	sllv	$26,$26,$25
	sw	$26,CPU_LOAD_OFFSET($24)

	/* DCACHE0 is done, move to DCACHE1 */
test_dcache1:	
	addiu	$20,+8
	bal	do_read_from_efuse

	beq	$22,$0, test_icache
	
	/* DCACHE1 needs fixing */	
	li	$26,0x1
	addiu	$22,-1
	li	$25,0x20
	sub	$25,$22,$25
	bgez    $25,fix_dc1_bits63to32
	
	/* Fix is needed for bits[31:0] */
	li	$25,0xa
	sw	$25,CPU_SELECT_OFFSET($24)
	sllv	$26,$26,$22
	sw	$26,CPU_LOAD_OFFSET($24)
	b	test_icache

	/* Fix is needed for bits[63:32] */
fix_dc1_bits63to32: /* In this case, $25 holds the fix vector minus 0x20. Manipulate unused $22 instead of $25 */
	li	$22,0xb
	sw	$22,CPU_SELECT_OFFSET($24)
	sllv	$26,$26,$25
	sw	$26,CPU_LOAD_OFFSET($24)

	/* DCACHE1 is done, move to ICACHE */
test_icache:	
	addiu	$20,+8
	bal	do_read_from_efuse

	beq	$22,$0, efuse_routine_done

	/* ICACHE needs fixing */
	li	$26,0x0 /* $26 will follow the required selector value */
	addiu	$22,-1
	li	$25,0x20
chunk_loop:
	addiu	$26,+1 /* We start by incrementing the selector value. This means that we point to NEXT required value */
	sub	$22,$22,$25
	bgez    $22,chunk_loop

	/* Decrement $26 to point to exact selector required */
	addiu	$26,-1
	sw	$26,CPU_SELECT_OFFSET($24)
	/* Now, generate the one-hot vector */
	li	$26,0x1
	sllv	$26,$26,$22
	sw	$26,CPU_LOAD_OFFSET($24)
			
	b	efuse_routine_done


#####  #####  #   #   ###   #####        ##     ###    ###   #####   ###    ### 
#      #      #   #  #   #  #           #  #   #   #  #   #  #      #   #  #   #
#      #      #   #  #      #          #    #  #      #      #      #      #	 
#      #      #   #  #      #          #    #  #      #      #      #      #	 
####   ####   #   #   ###   ####       #    #  #      #      ####    ###    ### 
#      #      #   #      #  #          ######  #      #      #          #      #
#      #      #   #      #  #          #    #  #      #      #          #      #
#      #      #   #  #   #  #          #    #  #   #  #   #  #      #   #  #   #
#####  #       ###    ###   #####      #    #   ###    ###   #####   ###    ### 

do_read_from_efuse:
	/* Write address to read from */
	sw	$20,EFUSE_ADDRESS($10)

	/* Set READ bit - also triggers machine operation */
	sw	$0,EFUSE_CONTROL($10)
	
	/* Wait for machine ready */
wait_if_busy:	
	lw	$21,EFUSE_STATUS($10)
	andi	$21,EFUSE_BUSY
	bne	$21,$0,wait_if_busy

	/* Load read data into $22 */
	lw	$22,EFUSE_DATA($10)
	jr	$31
	
	/* We are done */
efuse_routine_done:
	nop
	
####   #     #         #       ###     ##    #####   ###  #    #   ####
#   #  ##   ##         #      #   #   #  #    #   #   #   #    #  #    #
#   #  # # # #         #      #   #  #    #   #   #   #   ##   #  #
#   #  #  #  #         #      #   #  #    #   #   #   #   # #  #  #
####   #     #         #      #   #  #    #   #   #   #   #  # #  #
##     #     #         #      #   #  ######   #   #   #   #   ##  #  ###
# #    #     #         #      #   #  #    #   #   #   #   #    #  #    #
#  #   #     #         #      #   #  #    #   #   #   #   #    #  #   ##
#   #  #     #         #####   ###   #    #  #####   ###  #    #   ### #

	/* RM loading in USB mode is done as follows:	       */
	/* efuse address 56 (0x38), bit[6]    = RM valid       */
	/* efuse address 56 (0x38), bits[2:0] = ICACHE DataRAM - to be loaded to 0x001800d4, bit mask 00000007 */
	/* efuse address 56 (0x38), bits[5:3] = DCACHE DataRAM - to be loaded to 0x001800d4, bit mask 00007000 */
	/* efuse address 57 (0x39), bits[2:0] = IRAM/SHRAM     - to be loaded to 0x001800d8, bit mask 77777777 (IRAM), 0x001800dc, bit mask 777 (IRAM8,9,10)  and 0x001f01f8, bit mask 00007777 (SHRAM) */
	/* efuse address 57 (0x39), bits[5:3] = USB RAM        - to be loaded to 0x070000d4, bit mask 70000000 */
	.equ	EFUSE_RM_REG0_ADDR,	0x38<<3
	.equ	EFUSE_RM_REG1_ADDR,	0x39<<3
	
rm_wait_if_busy_pre_start:	
	lw	$21,EFUSE_STATUS($10)
	andi	$21,EFUSE_BUSY
	bne	$21,$0,rm_wait_if_busy_pre_start

	li	$20,EFUSE_RM_REG0_ADDR
	bal	do_read_from_efuse

	li	$21,0x1<<6
	and	$21,$21,$22
	beq	$21,$0,rm_routine_done /* No need to load RM */

	li	$21,SYS_IF_BASE
	/* Load the register which holds RM for ICACHE and DCACHE */
	lw	$23,0x00d4($21)
	/* Clear the fields for ICACHE and DCACHE. Keep the rest untouched. */
	li	$24,0xffff8ff8
	and	$23,$23,$24

	/* Prepare the mask for ICACHE, DCACHE */
	/* Mask bits[5:3] of the original efuse value */
	andi	$24,$22,0x38
	/* Shift to appropriate location - from [5:3] to [14:12] */
	sll	$24,9
	/* Now, add bits[2:0] from efuse */
	andi	$22,$22,0x7
	or	$24,$24,$22

	/* Combine all together back to the RM register to be written */
	or	$23,$23,$24
	sw	$23,0x00d4($21)
	
	/* SHRAM/IRAM - since for these RAMs, the register holds only RM for these specific memories,      */
	/* The approach is not read-modify-write. We create the RM register from scratch and just write it */

	li	$20,EFUSE_RM_REG1_ADDR
	bal	do_read_from_efuse

	li	$25,0x7
	/* Get the field for IRAM/SHRAM into RF22 */
	and	$25,$22,$25
	/* Duplicate it into RF23 - create a vector with two RM values */
	sll	$23,$25,4
	or	$23,$23,$25
	/* Duplicate it once again - this time to RF22 */
	sll	$25,$23,8
	or	$25,$25,$23
	/* And once again - into RF23 */
	sll	$23,$25,16
	or	$23,$23,$25
	/* We now have a 8-field value in $23. We can write it into IRAM's RM and also into SHRAM - although for SHRAM we need only 4 */
	/* Write to IRAM's RM reg. */
	li	$21,SYS_IF_BASE
	sw	$23,0x00d8($21)
	sw	$23,0x00dc($21)
	/* Write to SHRAM's RM reg. */
	li	$21,HT_EXT_BASE
	sw	$23,0x01f8($21)

	/* USB ROM */
	andi	$22,0x38
	sll	$22,25

	li	$21,0xa7000000
	lw	$25,0x00d4($21)
	li	$23,0x0fffffff
	and	$25,$25,$23
	or	$25,$25,$22

	sw	$25,0x00d4($21)
	
	/* We are done */
rm_routine_done:	
	nop	

	
