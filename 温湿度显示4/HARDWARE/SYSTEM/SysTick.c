#include "SysTick.h"

/*系统定时器，编写ms延时函数和us延时函数*/

void 	ms_delay(uint32_t ms)
{
		uint32_t i;
		SysTick_Config(72000);
		for(i=0;i<ms;i++)
		{
				while( !((SysTick->CTRL)&(1<<16)) );		//判断SysTick->CTRL寄存器的值是否为零（不太懂操做）
			
		}
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;		//失能SysTick
}


void 	us_delay(uint32_t us)
{
		uint32_t i;
		SysTick_Config(72);
		for(i=0;i<us;i++)
		{
				while( !((SysTick->CTRL)&(1<<16)) );		//判断SysTick->CTRL寄存器的值是否为零（不太懂操做）
			
		}
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;		//失能SysTick
}


