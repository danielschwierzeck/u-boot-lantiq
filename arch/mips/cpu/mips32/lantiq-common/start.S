/*
 * Copyright (C) 2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <asm/regdef.h>
#include <asm/mipsregs.h>

#define S_PRIdCoID	16		/* Company ID (R) */
#define M_PRIdCoID	(0xff << S_PRIdCoID)
#define S_PRIdImp	8		/* Implementation ID (R) */
#define M_PRIdImp	(0xff << S_PRIdImp)

#define K_CacheAttrCWTnWA	0	/* Cacheable, write-thru, no write allocate */
#define K_CacheAttrCWTWA	1	/* Cacheable, write-thru, write allocate */
#define K_CacheAttrU		2	/* Uncached */
#define K_CacheAttrC		3	/* Cacheable */
#define K_CacheAttrCN		3	/* Cacheable, non-coherent */
#define K_CacheAttrCCE		4	/* Cacheable, coherent, exclusive */
#define K_CacheAttrCCS		5	/* Cacheable, coherent, shared */
#define K_CacheAttrCCU		6	/* Cacheable, coherent, update */
#define K_CacheAttrUA		7	/* Uncached accelerated */

#define S_ConfigK23		28	/* Kseg2/3 coherency algorithm (FM MMU only) (R/W) */
#define M_ConfigK23		(0x7 << S_ConfigK23)
#define W_ConfigK23		3
#define S_ConfigKU		25	/* Kuseg coherency algorithm (FM MMU only) (R/W) */
#define M_ConfigKU		(0x7 << S_ConfigKU)
#define W_ConfigKU		3

#define S_ConfigMM		18	/* Merge mode (implementation specific) */
#define M_ConfigMM		(0x1 << S_ConfigMM)

#define S_StatusBEV		22	/* Enable Boot Exception Vectors (R/W) */
#define M_StatusBEV		(0x1 << S_StatusBEV)

#define S_StatusFR		26	/* Enable 64-bit FPRs (R/W) */
#define M_StatusFR		(0x1 << S_StatusFR)

#define S_ConfigK0		0	/* Kseg0 coherency algorithm (R/W) */
#define M_ConfigK0		(0x7 << S_ConfigK0)

#define CONFIG0_MIPS32_64_MSK	0x8000ffff
#define STATUS_MIPS32_64_MSK	0xfffcffff

#define STATUS_MIPS24K		0
#define CONFIG0_MIPS24K		((K_CacheAttrCN << S_ConfigK23) |\
				(K_CacheAttrCN << S_ConfigKU)  |\
				(M_ConfigMM))

#define STATUS_MIPS34K		0
#define CONFIG0_MIPS34K		((K_CacheAttrCN << S_ConfigK23) |\
				(K_CacheAttrCN << S_ConfigKU) |\
				(M_ConfigMM))

#define STATUS_MIPS32_64	(M_StatusBEV | M_StatusFR)
#define CONFIG0_MIPS32_64	(K_CacheAttrCN << S_ConfigK0)

#ifdef CONFIG_SOC_XWAY_DANUBE
#define CONFIG0_LANTIQ		(CONFIG0_MIPS24K | CONFIG0_MIPS32_64)
#define STATUS_LANTIQ		(STATUS_MIPS24K | STATUS_MIPS32_64)
#endif

#ifdef CONFIG_SOC_XWAY_ARX100
#define CONFIG0_LANTIQ		(CONFIG0_MIPS34K | CONFIG0_MIPS32_64)
#define STATUS_LANTIQ		(STATUS_MIPS34K | STATUS_MIPS32_64)
#endif

#ifdef CONFIG_SOC_XWAY_VRX200
#define CONFIG0_LANTIQ		(CONFIG0_MIPS34K | CONFIG0_MIPS32_64)
#define STATUS_LANTIQ		(STATUS_MIPS34K | STATUS_MIPS32_64)
#endif


	.set noreorder

	.globl _start
	.text
_start:
	/* Entry point */
	b	main
	 nop

	/* Lantiq SoC Boot config word */
	.org	0x10
#ifdef CONFIG_SYS_XWAY_EBU_BOOTCFG
	.word	CONFIG_SYS_XWAY_EBU_BOOTCFG
#else
	.word	0
#endif
	.word	0

	.align	4
main:

	/* Init Timer */
	mtc0	zero, CP0_COUNT
	mtc0	zero, CP0_COMPARE

	/* Setup MIPS24K/MIPS34K specifics (implementation dependent fields) */
	mfc0	t0, CP0_CONFIG
	li	t1, CONFIG0_MIPS32_64_MSK
	and	t0, t1
	li	t1, CONFIG0_LANTIQ
	or	t0, t1
	mtc0	t0, CP0_CONFIG

	mfc0	t0, CP0_STATUS
	li	t1, STATUS_MIPS32_64_MSK
	and	t0, t1
	li	t1, STATUS_LANTIQ
	or	t0, t1
	mtc0	t0, CP0_STATUS

	/* Initialize CGU */
	la	t9, ltq_cgu_init
	jalr	t9
	 nop

	/* Initialize memory controller */
	la	t9, ltq_mem_init
	jalr	t9
	 nop

	/* Initialize caches... */
	la	t9, mips_cache_reset
	jalr	t9
	 nop

	/* Clear BSS */
	la	t1, __bss_start
	la	t2, __bss_end
	sub	t1, 4
1:
	addi	t1, 4
	bltl	t1, t2, 1b
	 sw	zero, 0(t1)

	/* Setup stack pointer and force alignment on a 16 byte boundary */
	li	t0, (CONFIG_SPL_STACK_BASE & ~0xF)
	la	sp, 0(t0)

	la	t9, spl_lantiq_init
	jr	t9
	 nop
