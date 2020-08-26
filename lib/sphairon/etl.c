// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <linux/compiler.h>

#include <sas/etl.h>
#include <sas/util.h>
#include <sas/flash.h>

#if defined(CONFIG_BOARD_NAME)
#define BOARD_NAME	CONFIG_BOARD_NAME
#else
#define BOARD_NAME	""
#endif

#if defined(CONFIG_SPHAIRON_FLASHLAYOUT)
#define FLASHLAYOUT	CONFIG_SPHAIRON_FLASHLAYOUT
#else
#define FLASHLAYOUT	"pss"
#endif

struct sas_etl_map_entry {
	struct list_head link;
	enum sas_etl_id idx;
	char val[SAS_ETL_MAX_VALUE_CHARS];
};

static struct list_head sas_etl_map;
static int sas_etl_ver;

void sas_etl_init(void)
{
	INIT_LIST_HEAD(&sas_etl_map);
}

int sas_etl_load(void)
{
	const unsigned long addr = CONFIG_LOADADDR;
	int ret;

	ret = sas_etl_flash_read(addr);
	if (ret)
		return ret;

	return sas_etl_import(addr);
}

int sas_etl_flash_read(unsigned long addr)
{
	const struct sas_flash_partition *part;
	void *buf = (void *)addr;
	int eb, num, ret;

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return 1;

	for (eb = 0; eb < sas_flash_reserved_max_eb(); eb++) {
		for (num = 0; num < sas_flash_etl_count(); num++) {
			ret = sas_flash_read(part, sas_flash_etl_offset(part,
				eb, num), SAS_ETL_V2_SIZE, buf);
			if (ret == 0 || ret == -EUCLEAN)
				return 0;
		}
	}

	return 1;
}

int sas_etl_flash_write(unsigned long addr)
{
	const struct sas_flash_partition *part;
	const void *buf = (const void *)addr;
	int ret = 0, err, eb, num;

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return 1;

	ret = sas_flash_unlock(part, 0, part->size);
	if (ret)
		return 1;

	for (eb = 0; eb < sas_flash_reserved_max_eb(); eb++) {
		sas_flash_partial_erase_scrub(part, sas_flash_etl_offset(part, eb, 0),
			sas_flash_etl_count() * sas_flash_etl_size(), 1);

		for (num = 0; num < sas_flash_etl_count(); num++) {
			err = sas_flash_write_scrub(part, sas_flash_etl_offset(part,
				eb, num), SAS_ETL_V2_SIZE, buf, 1);
			if (err)
				ret++;
		}
	}

	sas_flash_lock(part, 0, part->size);

	if (ret == sas_flash_reserved_max_eb() * sas_flash_etl_count())
		return 1;

	return 0;
}

int sas_etl_flash_erase(void)
{
	const struct sas_flash_partition *part;
	int ret, eb;

	part = sas_flash_part_find(SAS_PART_UBOOT_FIX);
	if (!part)
		return 1;

	ret = sas_flash_unlock(part, 0, part->size);
	if (ret)
		return 1;

	for (eb = 0; eb < sas_flash_reserved_max_eb(); eb++) {
		sas_flash_partial_erase_scrub(part, sas_flash_etl_offset(part, eb, 0),
			sas_flash_etl_count() * sas_flash_etl_size(), 1);
	}

	sas_flash_lock(part, 0, part->size);

	return 0;
}

static struct sas_etl_map_entry *
sas_etl_entry_create(enum sas_etl_id idx)
{
	struct sas_etl_map_entry *entry;

	entry = malloc(sizeof(*entry));
	if (!entry) {
		debug("%s: failed to create entry\n", __func__);
		return NULL;
	}

	memset(entry, 0, sizeof(*entry));
	INIT_LIST_HEAD(&entry->link);
	entry->idx = idx;

	debug("%s: creating entry %d\n", __func__, entry->idx);

	return entry;
}

static void sas_etl_entry_add(struct sas_etl_map_entry *entry)
{
	debug("%s: adding entry %d\n", __func__, entry->idx);
	list_add_tail(&entry->link, &sas_etl_map);
}

static struct sas_etl_map_entry *sas_etl_entry_find(enum sas_etl_id idx)
{
	struct sas_etl_map_entry *entry;

	if (!idx || idx >= SAS_ETL_ID_LAST)
		return NULL;

	list_for_each_entry(entry, &sas_etl_map, link) {
		if (idx == entry->idx)
			return entry;
	}

	return NULL;
}

