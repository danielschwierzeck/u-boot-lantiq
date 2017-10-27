#include <common.h>
#include "aes_key.h"

void test_deu(void)
{

    /*need to power up DEU first*/
#ifdef CONFIG_PLATFORM_AR10   
   *AR10_PMU_PWDCR1 |=BSP_PMU_DEU; 
#endif
   
   secure_decrypt(aes_key, iv, (u8*)0x80500000, (u8*)0x80600000, 1024);
   


   //sha1_hash((u8*)0x80500000, 1024, (u8*)0x80600000); 
   return;
}
