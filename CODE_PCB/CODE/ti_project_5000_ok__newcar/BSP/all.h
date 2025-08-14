#ifndef _ALL_H__
#define _ALL_H__


//头文件
#include "ti_msp_dl_config.h"
#include "board.h"
#include "stdio.h"
#include "bsp_motor.h"
#include "bsp_track.h"
#include "bsp_pid.h"
#include "bsp_gyro.h"
#include "led.h"
#include "bsp_beep.h"
#include "oled.h"
//#include "bmp.h"
#include "JY61P.h"
#include "PID.h"
#include "key.h"
#include "math.h"
#include "LASER.h"
#include "stdlib.h"	
#include "icm42688.h"
#include "IMU.h"
#include "stdint.h"
#include "TEST.h"



//变量
extern int32_t KEY;//获取按键数值
extern float track_feedback;//循迹pid反馈
extern int32_t time_out;
extern int16_t turn_count;//转弯次数
extern int64_t a,b,c,d;
extern int32_t recongnize_state;
extern int32_t recongnize_time;//识别时间
extern int16_t exit_turn_state;//退出转弯标志位
void all_init(void);
void code_carry(void);
extern int32_t turngogo_state;
extern int32_t time_out ;//记录灰度全亮次数
extern int32_t basic_speed;//基础速度
extern int32_t Left_basic_speed;//左轮速度
extern int32_t Right_basic_speed;//右轮速度
void xunxian(void);
void xunxian_four(void);
void xunxian_five(void);

#endif

