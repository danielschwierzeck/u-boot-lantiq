// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Sphairon GmbH (a ZyXEL company)
 */

#include <asm/asm.h>
#include <asm/regdef.h>

	.set noreorder

ENTRY(_start)
	/* unlock EJTAG access */
	li	t1, 0xb6080000
	sw	zero, 0x124(t1)

	/* busy loop forever */
1:	b	1b
	 nop

	END(_start)
