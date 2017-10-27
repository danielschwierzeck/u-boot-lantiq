/*
 *	Code partially borrowed from uIP-1.0
 *
 *	Copyright 1994 - 2000 Neil Russell.
 *	Copyright 2000 Roland Borde
 *	Copyright 2000 Paolo Scaffardi
 *  Copyright 2009 Wu Qi Ming, Lantiq
 */
/*
 * General Desription:
 * A simple tcp layer implementation for u-boot
 */

#include <common.h>
#include <watchdog.h>
#include <command.h>
#include <net.h>
#include "tcp.h"


static u16 ipid;           /* Ths ipid variable is an increasing
				number that is used for the IP ID
				field. */

u16 uip_len, uip_slen;
                             /* The uip_len is either 8 or 16 bits,
                                depending on the maximum packet
                                size. */

u8 uip_flags;     /* The uip_flags variable is used for
                                communication between the TCP/IP stack
                                and the application program. */



struct tcp_conn *tcp_conn;   /* tcp_conn always points to the current
				connection. */

struct tcp_conn tcp_conns[MAX_CONNS];
                             /* The tcp_conns array holds all TCP
				connections. */
u16 tcp_listenports[MAX_LISTENPORTS];
                             /* The tcp_listenports list all currently
				listning ports. */
	
static u8 iss[4];          /* The iss variable is used for the TCP
				initial sequence number. */	
	
/* Temporary variables. */
u8 uip_acc32[4];				
				
static rxhand_f *UpperHandler;     /* Current RX packet handler        */
				
/**
 * \internal
 *
 * Check if a connection has outstanding (i.e., unacknowledged) data.
 *
 * \param conn A pointer to the uip_conn structure for the connection.
 *
 * \hideinitializer
 */
#define tcp_outstanding(conn) ((conn)->len)
				
				
void TcpSetHandler(void * f)
{
    UpperHandler = f;
}
				
/*check tcp chksum, pkt is the ip data packet*/				
u16 tcp_chksum(uchar * pkt)
{
	
	int i;
	u8* p;
	u32 sum;
	u16 chksum=0;
	u16 tmp;
	struct ip_hdr * ip_head=(struct ip_hdr *)pkt;
	struct tcp_hdr * tcp_head=NULL;
	int ihl; /*ip header length and tcp packet length*/
	u16 tcp_len;
	ihl = (ip_head->vhl & 0x0f) * 4 ;
	tcp_len = ((u16)(ip_head->len[0])<<8 & 0xff00) + (u16)(ip_head->len[1]) - (u16)ihl;
  sum = (u16)(ip_head->srcipaddr[0]<<8) + (u16)(ip_head->srcipaddr[1]) + \
        (u16)(ip_head->srcipaddr[2]<<8) + (u16)(ip_head->srcipaddr[3]) + \
        (u16)(ip_head->destipaddr[0]<<8) + (u16)(ip_head->destipaddr[1]) + \
        (u16)(ip_head->destipaddr[2]<<8) + (u16)(ip_head->destipaddr[3]) + \ 
        0x0006 + tcp_len;
  tcp_head = pkt + ihl;
	p = (u8*)tcp_head;
	 
	for(i=0;i<tcp_len-1;i+=2)
	{
		tmp =(u16)(*(p + i))<<8;
		tmp +=(u16)(*(p + i + 1 ));
	 	sum +=tmp;
	}
	
	if(tcp_len%2) {
		tmp= ((u16)(*(p + i )))<<8;
		sum += tmp;
	}
	chksum=(u16)(tcp_head->tcpchksum[0])<<8 & 0xff00 ;
	chksum += (u16)(tcp_head->tcpchksum[1]);
	sum -=chksum;
	while((sum & 0xffff0000)>>16){
	  sum = ((sum & 0xffff0000)>>16) + (sum & 0x0000ffff);
  }
	chksum = (u16)(sum  & 0xffff)+ chksum;
	
	
 	return chksum;
  
}				
		
