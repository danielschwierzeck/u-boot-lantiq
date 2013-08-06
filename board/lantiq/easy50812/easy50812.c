/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2013 Luka Perkov <luka@openwrt.org>
 */

#include <common.h>
#include <asm/gpio.h>
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
