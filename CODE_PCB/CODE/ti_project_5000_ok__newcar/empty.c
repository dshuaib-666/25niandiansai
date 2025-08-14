
#include "CSZ_ALL.h"

int main(void)
{
	  SYSCFG_DL_init();                           // 应用sysconfig的初始化
//sysconfig初始化
		board_init();
		NVIC_ClearPendingIRQ(UART_3_INST_INT_IRQN);
	//DL_UART_enableInterrupt(UART_3_INST, DL_UART_IIDX_RX);
	NVIC_EnableIRQ(UART_3_INST_INT_IRQN);
//定时器初始化
		DL_TimerG_startCounter(TIMER_0_INST);       // 初始化定时器
		DL_TimerG_startCounter(TIMER_1_INST);       // 初始化定时器	
	//10ms中断，常规任务
		NVIC_ClearPendingIRQ(TIMER_1_INST_INT_IRQN);
		NVIC_EnableIRQ(TIMER_1_INST_INT_IRQN);
//20ms中断
		NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
		NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);      // 配置定时器的NVIC（编码器定时器中断）++++++
//OLED初始化
		OLED_Init();//初始化OLED
		OLED_ColorTurn(0);//0正常显示，1 反色显示
		OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示		
//////			K230_Init_DATA();

//////			my_usart_tf_dma_init();
//////	//BUJIN_INIT(X);
	  TWO_BUJIN_START_Init();
//总任务初始化
		all_init();
			
			

	//	BUJIN_COUNTER(Y,YZHENG,100,50);

	//	LOCATION_X(50);
//				delay_1ms(2000);
//					LOCATION_Y(10);
//				delay_1ms(2000);
						//LOCATION_Y(0);
					//	LOCATION_Y(50);
							//delay_1ms(2000);
							//BUJIN_COUNTER(Y,YZHENG,100,0);
						//	BUJIN_COUNTER(Y,YZHENG,100,0);
					//	dma_tset();
						//K230_COUNTER(1);
						
//							K230_COUNTER(2);
////							delay_1ms(1000);
//LOCATION_X(-800);
//				LOCATION_Y(300);	
//				delay_1ms(2000);
//				LOCATION_Y(500);
//					delay_1ms(2000);
//				LOCATION_Y(600);
//					delay_1ms(2000);
//				LOCATION_Y(300);
//		delay_1ms(2000);
		//BUJIN_LOCATION_Init(X);
	//	delay_1ms(2000);
	//UART1_Console_write("122222222222222",strlen("122222222222222"));
	//BUJIN_COUNTER(Y,YFU,100,50);
  // BUJIN_COUNTER(X,XNI,100,100);
//	UART1_Console_write(BUJIN_TREFER1,13);
//	delay_1ms(2000);
//		UART1_Console_write("qqq",strlen("qqq"));
		//
//		UART1_Console_write(BUJIN_TREFER1,13);
//			delay_1ms(2000);                                                                                                                                                      
//			BUJIN_COUNTER(X,XSHUN,100,200);
//BUJIN_COUNTER(Y,YZHENG,100,50);
//		delay_1ms(2000);
//		BUJIN_COUNTER(X,XNI,100,200);
//			delay_1ms(2000);
// 	BUJIN_COUNTER(X,XSHUN,100,420);
//	LOCATION_X(200);
//			delay_1ms(2000);
//	LOCATION_X(-300);
//			delay_1ms(2000);
//	LOCATION_X(200);
//////// LOCATION_X(200);
//////// 
////////	delay_1ms(1000);
////////	//LOCATION_X(200);
////////	delay_1ms(1000);
////////	//	LOCATION_X(400);
//////////	BUJIN_LOCATION_Init(X);
//////////	BUJIN_COUNTER(1,1,100,3000,0);+
//////////	BUJIN_STOP();
////////		// dma_tset();
//////////		 
//////////		 sprintf((char *)debug_data.SPRINTF_BUFFER,"qwewe");
//////////		 uart0_send_string((char *)debug_data.SPRINTF_BUFFER);
////////			UART_printf("%d,%d,%d\r\n",500,100,300);
Location_DATA_init();
K230_COUNTER(2);
delay_1ms(1000);

