#!/bin/sh
#shell script to convert ddr setting header file to conf file for uart download 
#revision history
#13/04/2012 Wu Qi Ming initial version

Usage(){
  echo "Usage: ddrh2conf.sh [option]...[file]..."
  echo "-h  --help             print help information"
  echo "-i  --infile file      ddr header file"
  echo "example: ddrh2conf.sh -i ddr.h >ddr.conf"
  return
}

INFILE=
DDRFREQ=
DDR_CYCLE=

parse_args() {
  while [ "$#" -gt "0" ]
  do
     case $1 in
                --infile | -i)
                        INFILE=$2
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
    sed -e '/#define/!'d -e "/\b$1\b/!"d $INFILE |awk '{print $3}'    
}


if [ $# -eq 0 ] ; then  
   Usage
   exit 1
fi 

parse_args $@

DDR_MC_BASE=0xBF801000

echo 0xbf800060  0x7
echo 0xbf800010  0x0
echo 0xbf800020  0x0
echo 0xbf800200  0x02
echo 0xbf800210  0x0

i=0

while [ $i -le 46 ]
do
   ADDR=`get_value MC_DC$i`
   VALUE=`get_value MC_DC${i}_VALUE`
   echo $ADDR $VALUE
   let i=$i+1
done



echo 0xbf800060  0x05
echo 0xbf801030  0x100
echo 0xbf800071  0x0c

