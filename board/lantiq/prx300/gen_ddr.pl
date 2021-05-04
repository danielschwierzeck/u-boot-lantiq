#!/usr/bin/perl 
use strict;
use Getopt::Std;



my $i=0;
my $output="";
my $DDR_TYPE=3;
my $DDR_GRADE=7;
my $DDR_DENSITY=10;
my $DDR_BLEN=8;
my $DDR_AL=1;
my $endianval=1;

my $A_CPS_F=2;
my $A_Share_Link_F=8;
my $A_NGI_TEP_F=6;
my $A_CBM_F=3;
my $B_CPS_F=1;
my $B_DDR_Controller_F=5;
my $B_GSWIP_L_F=5;
my $B_GSWIP_RMII=6;







#post silicon =2
#haps=1
#palladium =0
my $platform=2;

my @ddr2_chips = (1,2,1,2,1,2,1,2,1,2);
my @ddr2_banks = (4,4,4,4,8,8,8,8,8,8);
my @ddr2_rows  = (13,13,13,14,13,14,14,15,15,16);
my @ddr2_cols  = (9,10,10,10,10,10,10,10,10,10);
my @ddr2_pagesize = (1,1,2,1,2,1,2,1,2,1);
my @ddr2_MM_SWAP0_H = (0x11634c,	0x117,	0x117,	0xd9,	0,	0,	0,	0,	0,	0);
my @ddr2_MM_SWAP0_L = (0x016c420a,	0x0d30324b,	0x0d30324b,	0x0f30324b,	0x0461128b,	0x0369228b,	0x0369228b,	0x0271328b,	0x0271328b,	0x01428b);
my @ddr2_freq = (200,0,266,0,333,333,400,400,0,533);
my @ddr2_TFAW_CFG = (5,0,5,0,5,5,5,5,0,4);
my @ddr2_TFAW_CFG_OFF = (0,0,1,0,3,3,2,2,0,0);
my @ddr2_TCL = (3,0,4,0,4,5,5,6,0,7);
my @ddr2_TWR = (3,0,4,0,5,5,6,6,0,8);
my @ddr2_TRC = (11,0,16,0,19,20,23,24,0,31);
my @ddr2_TRRD = (2,0,3,0,4,4,4,4,0,6);
my @ddr2_TRAS = (8,0,12,0,15,15,18,18,0,24);
my @ddr2_TRTP = (2,0,2,0,3,3,3,3,0,4);
my @ddr2_TRFC = (66,0,88,0,109,109,131,131,0,175);
my @ddr2_TFAW = (10,0,14,0,17,17,18,18,0,24);
my @ddr2_TXP = (5,0,7,0,8,8,10,10,0,13);






my @ddr3_chips = (0,0,1,2,1,2,1,2,1,2,1);
my @ddr3_banks = (0,0,8,8,8,8,8,8,8,8,8);
my @ddr3_rows  = (0,0,12,13,13,14,14,15,15,16,16);
my @ddr3_cols  = (0,0,10,10,10,10,10,10,10,10,10);
my @ddr3_pagesize = (0,0,2,1,2,1,2,1,2,1,2);
my @ddr3_MM_SWAP0_H = (0,0,0,0,0,0,0,0,0,0,0);
my @ddr3_MM_SWAP0_L = (0,0,0x0559028b,	0x0461128b,	0x0461128b,	0x0369228b,	0x0369228b,	0x0271328b,	0x0271328b,	0x01428b,	0x01428b);
my @ddr3_freq = (400,400,533,533,533,667,667,667,800,800,800);
my @ddr3_TFAW_CFG = (5,5,5,5,5,6,6,6,6,6,6);
my @ddr3_TFAW_CFG_OFF = (0,0,3,3,3,0,0,0,1,1,1);
my @ddr3_TCL = (5,6,6,7,8,8,9,10,9,10,11);
my @ddr3_TWR = (6,6,8,8,8,10,10,10,12,12,12);
my @ddr3_TRC = (20,21,26,27,28,32,33,34,37,38,39);
my @ddr3_TRRD = (4,4,6,6,6,5,5,5,6,6,6);
my @ddr3_TRAS = (15,15,20,20,20,24,24,24,28,28,28);
my @ddr3_TRTP = (4,4,5,5,5,5,5,5,6,6,6);
my @ddr3_TRFC = (140,140,187,187,187,234,234,234,280,280,280);
my @ddr3_TFAW = (20,20,27,27,27,30,30,30,32,32,32);
my @ddr3_TXS = (144,144,193,193,193,240,240,240,288,288,288);
my @ddr3_TXP = (10,10,13,13,13,16,16,16,20,20,20);




