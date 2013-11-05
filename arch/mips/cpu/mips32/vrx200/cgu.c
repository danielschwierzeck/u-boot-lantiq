/*
 * Copyright (C) 2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/arch/gphy.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/io.h>

#define LTQ_CGU_PLL1_PLLN_SHIFT		6
#define LTQ_CGU_PLL1_PLLN_MASK		(0x3F << LTQ_CGU_PLL1_PLLN_SHIFT)
#define LTQ_CGU_PLL1_PLLM_SHIFT		2
#define LTQ_CGU_PLL1_PLLM_MASK		(0xF << LTQ_CGU_PLL1_PLLM_SHIFT)
#define LTQ_CGU_PLL1_PLLL		(1 << 1)
#define LTQ_CGU_PLL1_PLL_EN		1

#define LTQ_CGU_SYS_OCP_SHIFT		0
#define LTQ_CGU_SYS_OCP_MASK		(0x3 << LTQ_CGU_SYS_OCP_SHIFT)
#define LTQ_CGU_SYS_CPU_SHIFT		4
#define LTQ_CGU_SYS_CPU_MASK		(0xF << LTQ_CGU_SYS_CPU_SHIFT)

#define LTQ_CGU_UPDATE			1

#define LTQ_CGU_IFCLK_GPHY_SEL_SHIFT	2
#define LTQ_CGU_IFCLK_GPHY_SEL_MASK	(0x7 << LTQ_CGU_IFCLK_GPHY_SEL_SHIFT)

struct ltq_cgu_regs {
	u32	rsvd0;
	u32	pll0_cfg;	/* PLL0 config */
	u32	pll1_cfg;	/* PLL1 config */
	u32	sys;		/* System clock */
	u32	clk_fsr;	/* Clock frequency select */
	u32	clk_gsr;	/* Clock gating status */
	u32	clk_gcr0;	/* Clock gating control 0 */
	u32	clk_gcr1;	/* Clock gating control 1 */
	u32	update;		/* CGU update control */
	u32	if_clk;		/* Interface clock */
	u32	ddr;		/* DDR memory control */
	u32	ct1_sr;		/* CT status 1 */
	u32	ct_kval;	/* CT K value */
	u32	pcm_cr;		/* PCM control */
	u32	pci_cr;		/* PCI clock control */
	u32	rsvd1;
	u32	gphy1_cfg;	/* GPHY1 config */
	u32	gphy0_cfg;	/* GPHY0 config */
	u32	rsvd2[6];
	u32	pll2_cfg;	/* PLL2 config */
};

static struct ltq_cgu_regs *ltq_cgu_regs =
	(struct ltq_cgu_regs *) CKSEG1ADDR(LTQ_CGU_BASE);

static inline u32 ltq_cgu_sys_readl(u32 mask, u32 shift)
{
	return (ltq_readl(&ltq_cgu_regs->sys) & mask) >> shift;
}

unsigned long ltq_get_io_region_clock(void)
{
	unsigned int ocp_sel;
	unsigned long clk, cpu_clk;

	cpu_clk = ltq_get_cpu_clock();

	ocp_sel = ltq_cgu_sys_readl(LTQ_CGU_SYS_OCP_MASK,
			LTQ_CGU_SYS_OCP_SHIFT);

	switch (ocp_sel) {
	case 0:
		/* OCP ratio 1 */
		clk = cpu_clk;
		break;
	case 2:
		/* OCP ratio 2 */
		clk = cpu_clk / 2;
		break;
	case 3:
		/* OCP ratio 2.5 */
		clk = (cpu_clk * 2) / 5;
		break;
	case 4:
		/* OCP ratio 3 */
		clk = cpu_clk / 3;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_cpu_clock(void)
{
	unsigned int cpu_sel;
	unsigned long clk;

	cpu_sel = ltq_cgu_sys_readl(LTQ_CGU_SYS_CPU_MASK,
			LTQ_CGU_SYS_CPU_SHIFT);

	switch (cpu_sel) {
	case 0:
		clk = CLOCK_600_MHZ;
		break;
	case 1:
		clk = CLOCK_500_MHZ;
		break;
	case 2:
		clk = CLOCK_393_MHZ;
		break;
	case 3:
		clk = CLOCK_333_MHZ;
		break;
	case 5:
	case 6:
		clk = CLOCK_197_MHZ;
		break;
	case 7:
		clk = CLOCK_166_MHZ;
		break;
	case 4:
	case 8:
	case 9:
		clk = CLOCK_125_MHZ;
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
	ltq_clrbits(&ltq_cgu_regs->if_clk, LTQ_CGU_IFCLK_GPHY_SEL_MASK);
	ltq_setbits(&ltq_cgu_regs->if_clk, clk << LTQ_CGU_IFCLK_GPHY_SEL_SHIFT);
}

static inline int ltq_cgu_pll1_locked(void)
{
	u32 pll1_cfg = ltq_readl(&ltq_cgu_regs->pll1_cfg);

	return pll1_cfg & LTQ_CGU_PLL1_PLLL;
}

static inline void ltq_cgu_pll1_restart(unsigned m, unsigned n)
{
	u32 pll1_cfg;

	ltq_clrbits(&ltq_cgu_regs->pll1_cfg, LTQ_CGU_PLL1_PLL_EN);
	ltq_setbits(&ltq_cgu_regs->update, LTQ_CGU_UPDATE);

	pll1_cfg = ltq_readl(&ltq_cgu_regs->pll1_cfg);
	pll1_cfg &= ~(LTQ_CGU_PLL1_PLLN_MASK | LTQ_CGU_PLL1_PLLM_MASK);
	pll1_cfg |= n << LTQ_CGU_PLL1_PLLN_SHIFT;
	pll1_cfg |= m << LTQ_CGU_PLL1_PLLM_SHIFT;
	pll1_cfg |= LTQ_CGU_PLL1_PLL_EN;
	ltq_writel(&ltq_cgu_regs->pll1_cfg, pll1_cfg);
	ltq_setbits(&ltq_cgu_regs->update, LTQ_CGU_UPDATE);

	__udelay(1000);
}

/*
 * From chapter 9 in errata sheet:
 *
 * Under certain condition, the PLL1 may failed to enter into lock
 * status by hardware default N, M setting.
 *
 * Since system always starts from PLL0, the system software can run
 * and re-program the PLL1 settings.
 */
static void ltq_cgu_pll1_init(void)
{
	unsigned i;
	const unsigned pll1_m[] = { 1, 2, 3, 4 };
	const unsigned pll1_n[] = { 21, 32, 43, 54 };

	/* Check if PLL1 has locked with hardware default settings */
	if (ltq_cgu_pll1_locked())
		return;

	for (i = 0; i < 4; i++) {
		ltq_cgu_pll1_restart(pll1_m[i], pll1_n[i]);

		if (ltq_cgu_pll1_locked())
			goto done;
	}

done:
	/* Restart with hardware default values M=5, N=64 */
	ltq_cgu_pll1_restart(5, 64);
}

void ltq_pll_init(void)
{
	ltq_cgu_pll1_init();
}
