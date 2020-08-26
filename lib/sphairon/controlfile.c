// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2011-2020 Sphairon GmbH (a ZyXEL company)
 */

#include <common.h>
#include <watchdog.h>
#include <linux/compiler.h>

#include <sas/controlfile.h>

__weak int sas_cf_check_board(void)
{
	return 0;
}

void sas_cf_status_board(enum sas_cf_state state)
{
	puts("control file ");

	switch (state) {
	case CF_STARTED:
		puts("started\n");
		sas_cf_led_action(CF_STARTED);
		break;
	case CF_FINISHED:
		puts("finished\n");
		sas_cf_led_action(CF_FINISHED);
		break;
	case CF_FAILED:
		puts("failed\n");
		sas_cf_led_action(CF_FAILED);
		break;
	}
}

__weak void sas_cf_led_action(enum sas_cf_state state)
{
	return;
}

static int sas_cf_debounce(unsigned long interval)
{
	unsigned long timebase = get_timer(0);

	while (sas_cf_check_board()) {
		WATCHDOG_RESET();

		if (get_timer(timebase) > interval)
			return 1;
	}

	return 0;
}

void sas_cf_run(void)
{
	int status;

	status = sas_cf_debounce(2000);
	if (!status)
		return;

	setenv("bootcmd", "sas_controlfile");
	setenv("bootdelay", "1");
}

int sas_cf_is_active(void)
{
	const char *bootcmd = getenv("bootcmd");

	if (!bootcmd)
		return 0;

	if (!strcmp(bootcmd, "sas_controlfile"))
	{
		sas_cf_status_board(CF_STARTED);
		return 1;
	}

	return 0;
}
