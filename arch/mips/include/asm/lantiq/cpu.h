/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_CPU_H__
#define __LANTIQ_CPU_H__

enum ltq_boot_select {
	BOOT_NOR,
	BOOT_NOR_NO_BOOTROM,
	BOOT_UART,
	BOOT_UART_NO_EEPROM,
	BOOT_SPI,
	BOOT_NAND,
	BOOT_PCI,
	BOOT_MII0,
	BOOT_RMII0,
	BOOT_RGMII0,
	BOOT_RGMII1,
	BOOT_UNKNOWN,
};

enum ltq_boot_select ltq_boot_select(void);
const char *ltq_boot_select_str(void);

void ltq_pmu_init(void);
void ltq_ebu_init(void);
void ltq_gpio_init(void);

void ltq_pll_init(void);
void ltq_dcdc_init(unsigned int dig_ref);

#endif /* __LANTIQ_CPU_H__ */
