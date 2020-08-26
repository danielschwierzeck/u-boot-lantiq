// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <linux/compiler.h>
#include <linux/stringify.h>

#include <sas/etl.h>
#include <sas/util.h>
#include <sas/flash.h>
#include <sas/zyclip.h>

static int sas_zyclip_val;
static struct mrd_format sas_zyclip_data;

int sas_zyclip_init(void)
{
	const unsigned long addr = CONFIG_LOADADDR;
	int ret;

	sas_zyclip_val = 0;
	memset(&sas_zyclip_data, 0x0, sizeof(sas_zyclip_data));

	ret = sas_zyclip_flash_read(addr);
	if (ret)
		return ret;

	return sas_zyclip_import(addr);
}

int sas_zyclip_valid(void)
{
	return sas_zyclip_val;
}

int sas_zyclip_flash_read(unsigned long addr)
{
	const struct sas_flash_partition *part;
	void *buf = (void *)addr;
	int ret;

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return 1;

	ret = sas_flash_read(part, SAS_ZYCLIP_OFFSET, SAS_ZYCLIP_SIZE, buf);

	if (ret && ret != -EUCLEAN)
		return 1;

	return 0;
}

int sas_zyclip_import(unsigned long addr)
{
	const u8 *buf = (const u8 *)addr;

	/* Check for empty flash and CLIP */
	if ((buf[0] == 0xff) || (buf[SAS_ZYCLIP_SIZE - 1] == 0xff)) {
		printf("ZYCLIP: no data available\n");
		return -ENOENT;
	}

	memcpy(&sas_zyclip_data, (const void *)addr, SAS_ZYCLIP_SIZE);
	sas_zyclip_val = 1;

	printf("ZYCLIP: Imported data\n");

	return 0;
}

static unsigned int SAS_ZYCLIP_getUInt(enum ZYCLIP_ID a_id)
{
	unsigned int val = 0;
	struct mrd_format *clip;

	clip = &sas_zyclip_data;

	switch (a_id) {
	case ZYCLIP_VENDOR_NAME:
		/* FALLTHROUGH */
	case ZYCLIP_PRODUCT_NAME:
		/* FALLTHROUGH */
	case ZYCLIP_SERIAL_NUMBER:
		/* FALLTHROUGH */
	case ZYCLIP_MAC_ADDR:
		break;
	case ZYCLIP_COUNTRY_CODE:
		val = (unsigned int) (clip->CountryCode[0] << 8 | clip->CountryCode[1]);
		break;
	case ZYCLIP_MAC_ADDR_POOL:
		val = (unsigned int) clip->FeatureBits[33];
		break;
	case ZYCLIP_DEBUG_FLAG:
		val = (unsigned int) clip->FeatureBits[10];
		break;
	case ZYCLIP_NUMBER_FLASHES:
		val = (unsigned int) clip->FeatureBits[5];
		break;
	case ZYCLIP_MAX_UPGRADE_CNT:
		val = (unsigned int) (clip->FeatureBits[6] << 24 | clip->FeatureBits[7] << 16 | clip->FeatureBits[8] << 8 | clip->FeatureBits[9]);
		break;
	case ZYCLIP_IMAGE_PLAN:
		val = (unsigned int) clip->FeatureBits[4];
		break;
	case ZYCLIP_MODEL_NUMBER:
		val = (unsigned int) (clip->FeatureBits[0] << 24 | clip->FeatureBits[1] << 16 | clip->FeatureBits[2] << 8 | clip->FeatureBits[3]);
		break;
	case ZYCLIP_HW_VERSION:
		val = (unsigned int)(clip->FeatureBits[34] << 16 | clip->FeatureBits[35] << 8 | clip->FeatureBits[36]);
		break;
	default:
		val = 0;
		break;
	}

	return val;
}

