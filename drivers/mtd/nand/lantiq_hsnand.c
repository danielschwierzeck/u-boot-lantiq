// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2015-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <nand.h>
#include <memalign.h>
#include <wait_bit.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <mach/dma.h>

#define EBU_BASE		0x16f00000
#define EBU_REGION0_BASE	0x17400000
#define EBU_REGION1_BASE	0x17c00000
#define NAND_BASE		(EBU_BASE + 0xb0)
#define HSNAND_BASE		0x17000000

#define NAND_CON_ECC_ON		BIT(31)
#define NAND_CON_LATCH_PRE	BIT(23)
#define NAND_CON_LATCH_WP	BIT(22)
#define NAND_CON_LATCH_SE	BIT(21)
#define NAND_CON_LATCH_CS	BIT(20)
#define NAND_CON_LATCH_CLE	BIT(19)
#define NAND_CON_LATCH_ALE	BIT(18)
#define NAND_CON_OUT_CS_MASK	(0x3 << 10)
#define NAND_CON_OUT_CS(cs)	(((cs) & 0x3) << 10)
#define NAND_CON_IN_CS_MASK	(0x3 << 8)
#define NAND_CON_IN_CS(cs)	(((cs) & 0x3) << 8)
#define NAND_CON_PRE_P		BIT(7)
#define NAND_CON_WP_P		BIT(6)
#define NAND_CON_SE_P		BIT(5)
#define NAND_CON_CS_P		BIT(4)
#define NAND_CON_CLE_P		BIT(3)
#define NAND_CON_ALE_P		BIT(2)
#define NAND_CON_CSMUX		BIT(1)
#define NAND_CON_NANDM		BIT(0)
#define NAND_CON_LATCH_ALL	(NAND_CON_LATCH_PRE | NAND_CON_LATCH_WP | \
				NAND_CON_LATCH_SE | NAND_CON_LATCH_CS)

#define NAND_WAIT_WR_C		BIT(3)
#define NAND_WAIT_RD_E		BIT(2)
#define NAND_WAIT_BY_E		BIT(1)
#define NAND_WAIT_RDBY		BIT(0)
#define NAND_WAIT_READY		NAND_WAIT_RDBY

#define NAND_CMD_ALE		BIT(2)
#define NAND_CMD_CLE		BIT(3)
#define NAND_CMD_CS		BIT(4)
#define NAND_CMD_SE		BIT(5)
#define NAND_CMD_WP		BIT(6)
#define NAND_CMD_PRE		BIT(7)

#define NDAC_CTL1_ADDR3(x)		(((x) & 0xff) << 24)
#define NDAC_CTL1_ADDR2(x)		(((x) & 0xff) << 16)
#define NDAC_CTL1_ADDR1(x)		(((x) & 0xff) << 8)
#define NDAC_CTL1_CMD(x)		((x) & 0xff)
#define NDAC_CTL1_CMD_READ		0x00
#define NDAC_CTL1_CMD_READ_SAMSUNG	0x60
#define NDAC_CTL1_CMD_WRITE		0x80
#define NDAC_CTL2_CMD2_READ_ONFI	0x00
#define NDAC_CTL2_CMD2_READ_SAMSUNG	0x60
#define NDAC_CTL2_CMD2_WRITE_ONFI	0x80
#define NDAC_CTL2_CMD2_WRITE_SAMSUNG	0x81
#define NDAC_CTL2_CMD_2(x)		(((x) & 0xff) << 19)
#define NDAC_CTL2_ADDR_CYCLE(x)		(((x) - 3) << 16)
#define NDAC_CTL2_ADDR5(x)		(((x) & 0xff) << 8)
#define NDAC_CTL2_ADDR4(x)		((x) & 0xff)
#define INT_AECC_EV			BIT(6)
#define INT_AECC_OD			BIT(5)
#define INT_WR_C			BIT(4)
#define ND_CTL_WRITE			BIT(10)
#define ND_CTL_CE_MASK			(0xf << 3)
#define ND_CTL_CE_SEL(x)		BIT((x + 3))
#define ND_CTL_GO			BIT(2)
#define ND_CTL_MODE_NO_ECC		BIT(1)
#define ND_CTL_DEFAULT			BIT(0)
#define ND_PARA0_TYPE_ONFI		BIT(18)
#define ND_PARA0_PCOUNT(x)		((((x) - 1) & 0xff) << 10)
#define ND_PARA0_PMODE_2PLANE		BIT(9)
#define ND_PARA0_ECC_4BYTE		BIT(8)
#define ND_PARA0_ECC_NO_OOB		BIT(7)
#define ND_PARA0_ECC_ADVANCED		BIT(6)
#define ND_PARA0_PIB_32			(0x0 << 4)
#define ND_PARA0_PIB_64			(0x1 << 4)
#define ND_PARA0_PIB_128		(0x2 << 4)
#define ND_PARA0_PIB_256		(0x3 << 4)
#define ND_PARA0_PAGE_512		0x0
#define ND_PARA0_PAGE_2048		0x1
#define ND_PARA0_PAGE_4096		0x2
#define ND_PARA0_PAGE_8192		0x3

#define EBU_ADDRSEL_MASK(mask)		((mask & 0xf) << 4)
#define EBU_ADDRSEL_REGEN		BIT(0)

