/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_RESET_H__
#define __LANTIQ_RESET_H__

enum ltq_reset_modules {
	LTQ_RESET_CORE,
	LTQ_RESET_DMA,
	LTQ_RESET_ETH,
	LTQ_RESET_PHY,
	LTQ_RESET_HARD,
	LTQ_RESET_SOFT,
};

extern u32 ltq_reset_map(enum ltq_reset_modules module);
extern int ltq_reset_activate(enum ltq_reset_modules module);
extern int ltq_reset_deactivate(enum ltq_reset_modules module);

static inline int ltq_reset_once(enum ltq_reset_modules module, ulong usec)
{
	int ret;

	ret = ltq_reset_activate(module);
	if (ret)
		return ret;

	__udelay(usec);
	ret = ltq_reset_deactivate(module);

	return ret;
}

#endif /* __LANTIQ_RESET_H__ */
