#ifndef _BOOT_H
#define _BOOT_H

#define USE_SP 2				// [valid 1,2,3] 	:1 dcachelock/4kec, ddr/interAptiv
								//					:2 dcachelock/4kec, 1st ssb/interAptiv
								//					:3 dcachelock/4kec, 4th ssb/interAptiv
#define CORE_ON 2				// [valid 1,2]	 	:1 for only core0, 2 for both
#define VPE_ON 2				// [valid 1,2]		:1 for only vpe0, 2 for additional vpe1
#define GIC_ON   

#define GIC_SH_WEDGE_REG  *((volatile unsigned int*) (0xb2320280))
#define FIRST_IPI 19  			// GIC interrupts 56+ are used to signal interrupts between cores.

#define IPCMAGIC			0x344B6563			/* ASCII: 4Kec */
#define SRAMFLAG			0xbf807f00
#define MPS_DDR_LOC			0xbf807f04
#define MPS_SIZE_LOC		0xbf807f08
#define MPS_LOAD_ADDR		0xbf807f0C
#define CPUMSG				0xa000ff00		
#define INTMSG				0xa000ff10
#define JMPMSG				0xa000ff20
#define ITCMSG				0xa000ff30

#define STACK_BASE_ADDR	      0xa0008000  		/* InterAptiv uses ddr for stack */
#define STACK_SIZE_LOG2  	  13          		/* 13(8Kbytes), 17(128Kbytes), 20(1Mbytes) */
#define STACK_BASE_ADDR_4KEc  0x9fc02000  		/* 4KEc uses 8K dcache for stack */


#define CFG_CACHE_LINES  32
#define CFG_CACHELINE_SIZE  CFG_CACHE_LINES            

#define MPS_SRAM_BASE_ADDRESS   0xbf300000		/* to be confirmed */
#define MPS_SRAM_BOOT_OFFSET    0x1c0 

/* Offset for CPU1 (both CPUs have same register set) */
#define BOOT_BASE_ADDRESS   (MPS_SRAM_BASE_ADDRESS + MPS_SRAM_BOOT_OFFSET)
#define BOOT_CPU_OFFSET     0x20
 
#ifdef __ASSEMBLY__
#define BOOT_RVEC		   (BOOT_BASE_ADDRESS + 0x00)
#define BOOT_NVEC		   (BOOT_BASE_ADDRESS + 0x04)
#define BOOT_EVEC		   (BOOT_BASE_ADDRESS + 0x08)
#define BOOT_CP0_CAUSE     (BOOT_BASE_ADDRESS + 0x0C)
#define BOOT_CP0_EPC	   (BOOT_BASE_ADDRESS + 0x10)
#define BOOT_CP0_EEPC	   (BOOT_BASE_ADDRESS + 0x14)
#define BOOT_SIZE          (BOOT_BASE_ADDRESS + 0x18)   /* for CPU1 */
#define BOOT_RCU_SR        (BOOT_BASE_ADDRESS + 0x18)   /* for CPU0 */
#define BOOT_CFG_STAT	   (BOOT_BASE_ADDRESS + 0x1C)
#else
#define BOOT_RVEC(cpu)		 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x00)
#define BOOT_NVEC(cpu)		 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x04)
#define BOOT_EVEC(cpu)		 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x08)
#define BOOT_CP0_STATUS(cpu) (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x0C)
#define BOOT_CP0_EPC(cpu)	 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x10)
#define BOOT_CP0_EEPC(cpu)	 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x14)
#define BOOT_SIZE(cpu)       (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x18)	/* for CPU1 */
#define BOOT_RCU_SR(cpu)     (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x18)	/* for CPU0 */
#define BOOT_CFG_STAT(cpu)	 (volatile u32*)(BOOT_BASE_ADDRESS + (cpu * BOOT_CPU_OFFSET) + 0x1C)
#endif

#define SWITCH_TX_DESC		(volatile u32*)(BOOT_BASE_ADDRESS + (2 * BOOT_CPU_OFFSET))

#define BOOT_CFG_TEST   	0x00
#define BOOT_CFG_NOR   		0x01
//reserved			0x02
#define BOOT_CFG_PCI  		0x03
#define BOOT_CFG_ASC   		0x04
#define BOOT_CFG_SFLASH		0x05
#define BOOT_CFG_NAND  		0x06
//reserved			0x07
#define BOOT_CFG_RGMII 		0x08
#define BOOT_CFG_MII   		0x09
#define BOOT_CFG_REVMII  	0x0A
#define BOOT_CFG_RINMII   	0x0B
//reserved			0x0C
//reserved  		    	0x0D
#define BOOT_CFG_REVTMII	0x0E
#define BOOT_CFG_ROUTMII   	0x0F

#define BOOT_NUM_RETRY  3

#define BOOT_STAT_MASK_ALL     0x0000FFFF
#define BOOT_STAT_MASK_STAT    0x0000F000
#define BOOT_STAT_MASK_BERR    0x00000F00
#define BOOT_STAT_MASK_BSTRAP  0x000000F0
#define BOOT_STAT_MASK_BMODULE 0x0000000F

