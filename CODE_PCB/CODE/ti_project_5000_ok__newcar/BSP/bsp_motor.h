#ifndef	__BSP_MOTOR_H__
#define __BSP_MOTOR_H__

#include "all.h"
#define ABS(a)      (a>0 ? a:(-a))


 typedef struct Encoder
{
	int32_t Encoder_Left;//左边电机编码值
	int32_t Encoder_Right;//右边电机编码值
	 
	  
}ENCODER;

extern ENCODER Encoder;

extern int32_t Get_Encoder_countA,Get_Encoder_countB,encoderA_cnt,encoderB_cnt;

void motor_init(void);
void Set_PWM(int pwma,int pwmb);
void motor_stop();

#endif
