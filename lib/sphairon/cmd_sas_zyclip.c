// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2018-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <command.h>
#include <sas/flash.h>
#include <sas/etl.h>
#include <sas/zyclip.h>

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

static int do_zyclip_import(cmd_tbl_t *cmdtp, int flag, int argc,
				char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	ret = sas_zyclip_import(loadaddr);
	if (ret)
		return ret;

	sas_etl_env_set_ethaddr(NULL);

	return 0;
}

static int do_zyclip_read(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	unsigned long loadaddr;
	int ret;

	ret = parse_loadaddr(argc, argv[1], &loadaddr);
	if (ret)
		return ret;

	return sas_zyclip_flash_read(loadaddr);
}

static int do_zyclip_update_etl(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	sas_zyclip_update_etl();

	return 0;
}

static int do_zyclip_dump(cmd_tbl_t *cmdtp, int flag, int argc,
			char * const argv[])
{
	sas_zyclip_dump();

	return 0;
}

static cmd_tbl_t cmd_zyclip_sub[] = {
	U_BOOT_CMD_MKENT(import, 2, 0, do_zyclip_import, "", ""),
	U_BOOT_CMD_MKENT(read, 2, 0, do_zyclip_read, "", ""),
	U_BOOT_CMD_MKENT(update_etl, 1, 0, do_zyclip_update_etl, "", ""),
	U_BOOT_CMD_MKENT(dump, 1, 0, do_zyclip_dump, "", ""),
};

static int do_sas_zyclip(cmd_tbl_t * cmdtp, int flag, int argc, char *const argv[])
{
	cmd_tbl_t *cp;

	/* need at least two arguments */
	if (argc < 2)
		return CMD_RET_USAGE;

	/* drop initial "sas_zyclip" arg */
	argc--;
	argv++;

	cp = find_cmd_tbl(argv[0], cmd_zyclip_sub, ARRAY_SIZE(cmd_zyclip_sub));
	if (!cp)
		return CMD_RET_USAGE;

	return cp->cmd(cmdtp, flag, argc, argv);
}

U_BOOT_CMD(sas_zyclip, CONFIG_SYS_MAXARGS, 0, do_sas_zyclip,
	"Sphairon ZYCLIP commands",
	"import [addr] - import ZYCLIP at [addr]\n"
	"sas_zyclip read [addr] - read ZYCLIP from flash to [addr]\n"
	"sas_zyclip update_etl - use imported ZYCLIP to update ETL\n"
	"sas_zyclip dump - dump ZYCLIP values\n");

