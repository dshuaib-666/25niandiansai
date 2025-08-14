#include "CSZ_ALL.h"
 //������� ���� 01 F3 AB 01 00 6B
//01�ǵ���ķ��ţ�Ҫ�����ֻ��߿�����������Ͱѿ�ͷ��01�ĵ�


 BUJIN bujin;

 #define HAL_Delay delay_1ms
 void BUJIN_communication_init(void)
 {     
//	 __HAL_UART_ENABLE_IT(&huart3, UART_IT_IDLE);
// 	HAL_UART_Receive_DMA(&huart3,BUJIN.REXEVICE,100);
	 
	 
 
 }
  uint8_t BUJIN_start_down[]={0x02,0xf3,0xab,0x01,0x00,0x6b};
   uint8_t BUJIN_start_up[]={0x01,0xf3,0xab,0x01,0x00,0x6b};
 void BUJIN_START(int add)
 {
	 if(add==1)
	 {  UART1_Console_write(BUJIN_start_up,5);
//		 for(int i=0;i<5;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_start_up[i]);
//	}
	 }
	else  if(add==2)
	 {  
		 UART1_Console_write(BUJIN_start_down,5);
//		 for(int i=0;i<5;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_start_down[i]);
//	}
	

 } 
		HAL_Delay(5);


 }
 //���ֹͣ ����01 FE 98 00 6B
 uint8_t BUJIN_stop_down[]={0x02,0xfe,0x98,0x00,0x6b};
  uint8_t BUJIN_stop_up[]={0x01,0xfe,0x98,0x00,0x6b};
 void BUJIN_STOP(int add)
 {
	 if(add==1)
	 {  
		  UART1_Console_write(BUJIN_stop_up,5);
//		 for(int i=0;i<5;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_stop_up[i]);
//	}
	 }
	else  if(add==2)
	 {  
		   UART1_Console_write(BUJIN_stop_down,5);
//		 for(int i=0;i<5;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_stop_down[i]);
//	}
	 }

	  HAL_Delay(5); 
 
 
 }
 //�����ת����
 uint8_t BUJIN_locked_rotor_stop_down[]={0x02,0x0e,0x52,0x6B};
  uint8_t BUJIN_locked_rotor_stop_up[]={0x01,0x0e,0x52,0x6B};
 void BUJIN_locked_rotor(int add)
 {
	 if(add==1)
	 {
		    UART1_Console_write(BUJIN_locked_rotor_stop_up,4);
//	    for(int i=0;i<4;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_locked_rotor_stop_up[i]);
//	}
	 }
	 
	 else if(add==2)
	 {
		   UART1_Console_write(BUJIN_locked_rotor_stop_down,4);
//		  for(int i=0;i<4;i++)
//	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_locked_rotor_stop_down[i]);
//	}
	 }
	 
 
	 HAL_Delay(5);  
 }
 //�ع����ģʽ���п���
  uint8_t BUJIN_location_parameter_Counter_down[]={0x02,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0B,0x6E,0x01,0x01,0x6B};
   uint8_t BUJIN_location_parameter_Counter_up[]={0x01,0xFD,0x01,0x00,0x32,0x00,0x00,0x00,0x0B,0x6E,0x01,0x01,0x6B};
 void BUJIN_LOCATION_parameter_Counter(int add)                           
 {
	HAL_Delay(100);
	 if(add==1)
	 {
		 		//   UART1_Console_write(BUJIN_location_parameter_Counter_up,20);
		 for(int i=0;i<20;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_location_parameter_Counter_up[i]);
	}
	 }
	 else if(add==2)
	 {
		//   UART1_Console_write(BUJIN_location_parameter_Counter_down,20);
		 for(int i=0;i<20;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_location_parameter_Counter_down[i]);
	}
	 
	 }
	 

	HAL_Delay(5);  
 
 }
 //���ȷ��������01 93 88 01 6B
 uint8_t BUJIN_location_init_up[]={0x01,0x93,0x88,0x01,0x6b};
  uint8_t BUJIN_location_init_down[]={0x02,0x93,0x88,0x01,0x6b};
 void BUJIN_LOCATION_Init(int add)
 {
	 BUJIN_communication_init();
	 BUJIN_START(add);
	 if(add==1)
	 {
		   //UART1_Console_write(BUJIN_location_init_up,5);
		 for(int i=0;i<5;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_location_init_up[i]);
	}
	 
	 }
	 else if(add==2)
	 {
		//   UART1_Console_write(BUJIN_location_init_down,5);
		 for(int i=0;i<5;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_location_init_down[i]);
	}
	 
	 
	 
	 }
	HAL_Delay(5);	 
	 
	//  HAL_UART_Transmit_DMA(&huart3,BUJIN_location_init,5);
	   HAL_Delay(100); 
 }
//�ع���� ����01 9A 00 00 6B
 uint8_t BUJIN_init_down[]={0x02,0x9a,0x00,0x00,0x6b}; 
  uint8_t BUJIN_init_up[]={0x01,0x9a,0x00,0x00,0x6b}; 
