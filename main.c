#include <stdint.h>

#define RCC_APB2ENR         (*(volatile uint32_t*)0x40021018)
#define GPIOC_CRH           (*(volatile uint32_t*)0x40011004)
#define GPIOC_ODR           (*(volatile uint32_t*)0x4001100C)

void delay(volatile uint32_t count)
{
	while(count--);
}
int main(void)
{
   RCC_APB2ENR |= (1<<4);

   GPIOC_CRH &=~(0xF << 20);
   GPIOC_CRH |= (0x1 << 20);
   /* Loop forever */
	for(;;)
	{
		GPIOC_ODR ^= (1<<13);
		delay(2000000);
	}
}
