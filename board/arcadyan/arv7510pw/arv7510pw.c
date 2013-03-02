/*
 * Copyright (C) 2013 Matti Laakso <malaakso@elisanet.fi>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <switch.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/cpu.h>

static void gpio_init(void)
{
	/* Initialize SSIO GPIOs */
	gpio_set_altfunc(4, 1, 0, 1);
	gpio_set_altfunc(5, 1, 0, 1);
	gpio_set_altfunc(6, 1, 0, 1);
	ltq_gpio_init();

	/* Power led on */
	gpio_direction_output(76, 1);
}

int board_early_init_f(void)
{
	gpio_init();

	return 0;
}

int checkboard(void)
{
	puts("Board: " CONFIG_BOARD_NAME "\n");
	ltq_chip_print_info();

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* MAC0: ADM6996I */
	{ 0, 0x0, LTQ_ETH_PORT_SWITCH, PHY_INTERFACE_MODE_RMII },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t *bis)
{
	return ltq_eth_initialize(&eth_board_config);
}

static struct switch_device adm6996i_dev = {
	.name = "adm6996i",
	.cpu_port = 5,
	.port_mask = 0xF,
};

int board_switch_init(void)
{
	/* Deactivate HRST line to release reset of ADM6996I switch */
	ltq_reset_once(LTQ_RESET_HARD, 200000);

	/* ADM6996I needs some time to come out of reset */
	__udelay(50000);

	return switch_device_register(&adm6996i_dev);
}
