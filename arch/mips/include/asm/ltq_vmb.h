#ifndef _LTQ_VMB_H
#define _LTQ_VMB_H

#define MAX_CORE 2 
#define MAX_VPE 2 
#define MAX_TC	6
#define MAX_TCS	4
#define MAX_CPU (MAX_CORE * MAX_VPE)

#define vmb_msg_size (sizeof(VMB_fw_msg_t) + sizeof(FW_vmb_msg_t))
#define CPU_LAUNCH 0xa0000000
#define IBL_LOADADDR 0xa0010000
#define GIC_SH_WEDGE_REG  *((volatile unsigned int*) (0xb2320280))

/* REVERT BACK TO 10 */
#define QUEUE_TIMEOUT (100 * HZ) 

#define get_cpu_id(core, vpe)   ((core * 2) + vpe)
#define which_core(cpu)         (cpu / 2)
#define vpe_in_core(cpu)        (cpu % 2)


#define VMB_CPU_START	0x00000001
#define VMB_CPU_STOP	0x00000002
#define VMB_TC_START	0x00000004
#define VMB_TC_STOP	0x00000008
#define VMB_TC_PAUSE	0x00000010
#define VMB_TC_RESUME	0x00000020

#define FW_VMB_ACK	0x00000001
#define FW_VMB_NACK	0x00000002
#define FW_RESET	0x00000004
#define IBL_IN_WAIT	0x00000008
#define FW_VMB_PRIV_INFO	0x00000010

typedef struct cpu_launch_t {
	uint	start_addr;
	uint	sp;
	uint	gp;
	uint	a0;
	uint	eva;
	uint	mt_group;
	uint	yield_res;
	uint	priv_info;
}CPU_launch_t; 

typedef struct tc_launch_t {
	uint	tc_num;
	uint	mt_group;
	uint	start_addr;
	uint	sp;
	uint	gp;
	uint	a0;
	uint	state;
	uint	priv_info;	
}TC_launch_t;

typedef struct vmb_fw_msg_t{
	uint	msg_id;
	CPU_launch_t	cpu_launch;
	TC_launch_t	tc_launch[MAX_TCS];
	uint	tc_num;
} VMB_fw_msg_t;

typedef struct fw_vmb_msg_t{
	uint	status;
	uint	priv_info;
} FW_vmb_msg_t;

#define read_c0_count()         __read_32bit_c0_register($9, 0)
#define write_c0_count(val)     __write_32bit_c0_register($9, 0, val)

#define read_c0_config()        __read_32bit_c0_register($16, 0)

#define read_c0_ebase()         __read_32bit_c0_register($15, 1)

#define read_c0_status()        __read_32bit_c0_register($12, 0)
#define read_c0_config7()       __read_32bit_c0_register($16, 7)
#define write_c0_config7(val)   __write_32bit_c0_register($16, 7, val)
#define write_c0_sp(val)   __write_32bit_c0_register($29, 0, val)
#define write_c0_gp(val)   __write_32bit_c0_register($28, 0, val)


void r4k_wait_irqoff(void)
{
                __asm__ __volatile__(
                "       .set    push            \n"   \
                "       .set    noreorder       \n"   \
                "       .set    mips3\n\t       \n"   \
                "       wait                    \n"   \
                "       .set    pop             \n");
}

/* IRQ Numbers and handler definations */
#define  VMB_CPU_IPI1           20
#define  VMB_CPU_IPI2           21
#define  VMB_CPU_IPI3           85

/* FW/IBL -> VMB IPI numbers */
#define FW_VMB_IPI1             87
#define FW_VMB_IPI2             88
#define FW_VMB_IPI3             110

void gic_send_ipi(unsigned int intr)
{
	(GIC_SH_WEDGE_REG) = (0x80000000 | intr);
}

void gic_clear_ipi(unsigned int intr)
{
	(GIC_SH_WEDGE_REG) = (0x00000000 | intr);
}

#endif
