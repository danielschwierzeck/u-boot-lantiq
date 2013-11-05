/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LANTIQ_PM_H__
#define __LANTIQ_PM_H__

enum ltq_pm_modules {
	LTQ_PM_CORE,
	LTQ_PM_DMA,
	LTQ_PM_ETH,
	LTQ_PM_SPI,
};

u32 ltq_pm_map(enum ltq_pm_modules module);
int ltq_pm_enable(enum ltq_pm_modules module);
int ltq_pm_disable(enum ltq_pm_modules module);

#endif /* __LANTIQ_PM_H__ */
