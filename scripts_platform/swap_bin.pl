#!/usr/bin/perl

if(@ARGV < 2){
     die("\n not enough arguments\n Syntax: ./swap_bin.pl input output\n");
	}
		
open(INFILE, "<$ARGV[0]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[1]") || die("\nOutput file open fail\n");

binmode INFILE;
binmode OUTFILE;


while (read (INFILE, $buffer, 4))
{
   ($b1,$b2,$b3,$b4)=unpack("C*",$buffer);
   
   print OUTFILE pack("C*",$b4);
   print OUTFILE pack("C*",$b3);
   print OUTFILE pack("C*",$b2);
   print OUTFILE pack("C*",$b1);
};

close INFILE;
close OUTFILE;