static struct sas_etl_map_entry *
sas_etl_entry_find_or_create(enum sas_etl_id idx)
{
	struct sas_etl_map_entry *entry = sas_etl_entry_find(idx);

	if (entry)
		return entry;

	entry = sas_etl_entry_create(idx);
	if (!entry)
		return NULL;

	sas_etl_entry_add(entry);

	return entry;
}

static void sas_etl_entries_clear(void)
{
	struct sas_etl_map_entry *entry;
	struct list_head *pos, *q;

	sas_etl_ver = 0;

	list_for_each_safe(pos, q, &sas_etl_map) {
		entry = list_entry(pos, struct sas_etl_map_entry, link);
		debug("%s: deleting entry %d\n", __func__, entry->idx);
		list_del(pos);
		free(entry);
	}
}

int sas_etl_import(unsigned long addr)
{
	const u8 *buf = (const u8 *)addr;
	struct sas_etl_map_entry *entry;
	u8 idx, len;

	sas_etl_entries_clear();

	/* Check for empty flash and ETL version */
	if (buf[0] == 0xff || buf[SAS_ETL_V2_SIZE - 1] == 0xff) {
		debug("%s: empty flash\n", __func__);
		return 0;
	}

	if (buf[SAS_ETL_V2_SIZE - 1] == 0x1) {
		debug("%s: ETL v2\n", __func__);
		sas_etl_ver = 2;
	} else {
		debug("%s: invalid ETL version\n", __func__);
		return 0;
	}

	do {
		idx = *buf++;
		len = *buf++;

		debug("%s: idx %u, len %u\n", __func__, idx, len);

		/* end of ETL reached */
		if (!idx && !len)
			return 0;

		if (idx >= SAS_ETL_ID_LAST) {
			debug("%s: invalid idx %u\n", __func__, idx);
			return 1;
		}

		if (len >= SAS_ETL_MAX_VALUE_CHARS) {
			debug("%s: invalid len %u\n", __func__, len);
			return 1;
		}

		entry = sas_etl_entry_create(idx);
		if (!entry)
			return 1;

		memcpy(entry->val, buf, len);
		sas_etl_entry_add(entry);

		buf += len;
	} while ((buf - (const u8 *)addr) < SAS_ETL_V2_SIZE);

	return 0;
}

int sas_etl_export(unsigned long addr)
{
	u8 *buf = (u8 *)addr;
	struct sas_etl_map_entry *entry;
	u8 len;

	memset(buf, 0, SAS_ETL_V2_SIZE);

	list_for_each_entry(entry, &sas_etl_map, link) {
		if (sas_etl_is_hex(entry->idx))
			len = 4;
		else
			len = strlen(entry->val);

		debug("%s: idx %u, len %u\n", __func__, entry->idx, len);

		*buf++ = entry->idx;
		*buf++ = len;
		memcpy(buf, entry->val, len);
		buf += len;
	}

	buf = (u8 *)addr;
	buf[SAS_ETL_V2_SIZE - 1] = 0x1;

	return 0;
}

static void sas_etl_env_set_default(enum sas_etl_id idx, const char *name,
					const char *defval, int *save_env)
{
	const char *etl_val = sas_etl_get_string(idx);
	const char *env_val;

	if (etl_val)
		env_val = etl_val;
	else
		env_val = defval;

	sas_setenv(name, env_val, save_env);
}

static void sas_etl_env_set_fill(enum sas_etl_id idx, const char *name,
				char fillval, size_t len, int *save_env)
{
	const char *etl_val = sas_etl_get_string(idx);
	const char *env_val;
	char tmp[40];

	if (etl_val)
		env_val = etl_val;
	else {
		memset(tmp, fillval, len);
		tmp[len] = 0;
		env_val = tmp;
	}

	sas_setenv(name, env_val, save_env);
}

void sas_etl_env_set_ethaddr(int *save_env)
{
	const char *val;
	int i;

	val = sas_etl_get_string(SAS_ETL_MAC_ADDR);
	if (!val)
		return;

	if (17 != strlen(val))
		return;

	for (i = 2; i < 15; i += 3)
		if (val[i] != ':')
			return;

	sas_setenv("ethaddr", val, save_env);
}

