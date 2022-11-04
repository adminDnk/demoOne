#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    	
#define OLED_MODE 0
#define Max_Column	128
    						  
//OLED IIC端口定义  					   
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_6)//SDA IIC接口的时钟信号
#define OLED_SCLK_Set() GPIO_SetBits(GPIOD,GPIO_Pin_6)
#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_7)//SCL IIC接口的数据信号
#define OLED_SDIN_Set() GPIO_SetBits(GPIOD,GPIO_Pin_7)

 		     
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

void IIC_Start();   //模拟IIC起始信号
void IIC_Stop();    //模拟IIC停止信号
void IIC_Wait_Ack();//模拟IIC读取从机应答信号
void Write_IIC_Byte(unsigned char IIC_Byte);//IIC读取一个字节byte
void Write_IIC_Command(unsigned char IIC_Command);//IIC写命令
void Write_IIC_Data(unsigned char IIC_Data);//写数据


//OLED控制用函数
void OLED_WR_Byte(unsigned dat,unsigned cmd);  //选择写数据还是写指令
void OLED_Set_Pos(unsigned char x, unsigned char y);    //设置坐标
void OLED_Display_On(void);  //开显示
void OLED_Display_Off(void);	//关显示   							   		    
void OLED_Init(void);         //初始化
void OLED_Clear(void);         //清屏
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);  //显示字符
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);//显示数字
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);	 //显示字符串
void OLED_ShowCHinese(u8 x,u8 y,u8 no);             //显示汉字
void Delay_50ms(unsigned int Del_50ms);   //延迟函数
void Delay_1ms(unsigned int Del_1ms);

#endif  
	 



