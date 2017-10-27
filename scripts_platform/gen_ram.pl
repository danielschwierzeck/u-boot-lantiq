#!/usr/bin/perl
#perl script to generate ram parameters for big nand flash
#Revision history
#7/7/08 Author Wu Qi Ming


open(INFILE1, "<$ARGV[0]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[1]") || die("\nOutput file open fail\n");

$string="";
while ($line = <INFILE1>){
		  chomp($line);
		  $line=~s/\t//;
		  @array=split(/ +/,$line);
		  $addr=@array[0];
	          $regval=@array[1];
		  $string=$string.sprintf("%08x%08x",hex($addr),hex($regval));
}

printf OUTFILE pack("H*",$string);

