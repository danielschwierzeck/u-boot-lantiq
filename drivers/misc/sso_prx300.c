/* Copyright (c) 2018, Intel Corporation.
 * PRX300 SSO driver
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#include <common.h>
#include <lantiq.h>
#include <sso.h>

void sso_init(void)
{
	int i;

	/* enable sso clk */
	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A,
				ltq_r32(CGU_MODULE_BASE, GGU_CLKGSR1)
				| CGU_CLKGCR1_A_SSO_MASK);

	/* set SSO settings */
	ltq_w32(SSIO_MODULE_BASE, SSO_CON0, SSO_CON0_RZFL_MASK);

	for (i = 0; i < 32; i++)
		ltq_w32(SSIO_MODULE_BASE,
			(DUTY_CYCLE_0 + (i * 4)), 0xFF);

	ltq_w32(SSIO_MODULE_BASE, SSO_CON1, (0xf
		| (CONST_SSO_CON1_US_FPID << SSO_CON1_US_POS)));

	ltq_w32(SSIO_MODULE_BASE, LED_BLINK_H8_0, 0x00000000);
	ltq_w32(SSIO_MODULE_BASE, LED_BLINK_H8_1, 0x00000000);

	ltq_w32(SSIO_MODULE_BASE, SSO_AR, 0x00000000);
}

int sso_output(int gpio, u32 value, u8 duty_cycle)
{
	u32 reg;

	if (gpio > 32)
		return -EINVAL;

	debug("gpio: %d, value: %d, duty cycle: 0x%02x\n",
		gpio, value, duty_cycle);

	ltq_w32(SSIO_MODULE_BASE, (DUTY_CYCLE_0 + gpio * 4),
		duty_cycle);

	reg = ltq_r32(SSIO_MODULE_BASE, SSO_CPU0);
	if (value)
		ltq_w32(SSIO_MODULE_BASE, SSO_CPU0,
			(reg | (value << gpio)));
	else
		ltq_w32(SSIO_MODULE_BASE, SSO_CPU0,
			(reg & ~(1 << gpio)));

	return 0;
}

int sso_output_all(u32 value, u8 duty_cycle)
{
	int i;

	for (i = 0; i < 32; i++)
		ltq_w32(SSIO_MODULE_BASE,
			(DUTY_CYCLE_0 + (i * 4)), duty_cycle);

	ltq_w32(SSIO_MODULE_BASE, SSO_CPU0, value);

	return 0;
}
