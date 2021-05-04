#!/usr/bin/perl
#perl script to convert hex to C array
#Revision history
#27/11/2009 Author Wu Qi Ming
#usage: hex2array.pl bn 010203....
#output: unsigned char bn[]={0x01,0x02,0x03,....};


$name = $ARGV[0];
$string = $ARGV[1];


if(length($string) % 2 >0){
   $string="0".$string;
}

@bytes = unpack("(A2)*", $string);
$len=@bytes;
$rem=$len%4;

print "unsigned char ";
print $name;
print "[]={";

$i=0;
if($rem>0){
 while($i<(4-$rem))
 {
   print "0x00,";
   $i++;
 }
}

$i=0;
while ($i<$len)
{
   print "0x$bytes[$i]";
   if($i != ($len-1)){
      print ",";
   }
   $i++;
}

print "};\n";

