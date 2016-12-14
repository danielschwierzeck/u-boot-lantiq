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
