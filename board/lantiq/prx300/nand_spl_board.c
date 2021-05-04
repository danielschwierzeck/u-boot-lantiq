/* Copyright (c) 2010-2017, Intel Corporation.
 *
 * Main function from start.S in the first stage bootloader (SPL)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
*/


#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/arch/prx300.h>
#include <environment.h>
#include <nand.h>
#include <asm/boot.h>
#include <lantiq.h>
#include <asm/reboot.h>

#define GPIO_INPUT 	0
#define GPIO_OUTPUT 	1
#define RX0_PIN     	2
#define TX0_PIN     	3
#define SPI0_CLK_PIN    4
#define SPI_CS0_PIN 	5

#define QSPI_CLK	0
#define	QSPI_CS		1
#define QSPI_IO_0	2
#define QSPI_IO_1	3
#define QSPI_IO_2	4
#define QSPI_IO_3	5

extern void start_interaptiv(u32 addr);
extern void ibl(u32 cpu_num, u32 core_num, u32 vpe_num);
extern void config_qspi_refclk(void);
extern u32 get_cpu_id(void);

#ifdef CONFIG_LTQ_SECURE_BOOT
extern void bootrom_auth(u32 addr);
extern u32 get_rbid_spl(void);
#endif /* CONFIG_LTQ_SECURE_BOOT */
#if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
extern int otp_prog_execute(void);
#endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) */

int cpu_is_cps(void)
{
    int ret=0;
    if(get_cpu_id()==0xa1) ret=1;
    return ret;
}

void hw_watchdog_reset(void) {};

void pads_init_pin(unsigned int pin, unsigned int value)
{
	u32 rel_pin_no = pin > 32 ? (pin - 32) : pin;
	u32 offset = pin > 32 ? (0x100 + (rel_pin_no << 2)) : (rel_pin_no << 2);

	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, offset, value);
}

void config_gpio(u32 pin, int dir)
{
	u32 pad_base = GPIO_PAD_CTRL_MODULE_BASE;
	u32 gpio_base = GPIO_FUNCTION_MODULE_BASE;
	u32 portmux_base = pin > 31 ? PORTMUXC32 : PORTMUXC0;
	u32 dir_base = pin > 31 ? DIR_1 : DIR_0;
	u32 od_base = pin > 31 ? OD_1 : OD_0;
	u32 puen_base = pin > 31 ? PUEN_1 : PUEN_0;
	u32 pden_base = pin > 31 ? PDEN_1 : PDEN_0;
	u32 src_base = pin > 32 ? SRC_1 : SRC_0;
	u32 dcc_base = pin > 32 ? DCC_1 : DCC_0;
	u32 rel_port_num = pin > 31 ? (pin - 32) : pin;

	ltq_w32(pad_base + portmux_base, (rel_port_num << 2), 0x0);
	ltq_w32(pad_base, puen_base,
		(ltq_r32(pad_base, puen_base) & ~(1 << rel_port_num)));
	ltq_w32(pad_base, pden_base,
		(ltq_r32(pad_base, pden_base) & ~(1 << rel_port_num)));
	ltq_w32(pad_base, src_base,
		(ltq_r32(pad_base, src_base) | (1 << rel_port_num)));
	ltq_w32(pad_base, dcc_base,
		(ltq_r32(pad_base, dcc_base) | (3 << (2 * rel_port_num))));
	ltq_w32(pad_base, od_base,
		(ltq_r32(pad_base, od_base) & ~(1 << rel_port_num)));

	if (dir) {
		ltq_w32(gpio_base, dir_base,
			(ltq_r32(gpio_base, dir_base) | (1 << rel_port_num)));
	} else {
		ltq_w32(gpio_base, dir_base,
			(ltq_r32(gpio_base, dir_base) & ~(1 << rel_port_num)));
	}
}

int spi_gpio_init(unsigned int cs)
{
     /*Enable SPI0 clock*/
	 ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A,
	 		(ltq_r32(CGU_MODULE_BASE, CGU_CLKGCR1_A) | CGU_CLKGCR1_A_SPI0_MASK));

	config_gpio(RX0_PIN, GPIO_INPUT);
	pads_init_pin(RX0_PIN, 0x3);

	config_gpio(TX0_PIN, GPIO_OUTPUT);
	pads_init_pin(TX0_PIN, 0x3);

	config_gpio(SPI0_CLK_PIN, GPIO_OUTPUT);
	pads_init_pin(SPI0_CLK_PIN, 0x3);

	config_gpio(SPI_CS0_PIN, GPIO_OUTPUT);
	pads_init_pin(SPI_CS0_PIN, 0x3);

	/* check for 1.8v */
	if ((ltq_r32(CHIP_TOP_MODULE_BASE, GP_STRAP)
			& (1 << 15)) != 0x00008000)
		ltq_w32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL,
			(ltq_r32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL)
			| CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_VDD1V8));

	return 1;
}