static int SAS_ZYCLIP_getString(enum ZYCLIP_ID a_id,
				char *a_buf,
				size_t a_len)
{
	struct mrd_format *clip;
	char *ptr = NULL;
	int val = 0;
	bool p_val = false;
	int ret = 0;

	if (!a_len)
		return -EINVAL;

	clip = &sas_zyclip_data;

	*a_buf = '\0';

	switch (a_id) {
	case ZYCLIP_VENDOR_NAME:
		ptr = (char *) &clip->VendorName;
		break;
	case ZYCLIP_PRODUCT_NAME:
		ptr = (char *) &clip->ProductName;
		break;
	case ZYCLIP_SERIAL_NUMBER:
		ptr = (char *) &clip->FeatureBits[37];
		break;
	case ZYCLIP_MAC_ADDR:
		ret = snprintf(a_buf, a_len, "%02x:%02x:%02x:%02x:%02x:%02x", clip->EtherAddr[0], clip->EtherAddr[1], 
					clip->EtherAddr[2], clip->EtherAddr[3], 
					clip->EtherAddr[4], clip->EtherAddr[5]);
		break;
	case ZYCLIP_COUNTRY_CODE:
		/* FALLTHROUGH */
	case ZYCLIP_MAC_ADDR_POOL:
		/* FALLTHROUGH */
	case ZYCLIP_DEBUG_FLAG:
		/* FALLTHROUGH */
	case ZYCLIP_NUMBER_FLASHES:
		/* FALLTHROUGH */
	case ZYCLIP_MAX_UPGRADE_CNT:
		/* FALLTHROUGH */
	case ZYCLIP_IMAGE_PLAN:
		/* FALLTHROUGH */
	case ZYCLIP_MODEL_NUMBER:
		/* FALLTHROUGH */
	case ZYCLIP_HW_VERSION:
		val = (int) SAS_ZYCLIP_getUInt(a_id);
		p_val = true;
		break;
	default:
		return 0;
		break;
	}

	if (ptr)
		ret = snprintf(a_buf, a_len, "%s", ptr);
	if (p_val == true)
		ret = snprintf(a_buf, a_len, "%x", val);

	return ret;
}

void sas_zyclip_dump(void)
{
	char buf[40];

	if (!sas_zyclip_valid())
		return;

	SAS_ZYCLIP_getString(ZYCLIP_VENDOR_NAME, buf, sizeof(buf));
	printf("Vendor Name:                      %s\n", buf);

	SAS_ZYCLIP_getString(ZYCLIP_PRODUCT_NAME, buf, sizeof(buf));
	printf("Product Name:                     %s\n", buf);

	SAS_ZYCLIP_getString(ZYCLIP_MAC_ADDR, buf, sizeof(buf));
	printf("Ethernet MAC address:             %s\n", buf);

	printf("Ethernet MAC address Quantity:    %d\n", SAS_ZYCLIP_getUInt(ZYCLIP_MAC_ADDR_POOL));
	printf("Country Code:                     %04X\n", SAS_ZYCLIP_getUInt(ZYCLIP_COUNTRY_CODE));

	SAS_ZYCLIP_getString(ZYCLIP_SERIAL_NUMBER, buf, sizeof(buf));
	printf("Serial Number:                    %s\n", buf);

	printf("Model ID:                         %04X\n", SAS_ZYCLIP_getUInt(ZYCLIP_MODEL_NUMBER));
	printf("HW Revision:                      %04X\n", SAS_ZYCLIP_getUInt(ZYCLIP_HW_VERSION));
	printf("Debug Flag:                       %01X\n", SAS_ZYCLIP_getUInt(ZYCLIP_DEBUG_FLAG));
	printf("Max upgrade count:                %02X\n", SAS_ZYCLIP_getUInt(ZYCLIP_MAX_UPGRADE_CNT));
	printf("IMAGE plan:                       0x%01X\n", SAS_ZYCLIP_getUInt(ZYCLIP_IMAGE_PLAN));
	printf("Number flashes:                   %01X\n", SAS_ZYCLIP_getUInt(ZYCLIP_NUMBER_FLASHES));
}

void sas_zyclip_update_etl(void)
{
	char buf[40];

	SAS_ZYCLIP_getString(ZYCLIP_PRODUCT_NAME, buf, sizeof(buf));
	sas_etl_set_value(SAS_ETL_IDENT_NO, buf);

	SAS_ZYCLIP_getString(ZYCLIP_SERIAL_NUMBER, buf, sizeof(buf));
	sas_etl_set_value(SAS_ETL_SERIAL, buf);

	SAS_ZYCLIP_getString(ZYCLIP_MAC_ADDR, buf, sizeof(buf));
	sas_etl_set_value(SAS_ETL_MAC_ADDR, buf);

	SAS_ZYCLIP_getString(ZYCLIP_VENDOR_NAME, buf, sizeof(buf));
	sas_etl_set_value(SAS_ETL_CUSTOMER, buf);

	SAS_ZYCLIP_getString(ZYCLIP_MAC_ADDR_POOL, buf, sizeof(buf));
	sas_etl_set_value(SAS_ETL_MAC_ADDR_POOL, buf);

	sas_etl_version_set_default();
}
