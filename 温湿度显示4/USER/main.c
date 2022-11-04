#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "DHT11.h"

 int main(void)
  {	
		delay_init();	    	  //延时函数初始化	  
		OLED_Init();		    	//初始化OLED  
		OLED_Clear();         //清屏

		
		OLED_ShowCHinese(0,2,0);//温
		OLED_ShowCHinese(16,2,1);//度
		OLED_ShowCHinese(32,2,2);//:
		OLED_ShowCHinese(48,2,3);//.
		OLED_ShowCHinese(72,2,5);//C
		
		OLED_ShowCHinese(0,5,4);//湿
		OLED_ShowCHinese(32,5,1);//度
		OLED_ShowCHinese(48,5,2);//：
		OLED_ShowCHinese(72,5,6);//%
		
		
		

	while(1) 
	{		
	  uint16_t i;
		uint8_t k;
		uint8_t kk;
		uint8_t kkk;
		DHT11_UpdateData();     //更新
		
		i=Rxbuff[0]+Rxbuff[1]+Rxbuff[2]+Rxbuff[3];//校验
		if(Rxbuff[4]==i)
		{
			k=Rxbuff[2];//温度
			kk=Rxbuff[0];//湿度
			kkk=Rxbuff[3];//温度小数
			OLED_ShowNum(40,2,k/10,1,16); //温度十位
			OLED_ShowNum(48,2,k%10,1,16); //温度个位
			OLED_ShowNum(64,2,kkk,1,16);  //温度小数
			
			OLED_ShowNum(56,5,kk/10,1,16); //湿度十位
			OLED_ShowNum(64,5,kk%10,1,16); //湿度个位
		}
		
		if(k/10>2)				//温度是否大于30度
		{
		GPIO_ResetBits(GPIOD,GPIO_Pin_3);  //蜂鸣器响起
		}else
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_3);    //关闭
		}
		
		ms_delay(2000);
	}	  
	
}
	