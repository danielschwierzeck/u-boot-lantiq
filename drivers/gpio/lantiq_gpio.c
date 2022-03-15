// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <asm/io.h>
#include <asm/mipsregs.h>
#include <asm/gpio.h>

#define GPIO_BANK_NUM		2
#define GPIO_BANK_SIZE		32

#define GPIO0_FUNCTION_BASE	0x16C00000
#define GPIO1_FUNCTION_BASE	(GPIO0_FUNCTION_BASE + 0x100)
#define GPIO0_PAD_CTRL_BASE	0x16C80000
#define GPIO1_PAD_CTRL_BASE	(GPIO0_PAD_CTRL_BASE + 0x100)
#define SSO_BASE		0x16d00000

#define GPIO_FUNCTION_OUT	0x0
#define GPIO_FUNCTION_IN	0x4
#define GPIO_FUNCTION_DIR	0x8
#define GPIO_FUNCTION_OUTSET	0x40
#define GPIO_FUNCTION_OUTCLR	0x44
#define GPIO_FUNCTION_DIRSET	0x48
#define GPIO_FUNCTION_DIRCLR	0x4c

#define GPIO_PAD_CTRL_PORTMUX(pin) (pin << 2)
#define GPIO_PAD_CTRL_PUEN	0x80
#define GPIO_PAD_CTRL_PDEN	0x84
#define GPIO_PAD_CTRL_OD	0x94

#define SSO_GPIO_BASE		64
#define SSO_GPIO_PER_REG	8
#if CONFIG_LANTIQ_SSO_SHR_COUNT > 1
#define SSO_GPIO_COUNT		(CONFIG_LANTIQ_SSO_SHR_COUNT * SSO_GPIO_PER_REG)
#else
#define SSO_GPIO_COUNT		0
#endif
#define SSO_GPIO_MAX		32

#define SSO_LED_BLINK_HB_0	0x0
#define SSO_LED_BLINK_HB_1	0x4
#define SSO_DUTY_CYCLE(pin)	(0x8 + pin * 4)
#define SSO_CON0		0x2b0
#define SSO_CON1		0x2b4
#define SSO_CPU0		0x2b8
#define SSO_CPU1		0x2bc
#define SSO_AR			0x2c0
#define SSO_CON2		0x2c4
#define SSO_CON3		0x2c8

#define SSO_CON0_SWU		BIT(31)
#define SSO_CON0_RZFL		BIT(26)

#if CONFIG_LANTIQ_SSO_SHR_COUNT > 1
#define SSO_CON1_GROUP		GENMASK(CONFIG_LANTIQ_SSO_SHR_COUNT - 1, 0)
#else
#define SSO_CON1_GROUP		0
#endif
#define SSO_CON1_FCDSC_25	0
#define SSO_CON1_FCDSC_12_5	BIT(20)
#define SSO_CON1_FCDSC_6_25	BIT(21)
#define SSO_CON1_FCDSC_3_125	GENMASK(21, 20)
#define SSO_CON1_FPID_2		0
#define SSO_CON1_FPID_4		BIT(23)
#define SSO_CON1_FPID_8		BIT(24)
#define SSO_CON1_FPID_10	GENMASK(24, 23)
#define SSO_CON1_US_SW		0
#define SSO_CON1_US_GPT2	BIT(30)
#define SSO_CON1_US_FPID	BIT(31)

#define CGU_BASE		0x16200000
#define CGU_CLKGCR1_A		0x124
#define CGU_CLKGCR1_A_SSO	BIT(11)

static u32 gpio_requested[GPIO_BANK_NUM];

static inline unsigned int gpio_to_bank(unsigned int gpio)
{
	return gpio < GPIO_BANK_SIZE ? 0 : 1;
}

static inline unsigned int gpio_to_pin(unsigned int gpio)
{
	return gpio < GPIO_BANK_SIZE ? gpio : gpio - GPIO_BANK_SIZE;
}

static inline unsigned int sso_gpio_to_pin(unsigned int gpio)
{
	return gpio - SSO_GPIO_BASE;
}

static inline void __iomem *gpio_function_base(unsigned int gpio)
{
	if (gpio < GPIO_BANK_SIZE)
		return (void __iomem *)CKSEG1ADDR(GPIO0_FUNCTION_BASE);
	else
		return (void __iomem *)CKSEG1ADDR(GPIO1_FUNCTION_BASE);
}

