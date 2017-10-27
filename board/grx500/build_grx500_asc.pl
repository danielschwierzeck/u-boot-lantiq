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

if(@ARGV < 3){
	print "\n not enough arguments";
	print "\n Syntax: build_grx500_asc.pl ram.conf data.bin offset u-boot.asc socmode\n";
    exit;
}

open(INFILE1, "<$ARGV[0]") || die("\ninput open fail\n");
open(INFILE2, "<$ARGV[1]") || die("\ninput open fail\n");
open(OUTFILE, ">$ARGV[3]") || die("\nOutput file open fail\n");
$socmode = hex($ARGV[4]);


binmode INFILE2;

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

$i=0;
$addr=$ARGV[2];
$addr=hex($addr);
$chsum=0x0;

while (read (INFILE2, $buffer, 4))
{
   if(($i % 16) eq 0)
   {
     printf OUTFILE ("\n%08x",$addr);
	 $chsum+=$addr;
	 $addr+=0x40;
   }
   $i+=1;
   $data=unpack("H*",$buffer);
   $data=hex($data);
   printf OUTFILE ("%08x",$data);
   $chsum+=$data;
}

while ( ($i % 16) != 0 )
{
   printf OUTFILE ("%08x",0);
   $i+=1;
}


##############
# SOCMODE_IND
##############
print OUTFILE "\n";
print OUTFILE "55"x4;
$socmode = sprintf("%08X", $socmode);
print OUTFILE $socmode;
print OUTFILE "00"x60;

###############
# checksum now
###############
$chsum=$chsum & 0xffffffff;
printf OUTFILE ("\n11111111");
printf OUTFILE ("%08x",$chsum);
$i=0;
while ( $i < 15 )
{
   printf OUTFILE ("%08x",0);
   $i+=1;
}


printf OUTFILE ("\n99999999");

printf OUTFILE ("%08x",hex($ARGV[2]));

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

printf OUTFILE ("\n");

close(INFILE1);
close(INFILE2);
close(OUTFILE);
