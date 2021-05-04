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

uint get_cpu_clk(void)
{
	    uint cpu_clk;
      switch( (*BSP_CGU_SYS >> 4) & 0xf){
      	 case 0:
      	 	 cpu_clk = 600000000;
      	 	 break;
      	 case 1:
      	 	 cpu_clk = 500000000;
      	 	 break;
      	 case 2:
      	 	 cpu_clk = 393000000;	 
      	   break;
      	 case 3:
      	 	 cpu_clk = 333000000;
      	 	 break;
      	 case 4:
      	 	 cpu_clk = 125000000;
      	 	 break;
      	 case 5:
      	 	 cpu_clk = 125000000;	 
      	   break;
      	 case 6:
      	 	 cpu_clk = 197000000;
      	 	 break;
      	 case 7:
      	 	 cpu_clk = 166000000;
      	 	 break;
      	 case 8:
      	 	 cpu_clk = 125000000;	 
      	   break;  
      	 case 9:
      	 	 cpu_clk = 125000000;	 
      	   break;      
      }
       return cpu_clk;
}


unsigned int get_ddr_clk(void)
{
	   unsigned int ddr_clk;
	   switch( *BSP_CGU_SYS & 0x7){
	   	  case 0:
	   	  	ddr_clk = get_cpu_clk();
	   	  	break;
	   	  case 2:
	   	  	ddr_clk = get_cpu_clk()/2;
	   	  	break;	
	   	 
		    case 3:
	   	  	ddr_clk = get_cpu_clk()/5 * 2;
	   	  	break;
	   	 
		    case 4:
	   	  	ddr_clk = get_cpu_clk()/3;
	   	  	break;	
	  }
	  return ddr_clk;
}


uint get_fpi_clk(void)
{
	    uint fpi_clk;
	    if (*BSP_CGU_CLKFSR & 0x20){
            fpi_clk = get_ddr_clk()/2;
        }else{
             fpi_clk = get_ddr_clk();
        }
	
	    return fpi_clk;	
}


