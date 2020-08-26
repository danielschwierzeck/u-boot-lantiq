// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <command.h>
#include <sas/flash.h>
#include <sas/etl.h>

static int parse_loadaddr(int argc, const char *value, unsigned long *loadaddr)
{
	if (argc == 2)
		strict_strtoul(value, 16, loadaddr);
	else if (argc == 1)
		*loadaddr = getenv_ulong("loadaddr", 16, CONFIG_LOADADDR);
	else
		return CMD_RET_USAGE;

	return 0;
}

static int do_etl_import(cmd_tbl_t *cmdtp, int flag, int argc,
				char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	ret = sas_etl_import(loadaddr);
	if (ret)
		return ret;

	sas_etl_env_set_ethaddr(NULL);

	return 0;
}

static int do_etl_export(cmd_tbl_t *cmdtp, int flag, int argc,
				char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	return sas_etl_export(loadaddr);
}

static int do_etl_read(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	return sas_etl_flash_read(loadaddr);
}

#if !defined(CONFIG_SPHAIRON_ETL_WRITE_DISABLE)
static int do_etl_write(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	return sas_etl_flash_write(loadaddr);
}
#endif

static int do_etl_set(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	enum sas_etl_id idx;

	if (argc != 3)
		return CMD_RET_USAGE;

	idx = sas_etl_id_parse(argv[1]);
	if (idx == SAS_ETL_ID_LAST) {
		printf("invalid id: %s\n", argv[1]);
		return CMD_RET_FAILURE;
	}

	return sas_etl_set_value(idx, argv[2]);
}

static int do_etl_get(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	enum sas_etl_id idx;
	const char *val;

	if (argc != 2)
		return CMD_RET_USAGE;

	idx = sas_etl_id_parse(argv[1]);
	if (idx == SAS_ETL_ID_LAST) {
		printf("invalid id: %s\n", argv[1]);
		return CMD_RET_FAILURE;
	}

	val = sas_etl_get_string(idx);
	printf("%s\n", val);

	return 0;
}

#if !defined(CONFIG_SPHAIRON_ETL_WRITE_DISABLE)
static int do_etl_save(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	parse_loadaddr(1, NULL, &loadaddr);

	ret = sas_etl_export(loadaddr);
	if (ret)
		return ret;

	sas_flash_verbose_set(1);
	ret = sas_etl_flash_write(loadaddr);
	sas_flash_verbose_set(0);

	return ret;
}
#endif

static int do_etl_dump(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	sas_etl_dump();

	return 0;
}

static cmd_tbl_t cmd_etl_sub[] = {
	U_BOOT_CMD_MKENT(import, 2, 0, do_etl_import, "", ""),
	U_BOOT_CMD_MKENT(export, 2, 0, do_etl_export, "", ""),
	U_BOOT_CMD_MKENT(read, 2, 0, do_etl_read, "", ""),
#if !defined(CONFIG_SPHAIRON_ETL_WRITE_DISABLE)
	U_BOOT_CMD_MKENT(write, 2, 0, do_etl_write, "", ""),
	U_BOOT_CMD_MKENT(save, 1, 0, do_etl_save, "", ""),
#endif
	U_BOOT_CMD_MKENT(dump, 1, 0, do_etl_dump, "", ""),
	U_BOOT_CMD_MKENT(set, 3, 0, do_etl_set, "", ""),
	U_BOOT_CMD_MKENT(get, 2, 0, do_etl_get, "", ""),
};

static int do_sas_etl(cmd_tbl_t * cmdtp, int flag, int argc, char *const argv[])
{
	cmd_tbl_t *cp;

	/* need at least two arguments */
	if (argc < 2)
		return CMD_RET_USAGE;

	/* drop initial "sas_etl" arg */
	argc--;
	argv++;

	cp = find_cmd_tbl(argv[0], cmd_etl_sub, ARRAY_SIZE(cmd_etl_sub));
	if (!cp)
		return CMD_RET_USAGE;

	return cp->cmd(cmdtp, flag, argc, argv);
}

U_BOOT_CMD(sas_etl, CONFIG_SYS_MAXARGS, 0, do_sas_etl,
	"Sphairon ETL commands",
	"import [addr] - import ETL at [addr]\n"
	"sas_etl export [addr] - export ETL to [addr]\n"
	"sas_etl read [addr] - read ETL from flash to [addr]\n"
#if !defined(CONFIG_SPHAIRON_ETL_WRITE_DISABLE)
	"sas_etl write [addr] - write ETL at [addr] to flash\n"
	"sas_etl save - save current ETL values to flash\n"
#endif
	"sas_etl dump - dump ETL values\n"
	"sas_etl set <id|name> <value> - set new <value> for <id|name>\n"
	"sas_etl get <id|name> - get value for <id|name>\n");