static void sas_etl_env_set_hwcfg(int *save_env)
{
	const char *val;
	struct sas_hw_cfg hw_cfg;

	val = sas_etl_get_string(SAS_ETL_HW_CFG);
	if (!val)
		return;

	memcpy(&hw_cfg, val, sizeof(hw_cfg));

	sas_setenv_num("etl_fxo", hw_cfg.FXO, save_env);
	sas_setenv_num("etl_s0_ext", hw_cfg.S0_ext, save_env);
	sas_setenv_num("etl_s0_int", hw_cfg.S0_int, save_env);
	sas_setenv_num("etl_ab_count", hw_cfg.ab_count, save_env);
	sas_setenv_num("etl_switch_ic", hw_cfg.switch_ic, save_env);
	sas_setenv_num("etl_usb", hw_cfg.USB, save_env);
	sas_setenv_num("etl_metering_hw", hw_cfg.metering_hw, save_env);
}

static void sas_etl_env_set_hwcfg2(int *save_env)
{
	const char *val;
	struct sas_hw_cfg2 hw_cfg2;

	val = sas_etl_get_string(SAS_ETL_HW_CFG2);
	if (!val)
		return;

	memcpy(&hw_cfg2, val, sizeof(hw_cfg2));

	sas_setenv_num("etl_fxs_ringvoltage", hw_cfg2.fxs_ringvoltage, save_env);
	sas_setenv_num("etl_s0_int_count", hw_cfg2.S0_int_count, save_env);
}

static void sas_etl_env_set_bcd(enum sas_etl_id idx, const char *name,
				int *save_env)
{
	unsigned long val;
	char buf[16];

	val = sas_etl_get_hex(idx, sas_etl_hex_size(idx));
	sprintf(buf, "%0*lx", sas_etl_hex_size(idx) * 2, val);
	sas_setenv(name, buf, save_env);
}

void sas_etl_env_save(int *save_env)
{
	if (!sas_etl_ver) {
		sas_setenv_num("etl_exists", 0, save_env);
		return;
	}

	sas_setenv_num("etl_exists", 1, save_env);

	sas_etl_env_set_ethaddr(save_env);

	sas_etl_env_set_default(SAS_ETL_TRIV_NAME, "etl_triv_name",
		BOARD_NAME, save_env);

	sas_etl_env_set_default(SAS_ETL_IDENT_NO, "etl_ident_no",
		"0", save_env);

	sas_etl_env_set_default(SAS_ETL_BASE_PLATFORM, "etl_base_platform",
		"0", save_env);

	sas_etl_env_set_default(SAS_ETL_FLASH_LAYOUT, "etl_flash_layout",
		FLASHLAYOUT, save_env);

	sas_etl_env_set_default(SAS_ETL_WLAN_SSID, "etl_wlan_ssid",
		"default", save_env);

	sas_etl_env_set_default(SAS_ETL_WLAN_SSID_EXTRA, "etl_wlan_ssid_extra",
		"default_extra", save_env);

	sas_etl_env_set_default(SAS_ETL_CUSTOMER, "etl_customer",
		"Sphairon", save_env);

	sas_etl_env_set_default(SAS_ETL_MAC_ADDR_POOL, "etl_mac_addr_pool",
		"8", save_env);

	sas_etl_env_set_default(SAS_ETL_DATA_PART_SIZE, "etl_data_part_size",
		"10", save_env);

	sas_etl_env_set_default(SAS_ETL_DATA_PART_LOC, "etl_data_part_loc",
		"0", save_env);

	sas_etl_env_set_bcd(SAS_ETL_WLANCFG, "etl_wlanconfig", save_env);
	sas_etl_env_set_bcd(SAS_ETL_LEDCFG, "etl_led", save_env);

	sas_etl_env_set_fill(SAS_ETL_HW_VERSION, "etl_hw_version",
		'x', 4, save_env);

	sas_etl_env_set_fill(SAS_ETL_SERIAL, "etl_serial_no",
		'x', 13, save_env);

	sas_etl_env_set_fill(SAS_ETL_SERIAL_EXTRA, "etl_serial_extra",
		'x', 15, save_env);

	sas_etl_env_set_fill(SAS_ETL_PROD_DATE, "etl_prod_date",
		'x', 10, save_env);

	sas_etl_env_set_fill(SAS_ETL_WLAN_MODULE, "etl_wlan_module",
		'x', 32, save_env);

	sas_etl_env_set_fill(SAS_ETL_WLAN_KEY, "etl_wlan_wep_key",
		'x', 26, save_env);

	sas_etl_env_set_fill(SAS_ETL_WPS_PIN, "etl_wlan_wps_pin",
		'x', 16, save_env);

	sas_etl_env_set_fill(SAS_ETL_ACS_AUTH, "etl_acs_auth",
		'x', 16, save_env);

	sas_etl_env_set_default(SAS_ETL_GUI_AUTH, "etl_gui_auth",
		"", save_env);

	sas_etl_env_set_hwcfg(save_env);
	sas_etl_env_set_hwcfg2(save_env);
}

