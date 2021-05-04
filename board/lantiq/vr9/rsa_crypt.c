typedef unsigned char u8;
#define HASH_RESULT_BYTES 	(20)

typedef unsigned short u16;
typedef unsigned long u32;

static long expmod(long m, long a, long pq);
static long rsa_crypt(long msg, long a, long pq);


void ds_crypt(u8 *input, u8 *output)
{
    u32 *rsa_dword = (u32 *)input;
    long privkey = 6539;
    long pubkey = 24287;
    int cnt;
      
    for (cnt = 0; cnt < HASH_RESULT_BYTES; cnt++)
    {
        output[cnt] = rsa_crypt(rsa_dword[cnt], privkey, pubkey);
    }
}

// computes  m^a mod pq
static long expmod(long m, long a, long pq)
{
	long z=m;
	long p=1;
	while(a>1)
	{
		if (a&1)  { p*=z; p%=pq;  }
		z*=z; z%=pq;
		a>>=1;
	}
	return (z*p)%pq;
}


static long rsa_crypt(long msg, long a, long pq)
{
    return expmod(msg, a, pq);
}

