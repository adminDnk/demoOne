#include "beep.h"

void Beep_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG, ENABLE);	 //ʹ��PC,D,G�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_3|GPIO_Pin_8;	 //PD3,PD6�������  
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOD, &GPIO_InitStructure);	  //��ʼ��GPIOD3,6
}






