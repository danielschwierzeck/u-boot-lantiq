/* Copyright (c) 2018, Intel Corporation.
 * PRX300 slim wdt driver
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <asm/gic.h>
#include <common.h>
#include <lantiq.h>
#include <watchdog.h>

#define WDT_START	0x1
#define WDT_OTM		(0 << 1)
#define WDT_SCM		(1 << 1)

extern int cpu_is_cps(void);
int wdt_disabled = 0;
int wdt_initialized = 1;

static void watchdog_start(void)
{
	if (wdt_disabled)
		return;

	/* enable watchdog */
	ltq_w32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_CONFIG0_OFS,
		(ltq_r32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
			+GIC_VPE_WD_CONFIG0_OFS) | WDT_START));
	wmb();
}

static void watchdog_stop(void)
{
	if (!cpu_is_cps())
		return;

	/* disable watchdog */
	ltq_w32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_CONFIG0_OFS,
		(ltq_r32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
			+GIC_VPE_WD_CONFIG0_OFS) & ~(WDT_START)));
	wmb();
}

void hw_watchdog_start(void)
{
	wdt_disabled = 0;
	watchdog_start();
}

void hw_watchdog_stop(void)
{
	watchdog_stop();
	wdt_disabled = 1;
}

int hw_watchdog_set_timer(u32 timeout)
{
	u32 timeout_cal = timeout;

	watchdog_stop();

	ltq_w32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_INITIAL0_OFS, timeout_cal);
	wmb();

	return 0;
}

void hw_watchdog_init(void)
{
	if (!cpu_is_cps())
		return;

	if (wdt_initialized == 0)
		return;

	/* enable watchdog rcu */
	ltq_w32(RCU_MODULE_BASE, INTERAPTIV_WDT_RST_EN,
		INTERAPTIV_WDT_RST_EN_WDT0_MASK);

	ltq_w32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_CONFIG0_OFS, 0x0);
	wmb();
	/* set watchdog to one trip mode */
	ltq_w32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_CONFIG0_OFS,
		(ltq_r32(GIC_BASE_ADDRESS, VPE_LOCAL_SECTION_OFS
		+ GIC_VPE_WD_CONFIG0_OFS) | WDT_SCM));
	wmb();
	hw_watchdog_set_timer(CONFIG_WDT_TIMEOUT_VALUE);
	wdt_initialized = 0;
}

#ifndef CONFIG_SPL_BUILD
void hw_watchdog_reset(void)
{
	if (!cpu_is_cps())
		return;

	/* keep alive the wdt timer */
	hw_watchdog_set_timer(CONFIG_WDT_TIMEOUT_VALUE);
	watchdog_start();
}
#else
void hw_watchdog_reset(void) {};
#endif
