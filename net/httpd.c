/*
 *	Copyright 2009 Lantiq
 */


#include <common.h>
#include <command.h>
#include <net.h>
#include "tcp.h"
#include "http-strings.h"
#include "httpd-fsdata.h"
#include "httpd-fsdata.c"
//#include "httpd.h"


#ifdef CONFIG_CMD_HTTPD
#undef	ET_DEBUG




#define ISO_nl      0x0a
#define ISO_return  0x0d
#define ISO_space   0x20
#define ISO_bang    0x21
#define ISO_percent 0x25
#define ISO_period  0x2e
#define ISO_slash   0x2f
#define ISO_colon   0x3a

static int post_flag=0;
static int post_content_length=0;
static int post_content_count=0;
static int post_current_pos=0;
static int post_file_pos=0;
static int post_file_length=0;
static char* post_file_p=NULL;


static char post_boundary[100];
static int post_boundary_found=0;

extern int http_upgrade(ulong srcAddr, int srcLen);

static void
clear_buf(u8* data, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		*(data+i)=0;
	}
	return;
}

static void
print_buf(u8* data, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%02x ",*(data+i));
	}
	printf("\n");
	return;
	
}

static int
readto(struct tcp_appstate *s, char c)
{
	 int i;
	 char value;
	 //printf("readto %02x\n",c);
	 for(i=0;i<((s->len)-(s->count));i++)
	 {
	     value=*(s->buf+s->count+i);
	     //printf("%02x ",value);
	     s->inputbuf[i]= value;
	     if(value==c) break;
	 }
	 s->count+=i+1;
	 //printf("\n");
	 return i+1;
}


static u8 httpd_fs_strcmp(const char *str1, const char *str2)
{
  u8 i;
  i = 0;
loop:

  if(str2[i] == 0 ||
	 str1[i] == '\r' ||
	 str1[i] == '\n') {
				     return 0;
					   }

  if(str1[i] != str2[i]) {
				     return 1;
					   }

   ++i;
   goto loop;
}
								   

int httpd_fs_open(const char *name, struct httpd_fs_file *file)
{
    struct httpd_fsdata_file_noconst *f;

	  for(f = (struct httpd_fsdata_file_noconst *)HTTPD_FS_ROOT;
          f != NULL;
	      f = (struct httpd_fsdata_file_noconst *)f->next) {
	      	if(httpd_fs_strcmp(name, f->name) == 0) {
		        file->data = f->data;
   	            file->len = f->len;
				return 1;
			   }
      	    }
	  return 0;
}
														  

static void send_data(struct tcp_appstate *s, const char *data, int len)
{
	int slen;
	int count=0;

  if(len==0){/*no data, means FIN*/
  	 tcp_send_data(0,0); 
     return;
  }
	while(len>0){
	//printf("send_data!\n");
	//print_buf(data,len);
	 if(len>tcp_conn->mss){
	 	  slen=tcp_conn->mss;
	  }else{
	  	slen=len;
	  }
	 len-=slen;  
	 tcp_send_data(data+count, slen);
	 count+=slen;
  }

  //tcp_send_data(data, len);
	return;
}

static void send_headers(struct tcp_appstate *s, const char *statushdr)
{
	 char *ptr;


   send_data(s, statushdr, strlen(statushdr));

  ptr = strrchr(s->filename, ISO_period);

  if(ptr == NULL) {
    send_data(s, http_content_type_binary, strlen(http_content_type_binary));
  } else if(strncmp(http_html, ptr, 5) == 0 ||
            strncmp(http_shtml, ptr, 6) == 0) {
    send_data(s, http_content_type_html, strlen(http_content_type_html));
  }else if(strncmp(http_css, ptr, 4) == 0) {
    send_data(s, http_content_type_css, strlen(http_content_type_css));
  } else if(strncmp(http_png, ptr, 4) == 0) {
    send_data(s, http_content_type_png, strlen(http_content_type_png));
  } else if(strncmp(http_gif, ptr, 4) == 0) {
    send_data(s, http_content_type_gif, strlen(http_content_type_gif));
  } else if(strncmp(http_jpg, ptr, 4) == 0) {
    send_data(s, http_content_type_jpg, strlen(http_content_type_jpg));
  }else {
    send_data(s, http_content_type_plain, strlen(http_content_type_plain));
  }
  
}

