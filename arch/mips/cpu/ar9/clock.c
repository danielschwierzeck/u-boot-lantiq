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

/*history
 * Wu Qi Ming Oct 18,2010 initial version
 *
 */


#include <asm/ar9.h>
#include <common.h>


unsigned int get_sys_clk(void){
	      unsigned int sys_clock;
        switch((*AMAZON_S_CGU_SYS >> 3) & 0x3){
        	    case 0:
        	    	 sys_clock = 333333333;
        	    	 break;
        	    case 1:
        	    	 sys_clock = 500000000;
        	    	 break;
        	    case 2:/*assume that we only have 393/196 or 442/147 combination and cpu clock is always the same as system clock if PLL1 is used*/
        	    	 if( *AMAZON_S_CGU_SYS & 0x1 ){
        	    	  sys_clock = 442000000;
        	    	}else{
        	    		sys_clock = 393000000;
        	    	}
        	    	 break;	 
        	    default:
        	    	 sys_clock = 500000000;
        	    	 break;
        }
	    return sys_clock;
}


unsigned int get_ddr_clk(void)
{
	      unsigned int ddr_clk;
        if ((*AMAZON_S_CGU_SYS) & 0x1){
               ddr_clk = get_sys_clk()/3;
        }else{
        	     ddr_clk = get_sys_clk()/2;
        }
        return ddr_clk;
}


uint get_cpu_clk(void)
{
	      unsigned int cpu_clk;
        if(*AMAZON_S_CGU_SYS & 0x04 ){
        	 cpu_clk = get_ddr_clk(); 
        }else{
        	 cpu_clk = get_sys_clk();  
        }
        	
        return cpu_clk;
    
}


uint get_fpi_clk(void)
{
        unsigned int fpi_clk;
        if(*AMAZON_S_CGU_SYS & 0x40 ){
           fpi_clk = get_ddr_clk()/2;
        }else{
        	 fpi_clk = get_ddr_clk();
        }
        return fpi_clk;
}

uint get_ssc_clk(void)
{
	  return get_fpi_clk(); /*ssc clock is the same as fpi clock*/
}
