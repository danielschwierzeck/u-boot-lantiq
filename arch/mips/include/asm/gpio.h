#include <asm-generic/gpio.h>

#ifdef CONFIG_LANTIQ_GPIO
#define gpio_status() 	gpio_info()
void gpio_info(void);
#endif
