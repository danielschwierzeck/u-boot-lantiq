/*
 *  Copyright (C) 2012 Wu Qi Ming wqiming@gmail.com
 */


#include <common.h>


char * strcpy(char * dest,const char *src)
{
	char *tmp = dest;

    while(*src!='\0'){
       *dest=*src;
        dest++;
        src++;
    }

	return tmp;
}

int strcmp(const char * str1,const char * str2)
{
   while((*str1==*str2)&&*str1!='\0')   
   {   
          str1++;   
          str2++;   
   }   
    
   if(*str1=='\0'&&*str2=='\0') return 1;   
   else return -1;   
}


size_t strlen(const char * s)
{
	int i=0;
	while(*(s+i)!='\0') i++;
	return i;
}

void * memset(void * s,int c,size_t count)
{
    int i;
	for(i=0;i<count;i++){
      *((unsigned char*)s+i)=c;
	}
	return s;
}


void * memcpy(void *dest, const void *src, size_t count)
{
    int i; 
    for(i=0;i<count;i++){
      *((u8*)dest+i)=*((u8*)src+i);
	}
	return dest;
}

void *memchr(const void *s, int c, size_t n)
{
	int i;
	for(i=0;i<n;i++){
       if(*((u8*)s+i)==c) return (void*)((u8*)s+i);
	}
	return NULL;
}


int memcmp(const void * cs,const void * ct,size_t count)
{
	int res = 0;
    int i;
	for(i=0;i<count;i++){
       if(*((u8*)cs+i)!=*((u8*)ct+i)){
            return -1;
	   }
	}
	return res;
}

