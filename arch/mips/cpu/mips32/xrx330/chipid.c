/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/lantiq/io.h>
#include <asm/lantiq/chipid.h>
#include <asm/lantiq/clk.h>
#include <asm/lantiq/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/nand.h>

#define CHIPID_VERSION_SHIFT	28
#define CHIPID_VERSION_MASK	(0x7 << CHIPID_VERSION_SHIFT)
#define CHIPID_PNUM_SHIFT	12
#define CHIPID_PNUM_MASK	(0xFFFF << CHIPID_PNUM_SHIFT)
#define ID_CFG_FUSE_720		(1 << 17)

struct ltq_chipid_regs {
	u32	manid;		/* Manufacturer identification */
	u32	chipid;		/* Chip identification */
	u32	rsvd[2];
	u32	id_cfg;
};

static struct ltq_chipid_regs *ltq_chipid_regs =
	(struct ltq_chipid_regs *) CKSEG1ADDR(LTQ_CHIPID_BASE);

unsigned int ltq_chip_version_get(void)
{
	u32 chipid = ltq_readl(&ltq_chipid_regs->chipid);

	return (chipid & CHIPID_VERSION_MASK) >> CHIPID_VERSION_SHIFT;
}

unsigned int ltq_chip_partnum_get(void)
{
	u32 chipid = ltq_readl(&ltq_chipid_regs->chipid);

	return (chipid & CHIPID_PNUM_MASK) >> CHIPID_PNUM_SHIFT;
}

const char *ltq_chip_partnum_str(void)
{
	enum ltq_chip_partnum partnum = ltq_chip_partnum_get();

	switch (partnum) {
	case LTQ_SOC_GRX387:
		return "GRX387";
	case LTQ_SOC_GRX369:
		return "GRX369";
	case LTQ_SOC_GRX389:
		return "GRX389";
	default:
		printf("Unknown partnum: %x\n", partnum);
	}

	return "";
}

int ltq_soc_is_grx389_720(void)
{
	u32 id_cfg = ltq_readl(&ltq_chipid_regs->id_cfg);

	return !(id_cfg & ID_CFG_FUSE_720);
}

void ltq_chip_print_info(void)
{
	char buf[32];
	const enum ltq_boot_select bootsel = ltq_boot_select();
	const char *bootsel_str = ltq_boot_select_str();
	unsigned int hsnand_strap;

	printf("SoC:   Lantiq %s v1.%u%s\n", ltq_chip_partnum_str(),
		ltq_chip_version_get(),
		ltq_soc_is_grx389_720() ? " (720 MHz)" : "");
	printf("CPU:   %s MHz\n", strmhz(buf, ltq_get_cpu_clock()));
	printf("IO:    %s MHz\n", strmhz(buf, ltq_get_io_region_clock()));
	printf("BUS:   %s MHz\n", strmhz(buf, ltq_get_bus_clock()));

	switch (bootsel) {
	case BOOT_HSNAND_SAMSUNG_2K:
	case BOOT_HSNAND_SAMSUNG_1K:
	case BOOT_HSNAND_ONFI:
		hsnand_strap = ltq_boot_hsnand_info();
		printf("BOOT:  %s, ECC %s %s %s, %s\n", bootsel_str,
			hsnand_strap & HSNAND_ECC_OFF ? "off" : "on",
			hsnand_strap & HSNAND_ECC_4BYTE ? "4B" : "3B",
			hsnand_strap & HSNAND_ECC_NO_OOB ? "IB" : "OOB",
			hsnand_strap & HSNAND_BIG_ENDIAN ? "BE" : "LE");
		break;
	default:
		printf("BOOT:  %s\n", bootsel_str);
	}
}
