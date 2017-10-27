/*
 * Copyright (C) 2012 Wu Qi Ming  wqiming@gmail.com
 *
 */



#include <common.h>

uint get_sys_clk(void)
{
    uint sys_clk;
    if ( *AR10_CGU_SYS & 0x100 ){
         sys_clk = 500000000;
    }else{
         sys_clk = 600000000;
    }

    return sys_clk;
}


uint get_cpu_clk(void)
{
        uint cpu_clk;
      switch( (*AR10_CGU_SYS & 0x70)>> 4 ){
         case 0:
            cpu_clk = get_sys_clk();
            break;
         case 1:
            cpu_clk = get_sys_clk()/2;
            break;
         case 2:
            cpu_clk = get_sys_clk()/4;
          break;
      }
      return cpu_clk;
}

unsigned int get_ddr_clk(void)
{
       unsigned int ddr_clk;
       switch( *AR10_CGU_SYS & 0x07 ){
          case 0:
            ddr_clk = get_sys_clk()/2;
            break;
          case 2:
            ddr_clk = get_sys_clk()/4;
            break;
      }
      return ddr_clk;
}

unsigned int get_fpi_clk(void)
{
     unsigned int fpi_clk;
     switch((*AR10_CGU_IF_CLK >> 25) & 0x0f){
         case 2:
           if (REG32(0xbf107350) & (1<<17)){
            /* check BSP_MPS_ID_CFG, if bit 17 is set, treat FPI clock as 125 instead of 150*/
            fpi_clk = 125000000;
           }else{
            fpi_clk = 150000000;
           }
           break;
         case 1:
           fpi_clk = 300000000;
           break;
         case 5:
           fpi_clk = 250000000;
           break;
         case 6:
           fpi_clk = 125000000;
           break;
     }
     return fpi_clk;
}



