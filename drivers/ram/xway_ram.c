// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016-2020 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <errno.h>
#include <common.h>
#include <dm.h>
#include <ram.h>
#include <asm/io.h>

struct xway_ram_hw {
	unsigned int dummy;
};

struct xway_ram_priv {
	void __iomem *global_regs;
	void __iomem *core_regs;
	const struct xway_ram_hw *hw;
};

static int xway_ram_get_info(struct udevice *dev, struct ram_info *info)
{
	info->base = 0x80000000;
	info->size = 128 * 1024 * 1024;
	return 0;
}

static const struct xway_ram_hw xway_ram_danube = {
	.dummy = 0
};

static const struct xway_ram_hw xway_ram_grx330 = {
	.dummy = 0
};

static const struct xway_ram_hw xway_ram_vrx200 = {
	.dummy = 0
};

static const struct udevice_id xway_ram_of_match[] = {
	{
		.compatible = "intel,danube-mc",
		.data = (ulong)&xway_ram_danube,
	}, {
		.compatible = "intel,grx330-mc",
		.data = (ulong)&xway_ram_grx330,
	}, {
		.compatible = "intel,vrx200-mc",
		.data = (ulong)&xway_ram_vrx200,
	},
	{ /* sentinel */ }
};

static const struct ram_ops xway_ram_ops = {
	.get_info	= xway_ram_get_info,
};

static int xway_ram_probe(struct udevice *dev)
{
	struct xway_ram_priv *priv = dev_get_priv(dev);
	const struct xway_ram_hw *hw =
		(const struct xway_ram_hw *)dev_get_driver_data(dev);

	priv->global_regs = dev_remap_addr_index(dev, 0);
	priv->core_regs = dev_remap_addr_index(dev, 1);
	priv->hw = hw;

	return 0;
}

U_BOOT_DRIVER(xway_ram) = {
	.name = "intel-xway-mc",
	.id = UCLASS_RAM,
	.of_match = xway_ram_of_match,
	.probe = xway_ram_probe,
	.priv_auto_alloc_size = sizeof(struct xway_ram_priv),
	.ops = &xway_ram_ops,
};
