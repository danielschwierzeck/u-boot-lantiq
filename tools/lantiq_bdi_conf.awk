#!/usr/bin/awk -f
#
# Copyright (C) 2013 Luka Perkov <luka@openwrt.org>
# Copyright (C) 2013 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>
#
# Usage:
#  awk -f lantiq_bdi_conf.awk -v soc=ar9 board=<name> PATH_TO_BOARD/ddr_settings.h
#
# Additional information:
#  http://www.abatron.ch/fileadmin/user_upload/products/pdf/ManGDBR4K-3000.pdf
#
# SPDX-License-Identifier:	GPL-2.0+
#

function print_header()
{
	print ";                                                                         "
	print "; Copyright (C) 2013 Luka Perkov <luka@openwrt.org>                       "
	print "; Copyright (C) 2013 Daniel Schwierzeck <daniel.schwierzeck@gmail.com>    "
	print ";                                                                         "
	print "; This file has been generated with lantiq_bdi_conf.awk script.           "
	print ";                                                                         "
	print "; SPDX-License-Identifier:	GPL-2.0+                                 "
	print ";                                                                         "
	print ""
}

function init_ar9_prologue()
{
	print "WM32 0xBF103010 0x80		; CGU for CPU 333Mhz, DDR 167Mhz"
	print "WM32 0xBF103014 0x01		; CGU update"
	print "WM32 0xBF800010 0x0		; Clear error access log register"
	print "WM32 0xBF800020 0x0		; Clear error access log register"
	print "WM32 0xBF800060 0xD		; Enable FPI, DDR and SRAM module in memory controller"
	print "WM32 0xBF801030 0x0		; Clear start bit of DDR memory controller"
}

function init_ar9_epilogue()
{
	print "WM32 0xBE105360 0x4001D7FF	; EBU setup"
}

function init_ddr1_epilogue()
{
	print "WM32 0xBF801030 0x100		; Set start bit of DDR memory controller"
}

function ar9_target()
{
	print "CPUTYPE		M34K"
	print "ENDIAN		BIG"
	print "JTAGCLOCK	1"
	print "BDIMODE		AGENT		; [ LOADONLY, AGENT ]"
	print "RESET		JTAG		; [ NONE, JTAG, HARD ]"
	print "POWERUP		100"
	print "WAKEUP		100"
	print "BREAKMODE	HARD		; [ SOFT, HARD ]"
	print  "STEPMODE	SWBP		; [ JTAG, HWBP, SWBP ]"
	print "VECTOR		CATCH"
	print  "SCANSUCC	1 5"
}

function flash_p2601hnfx()
{
	print "CHIPTYPE	MIRRORX16"
	print "CHIPSIZE	0x1000000"
	print "BUSWIDTH	16"
}

BEGIN {
	switch (soc) {
	case "ar9":
		reg_base = 0xbf801000
		print_header()
		print "[INIT]"
		init_ar9_prologue()
		break
	default:
		print "Invalid or no value for SoC specified!"
		exit 1
	}
}

/^#define/ {
	/* DC03 contains MC enable bit and must not be set here */
	if (tolower($2) != "mc_dc03_value")
		printf("WM32 0x%x %s\n", reg_base, tolower($3))

	reg_base += 0x10
}

END {
	switch (soc) {
	case "ar9":
		init_ddr1_epilogue()
		init_ar9_epilogue()
		print ""
		print "[TARGET]"
		ar9_target()
		print ""
		print "[HOST]"
		print "PROMPT		\"ar9> \""
		print ""
		break
	default:
	}

	switch (board) {
	case "p2601hnfx":
		print "[FLASH]"
		flash_p2601hnfx()
		print ""
		break
	default:
	}
}
