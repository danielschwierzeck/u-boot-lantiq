/*
 * Clear datapath to allow proper functionality of switch in the 
 * kernel. 
 *
 * Copyright (C) 2018 Xu Liang <liang.xu@intel.com>
 * Copyright (C) 2018 Mohammad Firdaus B Alias Thani <m.alasthani@intel.com>
 *
 * This program is free software; you can distribute it and/or modify it
 * under the terms of the GNU General Public License (Version 2) as
 * published by the Free Software Foundation.
*/

#include <lantiq.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>

#define RCU_RST_REQ		0x0010
#define GSWL_BASE		((void __iomem *) GSW_BASE_ADDR)
#define GSWR_BASE		((void __iomem *) GSW_R_BASE_ADDR)
#define ETHSW_SWRES		0x000
#define FDMA_PCTRL		0xA80
#define SDMA_PCTRL		0xBC0


/********************************
   Wrapper for Register Access
********************************/

static inline void reg_clr(uint32_t bit, void __iomem *base, uint32_t off)
{
	void __iomem *reg_addr = base + off;
	uint32_t val;

	val = readl(reg_addr);
	val &= ~BIT(bit);
	writel(val, reg_addr);
}

static inline void reg_set(uint32_t bit, void __iomem *base, uint32_t off)
{
	void __iomem *reg_addr = base + off;
	uint32_t val;

	val = readl(reg_addr);
	val |= BIT(bit);
	writel(val, reg_addr);
}

/***************************
   Put PHY in Reset State
***************************/

static inline void ltq_rcu_set(uint32_t bit, uint32_t off)
{
	reg_set(bit, (void __iomem *) RESET_BASE_REG, off);
}

void gphy_rst_assert(void)
{
	ltq_rcu_set(31, RCU_RST_REQ);	/* GPHY6F */
	ltq_rcu_set(29, RCU_RST_REQ);	/* GPHY2 */
	ltq_rcu_set(28, RCU_RST_REQ);	/* GPHY3 */
	ltq_rcu_set(26, RCU_RST_REQ);	/* GPHY4 */
	ltq_rcu_set(25, RCU_RST_REQ);	/* GPHY5 */
}

static inline uint32_t ltq_sw_r32(void __iomem *base, uint32_t off)
{
	void __iomem *reg_addr = base + off * 4;

	return readl(reg_addr);
}

static inline void ltq_sw_w32(uint32_t val, void __iomem *base, uint32_t off)
{
	void __iomem *reg_addr = base + off * 4;

	writel(val, reg_addr);
}

static inline void ltq_sw_clr(uint32_t bit, void __iomem *base, uint32_t off)
{
	reg_clr(bit, base, off * 4);
}

/*
 * Reset switch and stop transmission on port of Switch-L/R.
 * This is to solve traffic stall due to DMA reset with packet pending.
 */
void switch_reset_and_disable(void)
{
    void __iomem * gswl_base = GSWL_BASE;
    void __iomem * gswr_base = GSWR_BASE;
    int pidx;
    uint32_t off;
    uint32_t loop;

    /* Reset Switch-L */
    ltq_sw_w32(0x01, gswl_base, ETHSW_SWRES);
    loop = 1000;
    do {
        udelay(100);
    } while (ltq_sw_r32(gswl_base, ETHSW_SWRES) && --loop);
    if (!loop) {
        panic("Switch-L Reset fail. Reset ...\n");
    }
    /* Reset Switch-R */
    ltq_sw_w32(0x01, gswr_base, ETHSW_SWRES);
    loop = 1000;
    do {
        udelay(100);
    } while (ltq_sw_r32(gswr_base, ETHSW_SWRES) && --loop);
    if (!loop) {
        panic("Switch-R Reset fail. Reset ...\n");
    }

    /* Disable Ports of Switch-L */
    for (pidx = 2; pidx < 6; pidx++) {
        /* Set SDMA_PCTRL_PEN PORT disable */
        off = SDMA_PCTRL + pidx * 6;
        ltq_sw_clr(0, gswl_base, off);
        /* Set FDMA_PCTRL_EN PORT disable */
        off = FDMA_PCTRL + pidx * 6;
        ltq_sw_clr(0, gswl_base, off);
    }
    /* Disable Ports of Switch-R */
    for(pidx = 0; pidx < 16; pidx++) {
        /* Set SDMA_PCTRL_PEN PORT disable */
        off = SDMA_PCTRL + pidx * 6;
        ltq_sw_clr(0, gswr_base, off);
        /* Set FDMA_PCTRL_EN PORT disable */
        off = FDMA_PCTRL + pidx * 6;
        ltq_sw_clr(0, gswr_base, off);
    }
}
