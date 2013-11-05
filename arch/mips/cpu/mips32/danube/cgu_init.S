/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <asm/asm.h>
#include <asm/regdef.h>
#include <asm/addrspace.h>
#include <asm/arch/soc.h>

/* RCU module register */
#define LTQ_RCU_RST_REQ			0x0010
#define LTQ_RCU_RST_STAT		0x0014
#define LTQ_RCU_RST_REQ_VALUE		0x40000008
#define LTQ_RCU_RST_STAT_XTAL_F	0x20000

/* CGU module register */
#define LTQ_CGU_PLL0_CFG		0x0004	/* PLL0 config */
#define LTQ_CGU_PLL1_CFG		0x0008	/* PLL1 config */
#define LTQ_CGU_PLL2_CFG		0x000C	/* PLL2 config */
#define LTQ_CGU_SYS			0x0010	/* System clock */

/* Valid SYS.CPU0/1 values */
#define LTQ_CGU_SYS_CPU0_SHIFT		2
#define LTQ_CGU_SYS_CPU1_SHIFT		4
#define LTQ_CGU_SYS_CPU_PLL0		0x0
#define LTQ_CGU_SYS_CPU_DDR_EQUAL	0x1
#define LTQ_CGU_SYS_CPU_DDR_TWICE	0x2

/* Valid SYS.DDR values */
#define LTQ_CGU_SYS_DDR_SHIFT		0
#define LTQ_CGU_SYS_DDR_167_MHZ	0x0
#define LTQ_CGU_SYS_DDR_133_MHZ	0x1
#define LTQ_CGU_SYS_DDR_111_MHZ	0x2
#define LTQ_CGU_SYS_DDR_83_MHZ		0x3

/* Valid SYS.FPI values */
#define LTQ_CGU_SYS_FPI_SHIFT		6
#define LTQ_CGU_SYS_FPI_DDR_EQUAL	0x0
#define LTQ_CGU_SYS_FPI_DDR_HALF	0x1

/* Valid SYS.PPE values */
#define LTQ_CGU_SYS_PPE_SHIFT		7
#define LTQ_CGU_SYS_PPE_266_MHZ	0x0
#define LTQ_CGU_SYS_PPE_240_MHZ	0x1
#define LTQ_CGU_SYS_PPE_222_MHZ	0x2
#define LTQ_CGU_SYS_PPE_133_MHZ	0x3

#if (CONFIG_SYS_CLOCK_MODE == LTQ_CLK_CPU_333_DDR_167)
#define LTQ_CGU_SYS_CPU_CONFIG		LTQ_CGU_SYS_CPU_DDR_TWICE
#define LTQ_CGU_SYS_DDR_CONFIG		LTQ_CGU_SYS_DDR_167_MHZ
#define LTQ_CGU_SYS_FPI_CONFIG		LTQ_CGU_SYS_FPI_DDR_HALF
#define LTQ_CGU_SYS_PPE_CONFIG		LTQ_CGU_SYS_PPE_266_MHZ
#elif (CONFIG_SYS_CLOCK_MODE == LTQ_CLK_CPU_111_DDR_111)
#define LTQ_CGU_SYS_CPU_CONFIG		LTQ_CGU_SYS_CPU_DDR_EQUAL
#define LTQ_CGU_SYS_DDR_CONFIG		LTQ_CGU_SYS_DDR_111_MHZ
#define LTQ_CGU_SYS_FPI_CONFIG		LTQ_CGU_SYS_FPI_DDR_HALF
#define LTQ_CGU_SYS_PPE_CONFIG		LTQ_CGU_SYS_PPE_133_MHZ
#else
#error "Invalid system clock configuration!"
#endif

/* Build register values */
#define LTQ_CGU_SYS_VALUE	((LTQ_CGU_SYS_PPE_CONFIG << \
					LTQ_CGU_SYS_PPE_SHIFT) | \
				(LTQ_CGU_SYS_FPI_CONFIG << \
					LTQ_CGU_SYS_FPI_SHIFT) | \
				(LTQ_CGU_SYS_CPU_CONFIG << \
					LTQ_CGU_SYS_CPU1_SHIFT) | \
				(LTQ_CGU_SYS_CPU_CONFIG << \
					LTQ_CGU_SYS_CPU0_SHIFT) | \
				LTQ_CGU_SYS_DDR_CONFIG)

/* Reset values for PLL registers for usage with 35.328 MHz crystal */
#define PLL0_35MHZ_CONFIG	0x9D861059
#define PLL1_35MHZ_CONFIG	0x1A260CD9
#define PLL2_35MHZ_CONFIG	0x8000f1e5

/* Reset values for PLL registers for usage with 36 MHz crystal */
#define PLL0_36MHZ_CONFIG	0x1000125D
#define PLL1_36MHZ_CONFIG	0x1B1E0C99
#define PLL2_36MHZ_CONFIG	0x8002f2a1

LEAF(ltq_cgu_init)
	/* Load current CGU register value */
	li	t0, (LTQ_CGU_BASE | KSEG1)
	lw	t1, LTQ_CGU_SYS(t0)

	/* Load target CGU register values */
	li	t3, LTQ_CGU_SYS_VALUE

	/* Only update registers if values differ */
	beq	t1, t3, finished

	/*
	 * Check whether the XTAL_F bit in RST_STAT register is set or not.
	 * This bit is latched in via pin strapping. If bit is set then
	 * clock source is a 36 MHz crystal. Otherwise a 35.328 MHz crystal.
	 */
	 li	t1, (LTQ_RCU_BASE | KSEG1)
	 lw	t2, LTQ_RCU_RST_STAT(t1)
	 and	t2, t2, LTQ_RCU_RST_STAT_XTAL_F
	 beq	t2, LTQ_RCU_RST_STAT_XTAL_F, boot_36mhz

boot_35mhz:
	/* Configure PLL for 35.328 MHz */
	li	t2, PLL0_35MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL0_CFG(t0)
	li	t2, PLL1_35MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL1_CFG(t0)
	li	t2, PLL2_35MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL2_CFG(t0)

	b	do_reset

boot_36mhz:
	/* Configure PLL for 36 MHz */
	li	t2, PLL0_36MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL0_CFG(t0)
	li	t2, PLL1_36MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL1_CFG(t0)
	li	t2, PLL2_36MHZ_CONFIG
	sw	t2, LTQ_CGU_PLL2_CFG(t0)

do_reset:
	/* Store new clock config */
	sw	t3, LTQ_CGU_SYS(t0)

	/* Perform software reset to activate new clock config */
	li	t2, LTQ_RCU_RST_REQ_VALUE
	sw	t2, LTQ_RCU_RST_REQ(t1)

wait_reset:
	b	wait_reset

finished:
	jr	ra

	END(ltq_cgu_init)
