/*
 * Copyright (C) 2010 Lantiq Deutschland GmbH
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
#define LTQ_RCU_RST_REQ			0x0010	/* Reset request */
#define LTQ_RCU_RST_REQ_VALUE		((1 << 14) | (1 << 1))

/* CGU module register */
#define LTQ_CGU_PLL0_CFG		0x0004	/* PLL0 config */
#define LTQ_CGU_PLL1_CFG		0x0008	/* PLL1 config */
#define LTQ_CGU_PLL2_CFG		0x0060	/* PLL2 config */
#define LTQ_CGU_SYS			0x000C	/* System clock */
#define LTQ_CGU_CLK_FSR			0x0010	/* Clock frequency select */
#define LTQ_CGU_UPDATE			0x0020	/* Clock update control */

/* Valid SYS.CPU values */
#define LTQ_CGU_SYS_CPU_SHIFT		4
#define LTQ_CGU_SYS_CPU_600_MHZ		0x0
#define LTQ_CGU_SYS_CPU_500_MHZ		0x1
#define LTQ_CGU_SYS_CPU_393_MHZ		0x2
#define LTQ_CGU_SYS_CPU_333_MHZ		0x3
#define LTQ_CGU_SYS_CPU_197_MHZ		0x5
#define LTQ_CGU_SYS_CPU_166_MHZ		0x7
#define LTQ_CGU_SYS_CPU_125_MHZ		0x9

/* Valid SYS.OCP values */
#define LTQ_CGU_SYS_OCP_SHIFT		0
#define LTQ_CGU_SYS_OCP_1		0x0
#define LTQ_CGU_SYS_OCP_2		0x2
#define LTQ_CGU_SYS_OCP_2_5		0x3
#define LTQ_CGU_SYS_OCP_3		0x4

/* Valid CLK_FSR.ETH values */
#define LTQ_CGU_CLK_FSR_ETH_SHIFT	24
#define LTQ_CGU_CLK_FSR_ETH_50_MHZ	0x0
#define LTQ_CGU_CLK_FSR_ETH_25_MHZ	0x1
#define LTQ_CGU_CLK_FSR_ETH_2_5_MHZ	0x2
#define LTQ_CGU_CLK_FSR_ETH_125_MHZ	0x3

/* Valid CLK_FSR.PPE values */
#define LTQ_CGU_CLK_FSR_PPE_SHIFT	16
#define LTQ_CGU_CLK_FSR_PPE_500_MHZ	0x0	/* Overclock frequency */
#define LTQ_CGU_CLK_FSR_PPE_450_MHZ	0x1	/* High frequency */
#define LTQ_CGU_CLK_FSR_PPE_400_MHZ	0x2	/* Low frequency */

#if (CONFIG_SYS_CLOCK_MODE == LTQ_CLK_CPU_500_DDR_250)
#define LTQ_CGU_SYS_CPU_CONFIG		LTQ_CGU_SYS_CPU_500_MHZ
#define LTQ_CGU_SYS_OCP_CONFIG		LTQ_CGU_SYS_OCP_2
#define LTQ_CGU_CLK_FSR_ETH_CONFIG	LTQ_CGU_CLK_FSR_ETH_125_MHZ
#define LTQ_CGU_CLK_FSR_PPE_CONFIG	LTQ_CGU_CLK_FSR_PPE_450_MHZ
#else
#error "Invalid system clock configuration!"
#endif

/* Build register values */
#define LTQ_CGU_SYS_VALUE	((LTQ_CGU_SYS_CPU_CONFIG << \
					LTQ_CGU_SYS_CPU_SHIFT) | \
					LTQ_CGU_SYS_OCP_CONFIG)

#define LTQ_CGU_CLK_FSR_VALUE	((LTQ_CGU_CLK_FSR_ETH_CONFIG << \
					LTQ_CGU_CLK_FSR_ETH_SHIFT) | \
				(LTQ_CGU_CLK_FSR_PPE_CONFIG << \
					LTQ_CGU_CLK_FSR_PPE_SHIFT))

	.set noreorder

LEAF(ltq_cgu_init)
	/* Load current CGU register values */
	li	t0, (LTQ_CGU_BASE | KSEG1)
	lw	t1, LTQ_CGU_SYS(t0)
	lw	t2, LTQ_CGU_CLK_FSR(t0)

	/* Load target CGU register values */
	li	t3, LTQ_CGU_SYS_VALUE
	li	t4, LTQ_CGU_CLK_FSR_VALUE

	/* Only update registers if values differ */
	bne	t1, t3, update
	 nop
	beq	t2, t4, finished
	 nop

update:
	/* Store target register values */
	sw	t3, LTQ_CGU_SYS(t0)
	sw	t4, LTQ_CGU_CLK_FSR(t0)

	/* Perform software reset to activate new clock config */
#if 0
	li	t0, (LTQ_RCU_BASE | KSEG1)
	lw	t1, LTQ_RCU_RST_REQ(t0)
	or	t1, LTQ_RCU_RST_REQ_VALUE
	sw	t1, LTQ_RCU_RST_REQ(t0)
#else
	li	t1, 1
	sw	t1, LTQ_CGU_UPDATE(t0)
#endif

#if 0
wait_reset:
	b	wait_reset
	 nop
#endif

finished:
	jr	ra
	 nop

	END(ltq_cgu_init)
