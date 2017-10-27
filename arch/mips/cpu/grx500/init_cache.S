/*
Copyright (c) MIPS Technologies, Inc.  All rights reserved.  Unpublished
rights reserved
under the copyright laws of the United States of America and other countries.

Redistribution and use in source and binary forms, with or without
modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <asm/boot.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>
	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.

/**************************************************************************************
* init_icache invalidates all Instruction cache entries
**************************************************************************************/

LEAF(sys_init_icache)

	// Can be skipped if using magic simulation cache flush

	// Determine how big the I$ is
	mfc0	v0, CP0_CONFIG, 1				

	// I$ Line Size
	ext	    v1, v0, MIPS_CONF1_IL_SHIFT, 3		// extract IL (16B/4KEc, 32B/InterAptiv)

	// Skip ahead if No I$
	beq	    v1, zero, done_icache
	nop

	li	    a2, 2
	sllv    v1, a2, v1					// Now have true I$ line size in bytes (v1=32B/set) 

	ext	    a0, v0,  MIPS_CONF1_IS_SHIFT , 3		// extract IS
	li	    a2, 64
	sllv    a0, a2, a0					// I$ Sets per way (512sets/way/4KEc, 256sets/way/InterAptiv)

	// Config1IA == I$ Assoc - 1
	ext	    a1, v0, MIPS_CONF1_IA_SHIFT, 3		// extract IA
	add	    a1, 1					// a1 = 4 ways	

	mul	    a0, a0, a1					// Total number of sets (2048sets/4KEc, 1024sets/InterAptiv)
	lui	    a2, 0x8000					// 0x9fc0 Get a KSeg0 address for cacheops

	// Clear TagLo/TagHi registers
	mtc0    zero, CP0_TAGLO				// write C0_ITagLo $28,0

	// For 4Kec
	mtc0    zero, CP0_TAGHI

	move    a3, a0						

next_icache_tag:
	cache   0x8, 0(a2)					// ICIndexStTag
	add	    a3, -1						// Decrement set counter
	bne     a3, zero, next_icache_tag
	add     a2, v1						// Get next line address

done_icache:

    jr      ra
    nop
END(sys_init_icache)

/**************************************************************************************
* init_icache invalidates all Instruction cache entries
**************************************************************************************/
LEAF(sys_init_dcache)

	mfc0	v0, CP0_CONFIG, 1				// read C0_Config1

	// Isolate D$ Line Size
	ext	    v1, v0,  MIPS_CONF1_DL_SHIFT, 3		// extract DL

	// Skip ahead if No D$
	beq	    v1, zero, done_dcache
	nop

	li	    a2, 2
	sllv	v1, a2, v1					// Now have true D$ line size in bytes (16B/set/4KEc, 32B/set/InterAptiv)

	ext	    a0, v0, MIPS_CONF1_DS_SHIFT, 3		// extract DS
	li	    a2, 64
	sllv	a0, a2, a0					// D$ Sets per way (512sets/way/4KEc, 256sets/way/InterAptiv)

	ext	    a1, v0,  MIPS_CONF1_DA_SHIFT, 3		// extract DA
	add	    a1, 1						// a1 = 4 ways

	mul	    a0, a0, a1					// Get total number of sets (2048sets/4KEc, 1024sets/InterAptiv)

	// Clear TagLo/TagHi registers
	// Clear TagLo/TagHi registers
	mtc0	zero, CP0_TAGLO				// write C0_TagLo 

	// For 4Kec
	mtc0    zero, CP0_TAGHI
	
	mtc0	zero, CP0_TAGLO, 2			// write C0_DTagLo
	mtc0	zero, CP0_TAGHI, 2			// write C0_DTagHi
	
//DCIndexStTag	
	lui     a2, 0x8000		    		// 9fc0 Get a KSeg0 address for cacheops
	move	a3, a0						
1:
	// Index Store Tag Cache Op
	// Will invalidate the tag entry, clear the lock bit, and clear the LRF bit

        cache	    0x9, 0(a2)					// DCIndexStTag=0x9
	add	    a3, -1			    		// Decrement set counter

	bne	    a3, zero, 1b
	add	    a2, v1		    			// Get next line address
	
done_dcache:
    jr      ra
    nop
END(sys_init_dcache)

/**************************************************************************************
* fetch and lock 16KB dcache lines 
**************************************************************************************/
LEAF(init_dcache_lock)

	mfc0	v0, CP0_CONFIG, 1				// read C0_Config1

	// Isolate D$ Line Size
	ext	    v1, v0,  MIPS_CONF1_DL_SHIFT, 3		// extract DL

	// Skip ahead if No D$
	beq	    v1, zero, done_dcache
	nop

	li	    a2, 2
	sllv	v1, a2, v1					// Now have true D$ line size in bytes (16B/4KEc, 32B/InterAptiv)

	ext	    a0, v0, MIPS_CONF1_DS_SHIFT, 3		// extract DS
	li	    a2, 64
	sllv	a0, a2, a0					// D$ Sets per way (512sets/way/4KEc, 256sets/way/InterAptiv)

	ext	    a1, v0, MIPS_CONF1_DA_SHIFT, 3		// extract DA
	add	    a1, 1						// (4ways/4KEc, 8ways/InterAptiv

	mul	    a0, a0, a1					// Get total number of sets (2048sets/4KEc, 1024sets/InterAptiv)

	
