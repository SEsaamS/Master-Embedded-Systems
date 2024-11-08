#include<stdint.h>

#define RCC_BASE       0x40021000
#define PORTA_BASE     0x40010800

#define RCC_APB2ENR     *((volatile uint32_t *)(RCC_BASE+0X18))
#define GPIOA_CRH       *((volatile uint32_t *)(PORTA_BASE+0X04))
#define GPIOA_ODR       *((volatile uint32_t *)(PORTA_BASE+0X0C))

extern void NMI_Handler(void)
{

}
extern void H_fault_Handler(void)
{

}


int main(void)
{
	int i=0;
	RCC_APB2ENR|=1<<2;
	GPIOA_CRH&=0Xff0fffff;
	GPIOA_CRH|=0x00200000;



	while(1)
	{
		GPIOA_ODR|=1<<13;     //set bit 13
		for(i;i<5000;i++);
		GPIOA_ODR&=~(1<<13);  //reset bit 13
		for(i;i<5000;i++);

	}
	return 0;
}