#include <common.h>


void start_watchdog(int timeout)
{
    u32 DIV=262144;
    u32 fpi_clk;
    u32 reload;
    u32 CLKDIV=0x3;
    u32 PW1=0xBE;
    u32 PW2=0xDC;
    u32 wdt_cr;
    int i;
	fpi_clk=get_fpi_clk();
	reload=timeout*fpi_clk/DIV+0x8000;
	wdt_cr=(1<<31)|(0x3<<24)|(PW2<<16)|(reload);
	asm("sync");
	*BSP_BIU_WDT_CR = PW1<<16;
	asm("sync");
	*BSP_BIU_WDT_CR=wdt_cr;

}


void stop_watchdog()
{
    u32 PW1=0xBE;
	u32 PW2=0xDC;
    *BSP_BIU_WDT_CR = PW1<<16;
    *BSP_BIU_WDT_CR=  PW2<<16;
}
