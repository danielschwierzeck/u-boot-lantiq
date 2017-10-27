#ifndef AMAZON_S__DMA_H
#define AMAZON_S__DMA_H

#define RCV_INT          1
#define TX_BUF_FULL_INT  2
#define TRANSMIT_CPT_INT 4
#define AMAZON_S_DMA_CH_ON  1
#define AMAZON_S_DMA_CH_OFF 0
#define AMAZON_S_DMA_CH_DEFAULT_WEIGHT 100
#define AMAZON_S_DMA_DESCRIPTOR_OFFSET 25


enum attr_t{
   TX=0,
   RX=1,
   RESERVED=2,
   DEFAULT=3,
   
};

#ifdef CONFIG_CPU_LITTLE_ENDIAN
typedef struct rx_desc{
   u32 data_length:16;
   volatile u32 reserved:7;
   volatile u32 byte_offset:2; 
   volatile u32 Burst_length_offset:3;
   volatile u32 EoP:1;
   volatile u32 Res:1;
   volatile u32 C:1;
   volatile u32 OWN:1;
   volatile u32 Data_Pointer;
   /*fix me:should be 28 bits here, 32 bits just for host simulatiuon purpose*/ 
}_rx_desc; 


typedef struct tx_desc{
   volatile u32 data_length:16;
   volatile u32 reserved1:7;
   volatile u32 byte_offset:5;   
   volatile u32 EoP:1;
   volatile u32 SoP:1;
   volatile u32 C:1;
   volatile u32 OWN:1;
   volatile u32 Data_Pointer;//fix me:should be 28 bits here
}_tx_desc;
#else //BIG
typedef struct rx_desc{
	union
	{
		struct
		{
			volatile u32 OWN                 	:1;
			volatile u32 C	                 	:1;
			volatile u32 SoP                 	:1;
			volatile u32 EoP	         	:1;
			volatile u32 Burst_length_offset	:3;
			volatile u32 byte_offset	 	:2; 
			volatile u32 reserve             	:7;
			volatile u32 data_length             	:16;
		}field;

		volatile u32 word;
	}status;
	
	volatile u32 Data_Pointer;
}_rx_desc; 


typedef struct tx_desc{
	union
	{
		struct
		{
			volatile u32 OWN                 :1;
			volatile u32 C	                 :1;
			volatile u32 SoP                 :1;
			volatile u32 EoP	         :1;
			volatile u32 byte_offset	 :5; 
			volatile u32 reserved            :7;
			volatile u32 data_length         :16;
		}field;

		volatile u32 word;
	}status;
	
	volatile u32 Data_Pointer;
}_tx_desc;

#endif //ENDIAN


typedef struct dma_channel_info{
   
   /*relative channel number*/
   int rel_chan_no;
   /*class for this channel for QoS*/
   int pri;
   
   /*specify byte_offset*/ 
   int byte_offset;
   
   /*direction*/
   int dir;
   /*irq number*/
   int irq;
   /*descriptor parameter*/   
   int desc_base;
   int desc_len;
   int curr_desc;
   int prev_desc;/*only used if it is a tx channel*/
   
   /*weight setting for WFQ algorithm*/
   int weight;
   int default_weight;
   
   int packet_size;
   int burst_len;
   
   /*on or off of this channel*/
   int control;
   
   /**optional information for the upper layer devices*/
#if defined(CONFIG_AMAZON_S_ETHERNET_D2) || defined(CONFIG_DANUBE_PPA) || defined(CONFIG_DANUBE_PPA_MODULE)
  #if AMAZON_S_DMA_DESCRIPTOR_OFFSET > 64
   void* opt[AMAZON_S_DMA_DESCRIPTOR_OFFSET];
  #else
   void* opt[64];
  #endif
#else
   void* opt[AMAZON_S_DMA_DESCRIPTOR_OFFSET];
#endif
   
   /*Pointer to the peripheral device who is using this channel*/
   void* dma_dev;
   
   /*channel operations*/
   int (*open)(struct dma_channel_info* pCh);
   int (*close)(struct dma_channel_info* pCh);
   int (*reset)(struct dma_channel_info* pCh);
   int (*enable_irq)(struct dma_channel_info* pCh);
   int (*disable_irq)(struct dma_channel_info* pCh); 
}_dma_channel_info;


typedef struct dma_device_info{
   
    /*device name of this peripheral*/
    char device_name[15];
    int reserved;
    
    int tx_burst_len;
    int rx_burst_len;   
    int default_weight;
    
    int  current_tx_chan;
    int  current_rx_chan;
    int  num_tx_chan;
    int  num_rx_chan; 
    int  max_rx_chan_num;
    int  max_tx_chan_num;
    _dma_channel_info* tx_chan[20];
    _dma_channel_info* rx_chan[20]; 
    
    /*functions, optional*/
    u8* (*buffer_alloc)(int len,int* offset, void** opt);
    int (*buffer_free)(u8* dataptr, void* opt);
    int (*intr_handler)(struct dma_device_info* info, int status);
    void (*activate_poll)(struct dma_device_info* dma_dev);
	void (*inactivate_poll)(struct dma_device_info* dma_dev);

    void * priv;		/* used by peripheral driver only */
}_dma_device_info;

_dma_device_info* dma_device_reserve(char* dev_name);

int dma_device_release(_dma_device_info* dev);

int dma_device_register(_dma_device_info* info);

int dma_device_unregister(_dma_device_info* info);

int dma_device_read(struct dma_device_info* info, u8** dataptr, void** opt);

int dma_device_write(struct dma_device_info* info, u8* dataptr, int len, void* opt);

int dma_device_poll(struct dma_device_info* info, int work_to_do, int *work_done);
#endif /* AMAZON_DMA_H */
