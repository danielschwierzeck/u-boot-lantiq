/*
 * Copyright (C) 2012 Wu Qi Ming  wqiming@gmail.com
 *
 */

#include <common.h>
#include <openssl/bn.h>
#include <openssl/dsa.h>
//#include "autoconf.h"
#include "bn_val.h"

#define HEADER_MAGIC 0x65976743

typedef struct
{
    u32 header_magic;    /*header magic number*/
	u32 len;             /*image length, exclusive of the header*/
	u32 dst_addr;        /*image destination address*/
	u32 jump_addr;       /*image start address*/
	u8  sha1[20];        /*20 byte sha1 value*/
	u8  r[20];           /*signature r value*/
	u8  s[20];           /*signature s value*/
    u32 chsum;           /*header checksum*/
} secure_header_t;



void import_bn(BIGNUM* a, unsigned char* bn, int len)
{
   int i,j;
   int word_len;
   int remainder;
   int cur;
   word_len=(len+3)>>2;
   remainder=len%(sizeof(BN_ULONG));
   a->d=(BN_ULONG*)malloc(word_len*sizeof(BN_ULONG));
   if(!a->d) goto ERROR;
   a->top=word_len;
   a->dmax=word_len;
   memset(a->d,0,word_len*sizeof(BN_ULONG));
   for(i=0;i<word_len;i++){
    *(a->d+word_len-1-i)=*((u32*)bn+i);
   }
   return;
ERROR:
   return;
}




int dsa_verify()
{
   DSA *dsa=NULL;
   DSA_SIG *s;
   BIGNUM p,q,g,pub_key;
   int ret=-1;
   secure_header_t* shdr=(secure_header_t*)(CONFIG_STAGE2_LOADADDR+CONFIG_STAGE2_SIZE); 

   dsa = DSA_new();
   if(!dsa) goto ERROR;


   s = DSA_SIG_new();
   if (!s) goto ERROR;


   BN_init(&p);
   BN_init(&q);
   BN_init(&g);
   BN_init(&pub_key);
   //BN_init(&priv_key);

   import_bn(&p,bn_p,sizeof(bn_p));
   import_bn(&q,bn_q,sizeof(bn_q));
   import_bn(&g,bn_g,sizeof(bn_g));
   import_bn(&pub_key,bn_pubkey,sizeof(bn_pubkey));
   //import_bn(&priv_key,bn5,sizeof(bn5));
   dsa->p=&p;
   dsa->q=&q;
   dsa->g=&g;
   dsa->pub_key=&pub_key;

   s->r=malloc(sizeof(BIGNUM*));
   s->s=malloc(sizeof(BIGNUM*));
   BN_init(s->r);
   BN_init(s->s);
   import_bn(s->r,shdr->r,20);
   import_bn(s->s,shdr->s,20);
   dsa->flags |= DSA_FLAG_NO_EXP_CONSTTIME;
   ret=DSA_do_verify(shdr->sha1,20,s,dsa);
   BN_free(&p);
   BN_free(&q);
   BN_free(&g);
   BN_free(&pub_key);
   //BN_free(&priv_key);
   BN_free(s->r);
   BN_free(s->s);
   DSA_SIG_free(s);

   DSA_free(dsa);

   CRYPTO_cleanup_all_ex_data();
   return ret;


ERROR:
   return ret;

}


void decrypt_image(void)
{
   int i;
   u32 checksum=0;
   void (*jump)(void);
   secure_header_t* shdr=(secure_header_t*)(CONFIG_STAGE2_LOADADDR+CONFIG_STAGE2_SIZE);
   unsigned char sha1[20];
   unsigned char iv[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};   
   /*need to turn on DEU*/
#ifdef CONFIG_DRIVER_AR10   
   *AR10_PMU_CLKGCR1_A |=BSP_PMU_DEU;
#endif

#ifdef CONFIG_DRIVER_VR9
   *BSP_PMU_PWDCR &=~(BSP_PMU_DEU);
#endif

   if((shdr->header_magic ^ HEADER_MAGIC) & 0xfffffffe){
	 goto ERROR;
   }

   /*verify header checksum*/
   for(i=0;i<19;i++){
     checksum+=*((u32*)shdr+i);
   }

   if(checksum!=shdr->chsum){
	 goto ERROR;
   }

   /*clear destination memory*/
   memset(shdr->dst_addr,0,shdr->len);

   if(shdr->header_magic & 0x1){
     /*not encrypted, plain text*/
     memcpy((u8*)shdr->dst_addr,(u8*)((u8*)shdr+sizeof(secure_header_t)),shdr->len);
   }else{
     /*encrypted, need to decrypt*/
     secure_decrypt(aes_key, iv, (u8*)((u8*)shdr+sizeof(secure_header_t)),\
	               (u8*)(shdr->dst_addr), shdr->len);
   }


   /*verify hashing result*/
   sha1_hash((u8*)(shdr->dst_addr), shdr->len, &sha1);

   for(i=0;i<20;i++){
      if(sha1[i]!=shdr->sha1[i]) {
		 goto ERROR;
	   }
   }

   /*verify DSA signature*/
   if(dsa_verify()!=1){
	 goto ERROR;
   }
   /*all seems to be OK, jump to the program and execute*/
   jump = (void (*)(void))(shdr->jump_addr);
   (*jump)();

   return;

ERROR:
   return;
}

int main()
{
  decrypt_image();
}
