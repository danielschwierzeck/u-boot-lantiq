/*
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __DANUBE_SOC_H__
#define __DANUBE_SOC_H__

#define LTQ_ASC0_BASE			0x1E100400
#define LTQ_SPI_BASE			0x1E100800
#define LTQ_GPIO_BASE			0x1E100B00
#define LTQ_SSIO_BASE			0x1E100BB0
#define LTQ_ASC1_BASE			0x1E100C00
#define LTQ_DMA_BASE			0x1E104100

#define LTQ_EBU_BASE			0x1E105300
#define LTQ_EBU_REGION0_BASE		0x10000000
#define LTQ_EBU_REGION1_BASE		0x14000000
#define LTQ_EBU_NAND_BASE		(LTQ_EBU_BASE + 0xB0)

#define LTQ_PPE_BASE			0x1E180000
#define LTQ_PPE_ETOP_BASE		(LTQ_PPE_BASE + 0x11800)
#define LTQ_PPE_ENET0_BASE		(LTQ_PPE_BASE + 0x11840)

#define LTQ_PMU_BASE			0x1F102000
#define LTQ_CGU_BASE			0x1F103000
#define LTQ_MPS_BASE			0x1F107000
#define LTQ_CHIPID_BASE			(LTQ_MPS_BASE + 0x340)
#define LTQ_RCU_BASE			0x1F203000

#define LTQ_MC_GEN_BASE			0x1F800000
#define LTQ_MC_SDR_BASE			0x1F800200
#define LTQ_MC_DDR_BASE			0x1F801000
#define LTQ_MC_DDR_DC_OFFSET(x)		(x * 0x10)

#endif /* __DANUBE_SOC_H__ */
