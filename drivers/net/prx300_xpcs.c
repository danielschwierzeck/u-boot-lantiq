/*
 * Intel XPCS driver
 *
 * Copyright (C) 2018 Intel, Corp.
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <lantiq.h>
#include <asm/arch/prx300.h>

#include "prx300_xpcs.h"

#define MAX_BUSY_RETRY	2000

#define SERDES_MAIN_CFG(num)	CONFIG_SERDES_MAIN##num
#define SERDES_PRE_CFG(num)	CONFIG_SERDES_PRE##num
#define SERDES_POST_CFG(num)	CONFIG_SERDES_POST##num
#define SERDES_CFG(NAME, num)	\
		(num == 0) ? SERDES_##NAME##_CFG(0) \
			: (num == 1) ? SERDES_##NAME##_CFG(1) \
			: SERDES_##NAME##_CFG(2)

/* dummy values, not used */
#ifndef CONFIG_PRX300_EXTERNAL_PHY
#define CONFIG_SERDES_PRE0	0x14
#define CONFIG_SERDES_POST0	0x14
#define CONFIG_SERDES_MAIN0	0x1E
#define CONFIG_SERDES_PRE1	0x0
#define CONFIG_SERDES_POST1	0x0
#define CONFIG_SERDES_MAIN1	0x28
#define CONFIG_SERDES_PRE2	0x0
#define CONFIG_SERDES_POST2	0x0
#define CONFIG_SERDES_MAIN2	0x28
#endif

static void xpcs_cl37_an(struct xpcs_prv_data *pdata);
static void xpcs_cl73_an(struct xpcs_prv_data *pdata);
static void xpcs_cl72_startup(struct xpcs_prv_data *pdata);
static int xpcs_vs_reset(struct xpcs_prv_data *pdata);
static int xpcs_synphy_reset_sts(struct xpcs_prv_data *pdata);
static int xpcs_teng_kr_mode(struct xpcs_prv_data *pdata);
static int xpcs_teng_xaui_mode(struct xpcs_prv_data *pdata);
static int xpcs_oneg_xaui_mode(struct xpcs_prv_data *pdata);
static int xpcs_2p5g_sgmii_mode(struct xpcs_prv_data *pdata);

struct xpcs_mode_cfg mode_cfg[4] = {
	{
		.name = "10G_KR_MODE",
		.pma_type = PMA_TYPE_10G_BASE_KR,
		.pcs_type = PCS_TYPE_10G_BASE_R,
		.lane = LANE_1,
		.mplla_mult = 0x21,
		.mplla_bw = 0x7B,
		.vco_ld_val[0] = 0x549,
		.vco_ref_ld[0] = 0x29,
		.afe_en = 1,
		.dfe_en = 1,
		.cont_adapt0 = 1,
		.tx_rate[0] = 0,
		.rx_rate[0] = 0,
		.tx_width[0] = 2,	/* 2'b10 - 16 bit */
		.rx_width[0] = 2,	/* 2'b10 - 16 bit */
		.mplla_div165_clk_en = 1,
		.mplla_div10_clk_en = 0,
		.mplla_div8_clk_en = 1,
		.tx_eq_main = 0x1E,
		.tx_eq_pre = 0x14,
		.tx_eq_post = 0x14,
		.tx_eq_ovrride = 1,
		.ref_clk_ctrl = 0x171,
		.los_thr = 4,
		.phy_boost_gain_val = 0x774a,
		.rx_vref_ctrl = 0,
		.vboost_lvl = 0x5,
		.tx_iboost[0] = 0xF,
		.set_mode = xpcs_teng_kr_mode,
	},
	{
		.name = "10G_XAUI_MODE",
		.pma_type = PMA_TYPE_10G_BASE_KR,
		.pcs_type = PCS_TYPE_10G_BASE_X,
		.lane = LANE_1,
		.mplla_mult = 0x28,
		.mplla_bw = 0x56,
		.mpllb_mult = 0x28,
		.mpllb_bw = 0x56,
		.vco_ld_val[0] = 0x0550,
		.vco_ref_ld[0] = 0x22,
		.afe_en = 0,
		.afe_en_31 = 0,
		.dfe_en = 0,
		.dfe_en_31 = 0,
		.cont_adapt0 = 0,
		.tx_rate[0] = 2,	/* 2'b10 */
		.rx_rate[0] = 2,	/* 2'b10 */
		.tx_width[0] = 1,
		.rx_width[0] = 1,
		.mplla_div165_clk_en = 0,
		.mplla_div10_clk_en = 0,
		.mplla_div8_clk_en = 0,
		.mpllb_div_clk_en = 0,
		.mpllb_div10_clk_en = 1,
		.mpllb_div8_clk_en = 0,
		.tx_eq_main = 0x28,
		.tx_eq_pre = 0,
		.tx_eq_post = 0,
		.tx_eq_ovrride = 1,
		.ref_clk_ctrl = 0x171,
		.los_thr = 1,
		.phy_boost_gain_val = 0x7706,
		.rx_vref_ctrl = 0xF,	/* Setting BIT12:8 = 5'd15 */
		.vboost_lvl = 0x5,
		.tx_iboost[0] = 0xF,
		.set_mode = xpcs_teng_xaui_mode,
	},
	{
		.name = "1G_XAUI_MODE",
		.pma_type = PMA_TYPE_1G_BASE_KX,
		.pcs_type = PCS_TYPE_10G_BASE_X,
		.lane = LANE_1,
		.mplla_mult = 0x20,
		.mplla_bw = 0x6E,
		.vco_ld_val[0] = 0x0540,
		.vco_ref_ld[0] = 0x002a,
		.afe_en = 0,
		.dfe_en = 0,
		.cont_adapt0 = 0,
		.tx_rate[0] = 3,
		.rx_rate[0] = 3,
		.tx_width[0] = 1,	/* 2'b01 - 10 bit */
		.rx_width[0] = 1,	/* 2'b01 - 10 bit */
		.mplla_div165_clk_en = 0,
		.mplla_div10_clk_en = 1,
		.mplla_div8_clk_en = 0,
		.tx_eq_main = 0x28,
		.tx_eq_pre = 0,
		.tx_eq_post = 0,
		.tx_eq_ovrride = 1,
		.los_thr = 0,
		.ref_clk_ctrl = 0x1F1,
		.los_thr = 4,
		.phy_boost_gain_val = 0x7706,
		.rx_vref_ctrl = 0xF,	/* Setting BIT12:8 = 5'd15 */
		.vboost_lvl = 0x5,
		.tx_iboost[0] = 0xF,
		.set_mode = xpcs_oneg_xaui_mode,
	},
	{
		.name = "2P5G_SGMII_MODE",
		.pma_type = PMA_TYPE_1G_BASE_KX,
		.pcs_type = PCS_TYPE_10G_BASE_X,
		.lane = LANE_1,
		.mplla_mult = 0x28,
		.mplla_bw = 0x56,
		.mpllb_mult = 0x28,
		.mpllb_bw = 0x56,
		.vco_ld_val[0] = 0x550,
		.vco_ref_ld[0] = 0x22,
		.vco_ld_val[1] = 0x550,
		.afe_en = 0,
		.dfe_en = 0,
		.afe_en_31 = 0,
		.dfe_en_31 = 0,
		.cont_adapt0 = 0,
		.cont_adapt31 = 0,
		.tx_rate[0] = 2, /* 3'b010 : baud/4 */
		.rx_rate[0] = 2, /* 2'b10 : baud/4 */
		.tx_width[0] = 1, /* 2'b01: 10-bit; 2'b11: 20-bit */
		.rx_width[0] = 1, /* 2'b01: 10-bit; 2'b11: 20-bit */
		.mplla_div165_clk_en = 0,
		.mplla_div10_clk_en = 1,
		.mplla_div8_clk_en = 0,
		.mplla_div_clk_en = 0,
		.mpllb_div_clk_en = 0,
		.mpllb_div10_clk_en = 1,
		.mpllb_div8_clk_en = 0,
		.rx_div165_clk_en = 0,
		.tx_eq_main = 0x13,
		.tx_eq_pre = 4,
		.tx_eq_post = 4,
		.tx_eq_ovrride = 1,
		.los_thr = 1,
		.ref_clk_ctrl = 0x1F1,
		.los_thr = 1,
		.phy_boost_gain_val = 0x7706,
		.rx_vref_ctrl = 0xF,	/* Setting BIT12:8 = 5'd15 */
		.vboost_lvl = 0x5,
		.tx_iboost[0] = 0xF,
		.set_mode = xpcs_2p5g_sgmii_mode,
	},
};

