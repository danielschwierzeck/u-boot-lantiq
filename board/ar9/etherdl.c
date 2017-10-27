/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */
//-----------------------------------------------------------------------
//Description:	
// Lantiq ethernet download tool for AR9
//-----------------------------------------------------------------------
//Author:	Qi-Ming.Wu@lantiq.com
//Created:	24-November-2004
//-----------------------------------------------------------------------
/* History
 * Last changed on: 08-June-2011
 * Last changed by: Wu Qi Ming Qi-Ming.Wu@lantiq.com
 *
*/


#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <linux/if_packet.h>
#include <strings.h>
#include <string.h>
#include <linux/sockios.h>
#include <malloc.h>
#include <getopt.h>
#include <errno.h>
#include <linux/if_packet.h>

#define MAX_BUFFER_SIZE 4096 

/*=============================global variables================*/
int c=0;
int input_flag=0;
int digit_optind=0;
int verbose=0;
char interface[6]="eth1";
FILE* script_file;
void (*func)()=NULL;



unsigned char buf[4096]={0};
unsigned char start_frame[MAX_BUFFER_SIZE]={0};
unsigned char end_frame[MAX_BUFFER_SIZE]={0};
unsigned char data_frame[MAX_BUFFER_SIZE]={0};
unsigned char dest_mac[6]={0xff,0xff,0xff,0xff,0xff,0xff};
unsigned char src_mac[6];

unsigned char start_ack[4]={0x11,0x11,0x11,0x11};
unsigned char err_ack[4]={0x77,0x77,0x77,0x77};
unsigned char end_ack[4]={0x99,0x99,0x99,0x99};
/*=============================================================*/




void display_version()
{
   printf("etherdownload version2.0\nby Wu Qi Ming\nQi-Ming.Wu@lantiq.com\n");
   return;
}


int get_mac_addr(unsigned char* address)
{
   int s;
   struct ifreq buffer;

   s = socket(PF_INET, SOCK_DGRAM, 0);

   memset(&buffer, 0x00, sizeof(buffer));

   strcpy(buffer.ifr_name, interface);

   ioctl(s, SIOCGIFHWADDR, &buffer);

   memcpy(address, (unsigned char*)buffer.ifr_hwaddr.sa_data, 6);
   close(s);
}

int valid(char input)
{
   
   if((input>=48)&&(input<=57))
   return 0;  
   else if((input>=65)&&(input<=70))
   return 0;
   else if((input>=97)&&(input<=102))
   return 0;
   else
   return 1;

}

unsigned char ctou8(char input)
{
   unsigned char output=0;
   //printf("input=%d\n",input);
   if((input>=48)&&(input<=57))
   output=input-48;  
   else if((input>=65)&&(input<=70))
   output=input-55;
   else if((input>=97)&&(input<=102))
   output=input-87;
   else
   {printf("input out of range!\n");
    output=-1;
   }
   return output;

}

void etherdl_help()
{
    printf("Usage:etherdl [options] [parameter] ...\n");
    printf("options:\n");
    printf("-h --help            Display help information\n");       
    printf("-v --verbose         Display debugging information\n");
    printf("-f --file            Specify the script file\n");
    printf("-d --dest            Specify destination mac address\n");
    printf("-i --interface       Select network interface\n");
    return;
}

int send_raw(unsigned char* buf, int len)
{
   int sockd;
   struct sockaddr_ll sll;
   struct ifreq ifr;
   if((sockd = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL)))< 0)  {
    perror("socket");
    exit(-1);
    }
   fcntl(sockd,F_SETFL,O_NONBLOCK);
   memset(&sll, 0xff, sizeof(sll));
   sll.sll_family=AF_PACKET;
   sll.sll_protocol=htons(ETH_P_ALL);
   sll.sll_ifindex=if_nametoindex(interface);
   sll.sll_hatype = 1;
   sll.sll_halen=ETH_ALEN;
   bind(sockd, (struct sockaddr*)&sll,sizeof(sll));
   while(sendto(sockd,(char *)buf,len,0x0,
       (struct sockaddr *)&sll,sizeof(sll)) < 0)  {/*sleep(1);*/}
   close(sockd);
}


int recv_raw(unsigned char* buff)
{
  
   int i,n=0;
   struct ifreq ethreq;
   int sockdr;
   struct sockaddr_ll rll;
   if((sockdr = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL)))< 0)  {
    perror("socket");
    exit(-1);
    }
   fcntl(sockdr,F_SETFL,O_NONBLOCK);
   memset(&rll, 0xff, sizeof(rll));
   rll.sll_family=AF_PACKET;
   rll.sll_protocol=htons(ETH_P_ALL);
   rll.sll_ifindex=if_nametoindex(interface);
   rll.sll_hatype = 1;
   rll.sll_halen=ETH_ALEN;
   bind(sockdr, (struct sockaddr*)&rll,sizeof(rll));
   strncpy(ethreq.ifr_name, interface ,IFNAMSIZ);
   if(ioctl(sockdr, SIOCGIFFLAGS,&ethreq)==-1){
     perror("ioctl");
     close(sockdr);
     exit(1);
    }
   ethreq.ifr_flags|=IFF_PROMISC;
   if(ioctl(sockdr,SIOCSIFFLAGS,&ethreq)==-1){
     perror("ioctl");
     close(sockdr);
     exit(1);
   }
   while(1){
   n=recvfrom(sockdr, buff, 4096, 0, NULL, NULL);
   if(n>0) break; 
   } 
   close(sockdr);
   return n;

}




