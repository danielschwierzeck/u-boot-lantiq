/*
 * Copyright (c) 2004-2005 MIPS Technologies, Inc.
 * All rights reserved.
 * 
 * Unpublished rights (if any) reserved under the copyright laws of the
 * United States of America and other countries.
 * 
 * This code is proprietary to MIPS Technologies, Inc. ("MIPS
 * Technologies").  Any copying, reproducing, modifying or use of
 * this code (in whole or in part) that is not expressly permitted
 * in writing by MIPS Technologies or an authorized third party is
 * strictly prohibited.  At a minimum, this code is protected under
 * unfair competition and copyright laws.  Violations thereof may result
 * in criminal penalties and fines.
 * 
 * MIPS Technologies reserves the right to change this code to improve
 * function, design or otherwise.  MIPS Technologies does not assume any
 * liability arising out of the application or use of this code, or of
 * any error or omission in such code.  Any warranties, whether express,
 * statutory, implied or otherwise, including but not limited to the
 * implied warranties of merchantability or fitness for a particular
 * purpose, are excluded.  Except as expressly provided in any written
 * license agreement from MIPS Technologies or an authorized third party,
 * the furnishing of this code does not give recipient any license to
 * any intellectual property rights, including any patent rights, that
 * cover this code.
 * 
 * This code shall not be exported, reexported, transferred, or released,
 * directly or indirectly, in violation of the law of any country or
 * international law, regulation, treaty, Executive Order, statute,
 * amendments or supplements thereto.  Should a conflict arise regarding
 * the export, reexport, transfer, or release of this code, the laws of
 * the United States of America shall be the governing law.
 * 
 * This code constitutes one or more of the following: commercial
 * computer software, commercial computer software documentation or
 * other commercial items.  If the user of this code, or any related
 * documentation of any kind, including related technical data or
 * manuals, is an agency, department, or other entity of the United
 * States government ("Government"), the use, duplication, reproduction,
 * release, modification, disclosure, or transfer of this code, or
 * any related documentation of any kind, is restricted in accordance
 * with Federal Acquisition Regulation 12.212 for civilian agencies
 * and Defense Federal Acquisition Regulation Supplement 227.7202 for
 * military agencies.  The use of this code by the Government is further
 * restricted in accordance with the terms of the license agreement(s)
 * and/or applicable contract terms and conditions covering this code
 * from MIPS Technologies or an authorized third party.
 * 
 * 
 */

/*
 * mips/mt.h: MIPS MT ASE registers and intrinsics
 */


#ifndef _MIPS_MT_H_
#define _MIPS_MT_H_

#include <asm/m32c0.h>



/*
 * MIPS32 MVPControl Register (CP0 Register 0, Select 1)
 */
#define MVPCONTROL_EVP		0x00000001
#define MVPCONTROL_VPC		0x00000002
#define MVPCONTROL_STLB		0x00000004

/*
 * MIPS32 MVPConf0 Register (CP0 Register 0, Select 2)
 */
#define MVPCONF0_PTC		0x000000ff	
#define  MVPCONF0_PTC_SHIFT		 0	
#define MVPCONF0_PVPE		0x00003c00	
#define  MVPCONF0_PVPE_SHIFT		10	
#define MVPCONF0_TCA		0x00008000	
#define MVPCONF0_PTLBE		0x03ff0000	
#define  MVPCONF0_PTLBE_SHIFT		16
#define MVPCONF0_TLBS		0x20000000	
#define MVPCONF0_M		0x80000000	

/*
 * MIPS32 MVPConf1 Register (CP0 Register 0, Select 3)
 */
#define MVPCONF1_PCP1		0x000000ff	
#define  MVPCONF1_PCP1_SHIFT		 0	
#define MVPCONF1_PCP2		0x0003fc00	
#define  MVPCONF1_PCP2_SHIFT		10	
#define MVPCONF1_PCX		0x0ff00000	
#define  MVPCONF1_PCX_SHIFT		20
#define MVPCONF1_C1F		0x40000000     
#define MVPCONF1_C1M		0x80000000	

/*
 * MIPS32 VPEControl Register (CP0 Register 1, Select 1)
 */
#define VPECONTROL_TARGTC	0x000000ff	
#define  VPECONTROL_TARGTC_SHIFT	 0	
#define VPECONTROL_TARGVPE	0x00003c00	
#define  VPECONTROL_TARGVPE_SHIFT	10	
#define VPECONTROL_TE		0x00008000	
#define VPECONTROL_EXCPT	0x00070000	
#define  VPECONTROL_EXCPT_SHIFT	        16	
#define VPECONTROL_GSI		0x00100000	
#define VPECONTROL_YSI		0x00200000	