static int xpcs_rxtx_stable(struct xpcs_prv_data *pdata)
{
	int i = 0;
	u32 pseq_state = 0;

	do {
		pseq_state = XPCS_RGRD_VAL(pdata, PCS_DIG_STS, PSEQ_STATE);

		if (pseq_state == 4) {
			if (!strcmp(pdata->mode, "10G_KR_MODE"))
				debug("%s: Tx/Rx stable (Power_Good State) "
					 "Speed: 10G\n", pdata->name);
			else if (!strcmp(pdata->mode, "1G_XAUI_MODE"))
				debug("%s: Tx/Rx stable (Power_Good State) "
					 "Speed: 1G\n", pdata->name);
			else if (!strcmp(pdata->mode, "2P5G_SGMII_MODE"))
				debug("%s: Tx/Rx stable (Power_Good State) "
					 "Speed: 2.5G\n", pdata->name);

			break;
		}

		udelay(10);
	} while (i <= MAX_BUSY_RETRY);

	if (i > MAX_BUSY_RETRY) {
		printf("%s: TX/RX Stable TIMEOUT\n", pdata->name);
		return -1;
	}

	return XPCS_SUCCESS;
}

static int xpcs_byp_pwrupseq(struct xpcs_prv_data *pdata)
{
	int ret = XPCS_SUCCESS;

	XPCS_RGWR_VAL(pdata, PCS_DIG_CTRL1, BYP_PWRUP, 1);

	ret = xpcs_vs_reset(pdata);

	ret = xpcs_rxtx_stable(pdata);

	return ret;
}

