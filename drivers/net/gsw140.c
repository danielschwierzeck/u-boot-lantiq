// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2021 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <asm/io.h>
#include <asm/mipsregs.h>
#include <asm/gpio.h>
#include <mach/gsw140.h>

#define GSW_TOP_R_BASE		0x1a003c00
#define CHIPTOP_BASE		0x16080000

#define IFMUX_CFG		0x120
#define IFMUX_CFG_BB_SPI_EN	BIT(18)
#define IFMUX_CFG_PHY6F_SEL	BIT(20)

#define GSW_GLOB_CTRL		0x00
#define GSW_MDIO_CTRL		0x10
#define GSW_MDIO_READ		0x14
#define GSW_MDIO_WRITE		0x18
#define GSW_MDC_CFG_0		0x1c
#define GSW_MDC_CFG_1		0x20

#define GLOB_CTRL_SE		BIT(15)
#define MDIO_CTRL_WRITE		BIT(10)
#define MDIO_CTRL_READ		BIT(11)
#define MDIO_CTRL_MBUSY		BIT(12)

#define MDC_CFG_RST		BIT(15)
#define MDC_CFG_MCEN		BIT(8)
#define MDC_CFG_25MHZ		0

#define GSW140_GPIO_OUT		0xf380
#define GSW140_GPIO_IN		0xf381
#define GSW140_GPIO_DIR		0xf382
#define GSW140_GPIO_ALT0	0xf383
#define GSW140_GPIO_ALT1	0xf384
#define GSW140_GPIO_OD		0xf385
#define GSW140_GPIO_PUDSEL	0xf386
#define GSW140_GPIO_PUDEN	0xf387
#define GSW140_GPIO2_OUT	0xf390
#define GSW140_GPIO2_IN		0xf391
#define GSW140_GPIO2_DIR	0xf392
#define GSW140_GPIO2_ALT0	0xf393
#define GSW140_GPIO2_ALT1	0xf394
#define GSW140_GPIO2_OD		0xf395
#define GSW140_GPIO2_PUDSEL	0xf396
#define GSW140_GPIO2_PUDEN	0xf397
#define GSW140_MANU_ID		0xfa10
#define GSW140_GPIO_DRIVE0_CFG	0xfa70
#define GSW140_GPIO_DRIVE1_CFG	0xfa71
#define GSW140_GPIO2_DRIVE0_CFG	0xfa74
#define GSW140_GPIO2_DRIVE1_CFG	0xfa75

#define GSW140_GPIO_MASK	0x3fff
#define GSW140_GPIO2_MASK	0x7fff

#define GSW140_PHY_ADDR		0x1f
#define GSW140_MMD_ADDR		0x1f

#define GSW140_GPIO_SFP_LOS		0
#define GSW140_GPIO_SFP_MOD_DEF0	1
#define GSW140_GPIO_SFP_TX_FAULT	2
#define GSW140_GPIO_SFP_TX_DISABLE	17
#define GSW140_GPIO_SFP_RATESELECT0	6
#define GSW140_GPIO_SFP_RATESELECT1	20
#define GSW140_GPIO_MDC			4
#define GSW140_GPIO_MDIO		5
#define GSW140_GPIO_WANOE_LED		22

static inline void __iomem *gswr_top_base(void)
{
	return (void __iomem *)CKSEG1ADDR(GSW_TOP_R_BASE);
}

static inline void __iomem *chiptop_base(void)
{
	return (void __iomem *)CKSEG1ADDR(CHIPTOP_BASE);
}

static inline bool gswr_mdio_is_busy(void)
{
	return readl(gswr_top_base() + GSW_MDIO_CTRL) & MDIO_CTRL_MBUSY;
}

static inline void gswr_mdio_poll(void)
{
	while (gswr_mdio_is_busy())
		cpu_relax();
}

static unsigned int gswr_mdio_read(int phyaddr, int regaddr)
{
	unsigned int retval;

	gswr_mdio_poll();
	writel(MDIO_CTRL_READ | (phyaddr << 5) | regaddr, gswr_top_base() + GSW_MDIO_CTRL);
	mdelay(10);
	retval = readl(gswr_top_base() + GSW_MDIO_READ);

	debug("%s: phyaddr %x, regad %x, val %x\n", __func__, phyaddr, regaddr, retval);

	return retval;
}

