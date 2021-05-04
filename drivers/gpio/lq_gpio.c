/* Copyright (c) 2018, Intel Corporation.
 * PRX300 GPIO driver
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <lantiq.h>
#include <common.h>
#include <asm/gpio.h>
#include <asm/addrspace.h>

#define GPIO_INPUT 0
#define GPIO_OUTPUT 1
#define GPIO_HW 2
#define MAX_GPIO 40

#define GPIO_BASE		(KSEG1 | GPIO_FUNCTION_MODULE_BASE)
#define GPIO_MUX_BASE	(KSEG1 | GPIO_PAD_CTRL_MODULE_BASE)
#define GPIO_DIR_L		(uint32_t *)(KSEG1 | GPIO_FUNCTION_DIR_0)
#define GPIO_DIR_U		(uint32_t *)(KSEG1 | GPIO_FUNCTION_DIR_1)
#define GPIO_OUT_L		(uint32_t *)(KSEG1 | GPIO_FUNCTION_OUT_0)
#define GPIO_OUT_U		(uint32_t *)(KSEG1 | GPIO_FUNCTION_OUT_1)

int gpio_init;
short gpio_stat[MAX_GPIO];

/* Checked if pins are reserved for U-boot
 * functionality
 */
int check_reserved(unsigned int gpio)
{
	if (gpio >= MAX_GPIO)
		return -EINVAL;

	/* alt fn 0 = gpio mode else reserved */
	if (gpio_stat[gpio] != 0)
		return 1;

	return 0;
}

int gpio_free(unsigned int gpio)
{
	return 0;
}

int gpio_request(unsigned int gpio, const char *label)
{
	return 0;
}

/* ret: 1 -- output
 * ret: 0 -- input
 */
int gpio_get_direction(unsigned int gpio)
{
	uint32_t dir;

	if (gpio > 31)
		dir = (readl(GPIO_DIR_U) & (1 << (gpio - 32)));
	else
		dir = (readl(GPIO_DIR_L) & (1 << gpio));

	if (dir)
		return 1;
	else
		return 0;
}

/* Get input GPIO value */
int gpio_get_value(unsigned int gpio)
{
	int pin_no = (gpio > 31) ? (gpio - 32) : gpio;
	int offset_in = (gpio > 31) ? IN_1 : IN_0;
	int offset_out = (gpio > 31) ? OUT_1 : OUT_0;
	uint32_t value;

	if (gpio_get_direction(gpio))
		value = readl((uint32_t *)(GPIO_BASE + offset_out));
	else
		value = readl((uint32_t *)(GPIO_BASE + offset_in));

	return ((value & (1 << pin_no)) >> pin_no);
}

/* Set output GPIO value */
int gpio_set_value(unsigned int gpio, int value)
{
	int pin_no = (gpio > 31) ? (gpio - 32) : gpio;
	int offset = (gpio > 31) ? OUT_1 : OUT_0;
	uint32_t gpio_addr = (GPIO_BASE + offset);
	uint32_t reg;

	reg = readl((u32 *)gpio_addr);
	if (!value)
		reg &= ~(1 << pin_no);
	else
		reg |= (1 << pin_no);

	ltq_w32(GPIO_FUNCTION_MODULE_BASE, offset, reg);

	return 0;
}