#define EBU_CON_WRDIS			BIT(31)
#define EBU_CON_ADSWP			BIT(30)
#define EBU_CON_AGEN_DEMUX		(0x0 << 24)
#define EBU_CON_AGEN_MUX		(0x2 << 24)
#define EBU_CON_SETUP			BIT(22)
#define EBU_CON_WAIT_DIS		(0x0 << 20)
#define EBU_CON_WAIT_ASYNC		(0x1 << 20)
#define EBU_CON_WAIT_SYNC		(0x2 << 20)
#define EBU_CON_WINV			BIT(19)
#define EBU_CON_PW_8BIT			(0x0 << 16)
#define EBU_CON_PW_16BIT		(0x1 << 16)
#define EBU_CON_ALEC(cycles)		((cycles & 0x3) << 14)
#define EBU_CON_BCGEN_CS		(0x0 << 12)
#define EBU_CON_BCGEN_INTEL		(0x1 << 12)
#define EBU_CON_BCGEN_MOTOROLA		(0x2 << 12)
#define EBU_CON_BCGEN_RESERVED		(0x3 << 12)
#define EBU_CON_WAITWRC(cycles)		((cycles & 0x7) << 8)
#define EBU_CON_WAITRDC(cycles)		((cycles & 0x3) << 6)
#define EBU_CON_HOLDC(cycles)		((cycles & 0x3) << 4)
#define EBU_CON_RECOVC(cycles)		((cycles & 0x3) << 2)
#define EBU_CON_CMULT_1			0x0
#define EBU_CON_CMULT_4			0x1
#define EBU_CON_CMULT_8			0x2
#define EBU_CON_CMULT_16		0x3

#define RX_DESC_CNT			2
#define TX_DESC_CNT			2

#define CGU_BASE			0x16200000
#define CGU_CLKGCR1_A			0x124
#define CGU_CLKGCR1_A_EBU		BIT(10)

#define HSNAND_DMA			0

#define simulate_bitflips		0

#if !defined(CONFIG_NAND_LANTIQ_CS0_GPIO_NUM)
#define CONFIG_NAND_LANTIQ_CS0_GPIO_NUM 0
#endif

#if !defined(CONFIG_NAND_LANTIQ_CS1_GPIO_NUM)
#define CONFIG_NAND_LANTIQ_CS1_GPIO_NUM 0
#endif

struct ebu_regs {
	u32	clc;
	u32	rsvd0;
	u32	id;
	u32	rsvd1;
	u32	con;
	u32	rsvd2[3];
	u32	addr_sel_0;
	u32	addr_sel_1;
	u32	rsvd3[14];
	u32	con_0;
	u32	con_1;
};

struct nand_regs {
	u32	con;		/* NAND controller control */
	u32	wait;		/* NAND Flash Device RD/BY State */
	u32	ecc0;		/* NAND Flash ECC Register 0 */
	u32	ecc_ac;		/* NAND Flash ECC Register address counter */
	u32	ecc_cr;		/* NAND Flash ECC Comparison */
};

struct hsnand_regs {
	u32	rsvd0[4];
	u32	ndac_ctl1;	/* HSNAND access control 1 */
	u32	ndac_ctl2;	/* HSNAND access control 2 */
	u32	rsvd1[3];
	u32	int_msk_ctl;	/* Interrupt control */
	u32	int_sta;	/* Interrupt status */
	u32	rsvd2;
	u32	nd_ctl;		/* NAND mode control */
	u32	rsvd3[2];
	u32	nd_para0;	/* NAND parameter config 0 */
	u32	nd_odd_ecc;	/* NAND adv. ECC odd page result */
	u32	nd_odd_ecc1;	/* NAND adv. ECC odd page result 1 */
	u32	nd_even_ecc;	/* NAND adv. ECC even page result */
	u32	nd_even_ecc1;	/* NAND adv. ECC even page result 1 */
	u32	nd_cmsg_0;	/* NAND Customer Message Register */
	u32	nd_cmsg_1;	/* NAND Customer Message Register */
};

struct hsnand_drv {
	struct ltq_dma_device *dma_dev;
	void __iomem *base;
	u8 *readbuf;
	u8 addr_cycles;
	u8 rx_num;
	u8 tx_num;
	u32 pages_per_block;
	int hw_page;
	int hw_cmd;
	int hw_cmd_2;
	int chip_select;
	int chip_select_gpio;
	bool ecc_rs_4byte;
	nand_ecc_modes_t ecc_mode;
	struct nand_ecclayout ecc_layout;
};

static struct hsnand_drv hsnand_drv[CONFIG_SYS_MAX_NAND_DEVICE];
static struct nand_chip hsnand_chip[CONFIG_SYS_MAX_NAND_DEVICE];
static struct ltq_dma_device dma_dev;

static struct ebu_regs *ebu_regs =
	(struct ebu_regs *) CKSEG1ADDR(EBU_BASE);

static struct nand_regs *nand_regs =
	(struct nand_regs *) CKSEG1ADDR(NAND_BASE);

static struct hsnand_regs *hsnand_regs =
	(struct hsnand_regs *) CKSEG1ADDR(HSNAND_BASE);

static const u8 g_num2alpha[256] = {
	0,0,1,99,2,198,100,106,3,205,199,188,101,126,107,42,4,141,206,
	78,200,212,189,225,102,221,127,49,108,32,43,243,5,87,142,232,207,
	172,79,131,201,217,213,65,190,148,226,180,103,39,222,240,128,177,
	50,53,109,69,33,18,44,13,244,56,6,155,88,26,143,121,233,112,208,
	194,173,168,80,117,132,72,202,252,218,138,214,84,66,36,191,152,149,
	249,227,94,181,21,104,97,40,186,223,76,241,47,129,230,178,63,51,
	238,54,16,110,24,70,166,34,136,19,247,45,184,14,61,245,164,57,59,7,
	158,156,157,89,159,27,8,144,9,122,28,234,160,113,90,209,29,195,123,
	174,10,169,145,81,91,118,114,133,161,73,235,203,124,253,196,219,30,
	139,210,215,146,85,170,67,11,37,175,192,115,153,119,150,92,250,82,
	228,236,95,74,182,162,22,134,105,197,98,254,41,125,187,204,224,211,
	77,140,242,31,48,220,130,171,231,86,179,147,64,216,52,176,239,38,
	55,12,17,68,111,120,25,154,71,116,167,193,35,83,137,251,20,93,248,
	151,46,75,185,96,15,237,62,229,246,135,165,23,58,163,60,183
};

