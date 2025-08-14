#include "CSZ_ALL.h"


int16_t exit_turn_state=1;//退出转弯标志位
int16_t turn_count=0;//转弯次数
int16_t turn_state=0;//转弯次数标志位
int32_t KEY=0;//获取按键数值
int32_t basic_speed=2300;//基础速度
int32_t Left_basic_speed=0;//左轮速度
int32_t Right_basic_speed=0;//右轮速度
float track_feedback=0;//循迹pid反馈
int32_t time_out = 0;//记录灰度全亮次数
int32_t recongnize_state=0;//识别时间标志位
int32_t recongnize_time=0;//识别时间
int32_t turngogo_state=0;
int32_t enter_state=1;
//所有pid的初始化
void pid_init()
{
		huidupid.kp=0;
		huidupid.ki=0.6;
		huidupid.kd=0; 

}



//初始化函数
void all_init()
{
//PID初始化
	  pid_init();
//串口接收中断                             
//		NVIC_EnableIRQ(UART_JY61P_INST_INT_IRQN);       //使能中断
//		NVIC_EnableIRQ(UART_0_DEBUG_INST_INT_IRQN);     //使能中断 
//		NVIC_EnableIRQ(UART_3_INST_INT_IRQN);           //使能中断
//		NVIC_EnableIRQ(UART_1_INST_INT_IRQN);           //使能中断

//编码器开启中断计算
//		motor_init(); //开启电机编码器引脚外部中断


//陀螺仪解算
//    bsp_Icm42688Init();
//		Imu_gyro_offset_Init();
//		delay_ms(20);


//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
//若选用此定时器，要把所有的定时器中断放在外设初始化完后再开启
//eg:
//motor_init(); //开启电机编码器引脚外部中断
//NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);      // 配置定时器的NVIC（编码器定时器中断）
//bsp_Icm42688Init();
//Imu_gyro_offset_Init();

//应改成如下：
//motor_init(); //开启电机编码器引脚外部中断
//bsp_Icm42688Init();
//Imu_gyro_offset_Init();
//NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);      // 配置定时器的NVIC（编码器定时器中断）

//防止定时器中断立刻阻断外设的初始化

//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
//------------------------------------------------注意事项------------------------------------------------
}



//解释函数
void recognition_hanshu()
{
//		DL_UART_Main_transmitDataBlocking(UART_JY61P_INST,0x11);//串口发送数据函数
//		DL_UART_Main_transmitDataBlocking(UART_3_INST,0x11);//串口发送数据函数		
//		DL_UART_Main_transmitDataBlocking(UART_1_INST,0x11);//串口发送数据函数	
	
//		DL_GPIO_clearPins(SPI_connect_CE_PORT,SPI_connect_CE_PIN);//gpio清除函数


}

int64_t a,b,c,d;
void code_carry()
{
//		a=L5;
//		b=L4;
//		c=R4;
//		d=R5;
	//按键识别
		KEY=click();
		Data=Inrared_Get();
		recognition_hanshu();
	//	LASER_ON();
		if(KEY==2)
		{
	//TEST_THREE();	
//		xunxian();
//		delay_1ms(10);
	//
//			TEST_TWO();
//			TEST_THREE();
			TEST_FOUR();
		}
		
		if(KEY==3)
		{
		

			 xunxian();
	}
		if(KEY==4)
		{
		
		TEST_TWO();
		
		}
		if(KEY==5)
		{
		TEST_THREE();
		}
		if(KEY==6)
		{
		TEST_FIVE();
		}
	
		 
//显示数据
    KEY_choose_mode();
		OLED_Refresh();
//	  OLED_ShowString(1,15,"nihoashiji",2,16,1);
  	OLED_ShowNum(1,30,KEY,10,16,1);		
		OLED_ShowNum(1,45,recongnize_time,10,16,1);		
  	delay_ms(20);
		
//			menu_show();
}


void xunxian(void)
{

			if(enter_state==1)
			{
			exit_turn_state=0;
			enter_state=0;
			recongnize_state=1;
			}
if (((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0))&&exit_turn_state==1)
			 {
				 turngogo_state=1;
			 }
			 if(turn_count>=question_one_count*4)
			 {
				if(turn_count==question_one_count*4) 
				{
				if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						
						turn_state=0;
							
						}
						Set_PWM(-1000,2300);
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						turn_count++;
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
				
				}
				else
				{
			 Set_PWM(0,0);
				}
			 }
			 else
			 {
			 if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						turn_count++;
						turn_state=0;
							
						}
						Set_PWM(-1000,2300);
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
		}

}
int quanshu_four=1;

void xunxian_four(void)
{

					if(enter_state==1)
			{
			enter_state=0;
			recongnize_state=1;
			}
if (((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0))&&exit_turn_state==1)
			 {
				 turngogo_state=1;
			 }
						 if(turn_count>=quanshu_four*4)
			 {
				if(turn_count==quanshu_four*4) 
				{
				if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						
						turn_state=0;
							
						}
						Set_PWM(-1000,2300);
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						turn_count++;
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
				
				}
				else
				{
			 Set_PWM(0,0);
				}
			 }
			 else
			 {
			 if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						turn_count++;
						turn_state=0;
							//location.xunji_counter++;
							location.xunji_counter=1;
								if(turn_count==1)
								{
									LOCATION_X_FOUR_NEW(500);
								}
								else if(turn_count==2)
								{
									LOCATION_X_FOUR_NEW(600);
								}
									else if(turn_count==3)
								{
									LOCATION_X_FOUR_NEW(1200);
								}
					
						}
						Set_PWM(-1000,2300);//
						
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						location.xunji_counter=0;		
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
		}

}

int quanshu_five=2;

void xunxian_five(void)
{

					if(enter_state==1)
			{
			enter_state=0;
			recongnize_state=1;
			}
if (((L4 == 0)&&(L3 == 0)&& (L2 == 0) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)  && (R3 == 0))&&exit_turn_state==1)
			 {
				 turngogo_state=1;
			 }
						 if(turn_count>=quanshu_five*4)
			 {
				if(turn_count==quanshu_five*4) 
				{
				if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						
						turn_state=0;
							
						}
						Set_PWM(-1000,2300);
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						turn_count++;
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
				
				}
				else
				{
			 Set_PWM(0,0);
				}
			 }
			 else
			 {
			 if(turngogo_state==1)
			 {
						if(turn_state==1&&exit_turn_state==1)
						{
						turn_count++;
						turn_state=0;
							//location.xunji_counter++;
							location.xunji_counter=1;
								if(turn_count==1)
								{
									LOCATION_X_FOUR_NEW(500);
								}
								else if(turn_count==2)
								{
									LOCATION_X_FOUR_NEW(300);
								}
									else if(turn_count==3)
								{
									LOCATION_X_FOUR_NEW(800);
								}
					
						}
						Set_PWM(-1000,2300);//
						
						if (((L4 != 0)||(L3 != 0)|| (L2 != 0) || (L1 != 0) ||(ML != 0)||(MR != 0)||  (R1 != 0)||(R2 != 0)  || (R3 != 0)))
						{
						exit_turn_state=0;
						turngogo_state=0;
						recongnize_state=1;
						location.xunji_counter=0;		
						}

				}
			 else
			 {		 
			      turn_state=1;
			 	    Left_basic_speed=basic_speed+track_feedback*100;
						Right_basic_speed=basic_speed-track_feedback*100;		
						Set_PWM(Left_basic_speed,Right_basic_speed); 
			 }
		}

}
