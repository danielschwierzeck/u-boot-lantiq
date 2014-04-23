/*
 * Copyright (C) 2014 Álvaro Fernández Rojas <noltari@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <switch.h>
#include <asm/gpio.h>
#include <asm/lantiq/eth.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/chipid.h>

int board_early_init_f(void)
{
	/* Switch on Power LED */
	gpio_direction_output(2, 0);
	gpio_set_value(2, 0);

	return 0;
}

int checkboard(void)
{
	puts("Board: " CONFIG_BOARD_NAME "\n");
	ltq_chip_print_info();

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* MAC0: Atheros ar8216 switch */
	{ 0, 0x0, LTQ_ETH_PORT_SWITCH, PHY_INTERFACE_MODE_NONE },
};

static const struct ltq_eth_board_config eth_board_config = {
	.ports = eth_port_config,
	.num_ports = ARRAY_SIZE(eth_port_config),
};

int board_eth_init(bd_t *bis)
{
	return ltq_eth_initialize(&eth_board_config);
}

static struct switch_device ar8216_dev = {
	.name = "ar8216",
	.cpu_port = 0,
	.port_mask = 0xF,
};

int board_switch_init(void)
{
	return switch_device_register(&ar8216_dev);
}
