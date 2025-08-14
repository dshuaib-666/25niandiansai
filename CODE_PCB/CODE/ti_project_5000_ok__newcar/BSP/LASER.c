#include "CSZ_ALL.h"

void LASER_ON(void)
{
	//DL_GPIO_setPins(GPIOA,DL_GPIO_PIN_13);
DL_GPIO_clearPins(GPIOB,DL_GPIO_PIN_3);//gpio清除函数

}
void LASER_OFF(void)
{
	DL_GPIO_setPins(GPIOB,DL_GPIO_PIN_3);//gpio清除函数

}
