#!/usr/bin/perl 
use bignum;
use Getopt::Std;

my $TAG_DEBUG=0x11000000;
my $TAG_REGCFG=0x22000000;
my $TAG_IDWNLD=0x33000000;
my $TAG_CDWNLD=0x44000000;
my $TAG_DWNLD=0x55000000;
my $TAG_IFCFG=0x66000000;
my $TAG_START=0x77000000;
my $TAG_SOCMODE=0x88000000;
my $TAG_CHKSUM=0x99000000;
my $TAG_LQHDR=0xAA000000;

my $FLAG_RST=0x00800000;
my $FLAG_CFG=0x00700000;
my $FLAG_CFG2=0x00400000;
my $FLAG_CFG1=0x00200000;
my $FLAG_CFG0=0x00100000;
my $FLAG_SDBG=0x00080000;
my $FLAG_DBG=0x00040000;
my $FLAG_DEC=0x00020000;
my $FLAG_START=0x00010000;

my $ddr="";
my $input="";
my $output="";
my $jumpaddr=0;
my $socmode=0;

sub usage()
{
   print "mk_sf_image.pl -[options]\n";
   print "   -d  ddrconfig   ddr configuration file\n";
   print "   -i  inputfile   input file\n";
   print "   -o  outputfile  output file\n";
   print "   -j  address     jump address\n";
   print "   -m  mode        soc mode 0/1/2\n"; 
   exit;
}


# declare the perl command line flags/options we want to allow
my %options=();
getopts("d:i:o:j:m:h", \%options);

usage() if $options{h};
 
# test for the existence of the options on the command line.
# in a normal program you'd do more than just print these.
#print "-h $options{h}\n" if defined $options{h};
#print "-j $options{j}\n" if defined $options{j};
#print "-d $options{d}\n" if defined $options{d};
#print "-i $options{i}\n" if defined $options{i};
#print "-o $options{o}\n" if defined $options{o};
#print "-m $options{m}\n" if defined $options{m};
$ddr=$options{d} if defined $options{d};
$input=$options{i} if defined $options{i};
$output=$options{o} if defined $options{o};
$jumpaddr=$options{j} if defined $options{j};
$socmode=$options{m} if defined $options{m};


if($input eq ''){
   print "no input file specified!\n";
   usage();
}

if($output eq ''){
   print "no output file specified!\n";
   usage();
}



open(INFILE2, "<$input") || die("\ninput open fail\n");
open(OUTFILE, ">$output") || die("\nOutput file open fail\n");

if ($ddr){
   open(INFILE1, "<$ddr") || die("\ninput open fail\n");
  
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
}

#form a TAG_DWNLD head
$head=$TAG_DWNLD|$FLAG_SDBG|$FLAG_START;
$head=$head|(0xffff-($head>>16));
$head=sprintf("%08x",$head);
$datafile_size=(-s $input) + 4;
#printf "datafilesize=$datafile_size\n";
$datafile_size=sprintf("%08x",$datafile_size);
$start_address=sprintf("%08x",hex($jumpaddr));
printf OUTFILE pack("H*",$head.$datafile_size.$start_address);
binmode(INFILE2,":raw");
binmode(OUTFILE,":raw");
#while(<INFILE2>){
#  printf OUTFILE $_;
#}
read(INFILE2,$buf,(-s $input));
print OUTFILE $buf;
close(INFILE2);
#********************************************************************************************

open ($INFILE2, $input);
binmode $INFILE2;
$WIDTH = 4;   # number of bytes to read per loop
$packFormat  = "H" . 2 * $WIDTH;  # must use big "H" ie high nibble first
$chksum = 0;
while ( read $INFILE2, $buf, $WIDTH )
{
    $dword = unpack $packFormat, $buf;
    $dword = hex($dword);
    $chksum += $dword;
    $chksum &= 0xFFFFFFFF;
}

# note that tag-length-data format is the basis of bstrap protocol
# length is in bytes

$socmodetag=$TAG_SOCMODE;
$socmodetag=$socmodetag|(0xffff-($socmodetag>>16));
$socmodetag=sprintf("%08x",$socmodetag).sprintf("%08x%08x",0x4,hex($socmode));
printf OUTFILE pack("H*", $socmodetag);

$cstag=$TAG_CHKSUM;
$cstag=$cstag|(0xffff-($cstag>>16));
$cstag=sprintf("%08x",$cstag).sprintf("%08x%08x",0x4,$chksum);
printf OUTFILE pack("H*", $cstag);

$exehead=$TAG_START|$FLAG_SDBG;
$exehead=$exehead|(0xffff-($exehead>>16));
$exehead=sprintf("%08x",$exehead).sprintf("%08x%08x",0x4,hex($jumpaddr));
printf OUTFILE pack("H*", $exehead);




