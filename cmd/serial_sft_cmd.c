/* Copyright (c) 2018, Intel Corporation.
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#include <common.h>
#include <sso.h>

#define SSO_ON	1
#define SSO_OFF	0

int parse_sso_arg(char *val)
{
	if (strcmp(val, "off") == 0)
		return SSO_OFF;
	else if ((strcmp(val, "on") == 0))
		return SSO_ON;

	return -EINVAL;
}

int do_sso(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret, pin_no;
	unsigned long val;
	u8 duty_cycle = 0xff;

	if ((argc <= 1) || (argc > 5))
		return CMD_RET_USAGE;

	if (strcmp(argv[1], "init") == 0) {
		sso_init();
		return 0;

	} else if (strcmp(argv[1], "set") == 0) {
		if (argc < 3)
			return CMD_RET_USAGE;

		val = parse_sso_arg(argv[3]);
		if (val < 0)
			return CMD_RET_USAGE;

		pin_no = (int)simple_strtoul(argv[2], NULL, 10);
		if (pin_no < 0)
			return CMD_RET_USAGE;

		if (argc > 3)
			duty_cycle = (u8)simple_strtoul(argv[4], NULL, 16);

		ret = sso_output(pin_no, val, duty_cycle);
		if (ret)
			return ret;

	} else if (strcmp(argv[1], "setall") == 0) {
		val = (unsigned long)simple_strtoul(argv[2], NULL, 16);

		if (argc > 3)
			duty_cycle = (u8)simple_strtoul(argv[3], NULL, 16);

		ret = sso_output_all(val, duty_cycle);
		if (ret)
			return ret;
	}

	return 0;
}

U_BOOT_CMD(
	sso, 6, 1, do_sso,
	"configure serial shift output value",
	"set [output pin] [on|off] [duty cycle]\n"
	"\tsets output of gpio number with duty cycle value (optional)\n"
	"sso setall [output value] [duty cycle]\n"
	"\tsets all the output of the sso with value\n"
);

