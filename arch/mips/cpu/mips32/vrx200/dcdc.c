/*
 * Copyright (C) 2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>

#define LTQ_DCDC_CLK_SET0_CLK_SEL_P		(1 << 6)
#define LTQ_DCDC_CLK_SET1_SEL_DIV25		(1 << 5)
#define LTQ_DCDC_CONF_TEST_DIG_PID_FREEZE	(1 << 5)

struct ltq_dcdc_regs {
	u8	b0_coeh;		/* Coefficient b0 */
	u8	b0_coel;		/* Coefficient b0 */
	u8	b1_coeh;		/* Coefficient b1 */
	u8	b1_coel;		/* Coefficient b1 */
	u8	b2_coeh;		/* Coefficient b2 */
	u8	b2_coel;		/* Coefficient b2 */
	u8	clk_set0;		/* Clock setup */
	u8	clk_set1;		/* Clock setup */
	u8	pwm_confh;		/* Configure PWM */
	u8	pwm_confl;		/* Configure PWM */
	u8	bias_vreg0;		/* Bias and regulator setup */
	u8	bias_vreg1;		/* Bias and regulator setup */
	u8	adc_gen0;		/* ADC and general control */
	u8	adc_gen1;		/* ADC and general control */
	u8	adc_con0;		/* ADC and general config */
	u8	adc_con1;		/* ADC and general config */
	u8	conf_test_ana;		/* not documented */
	u8	conf_test_dig;		/* not documented */
	u8	dcdc_status;		/* not documented */
	u8	pid_status;		/* not documented */
	u8	duty_cycle;		/* not documented */
	u8	non_ov_delay;		/* not documented */
	u8	analog_gain;		/* not documented */
	u8	duty_cycle_max_sat;	/* not documented */
	u8	duty_cycle_min_sat;	/* not documented */
	u8	duty_cycle_max;		/* not documented */
	u8	duty_cycle_min;		/* not documented */
	u8	error_max;		/* not documented */
	u8	error_read;		/* not documented */
	u8	delay_deglitch;		/* not documented */
	u8	latch_control;		/* not documented */
	u8	rsvd[240];
	u8	osc_conf;		/* OSC general config */
	u8	osc_stat;		/* OSC general status */
};

static struct ltq_dcdc_regs *ltq_dcdc_regs =
	(struct ltq_dcdc_regs *) CKSEG1ADDR(LTQ_DCDC_BASE);

void ltq_dcdc_init(unsigned int dig_ref)
{
	u8 dig_ref_cur, val;

	/* Set duty cycle max sat. to 70/90, enable PID freeze */
	ltq_writeb(&ltq_dcdc_regs->duty_cycle_max_sat, 0x5A);
	ltq_writeb(&ltq_dcdc_regs->duty_cycle_min_sat, 0x46);
	val = ltq_readb(&ltq_dcdc_regs->conf_test_dig);
	val |= LTQ_DCDC_CONF_TEST_DIG_PID_FREEZE;
	ltq_writeb(&ltq_dcdc_regs->conf_test_dig, val);

	/* Program new coefficients */
	ltq_writeb(&ltq_dcdc_regs->b0_coeh, 0x00);
	ltq_writeb(&ltq_dcdc_regs->b0_coel, 0x00);
	ltq_writeb(&ltq_dcdc_regs->b1_coeh, 0xFF);
	ltq_writeb(&ltq_dcdc_regs->b1_coel, 0xE6);
	ltq_writeb(&ltq_dcdc_regs->b2_coeh, 0x00);
	ltq_writeb(&ltq_dcdc_regs->b2_coel, 0x1B);
	ltq_writeb(&ltq_dcdc_regs->non_ov_delay, 0x8B);

	/* Set duty cycle max sat. to 60/108, disable PID freeze */
	ltq_writeb(&ltq_dcdc_regs->duty_cycle_max_sat, 0x6C);
	ltq_writeb(&ltq_dcdc_regs->duty_cycle_min_sat, 0x3C);
	val = ltq_readb(&ltq_dcdc_regs->conf_test_dig);
	val &= ~LTQ_DCDC_CONF_TEST_DIG_PID_FREEZE;
	ltq_writeb(&ltq_dcdc_regs->conf_test_dig, val);

	/* Init clock and DLL settings */
	val = ltq_readb(&ltq_dcdc_regs->clk_set0);
	val |= LTQ_DCDC_CLK_SET0_CLK_SEL_P;
	ltq_writeb(&ltq_dcdc_regs->clk_set0, val);
	val = ltq_readb(&ltq_dcdc_regs->clk_set1);
	val |= LTQ_DCDC_CLK_SET1_SEL_DIV25;
	ltq_writeb(&ltq_dcdc_regs->clk_set1, val);
	ltq_writeb(&ltq_dcdc_regs->pwm_confh, 0xF9);

	wmb();

	/* Adapt value of digital reference of DCDC converter */
	dig_ref_cur = ltq_readb(&ltq_dcdc_regs->bias_vreg1);

	while (dig_ref_cur != dig_ref) {
		if (dig_ref >= dig_ref_cur)
			dig_ref_cur++;
		else if (dig_ref < dig_ref_cur)
			dig_ref_cur--;

		ltq_writeb(&ltq_dcdc_regs->bias_vreg1, dig_ref_cur);
		__udelay(1000);
	}
}
