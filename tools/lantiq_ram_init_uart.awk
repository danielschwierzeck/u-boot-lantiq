#!/usr/bin/awk -f
#
# This file is released under the terms of GPL v2 and any later version.
# See the file COPYING in the root directory of the source tree for details.
#
# Copyright (C) 2011-2012 Luka Perkov <luka@openwrt.org>
# Copyright (C) 2012 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
#
# usage: awk -f lantiq_ram_init_uart.awk -v soc=<danube|ar9|vr9> PATH_TO_BOARD/ddr_settings.h
#

function print_header()
{
	print ";                                                                            "
	print "; This file is released under the terms of GPL v2 and any later version.     "
	print "; See the file COPYING in the root directory of the source tree for details. "
	print ";                                                                            "
	print "; generated with lantiq_ram_init_uart.awk                                    "
	print ";                                                                            "
	print "; Copyright (C) 2011-2012 Luka Perkov <luka@openwrt.org>                     "
	print "; Copyright (C) 2012 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>       "
	print ";                                                                            "
	print ""
}

function mc_ddr1_prologue()
{
	/* Clear access error log registers */
	print "0xbf800010", "0x0"
	print "0xbf800020", "0x0"

	/* Enable DDR and SRAM module in memory controller */
	print "0xbf800060", "0x5"

	/* Clear start bit of DDR memory controller */
	print "0xbf801030", "0x0"
}

function mc_ddr1_epilogue()
{
	/* Set start bit of DDR memory controller */
	print "0xbf801030", "0x100"
}

function mc_ddr2_prologue()
{
	/* Put memory controller in inactive mode */
	print "0xbf401070", "0x0"
}

function mc_ddr2_epilogue(mc_ccr07_value)
{
	/* Put memory controller in active mode */
	mc_ccr07_value = or(mc_ccr07_value, 0x100)
	printf("0xbf401070 0x%x\n", mc_ccr07_value)
}

BEGIN {
	switch (soc) {
	case "danube":
	case "ar9":
		reg_base = 0xbf801000
		print_header()
		mc_ddr1_prologue()
		break
	case "vr9":
		reg_base = 0xbf401000
		print_header()
		mc_ddr2_prologue()
		break
	default:
		print "Invalid or no value for soc specified!"
		exit 1
	}

	mc_ccr07_value = 0
}

/^#define/ {
	printf("0x%x %s\n", reg_base, tolower($3))
	reg_base += 0x10
}

/^#define(.*)MC_CCR07_VALUE/ {
	printf("0x%x %s\n", reg_base, tolower($3))
	reg_base += 0x10
	mc_ccr07_value = strtonum($3)
}

END {
	switch (soc) {
	case "danube":
	case "ar9":
		mc_ddr1_epilogue()
		break
	case "vr9":
		mc_ddr2_epilogue(mc_ccr07_value)
		break
	default:
	}
}
