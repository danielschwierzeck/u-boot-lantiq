/*
 *  Copyright 2009 Wu Qi Ming, Lantiq
 */
#define MAX_CONNS 40
#define MAX_LISTENPORTS 80
/* The TCP states used in the uip_conn->tcpstateflags. */
#define TCP_CLOSED      0
#define TCP_SYN_RCVD    1
#define TCP_SYN_SENT    2
#define TCP_ESTABLISHED 3
#define TCP_FIN_WAIT_1  4
#define TCP_FIN_WAIT_2  5
#define TCP_CLOSING     6
#define TCP_TIME_WAIT   7
#define TCP_LAST_ACK    8
#define TCP_TS_MASK     15

#define TCP_STOPPED      16

/* Structures and definitions. */
#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20
#define TCP_CTL 0x3f


#define TCP_OPT_END     0   /* End of TCP options list */
#define TCP_OPT_NOOP    1   /* "No-operation" TCP option */
#define TCP_OPT_MSS     2   /* Maximum segment size TCP option */

#define TCP_OPT_MSS_LEN 4   /* Length of TCP MSS option. */

#define IP_TTL         64

#define IPH_LEN    20    /* Size of IP header */

#define TCPH_LEN   20    /* Size of TCP header */

#define IPTCPH_LEN (TCPH_LEN + IPH_LEN)    /* Size of IP +
                                                          TCP
                                                          header */

/*application status*/
#define STATE_WAITING 0
#define STATE_OUTPUT  1
#define STATE_DEBUG   2

/**
 * The TCP maximum segment size.
 *
 * This is should not be to set to more than
 * UIP_BUFSIZE - UIP_LLH_LEN - UIP_TCPIP_HLEN.
 */
#define TCP_MSS    500
 
#define TCP_RECEIVE_WINDOW TCP_MSS
 
 
/**
 * The initial retransmission timeout counted in timer pulses.
 *
 * This should not be changed.
 */
#define TCP_RTO         3


/* The TCP and IP headers. */
struct ip_hdr {
  /* IPv4 header. */
  u8  vhl;
  u8  tos;
  u8  len[2];
  u8  ipid[2];
  u8  ipoffset[2];
  u8  ttl;
  u8  proto;
  u8  ipchksum[2];
  u8  srcipaddr[4];
  u8  destipaddr[4];
};

struct tcp_hdr {  
  /* TCP header. */
  u8 srcport[2],
     destport[2];
  u8 seqno[4],
     ackno[4],
     tcpoffset,
     flags,
     wnd[2];
  u8 tcpchksum[2];
  u8 urgp[2];
  u8 optdata[4];
};

void tcp_init(void);

int tcp_send_data(char* data, int len);

void TcpSetHandler(void * f);

struct httpd_fs_file {
  char *data;
  int len;
};

struct tcp_appstate {
  unsigned char timer;
  //struct psock sin, sout;
  //struct pt outputpt, scriptpt;
  char inputbuf[500];
  char filename[50];
  char state;
  char* buf;
  
  struct httpd_fs_file file;
  int len; /*total length of the packet*/
  //char *scriptptr;
  //int scriptlen;

  unsigned short count; /*bytes processed*/
}tcp_appstate_t;


/**
 * Representation of a uIP TCP connection.
 *
 * The tcp_conn structure is used for identifying a connection. All
 * but one field in the structure are to be considered read-only by an
 * application. The only exception is the appstate field whos purpose
 * is to let the application store application-specific state (e.g.,
 * file pointers) for the connection. The type of this field is
 * configured in the "uipopt.h" header file.
 */
struct tcp_conn {
  u8 ripaddr[6];   /**< The IP address of the remote host. */
  
  u16 lport;        /**< The local TCP port, in network byte order. */
  u16 rport;        /**< The local remote TCP port, in network byte
			 order. */
  
  u8 rcv_nxt[4];    /**< The sequence number that we expect to
			 receive next. */
  u8 snd_nxt[4];    /**< The sequence number that was last sent by
                         us. */
  u16 len;          /**< Length of the data that was previously sent. */
  u16 mss;          /**< Current maximum segment size for the
			 connection. */
  u16 initialmss;   /**< Initial maximum segment size for the
			 connection. */
  u8 sa;            /**< Retransmission time-out calculation state
			 variable. */
  u8 sv;            /**< Retransmission time-out calculation state
			 variable. */
  u8 rto;           /**< Retransmission time-out. */
  u8 tcpstateflags; /**< TCP state and flags. */
  u8 timer;         /**< The retransmission timer. */
  u8 nrtx;          /**< The number of retransmissions for the last
			 segment sent. */

  /** The application state. */
  struct tcp_appstate appstate;
};



void tcp_listen(u16 port);

/**
 * Pointer to the current TCP connection.
 *
 * The uip_conn pointer can be used to access the current TCP
 * connection.
 */
extern struct tcp_conn *tcp_conn;
/* The array containing all uIP connections. */
extern struct tcp_conn tcp_conns[MAX_CONNS];



