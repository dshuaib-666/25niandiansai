#include "key.h"
/***********************************************
��˾����Ȥ�Ƽ�����ݸ�����޹�˾
Ʒ�ƣ�WHEELTEC
������wheeltec.net
�Ա����̣�shop114407458.taobao.com 
����ͨ: https://minibalance.aliexpress.com/store/4455017
�汾��V1.0
�޸�ʱ�䣺2024-07-019

Brand: WHEELTEC
Website: wheeltec.net
Taobao shop: shop114407458.taobao.com 
Aliexpress: https://minibalance.aliexpress.com/store/4455017
Version: V1.0
Update��2024-07-019

All rights reserved
***********************************************/
/*��ȡ����*/
uint8_t key_num=0;
uint8_t click(void)
{
	
	/*KEY1--Pa15  KEY2--Pa16 KEY3--Pa17*/
	if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_15)==0)
	{
		delay_ms(20);
		while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_15)==0);
		delay_ms(20);
		key_num=1;
	}
	else if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_16)==0)
	{
		delay_ms(20);
		while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_16)==0);
		delay_ms(20);
		key_num=3;
	}
	else if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_27)==0)
	{
			delay_ms(20);
			while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_27)==0);
			delay_ms(20);
			key_num=2;
	}
	else if(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_27)==0)
	{
			delay_ms(20);
			while(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_27)==0);
			delay_ms(20);
			key_num=4;
	}
	else if(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_16)==0)
	{
			delay_ms(20);
			while(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_16)==0);
			delay_ms(20);
			key_num=5;
	}
	else if(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_17)==0)
	{
			delay_ms(20);
			while(DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_17)==0);
			delay_ms(20);
			key_num=6;
	}
	return key_num;
}






uint8_t question_click(void)
{
	uint8_t key_num=0;
	/*KEY1--Pa15  KEY2--Pa16 KEY3--Pa17*/
	if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_15)==0)
	{
		delay_ms(50);
		while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_15)==0);
		
		delay_ms(50);
		key_num=1;
	}
	if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_16)==0)
	{
		delay_ms(50);
		while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_16)==0);
		delay_ms(50);
		key_num=3;
	}
	if(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_27)==0)
	{
			delay_ms(50);
			while(DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_27)==0);
			delay_ms(50);
			key_num=2;
	}

	return key_num;
}



