#include <common.h>
#include <asm/boot.h>
#include <config.h>
#include <asm/mt.h> 
#include <asm/mipsregs.h>
#include <asm/mipsmtregs.h>
#include <asm/cps.h>
#include <asm/ltq_vmb.h>


#define asc_puts serial_puts
#define asc_putc serial_putc

#ifdef CONFIG_BOOT_FROM_NAND
#define CONFIG_TEXT_BASE_ADDR	CONFIG_NAND_SPL_TEXT_BASE
#elif CONFIG_BOOT_FROM_SPI
#define CONFIG_TEXT_BASE_ADDR	CONFIG_SFDDR_TEXT_BASE
#endif

void print_u8(u8 data)
{
   char string[3]={0,0,0};
   char ascii[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

   string[0]=ascii[(data&0xf0)>>4];
   string[1]=ascii[data&0xf];

   asc_puts(string);
}

void print_u32(u32 data)
{
   print_u8( (u8) (data>>24)&0xff);
   print_u8( (u8) (data>>16)&0xff);
   print_u8( (u8) (data>>8)&0xff);
   print_u8( (u8) (data>>0)&0xff);
}

void set_tc_policy(int tc_num, int group)
{
    write_c0_mvpcontrol((read_c0_mvpcontrol() & ~MVPCONTROL_EVP) | MVPCONTROL_VPC);
    settc(tc_num);
    write_tc_c0_tcschedule(read_tc_c0_tcschedule()| (group & 0x3));
    write_c0_mvpcontrol((read_c0_mvpcontrol() & ~MVPCONTROL_VPC) | MVPCONTROL_EVP);
    return;
}

static u32 tc_getinfo(int8_t cpu, TC_launch_t tc_launch[]) {
	u32 tcmask = 0 , i = 0;

	tcmask = tcmask | (0x1 << (cpu % 2));

	for (i=0; i < MAX_TCS; i++) {
		if ((tc_launch[i].tc_num > 0) && (tc_launch[i].tc_num < MAX_TC)){
			tcmask = tcmask | (0x1 << tc_launch[i].tc_num);
                        set_tc_policy(tc_launch[i].tc_num, tc_launch[i].mt_group);
                }
	}

	return(tcmask);
}

static u32 Rx_Tx_IPI(int8_t cpu) {
	switch(cpu) {
		case 1:
			return ((VMB_CPU_IPI1 << 16) | FW_VMB_IPI1);
		case 2:
			return ((VMB_CPU_IPI2 << 16) | FW_VMB_IPI2);
		case 3:
			return ((VMB_CPU_IPI3 << 16) | FW_VMB_IPI3);
		default:
			break;
	}
	return 0;
}

/*
   This function is needed to trigger GIC IPI Interrupt .
*/

static void gic_trigger(int8_t cpu) {
        switch(cpu) {
                case 1:
                        gic_send_ipi(FW_VMB_IPI1);
                        break;
                case 2:
                        gic_send_ipi(FW_VMB_IPI2);
                        break;
                case 3:
                        gic_send_ipi(FW_VMB_IPI3);
                        break;
                default:
                        break;
        }

        return;
}

static void gic_clear(int8_t cpu) {
	switch (cpu) {
	case 1:
		gic_clear_ipi(VMB_CPU_IPI1);
		break;
	case 2:
		gic_clear_ipi(VMB_CPU_IPI2);
		break;
	case 3:
		gic_clear_ipi(VMB_CPU_IPI3);
		break;
	default:
		break;	
	}
}

#if 1
/* API to get the memory in DDR for strutures VMB_fw_msg_t/FW_vmb_msg_t */
void *VMB_get_msg_addr (int cpu, int direction) {

        void *msg_t =  (void *)(CPU_LAUNCH);

        /* VMB --> FW : VMB_fw_msg_t structure */
        if (direction == 0)
                msg_t = msg_t + (vmb_msg_size * cpu) + sizeof(FW_vmb_msg_t);
        else
                msg_t = msg_t + (vmb_msg_size * cpu);

        return (msg_t);
}
#else
/* API to get the memory in DDR for strutures VMB_fw_msg_t/FW_vmb_msg_t */
void *VMB_get_msg_addr (int cpu, int direction) {

        void *msg_t =  (void *)(CPU_LAUNCH);

        /* VMB --> FW : VMB_fw_msg_t structure */
        if (direction == 0)
                msg_t = msg_t + (vmb_msg_size * cpu) ;
        else
                msg_t = msg_t + (vmb_msg_size * cpu) + sizeof(VMB_fw_msg_t);

        return (msg_t);
}
#endif

void vpe_launch(int cpu, int c_id, int vpe_id, CPU_launch_t cpu_launch, TC_launch_t tc_launch[])
{
	u32  vmbfw = 0, addr = 0, fwvmb = 0, RxTx = 0, tcinfo = 0;
	u32 ibl_loadaddr = CONFIG_TEXT_BASE_ADDR;

	vmbfw = ((unsigned long)(VMB_get_msg_addr(cpu, 0)) & 0xffff);
	tcinfo = tc_getinfo(cpu, tc_launch);


      __write_32bit_c0_register($11, 0, (__read_32bit_c0_register($9, 0) + 1000));
        asm volatile ("ehb");

	/* a2 */
	fwvmb = ((unsigned long)(VMB_get_msg_addr(cpu, 1)) & 0xffff);
	addr = (fwvmb << 16) | vmbfw;
	//asc_puts("\naddr "); print_u32(addr); 

       asm volatile ("lw $6, %0" : : "m" ((unsigned long)addr));
       asm volatile ("ehb");

	/* a3 */
	RxTx = Rx_Tx_IPI(cpu);
       asm volatile ("lw $7, %0" : : "m" ((unsigned long)RxTx));
       asm volatile ("ehb");
	//asc_puts("\nRxTx "); print_u32(RxTx);

	   /* s1 */
       tcinfo = ((tcinfo << 16) | (unsigned long)cpu_launch.yield_res); 
       asm volatile ("lw $17, %0" : : "m" (tcinfo));
       asm volatile ("ehb");
	  //asc_puts("\ntcinfo "); print_u32(tcinfo);

        /* a0 */
       asm volatile ("lw $4, %0" : : "m" ((unsigned long)cpu_launch.a0));
       asm volatile ("ehb");

        /* a1 */
       asm volatile ("lw $5, %0" : : "m" ((unsigned long)cpu_launch.priv_info));
       asm volatile ("ehb");

	/* s0 */
       asm volatile ("lw $16, %0" : : "m" ((unsigned long)ibl_loadaddr));
       asm volatile ("ehb");

       asm volatile ("lw $28, %0" : : "m" ((unsigned long)cpu_launch.gp));
       asm volatile ("ehb");

       asm volatile ("lw $t9, %0" : : "m" ((unsigned long)cpu_launch.start_addr));
       asm volatile ("ehb");

      asm volatile ("lw $29, %0" : : "m" ((unsigned long)cpu_launch.sp));
       asm volatile ("ehb");

       asm volatile ("ei");
       asm volatile ("ehb");

       asm volatile ("jr $t9");

}


/* Boot routine for Core 0/1, Vpe 0/1 */
void ibl(u32 cpu_num, u32 core_num, u32 vpe_num)
{
        u32 msk,pnd;
        int i;
       FW_vmb_msg_t *fw_vmb;

       //asc_puts("\nGRX500 cpu "); print_u8(cpu_num);asc_puts("\n");

       fw_vmb = (FW_vmb_msg_t *)VMB_get_msg_addr(cpu_num, 1);

       fw_vmb->status = (unsigned int)IBL_IN_WAIT;
       fw_vmb->priv_info = (unsigned int)0;

       /* TODO : Generate an IPI to Core0/VPE0 to update VMB as IBL_IN_WAIT */
		gic_trigger(cpu_num);

      //asc_puts("\nFW_VMB cpu "); print_u8((unsigned long)fw_vmb);

    
	asm volatile ("ei");  
        asm volatile ("ehb") ;
	REG32(CPUMSG) += 1;

       while (1) {

               r4k_wait_irqoff();

		VMB_fw_msg_t *vmb_t, l_vmb_t;
		int v_id, c_id;

		asc_puts("\nOutside WAIT got IPI interrupt to launch from cpu "); print_u8(cpu_num);
		asc_puts("\n");
		REG32(INTMSG + cpu_num*4) = 0;
		
		/* gets the DDR address of the structure to this CPU*/
		c_id = which_core(cpu_num);
		v_id = vpe_in_core(cpu_num);
		
		vmb_t = (VMB_fw_msg_t *)VMB_get_msg_addr(cpu_num, 0);
		memcpy(&l_vmb_t, vmb_t, sizeof(VMB_fw_msg_t));

		asc_puts("\n MSG_ID = "); print_u8(l_vmb_t.msg_id);
	
		/* Clear IPI Interupts */
		gic_clear(cpu_num);
	
		if (l_vmb_t.msg_id == VMB_CPU_START) {
			// memset(vmb_t, 0, sizeof(VMB_fw_msg_t)); // commented as per MPEFW
			vpe_launch(cpu_num, c_id, v_id, l_vmb_t.cpu_launch, l_vmb_t.tc_launch);
		}
       }
	return;
}






