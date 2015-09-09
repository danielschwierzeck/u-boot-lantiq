/*
 * Copyright (C) 2014 Lantiq Deutschland GmbH
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/arch/gphy.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/reset.h>

#define CGU_SYS_CPU_FS_SHIFT		9
#define CGU_SYS_CPU_FS_MASK		(0x3 << CGU_SYS_CPU_FS_SHIFT)
#define CGU_SYS_CPU_FS_600		(0 << CGU_SYS_CPU_FS_SHIFT)
#define CGU_SYS_CPU_FS_666		(1 << CGU_SYS_CPU_FS_SHIFT)
#define CGU_SYS_CPU_FS_720		(2 << CGU_SYS_CPU_FS_SHIFT)
#define CGU_SYS_U_FREQ			(1 << 7)
#define CGU_SYS_CPU_SHIFT		4
#define CGU_SYS_CPU_MASK		(0x7 << CGU_SYS_CPU_SHIFT)
#define CGU_SYS_CPU_EQUAL_SYSCLK	(0 << CGU_SYS_CPU_SHIFT)
#define CGU_SYS_CPU_HALF_SYSCLK		(1 << CGU_SYS_CPU_SHIFT)
#define CGU_SYS_CPU_QUARTER_SYSCLK	(2 << CGU_SYS_CPU_SHIFT)
#define CGU_SYS_DDR_MASK		0x7
#define CGU_SYS_DDR_HALF_SYSCLK		1
#define CGU_SYS_DDR_QUARTER_SYSCLK	2
#define CGU_SYS_RESERVED		(1 << 8)

#define CGU_CLKFSR_PPE_SHIFT		16
#define CGU_CLKFSR_PPE_250		(0x1 << CGU_CLKFSR_PPE_SHIFT)
#define CGU_CLKFSR_PPE_432		(0x2 << CGU_CLKFSR_PPE_SHIFT)
#define CGU_CLKFSR_PPE_400		(0x4 << CGU_CLKFSR_PPE_SHIFT)

#define CGU_IFCLK_FPI_SEL_SHIFT		25
#define CGU_IFCLK_FPI_SEL_MASK		(0xf << CGU_IFCLK_FPI_SEL_SHIFT)
#define CGU_IFCLK_GPHY_SEL_SHIFT	2
#define CGU_IFCLK_GPHY_SEL_MASK		(0x7 << CGU_IFCLK_GPHY_SEL_SHIFT)

#define CGU_PLL0_FMOD_S0		(1 << 23)
#define CGU_PLL0_FMOD_S1		(1 << 22)
#define CGU_PLL0_PS2_EN			(1 << 21)
#define CGU_PLL0_PS1_EN			(1 << 20)
#define CGU_PLL0_N_SHIFT		6
#define CGU_PLL0_N_MASK			(0xff << CGU_PLL0_N_SHIFT)
#define CGU_PLL0_M_SHIFT		2
#define CGU_PLL0_M_MASK			(0xf << CGU_PLL0_M_SHIFT)
#define CGU_PLL0_LOCK			(1 << 1)
#define CGU_PLL0_EN			(1 << 0)

#define CGU_PLL2_K_SHIFT		20
#define CGU_PLL2_K_MASK			(0xfff << CGU_PLL2_K_SHIFT)
#define CGU_PLL2_N_SHIFT		6
#define CGU_PLL2_N_MASK			(0xff << CGU_PLL2_N_SHIFT)
#define CGU_PLL2_M_SHIFT		2
#define CGU_PLL2_M_MASK			(0xf << CGU_PLL2_M_SHIFT)
#define CGU_PLL2_LOCK			(1 << 1)
#define CGU_PLL2_EN			(1 << 0)

struct ltq_cgu_regs {
	u32	rsvd0;
	u32	pll0_cfg;	/* PLL0 config */
	u32	pll1_cfg;	/* PLL1 config */
	u32	sys;		/* System clock */
	u32	clk_fsr;	/* Clock frequency select */
	u32	clk_gsr0;	/* Clock gating status 0 */
	u32	clk_gcr0_a;	/* Clock gating control 0 A */
	u32	clk_gcr0_b;	/* Clock gating control 0 B */
	u32	update;		/* CGU update control */
	u32	if_clk;		/* Interface clock */
	u32	rsvd1;
	u32	ct1_sr;		/* CT status 1 */
	u32	ct_kval;	/* CT K value */
	u32	pcm_cr;		/* PCM control */
	u32	rsvd2[2];
	u32	ephy1_cfg;	/* EPHY1 config */
	u32	ephy2_cfg;	/* EPHY2 config */
	u32	ephy3_cfg;	/* EPHY3 config */
	u32	ephy0_cfg;	/* EPHY0 config */
	u32	rsvd3[4];
	u32	pll2_cfg;	/* PLL2 config */
};

