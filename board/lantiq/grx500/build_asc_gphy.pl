#!/usr/bin/perl
my $aline;
my $lineid;
my $length;
my $address;
my @bytes;
my $addstr;
my $chsum=0;
my $count=0;
my $firstime=1;
my $i;
my $currentaddr;
my $tmp;
my $holder="";
my $loadaddr;
my $socmode;
my $datastr;

if(@ARGV < 5){
	print "\n not enough arguments";
	print "\n Syntax: ./build_asc_gphy.pl <ddr-config> <u-boot.bin> <u-boot-start-addr> <gphy-firmware> <gphy-firmware-addr> <output> <socmode>\n";
}

open(INFILE1, "<$ARGV[0]") || die("\ninput open fail\n");
open(INFILE2, "<$ARGV[1]") || die("\ninput open fail\n");
open(GPHYFILE, "<$ARGV[3]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[5]") || die("\nOutput file open fail\n");
$socmode = hex($ARGV[6]);

binmode INFILE2;
binmode GPHYFILE;

$i=0;
while ($line = <INFILE1>){
            if($line=~/\w/){
	     if($line!~/[;#\*]/){
                  if($i eq 0){
		  printf OUTFILE ("33333333");
		  }
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
		  printf OUTFILE ("%08x%08x",hex($addr),hex($regval));
                  $i=$i+1;
		  if($i eq 8)
		  {
                      $i=0;
		      printf OUTFILE ("\n");
		  }

               }
             }

	    }

        while($i lt 8 && $i gt 0){
            printf OUTFILE "00"x8;
		    $i=$i+1;
		}

###################
# u-boot-gphy.bin #
###################

$i=0;
$addr=$ARGV[2];
$addr=hex($addr);
$loadaddr = sprintf("%x",$addr);

while (read (INFILE2, $buffer, 4))
{
   if(($i % 16) eq 0)
   {
     printf OUTFILE ("\n%08x",$addr);
	 $addrstr = sprintf("%08x", $addr);
     addchsum($addrstr);
     $addr+=0x40;
   }
   $i+=1;
   $data=unpack("H*",$buffer);
   $data=hex($data);
   printf OUTFILE ("%08x",$data);
   $datastr = sprintf("%08x", $data);
   addchsum($datastr);
}

while ( ($i % 16) != 0 )
{
   printf OUTFILE ("%08x",0);
   $i+=1;
}
################
# gphyfirmware #
################

$i=0;
$addr=$ARGV[4];
$addr=hex($addr);

while (read (GPHYFILE, $buffer, 4))
{
   if(($i % 16) eq 0)
   {
     printf OUTFILE ("\n%08x",$addr);
     $addrstr = sprintf("%08x", $addr);
     addchsum($addrstr);
     $addr+=0x40;
   }
   $i+=1;
   $data=unpack("H*",$buffer);
   $data=hex($data);
   printf OUTFILE ("%08x",$data);
   $datastr = sprintf("%08x", $data);
   addchsum($datastr);
}


while ( ($i % 16) != 0 )
{
   printf OUTFILE ("%08x",0);
   $i+=1;
}

printf OUTFILE ("\n");


##############
# SOCMODE_IND
##############
print OUTFILE "55"x4;
$socmode = sprintf("%08X", $socmode);
print OUTFILE $socmode;
print OUTFILE "00"x60;
print OUTFILE "\n";

##############
# CHECKSUM_IND
##############
print OUTFILE "11"x4;
use integer;
$chsum=$chsum & 0xffffffff;
$chsum = sprintf("%X", $chsum);
$chsum = "0"x(8-length($chsum)).$chsum;
$chsum =~tr/ABCDEF/abcdef/;
print OUTFILE $chsum;
print OUTFILE "00"x60;
print OUTFILE "\n";
#print OUTFILE "\r";

##############
# TERMINATING_ADDR
##############
print OUTFILE "99"x4;
print OUTFILE $loadaddr;
#print OUTFILE "00"x60;
$i=0;
if(($socmode eq "00000002") || ($socmode eq "00000001"))
{
   $datafile_size=(-s $ARGV[1]);
   printf OUTFILE ("%08x",$datafile_size);
   $i=1;
}
while ( $i < 15 )
{
   printf OUTFILE ("%08x",0);
   $i+=1;
}
print OUTFILE "\n";
#print OUTFILE "\r";


close OUTFILE;
#END of Program



sub addchsum{
	my $cc=$_[0];
	$holder=$holder.$cc;
	if(length($holder)==8){
		$holder = hex($holder);
		$chsum+=$holder;
		$holder="";
	}
}
#END


