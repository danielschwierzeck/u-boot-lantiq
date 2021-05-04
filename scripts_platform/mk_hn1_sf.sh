#!/bin/sh
touch scripts_platform/dummy
scripts_platform/sgct scripts_platform/dummy board/hn1/sf_bootrom.rec u-boot.sflash
scripts_platform/pad2align.sh -n 2048 u-boot.sflash
sed -e '/^[[:space:]]*$/d' -e '/^#/d' -e's/0x//g' ram.conf | awk '{printf "%s %s\n", $1, $2}' >tmp
scripts_platform/gen_ram.pl tmp ram_tmp
scripts_platform/pad2align.sh -n 2048 ram_tmp
cat ram_tmp >>u-boot.sflash
cat u-boot.ifx >>u-boot.sflash
rm tmp ram_tmp u-boot.ifx
