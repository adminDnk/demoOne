#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "DHT11.h"

 int main(void)
  {	
		delay_init();	    	  //��ʱ������ʼ��	  
		OLED_Init();		    	//��ʼ��OLED  
		OLED_Clear();         //����

		
		OLED_ShowCHinese(0,2,0);//��
		OLED_ShowCHinese(16,2,1);//��
		OLED_ShowCHinese(32,2,2);//:
		OLED_ShowCHinese(48,2,3);//.
		OLED_ShowCHinese(72,2,5);//C
		
		OLED_ShowCHinese(0,5,4);//ʪ
		OLED_ShowCHinese(32,5,1);//��
		OLED_ShowCHinese(48,5,2);//��
		OLED_ShowCHinese(72,5,6);//%
		
		
		

	while(1) 
	{		
	  uint16_t i;
		uint8_t k;
		uint8_t kk;
		uint8_t kkk;
		DHT11_UpdateData();     //����
		
		i=Rxbuff[0]+Rxbuff[1]+Rxbuff[2]+Rxbuff[3];//У��
		if(Rxbuff[4]==i)
		{
			k=Rxbuff[2];//�¶�
			kk=Rxbuff[0];//ʪ��
			kkk=Rxbuff[3];//�¶�С��
			OLED_ShowNum(40,2,k/10,1,16); //�¶�ʮλ
			OLED_ShowNum(48,2,k%10,1,16); //�¶ȸ�λ
			OLED_ShowNum(64,2,kkk,1,16);  //�¶�С��
			
			OLED_ShowNum(56,5,kk/10,1,16); //ʪ��ʮλ
			OLED_ShowNum(64,5,kk%10,1,16); //ʪ�ȸ�λ
		}
		
		if(k/10>2)				//�¶��Ƿ����30��
		{
		GPIO_ResetBits(GPIOD,GPIO_Pin_3);  //����������
		}else
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_3);    //�ر�
		}
		
		ms_delay(2000);
	}	  
	
}
	