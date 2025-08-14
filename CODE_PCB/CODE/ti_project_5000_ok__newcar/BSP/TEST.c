#include "CSZ_ALL.h"

int16_t question_KEY=0;//选择圈数按键
int16_t question_one_count=0;//gai'l
//题目一：按键选择圈数模式
void KEY_choose_mode(void)
{
		if(KEY==1)
		{
				while(question_KEY!=3)
				{
						question_KEY=question_click();
						if(question_KEY==1)
						{
						
						
						}
						if(question_KEY==2)
						{
						question_one_count++;
						
						}
						OLED_Refresh();		
						OLED_ShowNum(1,45,question_one_count,10,16,1);	
						delay_ms(20);
			  }
			
		}

}



void TEST_TWO(void)
{

			//K230_COUNTER(2);
			
		//	LASER_ON();
	while(1)
	{

					if(k230.RED_x!=0)
				{
						Location_PID_Y_NEW();
				    Location_PID_X_NEW();
			//		Location_PID_X_TWO(); 
	UART_printf("%d,%d,%d\r\n",k230.RED_x,(int)k230.RED_y,(int)415);
		
				
				}
			if(k230.RED_x>=410&&k230.RED_x<=430&&k230.RED_y>=207&&k230.RED_y<=227)
			{
			LASER_ON();
			
			
			}
			
			
			delay_1ms(10);
	}
	
	




}

void TEST_THREE(void)
{
		BUJIN_INIT(X);
	while(1)
	{
		

					if(k230.RED_x!=0&&k230.RED_y!=0)
				{
						Location_PID_Y_NEW();
				    Location_PID_X_NEW();
			//		Location_PID_X_TWO(); 
	UART_printf("%d,%d,%d\r\n",k230.RED_x,(int)k230.RED_y,(int)415);
		
					if(k230.RED_x>=410&&k230.RED_x<=420&&k230.RED_y>=207&&k230.RED_y<=227)
			{
			LASER_ON();
			
			
			}
				}
				
		
			
			
			
	}


}
void TEST_FOUR(void)
{		LASER_ON();
		while(1)
		{
			if(k230.RED_x!=0&&k230.RED_y!=0&&location.xunji_counter==0)
				{
						Location_PID_Y_FOUR();
				    Location_PID_X_NEW();
			//		Location_PID_X_TWO(); 
	UART_printf("%d,%d,%d\r\n",k230.RED_x,(int)k230.RED_y,(int)415);
		
			
				}
		Data=Inrared_Get();
		xunxian_four();
	
	
  	delay_ms(20);
		
		
}


}


void TEST_FIVE(void)
{
	LASER_ON();
		while(1)
		{
			if(k230.RED_x!=0&&k230.RED_y!=0&&location.xunji_counter==0)
				{
						Location_PID_Y_FOUR();
				    Location_PID_X_NEW();
			//		Location_PID_X_TWO(); 
	UART_printf("%d,%d,%d\r\n",k230.RED_x,(int)k230.RED_y,(int)415);
		
			
				}
		Data=Inrared_Get();
		xunxian_five();
	
	
  	delay_ms(20);
		
		
}


}





//int16_t count=0;
//main_screen all_screen;


//int16_t screen1_state=1;
//int16_t screen2_state=1;
//int16_t screen3_state=1;
//int16_t count_state=1;
////屏幕按键控制
//void screen_choose()
//{
//		if(all_screen.NEW_STAUS==0.0f&&KEY==1)
//		{
//				KEY=0;
//				all_screen.NEW_STAUS=0.1f;
//				count_state  =1;
//				return;
//				
//		
//		}
//		
//				
//				else if(all_screen.NEW_STAUS==0.1f&&KEY==1)
//				{

//						KEY=0;
//						
//						count_state  =1;
//						return;				
//				}
//				else if(all_screen.NEW_STAUS==0.1f&&KEY==2)
//				{
//						if(count_state==1)
//						{
//						count++;
//						count_state=0;
//						}
//						KEY=0;
//						
//				
//						return;				
//				}
//				else if(all_screen.NEW_STAUS==0.1f&&KEY==3)
//				{
//						 xunxian();
//						KEY=0;
//						OLED_ShowString(100,30,"OK",16,1);
//						return;		
//							
//			
//				}
//		else if(all_screen.NEW_STAUS==0.0f&&KEY==2)
//		{
//				
//				KEY=0;
//				all_screen.NEW_STAUS=0.2f;
//				return;		
//		
//		}
//				else if(all_screen.NEW_STAUS==0.2f&&KEY==1)
//				{
//						
//						KEY=0;
//			    OLED_Refresh();
//				OLED_ShowString(100,1,"OK",16,1);
//						return;
//				}
//				else if(all_screen.NEW_STAUS==0.2f&&KEY==3)
//				{
//						
//						KEY=0;
//					    OLED_ShowString(100,30,"OK",16,1);
//						return;				
//			
//				}				
//		else if(all_screen.NEW_STAUS==0.0f&&KEY==3)
//		{
//			
//				KEY=0;
//				all_screen.NEW_STAUS=0.3f;
//				return;		
//		
//		}			
//				else if(all_screen.NEW_STAUS==0.3f&&KEY==1)
//				{
//					
//						KEY=0;
//						OLED_ShowString(100,1,"OK",16,1);
//						return;
//				}
//				else if(all_screen.NEW_STAUS==0.3f&&KEY==2)
//				{
//					
//						KEY=0;
//						OLED_ShowString(100,15,"OK",16,1);
//						return;				
//				}
//				else if(all_screen.NEW_STAUS==0.3f&&KEY==3)
//				{
//					
//						KEY=0;
//						
//					
//						return;				
//			
//				}

//}


////菜单显示
//void menu_show()
//{
//	
//	
//	
//	
//		screen_choose();
//		if(all_screen.NEW_STAUS==0.0f)
//		{
//				OLED_Refresh();
//				OLED_ShowString(1,0,"quanshu",16,1);
//				OLED_ShowString(1,15,"start1",16,1);
//			    OLED_ShowString(1,30,"start2",16,1);

//		}
//		else if(all_screen.NEW_STAUS==0.1f)
//		{		
//				if(screen1_state==1)
//				{
//					OLED_Clear();
//					screen1_state=0;
//				}
//				
//				OLED_Refresh();   
//				OLED_ShowString(1,0,"count",16,1);
//				OLED_ShowNum(50,1,count,4,16,1);
//				OLED_ShowString(1,30,"1",16,1);
//		}
//		else if(all_screen.NEW_STAUS==0.2f)
//		{
//				if(screen2_state==1)
//				{
//					OLED_Clear();
//					screen2_state=0;
//				}			
//				OLED_Refresh();
//				OLED_ShowString(1,0,"2",16,1);
//			
//				OLED_ShowString(1,30,"3",16,1);
//						
//		
//		}
//		else if(all_screen.NEW_STAUS==0.3f)
//		{
//				if(screen3_state==1)
//				{
//					OLED_Clear();
//					screen3_state=0;
//				}			
//				OLED_Refresh();
//				OLED_ShowString(1,0,"4",16,1);
//			
//				OLED_ShowString(1,15,"5",16,1);
//				
//		
//		}












//  
//}







