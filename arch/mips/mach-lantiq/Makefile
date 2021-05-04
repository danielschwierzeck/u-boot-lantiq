#
# SPDX-License-Identifier:  GPL-2.0+
#

obj-$(CONFIG_LANTIQ_UBOOT_grx500) += grx500/
lib-$(CONFIG_LANTIQ_UBOOT_grx500) += grx500/

obj-$(CONFIG_LANTIQ_UBOOT_vr9) += vr9/
lib-$(CONFIG_LANTIQ_UBOOT_vr9) += vr9/

obj-$(CONFIG_LANTIQ_UBOOT_ar10) += ar10/
lib-$(CONFIG_LANTIQ_UBOOT_ar10) += ar10/

obj-$(CONFIG_LANTIQ_UBOOT_grx390) += ar10/
lib-$(CONFIG_LANTIQ_UBOOT_grx390) += ar10/

obj-$(CONFIG_LANTIQ_UBOOT_prx300) += prx300/
lib-$(CONFIG_LANTIQ_UBOOT_prx300) += prx300/

ifeq ($(CONFIG_LTQ_BOOT_FROM_NAND), y)
 ifeq ($(CONFIG_NAND_ECC_HW_REED_SOLOMON), y)
 obj-$(CONFIG_SPL_BUILD) += nand_boot_lq_mlc.o 
 else
  ifeq ($(CONFIG_NAND_LANTIQ), y)
  obj-$(CONFIG_SPL_BUILD) += nand_boot.o
  else
  obj-$(CONFIG_SPL_BUILD) += spinand_boot.o
  endif
 endif
endif