static struct ltq_cgu_regs *ltq_cgu_regs =
	(struct ltq_cgu_regs *) CKSEG1ADDR(LTQ_CGU_BASE);

static unsigned long ltq_get_sys_clock(void)
{
	unsigned int cpu_fs;
	unsigned long clk;

	cpu_fs = (ltq_readl(&ltq_cgu_regs->sys) & CGU_SYS_CPU_FS_MASK) >>
		CGU_SYS_CPU_FS_SHIFT;

	switch (cpu_fs) {
	case 0:
		clk = CLOCK_600_MHZ;
		break;
	case 1:
		clk = CLOCK_666_MHZ;
		break;
	case 2:
		clk = CLOCK_720_MHZ;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_io_region_clock(void)
{
	unsigned int ddr;
	unsigned long clk, sys_clk;

	ddr = ltq_readl(&ltq_cgu_regs->sys) & CGU_SYS_DDR_MASK;
	sys_clk = ltq_get_sys_clock();

	if (ddr == 2)
		clk = sys_clk / 4;
	else
		clk = sys_clk / 2;

	return clk;
}

unsigned long ltq_get_cpu_clock(void)
{
	unsigned int cpu;
	unsigned long clk, sys_clk;

	cpu = (ltq_readl(&ltq_cgu_regs->sys) & CGU_SYS_CPU_MASK) >>
			CGU_SYS_CPU_SHIFT;
	sys_clk = ltq_get_sys_clock();

	switch (cpu) {
	case 0:
		clk = sys_clk;
		break;
	case 1:
		clk = sys_clk / 2;
		break;
	case 2:
		clk = sys_clk / 4;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_bus_clock(void)
{
	return ltq_get_io_region_clock();
}

void ltq_cgu_gphy_clk_src(enum ltq_gphy_clk clk)
{
	ltq_clrbits(&ltq_cgu_regs->if_clk, CGU_IFCLK_GPHY_SEL_MASK);
	ltq_setbits(&ltq_cgu_regs->if_clk, clk << CGU_IFCLK_GPHY_SEL_SHIFT);
}

void ltq_cgu_init(void)
{
	u32 cgu_sys, pll0_cfg, pll2_cfg;
	bool soft_reset = false;

	pll0_cfg = CGU_PLL0_FMOD_S0 | CGU_PLL0_PS2_EN | CGU_PLL0_PS1_EN |
		177 << CGU_PLL0_N_SHIFT | 2 << CGU_PLL0_M_SHIFT | CGU_PLL0_EN;

	pll2_cfg = 659 << CGU_PLL2_K_SHIFT | 0 << CGU_PLL2_M_SHIFT |
		CGU_PLL2_EN;

	if (ltq_soc_is_grx389_720())
		pll2_cfg |= 9 << CGU_PLL2_N_SHIFT;
	else
		pll2_cfg |= 11 << CGU_PLL2_N_SHIFT;

	if (pll0_cfg != (ltq_readl(&ltq_cgu_regs->pll0_cfg) & ~CGU_PLL0_LOCK)) {
		ltq_writel(&ltq_cgu_regs->pll0_cfg, pll0_cfg);
		soft_reset = true;
	}

	if (pll2_cfg != (ltq_readl(&ltq_cgu_regs->pll2_cfg) & ~CGU_PLL2_LOCK)) {
		ltq_writel(&ltq_cgu_regs->pll2_cfg, pll2_cfg);
		soft_reset = true;
	}

	/* PLL shadow registers are only applied after soft-reset */
	if (soft_reset) {
		ltq_reset_activate(LTQ_RESET_SOFT);
		for (;;)
			;
	}

	if (ltq_soc_is_grx389_720()) {
		cgu_sys = CGU_SYS_RESERVED | CGU_SYS_CPU_FS_720 |
			CGU_SYS_CPU_EQUAL_SYSCLK | CGU_SYS_DDR_HALF_SYSCLK;

		ltq_writel(&ltq_cgu_regs->clk_fsr, CGU_CLKFSR_PPE_400);
	} else {
		cgu_sys = CGU_SYS_RESERVED | CGU_SYS_CPU_FS_600 |
			CGU_SYS_CPU_EQUAL_SYSCLK | CGU_SYS_DDR_HALF_SYSCLK;

		ltq_writel(&ltq_cgu_regs->clk_fsr, CGU_CLKFSR_PPE_432);
	}

	/* CGU.SYS shadow register is applied after setting bit U_FREQ */
	ltq_writel(&ltq_cgu_regs->sys, cgu_sys | CGU_SYS_U_FREQ);

}
