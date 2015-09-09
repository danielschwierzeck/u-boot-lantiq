/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/pm.h>
#include <asm/arch/soc.h>

#define PMU_PWDCR_GPHY2		(1 << 31)
#define PMU_PWDCR_GPHY1		(1 << 30)
#define PMU_PWDCR_GPHY0		(1 << 29)
#define PMU_PWDCR_SWITCH	(1 << 28)
#define PMU_PWDCR_USB1		(1 << 27)
#define PMU_PWDCR_GPHY3		(1 << 26)
#define PMU_PWDCR_TDM		(1 << 25)
#define PMU_PWDCR_PPE_DP	(1 << 23)
#define PMU_PWDCR_PPE_EMA	(1 << 22)
#define PMU_PWDCR_DEU		(1 << 20)
#define PMU_PWDCR_GPHY_25M	(1 << 19)
#define PMU_PWDCR_PCIE		(1 << 18)
#define PMU_PWDCR_UART1		(1 << 17)
#define PMU_PWDCR_GPTC		(1 << 12)
#define PMU_PWDCR_LEDC		(1 << 11)
#define PMU_PWDCR_EBU		(1 << 10)
#define PMU_PWDCR_SPI		(1 << 8)
#define PMU_PWDCR_USIF		(1 << 7)
#define PMU_PWDCR_USB0		(1 << 6)
#define PMU_PWDCR_DMA		(1 << 5)
#define PMU_PWDCR_DFEV1		(1 << 3)
#define PMU_PWDCR_DFEV0		(1 << 2)

struct ltq_pmu_regs {
	u32	rsvd0[8];
	u32	clkgsr1;
	u32	clkgcr1_a;
	u32	clkgcr1_b;
	u32	rsvd1;
	u32	clkgsr2;
	u32	clkgcr2_a;
	u32	clkgcr2_b;
	u32	rsvd2;
	u32	analog_sr;
	u32	analog_cr_a;
	u32	analog_cr_b;
};

static struct ltq_pmu_regs *ltq_pmu_regs =
	(struct ltq_pmu_regs *) CKSEG1ADDR(LTQ_PMU_BASE);

u32 ltq_pm_map(enum ltq_pm_modules module)
{
	u32 val;

	switch (module) {
	case LTQ_PM_CORE:
		val = PMU_PWDCR_UART1 | PMU_PWDCR_LEDC | PMU_PWDCR_EBU;
		break;
	case LTQ_PM_DMA:
		val = PMU_PWDCR_DMA;
		break;
	case LTQ_PM_ETH:
		val = PMU_PWDCR_GPHY3 | PMU_PWDCR_GPHY2 | PMU_PWDCR_GPHY1 |
			PMU_PWDCR_GPHY0 | PMU_PWDCR_SWITCH | PMU_PWDCR_PPE_DP |
			 PMU_PWDCR_PPE_EMA;
		break;
	case LTQ_PM_SPI:
		val = PMU_PWDCR_SPI;
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

	ltq_setbits(&ltq_pmu_regs->clkgcr1_a, val);

	timebase = get_timer(0);

	do {
		sr = ltq_readl(&ltq_pmu_regs->clkgsr1);
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

	ltq_setbits(&ltq_pmu_regs->clkgcr1_b, val);

	return 0;
}

void ltq_pmu_init(void)
{
	u32 pm = ltq_pm_map(LTQ_PM_CORE);

	ltq_setbits(&ltq_pmu_regs->clkgcr1_a, pm);
}