void BUJIN_INIT(int add)
{     
	   
	 
	  //BUJIN_LOCATION_parameter_Counter(add);
	  BUJIN_START(add);
	  if(add==1)
	  {
		  // UART1_Console_write(BUJIN_init_up,5);
		 for(int i=0;i<5;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_init_up[i]);
	}
	  }
	  else if(add==2)
	  {
		  //    UART1_Console_write(BUJIN_init_down,5);
		  for(int i=0;i<5;i++)
	{   DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_init_down[i]);
	}
	  }
	 HAL_Delay(1000); 
}

 uint8_t BUJIN_TREFER[13]={0x00,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00}; 
//���� ��ַΪ1/2������1/0���ٶ� ת��  distanceΪ���룬modeΪ0/1��Ի��߾���
 //ת����100
void BUJIN_COUNTER(uint8_t add,int dir,int speed,int distance)
{
  if(add==1)
  {
	 BUJIN_TREFER[0]=0x01;
  }
  else if(add==2)
  {	
	 BUJIN_TREFER[0]=0x02;
  }
  
	   if(dir==0)
	   {
		     BUJIN_TREFER[2]=0x01; //��˳ʱ��Ϊ׼
	   }
	   else if(dir==1)
	   {
		    BUJIN_TREFER[2]=0x00; //����ʱ��Ϊ׼
	   }
	 
	
  
  	  BUJIN_TREFER[4] = (char)(speed & 0xFF);      // ��8λ
	  BUJIN_TREFER[3]= (char)((speed >> 8) & 0xFF); // ��8λ
  
	 // BUJIN_TREFER[5]=0x14;//���ٶȵ�λ 20
		   BUJIN_TREFER[5]=0x40;//���ٶȵ�λ 20
  // BUJIN_TREFER[5]=0x00;
	  BUJIN_TREFER[9] = (distance) & 0xFF;          // ���8λ
      BUJIN_TREFER[8] = (distance >> 8) & 0xFF;
      BUJIN_TREFER[7] = (distance >> 16) & 0xFF;
      BUJIN_TREFER[6] = (distance >> 24) & 0xFF;   // ���8λ
  
	   if(add==X) //�������i���
	   {
		   	 BUJIN_TREFER[10]=0x00;//���
	   }
	   else if(add==Y)
	   {                          
		  //BUJIN_TREFER[10]=0x01;//����
	   BUJIN_TREFER[10]=0x00;//����
	   
	   }
  
	 //BUJIN_TREFER[10]=0x01;//����   //����
	 
    BUJIN_TREFER[11]=0x00;//���������
	BUJIN_TREFER[12]=0x6B;
     //  UART1_Console_write(BUJIN_TREFER,13);
	  for(int i=0;i<13;i++)
	{   
		DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_TREFER[i]);
	}
	 HAL_Delay(5); 
}
uint8_t BUJIN_TREFER_FOUR[13]={0x00,0xFD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00};
void BUJIN_COUNTER_FOUR(uint8_t add,int dir,int speed,int distance)
{
  if(add==1)
  {
	 BUJIN_TREFER[0]=0x01;
  }
  else if(add==2)
  {	
	 BUJIN_TREFER[0]=0x02;
  }
  
	   if(dir==0)
	   {
		     BUJIN_TREFER[2]=0x01; //��˳ʱ��Ϊ׼
	   }
	   else if(dir==1)
	   {
		    BUJIN_TREFER[2]=0x00; //����ʱ��Ϊ׼
	   }
	 
	
  
  	  BUJIN_TREFER[4] = (char)(speed & 0xFF);      // ��8λ
	  BUJIN_TREFER[3]= (char)((speed >> 8) & 0xFF); // ��8λ
  
	 // BUJIN_TREFER[5]=0x14;//���ٶȵ�λ 20
		   BUJIN_TREFER[5]=0x40;//���ٶȵ�λ 20
  // BUJIN_TREFER[5]=0x00;
	  BUJIN_TREFER[9] = (distance) & 0xFF;          // ���8λ
      BUJIN_TREFER[8] = (distance >> 8) & 0xFF;
      BUJIN_TREFER[7] = (distance >> 16) & 0xFF;
      BUJIN_TREFER[6] = (distance >> 24) & 0xFF;   // ���8λ
  
	   if(add==X) //�������i���
	   {
		   	 BUJIN_TREFER[10]=0x00;//���
	   }
	   else if(add==Y)
	   {                          
		  //BUJIN_TREFER[10]=0x01;//����
	   BUJIN_TREFER[10]=0x00;//����
	   
	   }
  
	 //BUJIN_TREFER[10]=0x01;//����   //����
	 
    BUJIN_TREFER[11]=0x00;//���������
	BUJIN_TREFER[12]=0x6B;
     //  UART1_Console_write(BUJIN_TREFER,13);
	  for(int i=0;i<13;i++)
	{   
		DL_UART_Main_transmitDataBlocking(UART_1_INST,BUJIN_TREFER[i]);
	}
	 HAL_Delay(5); 
}

void TWO_BUJIN_START_Init(void)
{
			//BUJIN_INIT(Y);
		//BUJIN_COUNTER(Y,YZHENG,100,50);
	//	 LOCATION_Y(400);

		HAL_Delay(10); 
	  	BUJIN_START(X);
  	HAL_Delay(10); 
	  	BUJIN_START(Y);

}