static inline void __iomem *gpio_pad_ctrl_base(unsigned int gpio)
{
	if (gpio < GPIO_BANK_SIZE)
		return (void __iomem *)CKSEG1ADDR(GPIO0_PAD_CTRL_BASE);
	else
		return (void __iomem *)CKSEG1ADDR(GPIO1_PAD_CTRL_BASE);
}

static inline void __iomem *sso_base(void)
{
	return (void __iomem *)CKSEG1ADDR(SSO_BASE);
}

static inline bool gpio_pin_isset(const void *addr, unsigned int pin)
{
	const u32 val = readl(addr);

	return !!(val & BIT(pin));
}

static inline bool is_sso_enabled(void)
{
	return CONFIG_LANTIQ_SSO_SHR_COUNT > 0;
}

static inline bool is_gpio_sso(unsigned int gpio)
{
	return is_sso_enabled() && (gpio >= SSO_GPIO_BASE) &&
		(gpio < SSO_GPIO_BASE + SSO_GPIO_COUNT);
}

static inline bool sso_pin_isset(unsigned int pin)
{
	void __iomem *sso = sso_base();
	const u32 val = readl(sso + SSO_CPU0);

	return !!(val & BIT(pin));
}

/* TODO: move to clock driver */
static inline void ltq_sso_clk_init(void)
{
	void *cgu_base = (void *)CKSEG1ADDR(CGU_BASE);

	setbits_32(cgu_base + CGU_CLKGCR1_A, CGU_CLKGCR1_A_SSO);
}

void ltq_gpio_init(u32 sso_init_value)
{
	void __iomem *sso = sso_base();
	int i;

	if (is_sso_enabled()) {
		ltq_sso_clk_init();

		writel(0, sso + SSO_AR);
		writel(0, sso + SSO_CPU1);
		writel(sso_init_value, sso + SSO_CPU0);

		for (i = 0; i < SSO_GPIO_MAX; i++)
			writel(0xff, sso + SSO_DUTY_CYCLE(i));

		writel(SSO_CON0_RZFL, sso + SSO_CON0);
		writel(SSO_CON1_US_FPID | SSO_CON1_FPID_8 | SSO_CON1_FCDSC_12_5 | SSO_CON1_GROUP,
			sso + SSO_CON1);
	}
}

void ltq_gpio_dump(void)
{
	unsigned int gpio;

	puts("GPIO MUX DIR OUT IN  PU  PD  OD\n");

	for (gpio = 0; gpio < GPIO_BANK_NUM * GPIO_BANK_SIZE; gpio++) {
		const unsigned int pin = gpio_to_pin(gpio);
		void __iomem *gpio_function = gpio_function_base(gpio);
		void __iomem *gpio_pad_ctrl = gpio_pad_ctrl_base(gpio);
		const unsigned int mux = readl(gpio_pad_ctrl + GPIO_PAD_CTRL_PORTMUX(pin)) & 0x7;

		printf(" %2d %3u %3d %3d %3d %3d %3d %3d\n",
			gpio, mux,
			gpio_pin_isset(gpio_function + GPIO_FUNCTION_DIR, pin),
			gpio_pin_isset(gpio_function + GPIO_FUNCTION_OUT, pin),
			gpio_pin_isset(gpio_function + GPIO_FUNCTION_IN, pin),
			gpio_pin_isset(gpio_pad_ctrl + GPIO_PAD_CTRL_PUEN, pin),
			gpio_pin_isset(gpio_pad_ctrl + GPIO_PAD_CTRL_PDEN, pin),
			gpio_pin_isset(gpio_pad_ctrl + GPIO_PAD_CTRL_OD, pin));
	}

	if (!is_sso_enabled())
		return;

	puts("GPIO SSO OUT\n");

	for (gpio = 0; gpio < SSO_GPIO_COUNT; gpio++)
		printf(" %2d %3u %3u\n", gpio + SSO_GPIO_BASE, gpio, sso_pin_isset(gpio));
}

