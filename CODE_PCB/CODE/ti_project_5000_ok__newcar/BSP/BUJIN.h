#ifndef BUJIN_H
#define BUJIN_H
#define DOWN 2
#define UP 	 1
#define X    2
#define Y 	 1

#define XSHUN 0
#define XNI   1

#define YFU   0
#define YZHENG 1
#include "stdint.h"
 typedef struct BUJIN//NRF2401接口
{
   uint8_t REXEVICE[40]; //发送缓冲区
   
	
	
	
	
	
}BUJIN;

 void BUJIN_START(int add);


void BUJIN_COUNTER(uint8_t add,int dir,int speed,int distance);

 void BUJIN_STOP(int add);
 
void TWO_BUJIN_START_Init(void);

 void BUJIN_INIT(int add);

 void BUJIN_LOCATION_Init(int add);

void BUJIN_COUNTER_FOUR(uint8_t add,int dir,int speed,int distance);

#endif