int qspi_gpio_init(unsigned int cs)
{
	config_qspi_refclk();

	pads_init_pin(QSPI_CLK, 0x2);
	pads_init_pin(QSPI_CS, 0x2);
	pads_init_pin(QSPI_IO_0, 0x2);
	pads_init_pin(QSPI_IO_1, 0x2);
	pads_init_pin(QSPI_IO_2, 0x2);
	pads_init_pin(QSPI_IO_3, 0x2);

	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, DCC_0,
		(ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, DCC_0) | 0xFFF));

	ltq_w32(GPIO_PAD_CTRL_MODULE_BASE, SRC_0,
		(ltq_r32(GPIO_PAD_CTRL_MODULE_BASE, SRC_0) | 0x3F));

	/* check for 1.8v */
	if ((ltq_r32(CHIP_TOP_MODULE_BASE, GP_STRAP)
			& (1 << 15)) != 0x00008000)
		ltq_w32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL,
			(ltq_r32(CHIP_TOP_MODULE_BASE, PAD_POWER_SUPPLY_SEL)
			| CONST_PAD_POWER_SUPPLY_SEL_SEL_1V8_RIGHT1_VDD1V8));

	return 0;

}

#if defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT)
void enable_eip123_iap_access()
{
   u32 reg_val = 0;

   #ifdef CONFIG_DRIVER_GRX500
   /* TODO: NGI settings may need to change */
   REG32(0xb608004c) &=~(1<<3);
   REG32(0xb608005c) |= 0xdfffff;
   #endif /* CONFIG_DRIVER_GRX500 */

   reg_val = REG32(0xbe003F10);
   REG32(0xbe003F10) = reg_val & 0xFFFFFF00;
}
#endif /* defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT) */

#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_PRX300) && !defined(CONFIG_MANUBOOT)
/* self FSB rollback id check */
/* for now enabled for PRX300 only */
/* can be ported to grx500 too though */
void self_fsb_rollback_id_chk(void)
{
	u32 cid   = 0;

	/* only consider bits 0:15  as uboot+fsb rollback bits*/
	cid = get_rbid_spl();

	if (CONFIG_SB_ROLLBACKID_VALUE < cid)
		_machine_restart();

	return;
}
#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_PRX300) && !defined(CONFIG_MANUBOOT) */


void main(u32 cpu_num, u32 core_num, u32 vpe_num)
{

	int i;

#if defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_PRX300) && !defined(CONFIG_MANUBOOT)
	/* FSB self rollbackid check with otp antirollback value */
	self_fsb_rollback_id_chk();
#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && defined(CONFIG_DRIVER_PRX300) && !defined(CONFIG_MANUBOOT) */

	switch (cpu_num) {
	case 8:
#if !defined (CONFIG_PRX300_BOOT_4KEC_ONLY) /* IAP boot */
		/* Initialize flag */
		REG32(SRAMFLAG) = 0;
		/* trigger IAP to run */
		start_interaptiv(CONFIG_NAND_SPL_TEXT_BASE);
            #if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
		wait:
            #endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) */
		/*wait until IAP release */
		while (REG32(SRAMFLAG) != IPCMAGIC);
		//mdelay(200);
	#if defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT)
		/*auth uboot , agree on 0xa0800000 */
		bootrom_auth(0xa0800000);
		/* inform iap done */
		REG32(SRAMFLAG)= (~IPCMAGIC);
		asm("sync");
		#ifdef CONFIG_LTQ_EIP123_IAP_ACCESS
		/* need to do it after bootrom img auth, since they reset eip123 again */
		enable_eip123_iap_access();
		#endif /* CONFIG_LTQ_EIP123_IAP_ACCESS */
		/* next round of wait, tos command */
		//mdelay(200);
		while (REG32(SRAMFLAG) != IPCMAGIC);
	#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
#endif  /* !CONFIG_PRX300_BOOT_4KEC_ONLY */

	#if defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined(CONFIG_PRX300_BOOT_4KEC_ONLY)
		/* this render the tos command become otp programming in manufacturing boot */
		/* and break the ability to load bootcore when RoT */
		otp_prog_execute();
		goto wait; /* back to wait magic */
	#else /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined (CONFIG_PRX300_BOOT_4KEC_ONLY) */
		/* FMT settings */
		REG32(0xb49001d4) = CONFIG_PRX300_FMT1_REG;
		nand_boot();
	#endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined (CONFIG_PRX300_BOOT_4KEC_ONLY) */
		break;
        case 0:
		/* set IOCU0 value */
		ltq_w32(GCR_MODULE_BASE, IC_MADDR_0, 0x2);
		/* set all mconnid to 5 */
		for (i = 0; i < 32; i++)
			ltq_w32(GCR_MODULE_BASE, CCA_IC_MREQ_0 + i * 4, 0x5);

		nand_boot();
		break;
        default:
		ibl(cpu_num,core_num,vpe_num);
		//while(1);
		break;
      }
}