//LASER_ON();

	while (1) 
	{  
		
//				if(k230.RED_x!=0)
//				{
//					Location_PID_X_NEW();
//		//Location_PID_X_FOUR();
//						Location_PID_Y_NEW();
//				Location_PID_X_NEW();
//			//		Location_PID_X_TWO(); 
//	UART_printf("%d,%d,%d\r\n",k230.RED_x,(int)location.XOUT,(int)415);
//		
//				
//				}
	//			delay_1ms(10);
			//	UART_printf("%d,%d,%d\r\n",k230.RED_y,(int)location.YOUT,(int)220);
//			if(k230.RED_y!=0)
//			{
////			Location_PID_X_TWO(); 
////			Location_PID_Y_TWO(); 
//				Location_PID_Y_NEW();
//			UART_printf("%d,%d,%d\r\n",k230.RED_y,(int)location.YOUT,(int)220);
//	
//			
//			}
	
		//delay_1ms(10);
	//TEST_THREE();	
		code_carry();
	}
}

//--------------------------------------中断程序--------------------------------------------

//电机编码器脉冲计数      20ms中断
void TIMER_0_INST_IRQHandler(void)
{

	if( DL_TimerA_getPendingInterrupt(TIMER_0_INST) == DL_TIMER_IIDX_ZERO )
	{
//编码器速度计算
//		Encoder.Encoder_Left = -Get_Encoder_countA;//两个电机安装相反，所以编码器值也要相反
//		Encoder.Encoder_Right = Get_Encoder_countB;
//		Get_Encoder_countA=0;
//		Get_Encoder_countB=0;
//timeout增加
//		if (((L4 == 1) &&(L3 == 1) &&(L2 == 1) && (L1 == 1) &&(ML == 1)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)&&(R3 == 0)&&(R4 == 0)&&(KEY!=0))
//			||((L4 == 1) &&(L3 == 1) &&(L2 == 1) && (L1 == 1) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)&&(R3 == 0)&&(R4 == 0)&&(KEY!=0))
//		  ||((L4 == 1) &&(L3 == 1) &&(L2 == 1) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)&&(R3 == 0)&&(R4 == 0)&&(KEY!=0))
//		  ||((L4 == 1) &&(L3 == 1) &&(L2 == 1) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)&&(R3 == 0)&&(R4 == 0)&&(KEY!=0))
//			||((L4 == 1) &&(L3 == 1) &&(L2 == 1) && (L1 == 0) &&(ML == 0)&&(MR == 0)&&  (R1 == 0)&&(R2 == 0)&&(R3 == 0)&&(R4 == 0)&&(KEY!=0))
//		) 
//    { 
//				time_out=1;	
//    }
//		else
//		{
//				time_out=0;
//		}  
		
		 
	}
}

//10ms中断
void TIMER_1_INST_IRQHandler(void)//10ms
{
	switch(DL_TimerA_getPendingInterrupt(TIMER_1_INST))
	{
		case DL_TIMER_IIDX_ZERO:

//定时清除
		if(recongnize_state==1)
		{
		recongnize_time++;
		if(recongnize_time>330)//350
		{
		recongnize_time=0;
		exit_turn_state=1;
		recongnize_state=0;		}
		
		}
//循迹pid反馈
		track_feedback=HUIDU_SHIBIE(&huidupid);
	

			DL_TimerG_clearInterruptStatus(TIMER_1_INST, DL_TIMER_IIDX_ZERO);
		break;
		default:
		break;
	}
}

//void UART_0_DEBUG_INST_IRQHandler(void) {
//    uint8_t uartdata = DL_UART_Main_receiveData(UART_0_DEBUG_INST); // 接收一个uint8_t数据

//   

//		DL_UART_Main_transmitDataBlocking(UART_0_DEBUG_INST, uartdata); // 可选：回传接收到的数据
//}
//void UART_1_INST_IRQHandler(void) {
//    uint8_t uartdata = DL_UART_Main_receiveData(UART_1_INST); // 接收一个uint8_t数据

//   

//		DL_UART_Main_transmitDataBlocking(UART_1_INST, uartdata); // 可选：回传接收到的数据
//}

//void UART_3_INST_IRQHandler(void) {
//    uint8_t uartdata = DL_UART_Main_receiveData(UART_3_INST); // 接收一个uint8_t数据

//   

//		DL_UART_Main_transmitDataBlocking(UART_3_INST, uartdata); // 可选：回传接收到的数据
//}














//--------------------------------------中断程序--------------------------------------------