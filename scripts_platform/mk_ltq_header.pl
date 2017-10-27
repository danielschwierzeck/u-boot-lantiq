#!/usr/bin/perl 
#perl script to generate lantiq header 
#Revision history
#19/11/2014 Author Wu Qi Ming

#use strict;
use Getopt::Long;

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



sub usage
{
   print "mk_ltq_header.pl --options\n";
   print "      --bch strength         enable bch, strength 8/16/40\n";
   print "      --col col              nand column address cycle\n";
   print "      --row row              nand row address cycle\n";
   print "      --pagesize pagesize    nand page size in bytes\n";
   print "      --blocksize blocksize  nand block size in kbytes \n";
   print "      --offset off1,off2...  offset of images\n";
   print "      --ddr ddrconfig        ddr configuration file\n";
   print "      --out output           output file name\n";
   print "      --gdsnand              gigadevice spi nand\n";
   print "      --help                 show this menu\n";
   exit 0;
}

# setup my defaults
my $bch      = 0;
my $help     = 0;
my $col      = 0;
my $row      = 0;
my $pagesize = 0;
my $blocksize = 0;
my $ddr = "";
my $output = "";
my @offset=();
my $gdsnand = 0;


GetOptions(
    'bch=i' => \$bch,
    'col=i' => \$col,
    'row=i' => \$row,
    'pagesize=s' => \$pagesize,
    'blocksize=s' => \$blocksize,
    'backup=i' => \$backup,
    'ddr=s'    => \$ddr,
    'out=s'    => \$output,
    'offset=s' => \@offset,
    'gdsnand' => \$gdsnand,
    'help!'     => \$help,
) or usage();

if( $help ) {
    usage();
} 

if($ddr eq ''){
   print "no ddr config file specified!\n";
   usage();
}


if($output eq ''){
   print "no output file specified!\n"; 
   usage();
}


if (@offset==0){
   print "no image offset specified!\n";
   usage();
}

if($bch==0){
  $bch=0;
}elsif($bch==8){
  $bch=1;
}elsif($bch==16){
  $bch=3;
}elsif($bch==40){
  $bch=5;
}else{
 print "ecc strenth can only be 8/16/40\n";
 usage();
}


if($pagesize eq '0x200'){
   $pagesize=0;
}elsif($pagesize eq '0x800'){
   $pagesize=1;
}elsif($pagesize eq '0x1000'){
   $pagesize=2;
}elsif($pagesize eq '0x2000'){
   $pagesize=3;
}elsif($pagesize eq '0x4000'){
   $pagesize=4;
}elsif($pagesize eq '0x8000'){
   $pagesize=5;
}elsif($pagesize==0){
   $pagesize=0;
}elsif($pagesize==512){
   $pagesize=0;
}elsif($pagesize==2048){
   $pagesize=1;
}elsif($pagesize==4096){
   $pagesize=2;
}elsif($pagesize==8192){
   $pagesize=3;
}elsif($pagesize==16384){
   $pagesize=4;
}elsif($pagesize==32768){
   $pagesize=5;
}else{
  print "page size must be 512/2048/8192/16384/32768\n";
  usage();
}

if($blocksize eq '0x4000'){
   $blocksize=0;
}elsif($blocksize eq '0x20000'){
   $blocksize=1;
}elsif($blocksize eq '0x40000'){
   $blocksize=2;
}elsif($blocksize eq '0x80000'){
   $blocksize=3;
}elsif($blocksize eq '0x100000'){
   $blocksize=4;
}elsif($blocksize eq '0x200000'){
   $blocksize=5;
}elsif($blocksize==0){
   $blocksize=0;
}elsif($blocksize==16){
   $blocksize=0;
}elsif($blocksize==128){
   $blocksize=1;
}elsif($blocksize==256){
   $blocksize=2;
}elsif($blocksize==512){
   $blocksize=3;
}elsif($blocksize==1024){
   $blocksize=4;
}elsif($blocksize==2048){
   $blocksize=5;
}else{
  print "block size must be 16/128/256/512/1024/2048\n";
  usage();
}


if ($gdsnand==0){
    $gdsnand=1<<5;   
}else{
    $gdsnand=0;
}



open(INFILE1, "<$ddr") || die("\ninput open fail\n");
open(OUTFILE, ">$output") || die("\nOutput file open fail\n");


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

#********************************************************************************************

# note that tag-length-data format is the basis of bstrap protocol
# length is in bytes
my $lnmw='';

$lqmwtag=$TAG_LQHDR;
$lqmwtag=$lqmwtag|(0xffff-($lqmwtag>>16));
@offset = split(/,/,join(',',@offset));

$lqmwtag=sprintf("%08x",$lqmwtag);
$lqmwtag=$lqmwtag.sprintf("%08x",20);
$lqmwtag=$lqmwtag.sprintf("%02x",scalar(@offset));
$byte=$pagesize|($blocksize<<4);
$lqmwtag=$lqmwtag.sprintf("%02x",$byte);
$byte=$gdsnand|(($bch>0?1:0)<<4)|(($col>0?($col-1):0)<<2)|($row>0?($row-1):0);
$lqmwtag=$lqmwtag.sprintf("%02x%02x",$bch,$byte);

my $i=0;
for ($i=0; $i<scalar(@offset); $i++) {
    $lqmwtag=$lqmwtag.sprintf("%08x",hex($offset[$i]));
}

for($i=0;$i<4-scalar(@offset);$i++){
    $lqmwtag=$lqmwtag.sprintf("%08x",0);
}

#print "lqmwtag=$lqmwtag\n";
printf OUTFILE pack("H*", $lqmwtag);


$exehead=$TAG_START|$FLAG_SDBG;
$exehead=$exehead|(0xffff-($exehead>>16));
$exehead=sprintf("%08x",$exehead).sprintf("%08x%08x",0x4,0);
printf OUTFILE pack("H*", $exehead);

close(INFILE1);
close(OUTFILE);



