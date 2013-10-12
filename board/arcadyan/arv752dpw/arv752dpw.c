/*
 * Copyright (C) 2012 Luka Perkov <luka@openwrt.org>
 * Copyright (C) 2013 Oliver Muth <dr.o.muth@gmx.de>
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
	return 0;
}

int checkboard(void)
{
	puts("Board: " CONFIG_BOARD_NAME "\n");
	ltq_chip_print_info();

	return 0;
}

static const struct ltq_eth_port_config eth_port_config[] = {
	/* MAC0: Realtek rtl8306 switch */
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
static struct switch_device rtl8306_dev = {
	.name = "rtl8306",
	.cpu_port = 5,
	.port_mask = 0xF,
};

int board_switch_init(void)
{
	return switch_device_register(&rtl8306_dev);
}
