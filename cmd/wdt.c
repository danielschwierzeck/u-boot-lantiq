/* Copyright (c) 2018, Intel Corporation.
 * Watchdog timer user application
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <watchdog.h>

/* Stops WDT timer */
void wdt_stop(void)
{
	printf("Watchdog timer stopped\n");
	hw_watchdog_stop();
}

/* Starts WDT timer */
void wdt_start(void)
{
	printf("Starting watchdog timer ...\n");
	hw_watchdog_init();
	hw_watchdog_start();
}

/* Tests WDT functionality */
void wdt_test(void)
{
	printf("Watchdog test, board will reset after wdt expire.\n");
	while(1);
}

int do_wdt(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int ret = 0;

	if (argc < 2)
		return CMD_RET_USAGE;

	if (strcmp(argv[1], "start") == 0) {
		wdt_start();
	} else if (strcmp(argv[1], "stop") == 0) {
		wdt_stop();
	} else if (strcmp(argv[1], "test") == 0) {
		wdt_test();
	} else {
		return CMD_RET_USAGE;
	}

	return ret;
}

U_BOOT_CMD(wdt, 2, 1, do_wdt,
	"User application to use the watchdog timer",
	"start\n"
	" - starts the watchdog timer\n"
	"stop\n"
	" - stops the watchdog timer permanently in U-boot\n"
	"test\n"
	" - tests the watchdog timer implementation"
);
