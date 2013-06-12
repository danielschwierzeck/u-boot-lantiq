/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/arch/gpio.h>
#include <asm/lantiq/io.h>

#define SSIO_GPIO_BASE		64

#define SSIO_CON0_SWU		(1 << 31)
#define SSIO_CON0_RZFL		(1 << 26)
#define SSIO_CON0_GPHY1_SHIFT	27
#define SSIO_CON0_GPHY1_CONFIG	((CONFIG_LTQ_SSIO_GPHY1_MODE & 0x7) << 27)

#define SSIO_CON1_US_FPI	(2 << 30)
#define SSIO_CON1_FPID_2HZ	(0 << 23)
#define SSIO_CON1_FPID_4HZ	(1 << 23)
#define SSIO_CON1_FPID_8HZ	(2 << 23)
#define SSIO_CON1_FPID_10HZ	(3 << 23)
#define SSIO_CON1_FPIS_1_2	(1 << 20)
#define SSIO_CON1_FPIS_1_32	(2 << 20)
#define SSIO_CON1_FPIS_1_64	(3 << 20)

#define SSIO_CON1_GPHY2_SHIFT	15
#define SSIO_CON1_GPHY2_CONFIG	((CONFIG_LTQ_SSIO_GPHY2_MODE & 0x7) << 15)

#define SSIO_CON1_GROUP2	(1 << 2)
#define SSIO_CON1_GROUP1	(1 << 1)
#define SSIO_CON1_GROUP0	(1 << 0)
#define SSIO_CON1_GROUP_CONFIG	(0x3)

#ifdef CONFIG_LTQ_SSIO_SHIFT_REGS
#define enable_ssio	1
#else
#define enable_ssio	0

#define CONFIG_LTQ_SSIO_GPHY1_MODE	0
#define CONFIG_LTQ_SSIO_GPHY2_MODE	0
#define CONFIG_LTQ_SSIO_INIT_VALUE	0
#endif

#ifdef CONFIG_LTQ_SSIO_EDGE_FALLING
#define SSIO_RZFL_CONFIG	SSIO_CON0_RZFL
#else
#define SSIO_RZFL_CONFIG	0
#endif

struct ltq_gpio_port_regs {
	__be32	out;
	__be32	in;
	__be32	dir;
	__be32	altsel0;
	__be32	altsel1;
	__be32	od;
	__be32	stoff;
	__be32	pudsel;
	__be32	puden;
	__be32	rsvd1[3];
};

struct ltq_gpio_regs {
	u32				rsvd[4];
	struct ltq_gpio_port_regs	ports[CONFIG_LTQ_GPIO_MAX_BANKS];
};

struct ltq_gpio3_regs {
	u32	rsvd0[13];
	__be32	od;
	__be32	pudsel;
	__be32	puden;
	u32	rsvd1[9];
	__be32	altsel1;
	u32	rsvd2[14];
	__be32	out;
	__be32	in;
	__be32	dir;
	__be32	altsel0;
};

struct ltq_ssio_regs {
	__be32	con0;
	__be32	con1;
	__be32	cpu0;
	__be32	cpu1;
	__be32	ar;
};

static struct ltq_gpio_regs *ltq_gpio_regs =
	(struct ltq_gpio_regs *) CKSEG1ADDR(LTQ_GPIO_BASE);

static struct ltq_gpio3_regs *ltq_gpio3_regs =
	(struct ltq_gpio3_regs *) CKSEG1ADDR(LTQ_GPIO_BASE);

static struct ltq_ssio_regs *ltq_ssio_regs =
	(struct ltq_ssio_regs *) CKSEG1ADDR(LTQ_SSIO_BASE);

static int is_gpio_bank3(unsigned int port)
{
#ifdef CONFIG_LTQ_HAS_GPIO_BANK3
	return port == 3;
#else
	return 0;
#endif
}

static int is_gpio_ssio(unsigned int gpio)
{
#ifdef CONFIG_LTQ_SSIO_SHIFT_REGS
	return gpio >= SSIO_GPIO_BASE;
#else
	return 0;
#endif
}

static inline int ssio_gpio_to_bit(unsigned gpio)
{
	return 1 << (gpio - SSIO_GPIO_BASE);
}

int ltq_gpio_init(void)
{
	ltq_writel(&ltq_ssio_regs->ar, 0);
	ltq_writel(&ltq_ssio_regs->cpu0, CONFIG_LTQ_SSIO_INIT_VALUE);
	ltq_writel(&ltq_ssio_regs->cpu1, 0);
	ltq_writel(&ltq_ssio_regs->con0, SSIO_CON0_SWU);

	if (enable_ssio) {
		ltq_writel(&ltq_ssio_regs->con0, SSIO_CON0_GPHY1_CONFIG |
			SSIO_RZFL_CONFIG);
		ltq_writel(&ltq_ssio_regs->con1, SSIO_CON1_US_FPI |
			SSIO_CON1_FPID_8HZ | SSIO_CON1_GPHY2_CONFIG |
			SSIO_CON1_GROUP_CONFIG);
	}

	return 0;
}

int gpio_request(unsigned gpio, const char *label)
{
	return 0;
}

int gpio_free(unsigned gpio)
{
	return 0;
}