#define BOOT_STAT_INIT         0x00000000
#define BOOT_STAT_BSTRAP       0x00001000
#define BOOT_STAT_RETRY        0x00002000
#define BOOT_STAT_START        0x00003000
#define BOOT_STAT_HALT         0x0000F000

#define BOOT_ERR_NO_RVEC       0x00000100
#define BOOT_ERR_NO_NVEC       0x00000200
#define BOOT_ERR_NO_EVEC       0x00000300
#define BOOT_ERR_BSTRAP        0x00000400
#define BOOT_ERR_EXC           0x00000800

#ifndef __ASSEMBLY__

void mips_dcache_flush(u32 lock_size, u32 cache_line_size,  u32 start_address);
void mips_allcache_invalidate(u32 size, u32 cache_line_size, u32 start_address, u32 cache);

void change_k0_cca(void);
void boot_cp0(u32 cpu_num, u32 core_num, u32 vpe_num, u32 core_id);
void boot_main(u32 cpu_num, u32 core_num, u32 vpe_num, u32 core_id);
void boot_others(u32 cpu_num, u32 core_num, u32 vpe_num, u32 core_id);
void boot_bootrom_config(void);
void boot_set_status( u32 status, u32 mask);
void boot_set_config( u32 config);
void boot_set_rvec( u32 vector);
void boot_set_size( u32 size);
void boot_sdbg( u8* string, u32 value);
void boot_error( u32 berr);
int boot_from_ebu(void);
void _boot_rvec(void);
typedef struct
{
	u32   cpu;              /** CPU number */
	u32   config;           /** Boot configuration */
	u32   endian;           /** CPU endianess */
	u32   debug;            /** Debug mode */
	u32	(*exit)(void);	    /** application vector */
} boot_data;

extern boot_data bootrom;
#endif


#define LEAF(name)\
    .##text;\
    .##globl    name;\
    .##ent  name;\
name:

#define END(name)\
    .##size name,.-name;\
    .##end  name

//For GRX500
#define GCR_CONFIG_ADDR     0xb2300000  // KSEG0 address of the GCR registers
#define GIC_P_BASE_ADDR		0x12320000  // physical address of the GIC
#define GIC_BASE_ADDR		0xb2320000  // KSEG0 address address of the GIC
#define CPC_P_BASE_ADDR 	0x12310001  // physical address of the CPC
#define CPC_BASE_ADDR		0xb2310000  // KSEG0 address address of the CPC

#define CUS_P_BASE_ADDR 	0x123f0001  // physical address of the CUS
#define CUS_BASE_ADDR		0xb23f0000  // KSEG0 address address of the CUS

#define CDMM_P_BASE_ADDR 	0x123e0001  // physical address of the CDMM
#define CDMM_BASE_ADDR		0xb23e0000  // KSEG0 address address of the CDMM

/**************************************************************************************
 Register use while executing in this file: ("GLOBAL" denotes a common value.)
**************************************************************************************/

#define r1_all_ones     $1   /* at Will hold 0xffffffff to simplify bit insertion of 1's. GLOBAL! */

// $2 - $7 (v0, v1 a0 - a3) reserved for program use

#define r8_core_num    $8  /* t0 Core number. Only core 0 is active after reset. */
#define r9_vpe_num     $9  /* t1 MT ASE VPE number that this TC is bound to (0 if non-MT.) */
#define r10_has_mt_ase  $10   /* t2 Core implements the MT ASE. */
#define r11_is_cps      $11   /* t3 Core is part of a Coherent Processing System. */

// $12 - $15 (t4 - t7) are free to use
// $16, $17 (s0 and s1) reserved for program use

#define r18_tc_num      $18  /* s2 MT ASE TC number (0 if non-MT.) */
#define r19_more_cores  $19  /* s3 Number of cores in CPS in addition to core 0. GLOBAL! */
#define r20_more_vpes   $20  /* s4 Number of vpes in this core in addition to vpe 0. */
#define r21_more_tcs    $21  /* s5 Number of tcs in vpe in addition to the first. */
#define r22_gcr_addr    $22  /* s6 Uncached (kseg1) base address of the Global Config Registers. */
#define r23_cpu_num     $23  /* s7 Unique per vpe "cpu" identifier (CP0 EBase[CPUNUM]). */
#define r24_malta_word  $24  /* t8 Uncached (kseg1) base address of Malta ascii display. GLOBAL! */
#define r25_coreid      $25  /* t9 Copy of cp0 PRiD GLOBAL! */
#define r26_int_addr    $26  /* k0 Interrupt handler scratch address. */
#define r27_int_data    $27  /* k1 Interrupt handler scratch data. */
// $28 gp and $29 sp
#define r30_cpc_addr    $30  /* s8 Address of CPC register block after cpc_init. 0 indicates no CPC. */
// $31 ra



#endif /* #ifdef _BOOT_H */
