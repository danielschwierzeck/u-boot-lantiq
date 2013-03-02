/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <asm/asm.h>
#include <asm/regdef.h>

NESTED(lowlevel_init, 0, ra)
	move	t8, ra

	la	t7, ltq_cgu_init
	jalr	t7

	la	t7, ltq_mem_init
	jalr	t7

	jr	t8
	END(lowlevel_init)