static const u8 g_alpha2num[256] = {
	1,2,4,8,16,32,64,128,135,137,149,173,221,61,122,244,111,222,59,118,
	236,95,190,251,113,226,67,134,139,145,165,205,29,58,116,232,87,174,
	219,49,98,196,15,30,60,120,240,103,206,27,54,108,216,55,110,220,63,
	126,252,127,254,123,246,107,214,43,86,172,223,57,114,228,79,158,187,
	241,101,202,19,38,76,152,183,233,85,170,211,33,66,132,143,153,181,
	237,93,186,243,97,194,3,6,12,24,48,96,192,7,14,28,56,112,224,71,142,
	155,177,229,77,154,179,225,69,138,147,161,197,13,26,52,104,208,39,
	78,156,191,249,117,234,83,166,203,17,34,68,136,151,169,213,45,90,
	180,239,89,178,227,65,130,131,129,133,141,157,189,253,125,250,115,
	230,75,150,171,209,37,74,148,175,217,53,106,212,47,94,188,255,121,
	242,99,198,11,22,44,88,176,231,73,146,163,193,5,10,20,40,80,160,
	199,9,18,36,72,144,167,201,21,42,84,168,215,41,82,164,207,25,50,
	100,200,23,46,92,184,247,105,210,35,70,140,159,185,245,109,218,51,
	102,204,31,62,124,248,119,238,91,182,235,81,162,195,1
};

static inline u8 g_mul(u8 arg1, u8 arg2)
{
	u8 s = 0;

	if (!arg1 || !arg2)
		return 0;

	s = (s + g_num2alpha[arg1]) % 255;
	s = (s + g_num2alpha[arg2]) % 255;

	return g_alpha2num[s];
}

static inline u8 g_add(u8 arg3, u8 arg4)
{
	return arg3 ^ arg4;
};

static int hsnand_rs_calculate(struct mtd_info *mtd, const uint8_t *dat,
					uint8_t *ecc_code)
{
	const struct nand_chip *chip = mtd->priv;
	const int ecc_size = chip->ecc.size;
	const int ecc_bytes = chip->ecc.bytes;
	u8 y, g[4], temp[3], s[4] = {0};
	int i;

	if (IS_ENABLED(CONFIG_NAND_LANTIQ_ECC_RS_4)) {
		g[3] = 205;
		g[2] =  63;
		g[1] =  92;
		g[0] =  32;
	} else {
		g[3] = 0;
		g[2] = 14;
		g[1] = 56;
		g[0] = 64;
	}

	for (i = 0; i < ecc_size; i++) {
		y = g_add(s[ecc_bytes - 1], dat[i]);
		temp[0] = g_mul(y, g[3]);
		temp[1] = g_mul(y, g[2]);
		temp[2] = g_mul(y, g[1]);
		s[3] = g_add(s[2], temp[0]);
		s[2] = g_add(s[1], temp[1]);
		s[1] = g_add(s[0], temp[2]);
		s[0] = g_mul(y, g[0]);
	};

	for (i = 0; i < ecc_bytes; i++)
		ecc_code[i] = s[ecc_bytes - 1 - i];

	return 0;
}

/* TODO: move to clock driver */
static void hsnand_clk_init(void)
{
	void *cgu_base = (void *)CKSEG1ADDR(CGU_BASE);

	setbits_32(cgu_base + CGU_CLKGCR1_A, CGU_CLKGCR1_A_EBU);
}

static int hsnand_wait_ready(void)
{
	return wait_for_bit_le32(&nand_regs->wait, NAND_WAIT_WR_C, true,
		200, false);
}

static int hsnand_dev_ready(struct mtd_info *mtd)
{
	u32 data = readl(&nand_regs->wait);
	return data & NAND_WAIT_READY;
}

static void hsnand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	unsigned long addr_w = (unsigned long) chip->IO_ADDR_W;
	unsigned long addr_r = (unsigned long) chip->IO_ADDR_R;

#if 0
	debug("%s: chip_select %d, cmd 0x%x, change %d, nCE %d, CLE %d, ALE %d\n",
		__func__, drv->chip_select, cmd,
		!!(ctrl & NAND_CTRL_CHANGE),
		!!(ctrl & NAND_NCE),
		!!(ctrl & NAND_CLE),
		!!(ctrl & NAND_ALE));
#endif

	if (ctrl & NAND_CTRL_CHANGE) {
		if (ctrl & NAND_NCE) {
			addr_w |= NAND_CMD_CS;
			addr_r |= NAND_CMD_CS;

			clrsetbits_32(&nand_regs->con, NAND_CON_IN_CS_MASK |
				NAND_CON_OUT_CS_MASK, NAND_CON_LATCH_CS |
				NAND_CON_IN_CS(drv->chip_select) |
				NAND_CON_OUT_CS(drv->chip_select));

			if (drv->chip_select_gpio != -1)
				gpio_set_value(drv->chip_select_gpio, 0);
		} else {
			addr_w &= ~NAND_CMD_CS;
			addr_r &= ~NAND_CMD_CS;

			 clrsetbits_32(&nand_regs->con, NAND_CON_LATCH_CS, 0);

			 if (drv->chip_select_gpio != -1)
				gpio_set_value(drv->chip_select_gpio, 1);
		}

		if (ctrl & NAND_ALE)
			addr_w |= NAND_CMD_ALE;
		else
			addr_w &= ~NAND_CMD_ALE;

		if (ctrl & NAND_CLE)
			addr_w |= NAND_CMD_CLE;
		else
			addr_w &= ~NAND_CMD_CLE;

		chip->IO_ADDR_W = (void __iomem *) addr_w;
		chip->IO_ADDR_R = (void __iomem *) addr_r;
	}

	if (cmd != NAND_CMD_NONE) {
#if 0
		debug("%s: addr %p val %x, NAND_CON %08x\n",
			__func__, chip->IO_ADDR_W, cmd, readl(&nand_regs->con));
#endif
		writeb(cmd, chip->IO_ADDR_W);
		hsnand_wait_ready();
	}
}

