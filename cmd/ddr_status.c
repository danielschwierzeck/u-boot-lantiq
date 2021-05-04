/* Copyright (c) 2018, Intel Corporation.
 * DDR status command to get ddr debug info
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <asm/boot.h>
#include <asm/addrspace.h>

extern int dump_ddr_status(void);

int do_ddr_status(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret;

	if (argc != 2)
		return 1;

	printf("\nStart of DDR Debug\n");
	if (strcmp(argv[1], "status") == 0)
		ret = dump_ddr_status();
	else
		return 1;
	
	printf("\nEnd of DDR Debug\n");
	return ret;
}

U_BOOT_CMD(ddr, 2, 1, do_ddr_status,
    "Command to get the DDR status in U-boot\n",
    "ddr status\n"
);

