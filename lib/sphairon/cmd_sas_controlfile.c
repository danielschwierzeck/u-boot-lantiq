// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <command.h>
#include <cli_hush.h>
#include <malloc.h>
#include <linux/types.h>
#include <sas/controlfile.h>
#include <sas/util.h>
#include <sas/etl.h>

#define SAS_CF_FILENAME		"control.script"

static int do_sas_controlfile(cmd_tbl_t * cmdtp, int flag, int argc, char *const argv[])
{
	size_t size = 0;
	unsigned long loadaddr;
	int ret;
	char *cmd;

	setenv("tftptimeout", "2000");
	setenv("tftptimeoutcountmax", "5");

	if (IS_ENABLED(CONFIG_CMD_DHCP)) {
		const char *ident_no = sas_etl_get_string(SAS_ETL_IDENT_NO);
		const char *serial_no = sas_etl_get_string(SAS_ETL_SERIAL);

		/* Sent ETL ident number as DHCP Vendor Class Identifier */
		if (ident_no)
			setenv("bootp_vci", ident_no);

		/* Sent ETL serial number as DHCP client hostname */
		if (serial_no)
			setenv("hostname", serial_no);

		/* Try DHCP/BOOTP requests for max. 5 seconds */
		setenv("bootpretryperiod", "2000");

		/* Reset rootpath */
		setenv("rootpath", NULL);
	}

	loadaddr = getenv_ulong("loadaddr", 16, 0);

	if (IS_ENABLED(CONFIG_CMD_DHCP)) {
		/*
		 * SAS_CF_FILENAME is used as fallback, the script can be
		 * overwritten by DHCP option "Boot file name"
		 */
		size = sas_run_dhcp(loadaddr, SAS_CF_FILENAME);

		if (size == 0) {
			/* Restore ipaddr from default env (unset after failed dhcp) */
			sas_run_command("env default ipaddr");
		}
	}

	if (size == 0)
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
