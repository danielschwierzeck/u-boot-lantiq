#include <vr9.h>
#include <common.h>

/*
 * Make sure all entries differ.  If they're not different
 * MIPS32 will take revenge ...
 */
#define PAGE_SHIFT      12
//#define UNIQUE_ENTRYHI(idx) (KSEG0 + ((idx) << (PAGE_SHIFT + 1)))
#define UNIQUE_ENTRYHI(idx) ((idx) << (PAGE_SHIFT + 1))
#define FLUSH_ITLB write_c0_diag(4);

static unsigned int tlbsize;

static void dump_tlb_all()
{
     unsigned long flags;
     unsigned long old_ctx;
	 unsigned int pagemask, entrylo0, entrylo1, entryhi;
     
     int i;

     /* Save old context and create impossible VPN2 value */
     old_ctx = read_c0_entryhi();
     for(i=0;i<tlbsize;i++){
        write_c0_index(i);
        tlb_read();
		asm("ehb");
        pagemask = read_c0_pagemask();
		entryhi  = read_c0_entryhi();
		entrylo0 = read_c0_entrylo0();
		entrylo1 = read_c0_entrylo1();
        printf("index=%d ",i);
		printf("pagemask=0x%08x ",pagemask);
		printf("entryhi=0x%08x ",entryhi);
		printf("entrylo0=0x%08x ",entrylo0);
		printf("entrylo1=0x%08x\n ",entrylo1);
		
	 }
    
	 asm("ehb");
	 write_c0_entryhi(old_ctx);
}

void local_flush_tlb_all(void)
{
        unsigned long flags;
        unsigned long old_ctx;
        int entry;

       /* Save old context and create impossible VPN2 value */
        old_ctx = read_c0_entryhi();
        write_c0_entrylo0(0);
        write_c0_entrylo1(0);
        entry = read_c0_wired();

        /* Blast 'em all away. */
        while (entry < tlbsize) {
               /* Make sure all entries differ. */
               write_c0_entryhi(UNIQUE_ENTRYHI(entry));
               write_c0_index(entry);
               asm("ehb");
               tlb_write_indexed();
               entry++;
																																									        }
        asm("ehb");
		write_c0_entryhi(old_ctx);
																																								        FLUSH_ITLB;
}

int probe_tlb(u32 vaddr)
{
    int result = 0;
    unsigned long old_ctx;
	unsigned long entryhi, index;
	old_ctx = read_c0_entryhi();
    entryhi = (vaddr & 0xfffff000);
    write_c0_entryhi(entryhi);
	tlb_probe();
    index = read_c0_index();
	printf("index=%d\n",index);
	asm("ehb");
	write_c0_entryhi(old_ctx);
    
	return 1;
}


void add_tlb_entry(u32 vaddr, u32 paddr0, u32 paddr1)
{
  unsigned long old_ctx;
  unsigned long wired;
  unsigned long pagemask, entrylo0, entrylo1, entryhi,entry;
  
  entryhi  = (vaddr & 0xfffff000);
  entrylo0 = (paddr0 & 0xfffff000)>>6|(2<<3)|(1<<2)|(1<<1)|1;
  entrylo1 = (paddr1 & 0xfffff000)>>6|(2<<3)|(1<<2)|(1<<1)|1;

  printf("%08x,%08x,%08x\n",entryhi,entrylo0,entrylo1);
  old_ctx = read_c0_entryhi();
  write_c0_entrylo0(entrylo0);
  write_c0_entrylo1(entrylo1);
  //entry = read_c0_wired();
  //printf("entry=%d\n",entry);
  write_c0_entryhi(entryhi);
  //write_c0_index(entry);
  tlb_write_random();
  asm("ehb");
  //tlb_write_indexed();
  asm("ehb");
  write_c0_entryhi(old_ctx);

}

void tlb_init(void)
{
   unsigned int reg;
   reg = read_c0_config1();

   tlbsize = ((reg >> 25) & 0x3f) + 1;
   
   printf("tlb size = %d\n", tlbsize);
   
   write_c0_pagemask(PM_DEFAULT_MASK);
   write_c0_wired(0);

   local_flush_tlb_all();

   return;
}


void test_tlb(void)
{
     u32 value;
     //init_icache();
	 //init_dcache();
	 tlb_init();
     //dump_tlb_all(); 

     add_tlb_entry(0x0,0x0,0x00001000);
   
     add_tlb_entry(0x10000000,0x50000000,0x50001000);
     //add_tlb_entry(0x00002000,0x00002000,0x00003000);
	 
	 dump_tlb_all();
     asm("sync");
     //invalidate_dcache_range(0x50000000, 0x50001fff);
	 asm("sync");
	 value = *(volatile u32*)0x10000000;
	 asm("sync");
	 printf("value=%08x\n",value);

     return;

}