sub usage()
{
   print "gen_ddr.pl -[options]\n";
   print "   -t  type          ddr type 2/3\n";
   	print "\t 2 ddr2\n";
   	print "\t 3 ddr3\n";
   print "   -g  grade         ddr grade\n";
    print "	\t ddr2grade	# \n";
    print "	\t 200MHz @ CL=3	0\n";
    print "	\t 266MHz @ CL=4	2\n";
    print "	\t 333MHz @ CL=4	4\n";
    print "	\t 333MHz @ CL=5	5\n";
    print "	\t 400MHz @ CL=5	6\n";
    print "	\t 400MHz @ CL=6	7\n";
    print "	\t 533MHz @ CL=7	9\n";

    print "	\t ddr3grade	#\n";
    print "	\t 400MHz @ CL=5	0\n";
    print "	\t 400MHz @ CL=6	1\n";
    print "	\t 533MHz @ CL=6	2\n";
    print "	\t 533MHz @ CL=7	3\n";
    print "	\t 533MHz @ CL=8	4\n";
    print "	\t 667MHz @ CL=8	5\n";
    print "	\t 667MHz @ CL=9	6\n";
    print "	\t 667MHz @ CL=10	7\n";
    print "	\t 800MHz @ CL=9	8\n";
    print "	\t 800MHz @ CL=10	9\n";
    print "	\t 800MHz @ CL=11	10\n";
	
     
   print "   -d  density       ddr density\n";

    print "	\t dd2density	#\n";
    print "	\t 16Mx16		0\n";
    print "	\t 32Mx8		1\n";
    print "	\t 32Mx16		2\n";
    print "	\t 64Mx8		3\n";
    print "	\t 64Mx16		4\n";
    print "	\t 128Mx8		5\n";
    print "	\t 128Mx16	6\n";
    print "	\t 256Mx8		7\n";
    print "	\t 256Mx16	8\n";
    print "	\t 512Mx8		9\n";

    print "	\t dd3density	#\n";
    print "	\t 32Mx16		2\n";
    print "	\t 64Mx8		3\n";
    print "	\t 64Mx16		4\n";
    print "	\t 128Mx8		5\n";
    print "	\t 128Mx16	6\n";
    print "	\t 256Mx8		7\n";
    print "	\t 256Mx16	8\n";
    print "	\t 512Mx8		9\n";
    print "	\t 512Mx16	10\n";


   
   print "   -b  length        burst length\n";
    print "	\t BL4	4\n";
    print "	\t BL8	8\n";



   print "   -l  latency       additive latency\n";
    print "	\t ddr2 	#\n";
    print "	\t AL=0	0\n";
    print "	\t AL=1	1\n";
    print "	\t AL=2	2\n";
    print "	\t AL=3	3\n";
    print "	\t AL=4	4\n";
    print "	\t AL=5	5\n";
    print "	\t AL=6	6\n";

    print "	\t ddr3 	#\n";
    print "	\t N0 AL	0\n";
    print "	\t CL-1	1\n";
    print "	\t CL-2	2\n";


   
   print "   -e  endian        endianness(B/L)\n";
    print "	\t Little Endian	0\n";
    print "	\t Big Endian	1\n";

      
      
   print "   -o  output        output file\n"; 
   print "   -h                help information\n";

   print "\n\t|--------------------------------------|\n";
   print "\t|---------- PLL0A Settings ------------|\n";
   print "\t|--------------------------------------|\n";
   print "   -cps              PLL0A CK4 - CPS    \n";
   print "   -share            PLL0A CK3 - Share Link    \n";
   print "   -ngi              PLL0A CK2 - NGI/TEP    \n";
   print "   -cbm              PLL0A CK1 - CBM     \n";

   print "\t   Frequency settings for all pll0a configurations	#   \n";
   print "\t   2400MHz	0   \n";
   print "\t   1200MHz	1   \n";
   print "\t   800MHz	2   \n";
   print "\t   600MHz	3   \n";
   print "\t   480MHz	4   \n";
   print "\t   400MHz	5   \n";
   print "\t   300MHz	6   \n";
   print "\t   240MHz	7   \n";
   print "\t   200MHz	8   \n";
   print "\t   150MHz	9   \n";
   print "\t   120MHz	10   \n";
   print "\t   100MHz	11   \n";
   print "\t   75MHz	12   \n";
   print "\t   60MHz	13   \n";
   print "\t   50MHz	14   \n";
   print "\t   37.5MHz	15   \n";
   

   print "\n\t|--------------------------------------|\n";
   print "\t|---------- PLL0B Settings ------------|\n";
   print "\t|--------------------------------------|\n";
   print "   -bc            PLL0B CK4 - CPS    \n";
   print "   -bd            PLL0B CK3 - DDR Controller    \n";
   print "   -bg            PLL0B CK2 - GSWIP-L    \n";
   print "   -bgr           PLL0B CK1 - GSWIP-R/MII     \n";
   
   print "\t    Frequency settings for all pll0b	configurations	#   \n";
   print "\t    2000MHz	0   \n";
   print "\t    1000MHz	1   \n";
   print "\t    666MHz	2   \n";
   print "\t    500MHz	3   \n";
   print "\t    400MHz	4   \n";
   print "\t    333MHz	5   \n";
   print "\t    250MHz	6   \n";
   print "\t    200MHz	7   \n";
   print "\t    166MHz	8   \n";
   print "\t    125MHz	9   \n";
   print "\t    100MHz	10   \n";
   print "\t    83MHz	11   \n";
   print "\t    62.5MHz	12   \n";
   print "\t    50MHz	13   \n";
   print "\t    41.6MHz	14   \n";
   print "\t    51.25MHz	15   \n";

   exit;
}




# declare the perl command line flags/options we want to allow
my %options=();
getopts("t:g:d:b:a:e:o:h:c:s:n:m:p:k:l:r:", \%options);

usage() if $options{h};


$output=$options{o} if defined $options{o};
$DDR_TYPE=$options{t} if defined $options{t};
$DDR_GRADE=$options{g} if defined $options{g};
$DDR_DENSITY=$options{d} if defined $options{d};
$DDR_BLEN=$options{b} if defined $options{b};
$DDR_AL=$options{a} if defined $options{a};
$endianval=$options{e} if defined $options{e};

#PLL0A_CFG1
$A_CPS_F=$options{c} if defined $options{c};
$A_Share_Link_F=$options{s} if defined $options{s};
$A_NGI_TEP_F=$options{n} if defined $options{n};
$A_CBM_F=$options{m} if defined $options{m};

#PLL0B_CFG1
$B_CPS_F=$options{p} if defined $options{p};
$B_DDR_Controller_F=$options{k} if defined $options{k};
$B_GSWIP_L_F=$options{l} if defined $options{l};
$B_GSWIP_RMII=$options{r} if defined $options{r};




if($output eq ''){
   print "no output file specified!\n";
   usage();
}

