/* Copyright (c) 2018, Intel Corporation.
 * PRX300 slim ethernet driver
 * Mohammad Firdaus B Alias Thani <m.aliasthani@intel.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <asm/gic.h>
#include <common.h>
#include <lantiq.h>
#include <config.h>
#include <asm/io.h>
#include <common.h>
#include <command.h>
#include <environment.h>
#include <watchdog.h>
#include <asm/mipsregs.h>
#include <asm/addrspace.h>

#define GPIO_INPUT		0
#define GPIO_OUTPUT		1
#define GPIO_HW			2

#define RX0_PIN			2
#define TX0_PIN			3
#define SPI0_CLK_PIN		4
#define SPI_CS0_PIN		5

#define QSPI_CLK		0
#define	QSPI_CS			1
#define QSPI_IO_0		2
#define QSPI_IO_1		3
#define QSPI_IO_2		4
#define QSPI_IO_3		5

#define MAX_4KEC_DDR		128
#define IAP_CPUID		0xa1
#define MEMMAX_THREADSCH7_UPPER MEMMAX_THREADSCH7 + 0x4

extern u32 get_cpu_id(void);
extern uint get_cpu_clk(void);
extern unsigned int get_ddr_clk(void);
extern void config_qspi_refclk(void);
extern int prx300_eth_initialize(bd_t *bis);
extern int gpio_reserve_and_set(unsigned int gpio,
				unsigned int func,
				unsigned int value);

int cpu_is_cps(void)
{
	int ret = 0;

	if (get_cpu_id() == IAP_CPUID)
		ret = 1;

	return ret;
}

phys_size_t initdram(int board_type)
{
	if (!cpu_is_cps() && (CONFIG_IFX_MEMORY_SIZE > 128))
		return (1024*1024*MAX_4KEC_DDR);
	else
		return (1024*1024*CONFIG_IFX_MEMORY_SIZE);
}

int flash_probe(void)
{
	return 1;
}

static void config_memmax_scheduler(void)
{
	u32 reg;

	reg = 2 << MEMMAX_THREADSCH7_QOS_MODE7_POS;
	reg |= 4 << MEMMAX_THREADSCH7_REQUEST_GROUP_SIZE7_POS;
	ltq_w32(DDR_MEMORY_SCHEDULER_MODULE_BASE,
		MEMMAX_THREADSCH7, reg);

	reg = 0x160020; 
	ltq_w32(DDR_MEMORY_SCHEDULER_MODULE_BASE,
		MEMMAX_THREADSCH7_UPPER, reg);

	reg = 4 << MEMMAX_THREADSCHEXT7_WORDS_PER_PERIOD_MAX7_POS;
	ltq_w32(DDR_MEMORY_SCHEDULER_MODULE_BASE,
		MEMMAX_THREADSCHEXT7, reg); 

	reg = 1 << MEMMAX_THREADSCH6_QOS_MODE6_POS;
	reg |= 4 << MEMMAX_THREADSCH6_REQUEST_GROUP_SIZE6_POS; 
	ltq_w32(DDR_MEMORY_SCHEDULER_MODULE_BASE,
		MEMMAX_THREADSCH6, reg);
}

void aquantia_phy_gpio_init(void)
{
	gpio_reserve_and_set(14, GPIO_OUTPUT, 0x2);
	gpio_reserve_and_set(15, GPIO_OUTPUT, 0x2);
	gpio_reserve_and_set(16, GPIO_OUTPUT, 0x2);
}

#ifdef CONFIG_QSPI_FLASH
/* idx:  Index
 * v_a:  Virtual address mapping
 * p_a:  Physical address to be mapped
 * pm:	 Page Mask
 * at:	 C, D, V, G Values
 * asid: Address Space Identifier
 */
void config_tlb(u32 idx, u32 v_a, u32 p_a, u32 pm, u32 at, u32 asid)
{
	u32 entry_hi;
	u32 entry_lo0, entry_lo1;

	entry_hi = v_a | asid;
	entry_lo0 = ((p_a >> 6) & (~0x3f)) | at;  //page 0
	entry_lo1 = ((p_a >> 6) & (~0x3f)) | at; //page 1 = page 0

	write_c0_index(idx);
	write_c0_pagemask(pm);
	write_c0_entryhi(entry_hi);
	write_c0_entrylo0(entry_lo0);
	write_c0_entrylo1(entry_lo1);
	asm volatile ("tlbwi");
	asm volatile ("ehb");

}
#endif /* CONFIG_QSPI_FLASH */