int gpio_direction_input(unsigned gpio)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_od = &ltq_gpio_regs->ports[port].od;
	const void *gpio_altsel0 = &ltq_gpio_regs->ports[port].altsel0;
	const void *gpio_altsel1 = &ltq_gpio_regs->ports[port].altsel1;
	const void *gpio_dir = &ltq_gpio_regs->ports[port].dir;

	if (is_gpio_ssio(gpio))
		return 0;

	if (is_gpio_bank3(port)) {
		gpio_od = &ltq_gpio3_regs->od;
		gpio_altsel0 = &ltq_gpio3_regs->altsel0;
		gpio_altsel1 = &ltq_gpio3_regs->altsel1;
		gpio_dir = &ltq_gpio3_regs->dir;
	}

	/*
	 * Reset open drain and altsel configs to workaround improper
	 * reset values or unwanted modifications by BootROM
	 */
	ltq_clrbits(gpio_od, gpio_to_bit(gpio));
	ltq_clrbits(gpio_altsel0, gpio_to_bit(gpio));
	ltq_clrbits(gpio_altsel1, gpio_to_bit(gpio));

	/* Switch to input */
	ltq_clrbits(gpio_dir, gpio_to_bit(gpio));

	return 0;
}

int gpio_direction_output(unsigned gpio, int value)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_od = &ltq_gpio_regs->ports[port].od;
	const void *gpio_altsel0 = &ltq_gpio_regs->ports[port].altsel0;
	const void *gpio_altsel1 = &ltq_gpio_regs->ports[port].altsel1;
	const void *gpio_dir = &ltq_gpio_regs->ports[port].dir;
	const void *gpio_out = &ltq_gpio_regs->ports[port].out;
	u32 data = gpio_to_bit(gpio);

	if (is_gpio_ssio(gpio)) {
		data = ssio_gpio_to_bit(gpio);
		if (value)
			ltq_setbits(&ltq_ssio_regs->cpu0, data);
		else
			ltq_clrbits(&ltq_ssio_regs->cpu0, data);

		return 0;
	}

	if (is_gpio_bank3(port)) {
		gpio_od = &ltq_gpio3_regs->od;
		gpio_altsel0 = &ltq_gpio3_regs->altsel0;
		gpio_altsel1 = &ltq_gpio3_regs->altsel1;
		gpio_dir = &ltq_gpio3_regs->dir;
		gpio_out = &ltq_gpio3_regs->out;
	}

	/*
	 * Reset open drain and altsel configs to workaround improper
	 * reset values or unwanted modifications by BootROM
	 */
	ltq_setbits(gpio_od, data);
	ltq_clrbits(gpio_altsel0, data);
	ltq_clrbits(gpio_altsel1, data);

	if (value)
		ltq_setbits(gpio_out, data);
	else
		ltq_clrbits(gpio_out, data);

	/* Switch to output */
	ltq_setbits(gpio_dir, data);

	return 0;
}

int gpio_get_value(unsigned gpio)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_in = &ltq_gpio_regs->ports[port].in;
	u32 data = gpio_to_bit(gpio);
	u32 val;

	if (is_gpio_ssio(gpio)) {
		gpio_in = &ltq_ssio_regs->cpu0;
		data = ssio_gpio_to_bit(gpio);
	}

	if (is_gpio_bank3(port))
		gpio_in = &ltq_gpio3_regs->in;

	val = ltq_readl(gpio_in);

	return !!(val & data);
}

int gpio_set_value(unsigned gpio, int value)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_out = &ltq_gpio_regs->ports[port].out;
	u32 data = gpio_to_bit(gpio);

	if (is_gpio_ssio(gpio)) {
		gpio_out = &ltq_ssio_regs->cpu0;
		data = ssio_gpio_to_bit(gpio);
	}

	if (is_gpio_bank3(port))
		gpio_out = &ltq_gpio3_regs->out;

	if (value)
		ltq_setbits(gpio_out, data);
	else
		ltq_clrbits(gpio_out, data);

	return 0;
}

int gpio_set_altfunc(unsigned gpio, int altsel0, int altsel1, int dir)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_od = &ltq_gpio_regs->ports[port].od;
	const void *gpio_altsel0 = &ltq_gpio_regs->ports[port].altsel0;
	const void *gpio_altsel1 = &ltq_gpio_regs->ports[port].altsel1;
	const void *gpio_dir = &ltq_gpio_regs->ports[port].dir;

	if (is_gpio_ssio(gpio))
		return 0;

	if (is_gpio_bank3(port)) {
		gpio_od = &ltq_gpio3_regs->od;
		gpio_altsel0 = &ltq_gpio3_regs->altsel0;
		gpio_altsel1 = &ltq_gpio3_regs->altsel1;
		gpio_dir = &ltq_gpio3_regs->dir;
	}

	if (altsel0)
		ltq_setbits(gpio_altsel0, gpio_to_bit(gpio));
	else
		ltq_clrbits(gpio_altsel0, gpio_to_bit(gpio));

	if (altsel1)
		ltq_setbits(gpio_altsel1, gpio_to_bit(gpio));
	else
		ltq_clrbits(gpio_altsel1, gpio_to_bit(gpio));

	if (dir) {
		ltq_setbits(gpio_od, gpio_to_bit(gpio));
		ltq_setbits(gpio_dir, gpio_to_bit(gpio));
	} else {
		ltq_clrbits(gpio_od, gpio_to_bit(gpio));
		ltq_clrbits(gpio_dir, gpio_to_bit(gpio));
	}

	return 0;
}

int gpio_set_opendrain(unsigned gpio, int od)
{
	unsigned port = gpio_to_port(gpio);
	const void *gpio_od = &ltq_gpio_regs->ports[port].od;

	if (is_gpio_ssio(gpio))
		return 0;

	if (is_gpio_bank3(port))
		gpio_od = &ltq_gpio3_regs->od;

	if (od)
		ltq_setbits(gpio_od, gpio_to_bit(gpio));
	else
		ltq_clrbits(gpio_od, gpio_to_bit(gpio));

	return 0;
}
