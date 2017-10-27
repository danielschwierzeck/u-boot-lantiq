#include <common.h>


#define HASH_START	HASH_CON

#define SHA1_DIGEST_SIZE	20
#define SHA1_HMAC_BLOCK_SIZE	64

#define u64 unsigned long long

struct deu_hash_t {
    struct hash_controlr {
        u32 reserved1:5;
        u32 KHS:1;
        u32 GO:1;
        u32 INIT:1;
        u32 reserved2:6;
        u32 NDC:1;
        u32 ENDI:1;
        u32 reserved3:7;
        u32 DGRY:1;
        u32 BSY:1;
        u32 reserved4:1;
        u32 IRCL:1;
        u32 SM:1;
        u32 KYUE:1;
                u32 HMEN:1;
        u32 SSEN:1;
        u32 ALGO:1;

    } controlr;
    u32 MR;         //B4h
    u32 D1R;        //B8h
    u32 D2R;        //BCh
    u32 D3R;        //C0h
    u32 D4R;        //C4h
    u32 D5R;        //C8h

    u32 dummy;      //CCh

    u32 KIDX;       //D0h
    u32 KEY;        //D4h
    u32 DBN;        //D8h
};



struct sha1_ctx {
        u64 count;
        u32 state[5];
        u8 buffer[64];
} sha1_context;

static void sha1_transform (u32 *state, const u32 *in)
{
	int i = 0;
	volatile struct deu_hash_t *hashs = (struct deu_hash_t *) HASH_START;

	for (i = 0; i < 16; i++) {
		hashs->MR = in[i];
	};

	//wait for processing
	while (hashs->controlr.BSY) {
		// this will not take long
	}
}

static void sha1_init(struct sha1_ctx *sctx)
{
        volatile struct deu_hash_t *hash = (struct deu_hash_t *) HASH_START;
	
	hash->controlr.ENDI = 1; // vr9 change
	hash->controlr.SM = 1;
	hash->controlr.ALGO = 0;	// 1 = md5  0 = sha1
	hash->controlr.INIT = 1;	// Initialize the hash operation by writing a '1' to the INIT bit.

        sctx->count = 0;
}

static void sha1_update(struct sha1_ctx *sctx, const u8 *data, unsigned int len)
{
	unsigned int i, j;

	j = (sctx->count >> 3) & 0x3f;
	sctx->count += len << 3;

	if ((j + len) > 63) {
		memcpy (&sctx->buffer[j], data, (i = 64 - j));
		sha1_transform (sctx->state, (const u32 *)sctx->buffer);
		for (; i + 63 < len; i += 64) {
			sha1_transform (sctx->state, (const u32 *)&data[i]);
		}

		j = 0;
	}
	else
		i = 0;

	memcpy (&sctx->buffer[j], &data[i], len - i);
}

static void sha1_final(struct sha1_ctx *sctx, u8 *out)
{
	u32 index, padlen;
	u64 t;
	u8 bits[8] = { 0, };
	static const u8 padding[64] = { 0x80, };
	volatile struct deu_hash_t *hashs = (struct deu_hash_t *) HASH_START;

	t = sctx->count;
	bits[7] = 0xff & t;
	t >>= 8;
	bits[6] = 0xff & t;
	t >>= 8;
	bits[5] = 0xff & t;
	t >>= 8;
	bits[4] = 0xff & t;
	t >>= 8;
	bits[3] = 0xff & t;
	t >>= 8;
	bits[2] = 0xff & t;
	t >>= 8;
	bits[1] = 0xff & t;
	t >>= 8;
	bits[0] = 0xff & t;

	/* Pad out to 56 mod 64 */
	index = (sctx->count >> 3) & 0x3f;
	padlen = (index < 56) ? (56 - index) : ((64 + 56) - index);
	sha1_update (sctx, padding, padlen);

	/* Append length */
	sha1_update (sctx, bits, sizeof bits);

	*((u32 *) out + 0) = hashs->D1R;
	*((u32 *) out + 1) = hashs->D2R;
	*((u32 *) out + 2) = hashs->D3R;
	*((u32 *) out + 3) = hashs->D4R;
	*((u32 *) out + 4) = hashs->D5R;
}

void sha1_hash(u8 *data, u32 len, u8 *out)
{
    sha1_init(&sha1_context);
    sha1_update(&sha1_context, data, len);    
    sha1_final(&sha1_context, out);    
}




