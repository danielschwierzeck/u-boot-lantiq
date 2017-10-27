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

#define C0_MVPCTL $0, 1
#define C0_MVPCONF0 $0, 2
#define C0_VPECTL $1, 1
#define C0_VPECONF0 $1, 2
#define C0_TCSTATUS $2, 1
#define C0_TCBIND $2, 2
#define C0_TCRESTART $2, 3
#define C0_TCHALT $2, 4

	.set	noreorder           // Don't allow the assembler to reorder instructions.
	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
**************************************************************************************/
LEAF(init_vpe1)

   // Each vpe will need to set up additional TC bound to it. (No rebinding.)

	// This is executing on TC0 bound to VPE0.  Therefore VPEConf0.MVP is set.
	// Enter config mode
	mfc0	v0, C0_MVPCTL	// read C0_MVPCtl
	or		v0, (1 << 1)		// set VPC
	mtc0	v0, C0_MVPCTL	// write C0_MVPCtl
	ehb

#define a0_NTCS	a0
#define a2_NVPES	a2
#define a3_TC	a3

	// Get number of a3_TC's and VPE's
	mfc0	v0, C0_MVPCONF0	// read C0_MVPCONF0
	ext		a0_NTCS, v0, 0, 8	// extract PTC
	ext		a2_NVPES, v0, 10, 4	// extract PVPE

	// Initialise a3_TC's/VPE's
	move	a3_TC, zero
nexttc:
	// Select TCn
	mfc0	v0, C0_VPECTL	// read C0_VPECTL
	ins		v0, a3_TC, 0, 8		// insert TargTC
	mtc0	v0, C0_VPECTL	// write C0_VPECTL
	ehb

	// Bind a3_TC to next VPE
	beqz	a3_TC, nextvpe	// Don't rebind TC0
	nop

	// Halt a3_TC being configured
	li		v0, 1			    // set Halt bit
	mttc0	v0, C0_TCHALT	// write C0_TCHALT
	ehb

	move    v1, a3_TC
	# Bind TC to a VPE
	mftc0   v0, C0_TCBIND	// Read C0_TCBind
	ins     v0, v1, 0, 4	// change S_TCBindCurVPE
	mttc0   v0, C0_TCBIND	// write C0_TCBind

	// This code checks to see if the a3_TC mumber is
	// less than the VPE number. This ensures
	// in a system with more than 1 VPE and TCs each
	// VPE will have at least one a3_TC bound to it
	// and any TCs left over will be bound to the last a3_TC
	slt		v1, a2_NVPES, a3_TC
	bnez	v1, 2f			// Bind spare a3_TC's to VPElast
	move	v1, a2_NVPES

	// Set XTC for active a3_TC's
	mftc0	v0, C0_VPECONF0	// read C0_VPECONF0
	ins		v0, a3_TC, 21, 8 // insert XTC
	mttc0	v0, C0_VPECONF0	// write C0_VPECONF0

	move	v1, a3_TC
2:
	// Bind a3_TC to a VPE
	mftc0	v0, C0_TCBIND	// read C0_TCBIND
	ins		v0, v1, 0, 4	// insert VPE
	mttc0	v0, C0_TCBIND	// write C0_TCBIND

	// Set up TCStatus register:
	// Disable Coprocessor Usable bits
	// Disable MDMX/DSP ASE
	// Clear Dirty a3_TC
	// not dynamically allocatable
	// not allocated
	// Kernel mode
	// interrupt exempt
	// ASID 0
	li		v0, (1 << 10)	// set IXMT
	mttc0	v0, C0_TCSTATUS	// write C0_TCSTATUS

	// Initialize the a3_TC's register file
	li v0, 0xdeadbeef
	mttgpr	v0, $1
	mttgpr	v0, $2
	mttgpr	v0, $3
	mttgpr	v0, $4
	mttgpr	v0, $5
	mttgpr	v0, $6
	mttgpr	v0, $7
	mttgpr	v0, $8
	mttgpr	v0, $9
	mttgpr	v0, $10
	mttgpr	v0, $11
	mttgpr	v0, $12
	mttgpr	v0, $13
	mttgpr	v0, $14
	mttgpr	v0, $15
	mttgpr	v0, $16
	mttgpr	v0, $17
	mttgpr	v0, $18
	mttgpr	v0, $19
	mttgpr	v0, $20
	mttgpr	v0, $21
	mttgpr	v0, $22
	mttgpr	v0, $23
	mttgpr	v0, $24
	mttgpr	v0, $25
	mttgpr	v0, $26
	mttgpr	v0, $27
	mttgpr	v0, $28
	mttgpr	v0, $29
	mttgpr	v0, $30
	mttgpr	v0, $31

