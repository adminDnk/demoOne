#include "DHT11.h"

//#include "stdio.h"


uint16_t Rxbuff[5];

void DHT11_GPIO_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
	
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,  ENABLE);

	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_SetBits(GPIOB,  GPIO_Pin_11);

}

void DHT11_GPIO_Init1(void)
{
   GPIO_InitTypeDef  GPIO_InitStructure;
	
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB,  ENABLE);

	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_SetBits(GPIOB,  GPIO_Pin_11);

}

static uint8_t DHT11_Back()
{
   uint8_t i =200;
	
	 while(read_data && i--); //等待低电平的到来
	 i= 200;
	 while(!read_data && i--); //等待高电平的到来
   return 0;
}

void DHT11_Start(void)
{
     data0;
	   ms_delay(20);
	
     data1;
	   us_delay(10);
     DHT11_GPIO_Init1();
     while(DHT11_Back());
}

void DHT11_ReceptionBuff()
{
   uint8_t y=1;
	 uint16_t i;
	 uint8_t x;
 
   for(x=0;x<5;x++)
	{
	    i=0;
		  for(y=1;y<9;y++)
		{
		   while(read_data)
			 {
			    __nop();
			 }
			 us_delay(40);
			  while(!read_data)
			 {
			    __nop();
			 }
		    i= i<<1;
			 us_delay(30);
       if(read_data)
			 {
			    i |=1;
			 }
			 while(read_data);
		}
	   Rxbuff[x] =i;
	}
}

void DHT11_UpdateData()
{
  DHT11_GPIO_Init();//初始化总线
	DHT11_Start();//发出开始信号然后释放总线
	DHT11_ReceptionBuff();//将数据更新到Rxbuff

}