if ($DDR_TYPE=~/2|DDR2|ddr2/){
   $DDR_TYPE=2;

	if ($DDR_GRADE=~/0|2|4|5|6|7|9/)
	{

	}
	else
	{
	print "parameters are invalid.\n";
   	print "   -g  grade         ddr grade\n";
    print "	\t ddr2grade	# \n";
    print "	\t 200MHz @ CL=3	0\n";
    print "	\t 266MHz @ CL=4	2\n";
    print "	\t 333MHz @ CL=4	4\n";
    print "	\t 333MHz @ CL=5	5\n";
    print "	\t 400MHz @ CL=5	6\n";
    print "	\t 400MHz @ CL=6	7\n";
    print "	\t 533MHz @ CL=7	9\n";
    exit;
	}

	if ($DDR_DENSITY=~/0|1|2|3|4|5|6|7|8|9/)
	{

	}
	else
	{
   print "   -d  density       ddr density\n";

    print "	\t dd2density	#\n";
    print "	\t 16Mx16		0\n";
    print "	\t 32Mx8		1\n";
    print "	\t 32Mx16		2\n";
    print "	\t 64Mx8		3\n";
    print "	\t 64Mx16		4\n";
    print "	\t 128Mx8		5\n";
    print "	\t 128Mx16	6\n";
    print "	\t 256Mx8		7\n";
    print "	\t 256Mx16	8\n";
    print "	\t 512Mx8		9\n";

    exit;
	}


	if ($DDR_BLEN=~/4|8/)
	{

	}
	else
	{
   print "   -b  length        burst length\n";
    print "	\t BL4	4\n";
    print "	\t BL8	8\n";
    exit;
	}


	if ($DDR_AL=~/0|1|2|3|4|5|6/)
	{

	}
	else
	{
   print "   -a  latency       additive latency\n";
    print "	\t ddr2 	#\n";
    print "	\t AL=0	0\n";
    print "	\t AL=1	1\n";
    print "	\t AL=2	2\n";
    print "	\t AL=3	3\n";
    print "	\t AL=4	4\n";
    print "	\t AL=5	5\n";
    print "	\t AL=6	6\n";


    exit;
	}


	if ($endianval=~/0|1/)
	{

	}
	else
	{
   print "   -e  endian        endianness(B/L)\n";
    print "	\t Little Endian	0\n";
    print "	\t Big Endian	1\n";

    exit;
	}

}elsif ($DDR_TYPE=~/3|DDR3|ddr3/){
   $DDR_TYPE=3;

	if ($DDR_GRADE=~/0|1|2|3|4|5|6|7|8|9|10/)
	{

	}
	else
	{
	print "parameters are invalid.\n";
   	print "   -g  grade         ddr grade\n";
    print "	\t ddr3grade	#\n";
    print "	\t 400MHz @ CL=5	0\n";
    print "	\t 400MHz @ CL=6	1\n";
    print "	\t 533MHz @ CL=6	2\n";
    print "	\t 533MHz @ CL=7	3\n";
    print "	\t 533MHz @ CL=8	4\n";
    print "	\t 667MHz @ CL=8	5\n";
    print "	\t 667MHz @ CL=9	6\n";
    print "	\t 667MHz @ CL=10	7\n";
    print "	\t 800MHz @ CL=9	8\n";
    print "	\t 800MHz @ CL=10	9\n";
    print "	\t 800MHz @ CL=11	10\n";
    exit;
	}

	if ($DDR_DENSITY=~/2|3|4|5|6|7|8|9|10/)
	{

	}
	else
	{
   print "   -d  density       ddr density\n";
    print "	\t dd3density	#\n";
    print "	\t 32Mx16		2\n";
    print "	\t 64Mx8		3\n";
    print "	\t 64Mx16		4\n";
    print "	\t 128Mx8		5\n";
    print "	\t 128Mx16	6\n";
    print "	\t 256Mx8		7\n";
    print "	\t 256Mx16	8\n";
    print "	\t 512Mx8		9\n";
    print "	\t 512Mx16	10\n";


    exit;
	}

	if ($DDR_BLEN=~/4|8/)
	{

	}
	else
	{
   print "   -b  length        burst length\n";
    print "	\t BL4	4\n";
    print "	\t BL8	8\n";
    exit;
	}

	if ($DDR_AL=~/0|1|2/)
	{

	}
	else
	{
   print "   -a  latency       additive latency\n";
    print "	\t ddr3 	#\n";
    print "	\t N0 AL	0\n";
    print "	\t CL-1	1\n";
    print "	\t CL-2	2\n";

    exit;
	}

	if ($endianval=~/0|1/)
	{

	}
	else
	{
   print "   -e  endian        endianness(B/L)\n";
    print "	\t Little Endian	0\n";
    print "	\t Big Endian	1\n";

    exit;
	}


   
}else{
   usage();
   exit;
}

	if ($A_CPS_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -c should be within range of 0 to 15.\n";
		print " \t 2400Mhz		0\n";
		print " \t 1200Mhz		1\n";
		print " \t 800Mhz		2\n";
		print " \t 600Mhz		3\n";
		print " \t 480Mhz		5\n";
		print " \t 400Mhz		5\n";
		print " \t 300Mhz		6\n";
		print " \t 240Mhz		7\n";
		print " \t 200Mhz		8\n";
		print " \t 150hz		9\n";
		print " \t 120hz		10\n";
		print " \t 100Mhz		11\n";
		print " \t 75Mhz		12\n";
		print " \t 60Mhz		13\n";
		print " \t 50Mhz		14\n";
   		print " \t 37Mhz		15\n";

    exit;
	}

	if ($A_Share_Link_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -s should be within range of 0 to 15.\n";
		print " \t 2400Mhz		0\n";
		print " \t 1200Mhz		1\n";
		print " \t 800Mhz		2\n";
		print " \t 600Mhz		3\n";
		print " \t 480Mhz		5\n";
		print " \t 400Mhz		5\n";
		print " \t 300Mhz		6\n";
		print " \t 240Mhz		7\n";
		print " \t 200Mhz		8\n";
		print " \t 150hz		9\n";
		print " \t 120hz		10\n";
		print " \t 100Mhz		11\n";
		print " \t 75Mhz		12\n";
		print " \t 60Mhz		13\n";
		print " \t 50Mhz		14\n";
   		print " \t 37Mhz		15\n";

    exit;
	}

	if ($A_NGI_TEP_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -n should be within range of 0 to 15.\n";
		print " \t 2400Mhz		0\n";
		print " \t 1200Mhz		1\n";
		print " \t 800Mhz		2\n";
		print " \t 600Mhz		3\n";
		print " \t 480Mhz		5\n";
		print " \t 400Mhz		5\n";
		print " \t 300Mhz		6\n";
		print " \t 240Mhz		7\n";
		print " \t 200Mhz		8\n";
		print " \t 150hz		9\n";
		print " \t 120hz		10\n";
		print " \t 100Mhz		11\n";
		print " \t 75Mhz		12\n";
		print " \t 60Mhz		13\n";
		print " \t 50Mhz		14\n";
   		print " \t 37Mhz		15\n";

    exit;
	}

	if ($A_CBM_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -m should be within range of 0 to 15.\n";
		print " \t 2400Mhz		0\n";
		print " \t 1200Mhz		1\n";
		print " \t 800Mhz		2\n";
		print " \t 600Mhz		3\n";
		print " \t 480Mhz		5\n";
		print " \t 400Mhz		5\n";
		print " \t 300Mhz		6\n";
		print " \t 240Mhz		7\n";
		print " \t 200Mhz		8\n";
		print " \t 150hz		9\n";
		print " \t 120hz		10\n";
		print " \t 100Mhz		11\n";
		print " \t 75Mhz		12\n";
		print " \t 60Mhz		13\n";
		print " \t 50Mhz		14\n";
   		print " \t 37Mhz		15\n";

    exit;
	}

	if ($B_CPS_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -p should be within range of 0 to 15.\n";
		print " \t 2000Mhz		0\n";
		print " \t 1000Mhz		1\n";
		print " \t 666Mhz		2\n";
		print " \t 500Mhz		3\n";
		print " \t 400Mhz		5\n";
		print " \t 333Mhz		5\n";
		print " \t 250Mhz		6\n";
		print " \t 200Mhz		7\n";
		print " \t 166Mhz		8\n";
		print " \t 125hz		9\n";
		print " \t 100hz		10\n";
		print " \t 83Mhz		11\n";
		print " \t 62.5Mhz		12\n";
		print " \t 50Mhz		13\n";
		print " \t 41.6Mhz		14\n";
   		print " \t 51.25Mhz		15\n";

    exit;
	}

	if ($B_DDR_Controller_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -k should be within range of 0 to 15.\n";
		print " \t 2000Mhz		0\n";
		print " \t 1000Mhz		1\n";
		print " \t 666Mhz		2\n";
		print " \t 500Mhz		3\n";
		print " \t 400Mhz		5\n";
		print " \t 333Mhz		5\n";
		print " \t 250Mhz		6\n";
		print " \t 200Mhz		7\n";
		print " \t 166Mhz		8\n";
		print " \t 125hz		9\n";
		print " \t 100hz		10\n";
		print " \t 83Mhz		11\n";
		print " \t 62.5Mhz		12\n";
		print " \t 50Mhz		13\n";
		print " \t 41.6Mhz		14\n";
   		print " \t 51.25Mhz		15\n";

    exit;
	}

	if ($B_GSWIP_L_F=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -l should be within range of 0 to 15.\n";
		print " \t 2000Mhz		0\n";
		print " \t 1000Mhz		1\n";
		print " \t 666Mhz		2\n";
		print " \t 500Mhz		3\n";
		print " \t 400Mhz		5\n";
		print " \t 333Mhz		5\n";
		print " \t 250Mhz		6\n";
		print " \t 200Mhz		7\n";
		print " \t 166Mhz		8\n";
		print " \t 125hz		9\n";
		print " \t 100hz		10\n";
		print " \t 83Mhz		11\n";
		print " \t 62.5Mhz		12\n";
		print " \t 50Mhz		13\n";
		print " \t 41.6Mhz		14\n";
   		print " \t 51.25Mhz		15\n";

    exit;
	}

	if ($B_GSWIP_RMII=~/0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15/)
	{

	}
	else
	{
   		print "  -r should be within range of 0 to 15.\n";
		print " \t 2000Mhz		0\n";
		print " \t 1000Mhz		1\n";
		print " \t 666Mhz		2\n";
		print " \t 500Mhz		3\n";
		print " \t 400Mhz		5\n";
		print " \t 333Mhz		5\n";
		print " \t 250Mhz		6\n";
		print " \t 200Mhz		7\n";
		print " \t 166Mhz		8\n";
		print " \t 125hz		9\n";
		print " \t 100hz		10\n";
		print " \t 83Mhz		11\n";
		print " \t 62.5Mhz		12\n";
		print " \t 50Mhz		13\n";
		print " \t 41.6Mhz		14\n";
   		print " \t 51.25Mhz		15\n";

    exit;
	}

