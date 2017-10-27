#include <common.h>

void test_mem()
{
   u8* p=NULL;
   u8* q=NULL;
   printf("test memory now!\n");
   p=(u8*)malloc(1);
   printf("p=%08x\n",(u32)p);
   q=(u8*)malloc(1638);
   printf("q=%08x\n",(u32)q);

   free(p); 
   free(q); 
   return;
}
