// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <mach/gpio.h>
#include <sas/controlfile.h>

static void gx5502_gpio_init(void)
{
	/* SLIC reset (low-active) */
	gpio_direction_output(1, 1);
	/* PCI-E 0 reset (low-active) */
	gpio_direction_output(14, 1);
	/* PCI-E 1 reset (low-active) */
	gpio_direction_output(3, 1);
	/* PCI-E 2 reset (high-active) */
	gpio_direction_output(2, 0);

	/* USB port OC (high-active) */
	gpio_direction_output(7, 0);
	/* USB port power (high-active) */
	gpio_direction_output(9, 0);

	/* Wifi power (high-active) */
	gpio_direction_output(61, 0);

	/* NAND CS0 (controlled manually via GPIO, low-active) */
	gpio_direction_output(8, 1);
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
	gpio_direction_input(0);
	/* WLAN button */
	gpio_direction_input(42);
	/* WPS button */
	gpio_direction_input(43);

	/* SLIC SPI CS (low-active) */
	gpio_direction_output(10, 1);
	/* IPAC SPI CS (low-active) */
	gpio_direction_output(11, 1);
	/* IPAC SPI CS (low-active) */
	gpio_direction_output(15, 1);

	/* PAE MDC (low-active) */
	gpio_direction_output(33, 1);
	/* PAE MDIO (low-active) */
	gpio_direction_output(32, 1);

	/* I2C SDA (high-active) */
	gpio_direction_output(21, 0);
	/* I2C SCL (high-active) */
	gpio_direction_output(22, 0);
	/* I2C SFP SDA (high-active) */
	gpio_direction_output(34, 0);
	/* I2C SFP SCL (high-active) */
	gpio_direction_output(35, 0);

	/* SSO LED_ST */
	ltq_gpio_mux(4, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);
	/* SSO LED_D */
	ltq_gpio_mux(5, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);
	/* SSO LED_SH */
	ltq_gpio_mux(6, LTQ_PORTMUX_SSO, LTQ_GPIO_OUTPUT);

	/* Enable red:power */
	ltq_gpio_init(BIT(14));
}

int board_early_init_f(void)
{
	gx5502_gpio_init();
	return 0;
}

int sas_cf_check_board(void)
{
	/* check if RESET button is pressed */
	return 0 == gpio_get_value(0);
}

void sas_cf_led_action(enum sas_cf_state state)
{
	switch (state) {
	case CF_STARTED:
		/* LED Service/Info green on */
		gpio_set_value(77, 1);
		break;
	case CF_FINISHED:
		/* LED Service/Info green off */
		gpio_set_value(77, 0);
		break;
	case CF_FAILED:
		/* LED Service/Info red on */
		gpio_set_value(73, 1);
		/* LED Service/Info green off */
		gpio_set_value(77, 0);
		break;
	}
}
