#!/usr/bin/perl

# only works on LINUX (not for Windows)
# this perl script does the following:
# 1. copy input file to output file.
# 2. pads output file to filesize 0x8000. 
# 3. add checksum to end of file. 

use strict;
use bigint;

use File::stat;


#********************************************************************************************

$ARGV[0] || go_die();
$ARGV[1] || go_die();

my $infile = $ARGV[0];
my $outfile = $ARGV[1];

my $csum = 0;
my $csum1;

my $stat;

my $zero = 0;

my $OUTPUTFILE;

my $INFILE;
my $WIDTH;
my $packFormat;
my $pack;
my $buf;

my $stat;

#********************************************************************************************


if ($stat = stat $infile) {
    print "$infile is ", $stat->size, " bytes\n";
} else {
    go_die("Can't open $infile for read", 1);
}

open ($INFILE, $infile) || go_die("Can't open $infile fo read",1);

binmode $INFILE;

$WIDTH = 4;   # number of bytes to read per loop
$packFormat  = "H" . 2 * $WIDTH;  # must use big "H" ie high nibble first

# compute U32 addition checksum
while ( read $INFILE, $buf, $WIDTH )
{
    $pack = unpack $packFormat, $buf;

    #$pack = sprintf("%08X", hex($pack));  # change to upper case
    $pack = hex($pack);
    
    $csum += $pack;
    $csum &= 0xFFFFFFFF;
}


system ("cp $infile $outfile");

open ($OUTPUTFILE, ">>$outfile") || go_die("Can't open $outfile for write",1);

binmode $OUTPUTFILE;

my $pad_cnt = $stat->size;

if ($pad_cnt > (0x8000 - 4))
{
    go_die("$infile is too big for MLC image", 1);
}

if ($pad_cnt != 0)
{
    $pad_cnt = 0x8000 - $pad_cnt - 4;
}

$zero = pack("C", $zero);   # note that data is saved in little-endian on Intel-based PC 
while ($pad_cnt > 0)
{
    print $OUTPUTFILE $zero;
    $pad_cnt--;
}

$csum = (($csum & 0x000000FF) << 24) | (($csum & 0x0000FF00) << 8) | (($csum & 0x00FF0000) >> 8) | (($csum & 0xFF000000) >> 24);
$csum = pack("L", $csum);   # note that data is saved in little-endian on Intel-based PC 
print $OUTPUTFILE $csum;

close ($OUTPUTFILE);

if ($stat = stat $outfile) {
    print "$outfile is ", $stat->size, " bytes\n";
} else {
    go_die("Can't open $outfile for read", 1);
}

#********************************************************************************************

sub go_die
{
    my($message, $supressformat) = @_;

    if ($message)
    {
        print "$message";
    }

    close (INFILE);
    close (OUTFILE);

    unless ($supressformat)
    {
        print "format is: \n";
        print " perl mk_mlc_image.pl original.bin mlc.bin\n";
    }
    else
    {
       print "----------------------------------------------------------\n";
    }

    die ("\n");
}

