#include <asm-generic/gpio.h>

#ifdef CONFIG_ARCH_LANTIQ
#define gpio_status() ltq_gpio_dump()
extern void ltq_gpio_dump(void);
extern void ltq_gpio_init(u32 sso_init_value);
#endif
