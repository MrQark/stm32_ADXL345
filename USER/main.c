#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "ADXL.h"
#include "key.h"  


//ALIENTEK ̽����STM32F407������ ʵ��24
//IIC ʵ�� --�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK



//Ҫд�뵽24c02���ַ�������


int main(void)
{ 
	u8 key;
	u8 *temp;
	float temx=0.00;
	float temy=0.00;
	float temz=0.00;
  float a=0.00;	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	uart_init(115200);	//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ�� 
	KEY_Init(); 				//������ʼ��  
	ADXL_init();			//IIC��ʼ�� 
 	POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"IIC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/6");	 
	while(1)
	{
    
		temp=ADXL_read();
    temx=data_x(temp);
		temy=data_y(temp);
		temz=data_z(temp);
 	  LCD_ShowxNum(30,130,temx,8,16,0);
		
//		LCD_ShowxNum(30,150,temp[0],8,16,0);
//		LCD_ShowxNum(30,170,temp[1],8,16,0);
//		LCD_ShowxNum(30,190,temp[2],8,16,0);
//		LCD_ShowxNum(30,210,temp[3],8,16,0);
//		LCD_ShowxNum(30,230,temp[4],8,16,0);
//		LCD_ShowxNum(30,250,temp[5],8,16,0);
		
		LCD_ShowxNum(30,150,temy,8,16,0);
		LCD_ShowxNum(30,170,temz,8,16,0);
		printf("X:%f    ",temx);
		printf("Y:%f    ",temy);
		printf("Z:%f    ",temz);
	}
	return 0;
}
