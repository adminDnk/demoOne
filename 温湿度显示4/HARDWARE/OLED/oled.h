#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    	
#define OLED_MODE 0
#define Max_Column	128
    						  
//OLED IIC�˿ڶ���  					   
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_6)//SDA IIC�ӿڵ�ʱ���ź�
#define OLED_SCLK_Set() GPIO_SetBits(GPIOD,GPIO_Pin_6)
#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_7)//SCL IIC�ӿڵ������ź�
#define OLED_SDIN_Set() GPIO_SetBits(GPIOD,GPIO_Pin_7)

 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

void IIC_Start();   //ģ��IIC��ʼ�ź�
void IIC_Stop();    //ģ��IICֹͣ�ź�
void IIC_Wait_Ack();//ģ��IIC��ȡ�ӻ�Ӧ���ź�
void Write_IIC_Byte(unsigned char IIC_Byte);//IIC��ȡһ���ֽ�byte
void Write_IIC_Command(unsigned char IIC_Command);//IICд����
void Write_IIC_Data(unsigned char IIC_Data);//д����


//OLED�����ú���
void OLED_WR_Byte(unsigned dat,unsigned cmd);  //ѡ��д���ݻ���дָ��
void OLED_Set_Pos(unsigned char x, unsigned char y);    //��������
void OLED_Display_On(void);  //����ʾ
void OLED_Display_Off(void);	//����ʾ   							   		    
void OLED_Init(void);         //��ʼ��
void OLED_Clear(void);         //����
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);  //��ʾ�ַ�
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);//��ʾ����
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);	 //��ʾ�ַ���
void OLED_ShowCHinese(u8 x,u8 y,u8 no);             //��ʾ����
void Delay_50ms(unsigned int Del_50ms);   //�ӳٺ���
void Delay_1ms(unsigned int Del_1ms);

#endif  
	 