sub get_DDR_TFAW_CFG_OFF {
	if ($DDR_TYPE==2) {
		if ($DDR_GRADE < 2) {
			return (($DDR_DENSITY<2)?2:(($DDR_DENSITY%2)==0)?0:2);
		}
		elsif ($DDR_GRADE < 4) {
			return (($DDR_DENSITY<2)?0:(($DDR_DENSITY%2)==0)?1:0);
		}
		elsif ($DDR_GRADE < 6) {
			return (($DDR_DENSITY<2)?2:(($DDR_DENSITY%2)==0)?3:2);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<2)?1:(($DDR_DENSITY%2)==0)?2:1);
		}
		else {
			return (($DDR_DENSITY<2)?1:(($DDR_DENSITY%2)==0)?0:1);
		}
	} else {
		if ($DDR_GRADE < 2) {
			return 0;
		}
		elsif ($DDR_GRADE < 5) {
			return (($DDR_DENSITY>9)?3:(($DDR_DENSITY%2)==0)?3:0);
		}
		elsif ($DDR_GRADE < 8) {
			return 0;
		}
		else {
			return (($DDR_DENSITY>9)?4:(($DDR_DENSITY%2)==0)?4:1);
		}
	}
}

sub get_TRRD {
	if ($DDR_TYPE==2) {
		if ($DDR_GRADE < 2) {
			return 2;
		} 
		elsif ($DDR_GRADE < 4) {
			return (($DDR_DENSITY<2)?2:(($DDR_DENSITY%2)==0)?3:2);
		}
		elsif ($DDR_GRADE < 6) {
			return (($DDR_DENSITY<2)?3:(($DDR_DENSITY%2)==0)?4:3);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<2)?3:(($DDR_DENSITY%2)==0)?4:3);
		} 
		else {
			return (($DDR_DENSITY<2)?4:(($DDR_DENSITY%2)==0)?6:4);
		}
	} 
	else {
		if ($DDR_GRADE < 2) {
			return 4;
		}
		elsif ($DDR_GRADE < 5) {
			return (($DDR_DENSITY>9)?6:(($DDR_DENSITY%2)==0)?6:4);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY>9)?5:(($DDR_DENSITY%2)==0)?5:4);
		}
		else {
			return (($DDR_DENSITY>9)?6:(($DDR_DENSITY%2)==0)?6:5);
		}
	}
}

