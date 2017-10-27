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
#include <config.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>


#define C0_CAUSE_IV_BIT 0x1<<23
#define C0_STATUS_IM_MSK 0xff<<8
#define C0_STATUS_BEV_BIT 0x1<<22
#define C0_STATUS_IE_BIT 0x1

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**********************************************************************************************/
LEAF(init_exception)
        /* CAUSE register */
        li      k0, C0_CAUSE_IV_BIT
        mtc0    k0, CP0_CAUSE

        li      v0, 0x0

        li      v1, 8
        beq     r23_cpu_num, v0, 1f
        nop       
 
        beqz    r23_cpu_num, 1f
        nop         

#ifdef CONFIG_BOOT_FROM_NAND
        li      v0, CONFIG_NAND_SPL_TEXT_BASE
#else
        li      v0, CONFIG_SFDDR_TEXT_BASE
#endif
        li      v1, (0x3ffff<<12)
        and     v0, v1
        mtc0    v0, CP0_EBASE

        li      v0, 0x00000401     
1:
        mtc0    v0, CP0_STATUS
        jr     ra
        nop
END(init_exception)
