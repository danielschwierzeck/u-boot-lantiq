/*
 * Copyright (C) 2011-2013 Daniel Schwierzeck, daniel.schwierzeck@gmail.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/asm.h>

	.section .rodata.__ltq_fw_phy11g_a1x
EXPORT(__ltq_fw_phy11g_a1x_start)
	.incbin "fw_phy11g_a1x.blob"
EXPORT(__ltq_fw_phy11g_a1x_end)

	.section .rodata.__ltq_fw_phy11g_a2x
EXPORT(__ltq_fw_phy11g_a2x_start)
	.incbin "fw_phy11g_a2x.blob"
EXPORT(__ltq_fw_phy11g_a2x_end)

	.section .rodata.__ltq_fw_phy22f_a1x
EXPORT(__ltq_fw_phy22f_a1x_start)
	.incbin "fw_phy22f_a1x.blob"
EXPORT(__ltq_fw_phy22f_a1x_end)

	.section .rodata.__ltq_fw_phy22f_a2x
EXPORT(__ltq_fw_phy22f_a2x_start)
	.incbin "fw_phy22f_a2x.blob"
EXPORT(__ltq_fw_phy22f_a2x_end)