sub get_TRFC {
	if ($DDR_TYPE==2) {
		if ($DDR_GRADE < 2) {
			return (($DDR_DENSITY<2)?15:(($DDR_DENSITY<4)?21:(($DDR_DENSITY<6)?26:(($DDR_DENSITY<8)?39:66))));
		}
		elsif ($DDR_GRADE < 4) {
			return (($DDR_DENSITY<2)?20:(($DDR_DENSITY<4)?28:(($DDR_DENSITY<6)?34:(($DDR_DENSITY<8)?52:88))));
		}
		elsif ($DDR_GRADE < 6) {
			return (($DDR_DENSITY<2)?25:(($DDR_DENSITY<4)?35:(($DDR_DENSITY<6)?43:(($DDR_DENSITY<8)?65:109))));
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<2)?30:(($DDR_DENSITY<4)?42:(($DDR_DENSITY<6)?51:(($DDR_DENSITY<8)?78:131))));
		}
		else {
			return (($DDR_DENSITY<2)?40:(($DDR_DENSITY<4)?57:(($DDR_DENSITY<6)?68:(($DDR_DENSITY<8)?102:175))));
		}
	} 
	else {
		if ($DDR_GRADE < 2) {
			return (($DDR_DENSITY<4)?36:(($DDR_DENSITY<6)?44:(($DDR_DENSITY<8)?64:(($DDR_DENSITY<10)?104:140))));
		}
		elsif ($DDR_GRADE < 5) {
			return (($DDR_DENSITY<4)?48:(($DDR_DENSITY<6)?59:(($DDR_DENSITY<8)?86:(($DDR_DENSITY<10)?139:187))));
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<4)?60:(($DDR_DENSITY<6)?74:(($DDR_DENSITY<8)?107:(($DDR_DENSITY<10)?174:234))));
		}
		else {
			return (($DDR_DENSITY<4)?72:(($DDR_DENSITY<6)?88:(($DDR_DENSITY<8)?128:(($DDR_DENSITY<10)?208:280))));
		}
	}
}

sub get_TFAW {
	if ($DDR_TYPE==2) {
		if ($DDR_GRADE < 2) {
			return (($DDR_DENSITY<2)?8:(($DDR_DENSITY%2)==0)?10:8);
		}
		elsif ($DDR_GRADE < 4) {
			return (($DDR_DENSITY<2)?10:(($DDR_DENSITY%2)==0)?14:10);
		}
		elsif ($DDR_GRADE < 6) {
			return (($DDR_DENSITY<2)?13:(($DDR_DENSITY%2)==0)?17:13);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<2)?14:(($DDR_DENSITY%2)==0)?18:14);
		}
		else {
			return (($DDR_DENSITY<2)?19:(($DDR_DENSITY%2)==0)?24:19);
		}
	} 
	else {
		if ($DDR_GRADE < 2) {
			return ((($DDR_DENSITY%2)==0)?20:16);
		}
		elsif ($DDR_GRADE < 5) {
			return (($DDR_DENSITY>9)?27:(($DDR_DENSITY%2)==0)?27:20);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY>9)?30:(($DDR_DENSITY%2)==0)?30:20);
		}
		else {
			return (($DDR_DENSITY>9)?32:(($DDR_DENSITY%2)==0)?32:24);
		}
	}
}

sub get_DDR_TXS {
	if ($DDR_TYPE==2) {
		return 200;
	} 
	else {
		if ($DDR_GRADE < 2) {
			return (($DDR_DENSITY<4)?40:($DDR_DENSITY<6)?48:($DDR_DENSITY<8)?68:($DDR_DENSITY<10)?108:144);
		}
		elsif ($DDR_GRADE < 5) {
			return (($DDR_DENSITY<4)?54:($DDR_DENSITY<6)?65:($DDR_DENSITY<8)?72:($DDR_DENSITY<10)?145:193);
		}
		elsif ($DDR_GRADE < 8) {
			return (($DDR_DENSITY<4)?66:($DDR_DENSITY<6)?80:($DDR_DENSITY<8)?113:($DDR_DENSITY<10)?180:240);
		}
		else {
			return (($DDR_DENSITY<4)?80:($DDR_DENSITY<6)?96:($DDR_DENSITY<8)?136:($DDR_DENSITY<10)?216:288);
		}
	}
}

my $DDR2_TFAW_CFG=(($DDR_GRADE<8)?5:(($DDR_DENSITY<2)?5:((($DDR_DENSITY % 2)==0)?4:5)));
my $DDR3_TFAW_CFG=(($DDR_GRADE<3)?((($DDR_DENSITY%2)==0)?5:4):(($DDR_GRADE<5)?5:(($DDR_DENSITY>9)?6:((($DDR_DENSITY%2)==0)?6:5))));

my $chip=($DDR_TYPE==2)?$ddr2_chips[$DDR_DENSITY]:$ddr3_chips[$DDR_DENSITY];
my $DDR_BANKSZ=($DDR_TYPE==2)?$ddr2_banks[$DDR_DENSITY]:$ddr3_banks[$DDR_DENSITY];
my $ddr_freq=($DDR_TYPE==2)?$ddr2_freq[$DDR_GRADE]:$ddr3_freq[$DDR_GRADE];
my $ddr_period=1000/$ddr_freq;


