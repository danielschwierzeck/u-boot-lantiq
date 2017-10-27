#!/bin/sh


./mk_ltq_header.pl --ddr haps-ram.conf --bch 8 --col 2 --row 3 --blocksize 0x20000 --pagesize 0x800 --offset 0x800 --out header.ltq
../../scripts_platform/pad2align.sh -n 1760 header.ltq
gcc -o bch_enc bch_enc.c
./bch_enc header.ltq header.bch 40
../../scripts_platform/pad2align.sh -n 0x800 header.bch

./mk_sf_image.pl -i chiptest.bin -o output.bin -j 0xa0400000 -m 0
../../scripts_platform/pad2align.sh -n 440 output.bin
./bch_enc output.bin output.bch 8

cp header.bch image.bin
cat output.bch >>image.bin


