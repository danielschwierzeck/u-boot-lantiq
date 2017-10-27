
 /* Created for HN1 by Andrei Toma */

 #include <config.h> 
#include <common.h>
#include <command.h>
#include <version.h>
#include <net.h>
#include <environment.h>

#define asc_puts serial_puts

/*****************************************************************************
 * testDCDC
 * Copyright (c) 2011, Lantiq Inc., All rights reserved
 *****************************************************************************/

//generate less code
#define MINIMIZE_DCDC_CODE

#ifndef MINIMIZE_DCDC_CODE
typedef unsigned long   UINT32;

typedef unsigned char u8;
#define REG8( addr )    (*(volatile u8 *) (addr))
void dcdc_ddr_w8(char vbyte, UINT32 abyte)
{
  UINT32 a;
  a= 0xBF106C00 + abyte;
  REG8(a)=vbyte;
}

void sys1_hw_activate(int i)
{
  //unknown function.
}

UINT32 status_r32(int i)
{
  //unknown function.
  return 0;
}

#else
#define dcdc_ddr_w8(vbyte, abyte) \
  (*(volatile unsigned char *) (0xBF106C00 + (unsigned long)(abyte))) = (char)(vbyte)

#define status_r32(value) (0)
#endif


#define  pdi_pid_hi_b0              0x00
#define  pdi_pid_lo_b0              0x01
#define  pdi_pid_hi_b1              0x02
#define  pdi_pid_lo_b1              0x03
#define  pdi_pid_hi_b2              0x04
#define  pdi_pid_lo_b2              0x05
#define  pdi_clk_set0               0x06
#define  pdi_clk_set1               0x07
#define  pdi_pwm0                   0x08
#define  pdi_pwm1                   0x09
#define  pdi_bias_vreg              0x0A
#define  pdi_dig_ref                0x0B
#define  pdi_general                0x0C
#define  pdi_adc0                   0x0D
#define  pdi_adc1                   0x0E
#define  pdi_adc2                   0x0F

#define  pdi_conf_test_ana_noauto   0x12
#define  pdi_conf_test_dig_noauto   0x13

#define  pdi_duty_cycle             0x16
#define  pdi_non_ov_delay           0x17
#define  pdi_analog_gain            0x18
#define  pdi_duty_cycle_max_sat     0x19
#define  pdi_duty_cycle_min_sat     0x1A
#define  pdi_duty_cycle_max         0x1B
#define  pdi_duty_cycle_min         0x1C
#define  pdi_error_max              0x1D
#define  pdi_delay_deglitch         0x1F
#define  pdi_latch_control_noauto   0x21
#define  pdi_cap_clk_cnt            0x22
#define  pdi_mdll_divider           0x23

#define  ACTS_DCDCDDR                         0
#define  fuse1                                0
#define  STATUS_FUSE1_OFFSETDDRDCDC_MASK      0
#define  STATUS_FUSE1_OFFSETDDRDCDC_OFFSET    0
#define  STATUS_FUSE1_GAINDDRDCDC_MASK        0
#define  STATUS_FUSE1_GAINDDRDCDC_OFFSET      0

  //CLK_SET0_Value from XLS
#define  DCDC_CLK_SET0_MDLL_MUL_PWM1000       0x26
#define  DCDC_CLK_SET1_MDLL_RES_OFFSET        0
#define  DCDC_BIAS_VREG_VREG_SEL_NOMINAL      0x10
#define  DCDC_GENERAL_OS_EN                   0x04
#define  DCDC_GENERAL_RESERVED0               0x08
#define  DCDC_GENERAL_SET_LSB_DIGREF          0x80
#define  DCDC_ANALOG_GAIN_ATTENUATE_ANA       0x1
#define  DCDC_DELAY_DEGLITCH_ALARM_DEGLITCH_OFFSET 0
#define  DCDC_DELAY_DEGLITCH_RAMP_DELAY_OFFSET  4


