/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef _CONFIG_ZYXEL_GX3502_H_
#define _CONFIG_ZYXEL_GX3502_H_

#define CONFIG_IDENT_STRING		" gx3502"
#define CONFIG_BOARD_NAME		"Zyxel gx5502 series [620, 621]"

#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_ONFI_DETECTION
#define CONFIG_SYS_NAND_PAGE_SIZE	0x800
#define CONFIG_SYS_NAND_BLOCK_SIZE	0x20000
#define CONFIG_SYS_NAND_PAGE_COUNT	(CONFIG_SYS_NAND_BLOCK_SIZE / \
					CONFIG_SYS_NAND_PAGE_SIZE)

#define CONFIG_SPL_U_BOOT_OFFS		0x40000
#define CONFIG_SPL_U_BOOT_SIZE		0x80000
#define CONFIG_LTQ_SPL_REDUND_IMAGES	1

#define CONFIG_MTD_UBI_BEB_LIMIT	20
#define CONFIG_ENV_UBI_VID_HDR_OFF	"2048"

#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_PHY_LANTIQ

#define MTDIDS_DEFAULT			"nand0=nand-cs1"
#define MTDPARTS_DEFAULT		\
	"mtdparts=nand-cs1:1792k(uboot_fix),1024k(calibration),-(ubi)"

#include <configs/xrx500_common.h>
#include <configs/gemini_env.h>

#define CONFIG_EXTRA_ENV_SETTINGS			\
	CONFIG_ENV_XRX500				\
	CONFIG_ENV_GEMINI

#endif /* _CONFIG_ZYXEL_GX5502_H_ */
