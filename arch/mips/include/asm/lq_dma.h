typedef struct
{
    union
    {
        struct
        {
            volatile u32 OWN                 :1;
            volatile u32 C                   :1;
            volatile u32 Sop                 :1;
            volatile u32 Eop             :1;
            volatile u32 reserved        :3;
            volatile u32 Byteoffset      :2;
            volatile u32 reserve             :7;
            volatile u32 DataLen             :16;
        }field;

        volatile u32 word;
    }status;

    volatile u32 DataPtr;
} dma_rx_descriptor_t;

typedef struct
{
    union
    {
        struct
        {
            volatile u32 OWN                 :1;
            volatile u32 C                   :1;
            volatile u32 Sop                 :1;
            volatile u32 Eop             :1;
            volatile u32 Byteoffset      :5;
            volatile u32 reserved            :7;
            volatile u32 DataLen             :16;
        }field;

        volatile u32 word;
    }status;

    volatile u32 DataPtr;
} dma_tx_descriptor_t;
#ifdef CONFIG_DRIVER_GRX500
#define DMA_PKT_SIZE_DEFAULT    2048

#define DMA_TX_PORT_DEFAULT_WEIGHT  1
/** Default Port Transmit weight value */
#define DMA_TX_CHAN_DEFAULT_WEIGHT  1

#define MAX_DMA_CHAN_PER_PORT   64
#define MAX_DMA_PORT_PER_CTRL   4
#define MAX_DMA_CONTROLLER  7 

#define DMA0_MAX_CHAN       16
#define DMA1TX_MAX_CHAN     16
#define DMA1RX_MAX_CHAN     32
#define DMA2TX_MAX_CHAN     16
#define DMA2RX_MAX_CHAN     32
#define DMA3_MAX_CHAN       64
#define DMA4_MAX_CHAN       16

#define DMA0_IRQ        64
#define DMA1TX_IRQ      65
#define DMA1RX_IRQ      66
#define DMA2TX_IRQ      67
#define DMA2RX_IRQ      68
#define DMA3_IRQ        69
#define DMA4_IRQ        70

#define DMA0_PORTS      4
#define DMA_DEFAULT_PORTS   1

typedef enum {
    DMA_CLASS_0 = 0,
    DMA_CLASS_1,
    DMA_CLASS_2,
    DMA_CLASS_3,
    DMA_CLASS_4,
    DMA_CLASS_5,
    DMA_CLASS_6,
    DMA_CLASS_7,
    DMA_CLASS_8,
    DMA_CLASS_9,
    DMA_CLASS_10,
    DMA_CLASS_11,
    DMA_CLASS_12,
    DMA_CLASS_13,
    DMA_CLASS_14,
    DMA_CLASS_15,
    DMA_CLASS_16,
    DMA_CLASS_17,
    DMA_CLASS_18,
    DMA_CLASS_19,
    DMA_CLASS_20,
    DMA_CLASS_21,
    DMA_CLASS_22,
    DMA_CLASS_23,
    DMA_CLASS_24,
    DMA_CLASS_25,
    DMA_CLASS_26,
    DMA_CLASS_27,
    DMA_CLASS_28,
    DMA_CLASS_29,
    DMA_CLASS_30,
    DMA_CLASS_31,
} dma_class_t;

#define DMA_CLASS_MAX       DMA_CLASS_31
#define DMA_CLASS_LOW_MAX   DMA_CLASS_7

/* bit 18~19 for high class value not defined yet*/

typedef enum {
    DMA_ENDIAN_TYPE0 = 0,
    DMA_ENDIAN_TYPE1,   /*!< Byte Swap(B0B1B2B3 => B1B0B3B2) */
    DMA_ENDIAN_TYPE2,   /*!< Word Swap (B0B1B2B3 => B2B3B0B1) */
    DMA_ENDIAN_TYPE3,   /*!< DWord Swap (B0B1B2B3 => B3B2B1B0) */
    DMA_ENDIAN_MAX,
} dma_endian_t;

#ifdef CONFIG_BIG_ENDIAN
#define DMA_ENDIAN_DEFAULT  DMA_ENDIAN_TYPE3
#else
#define DMA_ENDIAN_DEFAULT  DMA_ENDIAN_TYPE0
#endif

typedef enum {
    DMA_BURSTL_2DW = 1, /*!< 2 DWORD DMA burst length */
    DMA_BURSTL_4DW = 2, /*!< 4 DWORD DMA burst length */
    DMA_BURSTL_8DW = 3, /*!< 8 DWORD DMA burst length */
    DMA_BURSTL_16DW = 16,
} dma_burst_len_t;

#define DMA_BURSTL_DEFAULT  DMA_BURSTL_16DW

typedef enum {
    DMA_CH_OFF = 0, /*!< DMA channel is OFF */
    DMA_CH_ON = 1,  /*!< DMA channel is ON */
} dma_channel_on_off_t;

typedef enum {
    DMA_RX_CH = 0,  /*!< Rx channel */
    DMA_TX_CH = 1,  /*!< Tx channel */
} dma_chan_dir_t;

enum {
    DMA_PKT_DROP_DISABLE = 0,
    DMA_PKT_DROP_ENABLE,
};

#define DMA_FLUSH_MEMCPY        1
#define DMA_CHAN_RST            1

enum {
    DMA_CHAN_GLOBAL_POLLING_DIS = 0,
    DMA_CHAN_GLOBAL_POLLING_EN,
};

