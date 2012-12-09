/*
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/pm.h>
#include <asm/arch/soc.h>

#define LTQ_PMU_PWDCR_RESERVED		0xE00C200C

#define LTQ_PMU_PWDCR_SWITCH		(1 << 28)
#define LTQ_PMU_PWDCR_USB1		(1 << 27)
#define LTQ_PMU_PWDCR_USB1_PHY		(1 << 26)
#define LTQ_PMU_PWDCR_TDM		(1 << 25)
#define LTQ_PMU_PWDCR_DDR_MEM		(1 << 24)
#define LTQ_PMU_PWDCR_PPE_DP		(1 << 23)
#define LTQ_PMU_PWDCR_PPE_EMA		(1 << 22)
#define LTQ_PMU_PWDCR_PPE_TC		(1 << 21)
#define LTQ_PMU_PWDCR_DEU		(1 << 20)
#define LTQ_PMU_PWDCR_UART1		(1 << 17)
#define LTQ_PMU_PWDCR_SDIO		(1 << 16)
#define LTQ_PMU_PWDCR_AHB		(1 << 15)
#define LTQ_PMU_PWDCR_FPI0		(1 << 14)
#define LTQ_PMU_PWDCR_GPTC		(1 << 12)
#define LTQ_PMU_PWDCR_LEDC		(1 << 11)
#define LTQ_PMU_PWDCR_EBU		(1 << 10)
#define LTQ_PMU_PWDCR_DSL		(1 << 9)
#define LTQ_PMU_PWDCR_SPI		(1 << 8)
#define LTQ_PMU_PWDCR_UART0		(1 << 7)
#define LTQ_PMU_PWDCR_USB		(1 << 6)
#define LTQ_PMU_PWDCR_DMA		(1 << 5)
#define LTQ_PMU_PWDCR_PCI		(1 << 4)
#define LTQ_PMU_PWDCR_FPI1		(1 << 1)
#define LTQ_PMU_PWDCR_USB0_PHY		(1 << 0)

struct ltq_pmu_regs {
	u32	rsvd0[7];
	__be32	pwdcr;
	__be32	sr;
};

static struct ltq_pmu_regs *ltq_pmu_regs =
	(struct ltq_pmu_regs *) CKSEG1ADDR(LTQ_PMU_BASE);

u32 ltq_pm_map(enum ltq_pm_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_PM_CORE:
		val = LTQ_PMU_PWDCR_DDR_MEM | LTQ_PMU_PWDCR_UART1 |
			LTQ_PMU_PWDCR_FPI0 | LTQ_PMU_PWDCR_LEDC |
			LTQ_PMU_PWDCR_EBU;
		break;
	case LTQ_PM_DMA:
		val = LTQ_PMU_PWDCR_DMA;
		break;
	case LTQ_PM_ETH:
		val = LTQ_PMU_PWDCR_SWITCH | LTQ_PMU_PWDCR_PPE_DP |
			LTQ_PMU_PWDCR_PPE_EMA | LTQ_PMU_PWDCR_PPE_TC;
		break;
	case LTQ_PM_SPI:
		val = LTQ_PMU_PWDCR_SPI;
		break;
	default:
		val = 0;
		break;
	}

	return val;
}

int ltq_pm_enable(enum ltq_pm_modules module)
{
	const unsigned long timeout = 1000;
	unsigned long timebase;
	u32 sr, val;

	val = ltq_pm_map(module);
	if (unlikely(!val))
		return 1;

	ltq_clrbits(&ltq_pmu_regs->pwdcr, val);

	timebase = get_timer(0);

	do {
		sr = ltq_readl(&ltq_pmu_regs->sr);
		if (~sr & val)
			return 0;
	} while (get_timer(timebase) < timeout);

	return 1;
}

int ltq_pm_disable(enum ltq_pm_modules module)
{
	u32 val;

	val = ltq_pm_map(module);
	if (unlikely(!val))
		return 1;

	ltq_setbits(&ltq_pmu_regs->pwdcr, val);

	return 0;
}

void ltq_pmu_init(void)
{
	u32 set, clr;

	clr = ltq_pm_map(LTQ_PM_CORE);
	set = ~(LTQ_PMU_PWDCR_RESERVED | clr);

	ltq_clrsetbits(&ltq_pmu_regs->pwdcr, clr, set);
}
