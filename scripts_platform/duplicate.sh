#!/bin/bash
#duplicate file to a specific times
#Revision history
#19/09/2011 Author: Wu Qi Ming Qi-Ming.Wu@infineon.com

COUNTER=1
TARGETFILE=$2

cp $TARGETFILE tmp 

while [ $COUNTER -lt $1 ]; do
  echo "duplicate!"
  cat $TARGETFILE >> tmp
  COUNTER=$(($COUNTER+1))
done

cp tmp $2
rm tmp
