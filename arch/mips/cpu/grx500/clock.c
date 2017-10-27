/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <config.h>
#include <common.h>

#define CPU_CLK_MST_SEL_2GHZ    0x20000000
#define CLOCK_200M      200000000
#define CLOCK_2000M     2000000000UL
#define CLOCK_2400M     2400000000UL
#define PLL0B_CFG1_CLK4 0xF000
#define PLL0A_CFG1_CLK4 0xF000
#define PLL0A_CFG1_CLK3 0x0F00
#define PLL0B_CFG1_CLK3 0x0F00


uint get_sys_clk(void)
{
    return 0;
}


uint get_cpu_clk(void)
{
       unsigned long pllclk;
       u32 val;
       u32 clk4_div;

       val = REG32(CGU_PLL0A_CFG1);

        if (val & CPU_CLK_MST_SEL_2GHZ) {
                pllclk = CLOCK_2000M;
                clk4_div = (REG32(CGU_PLL0B_CFG1) & PLL0B_CFG1_CLK4)>>12;
        } else {
                pllclk = CLOCK_2400M;
                clk4_div = (REG32(CGU_PLL0A_CFG1) & PLL0A_CFG1_CLK4)>>12;
        }

        return (unsigned long)(pllclk / (clk4_div + 1));

}


unsigned int get_ddr_clk(void)
{
      
       unsigned long pllclk;
       u32 val=400000000;
       u32 clk3_div;
        
#if 1       
       pllclk = CLOCK_2000M;
       clk3_div = (REG32(CGU_PLL0B_CFG1) & PLL0B_CFG1_CLK3)>>8;
       /*fix me, should add more options*/
       switch(clk3_div){
          case 2:
              val = (pllclk/3)<<1;
              break;
          case 3:
              val = (pllclk/4)<<1;
              break;
          case 4:
              val = (pllclk/5)<<1;
              break;
          case 5:
              val = (pllclk/6)<<1; 
              break;
          case 6:
              val = (pllclk/8)<<1;
              break;
          case 7:
              val = (pllclk/10)<<1;
              break;
          case 8:
              val = (pllclk/12)<<1;
              break;

       }
#endif
       return val;
}


unsigned int get_fpi_clk()
{
    //return 16000000/4;   // HAPS 800MHz CPU Actual Frequency is 16MHz;
    return   CLOCK_200M;
}


