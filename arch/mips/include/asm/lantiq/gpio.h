/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_GPIO_H__
#define __LANTIQ_GPIO_H__

enum ltq_gpio_dir {
	GPIO_DIR_IN = 0,
	GPIO_DIR_OUT
};

enum ltq_gpio_od {
	GPIO_OD_ACTIVE = 0,
	GPIO_OD_NORMAL
};

enum ltq_gpio_altsel {
	GPIO_ALTSEL_CLR = 0,
	GPIO_ALTSEL_SET
};

enum ltq_gpio_pull {
	GPIO_PULL_DISABLE = 0,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
};

extern int gpio_set_altfunc(unsigned gpio, enum ltq_gpio_altsel altsel0,
			enum ltq_gpio_altsel altsel1, enum ltq_gpio_dir dir);
extern int gpio_set_opendrain(unsigned gpio, enum ltq_gpio_od od);
extern int gpio_set_pull(unsigned gpio, enum ltq_gpio_pull pull);

static inline int gpio_to_port(unsigned gpio)
{
	return gpio >> 4;
}

static inline int gpio_to_pin(unsigned gpio)
{
	return gpio & 0xF;
}

static inline int gpio_to_bit(unsigned gpio)
{
	return 1 << gpio_to_pin(gpio);
}

static inline int gpio_to_gpio(unsigned port, unsigned pin)
{
	return (port << 4) | (pin & 0xF);
}

#include <asm-generic/gpio.h>

#endif /* __LANTIQ_GPIO_H__ */
