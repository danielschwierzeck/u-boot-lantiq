
#include <asm/io.h>

#define ltq_w32(membase, offset, value)	writel(value, (u32 *) (KSEG1 + membase + offset))
#define ltq_r32(membase, offset)		readl((volatile u32 *) (KSEG1 + membase + offset))

/* TODO: change this */
#ifndef REG32
#define REG32(addr)                 *((volatile u32 *)(addr))
#endif

#ifndef REG16
#define REG16(addr)                 *((volatile u16 *)(addr))
#endif

#ifndef REG8
#define REG8(addr)                  *((volatile u8 *)(addr))
#endif

#define ltq_dma_r32(x)           REG32((x))
#define ltq_dma_w32(x, y)       (REG32((y)) = (x))
#define ltq_dma_w32_mask(clear, set, reg)   \
    ltq_dma_w32((ltq_dma_r32(reg) & ~(clear)) | (set), reg)

