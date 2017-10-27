#include <common.h>


#define DECRYPT   0
#define ENCRYPT   1
#define KEY_SIZE        32

/*fixme: DEU register definition, hard coded here*/
#define AES_START   0xBE103150
#ifdef CONFIG_DRIVER_AR10
#define PMU_CLKGCR1_A  (volatile u32*)0xBF102024
#elif defined(CONFIG_DRIVER_VR9)
#define PMU_PWDCR (volatile u32*)0xBF10201C
#endif

#define PMU_DEU     1<<20


#define AES_MIN_KEY_SIZE    16
#define AES_MAX_KEY_SIZE    32

#define AES_BLOCK_SIZE      16

struct aes_t {
    struct aes_controlr {

        u32 KRE:1;
        u32 reserved1:4;
        u32 PNK:1;
        u32 GO:1;
        u32 STP:1;

        u32 reserved2:6;
        u32 NDC:1;
        u32 ENDI:1;
        u32 reserved3:2;

        u32 F:3;    //fbs
        u32 O:3;    //om
        u32 BUS:1;  //bsy
        u32 DAU:1;
        u32 ARS:1;
        u32 SM:1;
        u32 E_D:1;
        u32 KV:1;
        u32 K:2;    //KL

    } controlr;
    u32 ID3R;       //80h
    u32 ID2R;       //84h
    u32 ID1R;       //88h
    u32 ID0R;       //8Ch
    u32 K7R;        //90h
    u32 K6R;        //94h
    u32 K5R;        //98h
    u32 K4R;        //9Ch
    u32 K3R;        //A0h
    u32 K2R;        //A4h
    u32 K1R;        //A8h
    u32 K0R;        //ACh
    u32 IV3R;       //B0h
    u32 IV2R;       //B4h
    u32 IV1R;       //B8h
    u32 IV0R;       //BCh
    u32 OD3R;       //D4h
    u32 OD2R;       //D8h
    u32 OD1R;       //DCh
    u32 OD0R;       //E0h
};



void aes_set_key (const u8 *in_key, u32 key_len)
{
    volatile struct aes_t *aes = (volatile struct aes_t *) AES_START;

    /* 128, 192 or 256 bit key length */
    aes->controlr.K = key_len / 8 - 2;

     aes->K7R = *((u32 *) in_key + 0);
     aes->K6R = *((u32 *) in_key + 1);
     aes->K5R = *((u32 *) in_key + 2);
     aes->K4R = *((u32 *) in_key + 3);
     aes->K3R = *((u32 *) in_key + 4);
     aes->K2R = *((u32 *) in_key + 5);
     aes->K1R = *((u32 *) in_key + 6);
     aes->K0R = *((u32 *) in_key + 7);

     aes->controlr.PNK = 1;
}


static void deu_aes (u8 *out_arg, const u8 *in_arg,
        u8 *iv_arg, u32 nbytes, int encdec, int mode)
{
    volatile struct aes_t *aes = (volatile struct aes_t *) AES_START;
        int i = 0;
    int byte_cnt = nbytes;

    aes->controlr.E_D = !encdec;    //encryption
    aes->controlr.O = mode; //0 ECB 1 CBC 2 OFB 3 CFB 4 CTR

    if (mode > 0) {
        aes->IV3R = *(u32 *) iv_arg;
        aes->IV2R = *((u32 *) iv_arg + 1);
        aes->IV1R = *((u32 *) iv_arg + 2);
        aes->IV0R = *((u32 *) iv_arg + 3);
    };

    i = 0;
    while (byte_cnt >= 16) {
        aes->ID3R = *((u32 *) in_arg + (i * 4) + 0);
        aes->ID2R = *((u32 *) in_arg + (i * 4) + 1);
        aes->ID1R = *((u32 *) in_arg + (i * 4) + 2);
        aes->ID0R = *((u32 *) in_arg + (i * 4) + 3);    /* start crypto */
        while (aes->controlr.BUS) {
            // this will not take long
        }

        *((volatile u32 *) out_arg + (i * 4) + 0) = aes->OD3R;
        *((volatile u32 *) out_arg + (i * 4) + 1) = aes->OD2R;
        *((volatile u32 *) out_arg + (i * 4) + 2) = aes->OD1R;
        *((volatile u32 *) out_arg + (i * 4) + 3) = aes->OD0R;

        i++;
        byte_cnt -= 16;
    }

}



void deu_aes_cbc (u8 *dst, const u8 *src,
        u8 *iv, u32 nbytes, int encdec)
{
    deu_aes (dst, src, iv, nbytes, encdec, 1);
}

void aes_chip_init(void)
{
    volatile struct aes_t *aes = (struct aes_t *) AES_START;

#ifdef CONFIG_DRIVER_AR10
    /*turn on DEU, hard coded for AR10 here*/
	*PMU_CLKGCR1_A |=PMU_DEU;
#endif

#ifdef CONFIG_DRIVER_VR9
    *PMU_PWDCR &=~(PMU_DEU);
#endif

    // start crypto engine with write to ILR

    aes->controlr.ENDI = 1; // vr9 change
    aes->controlr.SM = 1;
    aes->controlr.ARS = 0; // vr9 change

}


void secure_decrypt(u8 *key, u8 *iv, u8 *src, u8 *dst, u32 nbytes)
{
    aes_chip_init();

    aes_set_key(key, KEY_SIZE);

    deu_aes_cbc(dst, src, iv, nbytes, DECRYPT);
}

