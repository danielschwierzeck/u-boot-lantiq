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
/* Note:
* timer 2 is used for the u-boot.
* this timer support prescaler, default 0 - gives tick every cycle.
*/
#define timer_max_count0  	0x180 /*value to count down from for timer 0*/
#define timer_max_count1  	0x184 /*value to count down from for timer 1*/
#define timer_max_count2  	0x188 /*value to count down from for timer 2*/
#define timer_max_count3  	0x18c /*value to count down from for timer 3*/
#define timer_config  		0x1a4 /*addr 0x1a4:
                                    bit0-timer0 oneshotmode, bit1-timer1 oneshotmode, bit2-timer2 oneshotmode, bit3-timer3 oneshotmode
                                    bit4-timer0 enable, bit5-timer1 enable, bit6-timer2 enable, bit7-timer3 enable,*/
#define timer_2_prescaler  		0x1a8 /*0-no prescaler, like timer 0 & 1*/
#define timer_3_prescaler  		0x1ac /*0-no prescaler, like timer 0 & 1*/
#define timer_count_value0  	0x190 /*timer 0 count value*/
#define timer_count_value1  	0x194 /*timer 1 count value*/
#define timer_count_value2  	0x198 /*timer 2 count value*/
#define timer_count_value3  	0x19c /*timer 3 count value*/

#define TIME_CLK_ENABLE_REG_VAL                                 0x00000040
#define TIME_CLK_ENABLE_REG_MASK                                0x00000040

#define TICKS_2_MICROSEC(x)		((x)/1000000)

void ReadModWriteReg(unsigned long , unsigned long , unsigned long, unsigned long );
void WriteReg(unsigned long , unsigned long , unsigned long ) ;
unsigned long ReadReg (unsigned long , unsigned long );
static void mips_count_set (ulong val)
{
	WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_max_count2, val);
}

static unsigned long mips_count_get (void)
{
	return ( (volatile unsigned long ) ReadReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_count_value2));
}

void enable_timer (void) 
{
        WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_config, 0xff);
}

void disable_timer (void) 
{
        WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_config, 0);
}


/*
 * timer without interrupts
 * Explain value of 0x18 for prescaler:
 *   1/24000000=41.667 nano per cycle
 *   1/1000000=0.000001 (milisec)
 *   0.000001/(41.667e-9) =  24 (0x18)
 * Warning: prescaler id 8 bytes, if clock is higher than 240 need to test if prescaler os not more than 8 bits.
 *         If it is bigger use half of value and account it on timer Init.
 */
int timer_init(void)
{
 	unsigned long prescaler;
 	
 	ReadModWriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, 0, TIME_CLK_ENABLE_REG_VAL, TIME_CLK_ENABLE_REG_MASK);
 	prescaler = TICKS_2_MICROSEC(CONFIG_SYS_HZ);
 	WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_2_prescaler, prescaler);
// 	WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_2_prescaler, 0x18);  // 0x18 - gives tick/micro for 24M clock TODO- change when clock change
	set_timer (0xffffffff);
	enable_timer();
	return 0;
}

void reset_timer(void)
{
	WriteReg (VBG400_SYS_INTERFACE_BASE_ADDR, timer_count_value2, 0);
}

/* get_timer - returns in mili */
ulong get_timer(ulong base)
{
	//return (mips_count_get()/1000) - base;
	unsigned long temp = mips_count_get();
    temp = temp/1000;
	return temp - base;
}

void set_timer(ulong t)
{
	mips_count_set(t);
}

/* __delay - the timer returns tick every 1 micro. No need to change value */
void __udelay(unsigned long usec)
{
	ulong tmo;
	ulong start = mips_count_get()/*get_timer(0)*/;

	tmo = usec /* * (CONFIG_SYS_HZ / 1000000)*/;

	mips_count_set (tmo);
	while ((ulong)((mips_count_get() - start)) < tmo) ;

}


void mdelay (unsigned long msec)
{
       int i,j;
	   for(i=0;i<msec;i++)
	   {
	      __udelay(1000);
	   }

}
									  

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On MIPS it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
	return mips_count_get();
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On MIPS it returns the number of timer ticks per second.
 */
ulong get_tbclk(void)
{
	return CONFIG_SYS_HZ;
}

unsigned long ReadReg (unsigned long base, unsigned long offset ) {

        volatile unsigned long *ptr;

        ptr = (unsigned long *) (base + offset);
        return *ptr;
}

void WriteReg(unsigned long add, unsigned long offset, unsigned long val) {

        volatile unsigned long *ptr;

        ptr = (unsigned long *) (add + offset);

        *ptr = val;
}

void ReadModWriteReg(unsigned long add, unsigned long offset, unsigned long val, unsigned long mask)
{

        volatile unsigned long *ptr;
        unsigned long regVal;

        ptr = (unsigned long *) (add + offset);
        regVal = (*ptr) & (~mask);
        regVal = regVal | val;

        *ptr = regVal;
}