/*
 * MIPS32 VPEConf0 Register (CP0 Register 1, Select 2)
 */
#define VPECONF0_VPA		0x00000001
#define VPECONF0_MVP		0x00000002
#define VPECONF0_XTC		0x1fe00000
#define VPECONF0_XTC_SHIFT		21
#define VPECONF0_M		0x80000000	

/*
 * MIPS32 VPEConf1 Register (CP0 Register 1, Select 3)
 */
#define VPECONF1_NCP1		0x000000ff	
#define  VPECONF1_NCP1_SHIFT		 0	
#define VPECONF1_NCP2		0x0003fc00	
#define  VPECONF1_NCP2_SHIFT		10	
#define VPECONF1_NCX		0x0ff00000	
#define  VPECONF1_NCX_SHIFT		20	

/*
 * MIPS32 YQMask Register (CP0 Register 1, Select 4)
 */
#define YQMASK_MASK		0x7fffffff
#define  YQMASK_MASK_SHIFT		 0

/*
 * MIPS32 TCStatus Register (CP0 Register 2, Select 1)
 */
#define TCSTATUS_TASID		0x000000ff
#define  TCSTATUS_TASID_SHIFT	         0
#define TCSTATUS_IXMT		0x00000400
#define TCSTATUS_TKSU		0x00001800
#define  TCSTATUS_TKSU_SHIFT		11
#define TCSTATUS_A		0x00002000
#define TCSTATUS_DA		0x00008000
#define TCSTATUS_IMPL		0x000f0000
#define  TCSTATUS_IMPL_SHIFT		16
#define TCSTATUS_DT		0x00100000
#define TCSTATUS_TDS		0x00200000
#define TCSTATUS_TSST		0x00400000
#define TCSTATUS_RNST		0x01800000
#define  TCSTATUS_RNST_SHIFT		23
#define TCSTATUS_TCU0		0x10000000
#define TCSTATUS_TCU1		0x20000000
#define TCSTATUS_TCU2		0x40000000
#define TCSTATUS_TCU3		0x80000000

/*
 * MIPS32 TCBind Register (CP0 Register 2, Select 2)
 */
#define TCBIND_CURVPE		0x0000000f	
#define  TCBIND_CURVPE_SHIFT		 0	
#define TCBIND_CURTC		0x1fe00000	
#define  TCBIND_CURTC_SHIFT		21

/*
 * MIPS32 TCHalt Register (CP0 Register 2, Select 4)
 */
#define TCHALT_H		0x00000001

/*
 * MIPS32 SRSConf0 Register (CP0 Register 6, Select 1)
 */
#define SRSCONF0_SRS1		0x000003ff
#define  SRSCONF0_SRS1_SHIFT		 0
#define SRSCONF0_SRS2		0x000ffc00
#define  SRSCONF0_SRS2_SHIFT		10
#define SRSCONF0_SRS3		0x3ff00000
#define  SRSCONF0_SRS3_SHIFT		20
#define SRSCONF0_M		0x80000000

/*
 * MIPS32 SRSConf1 Register (CP0 Register 6, Select 2)
 */
#define SRSCONF1_SRS4		0x000003ff
#define  SRSCONF1_SRS4_SHIFT		 0
#define SRSCONF1_SRS5		0x000ffc00
#define  SRSCONF1_SRS5_SHIFT		10
#define SRSCONF1_SRS6		0x3ff00000
#define  SRSCONF1_SRS6_SHIFT		20
#define SRSCONF1_M		0x80000000

/*
 * MIPS32 SRSConf2 Register (CP0 Register 6, Select 3)
 */
#define SRSCONF2_SRS7		0x000003ff
#define  SRSCONF2_SRS7_SHIFT		 0
#define SRSCONF2_SRS8		0x000ffc00
#define  SRSCONF2_SRS8_SHIFT		10
#define SRSCONF2_SRS9		0x3ff00000
#define  SRSCONF2_SRS9_SHIFT		20
#define SRSCONF2_M		0x80000000

/*
 * MIPS32 SRSConf3 Register (CP0 Register 6, Select 4)
 */
#define SRSCONF3_SRS10		0x000003ff
#define  SRSCONF3_SRS10_SHIFT		 0
#define SRSCONF3_SRS11		0x000ffc00
#define  SRSCONF3_SRS11_SHIFT		10
#define SRSCONF3_SRS12		0x3ff00000
#define  SRSCONF3_SRS12_SHIFT		20
#define SRSCONF3_M		0x80000000

