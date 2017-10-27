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
 
 /* Updated for HN1 by Andrei Toma */
 
#include <config.h>
#include <common.h>

uint get_cpu_clk(void)
{
	    uint cpu_clk;
      switch( (*BSP_CGU_SYS >> 4) & 0xf){
      	 case 2:
      	 	 cpu_clk = 400000000;	 
      	   break;
      	 case 5:
      	 	 cpu_clk = 200000000;	 
      	   break;
		 default:
      	 	 cpu_clk = 200000000;	 
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
		  default:
	   	  	ddr_clk = get_cpu_clk();		  
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