const char *sas_etl_get_string(enum sas_etl_id idx)
{
	const struct sas_etl_map_entry *entry = sas_etl_entry_find(idx);

	if (!entry)
		return NULL;

	return entry->val;
}

int sas_etl_get_integer(enum sas_etl_id idx)
{
	const struct sas_etl_map_entry *entry = sas_etl_entry_find(idx);
	const char *cp;

	if (!entry)
		return 0;

	/*
	 * if first char is '0', remove it. Otherwise simple_strtoul sets
	 * base to octal but we want decimal or hex.
	 */
	cp = entry->val;
	if (*cp == '0')
		cp++;

	return simple_strtol(cp, NULL, 0);
}

unsigned long sas_etl_get_hex(enum sas_etl_id idx, unsigned int len)
{
	const struct sas_etl_map_entry *entry = sas_etl_entry_find(idx);
	unsigned long val;
	unsigned int i;

	if (!entry)
		return 0;

	val = entry->val[0];
	for (i = 1; i < len; i++) {
		val <<= 8;
		val |= entry->val[i];
	}

	return val;
}

void sas_etl_set_string(enum sas_etl_id idx, const char *val)
{
	struct sas_etl_map_entry *entry = sas_etl_entry_find_or_create(idx);

	if (!entry)
		return;

	if (val)
		snprintf(entry->val, SAS_ETL_MAX_VALUE_CHARS - 1, "%s", val);
	else
		memset(entry->val, 0, SAS_ETL_MAX_VALUE_CHARS);
}

void sas_etl_set_integer(enum sas_etl_id idx, int val)
{
	struct sas_etl_map_entry *entry = sas_etl_entry_find_or_create(idx);

	if (!entry)
		return;

	snprintf(entry->val, SAS_ETL_MAX_VALUE_CHARS - 1, "%d", val);
}

void sas_etl_set_hex(enum sas_etl_id idx, unsigned int len, unsigned long val)
{
	struct sas_etl_map_entry *entry = sas_etl_entry_find_or_create(idx);

	if (!entry)
		return;

	val <<= (4 - len) * 8;
	memcpy(entry->val, &val, 4);
}

static void sas_etl_banner_print(const char *name, const char *buf)
{
	sas_banner_content_print("%-25s%-s ", name, buf ? buf : "");
}

void sas_etl_print(void)
{
	if (!sas_etl_ver) {
		sas_banner_header_print("No Sphairon type label installed");
		return;
	}

	sas_banner_header_print("Sphairon type label v%u", sas_etl_ver);

	sas_etl_banner_print("Product name",
		sas_etl_get_string(SAS_ETL_TRIV_NAME));
	sas_etl_banner_print("Ident number",
		sas_etl_get_string(SAS_ETL_IDENT_NO));
	sas_etl_banner_print("Base platform",
		sas_etl_get_string(SAS_ETL_BASE_PLATFORM));
	sas_etl_banner_print("Flash layout",
		sas_etl_get_string(SAS_ETL_FLASH_LAYOUT));
	sas_etl_banner_print("Data partition size",
		sas_etl_get_string(SAS_ETL_DATA_PART_SIZE));
	sas_etl_banner_print("Data partition location",
		sas_etl_get_string(SAS_ETL_DATA_PART_LOC));

	sas_banner_line_print();

	sas_etl_banner_print("HW version",
		sas_etl_get_string(SAS_ETL_HW_VERSION));
	sas_etl_banner_print("Serial number",
		sas_etl_get_string(SAS_ETL_SERIAL));
	sas_etl_banner_print("Serial number extra",
		sas_etl_get_string(SAS_ETL_SERIAL_EXTRA));
	sas_etl_banner_print("ACS authentication",
		sas_etl_get_string(SAS_ETL_ACS_AUTH));
	sas_etl_banner_print("GUI authentication",
		sas_etl_get_string(SAS_ETL_GUI_AUTH));
	sas_etl_banner_print("Date of production",
		sas_etl_get_string(SAS_ETL_PROD_DATE));
	sas_etl_banner_print("MAC address",
		sas_etl_get_string(SAS_ETL_MAC_ADDR));
	sas_etl_banner_print("MAC address pool",
		sas_etl_get_string(SAS_ETL_MAC_ADDR_POOL));
	sas_etl_banner_print("WLAN SSID",
		sas_etl_get_string(SAS_ETL_WLAN_SSID));
	sas_etl_banner_print("WLAN SSID extra",
		sas_etl_get_string(SAS_ETL_WLAN_SSID_EXTRA));

	sas_banner_footer_print();
}

