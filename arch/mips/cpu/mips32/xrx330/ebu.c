/*
 * Copyright (C) 2015 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/soc.h>
#include <asm/lantiq/io.h>

#define EBU_ADDRSEL_MASK(mask)		((mask & 0xf) << 4)
#define EBU_ADDRSEL_REGEN		(1 << 0)

#define EBU_CON_WRDIS			(1 << 31)
#define EBU_CON_ADSWP			(1 << 30)
#define EBU_CON_AGEN_DEMUX		(0x0 << 24)
#define EBU_CON_AGEN_MUX		(0x2 << 24)
#define EBU_CON_SETUP			(1 << 22)
#define EBU_CON_WAIT_DIS		(0x0 << 20)
#define EBU_CON_WAIT_ASYNC		(0x1 << 20)
#define EBU_CON_WAIT_SYNC		(0x2 << 20)
#define EBU_CON_WINV			(1 << 19)
#define EBU_CON_PW_8BIT			(0x0 << 16)
#define EBU_CON_PW_16BIT		(0x1 << 16)
#define EBU_CON_ALEC(cycles)		((cycles & 0x3) << 14)
#define EBU_CON_BCGEN_CS		(0x0 << 12)
#define EBU_CON_BCGEN_INTEL		(0x1 << 12)
#define EBU_CON_BCGEN_MOTOROLA		(0x2 << 12)
#define EBU_CON_WAITWRC(cycles)		((cycles & 0x7) << 8)
#define EBU_CON_WAITRDC(cycles)		((cycles & 0x3) << 6)
#define EBU_CON_HOLDC(cycles)		((cycles & 0x3) << 4)
#define EBU_CON_RECOVC(cycles)		((cycles & 0x3) << 2)
#define EBU_CON_CMULT_1			0x0
#define EBU_CON_CMULT_4			0x1
#define EBU_CON_CMULT_8			0x2
#define EBU_CON_CMULT_16		0x3

#if defined(CONFIG_LTQ_NAND_CS0)
#define ebu_region0_enable		1
#else
#define ebu_region0_enable		0
#endif

#if defined(CONFIG_LTQ_NAND_CS1)
#define ebu_region1_enable		1
#else
#define ebu_region1_enable		0
#endif

struct ltq_ebu_regs {
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

static struct ltq_ebu_regs *ltq_ebu_regs =
	(struct ltq_ebu_regs *) CKSEG1ADDR(LTQ_EBU_BASE);

void ltq_ebu_init(void)
{
	ltq_build_check_reg(struct ltq_ebu_regs, addr_sel_0, 0x20);
	ltq_build_check_reg(struct ltq_ebu_regs, con_0, 0x60);

	if (ebu_region0_enable) {
		ltq_writel(&ltq_ebu_regs->addr_sel_0, LTQ_EBU_REGION0_BASE |
			EBU_ADDRSEL_MASK(3) | EBU_ADDRSEL_REGEN);

		ltq_writel(&ltq_ebu_regs->con_0, EBU_CON_SETUP |
			EBU_CON_ALEC(3) | EBU_CON_WAITWRC(3) |
			EBU_CON_WAITRDC(2) | EBU_CON_HOLDC(2) |
			EBU_CON_RECOVC(2) | EBU_CON_CMULT_8);
	} else {
		ltq_clrbits(&ltq_ebu_regs->addr_sel_0, EBU_ADDRSEL_REGEN);
	}

	if (ebu_region1_enable) {
		ltq_writel(&ltq_ebu_regs->addr_sel_1, LTQ_EBU_REGION1_BASE |
			EBU_ADDRSEL_MASK(3) | EBU_ADDRSEL_REGEN);

		ltq_writel(&ltq_ebu_regs->con_1, EBU_CON_SETUP |
			EBU_CON_ALEC(3) | EBU_CON_WAITWRC(2) |
			EBU_CON_WAITRDC(2) | EBU_CON_HOLDC(1) |
			EBU_CON_RECOVC(1) | EBU_CON_CMULT_4);
	} else {
		ltq_clrbits(&ltq_ebu_regs->addr_sel_1, EBU_ADDRSEL_REGEN);
	}
}
