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
#include <command.h>
#include <asm/addrspace.h>
#include <environment.h>


#define GPIO_OUTPUT 1
#define GPIO_INPUT 0
#define MAX_4KEC_DDR	128

extern u32 get_cpu_id(void);

int cpu_is_cps(void)
{
    int ret=0;
    if(get_cpu_id()==0xa1) ret=1;
    return ret;
}

phys_size_t initdram(int board_type)
{
	if (!cpu_is_cps() && (CONFIG_IFX_MEMORY_SIZE > 128))
		return (1024*1024*MAX_4KEC_DDR);
	else
		return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}

void config_led(void)
{
	int i;
	REG32(GPT2_CLC) = 0x00010100;							//gptc2 - full kernel clock
	REG32(GPT1_CLC) = 0x00010100;							//gptc1 - full kernel clock
	REG32(GPT3_CLC) = 0x00010100;							//gptc0 - full kernel clock
	REG32(GPT3_RELOAD_2_A) = 50;							//GPT_RELOAD_N_A		
	REG32(GPT3_CON_2_A) = 0x00;								//16-bit, timer, count down, auto-reload
	REG32(GPT3_RUN_2_A) = 0x05;								//Reload and Run 	
	while ((REG32(GPT3_CON_2_A) & 1) == 0);					//wait for status bit

	/* GPIO settings */
	REG32(0xb6c80000 + 4*4) = 0;							//GPIO4 as IO
	REG32(0xb6c80080) &= ~(1<<4);							//GPIO4 PUEN disabled
	REG32(0xb6c80084) &= ~(1<<4);							//GPIO4 PDEN disabled
	REG32(0xb6c80088) |= (1<<4);							//GPIO4 fast slowrate
	REG32(0xb6c8008c) |= (3<<(2*4));						//GPIO4 12mA driver
	REG32(0xb6c80094) &= ~(1<<4);							//GPIO4 normal output (not open drain) - if output

	REG32(0xb6c80000 + 4*5) = 0;							//GPIO5 as IO
	REG32(0xb6c80080) &= ~(1<<5);							//GPIO5 PUEN disabled
	REG32(0xb6c80084) &= ~(1<<5);							//GPIO5 PDEN disabled
	REG32(0xb6c80088) |= (1<<5);							//GPIO5 fast slowrate
	REG32(0xb6c8008c) |= (3<<(2*5));						//GPIO5 12mA driver
	REG32(0xb6c80094) &= ~(1<<5);							//GPIO5 normal output (not open drain) - if output

	REG32(0xb6c80000 + 4*6) = 0;							//GPIO6 as IO
	REG32(0xb6c80080) &= ~(1<<6);							//GPIO6 PUEN disabled
	REG32(0xb6c80084) &= ~(1<<6);							//GPIO6 PDEN disabled
	REG32(0xb6c80088) |= (1<<6);							//GPIO6 fast slowrate
	REG32(0xb6c8008c) |= (3<<(2*6));						//GPIO6 12mA driver
	REG32(0xb6c80094) &= ~(1<<6);							//GPIO6 normal output (not open drain) - if output
	
   	REG32(0xb6c80010) = 1;									//LED_ST selected instead of GPIO4 
   	REG32(0xb6c80014) = 1;									//LED_D  selected instead of GPIO5   
   	REG32(0xb6c80018) = 1;									//LED_SH selected instead of GPIO6

	/* End GPIO settings */
   	
   	REG32(SSO_CON0) = 0x44000000;				            //SSIO_SSO_CON0, /auto dim = 0 disabled, blink rate = update rate
														
#ifdef CONFIG_BOARD_EASY350
	REG32(SSO_CON1) = 0x40000003;							//SSIO_SSO_CON1;
#else	
	REG32(SSO_CON1) = 0x4000000f;							//LED_SH=25MHz, LED_ST=single, Data Offset = 0, 
#endif														//Blink rate for LED[23:0] - use FSC: 8K/4000 = 2Hz	

	REG32(LED_BLINK_H8_0) = 0x00000000;						//Blink rate for LED[28:24] - use FSC	
	REG32(LED_BLINK_H8_1) = 0x00000000;						//Blink rate for LED[31:29] - use FSC
								 							//Blink rate for LED[23:0]  - use FSC 	
															//   if use FSC, rate = 2Hz  (FSC = 8KHz/4000)	 
								 							//   if use GPT, rate = 1KHz (GPTC0-T2A = 2MHz/2000)								 							
	REG32(SSO_AR) = 0x00000000;								//CPU0 selected	
	
	for (i = 0; i < 32; i++)
		REG32(DUTY_CYCLE_0 + i*4) = 0x80;	
		
//Set Orange Color R:G:B = half bright of 255:165:0
#ifdef CONFIG_BOARD_EASY350	
	REG32(SSO_CPU0) = 0xa000;		//Blue off
	REG32(DUTY_CYCLE_13) = 0x80;		//Red  
	REG32(DUTY_CYCLE_15) = 0x52;		//Grn		
#else
	REG32(SSO_CPU0) = 0xa0000000;	//Blue off
	REG32(DUTY_CYCLE_29) = 0x80;		//Red  
	REG32(DUTY_CYCLE_31) = 0x52;		//Grn		
#endif	

}

