/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2010 John Crispin <blogic@openwrt.org>
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __LANTIQ_IO_H__
#define __LANTIQ_IO_H__

#include <asm/io.h>

#define ltq_readb(a)		__raw_readb(a)
#define ltq_writeb(a, v)	__raw_writeb(v, a)

#define ltq_readl(a)		__raw_readl(a)
#define ltq_writel(a, v)	__raw_writel(v, a)

#define ltq_clrbits(a, clear) \
	ltq_writel(a, ltq_readl(a) & ~(clear))

#define ltq_setbits(a, set) \
	ltq_writel(a, ltq_readl(a) | (set))

#define ltq_clrsetbits(a, clear, set) \
	ltq_writel(a, (ltq_readl(a) & ~(clear)) | (set))

static inline void ltq_reg_dump(const void *addr, const char *desc)
{
	u32 data;

	data = ltq_readl(addr);
	printf("ltq_reg_dump: %s 0x%p = 0x%08x\n",
		desc, addr, data);
}

#endif /* __LANTIQ_IO_H__ */