//DCAddrFetchLock for first 8KBytes	
	lui	    a2, 0x9fc0		    		// 9fc0 Get a KSeg0 address for cacheops
	move	a3, a0						
	
	li		a0, 2
	srlv	a3, a3, a0					// a3/=4, 8KByte 
	
1:
	// Index Store Tag Cache Op
	// Will invalidate the tag entry, clear the lock bit, and clear the LRF bit

        cache	0x1d, 0(a2)					// DCAddrFetchLock=0x1d
	add	    a3, -1			    		// Decrement set counter

	bne	    a3, zero, 1b
	add	    a2, v1		    			// Get next line address

done_dcache_lock:
    jr      ra
    nop
END(init_dcache_lock)

/**************************************************************************************
**************************************************************************************/
LEAF(disable_L23)
    beqz    r11_is_cps, done_disable_L23	# no cps skips
    nop

	bnez    r8_core_num, done_disable_L23	# Only done from core 0.

    // Use CCA Override disable the L2 cache
    // NOTE: If you have a L3 cache you must add code here
    // to disable it or initialize it if it can't be disabled.
    // Disable the L2 cache using CCA override by writing a 0x50 to
    // the GCR Base register. 0x50 enables the CCA override bit and sets
    // the CCA to uncached.

	lw	    a0, 0x0008(r22_gcr_addr)  	// Read GCR_BASE
    li      a3, 0x50                  	// Enable CCA and set to uncached
    ins     a0, a3, 0, 8    			// Insert bits
    sw      a0, 0x0008(r22_gcr_addr)  	// Write GCR_BASE

done_disable_L23:
    jr      ra
    nop
END(disable_L23)

/**************************************************************************************
* Initialize the L2 and L3 caches
**************************************************************************************/
LEAF(init_L23)
    beqz    r11_is_cps, done_cach_init	// no cps skips
    nop

	bnez    r8_core_num, done_cach_init	// Only done from core 0.

	// L2 Cache initialization routine
	// Check L2 cache size
	mfc0	v0, CP0_CONFIG, 2				// Read C0_Config2
	// Isolate L2$ Line Size
	ext	    v1, v0, 4, 4				// extract L2 line size
	li	    a2, 2
	sllv	v1, a2, v1					// Now have true L2$ line size in bytes (32B/InterAptiv)

	// Isolate L2 Sets per Way (cache lines per way)
	ext	    a3, v0, 8, 4				// extrace sets per way encoding
	li	    a2, 64
	sllv	a3, a2, a3					// L2$ Sets per way (1024 sets/way)

	// Isolate L2 Associativity (number of ways)
	// L2$ Assoc (-1)
	ext	    a1, v0, 0, 4				// extract ways encoding
	add	    a1, 1						// Decode L2 number of ways (8 ways)

	mul	    a3, a3, a1					// Get total number of sets (8196 sets)
	lui	    a2, 0x8000					// Get a KSeg0 address for cacheops

	// Clear L23TagLo/L23TagHi registers these are used to set the cache tag
	mtc0	zero, CP0_TAGLO, 4
	
	// L2$ Index Store Tag Cache Op
	// Will invalidate the tag entry, clear the lock bit, and clear the LRF bit
next_L2cache_tag:
	cache	0xb, 0(a2)					// Write Tag using index store tag
	add	    a3, -1						// Decrement set counter

	bne	    a3, zero, next_L2cache_tag 	// Done yet?
	add	    a2, v1						// Get next line address (each tag covers one line)

done_l2cache:
    // disable CCA Override to enable L2 cache
	lw	    a0, 0x0008(r22_gcr_addr)  	// GCR_BASE
    ins     a0, zero, 0, 8            	// CCA Override disabled
    sw      a0, 0x0008(r22_gcr_addr)  	// GCR_BASE

done_cach_init:
    jr      ra
    nop
END(init_L23)

LEAF(change_k0_cca)
	// NOTE! This code must be executed in KSEG1 (not KSGE0 uncached)
    // Set CCA for kseg0 to cacheable
	mfc0	v0, CP0_CONFIG				// read C0_Config
	beqz    r11_is_cps, set_kseg0_cca
	li	    v1, 3						// CCA for non coherent core
	li	    v1, 5						// CCA for coherent cores

set_kseg0_cca:

    ins	    v0, v1, 0, 3				// insert K0
    mtc0	v0, CP0_CONFIG				// write C0_Config
    jr.hb      ra
    nop

END(change_k0_cca)