enum {
    DMA_PORT_TXWGT0 = 0,
    DMA_PORT_TXWGT1 ,
    DMA_PORT_TXWGT2 ,
    DMA_PORT_TXWGT3 ,
    DMA_PORT_TXWGT4 ,
    DMA_PORT_TXWGT5 ,
    DMA_PORT_TXWGT6 ,
    DMA_PORT_TXWGT7 ,
    DMA_PORT_TXWGTMAX,
};

enum {
    DMA_CHAN_TXWGT0 = 0,
    DMA_CHAN_TXWGT1,
    DMA_CHAN_TXWGT2,
    DMA_CHAN_TXWGT3,
    DMA_CHAN_TXWGTMAX,
};

enum {
    DMA_ARB_BURST = 0,
    DMA_ARB_MUL_BURST,
    DMA_ARB_PKT,
};

#define DMA_CHAN_GLOBAL_POLLING_DEFAULT_INTERVAL    16

/* Interrupt related definition */
#define DMA_CIE_EOP     0x00000002
/** Descriptor Under-Run Interrupt enable  */
#define DMA_CIE_DUR     0x00000004
/** Descriptor Complete Interrupt  enable*/
#define DMA_CIE_DESCPT      0x00000008
/** Channel Off Interrupt enable */
#define DMA_CIE_CHOFF       0x00000010
/** SAI Read Error Interrupt enable*/
#define DMA_CIE_RDERR       0x00000020


#define DMA_CIE_ALL (DMA_CIE_EOP | DMA_CIE_DUR | DMA_CIE_DESCPT| \
            DMA_CIE_CHOFF | DMA_CIE_RDERR)

#define DMA_CIE_DEFAULT (DMA_CIE_EOP | DMA_CIE_DESCPT)

/* Four DWs desriptor format */
typedef struct {
    union {
        struct {
            volatile u32 session_id     :12;
            volatile u32 tcp_err        :1;
            volatile u32 nat        :1;
            volatile u32 dec        :1;
            volatile u32 enc        :1;
            volatile u32 mpe2       :1;
            volatile u32 mpe1       :1;
            volatile u32 color      :2;
            volatile u32 ep         :4;
            volatile u32 resv       :4;
            volatile u32 cla        :4;
        }field;
        volatile u32 all;
    }DW1;
    union {
        struct {
            volatile u32 resv       :3;
            volatile u32 tunnel_id      :4;
            volatile u32 flow_id        :8;
            volatile u32 eth_type       :2;
            volatile u32 dest_id        :15;
        }field;
        volatile u32 all;
    }DW0;
    union {
        struct {
        volatile u32 own        :1;
        volatile u32 c          :1;
        volatile u32 sop        :1;
        volatile u32 eop        :1;
        volatile u32 dic        :1;
        volatile u32 pdu        :1;
        volatile u32 byteoffset     :3;
        volatile u32 vdsl_wan       :7;
        volatile u32 datalen        :16;
        }field;
        volatile u32 all;
    }DW3;
    union {
        struct {
            volatile u32 address    :32;
        }field;
        volatile u32 all;
    }DW2;
} _dma_rx_descriptor_t;

typedef struct {
    union {
        struct {
            volatile u32 session_id     :12;
            volatile u32 tcp_err        :1;
            volatile u32 nat        :1;
            volatile u32 dec        :1;
            volatile u32 enc        :1;
            volatile u32 mpe2       :1;
            volatile u32 mpe1       :1;
            volatile u32 color      :2;
            volatile u32 ep         :4;
            volatile u32 resv       :4;
            volatile u32 cla        :4;
        }field;
    volatile u32 all;
    }DW1;
    union {
        struct {
            volatile u32 resv       :3;
            volatile u32 tunnel_id      :4;
            volatile u32 flow_id        :8;
            volatile u32 eth_type       :2;
            volatile u32 dest_id        :15;
        }field;
        volatile u32 all;
    }DW0;
    union {
        struct {
            volatile u32 own        :1;
            volatile u32 c          :1;
            volatile u32 sop        :1;
            volatile u32 eop        :1;
            volatile u32 dic        :1;
            volatile u32 pdu        :1;
            volatile u32 byteoffset     :3;
            volatile u32 vdsl_wan       :7;
            volatile u32 datalen        :16;
        }field;
        volatile u32 all;
    }DW3;
    union {
        struct {
            volatile u32 address        :32;
        }field;
    volatile u32 all;
    }DW2;
} _dma_tx_descriptor_t;

/* 2 DWs format descriptor */
struct dma_rx_desc_2dw {
    union {
        struct {
            volatile unsigned int own:1;
            volatile unsigned int c:1;
            volatile unsigned int sop:1;
            volatile unsigned int eop:1;
            volatile unsigned int reserve_25_27:3;
            volatile unsigned int byte_offset:2;
            volatile unsigned int rx_sideband:4;
            volatile unsigned int reserve16_18:3;
            volatile unsigned int data_len:16;
        } field;
        volatile unsigned int word; 
    } status;
    volatile unsigned int data_pointer; /* Descriptor data pointer */
};

struct dma_tx_desc_2dw {
    union {
        struct {
            volatile unsigned int own:1;
            volatile unsigned int c:1;
            volatile unsigned int sop:1;
            volatile unsigned int eop:1;
            volatile unsigned int byte_offset:5;
            volatile unsigned int reserved:7;
            volatile unsigned int data_len:16;
        } field;
        volatile unsigned int word;
    } status;
    volatile unsigned int data_pointer; /* Descriptor data pointer */
};
#endif
