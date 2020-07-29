// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <mach/gpio.h>

static void easy550_gpio_init(void)
{
	/* NAND CS1 (low-active) */
	ltq_gpio_mux(23, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND ALE (high-active) */
	ltq_gpio_mux(13, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND CLE (high-active) */
	ltq_gpio_mux(24, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND WE (low-active) */
	ltq_gpio_mux(59, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND WP (low-active) */
	ltq_gpio_mux(60, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND RE (low-active) */
	ltq_gpio_mux(49, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND Ready/Busy */
	ltq_gpio_mux(48, LTQ_PORTMUX_EBU, LTQ_GPIO_INPUT);

	/* NAND D0 (high-active) */
	ltq_gpio_mux(51, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D1 (high-active) */
	ltq_gpio_mux(50, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D2 (high-active) */
	ltq_gpio_mux(52, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D3 (high-active) */
	ltq_gpio_mux(57, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D4 (high-active) */
	ltq_gpio_mux(56, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D5 (high-active) */
	ltq_gpio_mux(55, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D6 (high-active) */
	ltq_gpio_mux(54, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);
	/* NAND D7 (high-active) */
	ltq_gpio_mux(53, LTQ_PORTMUX_EBU, LTQ_GPIO_OUTPUT);

	/* Reset button */
	gpio_direction_input(19);

	/* SSO LED_ST */
	ltq_gpio_mux(4, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);
	/* SSO LED_D */
	ltq_gpio_mux(5, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);
	/* SSO LED_SH */
	ltq_gpio_mux(6, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);

	ltq_gpio_init(0);
}

int board_early_init_f(void)
{
	easy550_gpio_init();
	return 0;
}