void
uip_add32(u8 *op32, u16 op16)
{
  uip_acc32[3] = op32[3] + (op16 & 0xff);
  uip_acc32[2] = op32[2] + (op16 >> 8);
  uip_acc32[1] = op32[1];
  uip_acc32[0] = op32[0];

  if(uip_acc32[2] < (op16 >> 8)) {
    ++uip_acc32[1];
    if(uip_acc32[1] == 0) {
      ++uip_acc32[0];
    }
  }


  if(uip_acc32[3] < (op16 & 0xff)) {
    ++uip_acc32[2];
    if(uip_acc32[2] == 0) {
      ++uip_acc32[1];
      if(uip_acc32[1] == 0) {
        ++uip_acc32[0];
      }
    }
  }
}
		
static void
tcp_add_rcv_nxt(u16 n)
{
  uip_add32(tcp_conn->rcv_nxt, n);
  tcp_conn->rcv_nxt[0] = uip_acc32[0];
  tcp_conn->rcv_nxt[1] = uip_acc32[1];
  tcp_conn->rcv_nxt[2] = uip_acc32[2];
  tcp_conn->rcv_nxt[3] = uip_acc32[3];
}
		
static void seq_add32(u8* data, u32 value)
{
	u32 tmp;
	tmp = ((u32)data[0]<<24) | ((u32)data[1]<<16) | ((u32)data[2]<<8) | ((u32)data[3]);
	tmp +=value;
	*data = (u8)((tmp>>24) & 0xff);
	*(data+1) = (u8)((tmp>>16) & 0xff);
	*(data+2) = (u8)((tmp>>8) & 0xff);
	*(data+3) = (u8)(tmp & 0xff);
}		
				
				
u16 test(uchar * pkt)
{
	
	int i;
	u8* p;
	u32 sum;
	u16 chksum=0;
	u16 tmp;
	struct ip_hdr * ip_head=(struct ip_hdr *)pkt;
	struct tcp_hdr * tcp_head=NULL;
	int ihl; /*ip header length and tcp packet length*/
	u16 tcp_len;
	ihl = (ip_head->vhl & 0x0f) * 4 ;
	tcp_len = ((u16)(ip_head->len[0])<<8 & 0xff00) + (u16)(ip_head->len[1]) - (u16)ihl;
	
	
  sum = (u16)(ip_head->srcipaddr[0]<<8) + (u16)(ip_head->srcipaddr[1]) + \
        (u16)(ip_head->srcipaddr[2]<<8) + (u16)(ip_head->srcipaddr[3]) + \
        (u16)(ip_head->destipaddr[0]<<8) + (u16)(ip_head->destipaddr[1]) + \
        (u16)(ip_head->destipaddr[2]<<8) + (u16)(ip_head->destipaddr[3]) + \ 
        0x0006 + tcp_len;
        
  printf("pseudo header=%08x\n",sum);      
  tcp_head = pkt + ihl;
  
  for(i=0;i<tcp_len;i++)
	{
	   printf("%02x ",*((u8*)tcp_head+i));  
  }
  
	p = (u8*)tcp_head;
	 
	for(i=0;i<tcp_len-1;i+=2)
	{
		tmp =(u16)(*(p + i))<<8;
		tmp +=(u16)(*(p + i + 1 ));
	 	sum +=tmp;
	}
	printf("sum1=%08x\n",sum);
	
	if(tcp_len%2) {
		tmp= ((u16)(*(p + i )))<<8;
		sum += tmp;
	}
	printf("sum2=%08x\n",sum);
	chksum=(u16)(tcp_head->tcpchksum[0])<<8 & 0xff00 ;
	chksum += (u16)(tcp_head->tcpchksum[1]);
	sum -=chksum;
	printf("sum3=%08x\n",sum);
	sum = ((sum & 0xffff0000)>>16) + (sum & 0x0000ffff);
	chksum = (u16)(sum  & 0xffff)+ chksum;
	printf("chksum=%04x\n",chksum);
	
 	return chksum;
  
}				
						
				
static void
TcpHandler (uchar * pkt, unsigned dest, unsigned src, unsigned len)		
{
  struct ip_hdr * ip_head=(struct ip_hdr *)pkt;
	struct tcp_hdr * tcp_head=NULL;
	int ihl; /*ip header length and tcp packet length*/
	u16 tcp_len, destport, srcport,tmp;
	int c,i;
	u8* p;
	u8* tcp_data_ptr;
	int tcp_data_len;   
	u8 opt;
	uchar * tx_pkt;
	
tcp_input:	
	
	  if(tcp_chksum(pkt)!=0xffff){
	  	printf("tcp bad checksum\n");
	  	//test(pkt);
	  	goto drop;
	  }
   
  /* Increase the initial sequence number. */
    if(++iss[3] == 0) {
       if(++iss[2] == 0) {
	       if(++iss[1] == 0) {
	         ++iss[0];
	        }
      }
    }
  ihl = (ip_head->vhl & 0x0f) * 4 ;
	tcp_len = ((u16)(ip_head->len[0])<<8 & 0xff00) + (u16)(ip_head->len[1]) - (u16)ihl;	 
	tcp_head = (struct tcp_hdr *)(pkt + ihl);
	tcp_data_len = tcp_len - ((tcp_head->tcpoffset)>>2);
	tcp_data_ptr = (u8*)tcp_head + ((tcp_head->tcpoffset)>>2);
	srcport = ((u16)(tcp_head->srcport[0])<<8) + ((u16)(tcp_head->srcport[1]));
	destport= ((u16)(tcp_head->destport[0])<<8)+ ((u16)(tcp_head->destport[1]));  
	
	
	
	
	//printf("ipid=%02x%02x\n",ip_head->ipid[0],ip_head->ipid[1]);
	
  /* Demultiplex this segment. */
    
  /* First check any active connections. */
  for(tcp_conn = &tcp_conns[0]; tcp_conn <= &tcp_conns[MAX_CONNS - 1]; ++tcp_conn) {
    if(tcp_conn->tcpstateflags != TCP_CLOSED &&
       destport == tcp_conn->lport &&
       srcport == tcp_conn->rport &&
       tcp_ipaddr_cmp(ip_head->srcipaddr, tcp_conn->ripaddr)) {
      goto found;
     }
   }
  
   /* If we didn't find and active connection that expected the packet,
     either this packet is an old duplicate, or this is a SYN packet
     destined for a connection in LISTEN. If the SYN flag isn't set,
     it is an old packet and we send a RST. */
  if((tcp_head->flags & TCP_CTL) != TCP_SYN) {
    goto reset;
  }
   	//printf("TCP SYNC!\n");
   	
   	/* Next, check listening connections. */
  for(c = 0; c < MAX_LISTENPORTS; ++c) {
    if(destport == tcp_listenports[c])
      goto found_listen;
  }

    /* No matching connection found, so we send a RST packet. */
reset:  
    /* We do not send resets in response to resets. */
    if(tcp_head->flags & TCP_RST) {
      goto drop;
    }
    /*fix me, should add code here*/
  
    goto drop;
    
found_listen:
	   //printf("found listen!\n");
	   /* First we check if there are any connections avaliable. Unused
     connections are kept in the same table as used connections, but
     unused ones have the tcpstate set to CLOSED. Also, connections in
     TIME_WAIT are kept track of and we'll use the oldest one if no
     CLOSED connections are found. Thanks to Eddie C. Dost for a very
     nice algorithm for the TIME_WAIT search. */
     tcp_conn = 0;
     for(c = 0; c < MAX_CONNS; ++c) {
       if(tcp_conns[c].tcpstateflags == TCP_CLOSED) {
         tcp_conn = &tcp_conns[c];
         break;
       }
       if(tcp_conns[c].tcpstateflags == TCP_TIME_WAIT) {
        if(tcp_conn == 0 ||
	        tcp_conns[c].timer > tcp_conn->timer) {
	        tcp_conn = &tcp_conns[c];
          }
       }
     }
     if(tcp_conn == 0) {
    /* All connections are used already, we drop packet and hope that
       the remote end will retransmit the packet at a time when we
       have more spare connections. */
      goto drop;
    }
      /* Fill in the necessary fields for the new connection. */
 
     tcp_conn->rto = tcp_conn->timer = TCP_RTO;
     
     tcp_conn->sa = 0;
     tcp_conn->sv = 4;
     tcp_conn->nrtx = 0;
     tcp_conn->lport = destport;
     tcp_conn->rport = srcport;
     tcp_ipaddr_copy(tcp_conn->ripaddr, ip_head->srcipaddr);
     tcp_conn->tcpstateflags = TCP_SYN_RCVD;
	   
	   
	   tcp_conn->snd_nxt[0] = iss[0];
     tcp_conn->snd_nxt[1] = iss[1];
     tcp_conn->snd_nxt[2] = iss[2];
     tcp_conn->snd_nxt[3] = iss[3];
     tcp_conn->len = 1;
     
     /* rcv_nxt should be the seqno from the incoming packet + 1. */
     tcp_conn->rcv_nxt[3] = tcp_head->seqno[3];
     tcp_conn->rcv_nxt[2] = tcp_head->seqno[2];
     tcp_conn->rcv_nxt[1] = tcp_head->seqno[1];
     tcp_conn->rcv_nxt[0] = tcp_head->seqno[0];
     tcp_add_rcv_nxt(1);
  
    
     /* Parse the TCP MSS option, if present. */
  if((tcp_head->tcpoffset & 0xf0) > 0x50) {
    for(c = 0; c < ((tcp_head->tcpoffset >> 4) - 5) << 2 ;) {
      opt = *((u8*)tcp_head + 20 + c);
      printf("opt=%02x\n",opt);
      if(opt == TCP_OPT_END) {
	    /* End of options. */
	    break;
      } else if(opt == TCP_OPT_NOOP) {
	   ++c;
	   /* NOP option. */
      } else if(opt == TCP_OPT_MSS &&
		           *((u8*)tcp_head + 20 + c +1) == TCP_OPT_MSS_LEN) {
	   /* An MSS option with the right option length. */
     tmp =  ((u16)(*((u8*)tcp_head + 20 + c + 2))<<8) | (u16)(*((u8*)tcp_head + 20 + c + 3));
     tcp_conn->initialmss = tcp_conn->mss =
	    tmp > TCP_MSS? TCP_MSS:tmp;    
	
	   /* And we are done processing options. */
	   break;
      }
     else {
	     /* All other options have a length field, so that we easily
	    can skip past them. */
	   if(*((u8*)tcp_head + 20 + c +1 ) == 0) {
	     /* If the length field is zero, the options are malformed
	     and we don't process them further. */
	      break;
	    }
	     c += *((u8*)tcp_head + 20 + c +1 );
     }   
   }
  }
  
tcp_send_synack:
	   tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
	   tcp_head->flags = TCP_SYN | TCP_ACK; 
	   tcp_head->optdata[0] = TCP_OPT_MSS;
     tcp_head->optdata[1] = TCP_OPT_MSS_LEN;
     tcp_head->optdata[2] = (TCP_MSS) / 256;
     tcp_head->optdata[3] = (TCP_MSS) & 255;
     tcp_len = 20 + 20 + TCP_OPT_MSS_LEN;
     tcp_head->tcpoffset = ((20 + TCP_OPT_MSS_LEN)/4)<<4;
     tcp_conn->tcpstateflags = TCP_SYN_RCVD;
     goto tcp_send;

found:
	 //printf("found!\n");

	    /* We do a very naive form of TCP reset processing; we just accept
     any RST and kill our connection. We should in fact check if the
     sequence number of this reset is wihtin our advertised window
     before we accept the reset. */
    if(tcp_head->flags & TCP_RST) {
      tcp_conn->tcpstateflags = TCP_CLOSED;
      printf("tcp: got reset, aborting connection.");
      goto drop;
     }
     /*
     if(tcp_head->flags == TCP_FIN | TCP_ACK) {
     	 tcp_conn->tcpstateflags = TCP_FIN_WAIT_2;
     	 tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
     	 tcp_head->flags = TCP_FIN | TCP_ACK;
       goto tcp_send_nodata;
      }
      */
     /* Calculated the length of the data, if the application has sent
     any data to us. */
     c = (tcp_head->tcpoffset >> 4) << 2;
	   
  /* First, check if the sequence number of the incoming packet is
     what we're expecting next. If not, we send out an ACK with the
     correct numbers in. */
#if 0     
  if(!(((tcp_conn->tcpstateflags & TCP_TS_MASK) == TCP_SYN_SENT) &&
       ((tcp_head->flags & TCP_CTL) == (TCP_SYN | TCP_ACK)))) {
    if((tcp_len > 0 || ((tcp_head->flags & (TCP_SYN | TCP_FIN)) != 0)) &&
       (tcp_head->seqno[0] != tcp_conn->rcv_nxt[0] ||
        tcp_head->seqno[1] != tcp_conn->rcv_nxt[1] ||
        tcp_head->seqno[2] != tcp_conn->rcv_nxt[2] ||
        tcp_head->seqno[3] != tcp_conn->rcv_nxt[3])) {
      goto drop;
    }
  }
#endif
    if( tcp_head->seqno[0] != tcp_conn->rcv_nxt[0] ||
        tcp_head->seqno[1] != tcp_conn->rcv_nxt[1] ||
        tcp_head->seqno[2] != tcp_conn->rcv_nxt[2] ||
        tcp_head->seqno[3] != tcp_conn->rcv_nxt[3] ) {
        /*
        printf("seq=%02x %02x %02x %02x, rcv_nxt=%02x %02x %02x %02x\n",
          tcp_head->seqno[0],tcp_head->seqno[1],tcp_head->seqno[2],tcp_head->seqno[3],
          tcp_conn->rcv_nxt[0],tcp_conn->rcv_nxt[1],tcp_conn->rcv_nxt[2],tcp_conn->rcv_nxt[3]);	
        */
      goto drop;
    }
 
    
     //uip_flags = UIP_ACKDATA;
  
  
  
  
  /* Do different things depending on in what state the connection is. */
  //printf("tcpstateflags=%02x\n",tcp_conn->tcpstateflags);
  
  switch(tcp_conn->tcpstateflags & TCP_TS_MASK) {
    /* CLOSED and LISTEN are not handled here. CLOSE_WAIT is not
	implemented, since we force the application to close when the
	peer sends a FIN (hence the application goes directly from
	ESTABLISHED to LAST_ACK). */
	case TCP_SYN_RCVD:
	  //printf("state=TCP_SYN_RCVD\n");
	    if(!(tcp_head->flags & TCP_ACK)){
      	 goto drop;/*if not ack, we go to drop*/
      	}  
      tcp_conn->tcpstateflags = TCP_ESTABLISHED;
      tcp_conn->len = 0;
      seq_add32(tcp_conn->snd_nxt, 1);
      break;
   
	case TCP_ESTABLISHED:
	  //	printf("state=TCP_ESTABLISHED\n");
   
      if(tcp_head->flags == (TCP_FIN | TCP_ACK)){
      	  tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
      	  tcp_head->flags = (TCP_FIN |TCP_ACK);
      	  //seq_add32(tcp_conn->snd_nxt, 1);
   	      //seq_add32(tcp_conn->rcv_nxt, 1);
      	  tcp_conn->tcpstateflags=TCP_FIN_WAIT_2;
      	  goto tcp_send_nodata;
      }
   
      if((tcp_len - 20) > 0 && !(tcp_conn->tcpstateflags & TCP_STOPPED)) {
      tcp_add_rcv_nxt(tcp_len-20); /*20 bytes for tcp header*/
      tmp = ((u16)tcp_head->wnd[0] << 8) + (u16)tcp_head->wnd[1];
      if(tmp > tcp_conn->initialmss || tmp == 0) {
         tmp = tcp_conn->initialmss;
       }
      tcp_conn->mss = tmp;
      UpperHandler(tcp_data_ptr,tcp_data_len,0,0);
      
      if(tcp_conn->appstate.state==STATE_WAITING)
      	{
      		tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
      		goto tcp_send_ack;
      	}
      	
     }
      break;
   case TCP_LAST_ACK:
     //printf("state=TCP_LAST_ACK\n");
     if(tcp_head->flags != (TCP_FIN | TCP_ACK)){
	          goto drop;/*if not FIN, we go to drop*/
	 }
     //printf("send back ack now\n");					  
   	 seq_add32(tcp_conn->snd_nxt, 1);
   	 seq_add32(tcp_conn->rcv_nxt, 1);
   	 tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
     tcp_conn->tcpstateflags = TCP_CLOSED;
     goto tcp_send_ack;	
   case TCP_FIN_WAIT_2:
   	 //printf("state=TCP_FIN_WAIT_2\n");
   	 tcp_conn->tcpstateflags = TCP_CLOSED;
   	 break;  
     
  }
       goto drop;

      
tcp_send_ack:
  tcp_head->flags = TCP_ACK;
tcp_send_nodata:
  tcp_len = IPTCPH_LEN;
tcp_send_noopts:
  tcp_head->tcpoffset = (TCPH_LEN / 4) << 4;
      
	  //printf("tcp_len=%d\n",tcp_len);
	      
tcp_send:
	   /* We're done with the input processing. We are now ready to send a
     reply. Our job is to fill in all the fields of the TCP and IP
     headers before calculating the checksum and finally send the
     packet. */
    
     tcp_head->srcport[0]= (u8)(tcp_conn->lport>>8);
     tcp_head->srcport[1]= (u8)(tcp_conn->lport & 0xff);
     tcp_head->destport[0]= (u8)(tcp_conn->rport>>8);
     tcp_head->destport[1]= (u8)(tcp_conn->rport & 0xff);
     tcp_head->ackno[0] = tcp_conn->rcv_nxt[0];
     tcp_head->ackno[1] = tcp_conn->rcv_nxt[1];
     tcp_head->ackno[2] = tcp_conn->rcv_nxt[2];
     tcp_head->ackno[3] = tcp_conn->rcv_nxt[3];
  
     tcp_head->seqno[0] = tcp_conn->snd_nxt[0];
     tcp_head->seqno[1] = tcp_conn->snd_nxt[1];
     tcp_head->seqno[2] = tcp_conn->snd_nxt[2];
     tcp_head->seqno[3] = tcp_conn->snd_nxt[3];	   
	   
	   if(tcp_conn->tcpstateflags & TCP_STOPPED) {
    /* If the connection has issued uip_stop(), we advertise a zero
       window so that the remote host will stop sending data. */
      tcp_head->wnd[0] = tcp_head->wnd[1] = 0;
    } else {
      tcp_head->wnd[0] = ((TCP_RECEIVE_WINDOW) >> 8);
      tcp_head->wnd[1] = ((TCP_RECEIVE_WINDOW) & 0xff);
    }
tcp_send_noconn:
       
     tcp_head->urgp[0] = tcp_head->urgp[1] = 0;
	   
	   tx_pkt = (uchar *)NetTxPacket;
	   tx_pkt += NetSetEther (tx_pkt, NetServerEther, PROT_IP);
	   ip_head = (struct ip_hdr*)tx_pkt;
	   
	   ip_head->vhl  = 0x45;		/* IP_HDR_SIZE / 4 (not including UDP) */
	   ip_head->tos   = 0;
	   //ip_head->len[0] = (u8)((20 + tcp_len) >> 8)  ;
	   //ip_head->len[1] = (u8)((20 + tcp_len) & 0xff);
	   ip_head->len[0] = (u8)((tcp_len) >> 8)  ;
	   ip_head->len[1] = (u8)((tcp_len) & 0xff);
	   ip_head->ttl = IP_TTL;
 
	   ++ipid;
     ip_head->ipid[0] = ipid >> 8;
     ip_head->ipid[1] = ipid & 0xff;
	   ip_head->ipoffset[0] = (u8)(htons(0x4000)>>8);	/* No fragmentation */
	   ip_head->ipoffset[1] = (u8)(htons(0x4000) & 0xff);
	   ip_head->ttl   = 255;
	   ip_head->proto     = IPPROTO_TCP;		/* TCP */
	   ip_head->ipchksum[0]   = 0;
	   ip_head->ipchksum[1]   = 0;
	   tcp_ipaddr_copy(ip_head->srcipaddr, &NetOurIP);
	   tcp_ipaddr_copy(ip_head->destipaddr, tcp_conn->ripaddr);
	   tmp   = ~NetCksum((uchar *)ip_head, IP_HDR_SIZE_NO_UDP / 2);
	   ip_head->ipchksum[0]   = (u8)(tmp>>8);
	   ip_head->ipchksum[1]   = (u8)(tmp & 0xff);
	   
	   tcp_head->tcpchksum[0]=0;
	   tcp_head->tcpchksum[1]=0;
	   
	   tmp=~tcp_chksum(ip_head);
	   tcp_head->tcpchksum[0]= (u8)(tmp>>8);
	   tcp_head->tcpchksum[1]= (u8)(tmp & 0xff);
	   //printf("send ipid=%02x%02x\n",ip_head->ipid[0],ip_head->ipid[1]);
	   eth_send(NetTxPacket,14 + 20 + tcp_len);
	   
	   
	
	
drop:
	return;	
}		
				
				
int tcp_send_data(char* data, int len)
{
	 struct ip_hdr * ip_head;
	 struct tcp_hdr * tcp_head=NULL;
	 int ihl; /*ip header length and tcp packet length*/
	 int i;
	 u16 tcp_len, destport, srcport,tmp;
	 uchar * tx_pkt;
	 tcp_len = 20 + len;
	 tcp_head = (struct tcp_hdr*)((uchar *)NetTxPacket + ETHER_HDR_SIZE + 20);
	 
	 tcp_head->srcport[0]= (u8)(tcp_conn->lport>>8);
   tcp_head->srcport[1]= (u8)(tcp_conn->lport & 0xff);
   tcp_head->destport[0]= (u8)(tcp_conn->rport>>8);
   tcp_head->destport[1]= (u8)(tcp_conn->rport & 0xff);
   tcp_head->ackno[0] = tcp_conn->rcv_nxt[0];
   tcp_head->ackno[1] = tcp_conn->rcv_nxt[1];
   tcp_head->ackno[2] = tcp_conn->rcv_nxt[2];
   tcp_head->ackno[3] = tcp_conn->rcv_nxt[3];
  

   tcp_head->seqno[0] = tcp_conn->snd_nxt[0];
   tcp_head->seqno[1] = tcp_conn->snd_nxt[1];
   tcp_head->seqno[2] = tcp_conn->snd_nxt[2];
   tcp_head->seqno[3] = tcp_conn->snd_nxt[3];	   
   
   seq_add32(tcp_conn->snd_nxt, len);
   tcp_head->tcpoffset = 5<<4;
   
   if(len>0){
	 memcpy((u8*)tcp_head + 20, data, len);
	 tcp_head->flags = TCP_PSH | TCP_ACK; 
	 }else{
	 tcp_head->flags = TCP_FIN | TCP_ACK;
	 tcp_conn->tcpstateflags = TCP_LAST_ACK;	
	}
	
	 if(tcp_conn->tcpstateflags & TCP_STOPPED) {
    /* If the connection has issued uip_stop(), we advertise a zero
       window so that the remote host will stop sending data. */
      tcp_head->wnd[0] = tcp_head->wnd[1] = 0;
    } else {
      tcp_head->wnd[0] = ((TCP_RECEIVE_WINDOW) >> 8);
      tcp_head->wnd[1] = ((TCP_RECEIVE_WINDOW) & 0xff);
    }
       
     tcp_head->urgp[0] = tcp_head->urgp[1] = 0;
	   
	   tx_pkt = (uchar *)NetTxPacket;
	   tx_pkt += NetSetEther (tx_pkt, NetServerEther, PROT_IP);
	   ip_head = (struct ip_hdr*)tx_pkt;
	   
	   ip_head->vhl  = 0x45;		/* IP_HDR_SIZE / 4 (not including UDP) */
	   ip_head->tos   = 0;
	   ip_head->len[0] = (u8)((20 + tcp_len) >> 8)  ;
	   ip_head->len[1] = (u8)((20 + tcp_len) & 0xff);
	   ip_head->ttl = IP_TTL;
 
	   ++ipid;
       ip_head->ipid[0] = ipid >> 8;
       ip_head->ipid[1] = ipid & 0xff;
	   ip_head->ipoffset[0] = (u8)(htons(0x4000)>>8);	/* No fragmentation */
	   ip_head->ipoffset[1] = (u8)(htons(0x4000) & 0xff);
	   ip_head->ttl   = 255;
	   ip_head->proto     = IPPROTO_TCP;		/* TCP */
	   ip_head->ipchksum[0]   = 0;
	   ip_head->ipchksum[1]   = 0;
	   tcp_ipaddr_copy(ip_head->srcipaddr, &NetOurIP);
	   tcp_ipaddr_copy(ip_head->destipaddr, tcp_conn->ripaddr);
	   tmp   = ~NetCksum((uchar *)ip_head, IP_HDR_SIZE_NO_UDP / 2);
	   ip_head->ipchksum[0]   = (u8)(tmp>>8);
	   ip_head->ipchksum[1]   = (u8)(tmp & 0xff);
	   
	   tcp_head->tcpchksum[0]=0;
	   tcp_head->tcpchksum[1]=0;
	   
	   tmp=~tcp_chksum(ip_head);
	   tcp_head->tcpchksum[0]= (u8)(tmp>>8);
	   tcp_head->tcpchksum[1]= (u8)(tmp & 0xff);
	   //printf("send ipid=%02x%02x\n",ip_head->ipid[0],ip_head->ipid[1]);
	   eth_send(NetTxPacket,14 + 20 + tcp_len);
	   return tcp_len;
}				
				
void tcp_init(void)
{
	int c;
  for(c = 0; c < MAX_LISTENPORTS; ++c) {
    tcp_listenports[c] = 0;
  }
  for(c = 0; c < MAX_CONNS; ++c) {
    tcp_conns[c].tcpstateflags = TCP_CLOSED;
    tcp_conns[c].appstate.count=0;
    tcp_conns[c].appstate.len=0;
    tcp_conns[c].appstate.buf=load_addr;
    tcp_conns[c].appstate.state=STATE_WAITING;
  }
  NetSetHandler (TcpHandler);
}

void tcp_unlisten(u16 port)
{
	int c;
  for(c = 0; c < MAX_LISTENPORTS; ++c) {
    if(tcp_listenports[c] == port) {
      tcp_listenports[c] = 0;
      return;
    }
  }
}
/*---------------------------------------------------------------------------*/
void tcp_listen(u16 port)
{
	int c;
  for(c = 0; c < MAX_LISTENPORTS; ++c) {
    if(tcp_listenports[c] == 0) {
      tcp_listenports[c] = port;
      return;
    }
  }
}


void tcp_send(u8* pkt, int len)
{
	
	return;
}
