#include <common.h>



void test_watchdog(void)
{
   u32 timeout=10; /*1 second timeout*/  
   u32 DIV=262144;
   u32 fpi_clk;
   u32 reload;
   u32 CLKDIV=0x3;
   u32 PW1=0xBE;
   u32 PW2=0xDC;
   u32 wdt_cr;
   int i;
   printf("watch dog timer test!\n");
   fpi_clk=get_fpi_clk();
   reload=timeout*fpi_clk/DIV+0x8000;
   printf("fpi_clk=%d\n",fpi_clk);
   printf("reload=0x%08x\n",reload);
   wdt_cr=(1<<31)|(0x3<<24)|(PW2<<16)|(reload);
   //printf("wdt_cr=%08x\n",wdt_cr);
   asm("sync");
   *BSP_BIU_WDT_CR = PW1<<16;
   asm("sync");
   *BSP_BIU_WDT_CR=wdt_cr;
   for(i=0;i<2;i++){
     mdelay(1000);
	 *BSP_BIU_WDT_CR=wdt_cr;
   }

   *BSP_BIU_WDT_CR = PW1<<16;
   *BSP_BIU_WDT_CR=  PW2<<16; 
   asm("sync");
   return;

}
