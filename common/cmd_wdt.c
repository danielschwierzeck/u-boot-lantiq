/*Copyright, Lantiq Asia Pacific,Ltd         */
/*Revision history:                          */
/*1 March, 2013 Wu Qi Ming Initial version   */
/*********************************************/

/*
 * watch dog timer support
 */
#include <common.h>
#include <command.h>

extern void start_watchdog(int timeout);
extern void stop_watchdog();

/* Allow ports to override the default behavior */
__attribute__((weak))

int do_wdt (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, rc;
	int     timeout;
	int     rcode = 0;
	if (argc < 2) {
		cmd_usage(cmdtp);
		return 1;
	}

    if (strncmp(argv[1], "start", 5) == 0){
	  if(!argv[2]){
                 cmd_usage(cmdtp);
		         return 1;
	  }
	  timeout=simple_strtoul(argv[2], NULL, 16);
	  //printf ("start %d\n",timeout);
	  start_watchdog(timeout);
	}else if (strncmp(argv[1], "stop", 4) == 0){
      //printf ("stop\n"); 
	  stop_watchdog();
	}else{
      cmd_usage(cmdtp);
      return 1;
    }

	return rcode;
}

/* -------------------------------------------------------------------- */

U_BOOT_CMD(
	wdt, CONFIG_SYS_MAXARGS, 2,	do_wdt,
	"start/stop a watchdog timer",
	"wdt start seconds\n    - start watchdog timer\n"
	"wdt stop\n    - stop watch dog timer\n"
);

