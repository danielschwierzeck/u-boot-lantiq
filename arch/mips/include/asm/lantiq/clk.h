/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2007-2010 Lantiq Deutschland GmbH
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * Based on Lantiq port in Linux kernel
 */

#ifndef __LANTIQ_CLK_H__
#define __LANTIQ_CLK_H__

/* Symbolic clock speeds */
enum ltq_clk {
	CLOCK_83_MHZ = 83333333,
	CLOCK_111_MHZ = 111111111,
	CLOCK_125_MHZ = 125000000,
	CLOCK_133_MHZ = 133333333,
	CLOCK_166_MHZ = 166666667,
	CLOCK_197_MHZ = 197000000,
	CLOCK_333_MHZ = 333333333,
	CLOCK_393_MHZ = 393219000,
	CLOCK_500_MHZ = 500000000,
	CLOCK_600_MHZ = 600000000,
	CLOCK_1000_MHZ = 1000000000,
};

extern unsigned long ltq_get_cpu_clock(void);
extern unsigned long ltq_get_bus_clock(void);
extern unsigned long ltq_get_io_region_clock(void);

#endif /* __LANTIQ_CLK_H__ */
