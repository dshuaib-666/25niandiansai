#include "bsp_beep.h"



void beep_init(void)
{
	printf("Buzzer initialized successfully\r\n");
}

void beep_on(void)
{
	DL_GPIO_clearPins(BEEP_PORT,BEEP_PIN_12_PIN);
	
}

void beep_off(void)
{
	DL_GPIO_setPins(BEEP_PORT,BEEP_PIN_12_PIN);
}
