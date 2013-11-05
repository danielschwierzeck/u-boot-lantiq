/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_DMA_H__
#define __LANTIQ_DMA_H__

enum ltq_dma_endianess {
	LTQ_DMA_ENDIANESS_B0_B1_B2_B3,	/* No byte swapping */
	LTQ_DMA_ENDIANESS_B1_B0_B3_B2,	/* B0B1B2B3 => B1B0B3B2 */
	LTQ_DMA_ENDIANESS_B2_B3_B0_B1,	/* B0B1B2B3 => B2B3B0B1 */
	LTQ_DMA_ENDIANESS_B3_B2_B1_B0,	/* B0B1B2B3 => B3B2B1B0 */
};

enum ltq_dma_burst_len {
	LTQ_DMA_BURST_2WORDS = 1,
	LTQ_DMA_BURST_4WORDS = 2,
	LTQ_DMA_BURST_8WORDS = 3,
};

struct ltq_dma_desc {
	u32 ctl;
	u32 addr;
};

struct ltq_dma_channel {
	struct ltq_dma_device *dev;
	u8 chan_no;
	u8 class;
	u16 num_desc;
	struct ltq_dma_desc *desc_base;
	void *mem_base;
	u32 dma_addr;
};

struct ltq_dma_device {
	enum ltq_dma_endianess rx_endian_swap;
	enum ltq_dma_endianess tx_endian_swap;
	enum ltq_dma_burst_len rx_burst_len;
	enum ltq_dma_burst_len tx_burst_len;
	struct ltq_dma_channel rx_chan;
	struct ltq_dma_channel tx_chan;
	u8 port;
};

/**
 * Initialize DMA hardware and driver
 */
void ltq_dma_init(void);

/**
 * Register given DMA client context
 *
 * @returns 0 on success, negative value otherwise
 */
int ltq_dma_register(struct ltq_dma_device *dev);

/**
 * Reset and halt all channels related to given DMA client
 */
void ltq_dma_reset(struct ltq_dma_device *dev);
void ltq_dma_enable(struct ltq_dma_device *dev);
void ltq_dma_disable(struct ltq_dma_device *dev);

/**
 * Map RX DMA descriptor to memory region
 *
 * @returns 0 on success, negative value otherwise
 */
int ltq_dma_rx_map(struct ltq_dma_device *dev, int index, void *data, int len);

/**
 * Check if new data is available.
 *
 * @returns length of received data, 0 otherwise
 */
int ltq_dma_rx_poll(struct ltq_dma_device *dev, int index);

int ltq_dma_rx_length(struct ltq_dma_device *dev, int index);

/**
 * Map TX DMA descriptor to memory region
 *
 * @returns 0 on success, negative value otherwise
 */
int ltq_dma_tx_map(struct ltq_dma_device *dev, int index, void *data, int len,
			unsigned long timeout);

int ltq_dma_tx_wait(struct ltq_dma_device *dev, int index,
			unsigned long timeout);

#endif /* __LANTIQ_DMA_H__ */