#ifndef MINIMIZE_DCDC_CODE
/**
 * Calculate coefficients for dcdc controller
 * @param[in]   L   Inductance in nH
 * @param[in]   C   Capacity in uF
 * @param[in]   fsw frequency in kHz
 * @param   b0  returns b0 coefficient
 * @param   b1  returns b1 coefficient
 * @param   b2  returns b2 coefficient
 * @return
 *  0   on success
 *  -1  on error
 */
int calc_dcdc_coeff(int L, int C, unsigned int fsw,
    unsigned short *b0, unsigned short *b1, unsigned short *b2)
{
    /** \todo calculate these coefficients */
    if ((L==4700) && (C==22) && (fsw==977)) {
        /* L=4.7uH, C=22uF, fsw=0.977MHz */
        *b0 = 0x0181;
        *b1 = 0xFCEA;
        *b2 = 0x0198;
        return 0;
    } else if ((L==1500) && (C==166) && (fsw==977)) {
        /* L=1.5uH,C=166uF, fsw=0.977MHz */
        *b0 = 0x0256;
        *b1 = 0xFB41;
        *b2 = 0x026C;
        return 0;
    } else if ((L==1500) && (C==166) && (fsw==1950)) {
        /* L=1.5uH,C=166uF, fsw=1.95MHz */
        *b0 = 0x04AB;
        *b1 = 0xF696;
        *b2 = 0x04C0;
        return 0;
    } else {
        myprintf("No DCDC coefficients for L=%d.%03duH, C=%duF, "
            "fsw=%d.%03dMHz\n",
            L/1000, L%1000, C, fsw/1000, fsw%1000);
        return -1;
    }
}
#endif

#ifdef CONFIG_HN1_DDR1
#define    dcdc_ddr_voltage 2500
#define    dcdc_dig_ref 225
#else
#define    dcdc_ddr_voltage 1800
#define    dcdc_dig_ref 180
#endif