my $DDR_TINIT =($platform==2)?200:1;
my $DDR_TFAW_CFG=($DDR_TYPE==2)?$DDR2_TFAW_CFG:$DDR3_TFAW_CFG;
my $DDR_TFAW_CFG_OFF=get_DDR_TFAW_CFG_OFF();
my $DDR_TCL=($DDR_TYPE==2)?$ddr2_TCL[$DDR_GRADE]:$ddr3_TCL[$DDR_GRADE];
my $DDR_TWR=($DDR_TYPE==2)?$ddr2_TWR[$DDR_GRADE]:$ddr3_TWR[$DDR_GRADE];
my $DDR_TCWL=($DDR_TYPE==2)?($DDR_TCL-1):(($DDR_GRADE<2)?(5):(($DDR_GRADE<5)?(6):(($DDR_GRADE<8)?(7):(8))));
my $DDR_TRC=($DDR_TYPE==2)?$ddr2_TRC[$DDR_GRADE]:$ddr3_TRC[$DDR_GRADE];
my $DDR_TRRD=get_TRRD();
my $DDR_TRAS=($DDR_TYPE==2)?$ddr2_TRAS[$DDR_GRADE]:$ddr3_TRAS[$DDR_GRADE];
my $DDR_TRTP=($DDR_TYPE==2)?$ddr2_TRTP[$DDR_GRADE]:$ddr3_TRTP[$DDR_GRADE];
my $DDR_TWLO=($DDR_TYPE==2)?0:8;
my $DDR_TWLMRD=($DDR_TYPE==2)?0:40;
my $DDR_TRFC=get_TRFC();
my $DDR_TFAW=get_TFAW();
my $DDR_TMOD=($DDR_TYPE==2)?0:12;
my $DDR_TMRD=($DDR_TYPE==2)?2:4;
my $DDR_TCKE=($DDR_TYPE==2)?3:(($DDR_GRADE<2)?3:(($DDR_GRADE<5)?4:(($DDR_GRADE<8)?4:4)));
my $DDR_TXP=($DDR_TYPE==2)?2:(($DDR_GRADE<2)?3:(($DDR_GRADE<5)?5:(($DDR_GRADE<8)?4:5)));
my $DDR_TXS=get_DDR_TXS();
my $DDR_TREFPRD=int(9*7800/$ddr_period);
my $DDR_TPLLPD=($DDR_TYPE==2)?(($DDR_GRADE<2)?100:($DDR_GRADE<4)?133:($DDR_GRADE<6)?167:($DDR_GRADE<8)?200:266):(($DDR_GRADE<2)?200:($DDR_GRADE<5)?266:($DDR_GRADE<8)?333:400);
my $DDR_TPLLGS=$DDR_TPLLPD*4;
my $DDR_TPLLRST=3*($DDR_TPLLPD);
my $DDR_TPLLLOCK=100*($DDR_TPLLPD);
my $DDR_TCKSRE=($DDR_TYPE==2)?0:(($DDR_GRADE<2)?5:(($DDR_GRADE<5)?6:(($DDR_GRADE<8)?7:8)));
my $DDR_TAL=($DDR_TYPE==2)?$DDR_AL:(($DDR_AL>0)?($DDR_TCL-$DDR_AL):0);
my $DDR_MR0=($DDR_TYPE==2)?((($DDR_BLEN==8)?3:2)+$DDR_TCL*16+($DDR_TWR-1)*512+256):  ((($DDR_BLEN==8)?0:(($DDR_BLEN==4)?0:1))+(($DDR_TCL<=11)?(($DDR_TCL-4)*16):(($DDR_TCL-11)*16+4))+256+ (($DDR_TWR<=8)?(($DDR_TWR-4)*512):(($DDR_TWR/2)*512)));
my $DDR_MR1=(($DDR_TYPE==2)?(($DDR_GRADE<6)?($DDR_AL*8+0x4):($DDR_AL*8+0x40)):(($DDR_GRADE<8)?($DDR_AL*8+0x46):($DDR_AL*8+0x44)));
my $DDR_MR2=($DDR_TYPE==2)?0:(($DDR_GRADE<8)?(($DDR_TCWL-5)*8 + 0x200):(($DDR_TCWL-5)*8 + 0x400));
my $DDR_MR3=0;
my $DDR_TCCD=4;
my $DDR_TDLLK=512;
my $DDR_TPHYRST=16;
my $DDR_TCALON=15;
my $DDR_TCALS=15;
my $DDR_TCALH=15;
my $DDR_TWLDLYS=16;
my $DDR_TREFI_N=2;
my $DDR_TREFI_C=($DDR_TREFI_N)*78;
my $DDR_DFIODTCFG1=($DDR_TYPE==2)?(($DDR_GRADE<9)?(0x06060000+(($DDR_TCL + $DDR_TAL - 3)<<8)+($DDR_TCWL +
$DDR_TAL - 3)):(0x07070000+(($DDR_TCL+$DDR_TAL-4)<<8)+(($DDR_TCWL+$DDR_TAL)-4))):(0x06060001+(($DDR_TCL-$DDR_TCWL)<<8));
my $PLL0A_CFG1=(0x40400000+($A_CPS_F<<12)+($A_Share_Link_F<<8)+($A_NGI_TEP_F<<4)+$A_CBM_F);
my $PLL0B_CFG1=(0x40400000+($B_CPS_F<<12)+($B_DDR_Controller_F<<8)+($B_GSWIP_L_F<<4)+($B_GSWIP_RMII));

my $DDR_TOGCNT1U=int($ddr_freq/2);
my $DDR_TOGCNT100N=int($ddr_freq/20);


########################################################################################



open(OUTFILE, ">$output") || die("\nOutput file open fail\n");
my $value=0;
my $addr=0;

#NGI_ENDIAN_IA
$addr=0xb608005c;
$value=(($endianval==1)?0xdfffff:0x200000);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DIR
for ($i=0; $i<16; $i++) {
	$addr=0xb2000000;
	$value=0x0014a315;
	printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);
}

