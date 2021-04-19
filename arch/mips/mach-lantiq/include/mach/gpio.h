/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __LANTIQ_GPIO_H__
#define __LANTIQ_GPIO_H__

#include <asm/gpio.h>

extern void ltq_gpio_dump(void);
extern void ltq_gpio_mux(unsigned gpio, unsigned int func, unsigned int dir);

#define LTQ_GPIO_INPUT		0
#define LTQ_GPIO_OUTPUT		1
#define LTQ_PORTMUX_GPIO	0
#define LTQ_PORTMUX_EBU		1
#define LTQ_PORTMUX_SSO		1
#define LTQ_PORTMUX_MDIO	1

#endif /* __LANTIQ_GPIO_H__ */