static void send_file(struct tcp_appstate *s)
{
	 send_data(s, s->file.data, s->file.len);

}

static int find_value(char* str, int len, struct tcp_appstate *s)
{
	 int flag=0;
	 int read_len=0;
	 printf("find value %s\n", str);
	 do{
	 	clear_buf(s->inputbuf, 500);
	  read_len=readto(s,ISO_nl);
	  
	  if(strncmp(str, s->inputbuf, len) == 0){
	  	printf("readlen=%d\n",read_len);
	    printf("%s\n",s->inputbuf);
	  	 flag=1;
	  	 break;
	  }
	 }while((s->count) < (s->len));
	 
	 return flag; 
}

static int find_post_file_length(struct tcp_appstate *s)
{
	  char *end=NULL;
	  char *start=s->buf+s->count;
	  int total_len=s->len - s->count;
	  int i;
	  for(i=0;i<total_len;i++){
	    end=s->buf+s->count+i;
	    if(*end==0x2d && *(end+1)==0x2d){
	    	if(strncmp(end+2, post_boundary, strlen(post_boundary)) ==0 ){
         break;
        }
	    }
	  }
	  end-=2; /*remove 2 bytes for CRLF*/
	  printf("end=%08x\n",(u32)end);
	  
	  return end-start;
}

static void
move_to_dual_CRLF(struct tcp_appstate *s)
{
	int i;
	for(i=0;i<s->len-s->count;i++)
      	{
      		
      		if(s->buf[s->count+i]==ISO_return &&
      			 s->buf[s->count+i+1]==ISO_nl &&
      			 s->buf[s->count+i+2]==ISO_return &&
      			 s->buf[s->count+i+3]==ISO_nl){
      			 	s->count+=i;
     			 	 break;
        	}
      	}
	return;
}

static void
handle_output(struct tcp_appstate *s)
{
	char *ptr;
  int flag;
  
  //printf("handle output!\n");
  
  if(post_flag ){
  	s->count=(s->count) + strlen(post_boundary)+ 2 ;
    //printf("buf=%08x\n",(u32)(s->buf + s->count));
    move_to_dual_CRLF(s);
    s->count=(s->count)+4;
    post_file_p=s->buf + s->count;
    //printf("buf=%08x\n",(u32)(post_file_p));
    post_file_length=find_post_file_length(s);
    //printf("file len=%d\n",post_file_length);
    
    httpd_fs_open(http_wait_html, &s->file);
	  strcpy(s->filename, http_wait_html);
	  send_headers(s, http_header_200);
  	send_file(s);
    send_data(s, 0, 0);
    
    memcpy((char*)0x80800000,post_file_p,post_file_length);
	post_file_p = 0x80800000;
	http_upgrade((u32)post_file_p, post_file_length);
    
  	post_flag=0;
  	post_content_length=0;
    post_content_count=0;
    post_current_pos=0;
    post_boundary_found=0;
    post_file_length=0;
    post_file_p=NULL;
   
	  
    s->len=0;
    s->count=0;
    return;
  }
  
  if(!httpd_fs_open(s->filename, &s->file)) {
  	 printf("open file error!\n");
     httpd_fs_open(http_404_html, &s->file);
	   strcpy(s->filename, http_404_html);
 
  }
  
  	 send_headers(s, http_header_200);
  	 send_file(s);
     send_data(s, 0, 0);
  
  
  return;
}





static int find_boundary(struct tcp_appstate *s)
{
	  int flag=0;
	  char *needle="boundary=";
    char *p=NULL;
	  flag=find_value("Content-Type",strlen("Content-Type"), s);
    p=strstr(s->inputbuf,needle); 	  
	  if(p){
	  	clear_buf(post_boundary, 100);
	  	strcpy(post_boundary, p+9);
	  	//printf("boundary=%s\n",post_boundary);
	  }
	  
	  return flag;
}






