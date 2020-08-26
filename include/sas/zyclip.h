/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2018 Sphairon GmbH (a ZyXEL company)
 */

#ifndef ZYCLIP_H
#define ZYCLIP_H

#include <linux/types.h>

struct mrd_format {
	u8 VendorName[32];
	u8 ProductName[32];
	u8 EtherAddr[6];
	u8 CountryCode[2];
	u8 FeatureBits[256];
};

/* MRD access macro */
#define NUM_OF_FEATURE_BITS_USED	32
#define LEN_BOOTBASE_VERSION		64

#define IS_DUAL_IM(x)			(((x)->FeatureBits[4])&0x1)
#define ARE_BOTH_FULL_FUNC(x)		(!(((x)->FeatureBits[4] >> 1)&0x1))
#define IS_SUPPORT_DEVICE_TREE(x)	(((x)->FeatureBits[4] >> 2)&0x1)
#define IS_MERGED_RAS(x)		(((x)->FeatureBits[4] >> 3)&0x1)
#define IS_DUAL_MRD_CERT(x)		(((x)->FeatureBits[4] >> 4)&0x1)

#define NUM_OF_ZBOOT_RESERVED_BLOCK	3
#define ZBOOT_PARTITION_SIZE		(ZBOOT_IMAGE_SIZE * NUM_OF_ZBOOT_RESERVED_BLOCK)
#define ZBOOT_IMAGE_SIZE		NAND_FLASH_BLOCK_SIZE

/* Dual image macro */
#define FIRST_IMAGE			1
#define SECOND_IMAGE			2

#define SAS_ZYCLIP_SIZE			328
#define SAS_ZYCLIP_OFFSET		0x0001feb8
#define SAS_ZYCLIP_PARTITION		cMTDUbootFixed

#define SAS_ZYCLIP_MAX_VALUE_CHARS	33

enum ZYCLIP_ID
{
	ZYCLIP_VENDOR_NAME		= 1,
	ZYCLIP_PRODUCT_NAME		= 2,
	ZYCLIP_MAC_ADDR			= 3,
	ZYCLIP_MAC_ADDR_POOL		= 4,
	ZYCLIP_COUNTRY_CODE		= 5,

	ZYCLIP_MODEL_NUMBER		= 6,
	ZYCLIP_IMAGE_PLAN		= 7,
	ZYCLIP_NUMBER_FLASHES		= 8,
	ZYCLIP_MAX_UPGRADE_CNT		= 9,
	ZYCLIP_DEBUG_FLAG		= 10,
	ZYCLIP_EMBED_FLAG		= 11,
	ZYCLIP_HW_VERSION		= 12,
	ZYCLIP_SERIAL_NUMBER		= 13,
	ZYCLIP_ID_LAST
};

/* sas_zyclip_init - initialize ZYCLIP subsystem */
int sas_zyclip_init(void);
int sas_zyclip_flash_read(unsigned long addr);

int sas_zyclip_import(unsigned long addr);
void sas_zyclip_dump(void);
int sas_zyclip_valid(void);

void sas_zyclip_update_etl(void);

static inline int sas_zyclip_is_integer(enum sas_etl_id idx)
{
	switch (idx) {
	case ZYCLIP_VENDOR_NAME:
	case ZYCLIP_PRODUCT_NAME:
		return 1;
	default:
		return 0;
	}
}

static inline int sas_zyclip_is_string(enum sas_etl_id idx)
{
	switch (idx) {
	case ZYCLIP_COUNTRY_CODE:
		return 1;
	default:
		return 0;
	}
}

#endif
