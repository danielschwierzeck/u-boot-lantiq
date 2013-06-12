/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/io.h>

#define LTQ_CGU_SYS_DDR_MASK		0x0003
#define LTQ_CGU_SYS_DDR_SHIFT		0
#define LTQ_CGU_SYS_CPU0_MASK		0x000C
#define LTQ_CGU_SYS_CPU0_SHIFT		2
#define LTQ_CGU_SYS_FPI_MASK		0x0040
#define LTQ_CGU_SYS_FPI_SHIFT		6

struct ltq_cgu_regs {
	u32	rsvd0;
	u32	pll0_cfg;	/* PLL0 config */
	u32	pll1_cfg;	/* PLL1 config */
	u32	pll2_cfg;	/* PLL2 config */
	u32	sys;		/* System clock */
	u32	update;		/* CGU update control */
	u32	if_clk;		/* Interface clock */
	u32	osc_con;	/* Update OSC Control */
	u32	smd;		/* SDRAM Memory Control */
	u32	rsvd1[3];
	u32	pcm_cr;		/* PCM control */
	u32	pci_cr;		/* PCI clock control */
};

static struct ltq_cgu_regs *ltq_cgu_regs =
	(struct ltq_cgu_regs *) CKSEG1ADDR(LTQ_CGU_BASE);

static inline u32 ltq_cgu_sys_readl(u32 mask, u32 shift)
{
	return (ltq_readl(&ltq_cgu_regs->sys) & mask) >> shift;
}

unsigned long ltq_get_io_region_clock(void)
{
	u32 ddr_sel;
	unsigned long clk;

	ddr_sel = ltq_cgu_sys_readl(LTQ_CGU_SYS_DDR_MASK,
					LTQ_CGU_SYS_DDR_SHIFT);

	switch (ddr_sel) {
	case 0:
		clk = CLOCK_166_MHZ;
		break;
	case 1:
		clk = CLOCK_133_MHZ;
		break;
	case 2:
		clk = CLOCK_111_MHZ;
		break;
	case 3:
		clk = CLOCK_83_MHZ;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_cpu_clock(void)
{
	u32 cpu0_sel;
	unsigned long clk;

	cpu0_sel = ltq_cgu_sys_readl(LTQ_CGU_SYS_CPU0_MASK,
					LTQ_CGU_SYS_CPU0_SHIFT);

	switch (cpu0_sel) {
		/* Same as PLL0 output (333,33 MHz) */
	case 0:
		clk = CLOCK_333_MHZ;
		break;
		/* 1/1 fixed ratio to DDR clock */
	case 1:
		clk = ltq_get_io_region_clock();
		break;
		/* 1/2 fixed ratio to DDR clock */
	case 2:
		clk = ltq_get_io_region_clock() << 1;
		break;
	default:
		clk = 0;
		break;
	}

	return clk;
}

unsigned long ltq_get_bus_clock(void)
{
	u32 fpi_sel;
	unsigned long clk;

	fpi_sel = ltq_cgu_sys_readl(LTQ_CGU_SYS_FPI_MASK,
					LTQ_CGU_SYS_FPI_SHIFT);

	if (fpi_sel)
		/* Half the DDR clock */
		clk = ltq_get_io_region_clock() >> 1;
	else
		/* Same as DDR clock */
		clk = ltq_get_io_region_clock();

	return clk;
}