static void hsnand_hw_setup(struct nand_chip *chip)
{
	struct mtd_info *mtd = nand_to_mtd(chip);
	struct hsnand_drv *drv = nand_get_controller_data(chip);

	u32 nd_para0 = ND_PARA0_PCOUNT(1);

	if (chip->onfi_version)
		nd_para0 |= ND_PARA0_TYPE_ONFI;

	if (drv->ecc_rs_4byte)
		nd_para0 |= ND_PARA0_ECC_4BYTE;

	switch (drv->pages_per_block) {
	case 32:
		nd_para0 |= ND_PARA0_PIB_32;
		break;
	case 64:
		nd_para0 |= ND_PARA0_PIB_64;
		break;
	case 128:
		nd_para0 |= ND_PARA0_PIB_128;
		break;
	case 256:
		nd_para0 |= ND_PARA0_PIB_256;
		break;
	default:
		break;
	}

	switch (mtd->writesize) {
	case 512:
		nd_para0 |= ND_PARA0_PAGE_512;
		break;
	case 2048:
		nd_para0 |= ND_PARA0_PAGE_2048;
		break;
	case 4096:
		nd_para0 |= ND_PARA0_PAGE_4096;
		break;
	case 8192:
		nd_para0 |= ND_PARA0_PAGE_8192;
		break;
	default:
		break;
	}

	writel(nd_para0, &hsnand_regs->nd_para0);
	writel(INT_AECC_EV | INT_AECC_OD | INT_WR_C, &hsnand_regs->int_sta);
	writel(INT_AECC_EV | INT_AECC_OD | INT_WR_C, &hsnand_regs->int_msk_ctl);
}

static void hsnand_hw_cmd_addr(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	u32 ndac_ctl1, ndac_ctl2;

#if 1
	debug("%s: hw_cmd %x, hw_cmd_2 %x, hw_page %d\n",
		__func__, drv->hw_cmd, drv->hw_cmd_2, drv->hw_page);
#endif

	ndac_ctl1 = NDAC_CTL1_ADDR1(0) | NDAC_CTL1_CMD(drv->hw_cmd);
	ndac_ctl2 = NDAC_CTL2_ADDR_CYCLE(drv->addr_cycles) |
		NDAC_CTL2_CMD_2(drv->hw_cmd_2);

	if (mtd->writesize > 512) {
		ndac_ctl1 |= NDAC_CTL1_ADDR2(0);
		ndac_ctl1 |= NDAC_CTL1_ADDR3(drv->hw_page);
		ndac_ctl2 |= NDAC_CTL2_ADDR4(drv->hw_page >> 8);
		if (drv->addr_cycles == 5)
			ndac_ctl2 |= NDAC_CTL2_ADDR5(drv->hw_page >> 16);
	} else {
		ndac_ctl1 |= NDAC_CTL1_ADDR2(drv->hw_page);
		ndac_ctl1 |= NDAC_CTL1_ADDR3(drv->hw_page >> 8);
		if (drv->addr_cycles == 4)
			ndac_ctl2 |= NDAC_CTL2_ADDR4(drv->hw_page >> 16);
	}

	writel(ndac_ctl1, &hsnand_regs->ndac_ctl1);
	writel(ndac_ctl2, &hsnand_regs->ndac_ctl2);
}

static void hsnand_hw_ctl(const struct hsnand_drv *drv, bool do_write,
				bool do_ecc)
{
	u32 nd_ctl = ND_CTL_DEFAULT;

#if 1
	debug("%s: write %d, ecc %d\n", __func__, do_write, do_ecc);
#endif

	if (do_write)
		nd_ctl |= ND_CTL_WRITE;

	if (!do_ecc)
		nd_ctl |= ND_CTL_MODE_NO_ECC;

	nd_ctl |= ND_CTL_CE_SEL(drv->chip_select);

	writel(nd_ctl, &hsnand_regs->nd_ctl);
}

static void hsnand_cmdfunc(struct mtd_info *mtd, unsigned cmd, int column,
				int page)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct hsnand_drv *drv = nand_get_controller_data(chip);

	drv->hw_page = page;

	if (cmd == NAND_CMD_SEQIN && column < mtd->writesize) {
		drv->hw_cmd = NDAC_CTL1_CMD_WRITE;
		drv->hw_cmd_2 = 0;
		hsnand_hw_cmd_addr(mtd);
		return;
	}

	if (cmd == NAND_CMD_READ0 && column < mtd->writesize) {
		drv->hw_cmd = NDAC_CTL1_CMD_READ;
		drv->hw_cmd_2 = 0;
		hsnand_hw_cmd_addr(mtd);
		return;
	}

	if (mtd->writesize > 512)
		nand_command_lp(mtd, cmd, column, page);
	else
		nand_command(mtd, cmd, column, page);
}

static void hsnand_hw_go(const struct hsnand_drv *drv)
{
	setbits_32(&hsnand_regs->nd_ctl, ND_CTL_GO);
}

static int hsnand_hw_wait_wr_c(const struct hsnand_drv *drv)
{
	int ret;

	ret = wait_for_bit_le32(&hsnand_regs->int_sta, INT_WR_C, true,
		200, false);
	if (!ret)
		setbits_32(&hsnand_regs->int_sta, INT_WR_C);

	return ret;
}

