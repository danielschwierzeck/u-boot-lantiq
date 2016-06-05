// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016-2020 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
 */

#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <asm/io.h>
#include <dt-bindings/clock/intel,xway.h>

struct xway_clk_priv;

struct xway_clk_hw {
	ulong (*get_cpu_clk)(struct xway_clk_priv *);
	ulong (*get_ddr_clk)(struct xway_clk_priv *);
};

struct xway_clk_priv {
	void __iomem *regs;
	const struct xway_clk_hw *hw;
};

static ulong danube_get_cpu_clk(struct xway_clk_priv *priv)
{
	return 333333333;
}

static ulong danube_get_ddr_clk(struct xway_clk_priv *priv)
{
	return 166666666;
}

static ulong vrx200_get_cpu_clk(struct xway_clk_priv *priv)
{
	return 500000000;
}

static ulong vrx200_get_ddr_clk(struct xway_clk_priv *priv)
{
	return 250000000;
}

static ulong grx330_get_cpu_clk(struct xway_clk_priv *priv)
{
	return 720000000;
}

static ulong grx330_get_ddr_clk(struct xway_clk_priv *priv)
{
	return 360000000;
}

static ulong xway_clk_get_rate(struct clk *clk)
{
	struct xway_clk_priv *priv = dev_get_priv(clk->dev);
	const struct xway_clk_hw *hw = priv->hw;
	ulong rate;

	switch (clk->id) {
	case XWAY_CLK_CPU:
		rate = hw->get_cpu_clk(priv);
		break;
	case XWAY_CLK_DDR:
	case XWAY_CLK_ASC:
		rate = hw->get_ddr_clk(priv);
		break;
	default:
		rate = 0;
		break;
	}

	return rate;
}

static struct clk_ops xway_clk_ops = {
	.get_rate = xway_clk_get_rate,
};

static const struct xway_clk_hw xway_clk_danube = {
	.get_cpu_clk = danube_get_cpu_clk,
	.get_ddr_clk = danube_get_ddr_clk,
};

static const struct xway_clk_hw xway_clk_vrx200 = {
	.get_cpu_clk = vrx200_get_cpu_clk,
	.get_ddr_clk = vrx200_get_ddr_clk,
};

static const struct xway_clk_hw xway_clk_grx330 = {
	.get_cpu_clk = grx330_get_cpu_clk,
	.get_ddr_clk = grx330_get_ddr_clk,
};

static const struct udevice_id xway_clk_of_match[] = {
	{
		.compatible = "intel,danube-cgu",
		.data = (ulong)&xway_clk_danube,
	}, {
		.compatible = "intel,grx330-cgu",
		.data = (ulong)&xway_clk_grx330,
	}, {
		.compatible = "intel,vrx200-cgu",
		.data = (ulong)&xway_clk_vrx200,
	},
	{ /* sentinel */ }
};

static int xway_clk_probe(struct udevice *dev)
{
	struct xway_clk_priv *priv = dev_get_priv(dev);
	const struct xway_clk_hw *hw =
		(const struct xway_clk_hw *)dev_get_driver_data(dev);

	priv->regs = dev_remap_addr(dev);
	priv->hw = hw;

	return 0;
}

U_BOOT_DRIVER(xway_clk) = {
	.name = "intel-xway-clk",
	.id = UCLASS_CLK,
	.of_match = xway_clk_of_match,
	.ops = &xway_clk_ops,
	.probe = xway_clk_probe,
	.priv_auto_alloc_size = sizeof(struct xway_clk_priv),
};