static void gswr_mdio_write(int phyaddr, int regaddr, u16 val)
{
	debug("%s: phyad %x, regad %x, val %x\n", __func__, phyaddr, regaddr, val);

	gswr_mdio_poll();
	writel(val, gswr_top_base() + GSW_MDIO_WRITE);
	writel(MDIO_CTRL_WRITE | (phyaddr << 5) | regaddr, gswr_top_base() + GSW_MDIO_CTRL);
	gswr_mdio_poll();
}

static inline u16 gsw140_gpio_bit(unsigned int gpio)
{
	const unsigned int pin = (gpio > 15) ? gpio - 16 : gpio;
	return BIT(pin);
}

static inline u16 gsw140_reg_read(u16 regaddr)
{
	gswr_mdio_write(GSW140_PHY_ADDR, GSW140_MMD_ADDR, regaddr);
	return gswr_mdio_read(GSW140_PHY_ADDR, 0);
}

static inline void gsw140_reg_write(u16 regaddr, u16 val)
{
	gswr_mdio_write(GSW140_PHY_ADDR, GSW140_MMD_ADDR, regaddr);
	gswr_mdio_write(GSW140_PHY_ADDR, 0, val);
}

static inline void gsw140_reg_mask(u16 regaddr, u16 clr, u16 set)
{
	u16 val;

	gswr_mdio_write(GSW140_PHY_ADDR, GSW140_MMD_ADDR, regaddr);
	val = gswr_mdio_read(GSW140_PHY_ADDR, 0);
	val &= ~clr;
	val |= set;
	gswr_mdio_write(GSW140_PHY_ADDR, GSW140_MMD_ADDR, regaddr);
	gswr_mdio_write(GSW140_PHY_ADDR, 0, val);
}

static void gsw140_hw_init(void)
{
	/* connect xMII6F port to GSWIP-R, disable WLAN SPI debug */
	clrsetbits_32(chiptop_base() + IFMUX_CFG, IFMUX_CFG_BB_SPI_EN, IFMUX_CFG_PHY6F_SEL);
	/* enable GSIP-R macro */
	writel(GLOB_CTRL_SE, gswr_top_base() + GSW_GLOB_CTRL);
	/* disable MDIO auto-polling */
	writel(0, gswr_top_base() + GSW_MDC_CFG_0);
	/* init MDIO interface */
	writel(MDC_CFG_RST, gswr_top_base() + GSW_MDC_CFG_1);
	udelay(100);
	writel(MDC_CFG_MCEN | MDC_CFG_25MHZ, gswr_top_base() + GSW_MDC_CFG_1);
}

void gsw140_gpio_init(void)
{
	gsw140_hw_init();

	/**
	 * - MDC/MDIO muxed to slave MDIO controller, input
	 * - WANoE LED muxed to PHY control, push-pull
	 * - SFP los is GPIO input, active-high
	 * - SFP mod-def0 is GPIO input, active-low
	 * - SFP tx-fault is GPIO input, active-high
	 * - SFP rate-select0 is GPIO output, push-pull, active-high, drive high, drive strength 2mA
	 * - SFP rate-select1 is GPIO output, push-pull, active-high, drive low, drive strength 2mA
	 * - SFP tx-disable is GPIO output, push-pull, active-high, drive high
	 * - all others at reset value
	 */
	gsw140_reg_mask(GSW140_GPIO_OD, 0,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0));

	gsw140_reg_mask(GSW140_GPIO_ALT0,
		gsw140_gpio_bit(GSW140_GPIO_SFP_LOS) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_MOD_DEF0) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_FAULT) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0) |
		gsw140_gpio_bit(GSW140_GPIO_MDC) |
		gsw140_gpio_bit(GSW140_GPIO_MDIO), 0);

	gsw140_reg_mask(GSW140_GPIO_ALT1,
		gsw140_gpio_bit(GSW140_GPIO_SFP_LOS) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_MOD_DEF0) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_FAULT) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0),
		gsw140_gpio_bit(GSW140_GPIO_MDC) |
		gsw140_gpio_bit(GSW140_GPIO_MDIO));

	gsw140_reg_mask(GSW140_GPIO_DRIVE0_CFG,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0), 0);

	gsw140_reg_mask(GSW140_GPIO_DRIVE1_CFG,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0), 0);

	gsw140_reg_mask(GSW140_GPIO_OUT, 0,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0));

	gsw140_reg_mask(GSW140_GPIO_DIR,
		gsw140_gpio_bit(GSW140_GPIO_SFP_LOS) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_MOD_DEF0) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_FAULT),
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT0));

	gsw140_reg_mask(GSW140_GPIO2_OD, 0,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_DISABLE) |
		gsw140_gpio_bit(GSW140_GPIO_WANOE_LED));

	gsw140_reg_mask(GSW140_GPIO2_ALT0,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_DISABLE),
		gsw140_gpio_bit(GSW140_GPIO_WANOE_LED));

	gsw140_reg_mask(GSW140_GPIO2_ALT1,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_DISABLE) |
		gsw140_gpio_bit(GSW140_GPIO_WANOE_LED), 0);

	gsw140_reg_mask(GSW140_GPIO2_OUT,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1),
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_DISABLE));

	gsw140_reg_mask(GSW140_GPIO2_DRIVE0_CFG,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1), 0);

	gsw140_reg_mask(GSW140_GPIO2_DRIVE1_CFG,
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1), 0);

	gsw140_reg_mask(GSW140_GPIO2_DIR, 0,
		gsw140_gpio_bit(GSW140_GPIO_WANOE_LED) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_RATESELECT1) |
		gsw140_gpio_bit(GSW140_GPIO_SFP_TX_DISABLE));
}

