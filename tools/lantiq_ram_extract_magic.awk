#
# This file is released under the terms of GPL v2 and any later version.
# See the file COPYING in the root directory of the source tree for details.
#
# Copyright (C) 2011 Luka Perkov <luka@openwrt.org>
#
# usage: mips-openwrt-linux-objdump -EB -b binary -m mips:isa32r2 -D YOUR_IMAGE_DUMP | awk -f lantiq_ram_extract_magic.awk
#

BEGIN {
	print "/*                                                                            "
	print " * This file is released under the terms of GPL v2 and any later version.     "
	print " * See the file COPYING in the root directory of the source tree for details. "
	print " *                                                                            "
	print " * generated with lantiq_ram_extract_magic.awk                                "
	print " *                                                                            "
	print " * Copyright (C) 2011 Luka Perkov <luka@openwrt.org>                          "
	print " */                                                                           "
	print ""

	mc_dc_value=0
	mc_dc_number=0
	right_section=0
	mc_dc_value_print=0
	mc_dc_number_print=0
}

/t2,[0-9]+$/ {
	if (right_section) {
		split($4, tmp, ",")
		mc_dc_value=sprintf("%X", tmp[2])
		mc_dc_value_print=1
	}
}

/t2,0x[0-9a-f]+$/ {
	if (right_section) {
		split($4, tmp, ",0x")
		mc_dc_value=sprintf("%s", tmp[2])
		mc_dc_value=toupper(mc_dc_value)
		mc_dc_value_print=1
	}
}

/t2,[0-9]+\(t1\)$/ {
	if (right_section) {
		split($4, tmp, ",")
		split(tmp[2], tmp, "(")
		mc_dc_number=tmp[1]/16
		mc_dc_number_print=1
	}
}

{
	if (right_section && mc_dc_number_print && mc_dc_value_print) {
		if (mc_dc_number < 10)
			print "#define MC_DC0" mc_dc_number "_VALUE\t0x" mc_dc_value
		else
			print "#define MC_DC" mc_dc_number "_VALUE\t0x" mc_dc_value
		mc_dc_value_print=0
		mc_dc_number_print=0
	}

	if ($4 == "t1,t1,0x1000")
		right_section=1


	if ($4 == "t2,736(t1)")
		right_section=0
}
