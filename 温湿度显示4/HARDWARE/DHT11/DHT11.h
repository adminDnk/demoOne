#ifndef _DHT11_H
#define _DHT11_H

#include "stm32f10x.h"
#include "SysTick.h"


#define data1  GPIO_SetBits(GPIOB,  GPIO_Pin_11)
#define data0  GPIO_ResetBits(GPIOB,  GPIO_Pin_11)

#define read_data  GPIO_ReadInputDataBit(GPIOB,  GPIO_Pin_11)


void DHT11_GPIO_Init(void);  //初始化总线
void DHT11_GPIO_Init1(void);
void DHT11_Start(void);    //发出开始信号然后释放总线
void DHT11_ReceptionBuff(void);  //将数据更新到Rxbuff
void DHT11_UpdateData(void);  //发送数据

extern uint16_t Rxbuff[5];




#endif







/***************************************
int  main(void)
{
		ms_delay(2000);
		OLED_Init();
		OLED_Clear();
	
	OLED_ShowCHinese(0,2,6); //当
  OLED_ShowCHinese(16,2,7); //前
	OLED_ShowCHinese(32,2,8); //温
	OLED_ShowCHinese(48,2,9); //度
	OLED_ShowCHinese(66,2,10); //：
	OLED_ShowCHinese(90,2,15); //.
  OLED_ShowCHinese(112,2,11); //C
	
  OLED_ShowCHinese(16,5,6); //当
  OLED_ShowCHinese(32,5,7); //前
	OLED_ShowCHinese(48,5,12); //湿
	OLED_ShowCHinese(64,5,9); //度
	OLED_ShowCHinese(80,5,10); //：
	OLED_ShowCHinese(112,5,13); //.
	
	
	while(1){
		uint16_t i;
		uint8_t k;
		uint8_t kk;
		uint8_t kkk;
		DHT11_UpdateData();
		
		i =  Rxbuff[0]+ Rxbuff[1]+Rxbuff[2]+ Rxbuff[3];
    if(Rxbuff[4] ==i)
		{
		  k=Rxbuff[2];
			kk=Rxbuff[0];
			kkk=Rxbuff[3];
			OLED_ShowNum(74,2,k/10,3,3,TextSize_8X16);
			OLED_ShowNum(82,2,k%10,3,3,TextSize_8X16);
			OLED_ShowNum(98,2,kkk,3,3,TextSize_8X16);
			OLED_ShowNum(88,5,kk/10,3,3,TextSize_8X16);
			OLED_ShowNum(98,55,kkk%10,3,3,TextSize_8X16);
		}
		ms_delay(2000);
	}
	
}
*************************************************/

