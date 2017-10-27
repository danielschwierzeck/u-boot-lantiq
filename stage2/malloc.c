/*
 * Copyright (c) Wu Qi Ming wqiming@gmail.com
*/

#include <common.h>

#define INTERNAL_SIZE_T size_t
#define PAGE_SZ 4096
#define PAGE_SZ_SHIFT 12
 
struct malloc_chunk
{
  INTERNAL_SIZE_T prev_size; /* Size of previous chunk (if free). */
  INTERNAL_SIZE_T size;      /* Size in bytes, including overhead. */
  struct malloc_chunk* fd;   /* double links -- used only if free. */
  struct malloc_chunk* bk;
};

typedef struct malloc_chunk* mchunkptr;

/*  sizes, alignments */

#define SIZE_SZ                (sizeof(INTERNAL_SIZE_T))
#define MALLOC_ALIGNMENT       (SIZE_SZ + SIZE_SZ)
#define MALLOC_ALIGN_MASK      (MALLOC_ALIGNMENT - 1)
#define MINSIZE                (sizeof(struct malloc_chunk))

#define MAX_MALLOC_SIZE        CONFIG_MALLOC_SIZE
/* conversion from malloc headers to user pointers, and back */

#define chunk2mem(p)   ((void*)((char*)(p) + 2*SIZE_SZ))
#define mem2chunk(mem) ((mchunkptr)((char*)(mem) - 2*SIZE_SZ))

/* pad request bytes into a usable size */