int flash_probe(void)
{
     return 1;
}

void show_boot_progress(int arg)
{
  return;
}

int checkboard (void)
{
    int i;
    if(cpu_is_cps()){
      printf("interAptiv\n");
      printf("cps cpu/ddr run in %d/%d Mhz\n",get_cpu_clk()/1000000, get_ddr_clk()/1000000);
    }else{
       printf("4Kec\n");
    }

#ifdef CONFIG_GRX500_A21
	config_led();
#endif

    return 0;
}

void config_gpio(u32 pin, int dir, u32 func_num)
{
    u32 portmux_base = pin>31?GPIO_PAD_CTRL_PORTMUXC32:GPIO_PAD_CTRL_PORTMUXC0; 
    u32 dir_base = pin>31?GPIO_FUNCTION_DIR_1:GPIO_FUNCTION_DIR_0;    
    u32 od_base = pin>31?GPIO_PAD_CTRL_OD_1:GPIO_PAD_CTRL_OD_0;
    u32 rel_port_num = pin>31?(pin-32):pin;

    REG32(portmux_base + (rel_port_num<<2)) = func_num;

    if(dir == GPIO_OUTPUT)
    {
        REG32(dir_base)|= (1<<rel_port_num); 
        REG32(od_base) &=~(1<<rel_port_num);
    }else{
        REG32(dir_base)&= ~(1<<rel_port_num);
        //REG32(od_base) |=(1<<rel_port_num);
    }
}

#ifdef CONFIG_LANTIQ_SPI

int spi_gpio_init(unsigned int cs)
{
     /*Enable SPI0 clock*/
     REG32(CGU_CLKGCR1_A)|= CGU_CLKGCR1_A_SPI0_MASK;
     
     /*GPIO 18, SPI0 CLK*/
     config_gpio(18, GPIO_OUTPUT, 1);
    
     /*enable all chip select signals*/ 
     config_gpio(15, GPIO_OUTPUT, 1);
     config_gpio(10, GPIO_OUTPUT, 0x2);
     config_gpio(11, GPIO_OUTPUT, 0x3);
     
     /*RX gpio*/
     config_gpio(17, GPIO_OUTPUT, 0x1);
     /*TX gpio*/
     config_gpio(16, GPIO_INPUT, 0x1);
   
     return 1;
}

#endif


#ifdef CONFIG_NAND_FLASH
void nand_gpio_init(void)
{
     config_gpio(13, GPIO_OUTPUT, 1);
     config_gpio(23, GPIO_OUTPUT, 1);
     config_gpio(24, GPIO_OUTPUT, 1);
     config_gpio(48, GPIO_INPUT,  1);
     config_gpio(49, GPIO_OUTPUT, 1);
     config_gpio(50, GPIO_OUTPUT, 1);
     config_gpio(51, GPIO_OUTPUT, 1);
     config_gpio(52, GPIO_OUTPUT, 1);
     config_gpio(53, GPIO_OUTPUT, 1);
     config_gpio(54, GPIO_OUTPUT, 1);
     config_gpio(55, GPIO_OUTPUT, 1);
     config_gpio(56, GPIO_OUTPUT, 1);
     config_gpio(57, GPIO_OUTPUT, 1);
     config_gpio(59, GPIO_OUTPUT, 1);
     config_gpio(60, GPIO_OUTPUT, 1);
     config_gpio(61, GPIO_OUTPUT, 1);

     REG32(EBU_ADDR_SEL_0) = 0x17400051;

}
#endif

int board_eth_init(bd_t *bis)
{
   if (grx500_eth_initialize(bis)<0)
             return -1;
   
	return 0;
}
						 
