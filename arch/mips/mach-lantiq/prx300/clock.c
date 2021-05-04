/* Copyright (c) 2018, Intel Corporation.
 * PRX300 slim ethernet driver
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <asm/gic.h>
#include <common.h>
#include <lantiq.h>
#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <lantiq.h>

#define BASEDIV		16777216
#define CLOCK_200M      200000000
#define MHZ		1000000
#define PLL0B_CFG1_CLK4 0xF000
#define PLL0A_CFG1_CLK4 0xF000
#define PLL0A_CFG1_CLK3 0x0F00
#define PLL0B_CFG1_CLK3 0x0F00
#define PLL0A_CFG1_CLK0	0x000F
#define PLL2_CFG1_CLK0	0x000F

uint get_sys_clk(void)
{
	return 0;
}

static unsigned long get_pll0_clk(int clka)
{
	int f_osc = 40;
	u32 reg;
	u32 refdiv, fbdiv;

	if (clka) {
		reg = ltq_r32(CGU_MODULE_BASE, PLL0A_CFG2);
		fbdiv = reg & PLL0A_CFG2_FBDIV_MASK;
		refdiv = (reg & PLL0A_CFG2_REFDIV_MASK)
				>> PLL0A_CFG2_REFDIV_POS;
	} else {
		reg = ltq_r32(CGU_MODULE_BASE, PLL0B_CFG2);
		fbdiv = reg & PLL0B_CFG2_FBDIV_MASK;
		refdiv = (reg & PLL0B_CFG2_REFDIV_MASK)
				>> PLL0B_CFG2_REFDIV_POS;
	}

	/* prevent div by zero although this should not happen */
	if (refdiv == 0)
		refdiv = 1;

	return (f_osc * (fbdiv / refdiv));
}

static unsigned long get_pll2_clk(void)
{
	int f_osc = 40;
	u32 reg;
	u32 fbdiv, refdiv, frac;
	u32 var;

	reg = ltq_r32(CGU_MODULE_BASE, PLL2_CFG0);
	frac = (reg & PLL2_CFG0_FRAC_MASK)
			>> PLL2_CFG0_FRAC_POS;
	reg = ltq_r32(CGU_MODULE_BASE, PLL2_CFG2);
	fbdiv = reg & PLL2_CFG2_FBDIV_MASK;
	refdiv = (reg & PLL2_CFG2_REFDIV_MASK) >> PLL2_CFG2_REFDIV_POS;

	/* prevent div by zero although this should not happen */
	if (refdiv == 0)
		refdiv = 1;

	/* round up & non-floating pt calculations */
	var = ((frac * 100 + BASEDIV - 1) / BASEDIV);
	var += (fbdiv * 100);
	var *= f_osc;
	
	return (var / (refdiv * 100));
}

static unsigned long get_pll3_clk(void)
{
	int f_osc = 40;
	u32 reg;
	u32 fbdiv, refdiv;
	u32 var;

	reg = ltq_r32(CGU_MODULE_BASE, PLL3_CFG2);
	fbdiv = reg & PLL3_CFG2_FBDIV_MASK;
	refdiv = (reg & PLL3_CFG2_REFDIV_MASK) >> PLL3_CFG2_REFDIV_POS;

	/* prevent div by zero although this should not happen */
	if (refdiv == 0)
		refdiv = 1;

	var = fbdiv / refdiv;
	var *= f_osc;

	return var / 4;
}

/* Get CPU clk based of freq divisor
 * 0H GNDref clk Output clock is ref clock.
 * 1H DIV2Divide by 2
 * 2H DIV3Divide by 3
 * 3H DIV4Divide by 4
 * 4H DIV5Divide by 5
 * 5H DIV6Divide by 6
 * 6H DIV8Divide by 8
 * 7H DIV10Divide by 10
 * 8H DIV12Divide by 12
 * 9H DIV16Divide by 16
 * AH DIV20Divide by 20
 * BH DIV24Divide by 24
 * CH DIV32Divide by 32
 * DH DIV40Divide by 40
 * EH DIV48Divide by 48
 * FH DIV64Divide by 64
 */

unsigned int get_divisor(u32 clk_div)
{
	unsigned int div = 64;

	if (clk_div < 0x6)
		return (clk_div + 1);
	else if (clk_div < 0x9)
		return (clk_div + (clk_div - 6 + 2));
	else if (clk_div < 0xC)
		return (clk_div + ((clk_div - 9) * 3) + 7);
	else if (clk_div < 0xF)
		return (clk_div + ((clk_div - 12) * 7) + 20);
	else
		return div;
}

