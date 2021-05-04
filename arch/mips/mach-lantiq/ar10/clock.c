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

uint get_sys_clk(void)
{
    uint sys_clk;

#if defined (CONFIG_DRIVER_GRX390)
	unsigned int freq = ((*AR10_CGU_SYS >> 9) & 0x3);
	
	switch (freq) {
		case 0: 
			sys_clk = 600000000;
			break;
		case 1:
			sys_clk = 666000000;
			break;
		case 2:
			sys_clk = 720000000;
			break;
	}
#else
    if ( *AR10_CGU_SYS & 0x100 ){
    	 sys_clk = 500000000;
    }else{
    	 sys_clk = 600000000;
    }
#endif	
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

#if defined (CONFIG_DRIVER_GRX390)
unsigned int get_fpi_clk(void)
{
    unsigned int fpi_clk;
    unsigned int cpu_fs = ((*AR10_CGU_SYS >> 9) & 0x3);
	unsigned int ddr_fs = ((*AR10_CGU_SYS) & 0x3);

	if (REG32(0xbf107350) & (1 << 17)) {
     /* check BSP_MPS_ID_CFG, if bit 17 is set, clock is max at 600 Mhz, else 720/666 */
	    if ((*AR10_CGU_IF_CLK >> 25) & 0x01)
			fpi_clk = 300000000;
		else
		    fpi_clk = 150000000;
    } else {
		switch (cpu_fs) {
			case 0:
				if (ddr_fs == 1)
					fpi_clk = 300000000;
				else
					fpi_clk = 150000000;
				break;
			case 1:
				fpi_clk = 333000000;
				break;
			case 2:
				if (ddr_fs == 1)
					fpi_clk = 360000000;
				else 
				    fpi_clk = 180000000;
				break;
		}
	}
	return fpi_clk;
}
#else
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
#endif
