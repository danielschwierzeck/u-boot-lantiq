/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/io.h>

#define CGU_SYS_DDR_SEL		(1 << 0)
#define CGU_SYS_CPU_SEL		(1 << 2)
#define CGU_SYS_SYS_SHIFT	3
#define CGU_SYS_SYS_MASK	(0x3 << CGU_SYS_SYS_SHIFT)
#define CGU_SYS_FPI_SEL		(1 << 6)
#define CGU_SYS_PPE_SEL		(1 << 7)

struct ltq_cgu_regs {
	u32	rsvd0;
	__be32	pll0_cfg;	/* PLL0 config */
	__be32	pll1_cfg;	/* PLL1 config */
	u32	rsvd2;
	__be32	sys;		/* System clock */
	__be32	update;		/* CGU update control */
	__be32	if_clk;		/* Interface clock */
	u32	rsvd3;
	__be32	smd;		/* SDRAM Memory Control */
	u32	rsvd4;
	__be32	ct1_sr;		/* CT status 1 */
	__be32	ct_kval;	/* CT K value */
	__be32	pcm_cr;		/* PCM control */
};

static struct ltq_cgu_regs *ltq_cgu_regs =
	(struct ltq_cgu_regs *) CKSEG1ADDR(LTQ_CGU_BASE);

static inline u32 ltq_cgu_sys_readl(u32 mask, u32 shift)
{
	return (ltq_readl(&ltq_cgu_regs->sys) & mask) >> shift;
}

static unsigned long ltq_get_system_clock(void)
{
	u32 sys_sel;
	unsigned long clk;

	sys_sel = ltq_cgu_sys_readl(CGU_SYS_SYS_MASK, CGU_SYS_SYS_SHIFT);

	switch (sys_sel) {
	case 0:
		clk = CLOCK_333_MHZ;
		break;
	case 2:
		clk = CLOCK_393_MHZ;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_io_region_clock(void)
{
	u32 ddr_sel;
	unsigned long clk;

	ddr_sel = ltq_cgu_sys_readl(1, CGU_SYS_DDR_SEL);

	if (ddr_sel)
		clk = ltq_get_system_clock() / 3;
	else
		clk = ltq_get_system_clock() / 2;

	return clk;
}

unsigned long ltq_get_cpu_clock(void)
{
	u32 cpu_sel;
	unsigned long clk;

	cpu_sel = ltq_cgu_sys_readl(1, CGU_SYS_CPU_SEL);

	if (cpu_sel)
		clk = ltq_get_io_region_clock();
	else
		clk = ltq_get_system_clock();

	return clk;
}

unsigned long ltq_get_bus_clock(void)
{
	u32 fpi_sel;
	unsigned long clk;

	fpi_sel = ltq_cgu_sys_readl(1, CGU_SYS_FPI_SEL);

	if (fpi_sel)
		clk = ltq_get_io_region_clock() / 2;
	else
		clk = ltq_get_io_region_clock();

	return clk;
}
