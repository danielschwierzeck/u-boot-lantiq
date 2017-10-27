#include <common.h>

#define VECTORSPACING 0x200     /* for EI/VI mode */


unsigned long ebase;
extern char except_generic;

unsigned long exception_handlers[32];

extern void handle_tlbl(void);


/*
void handle_tlb(void)
{
   printf("tlb exception!\n");
   return;

}
*/

/* Install CPU exception handler */
void set_handler(unsigned long offset, void *addr, unsigned long size)
{
        memcpy((void *)(ebase + offset), addr, size);
		flush_dcache_range((ulong)(ebase + offset), (ulong)(ebase + offset+size - 1));
}



void *set_except_vector(int n, void *addr)
{
        unsigned long handler = (unsigned long) addr;
        unsigned long old_handler = exception_handlers[n];

        exception_handlers[n] = handler;
        /*
		if (n == 0 && cpu_has_divec) {
               *(u32 *)(ebase + 0x200) = 0x08000000 |
                                         (0x03ffffff & (handler >> 2));
               local_flush_icache_range(ebase + 0x200, ebase + 0x204);
          }
		*/  
        return (void *)old_handler;
}


void test_exception(void)
{
    u32 tmp;
	printf("exception test\n");
    ebase = 0x81090000;

    change_c0_status(ST0_CU0|ST0_MX|ST0_IM|ST0_IE|ST0_BEV|ST0_EXL,ST0_CU0|ST0_MX|ST0_EXL);

	write_c0_ebase(ebase);

	/* Setting vector spacing enables EI/VI mode  */
	change_c0_intctl(0x3e0, VECTORSPACING); /*512 byte spacing*/

    change_c0_config3(MIPS_CONF3_VEIC|MIPS_CONF3_VINT,MIPS_CONF3_VINT);

    set_c0_cause(CAUSEF_IV);

	set_handler(0x180,&except_generic,0x80);
    

	set_except_vector(2, handle_tlbl);

	asm("sync");
    tmp=*(u32*)0x50000000;
	asm("sync");
	printf("%d\n",tmp);
	return;

}

