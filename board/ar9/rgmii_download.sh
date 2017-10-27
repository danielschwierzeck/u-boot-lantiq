#!/bin/sh

SOURCE_FILE=$1
ETHERDL=$2
INTERFACE=$3
TMP_FILE='tmp.txt'
TARGET_FILE='target.asc'
cp $SOURCE_FILE $TMP_FILE

while [ -s $TMP_FILE ]
do
   LINE_NUM=`sed -n -e '/^99999999/=' $TMP_FILE | sed -n '1'p`
   echo $LINE_NUM
   sed -n 1,${LINE_NUM}p $TMP_FILE >$TARGET_FILE
   $ETHERDL -f $TARGET_FILE -i $INTERFACE -v
   sed -e 1,${LINE_NUM}d $TMP_FILE >'tmp2.txt'
   cp tmp2.txt $TMP_FILE
   sleep 3  
done

