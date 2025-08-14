#ifndef __YUNTAI_COUNTER_H
#define __YUNTAI_COUNTER_H
#include "stdint.h"
 typedef struct DEBUG_DATA//�ڶ���ṹ��
{
     uint8_t SPRINTF_BUFFER[40];
}DEBUG_DATA;
extern DEBUG_DATA debug_data;
 typedef struct LOCATION//�ڶ���ṹ��
{
       float X_BIA;
       float Y_BIA;
	
	    float X_Error0,X_Error1,X_Error2;
		float Y_Error0,Y_Error1,Y_Error2;
		float XOUT;
		float YOUT;
	
		int buffer_X[20];
		int buffer_Y[20];
	
		float LVBO_X;
		float LVBO_Y;
	
		float X_DOUT;
		float Y_DOUT;
		int data_amount;
	
		float X_ErrorInt;
		float Y_ErrorInt;
	
	 float x_sum;
	 float y_sum;
	
		float location_PID_X_BIA;
		float location_PID_Y_BIA;
		float location_PID_X_Error0,location_PID_X_Error1,location_PID_X_Error2;
		float location_PID_Y_Error0,location_PID_Y_Error1,location_PID_Y_Error2;
		float location_PID_XOUT;
		float location_PID_YOUT;
		float location_PID_X_DOUT;
		float location_PID_Y_DOUT;
		float location_PID_X_ErrorInt;
		float location_PID_Y_ErrorInt;
		
		float location_OLD_D;
		
		int xuanzhuan_angle;
		
		int xunji_counter;
}LOCATION;

typedef struct
{
        float kp,ki,kd;             // ����ϵ��
        float error,lastError;      // ���ϴ����
        int integral,maxIntegral; // ���֡������޷�
        float output,maxOutput;     // ���������޷�
	
		float DISTANCE_KP;
	
		
}smotor_info;



extern  LOCATION location;
void Location_DATA_init(void);
   
   void Location_PID_Y_TWO(void);
   void Location_PID_X_TWO(void);

   void Location_PID_X_NEW(void);

  void Location_PID_Y_NEW(void);
void location_POINT_PID_X(float NOW_X,float TARGET_X);
void location_POINT_PID_Y(float NOW_Y,float TARGET_Y);
void LOCATION_X(int sumber);//xֵ��ʾ������
void LOCATION_Y(int sumber);//yֵ��ʾ������
void YUANDIXUANZHUAN(void);
 void Location_PID_Y_FOUR(void);
 void Location_PID_X_FOUR(void);
void LOCATION_X_FOUR_NEW(int sumber);//xֵ��ʾ������









#endif
