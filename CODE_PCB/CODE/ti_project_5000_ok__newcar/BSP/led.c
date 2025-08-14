#include "led.h"
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
void LED_ON(void)
{
	DL_GPIO_clearPins(LED1_PORT,LED1_PIN_14_PIN);
}
void LED2_ON(void)
{
	DL_GPIO_setPins(GPIOB,DL_GPIO_PIN_9);
}
void LED2_OFF(void)
{
	DL_GPIO_clearPins(GPIOB,DL_GPIO_PIN_9);
}
void LED_OFF(void)
{
	DL_GPIO_setPins(LED1_PORT,LED1_PIN_14_PIN);
}

void LED_Toggle(void)
{
	DL_GPIO_togglePins(LED1_PORT,LED1_PIN_14_PIN);
}

void LED_Flash(uint16_t time)
{
	static uint16_t temp;
	if(time==0) LED_ON();
	else if(++temp==time) LED_Toggle(),temp=0;
}


