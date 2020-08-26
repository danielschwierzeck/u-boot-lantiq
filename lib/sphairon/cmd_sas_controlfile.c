// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <command.h>
#include <cli_hush.h>
#include <malloc.h>
#include <sas/controlfile.h>
#include <sas/util.h>

#define SAS_CF_FILENAME		"control.script"

static int do_sas_controlfile(cmd_tbl_t * cmdtp, int flag, int argc, char *const argv[])
{
	size_t size;
	unsigned long loadaddr;
	int ret;
	char *cmd;

	setenv("tftptimeout", "2000");

	loadaddr = getenv_ulong("loadaddr", 16, 0);
	size = sas_run_tftpboot(loadaddr, SAS_CF_FILENAME);
	if (!size) {
		ret = -1;
		goto done;
	}

	cmd = malloc(size + 1);
	if (!cmd) {
		ret = -1;
		goto done;
	}

	memmove(cmd, (char *)loadaddr, size);
	cmd[size] = 0;

	ret = parse_string_outer(cmd, FLAG_PARSE_SEMICOLON);
	free(cmd);

done:
	sas_cf_status_board(ret ? CF_FAILED : CF_FINISHED);

	return ret;
}

U_BOOT_CMD(sas_controlfile, 1, 0, do_sas_controlfile,
	   "Sphairon control file execution", NULL);
