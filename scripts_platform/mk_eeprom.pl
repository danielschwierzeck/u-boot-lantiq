#!/usr/bin/perl
#perl script to generate an bootable image for eeprom
#Revision history
#03/27/08 Author Wu Qi Ming

my $SPI_MAGIC=0xAA55;
my $PHY1=0x1;
my $PHY0=0x0;
my $MAC0=0x2c;
my $MAC1=0x02;
my $MAC2=0x00;
my $MAC3=0x92;
my $MAC4=0xe0;
my $MAC5=0x00;
my $VALID=0x1; #always valid
my $OFFSET=0x0c;

if(@ARGV < 2){
	print "not enough arguments\n";
    print "Syntax: ./mk_eeprom.pl config data address output\n";
	print "example: ./mk_eeprom.pl ram.conf u-boot.ifx 0xa0100000 u-boot.eeprom\n";
    exit;
}
print "converting now, please wait...\n";

open(INFILE1, "<$ARGV[0]") || die("\ninput open fail\n");
open(INFILE2, "<$ARGV[1]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[3]") || die("\nOutput file open fail\n");

#form a REGCFG head
$head=sprintf("%08x",($SPI_MAGIC<<16)|($PHY1<<8)|($PHY0));
$head=$head.sprintf("%08x",($MAC3<<24)|($MAC2<<16)|($MAC1<<8)|($MAC0));
$head=$head.sprintf("%08x",($OFFSET<<24)|($VALID<<16)|($MAC5)|($MAC4));
printf OUTFILE pack("H*",$head);
$string="";
$count=0;
while ($line = <INFILE1>){
            if($line=~/\w/){
	     if($line!~/[;#\*]/){
		  chomp($line);
		  $line=~s/\t//;
		  @array=split(/ +/,$line);
                  $j=0;
		  while(@array[$j]!~/\w/)
		  {
                    $j=$j+1;
		  }
		  $addr=@array[$j];
	          $regval=@array[$j+1];
                  $addr=~s/0x//;
                  $regval=~s/0x//;
		  $string=$string.sprintf("%08x%08x",hex($addr),hex($regval));
                  $count=$count+1;
               }
             }
}


printf OUTFILE pack("H*",$string);


$datafile_size=(-s $ARGV[1]);
$datafile_size=sprintf("%08x",$datafile_size/4);
$start_address=sprintf("%08x",hex($ARGV[2])+1);
printf OUTFILE pack("H*",$start_address.$datafile_size);

binmode(INFILE2,":raw");
binmode(OUTFILE,":raw");

read(INFILE2,$buf,(-s $ARGV[1]));
print OUTFILE $buf;

$exehead=sprintf("%08x",0xffffffff);
$start_address=sprintf("%08x",hex($ARGV[2]));

printf OUTFILE pack("H*", $exehead.$start_address);

