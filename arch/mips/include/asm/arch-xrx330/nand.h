/*
 * Copyright (C) 2015-2016 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __XRX330_NAND_H__
#define __XRX330_NAND_H__

enum ltq_hsnand_info {
	HSNAND_BIG_ENDIAN	= (1 << 0),
	HSNAND_ECC_NO_OOB	= (1 << 1),
	HSNAND_ECC_OFF		= (1 << 2),
	HSNAND_ECC_4BYTE	= (1 << 3),
	HSNAND_SAMSUNG_1K	= (1 << 4),
	HSNAND_SAMSUNG_2K	= (1 << 5),
	HSNAND_ONFI		= (1 << 6),
};

unsigned int ltq_boot_hsnand_info(void);

#endif /* __XRX330_NAND_H__ */