void config_gpio(u32 pin, int dir)
{
	u32 pad_base = GPIO_PAD_CTRL_MODULE_BASE;
	u32 gpio_base = GPIO_FUNCTION_MODULE_BASE;
	u32 portmux_base = pin > 31 ? PORTMUXC32 : PORTMUXC0;
	u32 dir_base = pin > 31 ? DIR_1 : DIR_0;
	u32 od_base = pin > 31 ? OD_1 : OD_0;
	u32 puen_base = pin > 31 ? PUEN_1 : PUEN_0;
	u32 pden_base = pin > 31 ? PDEN_1 : PDEN_0;
	u32 src_base = pin > 31 ? SRC_1 : SRC_0;
	u32 dcc_base = pin > 31 ? DCC_1 : DCC_0;
	u32 rel_port_num = pin > 31 ? (pin - 32) : pin;

	ltq_w32(pad_base + portmux_base, (rel_port_num << 2), 0x0);
	ltq_w32(pad_base, puen_base,
		(ltq_r32(pad_base, puen_base) & ~(1 << rel_port_num)));
	ltq_w32(pad_base, pden_base,
		(ltq_r32(pad_base, pden_base) & ~(1 << rel_port_num)));
	ltq_w32(pad_base, src_base,
		(ltq_r32(pad_base, src_base) | (1 << rel_port_num)));
	ltq_w32(pad_base, dcc_base,
		(ltq_r32(pad_base, dcc_base) | (3 << (2 * rel_port_num))));
	ltq_w32(pad_base, od_base,
		(ltq_r32(pad_base, od_base) & ~(1 << rel_port_num)));

	if (dir) {
		ltq_w32(gpio_base, dir_base,
			(ltq_r32(gpio_base, dir_base) | (1 << rel_port_num)));
	} else {
		ltq_w32(gpio_base, dir_base,
			(ltq_r32(gpio_base, dir_base) & ~(1 << rel_port_num)));
	}
}

void pads_init_pin(unsigned int pin, unsigned int value)
{
	u32 rel_pin_no = pin > 31 ? (pin - 32) : pin;
	u32 offset = pin > 31 ? (0x100 + (rel_pin_no << 2)) : (rel_pin_no << 2);

	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, offset, value);
}

int gpio_direction_output(unsigned int gpio, int value)
{
	if (check_reserved(gpio)) {
		printf("GPIO pin %d is reserved\n", gpio);
		return -1;
	}

	config_gpio(gpio, GPIO_OUTPUT);

	return gpio_set_value(gpio, value);
}

int gpio_direction_input(unsigned int gpio)
{
	if (check_reserved(gpio)) {
		printf("GPIO pin %d is reserved\n", gpio);
		return -1;
	}

	config_gpio(gpio, GPIO_INPUT);
	return 0;
}

void gpio_info(void)
{
	int i, dir, func;
	uint32_t gpio_pad_base = (GPIO_MUX_BASE);

	printf("	 \tDirection\tValue\tFunction\tReserved?\n");
	for (i = 0; i < MAX_GPIO; i++) {
		printf("GPIO[%d]:\t", i);
		/* direction */
		dir = gpio_get_direction(i);
		printf("%s\t\t", (dir) ? "OUTPUT" : "INPUT");

		/* value */
		printf("%d\t", gpio_get_value(i));

		/* function */
		if (i < 32)
			func = readl((uint32_t *)(gpio_pad_base + (i << 2)));
		else
			func = readl((uint32_t *)(gpio_pad_base
					+ 0x100 + ((i - 32) << 2)));

		printf("%d\t\t", (func & 0x3));
		/* reserved ? */
		printf("%s\n", (gpio_stat[i] != 0)
			? "RESERVED" : "NOT-RESERVED");
	}
}

int gpio_set_mux(unsigned int gpio, int value)
{
	if (gpio > 32 || value > 4)
		return -EINVAL;

	pads_init_pin(gpio, value);

	return 0;
}

/* During boot, we reserve pins which are crucial to u-boot
 * to function properly (e.g. flash gpio pins) to prevent
 * users from re-configuring these pins
 */
int gpio_reserve_and_set(unsigned int gpio, unsigned int direction,
					unsigned int value)
{
	if (gpio_init != 1) {
		/* default as gpio */
		memset(gpio_stat, 0, MAX_GPIO);
		gpio_init = 1;
	}

	debug("Reserving gpio: %d, dir: %d & val: %d\n",
				gpio, direction, value);

	/* reserve gpio */
	gpio_stat[gpio] = value;

	if (direction != GPIO_HW)
		config_gpio(gpio, direction);

	pads_init_pin(gpio, value);

	return 0;
}