int gpio_request(unsigned gpio, const char *label)
{
	const unsigned int bank = gpio_to_bank(gpio);
	const unsigned int pin = gpio_to_pin(gpio);

	debug("%s: gpio %u, label %s\n", __func__, gpio, label);

	if (is_gpio_sso(gpio))
		return 0;

	if (test_and_set_bit(pin, &gpio_requested[bank])) {
		printf("GPIO %u already requested\n", gpio);
		return -EBUSY;
	}

	return 0;
}

int gpio_free(unsigned gpio)
{
	const unsigned int bank = gpio_to_bank(gpio);
	const unsigned int pin = gpio_to_pin(gpio);

	if (is_gpio_sso(gpio))
		return 0;

	clear_bit(pin, &gpio_requested[bank]);
	return 0;
}

int gpio_direction_input(unsigned gpio)
{
	void __iomem *gpio_function = gpio_function_base(gpio);
	void __iomem *gpio_pad_ctrl = gpio_pad_ctrl_base(gpio);
	const unsigned int pin = gpio_to_pin(gpio);

	if (is_gpio_sso(gpio))
		return 0;

	writel(0, gpio_pad_ctrl + GPIO_PAD_CTRL_PORTMUX(pin));
	writel(BIT(pin), gpio_function + GPIO_FUNCTION_DIRCLR);

	return 0;
}

int gpio_direction_output(unsigned gpio, int value)
{
	void __iomem *gpio_function = gpio_function_base(gpio);
	void __iomem *gpio_pad_ctrl = gpio_pad_ctrl_base(gpio);
	void __iomem *sso = sso_base();
	unsigned int pin;

	if (is_gpio_sso(gpio)) {
		pin = sso_gpio_to_pin(gpio);
		if (value)
			setbits_32(sso + SSO_CPU0, BIT(pin));
		else
			clrbits_32(sso + SSO_CPU0, BIT(pin));
	} else {
		pin = gpio_to_pin(gpio);

		writel(0, gpio_pad_ctrl + GPIO_PAD_CTRL_PORTMUX(pin));
		writel(BIT(pin), gpio_function + GPIO_FUNCTION_DIRSET);

		if (value)
			writel(BIT(pin), gpio_function + GPIO_FUNCTION_OUTSET);
		else
			writel(BIT(pin), gpio_function + GPIO_FUNCTION_OUTCLR);
	}

	return 0;
}

int gpio_get_value(unsigned gpio)
{
	void __iomem *gpio_function = gpio_function_base(gpio);
	void __iomem *sso = sso_base();
	unsigned int pin;
	u32 val;

	if (is_gpio_sso(gpio)) {
		val = readl(sso + SSO_CPU0);
		pin = sso_gpio_to_pin(gpio);
	} else {
		val = readl(gpio_function + GPIO_FUNCTION_IN);
		pin = gpio_to_pin(gpio);
	}

	return !!(val & BIT(pin));
}

int gpio_set_value(unsigned gpio, int value)
{
	void __iomem *gpio_function = gpio_function_base(gpio);
	void __iomem *sso = sso_base();
	unsigned int pin;

	if (is_gpio_sso(gpio)) {
		pin = sso_gpio_to_pin(gpio);
		if (value)
			setbits_32(sso + SSO_CPU0, BIT(pin));
		else
			clrbits_32(sso + SSO_CPU0, BIT(pin));
	} else {
		pin = gpio_to_pin(gpio);
		if (value)
			writel(BIT(pin), gpio_function + GPIO_FUNCTION_OUTSET);
		else
			writel(BIT(pin), gpio_function + GPIO_FUNCTION_OUTCLR);
	}

	return 0;
}

void ltq_gpio_mux(unsigned gpio, unsigned int func, unsigned int dir)
{
	void __iomem *gpio_function = gpio_function_base(gpio);
	void __iomem *gpio_pad_ctrl = gpio_pad_ctrl_base(gpio);
	const unsigned int pin = gpio_to_pin(gpio);

	if (is_gpio_sso(gpio))
		return;

	writel(func, gpio_pad_ctrl + GPIO_PAD_CTRL_PORTMUX(pin));

	if (dir)
		writel(BIT(pin), gpio_function + GPIO_FUNCTION_DIRSET);
	else
		writel(BIT(pin), gpio_function + GPIO_FUNCTION_DIRCLR);
}
