#ifndef K230_H_
#define K230_H_

#include "stdint.h"

  typedef struct K230//第二题结构体
{
		uint8_t STAUS_STUAS;//状态机的状态
	
      uint8_t REXEIVE[100];
      uint8_t TREFRECE[100];  
	  uint8_t RX_BUFFER[100];//将数据都存在这里，然后进行一起解包
	
	  int POINT;
	
	  int head_location;
	  int STAUS;
	  int STAUS_LENGTH;
	  int length;
	
	  int DATA_HEAD_LOCATION;
	  int DATA_length;
	  char DATA_buffer[100];//用于中转数据
	  char STAUS_buffer[20]; //用于接收并且转化的缓冲区
	 //缓冲区
	   
	   char ONE_BUFFER[20];
	   char TWO_BUFFER[20];
	   char THREE_BUFFER[20];
	   char FOUR_BUFFER[20];
	   char FIVE_BUFFER[20];
	   char SIX_BUFFER[20];
	   char SEVEN_BUFFER[20];
	   char EVERN_BUFFER[20];
	   char NINE_BUFFER[20];
	   char TEN_BUFFER[20];
	   
	   char REDX_BUFFER[20];
	   char REDY_BUFFER[20];
	   char GREENX_BUFFER[20];
	   char GREENY_BUFFER[20];
	   
	   char ZHONGXIN_X_BUFFER[20];
	   char ZHONGXIN_Y_BUFFER[20];
	   char ONE_X_BUFFER[20];
	   char ONE_Y_BUFFER[20];
	   char TWO_X_BUFFER[20];
	   char TWO_Y_BUFFER[20];
	   char THREE_X_BUFFER[20];
	   char THREE_Y_BUFFER[20];
	   char FOUR_X_BUFFER[20];
	   char FOUR_Y_BUFFER[20];
	   char FIVE_X_BUFFER[20];
	   char FIVE_Y_BUFFER[20];
	   
	   int RED_x;
	   int RED_y;
	   int GREEN_x;
	   int GREEN_y;
	   
	   int ZHONGXIN_x;
	   int ZHONGXIN_y;
	   int ONE_x;
	   int ONE_y;
	   int TWO_x;
	   int TWO_y;
	   int THREE_x;
	   int THREE_y;
	   int FOUR_x;
	   int FOUR_y;
	  
	 
	  	
	
}K230;

 void K230_Init_DATA(void);
 void K230_UART_Init(void);
 extern K230 k230;
void K230_DISPOSE(void);
void K230_COUNTER(int num);
void K230_Init_DATA_IT(void);
void uart3_send_char(char ch);

void uart3_send_string(char* str);



#endif
