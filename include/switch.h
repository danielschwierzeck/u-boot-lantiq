/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#ifndef __SWITCH_H
#define __SWITCH_H

#include <linux/list.h>

#define SWITCH_NAME_SIZE	32

struct switch_device;
struct mii_dev;

struct switch_driver {
	struct list_head list;

	/* Switch device name */
	const char name[SWITCH_NAME_SIZE];

	/*
	 * Called to probe the switch chip. Must return 0 if the switch
	 * chip matches the given switch device/driver combination. Otherwise
	 * 1 must be returned.
	 */
	int (*probe) (struct switch_device *dev);

	/*
	 * Called to initialize the switch chip.
	 */
	void (*setup) (struct switch_device *dev);
};

struct switch_device {
	struct list_head list;
	struct switch_driver *drv;

	/* MII bus the switch chip is connected to */
	struct mii_dev *bus;

	/* Switch device name */
	const char name[SWITCH_NAME_SIZE];

	/* Bitmask for board specific setup of used switch ports */
	u16 port_mask;

	/* Number of switch port that is connected to host CPU */
	u16 cpu_port;
};

/*
 * Board specific switch initialization.
 *
 * Called from switch_init to register the board specific switch_device
 * structure.
 */
extern int board_switch_init(void);

/* Initialize switch subsystem */
#ifdef CONFIG_SWITCH_MULTI
extern void switch_init(void);
#else
static inline void switch_init(void)
{
}
#endif

/* Register a switch driver */
extern void switch_driver_register(struct switch_driver *drv);

/* Register a switch device */
extern int switch_device_register(struct switch_device *dev);

/*
 * Probe the available switch chips and connect the found one
 * with the given MII bus
 */
#ifdef CONFIG_SWITCH_MULTI
extern struct switch_device *switch_connect(struct mii_dev *bus);
#else
static inline struct switch_device *switch_connect(struct mii_dev *bus)
{
	return NULL;
}
#endif

/*
 * Setup the given switch device
 */
static inline void switch_setup(struct switch_device *dev)
{
	if (dev->drv->setup)
		dev->drv->setup(dev);
}

/* Init functions for supported Switch drivers */
extern void switch_psb697x_init(void);
extern void switch_adm6996i_init(void);
extern void switch_ar8216_init(void);
extern void switch_rtl8306_init(void);

#endif /* __SWITCH_H */