/*
 * MIPS32 SRSConf4 Register (CP0 Register 6, Select 5)
 */
#define SRSCONF4_SRS13		0x000003ff
#define  SRSCONF4_SRS13_SHIFT		 0
#define SRSCONF4_SRS14		0x000ffc00
#define  SRSCONF4_SRS14_SHIFT		10
#define SRSCONF4_SRS15		0x3ff00000
#define  SRSCONF4_SRS15_SHIFT		20

/*
 * MIPS32 Config3 Register (CP0 Register 16, Select 3)
 * New fields for MT
 */
#define CFG3_MT			0x00000004

#ifdef __ASSEMBLER__

/* 
 * MT Coprocessor 0 register numbers 
 */
#define C0_MVPCONTROL         $0,1
#define C0_MVPCONF0           $0,2
#define C0_MVPCONF1           $0,3
#define C0_VPECONTROL         $1,1
#define C0_VPECONF0           $1,2
#define C0_VPECONF1           $1,3
#define C0_YQMASK             $1,4
#define C0_VPESCHEDULE        $1,5
#define C0_VPESCHEFBACK       $1,6
#define C0_TCSTATUS           $2,1
#define C0_TCBIND             $2,2
#define C0_TCRESTART          $2,3
#define C0_TCHALT             $2,4
#define C0_TCCONTEXT          $2,5
#define C0_TCSCHEDULE         $2,6
#define C0_TCSCHEFBACK        $2,7
#define C0_SRSCONF0           $6,1
#define C0_SRSCONF1           $6,2
#define C0_SRSCONF2           $6,3
#define C0_SRSCONF3           $6,4
#define C0_SRSCONF4           $6,5

#else

#define mips32_getmvpcontrol()	        _m32c0_mfc0(0,1)
#define mips32_setmvpcontrol(x)	        _m32c0_mtc0(0,1,x)
#define mips32_xchmvpcontrol(x)	        _m32c0_mxc0(0,1,x)

#define mips32_getmvpconf0()	        _m32c0_mfc0(0,2)
#define mips32_setmvpconf0(x)	        _m32c0_mtc0(0,2,x)
#define mips32_xchmvpconf0(x)	        _m32c0_mxc0(0,2,x)

#define mips32_getmvpconf1()	        _m32c0_mfc0(0,3)
#define mips32_setmvpconf1(x)	        _m32c0_mtc0(0,3,x)
#define mips32_xchmvpconf1(x)	        _m32c0_mxc0(0,3,x)

#define mips32_getvpecontrol()	        _m32c0_mfc0(1,1)
#define mips32_setvpecontrol(x)	        _m32c0_mtc0(1,1,x)
#define mips32_xchvpecontrol(x)	        _m32c0_mxc0(1,1,x)

#define mips32_getvpeconf0()	        _m32c0_mfc0(1,2)
#define mips32_setvpeconf0(x)	        _m32c0_mtc0(1,2,x)
#define mips32_xchvpeconf0(x)	        _m32c0_mxc0(1,2,x)

#define mips32_getvpeconf1()	        _m32c0_mfc0(1,3)
#define mips32_setvpeconf1(x)	        _m32c0_mtc0(1,3,x)
#define mips32_xchvpeconf1(x)	        _m32c0_mxc0(1,3,x)

#define mips32_getyqmask()	        _m32c0_mfc0(1,4)
#define mips32_setyqmask(x)	        _m32c0_mtc0(1,4,x)
#define mips32_xchyqmask(x)	        _m32c0_mxc0(1,4,x)

#define mips32_getvpeschedule()	        _m32c0_mfc0(1,5)
#define mips32_setvpeschedule(x)	_m32c0_mtc0(1,5,x)
#define mips32_xchvpeschedule(x)	_m32c0_mxc0(1,5,x)

#define mips32_getvpeschefback()        _m32c0_mfc0(1,6)
#define mips32_setvpeschefback(x)       _m32c0_mtc0(1,6,x)
#define mips32_xchvpeschefback(x)       _m32c0_mxc0(1,6,x)

#define mips32_gettcstatus()	        _m32c0_mfc0(2,1)
#define mips32_settcstatus(x)	        _m32c0_mtc0(2,1,x)
#define mips32_xchtcstatus(x)	        _m32c0_mxc0(2,1,x)

