#!/bin/bash
#Build uboot environment block image
#To be used in u-boot root directory of UGW package
#Copyright (C) 2007-2010 Lantiq Asia Pacific Pte. Ltd
#Revision history
#10/07/2012 Wu Qi Ming Qi-Ming.Wu@lantiq.com
#Usage: mk_envimg.sh target_file

packhex(){
    PACK_DATA_LEN=`echo $1 |wc -c`
    let PACK_DATA_LEN=$PACK_DATA_LEN-1
    PACK_START=1
    PACK_RESULT=
    while [ $PACK_START -le $PACK_DATA_LEN ]
    do
      PACK_TMP=`echo $1 | awk '{print substr($0, '$PACK_START', 2)}'`
      PACK_RESULT="${PACK_RESULT}\x${PACK_TMP}"
      let PACK_START=$PACK_START+2
    done
    echo $PACK_RESULT
}


OUTPUT=$1

ADDRHEX=`sed -e '/default_environment/!d' u-boot.sym |awk '{print substr($1,length($1)-4,5)}'`

ADDR=`echo $((16#$ADDRHEX))`


LENHEX=`sed -e '/default_environment/!d' u-boot.sym |awk '{print $2}'`

LEN=`echo $((16#$LENHEX))`


dd if=u-boot.bin of=env.tmp ibs=1 skip=$ADDR count=$LEN

CRC=`tools/envcrc env.tmp`

echo -en `packhex $CRC` >$OUTPUT

REDUND=`grep -r CONFIG_ENV_REDUND .config | awk -F'=' '{print $2}'`

if [ "$REDUND" = "y" ];then
   echo -en "\x0" >>$OUTPUT
fi

cat env.tmp >>$OUTPUT

CONFIG_ENV_SIZE=`strings env.tmp | grep f_ubootconfig_size=|awk -F'=' '{print $2}'`

scripts_platform/pad2align.sh -n $CONFIG_ENV_SIZE $OUTPUT

rm -rf env.tmp


