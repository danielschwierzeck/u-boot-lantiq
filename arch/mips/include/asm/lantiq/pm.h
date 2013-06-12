/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
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
