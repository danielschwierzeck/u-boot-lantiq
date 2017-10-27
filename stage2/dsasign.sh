#!/bin/sh
INPUTFILE=$1
OUTPUTFILE=$2

openssl dsaparam -out dsaparam.pem 1024
openssl gendsa -out privkey.pem dsaparam.pem
openssl dsa -in privkey.pem -out pubkey.pem -pubout

openssl asn1parse -in privkey.pem >privkey.asn1

P=`sed -n '3 p' privkey.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_p $P >$OUTPUTFILE

Q=`sed -n '4 p' privkey.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_q $Q >>$OUTPUTFILE

G=`sed -n '5 p' privkey.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_g $G >>$OUTPUTFILE

PUBKEY=`sed -n '6 p' privkey.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_pubkey $PUBKEY >>$OUTPUTFILE

openssl dsa -in privkey.pem -text -noout

# SHA1 digest
SHA1_RESULT=`openssl dgst -sha1 $INPUTFILE | awk -F'= ' '{print $2}'`
echo "sha1 result:" $SHA1_RESULT
./hex2array.pl str $SHA1_RESULT >>$OUTPUTFILE


openssl dgst -dss1 -sign privkey.pem $INPUTFILE >sign.result

openssl asn1parse -inform DER -in sign.result >sign.asn1
R=`sed -n '2 p' sign.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_r $R >>$OUTPUTFILE

S=`sed -n '3 p' sign.asn1 | awk -F':' '{print $4}'`
./hex2array.pl bn_s $S >>$OUTPUTFILE


openssl dgst -dss1 -verify pubkey.pem -signature sign.result $INPUTFILE