static int gsw140_cmd_read(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long addr, ret;

	if (argc != 2)
		return CMD_RET_USAGE;

	if (strict_strtoul(argv[1], 16, &addr) < 0)
		return CMD_RET_USAGE;

	ret = gsw140_reg_read(addr);
	printf("%lx = %lx\n", addr, ret);

	return 0;
}

static int gsw140_cmd_write(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long addr, val;

	if (argc != 3)
		return CMD_RET_USAGE;

	if (strict_strtoul(argv[1], 16, &addr) < 0)
		return CMD_RET_USAGE;

	if (strict_strtoul(argv[2], 16, &val) < 0)
		return CMD_RET_USAGE;

	gsw140_reg_write(addr, val);
	printf("%lx = %lx\n", addr, val);

	return 0;
}

static int gsw140_cmd_dump(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	#define print_reg(reg) printf("%-24s: 0x%04x\n", #reg, gsw140_reg_read(reg));

	print_reg(GSW140_MANU_ID);
	print_reg(GSW140_GPIO_OUT);
	print_reg(GSW140_GPIO_DIR);
	print_reg(GSW140_GPIO_ALT0);
	print_reg(GSW140_GPIO_ALT1);
	print_reg(GSW140_GPIO_OD);
	print_reg(GSW140_GPIO_PUDSEL);
	print_reg(GSW140_GPIO_PUDEN);
	print_reg(GSW140_GPIO_DRIVE0_CFG);
	print_reg(GSW140_GPIO_DRIVE1_CFG);
	print_reg(GSW140_GPIO2_OUT);
	print_reg(GSW140_GPIO2_DIR);
	print_reg(GSW140_GPIO2_ALT0);
	print_reg(GSW140_GPIO2_ALT1);
	print_reg(GSW140_GPIO2_OD);
	print_reg(GSW140_GPIO2_PUDSEL);
	print_reg(GSW140_GPIO2_PUDEN);
	print_reg(GSW140_GPIO2_DRIVE0_CFG);
	print_reg(GSW140_GPIO2_DRIVE1_CFG);

	return 0;
}

static cmd_tbl_t cmd_gsw140_sub[] = {
	U_BOOT_CMD_MKENT(read, 2, 0, gsw140_cmd_read, "", ""),
	U_BOOT_CMD_MKENT(write, 2, 0, gsw140_cmd_write, "", ""),
	U_BOOT_CMD_MKENT(dump, 2, 0, gsw140_cmd_dump, "", ""),
};

static int gsw140_cmd(cmd_tbl_t * cmdtp, int flag, int argc, char *const argv[])
{
	cmd_tbl_t *cp;

	/* need at least two arguments */
	if (argc < 2)
		return CMD_RET_USAGE;

	/* drop initial "sas_etl" arg */
	argc--;
	argv++;

	cp = find_cmd_tbl(argv[0], cmd_gsw140_sub, ARRAY_SIZE(cmd_gsw140_sub));
	if (!cp)
		return CMD_RET_USAGE;

	return cp->cmd(cmdtp, flag, argc, argv);
}

U_BOOT_CMD(gsw140, CONFIG_SYS_MAXARGS, 0, gsw140_cmd,
	"GSW140 commands",
	"read <addr> - read register\n"
	"gsw140 write <addr> <val> - write register\n"
	"gsw140 dump - dump registers\n"
);