static int xpcs_enable_pwrupseq(struct xpcs_prv_data *pdata)
{
	int ret = XPCS_SUCCESS;

	XPCS_RGWR_VAL(pdata, PCS_DIG_CTRL1, BYP_PWRUP, 0);

	ret = xpcs_vs_reset(pdata);

	/* This Synopsys PHY reset is selfcleared when PSEQ_STATE
	 * is equal to 3'b100, that is, Tx/Rx clocks are stable and in
	 * Power_Good state.
	 */
	if (xpcs_synphy_reset_sts(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	return ret;
}

/* 10G Mode */
static int xpcs_teng_mode(struct xpcs_prv_data *pdata)
{
	u32 pma_ctrl = XPCS_RGRD(pdata, PMA_CTRL1);
	u32 pcs_ctrl = XPCS_RGRD(pdata, PCS_CTRL1);

	if (pdata->pcs_mode == BACKPL_ETH_PCS) {
		XPCS_SET_VAL(pma_ctrl, PMA_CTRL1, SS13, 1);
		XPCS_RGWR(pdata, PMA_CTRL1, pma_ctrl);
	} else {
		XPCS_SET_VAL(pcs_ctrl, PCS_CTRL1, SS13, 1);
		XPCS_RGWR(pdata, PCS_CTRL1, pcs_ctrl);
	}

	return XPCS_SUCCESS;
}

/* 1G Mode */
static int xpcs_oneg_mode(struct xpcs_prv_data *pdata)
{
	u32 pma_ctrl = XPCS_RGRD(pdata, PMA_CTRL1);
	u32 pcs_ctrl = XPCS_RGRD(pdata, PCS_CTRL1);

	if (pdata->pcs_mode == BACKPL_ETH_PCS) {
		XPCS_SET_VAL(pma_ctrl, PMA_CTRL1, SS13, 0);
		XPCS_RGWR(pdata, PMA_CTRL1, pma_ctrl);
	} else {
		XPCS_SET_VAL(pcs_ctrl, PCS_CTRL1, SS13, 0);
		XPCS_RGWR(pdata, PCS_CTRL1, pcs_ctrl);
	}

	return XPCS_SUCCESS;
}

/* 2.5G Mode */
static int xpcs_2p5g_mode(struct xpcs_prv_data *pdata)
{
	u32 pma_ctrl = XPCS_RGRD(pdata, PMA_CTRL1);
	u32 pcs_ctrl = XPCS_RGRD(pdata, PCS_CTRL1);

	if (pdata->pcs_mode == BACKPL_ETH_PCS) {
		XPCS_SET_VAL(pma_ctrl, PMA_CTRL1, SS13, 0);
		XPCS_RGWR(pdata, PMA_CTRL1, pma_ctrl);
		XPCS_SET_VAL(pcs_ctrl, PCS_CTRL1, SS13, 0);
		XPCS_RGWR(pdata, PCS_CTRL1, pcs_ctrl);
	}

	return XPCS_SUCCESS;
}

/* XPCS Vendor Specific Soft Reset
 * When the host sets this bit, the CSR block triggers the software reset
 * process in which all internal blocks are reset, except the Management
 * Interface block and CSR block.
 * When this bit is set, it also resets the PHY.
 * This bit is self cleared
 */
static int xpcs_vs_reset(struct xpcs_prv_data *pdata)
{
	u32 reset = 0;
	u32 idx = 0;

	XPCS_RGWR_VAL(pdata, PCS_DIG_CTRL1, VR_RST, 1);

	do {
		reset = XPCS_RGRD_VAL(pdata, PCS_DIG_CTRL1, VR_RST);

		if (reset == 0)
			break;

		idx++;

		/* To put a small delay and make sure previous operations
		 * are complete
		 */
		udelay(10);
	} while (idx <= MAX_BUSY_RETRY);

	if (idx > MAX_BUSY_RETRY) {
		xpcs_printf("%s: XPCS Vendor Specific Soft Reset %d times\n",
				pdata->name, MAX_BUSY_RETRY);
		return XPCS_FAILURE;
	}

	return XPCS_SUCCESS;
}

static int xpcs_synphy_reset_sts(struct xpcs_prv_data *pdata)
{
	u32 reset = 0;
	u32 idx = 0;

	/* Make sure synopys phy is out of reset */
	do {
		reset = XPCS_RGRD_VAL(pdata, PCS_CTRL1, RST);

		if ((reset & 0x8000) == 0)
			break;

		idx++;

		/* To put a small delay and make sure previous operations
		 * are complete
		 */
		udelay(20);
	} while (idx <= MAX_BUSY_RETRY);

	if (idx > MAX_BUSY_RETRY) {
		xpcs_printf("%s: Synopsys Phy reset check reached %d times\n",
			 pdata->name, MAX_BUSY_RETRY);
		return XPCS_FAILURE;
	}

	return XPCS_SUCCESS;
}

static void xpcs_cfg_table(struct xpcs_prv_data *pdata)
{
	u32 mplla_ctrl2 = 0;
	u32 tx_eq0, tx_eq1;
	u32 val = 0;

	if (pdata->mpllb) {
		XPCS_RGWR_VAL(pdata, PMA_MPLLB_C0, MPLLB_MULTIPLIER,
			      pdata->mode_cfg->mpllb_mult);

		XPCS_RGWR_VAL(pdata, PMA_MPLLB_C3, MPPLB_BANDWIDTH,
			      pdata->mode_cfg->mpllb_bw);
	} else {
		XPCS_RGWR_VAL(pdata, PMA_MPLLA_C0, MPLLA_MULTIPLIER,
			      pdata->mode_cfg->mplla_mult);

		XPCS_RGWR_VAL(pdata, PMA_MPLLA_C3, MPPLA_BANDWIDTH,
			      pdata->mode_cfg->mplla_bw);
	}

	switch (pdata->mode_cfg->lane) {
	case LANE_4:
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_LD3, VCO_LD_VAL_3,
			      pdata->mode_cfg->vco_ld_val[3]);
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_REF1, VCO_REF_LD_3,
			      pdata->mode_cfg->vco_ref_ld[3]);
		XPCS_RGWR_VAL(pdata, PMA_TX_RATE_CTRL, TX_RATE_3,
			      pdata->mode_cfg->tx_rate[3]);
		XPCS_RGWR_VAL(pdata, PMA_RX_RATE_CTRL, RX_RATE_3,
			      pdata->mode_cfg->rx_rate[3]);
		XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL2, TX_WIDTH_3,
			      pdata->mode_cfg->tx_width[3]);
		XPCS_RGWR_VAL(pdata, PMA_RX_GENCTRL2, RX_WIDTH_3,
			      pdata->mode_cfg->rx_width[3]);
		XPCS_RGWR_VAL(pdata, PMA_TX_BOOST_CTRL, TX3_IBOOST,
			      pdata->mode_cfg->tx_iboost[3]);

	case LANE_3:
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_LD2, VCO_LD_VAL_2,
			      pdata->mode_cfg->vco_ld_val[2]);
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_REF1, VCO_REF_LD_2,
			      pdata->mode_cfg->vco_ref_ld[2]);
		XPCS_RGWR_VAL(pdata, PMA_TX_RATE_CTRL, TX_RATE_2,
			      pdata->mode_cfg->tx_rate[2]);
		XPCS_RGWR_VAL(pdata, PMA_RX_RATE_CTRL, RX_RATE_2,
			      pdata->mode_cfg->rx_rate[2]);
		XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL2, TX_WIDTH_2,
			      pdata->mode_cfg->tx_width[2]);
		XPCS_RGWR_VAL(pdata, PMA_RX_GENCTRL2, RX_WIDTH_2,
			      pdata->mode_cfg->rx_width[2]);
		XPCS_RGWR_VAL(pdata, PMA_TX_BOOST_CTRL, TX2_IBOOST,
			      pdata->mode_cfg->tx_iboost[2]);

	case LANE_2:
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_LD1, VCO_LD_VAL_1,
			      pdata->mode_cfg->vco_ld_val[1]);
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_REF0, VCO_REF_LD_1,
			      pdata->mode_cfg->vco_ref_ld[1]);
		XPCS_RGWR_VAL(pdata, PMA_TX_RATE_CTRL, TX_RATE_1,
			      pdata->mode_cfg->tx_rate[1]);
		XPCS_RGWR_VAL(pdata, PMA_RX_RATE_CTRL, RX_RATE_1,
			      pdata->mode_cfg->rx_rate[1]);
		XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL2, TX_WIDTH_1,
			      pdata->mode_cfg->tx_width[1]);
		XPCS_RGWR_VAL(pdata, PMA_RX_GENCTRL2, RX_WIDTH_1,
			      pdata->mode_cfg->rx_width[1]);
		XPCS_RGWR_VAL(pdata, PMA_TX_BOOST_CTRL, TX1_IBOOST,
			      pdata->mode_cfg->tx_iboost[1]);

	case LANE_1:
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_LD0, VCO_LD_VAL_0,
			      pdata->mode_cfg->vco_ld_val[0]);
		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_REF0, VCO_REF_LD_0,
			      pdata->mode_cfg->vco_ref_ld[0]);
		XPCS_RGWR_VAL(pdata, PMA_TX_RATE_CTRL, TX_RATE_0,
			      pdata->mode_cfg->tx_rate[0]);
		XPCS_RGWR_VAL(pdata, PMA_RX_RATE_CTRL, RX_RATE_0,
			      pdata->mode_cfg->rx_rate[0]);
		XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL2, TX_WIDTH_0,
			      pdata->mode_cfg->tx_width[0]);
		XPCS_RGWR_VAL(pdata, PMA_RX_GENCTRL2, RX_WIDTH_0,
			      pdata->mode_cfg->rx_width[0]);
		XPCS_RGWR_VAL(pdata, PMA_TX_BOOST_CTRL, TX0_IBOOST,
			      pdata->mode_cfg->tx_iboost[0]);

		break;

	default:
		break;
	}

	val = XPCS_RGRD(pdata, PMA_AFE_DFE_EN_CTRL);

	XPCS_SET_VAL(val, PMA_AFE_DFE_EN_CTRL, AFE_EN_0,
		     pdata->mode_cfg->afe_en);
	XPCS_SET_VAL(val, PMA_AFE_DFE_EN_CTRL, AFE_EN_3_1,
		     pdata->mode_cfg->afe_en_31);
	XPCS_SET_VAL(val, PMA_AFE_DFE_EN_CTRL, DFE_EN_0,
		     pdata->mode_cfg->dfe_en);
	XPCS_SET_VAL(val, PMA_AFE_DFE_EN_CTRL, DFE_EN_3_1,
		     pdata->mode_cfg->dfe_en_31);

	XPCS_RGWR(pdata, PMA_AFE_DFE_EN_CTRL, val);

	XPCS_RGWR_VAL(pdata, PMA_RX_EQ_CTRL4, CONT_ADAPT_0,
		      pdata->mode_cfg->cont_adapt0);
	XPCS_RGWR_VAL(pdata, PMA_RX_EQ_CTRL4, CONT_ADAPT_3_1,
		      pdata->mode_cfg->cont_adapt31);

	if (pdata->mpllb) {
		mplla_ctrl2 = XPCS_RGRD(pdata, PMA_MPLLB_C2);

		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLB_C2, MPLLB_DIV_CLK_EN,
			     pdata->mode_cfg->mpllb_div_clk_en);
		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLB_C2, MPLLB_DIV10_CLK_EN,
			     pdata->mode_cfg->mpllb_div10_clk_en);
		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLB_C2, MPLLB_DIV8_CLK_EN,
			     pdata->mode_cfg->mpllb_div8_clk_en);

		XPCS_RGWR(pdata, PMA_MPLLB_C2, mplla_ctrl2);

		XPCS_RGWR_VAL(pdata, PMA_VCO_CAL_LD1, VCO_LD_VAL_1,
			      pdata->mode_cfg->vco_ld_val[1]);
	} else {
		mplla_ctrl2 = XPCS_RGRD(pdata, PMA_MPLLA_C2);

		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLA_C2, MPLLA_DIV16P5_CLK_EN,
			     pdata->mode_cfg->mplla_div165_clk_en);
		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLA_C2, MPLLA_DIV10_CLK_EN,
			     pdata->mode_cfg->mplla_div10_clk_en);
		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLA_C2, MPLLA_DIV8_CLK_EN,
			     pdata->mode_cfg->mplla_div8_clk_en);
		XPCS_SET_VAL(mplla_ctrl2, PMA_MPLLA_C2, MPLLA_DIV_CLK_EN,
			     pdata->mode_cfg->mplla_div_clk_en);

		XPCS_RGWR(pdata, PMA_MPLLA_C2, mplla_ctrl2);
	}

	tx_eq0 = XPCS_RGRD(pdata, PMA_TX_EQ_C0);

	XPCS_SET_VAL(tx_eq0, PMA_TX_EQ_C0, TX_EQ_MAIN,
		     pdata->mode_cfg->tx_eq_main);
	XPCS_SET_VAL(tx_eq0, PMA_TX_EQ_C0, TX_EQ_PRE,
		     pdata->mode_cfg->tx_eq_pre);

	XPCS_RGWR(pdata, PMA_TX_EQ_C0, tx_eq0);

	tx_eq1 = XPCS_RGRD(pdata, PMA_TX_EQ_C1);

	XPCS_SET_VAL(tx_eq1, PMA_TX_EQ_C1, TX_EQ_POST,
		     pdata->mode_cfg->tx_eq_post);
	XPCS_SET_VAL(tx_eq1, PMA_TX_EQ_C1, TX_EQ_OVR_RIDE,
		     pdata->mode_cfg->tx_eq_ovrride);

	XPCS_RGWR(pdata, PMA_TX_EQ_C1, tx_eq1);

	/* Tx Voltage Boost Maximum level,
	 * maximum achievable Tx swing in the PHY
	 */
	XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL1, VBOOST_EN_0, 1);

	XPCS_RGWR_VAL(pdata, PMA_TX_GENCTRL1, VBOOST_LVL,
		      pdata->mode_cfg->vboost_lvl);
}