#PUB_DSGCR
$addr=0xb2000040;
$value=(($DDR_TYPE==2)?0xf000641f:0xf004641f);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MM_DRAMCONFIG:
$addr=(($endianval==1)?0xb2200004:0xb2200000);
$value= (($DDR_TYPE==2)?0x000c0020:0x000c0030)+(($DDR_BLEN==8)?256:0)+(($DDR_BANKSZ==8)?1:0);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MM_SWAP0_H
$addr=(($endianval==1)?0xb2200120:0xb2200124);
$value= (($DDR_TYPE==2)?(($DDR_DENSITY==2)?0xd8:0):0);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MM_SWAP0_L
$addr=(($endianval==1)?0xb2200124:0xb2200120);
$value= (($DDR_TYPE==2)?(($DDR_DENSITY==2)?0x0f2c420a:0x0369228b):0x0001528B);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#FMT_0
$addr=0xb49001d0;
$value= 0xF8002000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#FMT_1
$addr=0xb49001d4;
$value= 0xF8002800;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#FMT_2
$addr=0xb49001d8;
$value= 0xFE00A000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TOGCNT1U
$addr=0xb21000c0;
$value=$DDR_TOGCNT1U;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TINIT
$addr=0xb21000c4;
$value=$DDR_TINIT;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TOGCNT100N
$addr=0xb21000cc;
$value=$DDR_TOGCNT100N;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRSTH
$addr=0xb21000c8;
$value=($DDR_TYPE==2)?0:(($platform==2)?500:1);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRSTL
$addr=0xb2100134;
$value=($DDR_TYPE==2)?0:(($DDR_GRADE<2)?42:(($DDR_GRADE<5)?55:(($DDR_GRADE<8)?68:82)));
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCFG
$addr=0xb2100080;
$value=($DDR_TFAW_CFG-4)*(1<<18)+($DDR_TYPE-2)*(1<<5)+(($DDR_BLEN==8)?1:0);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCFG1
$addr=0xb210007c;
$value=($DDR_TFAW_CFG_OFF)*(1<<8);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DCR
$addr=0xb2000044;
$value=($DDR_TYPE==2)?0x40a:0x1000040b;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_MR0
$addr=0xb2000054;
$value=$DDR_MR0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_MR1
$addr=0xb2000058;
$value=$DDR_MR1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_MR2
$addr=0xb200005c;
$value=$DDR_MR2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_MR3
$addr=0xb2000060;
$value=$DDR_MR3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DTPR0
$addr=0xb2000048;
$value=$DDR_TRC*(1<<26)+$DDR_TRRD*(1<<22)+$DDR_TRAS*(1<<16)+$DDR_TCL*(1<<12)+$DDR_TCL*(1<<8)+$DDR_TRTP*(1<<4)+$DDR_TRTP;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DTPR1
$addr=0xb200004c;
$value=(($DDR_TYPE==2)?8:$DDR_TWLO)*(1<<26)+(($DDR_TYPE==2)?40:$DDR_TWLMRD)*(1<<20)+ $DDR_TRFC*(1<<11)+$DDR_TFAW*(1<<5)+(($DDR_TYPE==2)?4:($DDR_TMOD-12))*(1<<2)+(($DDR_TYPE==2)?$DDR_TMRD:($DDR_TMRD-4));
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DTPR2
$addr=0xb2000050;
$value=(($DDR_TCCD>4)?1*(1<<31):0) + ($DDR_TDLLK)*(1<<19)+  $DDR_TCKE*(1<<15)+  $DDR_TXP*(1<<10)+ $DDR_TXS + 1*(1<<30);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGCR2
$addr=0xb200008c;
$value=(($DDR_TYPE==2)?0x00f00000:0x00f80000)+ $DDR_TREFPRD;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PTR0
$addr=0xb200001c;
$value=$DDR_TPHYRST+  $DDR_TPLLGS*(1<<6)+  $DDR_TPLLPD*(1<<21);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PTR1
$addr=0xb2000020;
$value=$DDR_TPLLRST+ $DDR_TPLLLOCK*(1<<16);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PTR2
$addr=0xb2000024;
$value=$DDR_TCALON + $DDR_TCALS*(1<<5) + ($DDR_TCALH)*(1<<10) + ($DDR_TWLDLYS)*(1<<15);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DXCCR
$addr=0xb200003c;
$value=0x44181884;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0GCR
$addr=0xb20001c0;
$value=0x7c001e81;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX1GCR
$addr=0xb2000200;
$value=0x7c001e81;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_ZQ0CR1
$addr=0xb2000184;
$value=(($DDR_TYPE==2)?(($DDR_GRADE < 6)?0x0000104b:0x0000101b):(($DDR_GRADE < 8)?0x0000105d:0x0000101b));
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004+1;
$value=0x0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000000F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0LCDLR2
$addr=0xb20001e8;
$value=0x6E6E;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX1LCDLR2
$addr=0xb2000228;
$value=0x6E6E;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x40001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000001F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFISTSTAT0
$addr=0xb21002c0+1;
$value=0x1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#POWCTL
$addr=0xb2100044;
$value=0x1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#POWSTAT
$addr=0xb2100048+1;
$value=0x1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TOGCNT1U
$addr=0xb21000c0;
$value=$DDR_TOGCNT1U;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TINIT
$addr=0xb21000c4;
$value=$DDR_TINIT;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TOGCNT100N
$addr=0xb21000cc;
$value=$DDR_TOGCNT100N;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TREFI
$addr=0xb21000d0;
$value=(1<<31)+(($DDR_TREFI_N-1)<<16)+($DDR_TREFI_C);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TMRD
$addr=0xb21000d4;
$value=$DDR_TMRD;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRFC
$addr=0xb21000d8;
$value=$DDR_TRFC;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRP
$addr=0xb21000dc;
$value=($DDR_TYPE==2)?(($DDR_BANKSZ==8)?($DDR_TCL+65536):$DDR_TCL):$DDR_TCL;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TAL
$addr=0xb21000e4;
$value=$DDR_TAL;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCL
$addr=0xb21000e8;
$value=$DDR_TCL;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCWL
$addr=0xb21000ec;
$value=$DDR_TCWL;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRAS
$addr=0xb21000f0;
$value=$DDR_TRAS;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRC
$addr=0xb21000f4;
$value=$DDR_TRC;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRCD
$addr=0xb21000f8;
$value=$DDR_TCL;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRRD
$addr=0xb21000fc;
$value=$DDR_TRRD;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRTP
$addr=0xb2100100;
$value=$DDR_TRTP;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRTW
$addr=0xb21000e0;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TWR
$addr=0xb2100104;
$value=$DDR_TWR;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TWTR
$addr=0xb2100108;
$value=$DDR_TRTP;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TEXSR
$addr=0xb210010c;
$value=($DDR_TYPE==2)?200:512;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TXP
$addr=0xb2100110;
$value=$DDR_TXP;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TDQS
$addr=0xb2100120;
$value=($DDR_TYPE==2)?2:3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCKSRE
$addr=0xb2100124;
$value=$DDR_TCKSRE;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCKSRX
$addr=0xb2100128;
$value=($DDR_TYPE==2)?0:$DDR_TCKSRE;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TMOD
$addr=0xb2100130;
$value=$DDR_TMOD;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCKE
$addr=0xb210012c;
$value=$DDR_TCKE;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRSTH
$addr=0xb21000c8;
$value=($DDR_TYPE==2)?0:(($platform==2)?500:1);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TRSTL
$addr=0xb2100134;
$value=($DDR_TYPE==2)?0:(($DDR_GRADE<2)?42:(($DDR_GRADE<5)?55:(($DDR_GRADE<8)?68:82)));
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TZQCS
$addr=0xb2100118;
$value=($DDR_TYPE==2)?0:64;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TZQCL
$addr=0xb2100138;
$value=($DDR_TYPE==2)?0:512;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TXPDLL
$addr=0xb2100114;
$value=($DDR_TYPE==2)?$ddr2_TXP[$DDR_GRADE]:$ddr3_TXP[$DDR_GRADE];
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TZQCSI
$addr=0xb210011c;
$value=($DDR_TYPE==2)?0:5;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TCKESR
$addr=0xb2100140;
$value=($DDR_TYPE==2)?0:($DDR_TCKE+1);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#TDPD
$addr=0xb2100144;
$value=0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#EFI_MEM_DDR3
$addr=0xb2100148;
$value=($DDR_TYPE==2)?0:(int(7800/$ddr_period));
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCFG
$addr=0xb2100000;
$value=0x4480;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITPHYWRLAT
$addr=0xb2100254;
$value=(((($DDR_TCWL+$DDR_TAL)-1) >> 1) - 1);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITRDDATAEN
$addr=0xb2100260;
$value=$DDR_TCL-2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITPHYWRDATA
$addr=0xb2100250;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITPHYWRDATALAT
$addr=0xb2100258;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITPHYRDLAT
$addr=0xb2100264;
$value=15;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITDRAMCLKDIS
$addr=0xb21002d4;
$value=2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITDRAMCLKEN
$addr=0xb21002d0;
$value=2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITCTRLDELAY
$addr=0xb2100240;
$value=2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFIODTCFG
$addr=0xb2100244;
$value=0x8;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFIODTCFG1
$addr=0xb2100248;
$value=$DDR_DFIODTCFG1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFIODTRANKMAP
$addr=0xb210024c;
$value=0x21;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFITCTRLUPDMAX
$addr=0xb2100284;
$value=64;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFIUPDCFG
$addr=0xb2100290;
$value=7;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#####################
#MCMD
$addr=0xb2100040;
$value=0x86F00000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

