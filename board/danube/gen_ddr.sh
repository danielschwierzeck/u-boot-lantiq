#!/bin/sh
#shell script to generate ddr setting header file for danube 
#revision history
#12/04/2012 Wu Qi Ming initial version

Usage(){
  echo "Usage: gen_ddr.sh [option]...[file]..."
  echo "-h  --help             print help information"
  echo "-s  --spec ddrspec     ddrspec file"
  echo "-f  --freq freq        ddr frequency(Mhz)"
  echo "example: gen_ddr.sh -s spec.h -f 166 >ddr.h"
  return
}

SPECFILE=
DDRFREQ=
DDR_CYCLE=

parse_args() {
  while [ "$#" -gt "0" ]
  do
     case $1 in
                --spec | -s)
                        SPECFILE=$2
                        ;;
                --freq | -f)
                        DDRFREQ=$2
                        ;;
                --help | -h )
			Usage
			exit 1
			;;
      esac			
      shift 
  done
  return
}


get_value(){
    sed -e '/#define/!'d -e "/\b$1\b/!"d $SPECFILE |awk '{print $3}'    
}


if [ $# -eq 0 ] ; then  
   Usage
   exit 1
fi 

parse_args $@

echo /*This file is auto-generated           */
echo /*ddr setting header file for danube    */

let DDR_CYCLE=1000/${DDRFREQ}

echo /*DDR frequency = ${DDRFREQ} Mhz       */
echo /*DDR period per cycle= ${DDR_CYCLE} ns*/

echo 

echo "#define MC_DC0   0xbf801000"
echo "#define MC_DC1   0xbf801010"
echo "#define MC_DC2   0xbf801020"
echo "#define MC_DC3   0xbf801030"
echo "#define MC_DC4   0xbf801040"
echo "#define MC_DC5   0xbf801050"
echo "#define MC_DC6   0xbf801060"
echo "#define MC_DC7   0xbf801070"
echo "#define MC_DC8   0xbf801080"
echo "#define MC_DC9   0xbf801090"
echo "#define MC_DC10  0xbf8010a0"
echo "#define MC_DC11  0xbf8010b0"
echo "#define MC_DC12  0xbf8010c0"
echo "#define MC_DC13  0xbf8010d0"
echo "#define MC_DC14  0xbf8010e0"
echo "#define MC_DC15  0xbf8010f0"
echo "#define MC_DC16  0xbf801100"
echo "#define MC_DC17  0xbf801110"
echo "#define MC_DC18  0xbf801120"
echo "#define MC_DC19  0xbf801130"
echo "#define MC_DC20  0xbf801140"
echo "#define MC_DC21  0xbf801150"
echo "#define MC_DC22  0xbf801160"
echo "#define MC_DC23  0xbf801170"
echo "#define MC_DC24  0xbf801180"
echo "#define MC_DC25  0xbf801190"
echo "#define MC_DC26  0xbf8011a0"
echo "#define MC_DC27  0xbf8011b0"
echo "#define MC_DC28  0xbf8011c0"
echo "#define MC_DC29  0xbf8011d0"
echo "#define MC_DC30  0xbf8011e0"
echo "#define MC_DC31  0xbf8011f0"
echo "#define MC_DC32  0xbf801200"
echo "#define MC_DC33  0xbf801210"
echo "#define MC_DC34  0xbf801220"
echo "#define MC_DC35  0xbf801230"
echo "#define MC_DC36  0xbf801240"
echo "#define MC_DC37  0xbf801250"
echo "#define MC_DC38  0xbf801260"
echo "#define MC_DC39  0xbf801270"
echo "#define MC_DC40  0xbf801280"
echo "#define MC_DC41  0xbf801290"
echo "#define MC_DC42  0xbf8012a0"
echo "#define MC_DC43  0xbf8012b0"
echo "#define MC_DC44  0xbf8012c0"
echo "#define MC_DC45  0xbf8012d0"
echo "#define MC_DC46  0xbf8012e0"


#Use default 0x1B1B
echo "#define MC_DC0_VALUE  0x1B1B"

echo "#define MC_DC1_VALUE  0x0"
echo "#define MC_DC2_VALUE  0x0"
echo "#define MC_DC3_VALUE  0x0"
echo "#define MC_DC4_VALUE  0x0"

init_refresh=`get_value init_refresh`
VALUE=`echo "obase=16; (${init_refresh} * 256)+4" |bc`
echo "#define MC_DC5_VALUE  0x${VALUE}"


CASLTY=`get_value CASLTY`
CAS_LATENCY=`get_value CAS_LATENCY`
VALUE=`echo "obase=16;${CASLTY}*256 + ${CAS_LATENCY}*2"|bc |awk -F'.' '{print $1}'`
echo "#define MC_DC6_VALUE  0x${VALUE}"

Twr=`get_value Twr`
BURST_LENGTH=`get_value BURST_LENGTH`
bstlen=`echo "l($BURST_LENGTH)/l(2)" |bc -l|awk -F'.' '{print $1}'`
VALUE=`echo "obase=16;(${Twr}/$DDR_CYCLE+1)*256+${bstlen}" |bc`
echo "#define MC_DC7_VALUE  0x${VALUE}"


Tpdex=`get_value Tpdex`
Trrd=`get_value Trrd`
VALUE=`echo "obase=16;${Tpdex}*256+${Trrd}/$DDR_CYCLE+1" |bc`
echo "#define MC_DC8_VALUE  0x${VALUE}"

Trasmin=`get_value Trasmin`
Trc=`get_value Trc`
VALUE=`echo "obase=16;(${Trasmin}/${DDR_CYCLE}+1)*256+$Trc/$DDR_CYCLE+1" |bc`
echo "#define MC_DC9_VALUE  0x${VALUE}"

Temrs=`get_value Temrs`
Trp=`get_value Trp`
VALUE=`echo "obase=16;($Temrs/$DDR_CYCLE+1)*256+$Trp/$DDR_CYCLE+1" |bc`
echo "#define MC_DC10_VALUE  0x${VALUE}"

Trfc=`get_value Trfc`
Tmrd=`get_value Tmrd`
VALUE=`echo "obase=16;($Trfc/$DDR_CYCLE+1)*256+$Tmrd/$DDR_CYCLE+1" |bc`
echo "#define MC_DC11_VALUE  0x${VALUE}"

Twtr=`get_value Twtr`
Tdll=`get_value Tdll`
VALUE=`echo "obase=16;($Twtr/$DDR_CYCLE+1)*256+$Tdll/$DDR_CYCLE+1" |bc`
echo "#define MC_DC12_VALUE  0x${VALUE}"


#support write command interrupting, hardcoded
echo "#define MC_DC13_VALUE  0x1"

#use default value
echo "#define MC_DC14_VALUE  0x0"

#CSM and WDS, use CS0, for one ram chip by default
#Set write DQS shift to 0x20, will need to be tuned
echo "#define MC_DC15_VALUE  0x120"

Txsr=`get_value Txsr`
VALUE=`echo "obase=16;($Txsr/$DDR_CYCLE+1)*256" |bc`
echo "#define MC_DC16_VALUE  0x${VALUE}"

Txsnr=`get_value Txsnr`
VALUE=`echo "obase=16;$Txsnr/$DDR_CYCLE+1" |bc`
echo "#define MC_DC17_VALUE  0x${VALUE}"

Trcd=`get_value Trcd`
Tcke=`get_value Tcke`
VALUE=`echo "obase=16;($Trcd/$DDR_CYCLE+1)*256+$Tcke/$DDR_CYCLE+1" |bc`
echo "#define MC_DC18_VALUE  0x${VALUE}"

ROW_ADDR_NUM=`get_value ROW_ADDR_NUM`
VALUE=`echo "obase=16;(15-$ROW_ADDR_NUM)*256"|bc`
echo "#define MC_DC19_VALUE  0x${VALUE}"

AUTO_PRECHARGE_BIT=`get_value AUTO_PRECHARGE_BIT`
COLUMN_ADDR_NUM=`get_value COLUMN_ADDR_NUM`
VALUE=`echo "obase=16;$AUTO_PRECHARGE_BIT*256+(13-$COLUMN_ADDR_NUM)" |bc`
echo "#define MC_DC20_VALUE  0x${VALUE}"

#DLL DQS delay 0, set to 0xD by default
echo "#define MC_DC21_VALUE  0xD00"

#Read DQS delay for slice1 and slice2
#set to default 0xD
echo "#define MC_DC22_VALUE  0xD0D"

#cannot find the definition in the spec, set to 0
echo "#define MC_DC23_VALUE  0x0"

#DQS out shift setting, need tuning
echo "#define MC_DC24_VALUE 0x50"  


#cannot find in the spec, set to 0
echo "#define MC_DC25_VALUE 0x0"


#Endian setting, use default
echo "#define MC_DC26_VALUE 0x0"


#DDR controller version, 0x2040
echo "#define MC_DC27_VALUE 0x2040"

Tref=`get_value Tref`
VALUE=`echo "obase=16;$Tref*1000/$DDR_CYCLE+1" |bc`
echo "#define MC_DC28_VALUE 0x$VALUE"

Trasmax=`get_value Trasmax`
VALUE=`echo "obase=16;$Trasmax/$DDR_CYCLE+1" |bc`
echo "#define MC_DC29_VALUE 0x$VALUE"

Tinit=`get_value Tinit`
VALUE=`echo "obase=16;$Tinit*1000/$DDR_CYCLE+1" |bc`
echo "#define MC_DC30_VALUE 0x$VALUE"

#EMRS, extended mode register data, set to 0 by default
echo "#define MC_DC31_VALUE 0x0"

echo "#define MC_DC32_VALUE 0x0"
echo "#define MC_DC33_VALUE 0x0"
echo "#define MC_DC34_VALUE 0x0"
echo "#define MC_DC35_VALUE 0x0"
echo "#define MC_DC36_VALUE 0x0"
echo "#define MC_DC37_VALUE 0x0"
echo "#define MC_DC38_VALUE 0x0"
echo "#define MC_DC39_VALUE 0x0"
echo "#define MC_DC40_VALUE 0x0"
echo "#define MC_DC41_VALUE 0x0"
echo "#define MC_DC42_VALUE 0x0"
echo "#define MC_DC43_VALUE 0x0"
echo "#define MC_DC44_VALUE 0x0"

#CAS_LATENCY again
VALUE=`echo "obase=16;${CAS_LATENCY}*2*256"|bc |awk -F'.' '{print $1}'`
echo "#define MC_DC45_VALUE 0x$VALUE"

echo "#define MC_DC46_VALUE 0x0"


