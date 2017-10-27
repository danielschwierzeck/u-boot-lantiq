//#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/addrspace.h>
#include <asm/grx500.h>
#include <environment.h>
#include <nand.h>
#include <asm/boot.h>
#define GPIO_OUTPUT 1
#define GPIO_INPUT 0


extern void start_interaptiv(u32 addr);
extern void ibl(u32 cpu_num, u32 core_num, u32 vpe_num);

extern u32 get_cpu_id(void);

#ifdef CONFIG_LTQ_SECURE_BOOT
extern void bootrom_auth(u32 addr);
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

#ifdef CONFIG_NAND_ECC_BCH
/*
 * Begin and End of memory area for malloc(), and current "brk"
 */

static ulong mem_malloc_start;
static ulong mem_malloc_end;
static ulong mem_malloc_brk;


/*
 * The Malloc area is immediately below the monitor copy in DRAM
 */
void mem_malloc_init (ulong dest_addr, ulong size)
{
//  ulong dest_addr = BOOTSTRAP_CFG_MONITOR_BASE + gd->reloc_off;

    mem_malloc_end = dest_addr;
    mem_malloc_start = dest_addr - size;
    mem_malloc_brk = mem_malloc_start;

    memset ((void *) mem_malloc_start,
        0,
        mem_malloc_end - mem_malloc_start);
}

void *malloc(unsigned int size)
{
	/* ensure alignment */
	if (size & 0x7) {
		size += (8 - (size & 7));
	}

    if(size < (mem_malloc_end - mem_malloc_start))
    {
        mem_malloc_start += size;
        return (void *)(mem_malloc_start - size);
    }
    return NULL;
}

void *realloc(void *src,unsigned int size)
{
    return NULL;
}

void free(void *src)
{
    return;
}

void * calloc(
    size_t nelem,
    size_t size)
{
   return;
}

void *sbrk (ptrdiff_t increment)
{
    ulong old = mem_malloc_brk;
    ulong new = old + increment;

    if ((new < mem_malloc_start) || (new > mem_malloc_end)) {
        return (NULL);
    }
    mem_malloc_brk = new;
    return ((void *) old);
}
#else
void *malloc(unsigned int size)
{
	return NULL;
}
#endif /* CONFIG_NAND_ECC_BCH */

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

#if defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT)
void enable_eip123_iap_access()
{
   u32 reg_val = 0;

   // i=0;
   // i += permission_wr(0xbff80058, 0x1f);
   // i += permission_wr(0xbff80050, 0x1f);

   REG32(0xb608004c) &=~(1<<3);
   REG32(0xb608005c) |= 0xdfffff;

   reg_val = REG32(0xbe003F10);
   REG32(0xbe003F10) = reg_val & 0xFFFFFF00;
}
#endif /* defined(CONFIG_LTQ_EIP123_IAP_ACCESS) && !defined(CONFIG_MANUBOOT) */

void main(u32 cpu_num, u32 core_num, u32 vpe_num)
{
      int i;

      switch (cpu_num) {
        case 8:
#if !defined (CONFIG_GRX500_BOOT_4KEC_ONLY) /* IAP boot */
			/* Initialize flag */
			REG32(SRAMFLAG) = 0;
			/* trigger IAP to run */
			start_interaptiv(CONFIG_NAND_SPL_TEXT_BASE);
            #if defined(CONFIG_MANUBOOT_OTP_SUPPORT)
            wait:
            #endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) */
			/*wait until IAP release */
			while (REG32(SRAMFLAG) != IPCMAGIC); 
			mdelay(200);
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
           mdelay(200);
           while (REG32(SRAMFLAG) != IPCMAGIC);
	#endif /* defined(CONFIG_LTQ_SECURE_BOOT) && !defined(CONFIG_MANUBOOT) */
#endif  /* !CONFIG_GRX500_BOOT_4KEC_ONLY */

           #if defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined(CONFIG_GRX500_BOOT_4KEC_ONLY)
           /* this render the tos command become otp programming in manufacturing boot */
           /* and break the ability to load bootcore when RoT */
           otp_prog_execute();
           goto wait; /* back to wait magic */
           #else /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined (CONFIG_GRX500_BOOT_4KEC_ONLY) */
		   /* FMT settings */
           REG32(0xb49001d4) = CONFIG_FMT1_REG;
           nand_boot();
           #endif /* defined(CONFIG_MANUBOOT_OTP_SUPPORT) && !defined (CONFIG_GRX500_BOOT_4KEC_ONLY) */
           break;
        case 0:
            for (i=0; i<4; i++){                            //Reset All MSG
                REG32(CPUMSG + 4*i) = 0;
                REG32(INTMSG + 4*i) = 0;
                REG32(JMPMSG + 4*i) = 0;
            }

           REG32(CPUMSG)+=1; 
           /* 
           REG32(0xb23f0014) = 2;
           for (i=0; i<32; i++){
                REG32(0xb23f0018 + i*4) = 5;
           }
           mdelay(500);
           */
           //while(REG32(0xa0400000)!=0x88888888);
           nand_boot();
           break;
        default:
           ibl(cpu_num,core_num,vpe_num);
           //while(1);
           break;
      }
}
	

