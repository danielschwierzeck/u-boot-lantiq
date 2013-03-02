#!/usr/bin/awk -f
#
# Copyright (C) 2011-2012 Luka Perkov <luka@openwrt.org>
# Copyright (C) 2012-2015 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
#
# Usage:
# awk -f lantiq_ram_init_uart.awk -v soc=<danube|ar9|vr9|ar10> PATH_TO_BOARD/ddr_settings.h
#
# SPDX-License-Identifier:	GPL-2.0+
#

function print_header()
{
	print ";                                                                            "
	print "; Copyright (C) 2011-2013 Luka Perkov <luka@openwrt.org>                     "
	print "; Copyright (C) 2012-2015 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>  "
	print ";                                                                            "
	print "; This file has been generated with lantiq_ram_init_uart.awk script.         "
	print ";                                                                            "
	print "; SPDX-License-Identifier:	GPL-2.0+                                    "
	print ""
}

function mc_danube_prologue()
{
	print ";Clear access error logs"
	print "0xbf800010", "0x0"
	print "0xbf800020", "0x0"

	print ";Enable FPI and SRAM module in memory controller"
	print "0xbf800060", "0x5"

	print ";MC_DC03_VALUE -> halt memory controller"
	print "0xbf801030", "0x0"
}

function mc_ar9_prologue()
{
	print ";Clear access error logs"
	print "0xbf800010", "0x0"
	print "0xbf800020", "0x0"

	print ";Enable FPI, DDR and SRAM module in memory controller"
	print "0xbf800060", "0xD"

	print ";MC_DC03_VALUE -> halt memory controller"
	print "0xbf801030", "0x0"
}

function mc_danube_epilogue()
{
	print ";MC_DC03_VALUE -> start memory controller"
	print "0xbf801030", "0x100"
}

function mc_vr9_prologue()
{
	print ";MC_CCR07_VALUE -> halt memory controller"
	print "0xbf401070", "0x0"
}

function mc_vr9_epilogue()
{
	print ";DDR_ECHO_DLL0"
	print "0xbf400420", "0x24"
	print ";DDR_ECHO_DLL1"
	print "0xbf400428", "0x24"
	print ";MC_CCR07_VALUE -> start memory controller"
	printf("0xbf401070 0x%x\n", or(mc_ccr07_value, 0x100))
}

function mc_ar10_prologue()
{
	print ";MC_CCR00_VALUE -> halt memory controller"
	print "0xbf801000", "0x0"
}

function mc_ar10_epilogue()
{
	print ";DDR_ECHO_DLL0"
	print "0xbf8001d8", "0x20"
	print ";DDR_ECHO_DLL1"
	print "0xbf8001e0", "0x20"
	print ";MC_CCR00_VALUE -> start memory controller"
	print "0xbf801000", "0x401"
}

BEGIN {
	switch (soc) {
	case "danube":
		dc_reg_base = 0xbf801000
		print_header()
		mc_danube_prologue()
		break
	case "ar9":
		dc_reg_base = 0xbf801000
		print_header()
		mc_ar9_prologue()
		break
	case "vr9":
		ccr_reg_base = 0xbf401000
		print_header()
		mc_vr9_prologue()
		break
	case "ar10":
		ccr_reg_base = 0xbf801000
		phyr_reg_base = 0xbf801400
		print_header()
		mc_ar10_prologue()
		break
	default:
		print "Invalid or no value for soc specified!"
		exit 1
	}

	mc_ccr07_value = 0
	do_print = 1
}

/^#define[[:space:]]MC_DC03_VALUE[[:space:]]/ {
	do_print = 0
}

/^#define[[:space:]]MC_CCR00_VALUE[[:space:]]/ {
	if (soc == "ar10")
		do_print = 0
}

/^#define[[:space:]]MC_CCR07_VALUE[[:space:]]/ {
	if (soc == "vr9") {
		mc_ccr07_value = strtonum($3)
		do_print = 0
	}
}

/^#define[[:space:]]MC_DC[[:digit:]][[:digit:]]_VALUE[[:space:]]/ {
	if (do_print) {
		printf(";%s\n", $2);
		printf("0x%x %s\n", dc_reg_base, tolower($3))
	} else {
		do_print = 1
	}

	dc_reg_base += 0x10
}

/^#define[[:space:]]MC_CCR[[:digit:]][[:digit:]]_VALUE[[:space:]]/ {
	if (do_print) {
		printf(";%s\n", $2)
		printf("0x%x %s\n", ccr_reg_base, tolower($3))
	} else {
		do_print = 1
	}

	ccr_reg_base += 0x10
}

/^#define[[:space:]]MC_PHYR[[:digit:]]_VALUE[[:space:]]/ {
	printf(";%s\n", $2)
	printf("0x%x %s\n", phyr_reg_base, tolower($3))

	phyr_reg_base += 0x10
}

END {
	switch (soc) {
	case "danube":
	case "ar9":
		mc_danube_epilogue()
		break
	case "vr9":
		mc_vr9_epilogue()
		break
	case "ar10":
		mc_ar10_epilogue()
		break
	default:
	}
}
