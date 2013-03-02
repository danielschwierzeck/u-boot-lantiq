#!/bin/bash

set -e
set -x

test $# -eq 1

openwrt_root=$(readlink -f $1)
test -d $openwrt_root

uboot_lantiq_dir=$openwrt_root/package/boot/uboot-lantiq/patches
test -d $uboot_lantiq_dir

rm -vf $uboot_lantiq_dir/*
git format-patch -k -p --no-renames --text --full-index -o $uboot_lantiq_dir v2012.10..openwrt/v2013.01