/* Switch to 10G XAUI Mode in 12G gen5 PHY */
static int xpcs_teng_xaui_mode(struct xpcs_prv_data *pdata)
{
	if (xpcs_byp_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Use internal clock */
	XPCS_RGWR_VAL(pdata, PMA_REF_CLK_CTRL, REF_USE_PAD, 0);

	/* Setting SS13 bit PMA side */
	xpcs_teng_mode(pdata);

	XPCS_RGWR_VAL(pdata, PCS_XAUI_CTRL, XAUI_MODE, 0);

	XPCS_RGWR_VAL(pdata, PCS_CTRL2, PCS_TYPE_SEL,
		      pdata->mode_cfg->pcs_type);

	/* Setting SS13 bit of PCS side */
	XPCS_RGWR_VAL(pdata, PCS_CTRL1, SS13, 1);

	/* Select MPLLB for XAUI/10GBASE-KX4
	 * When this bit is set, PHY selects MPLLB to generate
	 * Tx analog clocks on lane 0
	 */
	if (pdata->mpllb) {
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_3_1, 0);
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_0, 1);
	} else {
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_3_1, 0);
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_0, 0);
	}

	xpcs_cfg_table(pdata);

	/* PHY LOS threshold register */
	XPCS_RGWR(pdata, PMA_RX_GENCTRL3, pdata->mode_cfg->los_thr);

	/* PHY ctle_pole and boost and gain register */
	XPCS_RGWR(pdata, PMA_RX_EQ_CTRL0, pdata->mode_cfg->phy_boost_gain_val);

	/* Rx Biasing Current Control for Rx analog front end */
	XPCS_RGWR_VAL(pdata, PMA_MISC_C0, RX_VREF_CTRL,
		      pdata->mode_cfg->rx_vref_ctrl);

	/* Link Up and Down, No Configuration reset */
	if (xpcs_vs_reset(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	if (!strcmp(pdata->conntype, "SFP")) {
		/* Disable Autoneg */
		XPCS_RGWR_VAL(pdata, AN_CTRL, AN_EN, 0);
	} else {
		xpcs_cl73_an(pdata);
	}

	return XPCS_SUCCESS;
}

/* Switch to 10G KR Mode in 12G gen5 PHY */
static int xpcs_teng_kr_mode(struct xpcs_prv_data *pdata)
{
	if (xpcs_byp_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Use internal clock */
	XPCS_RGWR_VAL(pdata, PMA_REF_CLK_CTRL, REF_USE_PAD, 0);

	/* Setting SS13 bit PMA side */
	xpcs_teng_mode(pdata);

	if (xpcs_enable_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	XPCS_RGWR_VAL(pdata, PCS_CTRL2, PCS_TYPE_SEL,
		      pdata->mode_cfg->pcs_type);

	/* 10GBASE-KR PMA or PMD type */
	XPCS_RGWR_VAL(pdata, PMA_CTRL2, PMA_TYPE,
		      pdata->mode_cfg->pma_type);

	xpcs_cfg_table(pdata);

	/* PHY LOS threshold register */
	XPCS_RGWR(pdata, PMA_RX_GENCTRL3, pdata->mode_cfg->los_thr);

	/* PHY ctle_pole and boost and gain register */
	XPCS_RGWR(pdata, PMA_RX_EQ_CTRL0, pdata->mode_cfg->phy_boost_gain_val);

	XPCS_RGWR(pdata, PMA_REF_CLK_CTRL, pdata->mode_cfg->ref_clk_ctrl);

	/* Link Up and Down, No Configuration reset */
	if (xpcs_vs_reset(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* If connected to SFP module CL73 Auto-negotiation need to be
	 * disabled
	 */
	if (!strcmp(pdata->conntype, "SFP")) {
		/* Disable Autoneg */
		XPCS_RGWR_VAL(pdata, AN_CTRL, AN_EN, 0);
	} else {
		xpcs_cl73_an(pdata);
	}

	return XPCS_SUCCESS;
}

/*
 * Speed     mode  SS6 SS13
 * 1000 Mbps SGMII 1   0
 * 100 Mbps  SGMII 0   1
 * 10 Mbps   SGMII 0   0
 */
/* 1G XAUI Mode */
static int xpcs_oneg_xaui_mode(struct xpcs_prv_data *pdata)
{
	pdata->sgmii_type = PHY_SIDE_SGMII;

	if (xpcs_byp_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Use internal clock */
	XPCS_RGWR_VAL(pdata, PMA_REF_CLK_CTRL, REF_USE_PAD, 0);

	xpcs_oneg_mode(pdata);

	if (xpcs_enable_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Set to XAUI mode */
	XPCS_RGWR_VAL(pdata, PCS_XAUI_CTRL, XAUI_MODE, 0);

	/* When this field is written with 2'b00, the KR
	 * speed mode is selected. When this field is written with a value other
	 * than 2'b00, the KR speed mode is de-selected and non-KR speed
	 * mode (KX4 or KX) is selected
	 */
	XPCS_RGWR_VAL(pdata, PCS_CTRL2, PCS_TYPE_SEL,
		      pdata->mode_cfg->pcs_type);

	/* PMA_TYPE_1G_BASE_KX */
	XPCS_RGWR_VAL(pdata, PMA_CTRL2, PMA_TYPE,
		      pdata->mode_cfg->pma_type);

	/* 1Gbps SGMII Mode */
	XPCS_RGWR_VAL(pdata, SR_MII_CTRL, SS13, 0);
	XPCS_RGWR_VAL(pdata, SR_MII_CTRL, SS6, 1);

	xpcs_cfg_table(pdata);

	/* PHY LOS threshold register */
	XPCS_RGWR(pdata, PMA_RX_GENCTRL3, pdata->mode_cfg->los_thr);

	/* PHY ctle_pole and boost and gain register */
	XPCS_RGWR(pdata, PMA_RX_EQ_CTRL0, pdata->mode_cfg->phy_boost_gain_val);

	/* Rx Biasing Current Control for Rx analog front end */
	XPCS_RGWR_VAL(pdata, PMA_MISC_C0, RX_VREF_CTRL,
		      pdata->mode_cfg->rx_vref_ctrl);

	XPCS_RGWR(pdata, PMA_REF_CLK_CTRL, pdata->mode_cfg->ref_clk_ctrl);

	/* Link Up and Down, No Configuration reset */
	if (xpcs_vs_reset(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Enable Clause 37 Auto-negotiation */
	xpcs_cl37_an(pdata);

	return XPCS_SUCCESS;
}

/* 2.5G SGMII Mode */
static int xpcs_2p5g_sgmii_mode(struct xpcs_prv_data *pdata)
{
	/* we do not init wan xpcs */
	pdata->mpllb = 1;

	if (xpcs_byp_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* Use internal clock */
	XPCS_RGWR_VAL(pdata, PMA_REF_CLK_CTRL, REF_USE_PAD, 0);

	xpcs_2p5g_mode(pdata);

	if (xpcs_enable_pwrupseq(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	/* XAUI Mode to 0 to disable RXAUI Mode */
	XPCS_RGWR_VAL(pdata, PCS_XAUI_CTRL, XAUI_MODE, 0);

	/* Set PCS_Type=1 to disable KR Mode */
	XPCS_RGWR_VAL(pdata, PCS_CTRL2, PCS_TYPE_SEL,
		      pdata->mode_cfg->pcs_type);

	/* Set 1GBASE-KX PCS Type */
	XPCS_RGWR_VAL(pdata, PMA_CTRL2, PMA_TYPE,
		      pdata->mode_cfg->pma_type);

	/* 2.5G GMII Mode operation for 1000BaseX PCS Configuration */
	XPCS_RGWR_VAL(pdata, VR_MII_DIG_CTRL1, EN_2_5G_MODE, 1);

	/* SGMII Mode */
	XPCS_RGWR_VAL(pdata, SR_MII_CTRL, SS13, 0);
	XPCS_RGWR_VAL(pdata, SR_MII_CTRL, SS6, 1);

	if (pdata->mpllb) {
		/* Select MPLLB for XAUI/10GBASE-KX4 */
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_3_1, 0);
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_0, 1);
	} else {
		/* De-Select MPLLB for XAUI/10GBASE-KX4 */
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_3_1, 0);
		XPCS_RGWR_VAL(pdata, PMA_MPLL_CMN_CTRL, MPLLB_SEL_0, 0);
	}

	xpcs_cfg_table(pdata);

	/* Receiver Divide by 16.5 output clock on lane 0 */
	XPCS_RGWR_VAL(pdata, PMA_RX_GENCTRL1, RX_DIV16P5_CLK_EN,
		      pdata->mode_cfg->rx_div165_clk_en);

	/* PHY LOS threshold register */
	XPCS_RGWR(pdata, PMA_RX_GENCTRL3, pdata->mode_cfg->los_thr);

	/* PHY ctle_pole and boost and gain register */
	XPCS_RGWR(pdata, PMA_RX_EQ_CTRL0, pdata->mode_cfg->phy_boost_gain_val);

	/* Rx Biasing Current Control for Rx analog front end */
	XPCS_RGWR_VAL(pdata, PMA_MISC_C0, RX_VREF_CTRL,
		      pdata->mode_cfg->rx_vref_ctrl);


	/* Select CR Para Port This bit select the interface for accessing
 	 * PHY registers: * 0 -JTAG * 1 -CR parallel port This bit should be
	 * changed only after disabling 'jtag_tck'to PHY.
 	 */
	XPCS_RGWR_VAL(pdata, PMA_MISC_C0, CR_PARA_SEL, 1);

	XPCS_RGWR(pdata, PMA_REF_CLK_CTRL, pdata->mode_cfg->ref_clk_ctrl);

	/* Link Up and Down, No Configuration reset */
	if (xpcs_vs_reset(pdata) != XPCS_SUCCESS)
		return XPCS_FAILURE;

	return XPCS_SUCCESS;
}
/* Programming seq to enable Clause 37 Autonegotiation */
static void xpcs_cl37_an(struct xpcs_prv_data *pdata)
{
	/* Disable CL73 Autoneg */
	XPCS_RGWR_VAL(pdata, AN_CTRL, AN_EN, 0);

	/* Enable Backplane CL37 Autonegotiation */
	XPCS_RGWR_VAL(pdata, PCS_DIG_CTRL1, CL37_BP, 1);

	/* Enable CL37 Autoneg */
	XPCS_RGWR_VAL(pdata, SR_MII_CTRL, AN_ENABLE, 1);

	/* PCS_Mode = 2 SGMII Mode */
	XPCS_RGWR_VAL(pdata, VR_MII_AN_CTRL, PCS_MODE, 2);

	/* Enables the generation of Clause 37 autonegotiation complete
	 * interrupt output
	 */
	XPCS_RGWR_VAL(pdata, VR_MII_AN_CTRL, MII_AN_INTR_EN, 1);

	/* We are using PHY_SIDE_SGMII */
	if (pdata->sgmii_type == PHY_SIDE_SGMII) {
		/* PHY Side SGMII */
		XPCS_RGWR_VAL(pdata, VR_MII_AN_CTRL, TX_CONFIG, 1);
		/* 1 Full Duplex, 0 Half Duplex */
		XPCS_RGWR_VAL(pdata, SR_MII_CTRL, DUPLEX_MODE, 1);

	} else {
		/* MAC Side SGMII */
		XPCS_RGWR_VAL(pdata, VR_MII_AN_CTRL, TX_CONFIG, 0);
	}

	/* 8-BIT MII Interface */
	XPCS_RGWR_VAL(pdata, VR_MII_AN_CTRL, MII_CONTROL, 1);

	/* Automatic Speed Mode Change after CL37 AN, xpcs automatically
	 * switches to the negotiated SGMII/USXGMII/QSGMII(port0) speed, after
	 * the completion of Clause 37 auto-negotiation.
	 */
	XPCS_RGWR_VAL(pdata, VR_MII_DIG_CTRL1, MAC_AUTO_SW, 0);

	/* 2.5G Mode */
	if (!strcmp(pdata->mode, "2P5G_SGMII_MODE")) {
		/* Link timer runs for 1.6 ms */
		XPCS_RGWR(pdata, VR_MII_LINK_TIMER_CTRL, 0x07A1);

		/* If this bit is set, the value programmed to
		 * VR MII MMD Link Timer Control Register will be used to
		 * compute the duration of Link Timer.
		 */
		XPCS_RGWR_VAL(pdata, VR_MII_DIG_CTRL1, CL37_TMR_OVR_RIDE, 1);
	}
}

/* Programming seq to enable Clause 73 Autonegotiation */
static void xpcs_cl73_an(struct xpcs_prv_data *pdata)
{
	/* Enable Autoneg */
	XPCS_RGWR_VAL(pdata, AN_CTRL, AN_EN, 1);

	/* Link Fail Inhibit/Autoneg Wait Timer Value for
	 * Clause 73 autonegotiation.
	 */
	XPCS_RGWR_VAL(pdata, AN_TIMER_CTRL1, INHBT_OR_WAIT_TIME, 0xF);

	/* Over-Ride Control for Clause 73 Auto-negotiation Timers. */
	XPCS_RGWR_VAL(pdata, AN_DIG_CTRL, CL73_TMR_OVR_RIDE, 1);

	/* Enable the AN Complete Interrupt, An Incompatible Link
	 * Interrupt, An page received Interrupt enable
	 */
	XPCS_RGWR(pdata, AN_INTR_MSK, 7);

	/* Restart Autoneg */
	XPCS_RGWR_VAL(pdata, AN_CTRL, RSTRT_AN, 1);

	/* Start Training */
	xpcs_cl72_startup(pdata);
}

/* If this bit is set before or during Clause 73 auto-negotiation, the
 * training starts after all pages have been exchanged during Clause
 * 73 auto-negotiation.
 */
static void xpcs_cl72_startup(struct xpcs_prv_data *pdata)
{
	/* Enable the 10G-Base-KR start up protocol */
	XPCS_RGWR_VAL(pdata, PMA_KR_PMD_CTRL, TR_EN, 1);
}

static void get_serdes_config(struct xpcs_prv_data *pdata,
			int serdes_number)
{
	char serdes_pre[18];
	char serdes_post[18];
	char serdes_main[18];
	unsigned long cfg;
	unsigned long default_val = 0xFFFF;

	/* just a check (to prevent overflow), we only init 3 serdes */
	if (serdes_number > 3)
		return;

	snprintf(serdes_pre, sizeof(serdes_pre) / sizeof(char),
			"serdes%d_tx_pre", serdes_number);
	snprintf(serdes_post, sizeof(serdes_pre) / sizeof(char),
			"serdes%d_tx_post", serdes_number);
	snprintf(serdes_main, sizeof(serdes_pre) / sizeof(char),
			"serdes%d_tx_main", serdes_number);

	/* pre value */
	cfg = getenv_ulong(serdes_pre, 16, default_val);
	if (cfg != default_val)
		pdata->mode_cfg->tx_eq_pre = cfg;
	else
		pdata->mode_cfg->tx_eq_pre =
			SERDES_CFG(PRE, serdes_number);

	/* post value */
	cfg = getenv_ulong(serdes_post, 16, default_val);
	if (cfg != default_val)
		pdata->mode_cfg->tx_eq_post = cfg;
	else
		pdata->mode_cfg->tx_eq_post =
			SERDES_CFG(POST, serdes_number);

	/* main value */
	cfg = getenv_ulong(serdes_main, 16, default_val);
	if (cfg != default_val)
		pdata->mode_cfg->tx_eq_main = cfg;
	else
		pdata->mode_cfg->tx_eq_main =
			SERDES_CFG(MAIN, serdes_number);

	xpcs_printf("serdes%d_pre: 0x%08x\n", serdes_number,
			pdata->mode_cfg->tx_eq_pre);
	xpcs_printf("serdes%d_main: 0x%08x\n", serdes_number,
			pdata->mode_cfg->tx_eq_main);
	xpcs_printf("serdes%d_post: 0x%08x\n", serdes_number,
			pdata->mode_cfg->tx_eq_post);

}

static int xpcs_init(struct xpcs_prv_data *pdata, int serdes_number)
{
	int ret = XPCS_SUCCESS;

	pdata->pcs_mode = BACKPL_ETH_PCS;

	xpcs_printf("Addr Base %x\n", pdata->addr_base);

	/* Default all 3 XPCS in 10G KR Mode, if need to change, Change DT */
	if (!strcmp(pdata->mode, "10G_KR_MODE")) {
		pdata->mode_cfg = &mode_cfg[TENG_KR_MODE];
		get_serdes_config(pdata, serdes_number);
		ret = xpcs_teng_kr_mode(pdata);
		if (ret == XPCS_SUCCESS)
			xpcs_printf("%s: 10G_KR_MODE Initialized\n",
				    pdata->name);
		else
			xpcs_printf("%s: 10G_KR_MODE :::: Failed ::::\n",
				    pdata->name);
	} else if (!strcmp(pdata->mode, "10G_XAUI_MODE")) {
		pdata->mode_cfg = &mode_cfg[TENG_XAUI_MODE];
		get_serdes_config(pdata, serdes_number);
		pdata->mpllb = 0;
		ret = xpcs_teng_xaui_mode(pdata);

		if (ret == XPCS_SUCCESS)
			xpcs_printf("%s: 10G_XAUI_MODE Initialized\n",
				    pdata->name);
		else
			xpcs_printf("%s: 10G_XAUI_MODE :::: Failed ::::\n",
				    pdata->name);

	} else if (!strcmp(pdata->mode, "1G_XAUI_MODE")) {
		pdata->mode_cfg = &mode_cfg[ONEG_XAUI_MODE];
		get_serdes_config(pdata, serdes_number);
		pdata->speed = SPEED_1G;
		pdata->sgmii_type = PHY_SIDE_SGMII;
		ret = xpcs_oneg_xaui_mode(pdata);

		if (ret == XPCS_SUCCESS)
			xpcs_printf("%s: 1G_XAUI_MODE Initialized\n",
				    pdata->name);
		else
			xpcs_printf("%s: 1G_XAUI_MODE :::: Failed ::::\n",
				    pdata->name);

	} else if (!strcmp(pdata->mode, "2P5G_SGMII_MODE")) {
		pdata->mode_cfg = &mode_cfg[TWOP5G_SGMII_MODE];
		get_serdes_config(pdata, serdes_number);
		ret = xpcs_2p5g_sgmii_mode(pdata);

		if (ret == XPCS_SUCCESS)
			xpcs_printf("%s: 2.5G_GMII_MODE Initialized\n",
					pdata->name);
		else
			xpcs_printf("%s: 2.5G_GMII_MODE :::: Failed ::::\n",
					pdata->name);

	} else {
		xpcs_printf("Invalid Mode for XPCS %s", pdata->name);
		ret = XPCS_FAILURE;
	}

	if (ret != XPCS_SUCCESS)
		return ret;
	return ret;
}

static struct xpcs_prv_data xpcs_data[3] = {
	{
		.id = 0,
		.num_resources = 0,
		.addr_base = XPCS0_BASE_ADD,
		.dev = NULL,
		.name = "XGMAC3",
		.mode = "10G_KR_MODE",
		.irq_num = 0,
		.pcs_mode = BACKPL_ETH_PCS,
		.sgmii_type = PHY_SIDE_SGMII,
		.speed = TENG_KR_MODE,
		.duplex = 1, /* FULL Duplex */
		.mpllb = 0,
		.conntype = "SFP",
		.mode_cfg = NULL,

	},
	{
		.id = 1,
		.num_resources = 0,
		.addr_base = XPCS1_BASE_ADD,
		.dev = NULL,
		.name = "XGMAC4",
		.mode = "1G_XAUI_MODE",
		.irq_num = 0,
		.pcs_mode = BACKPL_ETH_PCS,
		.sgmii_type = PHY_SIDE_SGMII,
		.speed = TENG_KR_MODE,
		.duplex = 1, /* FULL Duplex */
		.mpllb = 0,
		.conntype = "SFP",
		.mode_cfg = NULL,
	},
	{
		.id = 2,
		.num_resources = 0,
		.addr_base = WAN_XPCS_BASE_ADD,
		.dev = NULL,
		.name = "XGMAC2",
		.mode = "1G_XAUI_MODE",
		.irq_num = 0,
		.pcs_mode = BACKPL_ETH_PCS,
		.sgmii_type = PHY_SIDE_SGMII,
		.speed = TENG_KR_MODE,
		.duplex = 1, /* FULL Duplex */
		.mpllb = 0,
		.conntype = "SFP",
		.mode_cfg = NULL,
	},
};

#define COMBO_PHY0_APPL_BASE		0x1A300000UL
#define COMBO_PHY1_APPL_BASE		0x1A800000UL
#define WAN_PHY_APPL_BASE		0x18C00000UL

#define PHY_GEN_CTRL			0x00
#define PHY_MPLLA_CTRL			0x10
#define PHY_MPLLB_CTRL			0x14

#define LJPLL3_LOCK_POLL_CNT		5000

static void ljpll3_cfg_integ_cdr(void)
{
	int i;
	u32 val;
	unsigned int postdiv0_a = 0x4, postdiv1_b = 0x1;
	unsigned int postdiv2_b = 0x1, postdiv_3a = 0x4;

	/* Start LJPLL3 Integer Mode 156.25MHz refclk
	 * for CDR bring up refclk config: LJPLL3_CFG0
	 */

	ltq_w32(CGU_MODULE_BASE, PLL3_CFG0, 0);

	val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG2);
	val &= ~(0xFFF << 0);
	val |= 250 << 0;	/* FBDIV Bit 11:0 LJPLL Feedback Divider (250 = 0xFA). 10G VCO */
	val &= ~(0x3F << 18);
	val |= 1 << 18; 	/* REFDIV Bit 23:18 PLL Reference Clock Input Divider (1 = 0x1) */
	val &= ~(0x1 << 24);	/* BYPASS0 Bit 24 FOUT0 Bypass */
	val &= ~(0x1 << 25);	/* BYPASS0 Bit 25 FOUT1 Bypass */
	val &= ~(0x1 << 26);	/* BYPASS0 Bit 26 FOUT2 Bypass */
	val &= ~(0x1 << 27);	/* BYPASS0 Bit 27 FOUT3 Bypass */
	val |= 0x1 << 28;	/* FREFCMLEN Bit 28 0h = CMOS Mode; 1h = CML Mode. Enable Reference Clock CML Mode */
	ltq_w32(CGU_MODULE_BASE, PLL3_CFG2, val);

	/* Start PLL3_CFG0 config */
	val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG0);
	val |= 0x3 << 30;	/* DACEN Bit 30 (0h DAC is disable, 1h DAC is enable) */
	ltq_w32(CGU_MODULE_BASE, PLL3_CFG0, val);	/* Should get back 0x4000 0003 */

	/* Start LJPLL3 config: PLL3_CFG1 */
	val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG1);
	val &= ~(0x7 << 0);
	val |= postdiv0_a << 0;
	val &= ~(0x7 << 3);
	val |= 0x4 << 3;	/* POST_DIV0B Bit 5:3 2nd post divide value for FOUTCML0P/N (nominal 50% duty cycle). VCO  10G */
	val &= ~(0x7 << 6);
	val |= 0x7 << 6;	/* POST_DIV1A Bit 8:6 First post divide value for FOUTCML1P/N (nominal 50% duty cycle) */
	val &= ~(0x7 << 9);
	val |= postdiv1_b << 9;
	val &= ~(0x7 << 12);
	val |= 0x0 << 12;	/* POST_DIV2A Bit 14:12 First post divide value for FOUTCML2P/N (nominal 50% duty cycle) */
	val &= ~(0x7 << 15);
	val |= postdiv2_b << 15;
	val &= ~(0x7 << 18);
	val |= postdiv_3a << 18;
	val &= ~(0x7 << 21);
	val |= 0x0 << 21;	/* POST_DIV3B Bit 23:21 2nd post divide value for FOUTCML3P/N (nominal 50% duty cycle). VCO 10G */
	val &= ~(0x1 << 29);
	val |= 0x1 << 29;	/* POST_DIV0PRE Bit 29 Enable for Pre-Divide for FOUTCML0N/P */
	ltq_w32(CGU_MODULE_BASE, PLL3_CFG1, val);

	/* Disable DPLL, set to 0 */
	val = ltq_r32(CGU_MODULE_BASE, DPLL_CTRL);
	val &= ~(0x1 << 0);	/* DPLL_CTRL Bit 0. 0h = Disable DPLL; 1h = Enable DPLL */
	ltq_w32(CGU_MODULE_BASE, DPLL_CTRL, val);

	val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG0);
	val |= 0x1 << 0;	/* PLLEN Bit 0 (0h Disable, 1h Enable) */
	ltq_w32(CGU_MODULE_BASE, PLL3_CFG0, val);

	for (i = 0; i < LJPLL3_LOCK_POLL_CNT; i++) {
		val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG0);
		if ((val & PLL3_CFG0_LOCK_MASK))
			break;
		udelay(10);
	}

	if (i >= LJPLL3_LOCK_POLL_CNT)
		xpcs_printf("LJPLL3 Lock failed\n");

	/* Enable all PLL3_CFG1 FOUT0-3 after PLL lock. */
	val = ltq_r32(CGU_MODULE_BASE, PLL3_CFG1);
	val |= 0x1 << 25;	/* FOUT1EN Bit 25 PLL Clock Output 1 Enable */
	val |= 0x1 << 26;	/* FOUT2EN Bit 26 PLL Clock Output 2 Enable */
	val |= 0x1 << 24;	/* FOUT0EN Bit 24 PLL Clock Output 0 Enable */
	val |= 0x1 << 27;	/* FOUT3EN Bit 27 PLL Clock Output 3 Enable */

	ltq_w32(CGU_MODULE_BASE, PLL3_CFG1, val);

	udelay(1000);
}

static void cgu_config(void)
{
	u32 val;

	/* Configure LJPLL3 to 156.25Mhz */
	ljpll3_cfg_integ_cdr();

	val = ltq_r32(CGU_MODULE_BASE, CGU_IF_CLK);
	/* Enable CML MUX enable for serdes PHY0/1 internal reference clock */
	val |= 3 << 24;
	val &= ~(0x1 << 0);	/* PLL5_PLL3_SEL (0h LJPLL3, 1h LJPLL5 to WAN PHY refclk) */
	val |= 0x1 << 4;	/* SW_REFCLK_EN (0h WAN PHY Internal CLK disabled, 1h WAN PHY Internal CLK enabled) */
	val &= ~(1 << 5);	/* SW_HW_REFCLK_EN_SEL (0h SWControlled by configuration "SW_REFCLK_EN", 1h HWControlled by hardware signal) */
	val |= (1 << 12);

	ltq_w32(CGU_MODULE_BASE, CGU_IF_CLK, val);
}

#define REG_DBG(base, reg)		do {				\
	u32 val = ltq_r32(base, reg);					\
	xpcs_printf("%s: " #reg " = %08x\n", __FUNCTION__, val);	\
} while (0)

	/* Initialize XPCS */
void prx300_xpcs_init(char **link_mode)
{
	unsigned int i;
	int ret;
	u32 val;

	if (!link_mode)
		return;

	/* use internal clock for 2 serdes */
	ltq_w32(COMBO_PHY0_APPL_BASE, PHY_GEN_CTRL,
		(ltq_r32(COMBO_PHY0_APPL_BASE, PHY_GEN_CTRL) & ~BIT(17)));
	ltq_w32(COMBO_PHY1_APPL_BASE, PHY_GEN_CTRL,
		(ltq_r32(COMBO_PHY1_APPL_BASE, PHY_GEN_CTRL) & ~BIT(17)));

	cgu_config();
	xpcs_printf("\n");
	REG_DBG(RCU_MODULE_BASE, RST_REQ);
	REG_DBG(CHIP_TOP_MODULE_BASE, IFMUX_CFG);
	REG_DBG(COMBO_PHY0_APPL_BASE, PHY_GEN_CTRL);
	REG_DBG(COMBO_PHY1_APPL_BASE, PHY_GEN_CTRL);
	REG_DBG(WAN_PHY_APPL_BASE, PHY_GEN_CTRL);
	REG_DBG(CGU_MODULE_BASE, PLL3_CFG0);
	REG_DBG(CGU_MODULE_BASE, PLL3_CFG1);
	REG_DBG(CGU_MODULE_BASE, PLL3_CFG2);
	REG_DBG(CGU_MODULE_BASE, PLL5_CFG0);
	REG_DBG(CGU_MODULE_BASE, PLL5_CFG1);
	REG_DBG(CGU_MODULE_BASE, PLL5_CFG2);
	REG_DBG(CGU_MODULE_BASE, CGU_IF_CLK);
	REG_DBG(CGU_MODULE_BASE, CGU_PCMCR);

	for (i = 0; i < ARRAY_SIZE(xpcs_data) - 1; i++) {
		xpcs_data[i].mode = link_mode[i];

		/* skip WAN port init, not used in U-boot */
		if (xpcs_data[i].addr_base == WAN_XPCS_BASE_ADD)
			continue;

		printf("lan-%d config to %s, ", i, link_mode[i]);

		ret = xpcs_init(&xpcs_data[i], i);
		if (ret == XPCS_FAILURE) {
			printf("INVALID MODE: %s\n", link_mode[i]);
			printf("Available modes: 10G_KR_MODE, 10G_XAUI_MODE, "
				"1G_XAUI_MODE, 2P5G_SGMII_MODE\n");
			return;
		}

		mdelay(100);

		val = XPCS_RGRD_VAL(&xpcs_data[i], PCS_KR_STS1, RLU);
		xpcs_printf("%s: %s\n", xpcs_data[i].name, val
				? "Link Up" : "Link Down");
	}

	/* put WAN port to reset */
	val = (RST_REQ_PHY2_MASK | RST_REQ_XPCS2_MASK
			| RST_REQ_WANSS_MASK);
	ltq_w32(RCU_MODULE_BASE, RST_REQ, val);

	/* disable WAN clk */
	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A,
				ltq_r32(CGU_MODULE_BASE, GGU_CLKGSR1)
				& ~(CGU_CLKGCR1_A_SSO_MASK));

}
