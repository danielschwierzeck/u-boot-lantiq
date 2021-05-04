#!/usr/bin/perl
#perl script to generate spi bootable u-boot using binary file
#Revision history
#1/7/2009 Author Wu Qi Ming

my $TAG_DEBUG=0x11000000;
my $TAG_REGCFG=0x22000000;
my $TAG_IDWNLD=0x33000000;
my $TAG_CDWNLD=0x44000000;
my $TAG_DWNLD=0x55000000;
my $TAG_IFCFG=0x66000000;
my $TAG_START=0x77000000;

my $FLAG_RST=0x00800000;
my $FLAG_CFG=0x00700000;
my $FLAG_CFG2=0x00400000;
my $FLAG_CFG1=0x00200000;
my $FLAG_CFG0=0x00100000;
my $FLAG_SDBG=0x00080000;
my $FLAG_DBG=0x00040000;
my $FLAG_DEC=0x00020000;
my $FLAG_START=0x00010000;



if(@ARGV < 2){
	print "not enough arguments\n";
	print "Syntax: ./mk_sf.pl config data address output\n";
	print "example: ./mk_sf.pl ram.conf u-boot.ifx 0xa0100000 u-boot.sflash\n";
	exit;
}
print "converting now, please wait...\n";

open(INFILE1, "<$ARGV[0]") || die("\ninput open fail\n");
open(INFILE2, "<$ARGV[1]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[3]") || die("\nOutput file open fail\n");

#form a REGCFG head
$head=$TAG_REGCFG|$FLAG_SDBG|$FLAG_DBG;
$head=$head|(0xffff-($head>>16));

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

$head=sprintf("%08x",$head).sprintf("%08x",$count*8);
printf OUTFILE pack("H*",$head.$string);

#form a TAG_DWNLD head
$head=$TAG_DWNLD|$FLAG_SDBG|$FLAG_START;
$head=$head|(0xffff-($head>>16));
$head=sprintf("%08x",$head);
$datafile_size=(-s $ARGV[1]) + 4;
#printf "datafilesize=$datafile_size\n";
$datafile_size=sprintf("%08x",$datafile_size);
$start_address=sprintf("%08x",hex($ARGV[2]));
printf OUTFILE pack("H*",$head.$datafile_size.$start_address);
binmode(INFILE2,":raw");
binmode(OUTFILE,":raw");
#while(<INFILE2>){
#  printf OUTFILE $_;
#}
read(INFILE2,$buf,(-s $ARGV[1]));
print OUTFILE $buf;

$exehead=$TAG_START|$FLAG_SDBG;
$exehead=$exehead|(0xffff-($exehead>>16));
$exehead=sprintf("%08x",$exehead).sprintf("%08x%08x",0x4,hex($ARGV[2]));

printf OUTFILE pack("H*", $exehead);