static int hsnand_check_ecc_chunk(void *buf1, void *buf2, int len,
				  int bitflips_threshold)
{
	const unsigned char *bitmap1 = buf1;
	const unsigned char *bitmap2 = buf2;
	int bitflips = 0;

	for (; len && ((uintptr_t)bitmap1) % sizeof(long);
	     len--, bitmap1++, bitmap2++) {
		bitflips += hweight8(*bitmap1 ^ *bitmap2);
		if (unlikely(bitflips > bitflips_threshold))
			return -EBADMSG;
	}

	for (; len >= sizeof(long);
	     len -= sizeof(long), bitmap1 += sizeof(long),
	     bitmap2 += sizeof(long)) {
		bitflips += hweight32(*((unsigned long *)bitmap1) ^
				*((unsigned long *)bitmap2));
		if (unlikely(bitflips > bitflips_threshold))
			return -EBADMSG;
	}

	for (; len > 0; len--, bitmap1++, bitmap2++) {
		bitflips += hweight8(*bitmap1 ^ *bitmap2);
		if (unlikely(bitflips > bitflips_threshold))
			return -EBADMSG;
	}

	return bitflips;
}

static bool hsnand_read_error(struct mtd_info *mtd)
{
	u32 int_sta;

	/* HW only shows uncorrectable errors per ECC block */
	int_sta = readl(&hsnand_regs->int_sta);
	if (int_sta & (INT_AECC_EV | INT_AECC_OD)) {
		/* clear ECC interrupts */
		setbits_32(&hsnand_regs->int_sta, INT_AECC_EV | INT_AECC_OD);
		return true;
	}

	return false;
}

static int hsnand_read_page_dma(struct mtd_info *mtd, uint8_t *buf,
				int oob_required)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err;

	ltq_dma_rx_map(&dma_dev, drv->rx_num, buf, mtd->writesize);

	hsnand_cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_ALE |
		NAND_CTRL_CHANGE);
	hsnand_hw_go(drv);

	err = ltq_dma_rx_wait(&dma_dev, drv->rx_num, 2000);

	if (!err && oob_required)
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);

	hsnand_cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
	drv->rx_num = (drv->rx_num + 1) % RX_DESC_CNT;

	return err;
}

static int hsnand_read_page_raw(struct mtd_info *mtd,
				struct nand_chip *chip, uint8_t *buf,
				int oob_required, int page)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err;

#if 1
	debug("%s: oob_required %d, page %d, hw_page %d, buf %p\n",
		__func__, oob_required, page, drv->hw_page, buf);
#endif

	hsnand_hw_ctl(drv, false, false);
	err = hsnand_read_page_dma(mtd, buf, oob_required);

	return err ? -EIO : 0;
}

static int hsnand_read_page_ecc(struct mtd_info *mtd,
				struct nand_chip *chip, uint8_t *buf,
				int oob_required, int page)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err, i, stat;
	int eccbytes = chip->ecc.bytes;
	int eccsize = chip->ecc.size;
	int eccsteps = chip->ecc.steps;
	int eccstrength = chip->ecc.strength;
	int max_bitflips = 0;
	uint8_t *data = buf;
	uint8_t *data_raw = drv->readbuf;
	uint8_t *oob_poi = chip->oob_poi;
	bool read_error;

#if 0
	unsigned int ecc_failures = mtd->ecc_stats.failed;
	unsigned int ecc_corrected = mtd->ecc_stats.corrected;

	debug("%s: oob_required %d, page %d, buf %p\n",
		__func__, oob_required, drv->hw_page, buf);
#endif

	/* Read via DMA with HW ECC enabled into page buffer */
	hsnand_hw_ctl(drv, false, true);
	err = hsnand_read_page_dma(mtd, buf, 0);
	if (err)
		return -EIO;

	/* Check if HW ECC engine indicated uncorrectable errors */
	read_error = hsnand_read_error(mtd);

	/*
	 * Read again via DMA but now with HW ECC disabled into temporary
	 * page buffer. Now we also read OOB to get the ECC bytes. We need
	 * this information to check for empty pages or to determine bit flips.
	 */
	hsnand_hw_ctl(drv, false, false);
	err = hsnand_read_page_dma(mtd, drv->readbuf, 1);
	if (err)
		return -EIO;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, data += eccsize,
	     data_raw += eccsize) {
		if (read_error) {
			/* Check for empty pages with bitflips */
			stat = nand_check_erased_ecc_chunk(data_raw, eccsize,
				&oob_poi[i], eccbytes, NULL, 0, eccstrength);
		} else {
			/*
			 * Check for bitflips between corrected and uncorrected
			 * page data.
			 */
			stat = hsnand_check_ecc_chunk(data, data_raw, eccsize,
				eccstrength);
		}

		if (stat < 0) {
			mtd->ecc_stats.failed++;
		} else {
			mtd->ecc_stats.corrected += stat;
			max_bitflips = max_t(unsigned int, max_bitflips, stat);
		}
	}

#if 0
	debug("%s: read_error %d, max_bitflips %d, corrected %d, failed %d\n",
		__func__, read_error, max_bitflips,
		mtd->ecc_stats.corrected - ecc_corrected,
		mtd->ecc_stats.failed - ecc_failures);
#endif

	return max_bitflips;
}

static int hsnand_write_page_dma(struct mtd_info *mtd, const uint8_t *buf)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err;

	err = ltq_dma_tx_map(&dma_dev, drv->tx_num, buf, mtd->writesize, 2);
	if (err)
		return err;

	hsnand_cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_ALE |
		NAND_CTRL_CHANGE);
	hsnand_hw_go(drv);

	err = hsnand_hw_wait_wr_c(drv);
	hsnand_cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
	drv->tx_num = (drv->tx_num + 1) % TX_DESC_CNT;

	return err;
}