#define mips32_gettcbind()	        _m32c0_mfc0(2,2)
#define mips32_settcbind(x)	        _m32c0_mtc0(2,2,x)
#define mips32_xchtcbind(x)	        _m32c0_mxc0(2,2,x)

#define mips32_gettcrestart()	        _m32c0_mfc0(2,3)
#define mips32_settcrestart(x)	        _m32c0_mtc0(2,3,x)
#define mips32_xchtcrestart(x)	        _m32c0_mxc0(2,3,x)

#define mips32_gettchalt()	        _m32c0_mfc0(2,4)
#define mips32_settchalt(x)	        _m32c0_mtc0(2,4,x)
#define mips32_xchtchalt(x)	        _m32c0_mxc0(2,4,x)

#define mips32_gettccontext()	        _m32c0_mfc0(2,5)
#define mips32_settccontext(x)	        _m32c0_mtc0(2,5,x)
#define mips32_xchtccontext(x)	        _m32c0_mxc0(2,5,x)

#define mips32_gettcschedule()	        _m32c0_mfc0(2,6)
#define mips32_settcschedule(x)	        _m32c0_mtc0(2,6,x)
#define mips32_xchtcschedule(x)	        _m32c0_mxc0(2,6,x)

#define mips32_gettcschefback()	        _m32c0_mfc0(2,7)
#define mips32_settcschefback(x)        _m32c0_mtc0(2,7,x)
#define mips32_xchtcschefback(x)        _m32c0_mxc0(2,7,x)

#define mips32_getsrsconf0()	        _m32c0_mfc0(6,1)
#define mips32_setsrsconf0(x)	        _m32c0_mtc0(6,1,x)
#define mips32_xchsrsconf0(x)	        _m32c0_mxc0(6,1,x)

#define mips32_getsrsconf1()	        _m32c0_mfc0(6,2)
#define mips32_setsrsconf1(x)	        _m32c0_mtc0(6,2,x)
#define mips32_xchsrsconf1(x)	        _m32c0_mxc0(6,2,x)

#define mips32_getsrsconf2()	        _m32c0_mfc0(6,3)
#define mips32_setsrsconf2(x)	        _m32c0_mtc0(6,3,x)
#define mips32_xchsrsconf2(x)	        _m32c0_mxc0(6,3,x)

#define mips32_getsrsconf3()	        _m32c0_mfc0(6,4)
#define mips32_setsrsconf3(x)	        _m32c0_mtc0(6,4,x)
#define mips32_xchsrsconf3(x)	        _m32c0_mxc0(6,4,x)

#define mips32_getsrsconf4()	        _m32c0_mfc0(6,5)
#define mips32_setsrsconf4(x)	        _m32c0_mtc0(6,5,x)
#define mips32_xchsrsconf4(x)	        _m32c0_mxc0(6,5,x)

#if !__mips16
/* Access to other VPE/TC registers */

/* move from gpr */
#define _m32c0_mftgpr(rt) \
__extension__ ({ \
	unsigned long __res; \
	__asm__ __volatile__( \
	"%[mftgpr\t%0,$" #rt "%]" \
		: "=d" (__res)); \
	__res; \
})

/* move to gpr */
#define _m32c0_mttgpr(rd,v) \
do { \
	__asm__ __volatile__( \
		"%[mttgpr\t%z0,$" #rd "%]" \
		: : "dJ" (v)); \
} while (0)

/* move from cp0 */
#define _m32c0_mftc0(rt,sel) \
__extension__ ({ \
	unsigned long  __res; \
	__asm__ __volatile__( \
		"mftc0\t%0,$" #rt "," #sel \
		: "=d" (__res)); \
	__res; \
})

/* move to cp0 */
#define _m32c0_mttc0(rd,sel,v) \
do { \
	__asm__ __volatile__( \
		"%(mttc0\t %z0,$" #rd "," #sel "; ehb%)" \
		: : "dJ" (v)); \
} while (0)
#endif /* ! __mips16 */

/*
 * targeted VPE register macros
 */
#define mips32_mt_settarget(tc) \
	mips32_setvpecontrol ( \
		(mips32_getvpecontrol () & ~(VPECONTROL_TARGTC)) \
		| ((tc) << VPECONTROL_TARGTC_SHIFT))

/*
 * Before using any mips32_mt_ macros you should ensure the
 * destination VPE and TC are set with a call to mips32_mt_settarget()
 */

/*
 * Non-MT CP0 registers
 */
