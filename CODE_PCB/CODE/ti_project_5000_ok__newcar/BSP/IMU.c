#include "IMU.h"
#include "icm42688.h"
#include <stdio.h>
//#include "eeprom.h"
/* XYZ结构体 */

/* 加速度：由南向北方向的加速度在加速度计的分量 *//* 加速度：由东向西方向的加速度在加速度计的分量 */
xyz_f_t north,west;
volatile float exInt, eyInt, ezInt;  // 误差积分
volatile float q0, q1, q2, q3; // 全局四元数
volatile float integralFBhand,handdiff;
volatile uint32_t lastUpdate, now; // 采样周期计数 单位 us
volatile float yaw[5]= {0,0,0,0,0};  //处理航向的增值
int16_t Ax_offset=0,Ay_offset=0;
float TTangles_gyro[7]; //彤彤滤波角度
	
float Angle_Final[3];	//X最终倾斜角度
float Kp = 10.0f;

uint32_t nowtime = 0;





gyro_param_t Gyro_offset;
int32_t o;
float Yaw_1 = 0; 
int IMU_1_Open_flag=0;
	icm42688RealData_t accval;
	icm42688RealData_t gyroval;

float Angular_Speed=0;     //?????
float yaw1=0;

void Imu_gyro_offset_Init(void)//零飘
{
	// 将陀螺仪零漂的 X、Y、Z 分量初始化为 0
	Gyro_offset.Xdata = 0;
	Gyro_offset.Ydata = 0;
	Gyro_offset.Zdata = 0;
	for ( o=0;o < 1000;o++)//叠加一千次，算出均值（此方法过于死板，有局限）
	{
		bsp_IcmGetRawData(&accval, &gyroval);
	  IMU_Data.gyro_x=gyroval.x;
	  IMU_Data.gyro_y=gyroval.y;
	  IMU_Data.gyro_z=gyroval.z;
		Gyro_offset.Xdata+= IMU_Data.gyro_x;
	  Gyro_offset.Ydata+= IMU_Data.gyro_y;
   	Gyro_offset.Zdata+= IMU_Data.gyro_z;
		delay_ms(10);// 延迟 5 毫秒，等待传感器数据稳定
	}
	// 计算陀螺仪零漂的平均值
	Gyro_offset.Xdata /= 1000;
	Gyro_offset.Ydata /= 1000;
	Gyro_offset.Zdata /= 1000;
	
}



float Q_rsqrt( float number )
{long i;
	float x2, y;
	const float threehalfs = 1.5F;
	

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       
	i  = 0x5f3759df - ( i >> 1 );             
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   

	return y;
}	


//?????



IMU_param_t IMU_Data;
//#define M_PI 3.1415926535
float vx,vy,vz;
float ax,ay,az,gx,gy,gz;
float norm;
float dq0,dq1,dq2,dq3;
float ex,ey,ez;
float q[4]={1.0,0,0,0};
float q0_old, q1_old, q2_old, q3_old;

// ??????(??????????)
float dt = 0.01f; // ??:100Hz?????0.01?
//???????
void IMU_UpdateQuaternion(IMU_param_t* imu_data) {
    // ???????(??????/?)
     gx = imu_data->gyro_x * M_PI / 180.0f; // ????????/?
     gy = imu_data->gyro_y * M_PI / 180.0f;
     gz = imu_data->gyro_z * M_PI / 180.0f;

    // ?????
     q0 = q[0], q1 = q[1], q2 = q[2], q3 = q[3];

    // ??????? ??????????? ???????
    // ???????(???????)
     dq0 = 0.5f * (-q1*gx - q2*gy - q3*gz);
     dq1 = 0.5f * ( q0*gx + q2*gz - q3*gy);
     dq2 = 0.5f * ( q0*gy - q1*gz + q3*gx);
     dq3 = 0.5f * ( q0*gz + q1*gy - q2*gx);

    // ????????
    q0 += dq0 * dt;
    q1 += dq1 * dt;
    q2 += dq2 * dt;
    q3 += dq3 * dt;

    // ??????
     norm = Q_rsqrt(q0*q0 + q1*q1 + q2*q2 + q3*q3);
    q[0] = q0 * norm;
    q[1] = q1 * norm;
    q[2] = q2 * norm;
    q[3] = q3 * norm;
}
double my_atan2(double y, double x) {
	// ??x = 0???
	if (x == 0) {
			if (y > 0) {
					return M_PI / 2; // y????
			} else if (y < 0) {
					return -M_PI / 2; // y????
			} else {
					return 0; // ??
			}
	}
else{
	// ??????
	double theta = atan(y / x);

	// ??x ? 0???
	if (x > 0) {
			return theta; // ?????????
 // ??x < 0???
	} else {
			if (y >= 0) {
					return theta + M_PI; // ?????x????
			} else {
					return theta - M_PI; // ????
			}
	 }
}
}










/**************************实现函数********************************************
*函数原型:	   void IMU_getValues(float * values)
*功　　能:	 读取加速度 陀螺仪 磁力计 的当前值  
输入参数： 将结果存放的数组首地址
输出参数：没有
*******************************************************************************/
//void IMU_getValues(float * values) {  
//	//int16_t accgyroval[7];

//	
//	float sqrResult_gyro[3];
//	float avgResult_gyro[3];
//	//读取加速度和陀螺仪的当前ADC
//	bsp_IcmGetRawData(&accval, &gyroval);
//    TTangles_gyro[0] =  accval.x;
//    TTangles_gyro[1] =  accval.y;
//    TTangles_gyro[2] =  accval.z;
//	TTangles_gyro[3] =  gyroval.x;
//	TTangles_gyro[4] =  gyroval.y;
//	TTangles_gyro[5] =  gyroval.z;
//	TTangles_gyro[6] =  0;
//	IMU_Data.gyro_x=gyroval.x;
//	IMU_Data.gyro_y=gyroval.y;
//	IMU_Data.gyro_z=gyroval.z;


//		//这里已经将量程改成了 1000度每秒  32.8 对应 1度每秒
//}


void IMU_Data_GetValues(void)//??????????????, ?????
{
		
	  bsp_IcmGetRawData(&accval, &gyroval);
	  IMU_Data.gyro_x=gyroval.x;
	  IMU_Data.gyro_y=gyroval.y;
	  IMU_Data.gyro_z=gyroval.z;
	
    IMU_Data.gyro_x = (float)((IMU_Data.gyro_x-Gyro_offset.Xdata)/10*10);//????=??-?????
    IMU_Data.gyro_y = (float)((IMU_Data.gyro_y-Gyro_offset.Ydata)/10*10);// ?/16.384f??????
    IMU_Data.gyro_z = (float)((IMU_Data.gyro_z-Gyro_offset.Zdata)/10*10);//16.384??????,? ??? IMU660RA ?321????
	//?????????????  ??????????
	
	  
	   IMU_UpdateQuaternion(&IMU_Data);
	    yaw1= my_atan2(
        2.0f * (q[1] * q[2] + q[0] * q[3]),
        q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3]
    );
	   Yaw_1=yaw1 * 57.295779513f;
		
if(Yaw_1>180)
		{
		Yaw_1-=360;
		}
		else if(Yaw_1<-180)
		{
		Yaw_1+=360;
		}
		Yaw_1=-Yaw_1;
		
		
}



