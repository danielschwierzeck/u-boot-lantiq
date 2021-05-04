#!/usr/bin/perl
# perl script from binary to C array
# 1-March-2016 Author William Widjaja

use warnings;
use strict;

my $name;
my $buffer;
my $byte;

if(@ARGV < 3){
	print "not enough arguments\n";
    print "Syntax: ./bin2array.pl <input-file> <output-file> <array-name>\n";
	print "example: ./bin2array.pl data.bin output.h data_array\n";
    exit;
}

open(INFILE, "<$ARGV[0]") or die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[1]") or die("\nOutput file open fail\n");
$name = $ARGV[2];

binmode INFILE;
binmode OUTFILE;

print OUTFILE "unsigned char ";
print OUTFILE $name;
print OUTFILE "[]={";

while (read (INFILE, $buffer, 1))
{
    $byte = unpack("H2",$buffer);
   
    print OUTFILE "0x$byte";
   
    if (!eof(INFILE)) {
        print OUTFILE ", ";
	}
   
};

print OUTFILE "};\n";

close INFILE;
close OUTFILE;