// The function is called from assembly, with C stack available
void configure_ddr_dcdc(void)
{
    volatile unsigned int i,j;

    //falcon_dcdc_ddr_init();
    {
        #ifndef MINIMIZE_DCDC_CODE
        int ret;
        unsigned char dcdc_dig_ref, dcdc_offset_fuse, dcdc_gain_fuse;
        #endif
        unsigned short b0, b1, b2;

        #ifndef MINIMIZE_DCDC_CODE
        sys1_hw_activate(ACTS_DCDCDDR);
        #endif

        #ifndef MINIMIZE_DCDC_CODE
        dcdc_offset_fuse = (status_r32(fuse1) & STATUS_FUSE1_OFFSETDDRDCDC_MASK)
            >> STATUS_FUSE1_OFFSETDDRDCDC_OFFSET;
        dcdc_gain_fuse = (status_r32(fuse1) & STATUS_FUSE1_GAINDDRDCDC_MASK)
            >> STATUS_FUSE1_GAINDDRDCDC_OFFSET;

        if ((dcdc_gain_fuse == 0) && (dcdc_offset_fuse == 0)) {
            /* unfused chip? */
            dcdc_gain_fuse = 32;
        }

        dcdc_dig_ref = ((( (((dcdc_ddr_voltage/10) + 100)*64 - 75) *
                  (320 + (dcdc_gain_fuse-32)) ) / 32000 ) - dcdc_offset_fuse);
        #endif

        /* disable */
        dcdc_ddr_w8(0x78, pdi_conf_test_ana_noauto);
        dcdc_ddr_w8(0x00, pdi_conf_test_dig_noauto);

        #ifndef MINIMIZE_DCDC_CODE
        ret = calc_dcdc_coeff(4700, 22, 977, &b0, &b1, &b2);
        if (ret == 0)
        {
            dcdc_ddr_w8(b0>>8, pdi_pid_hi_b0);
            dcdc_ddr_w8(b0, pdi_pid_lo_b0);
            dcdc_ddr_w8(b1>>8, pdi_pid_hi_b1);
            dcdc_ddr_w8(b1, pdi_pid_lo_b1);
            dcdc_ddr_w8(b2>>8, pdi_pid_hi_b2);
            dcdc_ddr_w8(b2, pdi_pid_lo_b2);
        }
        #else
        //The b0=0x0181 is OK for 25MHz only, with default L population
        //The b1=0xFCEA is OK for 25MHz only, with default L population
        //The b2=0x0198 is OK for 25MHz only, with default L population
        //Note: until the code size is reduced, use a single set of values
        if (((REG32(BSP_RCU_GP_STRAP))& (1<<13))!=0)
        {
            //myprintf("\n Use Lantiq third-party AFE.");
            b0=0x0185;
            b1=0xfce2;
            b2=0x019d;

            dcdc_ddr_w8(0x01, pdi_mdll_divider);    //set divider to 2
        }
        else
        {
            //myprintf("\n Use Lantiq VR9 AFE.");
            b0=0x0124;
            b1=0xfda5;
            b2=0x013c;

            dcdc_ddr_w8(0x03, pdi_mdll_divider);    //set divider to 4
        }
        dcdc_ddr_w8(b0>>8, pdi_pid_hi_b0);
        dcdc_ddr_w8(b0, pdi_pid_lo_b0);
        dcdc_ddr_w8(b1>>8, pdi_pid_hi_b1);
        dcdc_ddr_w8(b1, pdi_pid_lo_b1);
        dcdc_ddr_w8(b2>>8, pdi_pid_hi_b2);
        dcdc_ddr_w8(b2, pdi_pid_lo_b2);
        #endif

        dcdc_ddr_w8(DCDC_CLK_SET0_MDLL_MUL_PWM1000, pdi_clk_set0);
        //can skip this        dcdc_ddr_w8((1<<DCDC_CLK_SET1_MDLL_RES_OFFSET), pdi_clk_set1);

        //can skip this        dcdc_ddr_w8(0xFF, pdi_pwm0);
        dcdc_ddr_w8(0x00, pdi_pwm1);
        //can skip this        dcdc_ddr_w8(DCDC_BIAS_VREG_VREG_SEL_NOMINAL, pdi_bias_vreg);
        dcdc_ddr_w8(dcdc_dig_ref, pdi_dig_ref);
        //can skip this         dcdc_ddr_w8(DCDC_GENERAL_OS_EN | DCDC_GENERAL_RESERVED0 | DCDC_GENERAL_SET_LSB_DIGREF, pdi_general);
        //can skip this         dcdc_ddr_w8(0x62, pdi_adc0); /* reset value */
        //can skip this         dcdc_ddr_w8(0x12, pdi_adc1); /* reset value */
        //can skip this         dcdc_ddr_w8(0x77, pdi_adc2); /* reset value */
        dcdc_ddr_w8(0x00, pdi_duty_cycle);
        //can skip this         dcdc_ddr_w8(0x47, pdi_non_ov_delay);
        dcdc_ddr_w8(DCDC_ANALOG_GAIN_ATTENUATE_ANA, pdi_analog_gain);
#ifdef CONFIG_HN1_DDR1
        dcdc_ddr_w8(0xC9, pdi_duty_cycle_max_sat);
#else
        dcdc_ddr_w8(0xA0, pdi_duty_cycle_max_sat);
#endif
        //can skip this        dcdc_ddr_w8(0x07, pdi_duty_cycle_min_sat);
        dcdc_ddr_w8(0x7E, pdi_duty_cycle_max);
        dcdc_ddr_w8(0xAC, pdi_duty_cycle_min);
        dcdc_ddr_w8(0x40, pdi_error_max);
        dcdc_ddr_w8(15 << DCDC_DELAY_DEGLITCH_ALARM_DEGLITCH_OFFSET |
                 7 << DCDC_DELAY_DEGLITCH_RAMP_DELAY_OFFSET,
                 pdi_delay_deglitch);
        dcdc_ddr_w8(0x51, pdi_latch_control_noauto);
        dcdc_ddr_w8(0x80, pdi_cap_clk_cnt);

        /* enable */
        dcdc_ddr_w8(0x07, pdi_conf_test_ana_noauto);
        dcdc_ddr_w8(0x03, pdi_conf_test_dig_noauto);

        //return;
    }

    //Add 100msec delay
    j=0;
    for (i=0; i<0x20000; i++)
    {
        j = j+0x1234;
    }

    return;
}