static int hsnand_write_page_raw(struct mtd_info *mtd,
					struct nand_chip *chip,
					const uint8_t *buf, int oob_required,
					int page)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err;

#if 1
	debug("%s: oob_required %d, page %d, hw_page %d, buf %p\n",
		__func__, oob_required, page, drv->hw_page, buf);
#endif

	hsnand_hw_ctl(drv, true, false);
	err = hsnand_write_page_dma(mtd, buf);

	if (!err && oob_required)
		chip->ecc.write_oob_raw(mtd, chip, drv->hw_page);

	return err ? -EIO : 0;
}

static int hsnand_write_page_ecc(struct mtd_info *mtd,
					struct nand_chip *chip,
					const uint8_t *buf, int oob_required,
					int page)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int err;

#if 1
	debug("%s: oob_required %d, page %d, hw_page %d, buf %p\n",
		__func__, oob_required, page, drv->hw_page, buf);
#endif

	hsnand_hw_ctl(drv, true, true);
	err = hsnand_write_page_dma(mtd, buf);

	if (!err && oob_required)
		chip->ecc.write_oob_raw(mtd, chip, drv->hw_page);

	return err ? -EIO : 0;
}

static int hsnand_write_page_ecc_sw(struct mtd_info *mtd,
					struct nand_chip *chip,
					const uint8_t *buf, int oob_required,
					int page)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int i;
	int eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *ecc_calc = chip->buffers->ecccalc;
	const uint8_t *p = buf;
	uint32_t *eccpos = chip->ecc.layout->eccpos;

#if 1
	debug("%s: oob_required %d, page %d, buf %p\n",
		__func__, oob_required, drv->hw_page, buf);
#endif

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
		hsnand_rs_calculate(mtd, p, &ecc_calc[i]);

	for (i = 0; i < chip->ecc.total; i++)
		chip->oob_poi[eccpos[i]] = ecc_calc[i];

	if (drv->hw_page == 384) {
		debug("%s: simulating one bit error at page %d\n",
			__func__, drv->hw_page);
		uint8_t *b = (uint8_t *)buf;
		b[2] ^= BIT(4);
	}
	if (drv->hw_page == 385) {
		debug("%s: simulating two bit errors at page %d\n",
			__func__, drv->hw_page);
		uint8_t *b = (uint8_t *)buf;
		b[2] ^= BIT(4);
		b[8] ^= BIT(2);
	}
	if (drv->hw_page == 386) {
		debug("%s: simulating three bit errors at page %d\n",
			__func__, drv->hw_page);
		uint8_t *b = (uint8_t *)buf;
		b[2] ^= BIT(4);
		b[8] ^= BIT(2);
		b[13] ^= BIT(5);
	}

	return hsnand_write_page_raw(mtd, chip, buf, 1, page);
}

static uint8_t hsnand_read_byte(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	uint8_t val = readb(chip->IO_ADDR_R);

#if 0
	debug("%s: addr %p val %x\n", __func__, chip->IO_ADDR_R, val);
#endif

	return val;
}

static void hsnand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	int i;

	for (i = 0; i < len; i++) {
		buf[i] = readb(chip->IO_ADDR_R);
#if 0
		debug("%s: addr %p val %x\n", __func__, chip->IO_ADDR_R, buf[i]);
#endif
	}
}

static void hsnand_write_byte(struct mtd_info *mtd, uint8_t byte)
{
	struct nand_chip *chip = mtd_to_nand(mtd);

#if 0
	debug("%s: addr %p val %x\n", __func__, chip->IO_ADDR_W, byte);
#endif
	writeb(byte, chip->IO_ADDR_W);
	hsnand_wait_ready();
}

static void hsnand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	int i;

	for (i = 0; i < len; i++) {
#if 0
		debug("%s: addr %p val %x\n", __func__, chip->IO_ADDR_W, buf[i]);
#endif
		writeb(buf[i], chip->IO_ADDR_W);
	}
}

static void hsnand_ecc_layout_create(struct nand_chip *chip)
{
	struct mtd_info *mtd = nand_to_mtd(chip);
	struct hsnand_drv *drv = nand_get_controller_data(chip);
	int i, ecc_steps, ecc_total;

	ecc_steps = mtd->writesize / chip->ecc.size;
	ecc_total = ecc_steps * chip->ecc.bytes;

	drv->ecc_layout.eccbytes = ecc_total;

	for (i = 0; i < ecc_total; i++)
		drv->ecc_layout.eccpos[i] = i;

	if (ecc_total < mtd->oobsize) {
		drv->ecc_layout.oobfree[0].offset = ecc_total;
		drv->ecc_layout.oobfree[0].length = mtd->oobsize - ecc_total;
	}

	chip->ecc.layout = &drv->ecc_layout;
}

static void hsnand_ecc_init_reed_solomon(struct nand_chip *chip)
{
	struct hsnand_drv *drv = nand_get_controller_data(chip);

	chip->cmdfunc = hsnand_cmdfunc;
	chip->ecc.mode = NAND_ECC_HW;
	chip->ecc.read_page_raw = hsnand_read_page_raw;
	chip->ecc.write_page_raw = hsnand_write_page_raw;
	chip->ecc.read_page = hsnand_read_page_ecc;

	if (simulate_bitflips)
		chip->ecc.write_page = hsnand_write_page_ecc_sw;
	else
		chip->ecc.write_page = hsnand_write_page_ecc;

	chip->ecc.size = 128;

	if (drv->ecc_rs_4byte) {
		chip->ecc.bytes = 4;
		chip->ecc.strength = 2;
	} else {
		chip->ecc.bytes = 3;
		chip->ecc.strength = 1;
	}

	hsnand_ecc_layout_create(chip);

	chip->options |= NAND_NO_SUBPAGE_WRITE;
	chip->bbt_options |= NAND_BBT_NO_OOB_BBM | NAND_BBT_NO_OOB |
		NAND_BBT_CREATE_EMPTY;
}

