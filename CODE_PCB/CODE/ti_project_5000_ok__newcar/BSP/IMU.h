#ifndef __IMU_H
#define __IMU_H

#include "board.h"
#include <math.h>
#define M_PI  3.1415926535




typedef struct
{
    float x;
    float y;
    float z;
} xyz_f_t;
extern xyz_f_t north,west;
extern volatile float yaw[5];   //处理航向的增值
extern float motion6[7];
//Mini IMU AHRS 解算的API
void IMU_init(void); //初始化
void IMU_getYawPitchRoll(float * ypr); //更新姿态
void IMU_TT_getgyro(float * zsjganda);
//uint32_t micros(void);	//读取系统上电后的时间  单位 us 
void MPU6050_InitAng_Offset(void);

void IMU_Data_GetValues(void);

void Imu_gyro_offset_Init(void);//零飘

//结构体声明
typedef struct{  
	float Xdata;
	float Ydata;
	float Zdata;
}gyro_param_t;



typedef struct{
	float gyro_x;
	float gyro_y;
	float gyro_z; 
}IMU_param_t;
extern IMU_param_t IMU_Data;
extern gyro_param_t Gyro_offset;
extern float Yaw_1;
#endif

//------------------End of File----------------------------