#define tcp_ipaddr_cmp(addr1, addr2) (((u8 *)addr1)[0] == ((u8 *)addr2)[0] && \
				      ((u8 *)addr1)[1] == ((u8 *)addr2)[1] && \
				      ((u8 *)addr1)[2] == ((u8 *)addr2)[2] && \
				      ((u8 *)addr1)[3] == ((u8 *)addr2)[3])
				      
#define tcp_ipaddr_copy(dest, src) do { \
                     ((u8 *)dest)[0] = ((u8 *)src)[0]; \
                     ((u8 *)dest)[1] = ((u8 *)src)[1]; \
                     ((u8 *)dest)[2] = ((u8 *)src)[2]; \
                     ((u8 *)dest)[3] = ((u8 *)src)[3]; \
                  } while(0)			      
                  
                  
/*---------------------------------------------------------------------------*/
/* u8_t uip_flags:
 *
 * When the application is called, uip_flags will contain the flags
 * that are defined in this file. Please read below for more
 * infomation.
 */
extern u8 uip_flags;

/* The following flags may be set in the global variable uip_flags
   before calling the application callback. The UIP_ACKDATA,
   UIP_NEWDATA, and UIP_CLOSE flags may both be set at the same time,
   whereas the others are mutualy exclusive. Note that these flags
   should *NOT* be accessed directly, but only through the uIP
   functions/macros. */

#define UIP_ACKDATA   1     /* Signifies that the outstanding data was
                               acked and the application should send
                               out new data instead of retransmitting
                               the last data. */
#define UIP_NEWDATA   2     /* Flags the fact that the peer has sent
                               us new data. */
#define UIP_REXMIT    4     /* Tells the application to retransmit the
                               data that was last sent. */
#define UIP_POLL      8     /* Used for polling the application, to
                               check if the application has data that
                               it wants to send. */
#define UIP_CLOSE     16    /* The remote host has closed the
                               connection, thus the connection has
                               gone away. Or the application signals
                               that it wants to close the
                               connection. */
#define UIP_ABORT     32    /* The remote host has aborted the
                               connection, thus the connection has
                               gone away. Or the application signals
                               that it wants to abort the
                               connection. */
#define UIP_CONNECTED 64    /* We have got a connection from a remote
                               host and have set up a new connection
                               for it, or an active connection has
                               been successfully established. */

#define UIP_TIMEDOUT  128   /* The connection has been aborted due to
                               too many retransmissions. */
                  
                  
                  

/**
 * Is new incoming data available?
 *
 * Will reduce to non-zero if there is new data for the application
 * present at the uip_appdata pointer. The size of the data is
 * avaliable through the uip_len variable.
 *
 * \hideinitializer
 */
#define uip_newdata()   (uip_flags & UIP_NEWDATA)

/**
 * Has the connection just been connected?
 *
 * Reduces to non-zero if the current connection has been connected to
 * a remote host. This will happen both if the connection has been
 * actively opened (with uip_connect()) or passively opened (with
 * uip_listen()).
 *
 * \hideinitializer
 */
#define uip_connected() (uip_flags & UIP_CONNECTED)

/**
 * Has the connection been closed by the other end?
 *
 * Is non-zero if the connection has been closed by the remote
 * host. The application may then do the necessary clean-ups.
 *
 * \hideinitializer
 */
#define uip_closed()    (uip_flags & UIP_CLOSE)

/**
 * Has the connection been aborted by the other end?
 *
 * Non-zero if the current connection has been aborted (reset) by the
 * remote host.
 *
 * \hideinitializer
 */
#define uip_aborted()    (uip_flags & UIP_ABORT)

/**
 * Has the connection timed out?
 *
 * Non-zero if the current connection has been aborted due to too many
 * retransmissions.
 *
 * \hideinitializer
 */
#define uip_timedout()    (uip_flags & UIP_TIMEDOUT)

/**
 * Do we need to retransmit previously data?
 *
 * Reduces to non-zero if the previously sent data has been lost in
 * the network, and the application should retransmit it. The
 * application should send the exact same data as it did the last
 * time, using the uip_send() function.
 *
 * \hideinitializer
 */
#define uip_rexmit()     (uip_flags & UIP_REXMIT)

/**
 * Is the connection being polled by uIP?
 *
 * Is non-zero if the reason the application is invoked is that the
 * current connection has been idle for a while and should be
 * polled.
 *
 * The polling event can be used for sending data without having to
 * wait for the remote host to send data.
 *
 * \hideinitializer
 */
#define uip_poll()       (uip_flags & UIP_POLL)

/**
 * Get the initial maxium segment size (MSS) of the current
 * connection.
 *
 * \hideinitializer
 */
#define uip_initialmss()             (uip_conn->initialmss)

/**
 * Abort the current connection.
 *
 * This function will abort (reset) the current connection, and is
 * usually used when an error has occured that prevents using the
 * uip_close() function.
 *
 * \hideinitializer
 */
#define uip_abort()         (uip_flags = UIP_ABORT)
                  