static void hsnand_ecc_init_soft_bch(struct nand_chip *chip)
{
	chip->ecc.mode = NAND_ECC_SOFT_BCH;
	chip->ecc.size = chip->ecc_step_ds;
	chip->ecc.strength = chip->ecc_strength_ds;
}

static void hsnand_ecc_init_soft(struct nand_chip *chip)
{
	chip->ecc.mode = NAND_ECC_SOFT;
}

static void hsnand_ecc_init_none(struct nand_chip *chip)
{
	if (HSNAND_DMA) {
		chip->cmdfunc = hsnand_cmdfunc;
		chip->ecc.read_page_raw = hsnand_read_page_raw;
		chip->ecc.write_page_raw = hsnand_write_page_raw;
		chip->options |= NAND_NO_SUBPAGE_WRITE;
	}
}

static void hsnand_drv_setup(struct nand_chip *chip)
{
	struct mtd_info *mtd = nand_to_mtd(chip);
	struct hsnand_drv *drv = nand_get_controller_data(chip);

	if (mtd->writesize > 512) {
		if (chip->chipsize > (128 << 20))
			drv->addr_cycles = 5;
		else
			drv->addr_cycles = 4;
	} else {
		if (chip->chipsize > (32 << 20))
			drv->addr_cycles = 4;
		else
			drv->addr_cycles = 3;
	}

	drv->pages_per_block = mtd->erasesize / mtd->writesize;
}

static void hsnand_ebu_init(void)
{
	/* Enable NAND module and set polarity of latch pins */
	writel(NAND_CON_LATCH_ALL | NAND_CON_PRE_P | NAND_CON_WP_P |
		NAND_CON_SE_P | NAND_CON_CS_P | NAND_CON_CSMUX |
		NAND_CON_NANDM, &nand_regs->con);

	if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0)) {
		writel(EBU_REGION0_BASE | EBU_ADDRSEL_MASK(1) |
			EBU_ADDRSEL_REGEN, &ebu_regs->addr_sel_0);

		writel(EBU_CON_SETUP | EBU_CON_ALEC(2) | EBU_CON_WAITWRC(2) |
			EBU_CON_WAITRDC(2) | EBU_CON_HOLDC(3) | EBU_CON_BCGEN_RESERVED |
			EBU_CON_RECOVC(1) | EBU_CON_CMULT_4, &ebu_regs->con_0);
	} else {
		clrbits_32(&ebu_regs->addr_sel_0, EBU_ADDRSEL_REGEN);
	}

	if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1)) {
		writel(EBU_REGION1_BASE | EBU_ADDRSEL_MASK(1) |
			EBU_ADDRSEL_REGEN, &ebu_regs->addr_sel_1);

		writel(EBU_CON_SETUP | EBU_CON_ALEC(2) | EBU_CON_WAITWRC(2) |
			EBU_CON_WAITRDC(2) | EBU_CON_HOLDC(1) | EBU_CON_BCGEN_RESERVED |
			EBU_CON_RECOVC(1) | EBU_CON_CMULT_4, &ebu_regs->con_1);
	} else {
		clrbits_32(&ebu_regs->addr_sel_1, EBU_ADDRSEL_REGEN);
	}

#if 0
	debug("%s: NAND_CON %08x, EBU_CON_0 %08x, EBU_CON_1 %08x, EBU_ADDR_SEL_0 %08x, EBU_ADDR_SEL_1 %08x\n",
		__func__, readl(&nand_regs->con), readl(&ebu_regs->con_0),
		readl(&ebu_regs->con_1), readl(&ebu_regs->addr_sel_0),
		readl(&ebu_regs->addr_sel_1));
#endif
}

static void hsnand_init(int devnum)
{
	struct hsnand_drv *drv = &hsnand_drv[devnum];
	struct nand_chip *chip = &hsnand_chip[devnum];
	struct mtd_info *mtd = nand_to_mtd(chip);
	int err;

	chip->dev_ready = hsnand_dev_ready;
	chip->cmd_ctrl = hsnand_cmd_ctrl;
	chip->bbt_options |= NAND_BBT_USE_FLASH;
	chip->IO_ADDR_W = chip->IO_ADDR_R = drv->base;

	chip->read_byte = hsnand_read_byte;
	chip->read_buf = hsnand_read_buf;
	chip->write_byte = hsnand_write_byte;
	chip->write_buf = hsnand_write_buf;

	if (drv->chip_select_gpio != -1)
		gpio_request(drv->chip_select_gpio, "hsnand-cs");

	nand_set_controller_data(chip, drv);

	err = nand_scan_ident(mtd, 1, NULL);
	if (err) {
		debug("nand_scan_ident failed\n");
		return;
	}

	hsnand_drv_setup(chip);

	if (HSNAND_DMA) {
		drv->readbuf = malloc_cache_aligned(mtd->writesize);
		if (!drv->readbuf) {
			debug("malloc_cache_aligned failed\n");
			return;
		}
	}

	switch (drv->ecc_mode) {
	case NAND_ECC_SOFT:
		hsnand_ecc_init_soft(chip);
		break;
	case NAND_ECC_SOFT_BCH:
		hsnand_ecc_init_soft_bch(chip);
		break;
	case NAND_ECC_HW:
		hsnand_hw_setup(chip);
		hsnand_ecc_init_reed_solomon(chip);
		break;
	default:
		hsnand_hw_setup(chip);
		hsnand_ecc_init_none(chip);
		break;
	}

	err = nand_scan_tail(mtd);
	if (err) {
		debug("nand_scan_tail failed\n");
		goto err_free;
	}

	nand_register(devnum, mtd);
	return;

err_free:
	free(drv->readbuf);
}