#define mips32_mt_getc0status()		_m32c0_mftc0(12, 0)
#define mips32_mt_setc0status(val)	_m32c0_mttc0(12, 0, val)
#define mips32_mt_getc0cause()		_m32c0_mftc0(13, 0)
#define mips32_mt_setc0cause(val)	_m32c0_mttc0(13, 0, val)
#define mips32_mt_getc0config()		_m32c0_mftc0(16, 0)
#define mips32_mt_setc0config(val)	_m32c0_mttc0(16, 0, val)
#define mips32_mt_getc0config1()	_m32c0_mftc0(16, 1)
#define mips32_mt_setc0config1(val) 	_m32c0_mttc0(16, 1, val)
#define mips32_mt_getc0ebase()		_m32c0_mftc0(15, 1)
#define mips32_mt_setc0ebase(val)	_m32c0_mttc0(15, 1, val)

/*
 * Non-MT GPR registers
 */
#define mips32_mt_getsp()			_m32c0_mftgpr(29)
#define mips32_mt_setsp(val)		_m32c0_mttgpr(29, val)
#define mips32_mt_getgp()			_m32c0_mftgpr(28)
#define mips32_mt_setgp(val)		_m32c0_mttgpr(28, val)
#define mips32_mt_sett9(val)		_m32c0_mttgpr(25, val)

/*
 * VPE
 */
#define mips32_mt_getvpecontrol()		_m32c0_mftc0(1, 1)
#define mips32_mt_setvpecontrol(val)	_m32c0_mttc0(1, 1, val)
#define mips32_mt_getvpeconf0()			_m32c0_mftc0(1, 2)
#define mips32_mt_setvpeconf0(val)		_m32c0_mttc0(1, 2, val)

/*
 * TC
 */
#define mips32_mt_gettcstatus() 	_m32c0_mftc0(2, 1)
#define mips32_mt_settcstatus(val)	_m32c0_mttc0(2, 1, val)
#define mips32_mt_gettcbind()		_m32c0_mftc0(2, 2)
#define mips32_mt_settcbind(val)	_m32c0_mttc0(2, 2, val)
#define mips32_mt_gettcrestart()	_m32c0_mftc0(2, 3)
#define mips32_mt_settcrestart(val)	_m32c0_mttc0(2, 3, val)
#define mips32_mt_gettchalt()		_m32c0_mftc0(2, 4)
#define mips32_mt_settchalt(val)	_m32c0_mttc0(2, 4, val)
#define mips32_mt_gettccontext()	_m32c0_mftc0(2, 5)
#define mips32_mt_settccontext(val)	_m32c0_mttc0(2, 5, val)


/* 
 * MT Intrinsics
 */
#define mips_mt_fork(a, pv, cv)					\
__extension__ ({						\
    void * __a = (a);						\
    unsigned int __cv = (cv);					\
    unsigned int __res = (pv); 					\
    __asm__ __volatile ("fork %0,%1,%z2"			\
			: "+d" (__res)				\
			: "d" (__a), "dJ" (__cv));		\
    __res; 							\
})

#define mips_mt_yield(yq)					\
__extension__ ({						\
    unsigned int __yq = (yq);					\
    unsigned int __res; 					\
    __asm__ __volatile ("yield %0,%z1"				\
			: "=d" (__res)				\
			: "dJ" (__yq));				\
    __res; 							\
})

#define mips_mt_dmt() 						\
__extension__ ({						\
    unsigned int __res; 					\
    __asm__ __volatile ("dmt %0; ehb"				\
			: "=d" (__res));			\
    __res & VPECONTROL_TE;					\
})

#define mips_mt_emt() 						\
__extension__ ({						\
    unsigned int __res; 					\
    __asm__ __volatile ("emt %0; ehb"				\
			: "=d" (__res));			\
    __res & VPECONTROL_TE;					\
})

#define mips_mt_dvpe() 						\
__extension__ ({						\
    unsigned int __res; 					\
    __asm__ __volatile ("dvpe %0; ehb"				\
			: "=d" (__res));			\
    __res & MVPCONTROL_EVP;					\
})

#define mips_mt_evpe() 						\
__extension__ ({						\ 
    unsigned int __res; 					\
    __asm__ __volatile ("evpe %0; ehb"				\
			: "=d" (__res));			\
    __res & MVPCONTROL_EVP;					\
})

#define mips32_mt_gettcschedule()          _m32c0_mftc0(2,6)
#define mips32_mt_settcschedule(val)         _m32c0_mttc0(2,6,val)


#endif /* __ASSEMBLER__ */

#endif /* _MIPS_MT_H_ */
