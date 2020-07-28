#
# SPDX-License-Identifier:	GPL-2.0+
#

hostprogs-$(CONFIG_NAND_BOOT) += init_ddr
hostprogs-$(CONFIG_NAND_BOOT) += bch_enc
HOSTCFLAGS_bch_enc.o := -Wno-unused-result

always := $(hostprogs-y)
