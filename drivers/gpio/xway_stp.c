// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <errno.h>
#include <common.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/io.h>

struct xway_stp {
	u32	clc;
};

struct xway_stp_hw {
	unsigned int bank_cnt;
	unsigned int gpio_per_bank;
};

struct xway_stp_priv {
	struct xway_stp *regs;
	const struct xway_stp_hw *hw;
};

static int xway_stp_get_value(struct udevice *dev, unsigned offset)
{
	struct xway_stp_priv __maybe_unused *priv = dev_get_priv(dev);

	return 0;
}

static int xway_stp_set_value(struct udevice *dev, unsigned offset,
				 int value)
{
	struct xway_stp_priv __maybe_unused *priv = dev_get_priv(dev);

	return 0;
}

static int xway_stp_direction_input(struct udevice *dev, unsigned offset)
{
	struct xway_stp_priv __maybe_unused *priv = dev_get_priv(dev);

	return 0;
}

static int xway_stp_direction_output(struct udevice *dev,
				       unsigned offset, int value)
{
	struct xway_stp_priv __maybe_unused *priv = dev_get_priv(dev);

	return 0;
}

static int xway_stp_get_function(struct udevice *dev, unsigned offset)
{
	int ret = GPIOF_UNUSED;

	return ret;
}

static const struct xway_stp_hw xway_stp_danube = {
	.bank_cnt = 3, .gpio_per_bank = 16,
};

static const struct xway_stp_hw xway_stp_grx330 = {
	.bank_cnt = 4, .gpio_per_bank = 16,
};

static const struct xway_stp_hw xway_stp_vrx200 = {
	.bank_cnt = 4, .gpio_per_bank = 16,
};

static const struct udevice_id xway_stp_of_match[] = {
	{
		.compatible = "intel,danube-stp",
		.data = (ulong)&xway_stp_danube,
	}, {
		.compatible = "intel,grx330-stp",
		.data = (ulong)&xway_stp_grx330,
	}, {
		.compatible = "intel,vrx200-stp",
		.data = (ulong)&xway_stp_vrx200,
	},
	{ /* sentinel */ }
};

static const struct dm_gpio_ops xway_stp_ops = {
	.direction_input	= xway_stp_direction_input,
	.direction_output	= xway_stp_direction_output,
	.get_value		= xway_stp_get_value,
	.set_value		= xway_stp_set_value,
	.get_function		= xway_stp_get_function,
};

static int xway_stp_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	struct xway_stp_priv *priv = dev_get_priv(dev);
	const struct xway_stp_hw *hw =
		(const struct xway_stp_hw *)dev_get_driver_data(dev);

	priv->regs = dev_remap_addr(dev);
	priv->hw = hw;

	uc_priv->gpio_count = hw->bank_cnt * hw->gpio_per_bank;
	uc_priv->bank_name = "STP";

	return 0;
}

U_BOOT_DRIVER(xway_stp) = {
	.name = "intel-xway-stp",
	.id = UCLASS_GPIO,
	.of_match = xway_stp_of_match,
	.probe = xway_stp_probe,
	.priv_auto_alloc_size = sizeof(struct xway_stp_priv),
	.ops = &xway_stp_ops,
};
