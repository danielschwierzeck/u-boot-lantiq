/*
 * Copyright (C) 2012 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/chipid.h>
#include <asm/arch/soc.h>

#define LTQ_CHIPID_VERSION_SHIFT	28
#define LTQ_CHIPID_VERSION_MASK		(0xF << LTQ_CHIPID_VERSION_SHIFT)
#define LTQ_CHIPID_PNUM_SHIFT		12
#define LTQ_CHIPID_PNUM_MASK		(0xFFFF << LTQ_CHIPID_PNUM_SHIFT)

struct ltq_chipid_regs {
	u32	manid;		/* Manufacturer identification */
	u32	chipid;		/* Chip identification */
};

static struct ltq_chipid_regs *ltq_chipid_regs =
	(struct ltq_chipid_regs *) CKSEG1ADDR(LTQ_CHIPID_BASE);

unsigned int ltq_chip_version_get(void)
{
	u32 chipid;

	chipid = ltq_readl(&ltq_chipid_regs->chipid);

	return (chipid & LTQ_CHIPID_VERSION_MASK) >> LTQ_CHIPID_VERSION_SHIFT;
}

unsigned int ltq_chip_partnum_get(void)
{
	u32 chipid;

	chipid = ltq_readl(&ltq_chipid_regs->chipid);

	return (chipid & LTQ_CHIPID_PNUM_MASK) >> LTQ_CHIPID_PNUM_SHIFT;
}

const char *ltq_chip_partnum_str(void)
{
	enum ltq_chip_partnum partnum = ltq_chip_partnum_get();

	switch (partnum) {
	case LTQ_SOC_ARX188:
		return "ARX188";
	case LTQ_SOC_ARX186:
	case LTQ_SOC_ARX186_2:
		return "ARX186";
	case LTQ_SOC_ARX182:
		return "ARX182";
	default:
		printf("Unknown partnum: %x\n", partnum);
	}

	return "";
}