##MCMD
$addr=0xb2100040+1;
$value=0x86F00000 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

if ($DDR_TYPE == 2) {
#MCMD 
$addr=0xb2100040;
$value=0x86F00001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);
}

#MCMD
$addr=0xb2100040;
$value=0x80f40003 +  $DDR_MR2*(1<<4);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80f40003 +  $DDR_MR2*(1<<4) - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value= 0x80f60003 + $DDR_MR3*(1<<4);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80f60003 + $DDR_MR3*(1<<4) - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value= 0x80f20003 + $DDR_MR1*(1<<4);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

##MCMD
$addr=0xb2100040+1;
$value= 0x80f20003 + $DDR_MR1*(1<<4) - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value= 0x80f00003 + $DDR_MR0*(1<<4);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

##MCMD
$addr=0xb2100040+1;
$value=0x80f00003 + $DDR_MR0*(1<<4) - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

if ($DDR_TYPE==2) {
#MCMD
$addr=0xb2100040;
$value=0x80F00001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80F00001 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value=0x80f00002;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80F00002 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value=0x80f00002;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80F00002 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value= 0x80f00003+ ($DDR_MR0-  ((int($DDR_MR0/256)%2==1)?256:0) )*16;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80f00003+ ($DDR_MR0-  ((int($DDR_MR0/256)%2==1)?256:0) )*16 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value=0x80f20003 + ($DDR_MR1)*(1<<4);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80f20003 + ($DDR_MR1)*(1<<4) - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

}

#MCMD
$addr=0xb2100040;
$value=0x80f00005;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80F00005 - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040;
$value=0x80f0000A;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#MCMD
$addr=0xb2100040+1;
$value=0x80F0000A - 0x80000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCTL
$addr=0xb2100004;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PPCFG
$addr=0xb2100084;
$value=0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFISTCFG0
$addr=0xb21002c4;
$value=7;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFISTCFG1
$addr=0xb21002c8;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFISTCFG2
$addr=0xb21002d8;
$value=0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFILPCFG0
$addr=0xb21002f0;
$value=0x70101;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#ECCCFG
$addr=0xb2100180;
$value=0;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DFIUPDCFG
$addr=0xb2100290;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#CMDSTATEN
$addr=0xb2100050;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#CMDSTAT
$addr=0xb210004c+1;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCTL
$addr=0xb2100004;
$value=2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCTL
$addr=0xb2100004;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=0x45;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PLL0A_CFG1
$addr=0xb6200008;
#$value= 0x40403866;
$value=$PLL0A_CFG1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PLL0B_CFG1
$addr=0xb6200038;
#$value= ($DDR_TYPE==2)?0x40401656:0x40401556;
$value=$PLL0B_CFG1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PLLCR
$addr=0xb6200018;
$value=0x40000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PLLCR
$addr=0xb6200018;
$value=0x0001c000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCTL
$addr=0xb2100004;
$value=4;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#SCTL
$addr=0xb2100004;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=1;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DTCR
$addr=0xb2000068;
$value=($DDR_TYPE==2)?0x91007887:(($DDR_GRADE>5)?0x910035c7:0x910078c7);
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x8000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB0000017;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x13;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000001F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#DELAY
$addr=0x80000000;
$value=0x0000ffff;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR0
$addr=0xb20001cc;
$value=0x18618618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR1
$addr=0xb20001d0;
$value=0x18618618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR2
$addr=0xb20001d4;
$value=0x00000618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR3
$addr=0xb20001d8;
$value=0x00000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR4
$addr=0xb20001dc;
$value=0x00000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR0
$addr=0xb200020c;
$value=0x18618618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR1
$addr=0xb2000210;
$value=0x18618618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR2
$addr=0xb2000214;
$value=0x00000618;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR3
$addr=0xb2000218;
$value=0x00000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_DX0BDLR4
$addr=0xb200021c;
$value=0x00000000;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

if ($DDR_TYPE==2) {
#PUB_PIR
$addr=0xb2000004;
$value=0x401;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000005F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x1001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000015f;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x2001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010;
$value=0xB000035f;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x4001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010;
$value=0xB000075F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x8001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010;
$value=0xB0000F5F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);
}
else {
#PUB_PIR
$addr=0xb2000004;
$value=0x201;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000003F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x401;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB000007F;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x801;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB00000FF;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x1001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB00001FF;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x2001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB00003FF;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x4001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB00007FF;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PIR
$addr=0xb2000004;
$value=0x8001;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#PUB_PGSR0
$addr=0xb2000010+1;
$value=0xB0000FFF;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);
}

#SCTL
$addr=0xb2100004;
$value=2;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);

#STAT
$addr=0xb2100008+1;
$value=3;
printf OUTFILE ("0x%08x 0x%08x \n",$addr, $value);