static void
handle_post(struct tcp_appstate *s)
{
	 int i;
	 char tmp;
	 char *p=NULL;
	 int found_flag=0;
   //print_buf(s->buf,s->len);
  
   if(post_boundary_found==0){
   	  
     	post_boundary_found= find_boundary(s);  
      
   }
   
   if(post_content_length==0){
   	  s->count=0;
      found_flag=find_value("Content-Length",strlen("Content-Length"), s);
      if(found_flag==0){
      	/*if not found, then wait for new packets*/
      	s->state = STATE_WAITING;
      
      }	else {
      	//printf("value found!"); 
      	//printf("%02x\n",s->inputbuf[strlen("Content-Length")+2]);
      	for(i=0;i<500;i++)
      	{
      		tmp=s->inputbuf[strlen("Content-Length")+2+i];
      		if(tmp==ISO_return) break;
          post_content_length= (post_content_length*10)+(tmp-0x30);     		
      	}
      	//printf("post_content_length=%d\n",post_content_length);
      	
      	//printf("s->len=%d, s->count=%d\n",s->len,s->count);
      	//joelin for firefox bugfix
      	if ( s->buf[s->count]==ISO_return &&
      			 s->buf[s->count+1]==ISO_nl ) s->count+=2;
      	else {
      			  move_to_dual_CRLF(s);// s->count, move to   \r\n
      	
      	s->count=s->count+4;/*remove dual CRLF*/
       }//joelin for firefox
      	//printf("after move s->len=%d, s->count=%d\n",s->len,s->count);
      	post_content_count=(s->len)-(s->count);
      	//printf("post_content_count=%d\npost_content_length=%d\n",post_content_count,post_content_length); 
		    if(post_content_count==post_content_length){
      		s->state=STATE_OUTPUT;
      	}else{ 
      	  s->state = STATE_WAITING;
      	}  
      }
   }else if(post_content_count==post_content_length){
      	s->state=STATE_OUTPUT;   	
   }else{
   	    s->state = STATE_WAITING;
   }
  
    return; 
}

static void
handle_input(struct tcp_appstate *s)
{
  int i,len;
	
  //printf("handle input!\n");
  //print_buf(s->buf,s->len);
  if(post_flag) {
    handle_post(s);
	  return;
    }
  clear_buf(s->inputbuf, 500);	
  s->count=0;
  len=readto(s, ISO_space);
  //printf("got\n");
  //print_buf(s->inputbuf,len);
  if(strncmp(s->inputbuf, http_get, 4) == 0) {
    //printf("http get!\n");
    len=readto(s, ISO_space);
    if(s->inputbuf[0] != ISO_slash) {
     goto exit;
    }
    if(s->inputbuf[1] == ISO_space) {
       strncpy(s->filename, http_index_html, sizeof(s->filename));
    } else {
       s->inputbuf[len + 1] = 0;
       strncpy(s->filename, &s->inputbuf[0], sizeof(s->filename));
       //printf("file=%s\n",s->filename);
    }
    s->state = STATE_OUTPUT;    
  }else if(strncmp(s->inputbuf, http_post, 5) == 0){
  	//printf("http post!\n");
  	post_flag=1;
	  handle_post(s);
	  return;
  }else{
    print_buf(s->buf,s->len);
    printf("unsupported method!\n");
  }
  

exit:
  s->count=0;
  s->len=0;   	 
  return;
}



static void
handle_connection(struct tcp_appstate *s)
{
  
  handle_input(s);
  if(s->state == STATE_OUTPUT) {
    handle_output(s);
  }
  return;
}


static void
HttpdHandler (uchar * data, int len, unsigned unused1, unsigned unused2)
{
	
	struct tcp_appstate *s = (struct tcp_appstate *)&(tcp_conn->appstate);
	int i;

  //print_buf(data,len);
  
  memcpy(s->buf + s->len, data, len); 
  s->len= s->len + len;
  if((s->len)%(102400)==0){
    printf("#");
  }
  //printf("httpdhadler s->len=%d, s->count=%d\n",s->len,s->count);
  //printf("httphandler post_content_length=%d\n",post_content_length);
  //printf("httphandler post_content_count=%d\n",post_content_count);
  if(post_content_length>0){
  	post_content_count +=len;
    handle_connection(s);
  }else if(( *(data+len-2) == ISO_return ) && (*(data+len-1) == ISO_nl)){  
    
    handle_connection(s);
  }else{
  	s->state = STATE_WAITING;
  }
	return;
	
}

void HttpSend (uchar * pkt, unsigned len)
{
	
	return;
}


void HttpdStart (void)
{
   printf("http server start...\n");
   tcp_init();
   TcpSetHandler(HttpdHandler);
   tcp_listen(80);
   
}



#endif
