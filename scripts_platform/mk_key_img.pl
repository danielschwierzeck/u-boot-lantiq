#!/usr/bin/perl
#perl script to make an image which contains the aes key
#Revision history
#18/02/2013 Author Wu Qi Ming
#usage: mk_key_img.pl $(key) data.bin
#output: data.bin

use strict;

#key image size, hardcoded to 256 bytes
my $img_size=256;

my $mask=0;
my @array;
my @key;
my @result;

my $string = $ARGV[0];
open(OUTFILE, ">$ARGV[1]") || die("\nOutput file open fail\n");

if(length($string) % 2 >0){
   $string="0".$string;
   }

printf("key=%s\n",$string);

my $range = 255;
my $minimum = 0;
my $rand_number;
my $mask='';

my @ascii = unpack("(A2)*", $string);
my $arg;
foreach $arg (@ascii){
   $rand_number = int(rand($range)) + $minimum;
   $arg = hex($arg) ^ $rand_number;
   $rand_number=sprintf("%02x",$rand_number); 
   $mask=$mask.$rand_number;
   $arg=sprintf("%02x",$arg);
}

printf("mask=%s\n",$mask);

my $result_string = pack("(A2)*", @ascii);

printf("result_string=%s\n",$result_string);

printf OUTFILE pack("H*", $result_string);