static int hsnand_dma_init(void)
{
	int err;

	if (!HSNAND_DMA)
		return 0;

	ltq_dma_init();

	dma_dev.port = 2;
	dma_dev.rx_chan.chan_no = 4;
	dma_dev.rx_chan.class = 0;
	dma_dev.rx_chan.num_desc = RX_DESC_CNT;
	dma_dev.rx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev.rx_burst_len = LTQ_DMA_BURST_8WORDS;
	dma_dev.tx_chan.chan_no = 5;
	dma_dev.tx_chan.class = 0;
	dma_dev.tx_chan.num_desc = TX_DESC_CNT;
	dma_dev.tx_endian_swap = LTQ_DMA_ENDIANESS_B3_B2_B1_B0;
	dma_dev.tx_burst_len = LTQ_DMA_BURST_8WORDS;
	dma_dev.debug = true;

	err = ltq_dma_register(&dma_dev);
	if (err)
		return err;

	ltq_dma_enable(&dma_dev);

	return 0;
}

void board_nand_init(void)
{
	int err, i, devnum = 0;
	bool init_cs0 = false, init_cs1 = false;

	err = hsnand_dma_init();
	if (err)
		return;

	hsnand_clk_init();
	hsnand_ebu_init();

	for (i = 0; i < CONFIG_SYS_MAX_NAND_DEVICE; i++) {
		struct hsnand_drv *drv = &hsnand_drv[i];

		if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1) && !init_cs1) {
			drv->chip_select = 1;
			drv->base = (void __iomem *)CKSEG1ADDR(EBU_REGION1_BASE);

			if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1_ECC_SOFT)) {
				drv->ecc_mode = NAND_ECC_SOFT;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1_ECC_RS_3)) {
				drv->ecc_mode = NAND_ECC_HW;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1_ECC_RS_4)) {
				drv->ecc_mode = NAND_ECC_HW;
				drv->ecc_rs_4byte = true;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1_ECC_BCH)) {
				drv->ecc_mode = NAND_ECC_SOFT_BCH;
			} else {
				drv->ecc_mode = NAND_ECC_NONE;
			}

			if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS1_GPIO))
				drv->chip_select_gpio = CONFIG_NAND_LANTIQ_CS1_GPIO_NUM;
			else
				drv->chip_select_gpio = -1;

			hsnand_init(devnum);
			devnum++;
			init_cs1 = true;
			continue;
		}

		if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0) && !init_cs0) {
			drv->chip_select = 0;
			drv->base = (void __iomem *)CKSEG1ADDR(EBU_REGION0_BASE);

			if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0_ECC_SOFT)) {
				drv->ecc_mode = NAND_ECC_SOFT;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0_ECC_RS_3)) {
				drv->ecc_mode = NAND_ECC_HW;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0_ECC_RS_4)) {
				drv->ecc_mode = NAND_ECC_HW;
				drv->ecc_rs_4byte = true;
			} else if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0_ECC_BCH)) {
				drv->ecc_mode = NAND_ECC_SOFT_BCH;
			} else {
				drv->ecc_mode = NAND_ECC_NONE;
			}

			if (IS_ENABLED(CONFIG_NAND_LANTIQ_CS0_GPIO))
				drv->chip_select_gpio = CONFIG_NAND_LANTIQ_CS0_GPIO_NUM;
			else
				drv->chip_select_gpio = -1;

			hsnand_init(devnum);
			devnum++;
			init_cs0 = true;
			continue;
		}
	}
}

#if defined(CONFIG_SPL_BUILD)
static void spl_nand_read_page(struct mtd_info *mtd, int page, uint8_t *buf)
{
	struct nand_chip *chip = mtd_to_nand(mtd);

	nand_command_lp(mtd, NAND_CMD_READ0, 0, page);
	chip->read_buf(mtd, buf, mtd->writesize);
}

int nand_spl_load_image(uint32_t offs, unsigned int size, void *dst)
{
	struct nand_chip *chip = &hsnand_chip[0];
	struct mtd_info *mtd = nand_to_mtd(chip);
	uint8_t *buf = dst;
	int realpage, lastpage;

	realpage = (int)(offs >> chip->page_shift);
	lastpage = (int)((offs + size - 1) >> chip->page_shift);

	while (realpage <= lastpage) {
		spl_nand_read_page(mtd, realpage, buf);
		realpage++;
		buf += mtd->writesize;
	}

	return 0;
}

void nand_init(void)
{
	struct hsnand_drv *drv = &hsnand_drv[0];
	struct nand_chip *chip = &hsnand_chip[0];
	struct mtd_info *mtd = nand_to_mtd(chip);

	hsnand_clk_init();
	hsnand_ebu_init();

	drv->chip_select = 1;
	drv->base = (void __iomem *)CKSEG1ADDR(EBU_REGION1_BASE);

	chip->dev_ready = hsnand_dev_ready;
	chip->cmd_ctrl = hsnand_cmd_ctrl;
	chip->IO_ADDR_W = chip->IO_ADDR_R = drv->base;

	chip->read_byte = hsnand_read_byte;
	chip->read_buf = hsnand_read_buf;
	chip->write_byte = hsnand_write_byte;
	chip->write_buf = hsnand_write_buf;

	mtd->writesize = CONFIG_SYS_NAND_PAGE_SIZE;
	mtd->erasesize = CONFIG_SYS_NAND_BLOCK_SIZE;
	chip->page_shift = ffs(mtd->writesize) - 1;

	nand_set_controller_data(chip, drv);
	hsnand_drv_setup(chip);
	hsnand_hw_setup(chip);
	hsnand_ecc_init_none(chip);
}
#endif
