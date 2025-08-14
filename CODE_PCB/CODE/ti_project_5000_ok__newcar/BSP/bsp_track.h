#ifndef	__BSP_TRACK_H__
#define __BSP_TRACK_H__
#include "all.h"
 typedef struct HUIDU//第二题结构体
{
      int32_t STAUS;
	 
	  float location_bias;
}HUIDU;
typedef struct{

  float kp,ki,kd;
	float error,last_error,previous_error;
	float pout;
	float integral;
	float dout;
	float output;
	float pwm;
	
}HUIDUPID;
float HUIDU_SHIBIE(HUIDUPID*pid);

extern HUIDUPID huidupid;
extern uint8_t* Data;
uint8_t* Inrared_Get(void);
	
//普通灰度
////////#define L5 DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_1)
////////#define L4 DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_0)//原来是PB0
//////#define L3 DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_30)
//////#define L2 DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_0)
//////#define L1 DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_21)
//////#define ML DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_22)

//////#define MR  DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_25)
//////#define R1 	DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_25)
//////#define R2 	DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_13)
//////#define R3	DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_9)
////////#define R4 	DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_26)
////////#define R5 	DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_29)


//总线灰度
#define L5 DL_GPIO_readPins(GPIOB,DL_GPIO_PIN_25)
#define L4 DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_25)//原来是PB0
#define L3  Data[0]  //LEFT
#define L2	Data[1]
#define L1	Data[2]
#define ML	Data[3]  //MIDDLE
#define MR	Data[4]
#define R1	Data[5]
#define R2  Data[6]
#define R3  Data[7]  //RIGHT
#define R4 	DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_22)
//#define R5 	DL_GPIO_readPins(GPIOA,DL_GPIO_PIN_29)




#endif
