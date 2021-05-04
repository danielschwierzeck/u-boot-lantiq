#!/bin/sh
#shell script to generate stage3 image 
#revision history
#Wu Qi Ming 6/12/2012 Qi-Ming.Wu@lantiq.com

Usage(){
  echo "Usage: build_stage3.sh [option]...[file]..."
  echo "-h  --help             print help information"
  echo "-i  --in   input       input file"
  echo "-o  --out  output      output file"
  echo "-k  --key  key         aes cbc key"
  echo "-p  --priv privkey     dsa private key"
  echo "-d  --da   address     decrypted(destination) image address"
  echo "-j  --ja   address     jump address"
  return
}

PRIVKEY=
HEADMAGIC=0x65976743
INPUTFILE=
OUTPUTFILE=
#CBCKEY=693deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4
CBCKEY=
CBCIV=00000000000000000000000000000000
ENCRYPT_ADDR=
DECRYPT_ADDR=
JUMP_ADDR=

parse_args() {
  while [ "$#" -gt "0" ]
  do
     case $1 in
	             --in | -i)
		                INPUTFILE=$2		
			            ;;
                --out | -o)
                        OUTPUTFILE=$2
                        ;;
                --key | -k)
                        CBCKEY=$2
						HEADMAGIC=0x65976742
                        ;;
				--privkey | -p)
				        PRIVKEY=$2
						;;
                --ea | -e)
                        ENCRYPT_ADDR=$2
                        ;;
				--da | -d)
				        DECRYPT_ADDR=$2
					    ;;
                --ja | -j)
			            JUMP_ADDR=$2
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

addchksum(){
    RESULT=`perl -e "print $1+$2"|xargs printf "%08x\n"`
    echo 0x$RESULT
}



if [ $# -eq 0 ] ; then  
   Usage
   exit 1
fi 

parse_args $@


if [ -z $PRIVKEY ]
then
   echo "no dsa privkey"
   Usage
   exit 1
fi

if [ -z $DECRYPT_ADDR ]
then
   echo "no destination address"
   Usage
   exit 1
fi


if [ -z $JUMP_ADDR ]
then
   echo "no jump address"
   Usage
   exit 1
fi


if [ -z $OUTPUTFILE ]
then
   echo "no output file"
   Usage
   exit 1
fi


if [ -z $INPUTFILE ]
then
   echo "no output file"
   Usage
   exit 1
fi


#echo "input:" $INPUTFILE
#echo "output:" $OUTPUTFILE
#echo "cbckey:" $CBCKEY
#echo "cbciv:"  $CBCIV
#echo "headmagic:" $HEADMAGIC


#creating secure header now

#add headmagic
DATA=`printf "%08x" $HEADMAGIC`
echo -en `packhex $DATA` >shdr

#followed by image length
LEN=`stat -c %s $INPUTFILE`
LENHEX=`printf "%08x" $LEN`
echo -en `packhex $LENHEX` >>shdr

#Followed by decrypted image address
ADDR=`printf "%08x" $DECRYPT_ADDR`
echo -en `packhex $ADDR` >>shdr

#jump address
ADDR=`printf "%08x" $JUMP_ADDR`
echo -en `packhex $ADDR` >>shdr

#SHA1 result 
SHA_RESULT=`openssl dgst -sha1 $INPUTFILE | awk -F'= ' '{print $2}'`
#echo "sha result:" $SHA_RESULT
echo -en `packhex $SHA_RESULT` >>shdr

#dsa signature now
openssl dgst -dss1 -sign $PRIVKEY $INPUTFILE >sign.result

openssl asn1parse -inform DER -in sign.result >sign.asn1
R=`sed -n '2 p' sign.asn1 | awk -F':' '{print $4}'`
#echo "R:" $R
echo -en `packhex $R` >>shdr

S=`sed -n '3 p' sign.asn1 | awk -F':' '{print $4}'`
#echo "S:" $S
echo -en `packhex $S` >>shdr

#add header checksum */
CHKSUM=0x0
DATA=`hexdump -v -e '"0x"' -e '4/1 "%02x"' -e '" "' shdr`

for VALUE in $DATA
do
  CHKSUM=`addchksum $CHKSUM $VALUE`
done

#echo $CHKSUM

RESULT=`perl -e "print $CHKSUM & 0xffffffff"|xargs printf "%08x\n"`
RESULT=`echo 0x$RESULT`

DATA=`printf "%08x" $RESULT`
echo -en `packhex $DATA` >>shdr

cp shdr $OUTPUTFILE

if [ -z $CBCKEY ];then
  cat $INPUTFILE >>$OUTPUTFILE
else
  openssl enc -aes-256-cbc -in $INPUTFILE -out file.enc -K $CBCKEY -iv $CBCIV -nopad
  cat file.enc >>$OUTPUTFILE
fi

