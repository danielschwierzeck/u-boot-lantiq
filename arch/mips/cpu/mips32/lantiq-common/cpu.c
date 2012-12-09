/*
 * Copyright (C) 2012-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/reset.h>
#include <asm/lantiq/cpu.h>

static const char ltq_bootsel_strings[][16] = {
	"NOR",
	"NOR w/o BootROM",
	"UART",
	"UART w/o EEPROM",
	"SPI",
	"NAND",
	"PCI",
	"MII0",
	"RMII0",
	"RGMII0",
	"RGMII1",
	"unknown",
};

const char *ltq_boot_select_str(void)
{	enum ltq_boot_select bootsel = ltq_boot_select();

	if (bootsel > BOOT_UNKNOWN)
		bootsel = BOOT_UNKNOWN;

	return ltq_bootsel_strings[bootsel];
}

void ltq_chip_print_info(void)
{
	char buf[32];

	printf("SoC:   Lantiq %s v1.%u\n", ltq_chip_partnum_str(),
		ltq_chip_version_get());
	printf("CPU:   %s MHz\n", strmhz(buf, ltq_get_cpu_clock()));
	printf("IO:    %s MHz\n", strmhz(buf, ltq_get_io_region_clock()));
	printf("BUS:   %s MHz\n", strmhz(buf, ltq_get_bus_clock()));
	printf("BOOT:  %s\n", ltq_boot_select_str());
}

int arch_cpu_init(void)
{
	ltq_pmu_init();
	ltq_ebu_init();

	return 0;
}

void _machine_restart(void)
{
	ltq_reset_activate(LTQ_RESET_CORE);
}
