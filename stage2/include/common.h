#include <types.h>
#include <regdef.h>
#include <cp0regdef.h>
#include <asm.h>
#include <addrspace.h>
#include <mipsregs.h>
#include <cacheops.h>
#include <config.h>
#include <autoconf.h>

#ifdef CONFIG_DRIVER_AR10
#include <ar10.h>
#endif

#ifdef CONFIG_DRIVER_VR9
#include <vr9.h>
#endif
/*commonly used functions*/

void * memcpy(void *dest, const void *src, size_t count);
void * memset(void * s,int c,size_t count);
void* malloc(int bytes);
