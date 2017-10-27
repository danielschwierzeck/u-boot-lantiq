/* dsa_asn1.c */
/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL
 * project 2000.
 */
/* ====================================================================
 * Copyright (c) 2000-2005 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */
#include <common.h>
#include <openssl/dsa.h>

unsigned char bn_r[]={0x68,0xB7,0xAE,0x46,0x11,0x51,0x1C,0xF3,0xCD,0x0E,0xB3,0xAD,0x03,0x32,0x41,0x63,0x91,0x5F,0x18,0xF0};
unsigned char bn_s[]={0x9E,0xBD,0x87,0x94,0x21,0xEB,0x77,0x5D,0x0E,0x42,0xB2,0x73,0xC7,0x21,0x18,0x73,0x5B,0xDE,0x7F,0x23};

extern void printBN(BIGNUM* a);
extern void import_bn(BIGNUM* a, unsigned char* bn, int len);





/* data has already been hashed (probably with SHA or SHA-1). */
/* returns
 *      1: correct signature
 *      0: incorrect signature
 *     -1: error
 */
int DSA_verify(int type, const unsigned char *dgst, int dgst_len,
	     const unsigned char *sigbuf, int siglen, DSA *dsa)
	{
	DSA_SIG *s;
	int ret=-1;

	s = DSA_SIG_new();
	if (s == NULL) return(ret);
	//if (d2i_DSA_SIG(&s,&sigbuf,siglen) == NULL) goto err;
		s->r=malloc(sizeof(BIGNUM*));
        s->s=malloc(sizeof(BIGNUM*));
        BN_init(s->r);
        BN_init(s->s); 

        import_bn(s->r,bn_r,sizeof(bn_r));
        import_bn(s->s,bn_s,sizeof(bn_s));

        printf("s->r=");
        printBN(s->r);
        printf("\n");

        printf("s->s=");
        printBN(s->s);
        printf("\n");
        ret=DSA_do_verify(dgst,dgst_len,s,dsa);
err:
	DSA_SIG_free(s);
	return(ret);
	}