nextvpe:
	slt		v1, a2_NVPES, a3_TC
	bnez	v1, donevpe		// No more VPE's
	nop

	// Disable multi-threading with a3_TC's
	mftc0	v0, C0_VPECTL	// read C0_VPECTL
	ins		v0, zero, 15, 1	// clear TE
	mttc0	v0, C0_VPECTL	// write C0_VPECTL

	beqz	a3_TC, 1f
	nop

	// For VPE1..n
	// Clear VPA and set master VPE
	mftc0	v0, C0_VPECONF0	// read C0_VPECONF0
	ins		v0, zero, 0, 1	// insert VPA
	or		v0, (1 << 1)	// set MVP
	mttc0	v0, C0_VPECONF0	// write C0_VPECONF0

	mfc0	v0, CP0_STATUS	// read CP0_STATUS
	mttc0	v0, CP0_STATUS	// write CP0_Status

	li		v0, 0x12345678
	mttc0	v0, CP0_EPC		// write C0_EPC

	mttc0	zero, CP0_CAUSE	// write C0_CAUSE

	mfc0	v0, CP0_CONFIG	// read C0_CONFIG
	mttc0	v0, CP0_CONFIG	// write C0_CONFIG

	mftc0	v0, CP0_EBASE	// read C0_EBASE
	ext		v0, v0, 0, 10	// extract CPUNum
	mttgpr	v0, r23_cpu_num

	// vpe1 of each core can execute cached as it's L1 I$ has already been initialized.
    // and the L2$ has been initialized or "disabled" via CCA override.
	la		a1, __reset_vector
//TRI 1-1-2014
//Temporary comment out until cache issue is fixed	
//	ins     a1, zero, 29, 1 // Convert to cached kseg0 address in case we linked to kseg1.
	mttc0   a1, C0_TCRESTART // write C0_TCRESTART

	// Yes.. this is undoing all of the work done above... :)
	mftc0	v0, C0_TCSTATUS	// read C0_TCSTATUS
	ins	    v0, zero, 10, 1	// insert IXMT
	ori	    v0, (1 << 13)	// set A
	mttc0	v0, C0_TCSTATUS	// write C0_TCSTATUS

	mttc0	zero, C0_TCHALT	// write C0_TCHALT

	mftc0	v0, C0_VPECONF0	// read C0_VPECONF0
	ori	    v0, 1		    // set VPA
	mttc0	v0, C0_VPECONF0	// write C0_VPECONF0
1:

donevpe:
	addu	a3_TC, 1
	sltu	v1, a0_NTCS, a3_TC
	beqz	v1, nexttc
	nop

	// Exit config mode
	mfc0	v0, C0_MVPCTL	// read C0_MVPCtl
    ori     v0, 1           // set EVP will enable execution by vpe1
	ins	    v0, zero, 1, 1	// insert VPC
	mtc0	v0, C0_MVPCTL	// write C0_MVPCtl
	ehb

#undef a0_NTCS
#undef a2_NVPES
#undef a3_TC

done_init_vpe1:

    jr   ra
    nop
END(init_vpe1)