#define request2size(req) \
 (((long)((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) < \
  (long)(MINSIZE + MALLOC_ALIGN_MASK)) ? MINSIZE : \
   (((req) + (SIZE_SZ + MALLOC_ALIGN_MASK)) & ~(MALLOC_ALIGN_MASK)))

/* Check if m has acceptable alignment */

#define aligned_OK(m)    (((unsigned long)((m)) & (MALLOC_ALIGN_MASK)) == 0)

/*
  Physical chunk operations
*/


/* size field is or'ed with PREV_INUSE when previous adjacent chunk in use */

#define INUSE 0x1

#define set_inuse(p) p->size|=INUSE
#define clear_inuse(p) p->size &=~INUSE
#define inuse(p) (p->size & INUSE)

/* Get size, ignoring use bits */

#define chunksize(p)          ((p)->size & ~(INUSE))

/* Set size at head, without disturbing its use bit */

#define set_head_size(p, s)   ((p)->size = (((p)->size & PREV_INUSE) | (s)))

/* Set size/use ignoring previous bits in header */

#define set_head(p, s)        ((p)->size = (s))

/* Set size at footer (only when chunk is not in use) */

#define set_foot(p, s)   (((mchunkptr)((char*)(p) + (s)))->prev_size = (s))



static mchunkptr bin[20]={0}; 


int bin_index(int size)
{
   int idx=0;
   idx=(((size>>5)<1 || size ==(1<<5))?   5:\
       ((size>>6)<1 || size ==(1<<6))?    6:\
       ((size>>7)<1 || size ==(1<<7))?    7:\
       ((size>>8)<1 || size ==(1<<8))?    8:\
       ((size>>9)<1 || size ==(1<<9))?    9:\
       ((size>>10)<1 || size ==(1<<10))?  10:\
       ((size>>11)<1 || size ==(1<<11))?  11:\
       ((size>>12)<1 || size ==(1<<12))?  12:\
       ((size>>13)<1 || size ==(1<<13))?  13:\
       ((size>>14)<1 || size ==(1<<14))?  14:\
       ((size>>15)<1 || size ==(1<<15))?  15:\
       ((size>>16)<1 || size ==(1<<16))?  16:\
       ((size>>17)<1 || size ==(1<<17))?  17:\
       ((size>>18)<1 || size ==(1<<18))?  18:\
       19);
   return idx;
}

/* field-extraction macros */

#define first(b) ((b)->fd)
#define last(b)  ((b)->bk)


ulong mem_malloc_start = CONFIG_RAMSTART_ADDR+CONFIG_RAMSIZE-CONFIG_MALLOC_SIZE;
ulong mem_malloc_end = CONFIG_RAMSTART_ADDR+CONFIG_RAMSIZE;
ulong mem_malloc_brk = CONFIG_RAMSTART_ADDR+CONFIG_RAMSIZE-CONFIG_MALLOC_SIZE;

void *sbrk(ulong increment)
{
    ulong old = mem_malloc_brk;
    ulong new = old + increment;

    if ((new < mem_malloc_start) || (new > mem_malloc_end))
        return (void *)NULL;

    mem_malloc_brk = new;
    
    memset((void *)old, 0, increment);
    return (void *)old;
}


void add_to_bin(mchunkptr chunk)
{
   mchunkptr p;
   mchunkptr BK;
   mchunkptr FD;
   int idx=bin_index(chunksize(chunk));
   p=bin[idx];
   if(p){
      BK=p->bk;
      FD=p->fd;
      p->bk=chunk;
      BK->fd=chunk;
      chunk->fd=p;
      chunk->bk=BK;
   }else{
      chunk->bk=chunk;
      chunk->fd=chunk;
      clear_inuse(chunk);
   }
   bin[idx]=chunk;
}

void remove_from_bin(mchunkptr chunk)
{
   mchunkptr p;
   mchunkptr BK;
   mchunkptr FD;
   int idx=bin_index(chunksize(chunk));
   BK=chunk->bk;
   FD=chunk->fd;
   FD->bk=BK;
   BK->fd=FD;
   if(BK==chunk){
     bin[idx]=NULL; /*clear the link list*/
   }else{
     bin[idx]=FD;
   }
}



mchunkptr malloc_extend_top(int size)
{
   char* brk; 
   int sbrk_size;
   mchunkptr p;
   mchunkptr q;
   int idx;
   sbrk_size=MAX_MALLOC_SIZE;
   q=(mchunkptr)sbrk(sbrk_size);
   q->size=sbrk_size;
   add_to_bin(q);
   return q;
}

mchunkptr split_obtain(mchunkptr chunk, int nb)
{
   mchunkptr p=chunk;
   mchunkptr q;
   remove_from_bin(p);
   if(bin_index(chunksize(p))!=bin_index(nb)){
   q=(mchunkptr)((char*)p+chunksize(p)/2);
   q->size=chunksize(p)/2;
   p->size=chunksize(p)/2;
   add_to_bin(p);
   add_to_bin(q);
   p=split_obtain(p,nb);        
   }else{  
     return p;
   }
}


void* malloc(int bytes)
{ 
    mchunkptr victim;  
    int       idx;                     /* index for bin traversal */
    mchunkptr q;
    int i;
   int nb;
   /* check if mem_malloc_init() was run */
   if ((mem_malloc_start == 0) && (mem_malloc_end == 0)) {
    /* not initialized yet */
    return 0;
   }

   if ((long)bytes < 0) return 0;

   nb = bytes+16;  /* padded request size; */

  
   idx=bin_index(nb);

   
   for(i=idx;i<20;i++){

    q=bin[i];
    if(q){
      q=split_obtain(q, nb);
      goto exit;
     }
   }
   
   /* Space not found, try to use top chunk */ 
   q = malloc_extend_top(nb);
   q = split_obtain(q,nb); 
exit:
   set_inuse(q);
   //display_bin();
   return chunk2mem(q);  
   
}

void* realloc(void* p, size_t n)
{
   void* mem;
   if(!p) {
      return malloc(n);
   }
   mem=malloc(n);
   memcpy(mem,p,n);
   free(p);  
   return mem;
}


mchunkptr merge_chunk(mchunkptr p,mchunkptr q)
{
   mchunkptr chunk;
   if(p->size != q->size) {
       goto error;
   }
   if((u32)p<(u32)q){chunk=p;}
   else{chunk=q;}
   chunk->size=(p->size)<<1;
   memset((u8*)chunk+16,0,chunk->size-16);   
   return chunk;
error:
   return NULL;
}

void grow(mchunkptr chunk)
{
    mchunkptr p;
    if(chunk->size==MAX_MALLOC_SIZE){ 
         add_to_bin(chunk);
         goto exit;   
        }
    if((u32)chunk & chunk->size){
         p=(mchunkptr)((u32)chunk-chunk->size);
    }else{
         p=(mchunkptr)((u32)chunk+chunk->size);
    } 
    if(inuse(p) || (p->size)!=(chunk->size)){
       add_to_bin(chunk);  
       goto exit;
    }else{
       remove_from_bin(p);
       p=merge_chunk(p,chunk);
       grow(p);           
    }
exit:
    return;
}


void free(void* mem)
{
   mchunkptr p=mem2chunk(mem);
   clear_inuse(p);
   grow(p);    
}

