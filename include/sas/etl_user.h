/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#ifndef __SAS_ETL_USER_H__
#define __SAS_ETL_USER_H__

enum sas_etl_id
{
	SAS_ETL_HW_VERSION		= 1,
	SAS_ETL_SERIAL			= 2,
	SAS_ETL_PROD_DATE		= 3,
	SAS_ETL_WLAN_MODULE		= 4,
	SAS_ETL_WLAN_KEY		= 5,
	SAS_ETL_TRIV_NAME		= 6,
	SAS_ETL_MAC_ADDR		= 7,
	SAS_ETL_HW_CFG			= 8,
	SAS_ETL_HW_CFG2			= 9,
	SAS_ETL_IDENT_NO		= 10,
	SAS_ETL_CUSTOMER		= 11,
	SAS_ETL_BASE_PLATFORM		= 12,
	SAS_ETL_WPS_PIN			= 13,
	SAS_ETL_LEDCFG			= 14,
	SAS_ETL_WLANCFG			= 15,
	SAS_ETL_WLAN_SSID		= 16,
	SAS_ETL_FLASH_LAYOUT		= 17,
	SAS_ETL_EXTRA_SPACE_SIZE	= 18,
	SAS_ETL_JFFS_IMAGES		= 19,
	SAS_ETL_SERIAL_EXTRA		= 20,
	SAS_ETL_SHDSL_LINES		= 21,
	SAS_ETL_MAC_ADDR_POOL		= 22,
	SAS_ETL_DATA_PART_SIZE		= 23,
	SAS_ETL_DATA_PART_LOC		= 24,
	SAS_ETL_ACS_AUTH		= 25,
	SAS_ETL_WLAN_SSID_EXTRA		= 26,
	SAS_ETL_GUI_AUTH		= 27,
	SAS_ETL_ID_LAST,
};

typedef enum sas_etl_id sas_etl_id_t;

struct sas_hw_cfg
{
	unsigned FXO : 1;
	unsigned S0_ext : 1;
	unsigned S0_int : 1;
	unsigned ab_count : 2;
	unsigned switch_ic : 1;
	unsigned USB : 1;
	unsigned metering_hw : 1;
};

struct sas_hw_cfg2
{
	unsigned reserved0 : 4;
	unsigned fxs_ringvoltage : 4;
	unsigned S0_int_count : 7;
	unsigned reserved1 : 1;
};

struct sas_led_cfg
{
	unsigned l01 : 1;
	unsigned l02 : 1;
	unsigned l03 : 1;
	unsigned l04 : 1;
	unsigned l05 : 1;
	unsigned l06 : 1;
	unsigned l07 : 1;
	unsigned l08 : 1;
	unsigned l09 : 1;
	unsigned l10 : 1;
	unsigned l11 : 1;
	unsigned l12 : 1;
	unsigned l13 : 1;
	unsigned l14 : 1;
	unsigned rsvd : 2;
};

enum sas_data_part_loc {
	DATA_PART_LOC_AUTO	= 0,
	DATA_PART_LOC_BOOT	= 1,
	DATA_PART_LOC_NAND	= 2,
	DATA_PART_LOC_INVALID,
};

static inline int sas_etl_is_string(enum sas_etl_id idx)
{
	switch (idx) {
	case SAS_ETL_HW_VERSION:
	case SAS_ETL_SERIAL:
	case SAS_ETL_PROD_DATE:
	case SAS_ETL_WLAN_MODULE:
	case SAS_ETL_WLAN_KEY:
	case SAS_ETL_TRIV_NAME:
	case SAS_ETL_MAC_ADDR:
	case SAS_ETL_CUSTOMER:
	case SAS_ETL_WPS_PIN:
	case SAS_ETL_WLAN_SSID:
	case SAS_ETL_FLASH_LAYOUT:
	case SAS_ETL_SERIAL_EXTRA:
	case SAS_ETL_ACS_AUTH:
	case SAS_ETL_IDENT_NO:
	case SAS_ETL_WLAN_SSID_EXTRA:
	case SAS_ETL_GUI_AUTH:
		return 1;
	default:
		return 0;
	}
}

static inline int sas_etl_is_integer(enum sas_etl_id idx)
{
	switch (idx) {
	case SAS_ETL_BASE_PLATFORM:
	case SAS_ETL_EXTRA_SPACE_SIZE:
	case SAS_ETL_JFFS_IMAGES:
	case SAS_ETL_SHDSL_LINES:
	case SAS_ETL_MAC_ADDR_POOL:
	case SAS_ETL_DATA_PART_SIZE:
	case SAS_ETL_DATA_PART_LOC:
		return 1;
	default:
		return 0;
	}
}

static inline int sas_etl_is_hex(enum sas_etl_id idx)
{
	switch (idx) {
	case SAS_ETL_HW_CFG:
	case SAS_ETL_HW_CFG2:
	case SAS_ETL_LEDCFG:
	case SAS_ETL_WLANCFG:
		return 1;
	default:
		return 0;
	}
}

static inline size_t sas_etl_hex_size(enum sas_etl_id idx)
{
	switch (idx) {
	case SAS_ETL_HW_CFG:
		return 1;
	case SAS_ETL_HW_CFG2:
	case SAS_ETL_LEDCFG:
		return 2;
	case SAS_ETL_WLANCFG:
		return 4;
	default:
		return 0;
	}
}

#define SAS_ETL_AREA_SIZE		256
#define SAS_ETL_VARIABLE_EMPTY_CHAR	0x78
#define SAS_ETL_MAX_VALUE_CHARS		40
#define SAS_ETL_V2_SIZE			256
#define SAS_ETL_DATA_PART_LOC_DEFAULT	DATA_PART_LOC_AUTO
#define SAS_ETL_DATA_PART_SIZE_DEFAULT	10

#endif /* __SAS_ETL_USER_H__ */
