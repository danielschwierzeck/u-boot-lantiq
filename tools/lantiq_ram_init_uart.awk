#!/usr/bin/awk -f
#
# Copyright (C) 2011-2012 Luka Perkov <luka@openwrt.org>
# Copyright (C) 2012 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
#
# Usage:
# awk -f lantiq_ram_init_uart.awk -v soc=<danube|ar9|vr9> PATH_TO_BOARD/ddr_settings.h
#
# SPDX-License-Identifier:	GPL-2.0+
#

function print_header()
{
	print ";                                                                            "
	print "; Copyright (C) 2011-2013 Luka Perkov <luka@openwrt.org>                     "
	print "; Copyright (C) 2012-2013 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>  "
	print ";                                                                            "
	print "; This file has been generated with lantiq_ram_init_uart.awk script.         "
	print ";                                                                            "
	print "; SPDX-License-Identifier:	GPL-2.0+                                    "
	print ""
}

function mc_danube_prologue()
{
	/* Clear access error log registers */
	print "0xbf800010", "0x0"
	print "0xbf800020", "0x0"

	/* Enable DDR and SRAM module in memory controller */
	print "0xbf800060", "0x5"

	/* Clear start bit of DDR memory controller */
	print "0xbf801030", "0x0"
}

function mc_ar9_prologue()
{
	/* Clear access error log registers */
	print "0xbf800010", "0x0"
	print "0xbf800020", "0x0"

	/* Enable FPI, DDR and SRAM module in memory controller */
	print "0xbf800060", "0xD"

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
		reg_base = 0xbf801000
		print_header()
		mc_danube_prologue()
		break
	case "ar9":
		reg_base = 0xbf801000
		print_header()
		mc_ar9_prologue()
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
	/* CCR07 contains MC enable bit and must not be set here */
	if (tolower($2) == "mc_ccr07_value")
		mc_ccr07_value = strtonum($3)
	if (tolower($2) == "mc_dc03_value")
		/* CCR07 contains MC enable bit and must not be set here */
	else
		printf("0x%x %s\n", reg_base, tolower($3))

	reg_base += 0x10
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
