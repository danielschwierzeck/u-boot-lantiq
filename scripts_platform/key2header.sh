#!/bin/sh
INPUTFILE=$1
OUTPUTFILE=$2

openssl asn1parse -in $INPUTFILE >privkey.asn1

P=`sed -n '3 p' privkey.asn1 | awk -F':' '{print $4}'`
scripts_platform/hex2array.pl bn_p $P >$OUTPUTFILE

Q=`sed -n '4 p' privkey.asn1 | awk -F':' '{print $4}'`
scripts_platform/hex2array.pl bn_q $Q >>$OUTPUTFILE

G=`sed -n '5 p' privkey.asn1 | awk -F':' '{print $4}'`
scripts_platform/hex2array.pl bn_g $G >>$OUTPUTFILE

PUBKEY=`sed -n '6 p' privkey.asn1 | awk -F':' '{print $4}'`
scripts_platform/hex2array.pl bn_pubkey $PUBKEY >>$OUTPUTFILE


