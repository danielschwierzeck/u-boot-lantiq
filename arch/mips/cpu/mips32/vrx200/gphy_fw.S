/*
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 *
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 */

#include <asm/asm.h>

	.section .rodata.__ltq_fw_phy11g_a1x
EXPORT(__ltq_fw_phy11g_a1x_start)
	.incbin "fw_phy11g_a1x.bin.lzma"
EXPORT(__ltq_fw_phy11g_a1x_end)

	.section .rodata.__ltq_fw_phy11g_a2x
EXPORT(__ltq_fw_phy11g_a2x_start)
	.incbin "fw_phy11g_a2x.bin.lzma"
EXPORT(__ltq_fw_phy11g_a2x_end)

	.section .rodata.__ltq_fw_phy22f_a1x
EXPORT(__ltq_fw_phy22f_a1x_start)
	.incbin "fw_phy22f_a1x.bin"
EXPORT(__ltq_fw_phy22f_a1x_end)

	.section .rodata.__ltq_fw_phy22f_a2x
EXPORT(__ltq_fw_phy22f_a2x_start)
	.incbin "fw_phy22f_a2x.bin"
EXPORT(__ltq_fw_phy22f_a2x_end)
