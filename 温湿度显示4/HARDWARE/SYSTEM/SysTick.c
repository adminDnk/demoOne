#include "SysTick.h"

/*ϵͳ��ʱ������дms��ʱ������us��ʱ����*/

void 	ms_delay(uint32_t ms)
{
		uint32_t i;
		SysTick_Config(72000);
		for(i=0;i<ms;i++)
		{
				while( !((SysTick->CTRL)&(1<<16)) );		//�ж�SysTick->CTRL�Ĵ�����ֵ�Ƿ�Ϊ�㣨��̫��������
			
		}
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;		//ʧ��SysTick
}


void 	us_delay(uint32_t us)
{
		uint32_t i;
		SysTick_Config(72);
		for(i=0;i<us;i++)
		{
				while( !((SysTick->CTRL)&(1<<16)) );		//�ж�SysTick->CTRL�Ĵ�����ֵ�Ƿ�Ϊ�㣨��̫��������
			
		}
		SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;		//ʧ��SysTick
}