void sas_etl_dump(void)
{
	enum sas_etl_id idx;
	const char *str;

	for (idx = SAS_ETL_HW_VERSION; idx < SAS_ETL_ID_LAST; idx++) {
		printf("%03d: %s = ", idx, sas_etl_id_str(idx));

		if (sas_etl_is_integer(idx))
			printf("%d\n", sas_etl_get_integer(idx));
		else if (sas_etl_is_hex(idx))
			printf("0x%0*lx\n", 2 * sas_etl_hex_size(idx),
				sas_etl_get_hex(idx, sas_etl_hex_size(idx)));
		else {
			str = sas_etl_get_string(idx);
			printf("%s\n", str ? str : "");
		}
	}
}

int sas_etl_version(void)
{
	return sas_etl_ver;
}

void sas_etl_version_set_default(void)
{
	sas_etl_ver = 2;
}

enum sas_flash_layout_type sas_etl_flash_layout(void)
{
	const char *val;

	val = getenv("flash_layout_override");
	if (!val) {
		val = sas_etl_get_string(SAS_ETL_FLASH_LAYOUT);
		if (!val)
			val = FLASHLAYOUT;
	}

	return sas_flash_layout_parse(val);
}

size_t sas_etl_data_part_size(void)
{
	size_t size = sas_etl_get_integer(SAS_ETL_DATA_PART_SIZE);

	if (!size)
		size = SAS_ETL_DATA_PART_SIZE_DEFAULT;

	return size << 20;
}

enum sas_data_part_loc sas_etl_data_part_loc(void)
{
	int loc = sas_etl_get_integer(SAS_ETL_DATA_PART_LOC);

	if (loc < 0 || loc >= DATA_PART_LOC_INVALID)
		return SAS_ETL_DATA_PART_LOC_DEFAULT;

	return loc;
}

unsigned int sas_etl_base_platform(void)
{
	if (!sas_etl_ver)
		return 0;

	return sas_etl_get_integer(SAS_ETL_BASE_PLATFORM);
}

static const char sas_etl_id_strings[][16] = {
	"hw_version",
	"serial_no",
	"prod_date",
	"wlan_module",
	"wlan_key",
	"triv_name",
	"mac_addr",
	"hw_cfg",
	"hw_cfg2",
	"ident_no",
	"customer",
	"base_platform",
	"wlan_wps_pin",
	"led_cfg",
	"wlan_cfg",
	"wlan_ssid",
	"flash_layout",
	"extra_space",
	"jffs_images",
	"serial_extra",
	"shdsl_lines",
	"mac_addr_pool",
	"data_part_size",
	"data_part_loc",
	"acs_auth",
	"wlan_ssid_extra",
	"gui_auth",
};

const char *sas_etl_id_str(enum sas_etl_id idx)
{
	assert(idx && idx < SAS_ETL_ID_LAST);

	return sas_etl_id_strings[idx - 1];
}

enum sas_etl_id sas_etl_id_parse(const char *str)
{
	unsigned int i;
	unsigned long val;
	const char *name;

	if (!str)
		return SAS_ETL_ID_LAST;

	for (i = SAS_ETL_HW_VERSION; i < SAS_ETL_ID_LAST; i++) {
		name = sas_etl_id_strings[i - 1];

		if (!strncmp(name, str, 15))
			return i;
	}

	if (strict_strtoul(str, 10, &val))
		return SAS_ETL_ID_LAST;

	if (val && val < SAS_ETL_ID_LAST)
		return val;

	return SAS_ETL_ID_LAST;
}

int sas_etl_set_value(enum sas_etl_id idx, const char *str)
{
	unsigned long val;

	if (idx >= SAS_ETL_ID_LAST) {
		printf("invalid id: %d\n", idx);
		return 1;
	}

	if (sas_etl_is_hex(idx)) {
		strict_strtoul(str, 16, &val);
		sas_etl_set_hex(idx, sas_etl_hex_size(idx), val);
	} else
		sas_etl_set_string(idx, str);

	return 0;
}
