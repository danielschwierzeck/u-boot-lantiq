
#define KSEG1 0xa0000000


/************************************************************************/
/*   Module       :   DEU register address and bits             */
/************************************************************************/
#define DEU_BASE_ADDR                  (KSEG1 | 0x1E103100)

/* AES DEU register */
#define AES_CON                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0050))
#define AES_ID3R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0054))
#define AES_ID2R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0058))
#define AES_ID1R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x005C))
#define AES_ID0R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0060))

/* AES Key register */
#define AES_K7R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0064))
#define AES_K6R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0068))
#define AES_K5R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x006C))
#define AES_K4R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0070))
#define AES_K3R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0074))
#define AES_K2R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0078))
#define AES_K1R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x007C))
#define AES_K0R                        ((volatile u32 *)(DEU_BASE_ADDR + 0x0080))

/* AES vector register */
#define AES_IV3R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0084))
#define AES_IV2R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0088))
#define AES_IV1R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x008C))
#define AES_IV0R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0090))
#define AES_0D3R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0094))
#define AES_0D2R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x0098))
#define AES_OD1R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x009C))
#define AES_OD0R                       ((volatile u32 *)(DEU_BASE_ADDR + 0x00A0))


/* hash control register */
#define HASH_CON                       ((volatile u32 *)(DEU_BASE_ADDR + 0x00B0))



/***********************************************************************/
/*  Module      :  PMU register address and bits                       */
/***********************************************************************/
#define BSP_PMU_BASE_ADDR                    (KSEG1+0x1F102000)

#define BSP_PMU_PWDCR                   ((volatile u32*)(BSP_PMU_BASE_ADDR + 0x001c))

/***PM Global Enable Register 0 ***/
#define BSP_PMU_DEU             (1 << 20)