void send_file()
{
   int i=0,j=0,k=0,len=0,nread=0;
   int num_line=0;
   if(!script_file) return;
   
   printf("downloading now\n");
   memcpy(buf,dest_mac,6);  
   get_mac_addr(src_mac);
   get_mac_addr(buf+6);
   
   
 
   buf[12]=0x0;
   buf[13]=0x0;
   while(fgets(buf+18,MAX_BUFFER_SIZE-18,script_file))
   {
       
       if((strlen(buf+18)-1)>0)
       {
         //printf("len=%d\n",strlen(buf+18)-1);
         num_line++;
       }
       memset(buf+18,0,4078);
   }
   printf("%d lines in total\n",num_line);
   
   fseek(script_file, 0, SEEK_SET);
   while(fgets(buf+14,MAX_BUFFER_SIZE-14,script_file))
   {
       len=strlen(buf+14)-1;
       if(len>0)
        {
	   i++;
	   if(i==num_line-1)
	    {
	     for(j=0;j<len/2;j++)
	     {
	       start_frame[14+j]=(ctou8(buf[14+j*2])<<4)+ctou8(buf[14+j*2+1]);
	     }
	     memcpy(start_frame,buf,14);	    
	     break;
	    }
	} 
   }
   if(verbose){
      for(i=0;i<len/2+14;i++)
      printf("%02x",start_frame[i]);
      printf("\n");
       }
START:     
   printf("send starting frame now!\n");
#if 0
   while(1)
   {
     
     send_raw((unsigned char*)start_frame,len/2+14);
     nread=recv_raw((unsigned char*)buf);
     if(memcmp(buf+6,src_mac,6)==0) continue;
     if((nread>0)&&(buf[12]==0x05)&&(buf[13]==0xff)&&(buf[14]==0x11))
      {
          if(memcmp((unsigned char*)buf+14,(unsigned char*)start_ack,4)==0)
	  {
	    
	    for(i=0;i<nread;i++)
            {
               printf("%02x",buf[i]);
            }
	    printf("start ack\n");
            break;
	  }
	  
	  
     }
     nread=0;
     memset((unsigned char*)buf+12,0,4096);
   }
#endif  
   send_raw((unsigned char*)start_frame,len/2+14); 
   usleep(1000);
   //printf("start frame acknoledged, send data now!\n");
   //memcpy(dest_mac,buf+6,6);
   
   memcpy(data_frame,dest_mac,6); 
   
   memcpy(data_frame+6,src_mac,6);
   
   fseek(script_file, 0, SEEK_SET);
   data_frame[12]=0x0;
   data_frame[13]=0x0;
   i=0;
   while(fgets(buf,MAX_BUFFER_SIZE,script_file))
   {
       
       len=strlen(buf)-1;
       if(len>0)
        {
	     i++;
	     if(i==num_line-1) continue;
	     if(i==num_line) { printf("send end frame now\n"); usleep(4000);}
	     for(j=0;j<len/2;j++)
	     {
	       data_frame[14+j]=(ctou8(buf[j*2])<<4)+ctou8(buf[j*2+1]);
	       
	     }
	       if(verbose){ 
		printf("data %d:\n",i);
                for(k=0;k<len/2+14;k++) printf("%02x",data_frame[k]);
		printf("\n");
                }else{

                 printf(".");
                }
                usleep(4000);
		send_raw((unsigned char*)data_frame,len/2+14);
                
	} 
       
   }

#if 0   
   while(1)
   {
     nread=recv_raw((unsigned char*)buf);
     if((nread>0)&&(buf[12]==0x05)&&(buf[13]==0xff))
      {
	  for(i=0;i<nread;i++)
          printf("%02x",buf[i]);
          printf("\n");
	  if(memcmp((unsigned char*)buf+14,(unsigned char*)end_ack,4)==0)
          break;
	  if(memcmp((unsigned char*)buf+14,(unsigned char*)err_ack,4)==0)
	  goto START;
      }
     
     nread=0;
     memset((unsigned char*)buf+12,0,4096);
   }
#endif
   
   printf("\ndownload complete!\n");
   return;
}


int main (int argc, char** argv) {
    
     while(1) {
       int option_index=0;
       static struct option long_options[] ={
           {"help",0,0,0},
	   {"verbose",0,0,0},
	   {"file",1,0,0},
           {"interface",1,0,0}   
       };
       
       c = getopt_long(argc,argv, "hvf:i:",
                      long_options, &option_index);
       
       //printf("c=%d option_index=%d\n",c,option_index);	
       if(c==-1)
         {
	  if(input_flag==0)
	  {
	   printf("etherdl:please specify parameters\n");
	   func=&etherdl_help;
          }
	  if(func)
	   (*func)();
	  else
	   {
ERROR:      etherdl_help();
	   } 
	  break;
	 }
       input_flag=1;
       switch (c) {
            case 0:
	       if(option_index==0)
	        {
		 func=&etherdl_help;
		 break; 
	        } 
	       if(option_index==1) 
	        {
		    goto VERBOSE;
		    break;
                } 
	       if(option_index==2)
	        {
	            goto FILE;
		    break;
	        }
	       if(option_index==3)
	        {
	            goto INTERFACE;
		    break; 
	        }
	    case 'h':
	       func=&etherdl_help;
	       break;    
	    case 'v':
VERBOSE:       verbose=1;
	       break;
	    case 'f':
FILE:	       if(!optarg) goto ERROR;
	       script_file=fopen((char*)optarg,"r");
               if(!script_file) perror("fopen");
	       func=&send_file;
	       break;
	    case 'i':
INTERFACE:     if(!optarg) goto ERROR;
               memset(&interface, 0x00, sizeof(interface)); 
               strcpy((char*)interface,(char*)optarg);     
               break;
	    }     
	
	    
     }
            if(script_file) fclose(script_file);
    
}







