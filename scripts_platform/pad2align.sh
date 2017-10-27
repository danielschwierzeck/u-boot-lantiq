#!/bin/bash
#pad file to align with specific alignments
#Revision history
#30/4/2009 Author: Wu Qi Ming Qi-Ming.Wu@infineon.com
#26/08/2011 Modified to accept hex number input  Wu Qi Ming Qi-Ming.Wu@lantiq.com

Usage(){
  echo "Usage: pad2align [option]...[file]..."
  echo "Pad file to align with specified number of bytes"
  echo "-n  --number bytes    specify alignment boundary"
  echo "-h  --help            print help information"
  return
}

ALIGNMENT=
ALIGNFILE=

parse_args() {
  while [ "$#" -gt "0" ]
  do
     case $1 in
	        --number | -n)
		        ALIGNMENT=$2
		        ALIGNFILE=$3		
				;;
			--help | -h)
				Usage
				exit 1
				;;
	 esac			
	 shift
  done
  return
}
 


parse_args $@

if [ "$ALIGNFILE" == "" ]; then
      echo "no file specified!"
	  exit 1;
fi

TMP=`echo $2 | sed -n "/0x/p"`
if [ "$TMP" ];
then
   TMP=`echo $2 | sed "s/0x//g"`
   ALIGNMENT=`echo 'ibase=16;' $TMP | bc`
else
   ALIGNMENT=$2
fi


FILESIZE=`wc -c $ALIGNFILE | awk '{print $1}'`
MODULO=`expr $FILESIZE % $ALIGNMENT`


if [ $MODULO != 0 ];then
  PADSIZE=`expr $ALIGNMENT - $MODULO` 
  dd if=/dev/zero of=tmppad bs=$PADSIZE count=1 
  cat tmppad >>$ALIGNFILE
  rm tmppad
fi