uint get_cpu_clk(void)
{
	unsigned long pllclk;
	u32 clk4_div;

	pllclk = get_pll0_clk(1) * MHZ;
	clk4_div = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1) & PLL0A_CFG1_CLK0);

	return (unsigned long)(pllclk / get_divisor(clk4_div));
}

unsigned int get_ddr_clk(void)
{
	u32 pllclk;
	u32 val;
	u32 clk0_div;

	pllclk = get_pll2_clk() * MHZ;
	clk0_div = ltq_r32(CGU_MODULE_BASE, PLL2_CFG1) & PLL2_CFG1_CLK0;

	/* get ctrl clk freq */
	val = pllclk / get_divisor(clk0_div);

	return val;
}

unsigned int get_gphy_clk(void)
{
	u32 pllclk;
	u32 val, postdiv_a, postdiv_b, postdiv_pre0;

	pllclk = get_pll3_clk() * MHZ;
	postdiv_pre0 = ltq_r32(CGU_MODULE_BASE, PLL3_CFG1);
	/* postdiv_pre0 includes a 2.5 divider */
	if (postdiv_pre0 & PLL3_CFG1_POST_DIV0PRE_MASK)
		pllclk = (pllclk / 25) * 10;

	postdiv_a = ltq_r32(CGU_MODULE_BASE, PLL3_CFG1) & PLL3_CFG1_POST_DIV0A_MASK;
	postdiv_b = ltq_r32(CGU_MODULE_BASE, PLL3_CFG1) & PLL3_CFG1_POST_DIV0B_MASK;

	postdiv_b >>= PLL3_CFG1_POST_DIV0B_POS;

	val = pllclk / (postdiv_a + 1) / (postdiv_b + 1);
	return val;
}

unsigned int get_fpi_clk(void)
{
	return CLOCK_200M;
}

void config_qspi_refclk(void)
{
	u32 reg;
	unsigned long pllclk;

	/* disable QSPI clk */
	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_B,
		CGU_CLKGCR1_B_QSPI_MASK);

	/*
	 * set QSPI clk to 400Mhz frequency
	 * depending on the VC0 value
	 * if it is already at that frequency don't reconfig it.
	 */
	reg = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1)
		& PLL0A_CFG1_PLL_CLK3_MASK);
	pllclk = get_pll0_clk(1);
	if (pllclk == 800) {
		if ((reg >> PLL0A_CFG1_PLL_CLK3_POS)
			!= CONST_PLL0A_CFG1_PLL_CLK3_DIV8) {
			reg = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1)
				& ~(PLL0A_CFG1_PLL_CLK3_MASK));
			reg |= (CONST_PLL0A_CFG1_PLL_CLK3_DIV8
				<< PLL0A_CFG1_PLL_CLK3_POS);
			ltq_w32(CGU_MODULE_BASE, PLL0A_CFG1, reg);
		}
	} else if (pllclk == 2400) {
		if ((reg >> PLL0A_CFG1_PLL_CLK3_POS)
			!= CONST_PLL0A_CFG1_PLL_CLK3_DIV24) {
			reg = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1)
				& ~(PLL0A_CFG1_PLL_CLK3_MASK));
			reg |= (CONST_PLL0A_CFG1_PLL_CLK3_DIV24
				<< PLL0A_CFG1_PLL_CLK3_POS);
			ltq_w32(CGU_MODULE_BASE, PLL0A_CFG1, reg);
		}
	} else if (pllclk == 1600) {
		if ((reg >> PLL0A_CFG1_PLL_CLK3_POS)
			!= CONST_PLL0A_CFG1_PLL_CLK3_DIV16) {
			reg = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1)
				& ~(PLL0A_CFG1_PLL_CLK3_MASK));
			reg |= (CONST_PLL0A_CFG1_PLL_CLK3_DIV16
				<< PLL0A_CFG1_PLL_CLK3_POS);
			ltq_w32(CGU_MODULE_BASE, PLL0A_CFG1, reg);
		}
	} else {
		pllclk = pllclk / 100;
		if (reg >> PLL0A_CFG1_PLL_CLK3_POS != pllclk) {
			reg = (ltq_r32(CGU_MODULE_BASE, PLL0A_CFG1)
				& ~(PLL0A_CFG1_PLL_CLK3_MASK));
			reg |= ((pllclk + 1 )<< PLL0A_CFG1_PLL_CLK3_POS);
			ltq_w32(CGU_MODULE_BASE, PLL0A_CFG1, reg);
		}
	}

	/*Enable QSPI clock*/
	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A,
			(ltq_r32(CGU_MODULE_BASE, CGU_CLKGCR1_A)
			| CGU_CLKGCR1_A_QSPI_MASK));

	udelay(400);

}
