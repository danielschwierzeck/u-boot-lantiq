#include <common.h>

#include <openssl/bn.h>
#include <openssl/dsa.h>
#include <openssl/ecdsa.h>
#include "bn_val.h" 
#define CONFIG_DSA
void printBN(BIGNUM* a)
{
       int i;
       for(i=0;i<a->top;i++)
       {
          printf("%08x",a->d[a->top-i-1]);
       }
/*
       printf("\ntop=%d\n",a->top);
       printf("dmax=%d\n",a->dmax);
       printf("neg=%d\n",a->neg);
       printf("flags=%d\n",a->flags);
*/  
       return;
}

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
  printf("import_bn error!\n");
  return;

}



printDSA(DSA* dsa)
{
      BIGNUM* p=NULL;

      p=dsa->p;
      printf("p=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      p=dsa->q;
      printf("q=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      p=dsa->g;
      printf("g=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      p=dsa->pub_key;
      printf("pub_key=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");


      p=dsa->priv_key;
      printf("priv_key=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      p=dsa->kinv;
      printf("kinv=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      p=dsa->r;
      printf("r=");
      if(p) printBN(p);
      else printf("NULL");
      printf("\n");

      printf("flags=%d\n",dsa->flags);

      if(dsa->meth) printf("meth allocated!\n");
}

#ifdef CONFIG_DSA
void test_dsa()
{
   DSA *dsa=NULL;
   int counter,ret=0,i,j;
   unsigned char buf[256];
   unsigned long h;
   unsigned char sig[256];
   unsigned int siglen;
   BIGNUM p,q,g,pub_key,priv_key;   
   

   dsa = DSA_new();
   if(!dsa) goto ERROR;
   
   BN_init(&p);
   BN_init(&q);
   BN_init(&g);
   BN_init(&pub_key);
   BN_init(&priv_key); 
   
   import_bn(&p,bn_p,sizeof(bn_p));   
   import_bn(&q,bn_q,sizeof(bn_q));
   import_bn(&g,bn_g,sizeof(bn_g));
   import_bn(&pub_key,bn_pubkey,sizeof(bn_pubkey));
   //import_bn(&priv_key,bn5,sizeof(bn5));   
   dsa->p=&p;
   dsa->q=&q;
   dsa->g=&g;
   dsa->pub_key=&pub_key;
   dsa->priv_key=&priv_key;

   printDSA(dsa);


   dsa->flags |= DSA_FLAG_NO_EXP_CONSTTIME;
  
   if (DSA_verify(0, bn_dss1, sizeof(bn_dss1), NULL, 0, dsa) == 1){
        printf("verify OK!\n");        
        ret=1;
           }
    
   BN_free(&p);
   BN_free(&q);
   BN_free(&g);
   BN_free(&pub_key);
   BN_free(&priv_key);


   DSA_free(dsa);
   
   CRYPTO_cleanup_all_ex_data();
   return;
ERROR:
   printf("test_dsa error!\n");
   return;

}
#endif

#ifdef CONFIG_ECDSA
void test_ecdsa()
{
        EC_builtin_curve *curves = NULL;
        size_t          crv_len = 0, n = 0;
        EC_KEY          *eckey = NULL, *wrong_eckey = NULL;
        EC_GROUP        *group;
        ECDSA_SIG       *ecdsa_sig = NULL;
        unsigned char   digest[20], wrong_digest[20];
        unsigned char   *signature = NULL;
        const unsigned char     *sig_ptr;
        unsigned char   *sig_ptr2;
        unsigned char   *raw_buf = NULL;
        unsigned int    sig_len, degree, r_len, s_len, bn_len, buf_len;
        int             nid, ret =  0;
         
        /* get a list of all internal curves */
        crv_len = EC_get_builtin_curves(NULL, 0);

        curves = OPENSSL_malloc(sizeof(EC_builtin_curve) * crv_len);

        if (!EC_get_builtin_curves(curves, crv_len))
                {
                goto ERROR;
                }

        /* create new ecdsa key (== EC_KEY) */
        if ((eckey = EC_KEY_new()) == NULL)
        goto ERROR;

        nid = curves[0].nid;
        group = EC_GROUP_new_by_curve_name(nid);
        if (group == NULL)
                        goto ERROR;

         /*
        if (EC_KEY_set_group(eckey, group) == 0)
        goto ERROR;
        EC_GROUP_free(group);

        if (!EC_KEY_generate_key(eckey)) goto ERROR;
        */

    return;

ERROR:
   printf("error!\n");

   return;
}
#endif

void test_bn(void)
{
   BN_CTX *ctx;
   printf("testing big number!\n");
   ctx=BN_CTX_new();
   if (ctx == NULL) goto ERROR;

   //test_add();
   
   //test_mul();

   test_dsa();

   //test_ecdsa();


   //BN_CTX_free(ctx);

   return;

ERROR:
   printf("error!\n");
   return;

}