int checkboard(void)
{
	if (cpu_is_cps()) {
		printf("interAptiv\n");
		printf("cps cpu/ddr run in %d/%d Mhz\n",
			get_cpu_clk() / 1000000, get_ddr_clk() / 1000000);
	} else {
		printf("4Kec\n");
	}

#ifdef CONFIG_QSPI_FLASH
	/* Map address 0xB0000000 to VA 0x00000000 */
	config_tlb(16, 0x0, 0xb0000000, 0x7FFE000, 0x16, 0x08);
#endif /* CONFIG_QSPI_FLASH */

	/* Memmax config changes WA for traffic issues
 	 * during 20G traffic 
 	 * JIRA UBOOT_SW-596
 	 */
	config_memmax_scheduler();

	return 0;
}

#ifdef CONFIG_RST_CAUSE
static int add_reset_cause_env(u32 val_rst_state)
{
	char *Sname2 = NULL;

	if (val_rst_state & (1<<24))
		Sname2 = "PLL0B_RESET";
	if (val_rst_state & (1<<25))
		Sname2 = "SYSTEM_ERROR_RESET";
	if (val_rst_state & (1<<26))
		Sname2 = "EJTAG_RESET";
	if (val_rst_state & (1<<27))
		Sname2 = "POR_RESET";
	if (val_rst_state & (1<<30))
		Sname2 = "GLOBAL_SW_RESET";
	if (val_rst_state & (1<<31))
		Sname2 = "WDT_RESET";

	if(Sname2 != NULL)
		setenv("rst_cause", Sname2);

	return 0;
}

static int print_reset_cause(u32 val_rst_state)
{
	printf("Reset cause: ");
	if (val_rst_state & (1<<24))
		printf("PLL0B RESET\n");
	if (val_rst_state & (1<<25))
		printf("SYSTEM ERROR RESET\n");
	if (val_rst_state & (1<<26))
		printf("EJTAG RESET\n");
	if (val_rst_state & (1<<27))
		printf("POR RESET\n");
	if (val_rst_state & (1<<30))
		printf("GLOBAL SW RESET\n");
	if (val_rst_state & (1<<31))
		printf("WDT RESET\n");
	return 0;
}
#endif /* CONFIG_RST_CAUSE */

#ifdef CONFIG_BOARD_LATE_INIT
void setenv_cpu_clk(void)
{
	char str[33];

	memset((void *)str, 0, sizeof(str));
	sprintf(str, "%u", get_cpu_clk());
	setenv("cpuclk", str);

	return;
}

int board_late_init (void)
{
#ifdef CONFIG_RST_CAUSE
	u32 val_rst_state;
	val_rst_state = ltq_r32(RCU_MODULE_BASE, RST_STAT); /* 0xb6100014 */
	print_reset_cause(val_rst_state);
	add_reset_cause_env(val_rst_state);
#endif
	setenv_cpu_clk();
	return 0;
}
#endif

#ifdef CONFIG_LANTIQ_SPI
int spi_gpio_init(unsigned int cs)
{
	/*Enable SPI0 clock*/
	ltq_w32(CGU_MODULE_BASE, CGU_CLKGCR1_A,
		(ltq_r32(CGU_MODULE_BASE, CGU_CLKGCR1_A)
		| CGU_CLKGCR1_A_SPI0_MASK));

	gpio_reserve_and_set(SPI_CS0_PIN, GPIO_OUTPUT, 0x3);
	gpio_reserve_and_set(RX0_PIN, GPIO_INPUT, 0x3);
	gpio_reserve_and_set(TX0_PIN, GPIO_OUTPUT, 0x3);
	gpio_reserve_and_set(SPI0_CLK_PIN, GPIO_OUTPUT, 0x3);

	return 1;
}
#endif /* CONFIG_LANTIQ_SPI */

#ifdef CONFIG_LANTIQ_QSPI
int qspi_gpio_init(unsigned int cs)
{
	config_qspi_refclk();

	gpio_reserve_and_set(QSPI_CLK, GPIO_HW, 0x2);
	gpio_reserve_and_set(QSPI_CS, GPIO_HW, 0x2);
	gpio_reserve_and_set(QSPI_IO_0, GPIO_HW, 0x2);
	gpio_reserve_and_set(QSPI_IO_1, GPIO_HW, 0x2);
	gpio_reserve_and_set(QSPI_IO_2, GPIO_HW, 0x2);
	gpio_reserve_and_set(QSPI_IO_3, GPIO_HW, 0x2);

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
#endif /* CONFIG_LANTIQ_QSPI */

int board_eth_init(bd_t *bis)
{
#if 1
	/* Do not let 4KEc init the xpcs */
	if (get_cpu_id() != IAP_CPUID)
		return 0;
#endif
#ifdef CONFIG_PRX300_EXTERNAL_PHY
	aquantia_phy_gpio_init();
#endif
	if (prx300_eth_initialize(bis) < 0)
		return -1;

	return 0;
}
