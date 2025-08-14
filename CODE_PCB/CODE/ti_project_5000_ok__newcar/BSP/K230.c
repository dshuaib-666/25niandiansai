#include "CSZ_ALL.h"
//   #include "stdarg.h"
//#include <string.h>
#include <stdlib.h> 
//#include <stdio.h>
K230 k230;


void K230_Init_DATA(void)
{
	k230.STAUS_STUAS=0;
	k230.POINT=0;
	k230.RED_x=0;
	k230.RED_y=0;
	k230.ZHONGXIN_x=0;
	k230.ZHONGXIN_y=0;
	k230.ONE_x=0;
	k230.ONE_y=0;
	k230.TWO_x=0;
	k230.TWO_y=0;
	k230.THREE_x=0;
	k230.THREE_y=0;
	k230.FOUR_x=0;
	k230.FOUR_y=0;

	
	for(int i=0;i<99;i++)
	{
		k230.REXEIVE[i]=0;
		k230.RX_BUFFER[i]=0;
		k230.TREFRECE[i]=0;
		
	}
	K230_Init_DATA_IT();
//	K230_COUNTER(0);
//	HAL_Delay(1000);
}
//����״̬λ
void k230_DATA_GET(int stuasnum)
{
   if(stuasnum==2)
   {
	for(int i=0;i<=2;i++)
	{
		 k230.REDX_BUFFER[i]=k230.ONE_BUFFER[i];
		 k230.REDY_BUFFER[i]=k230.TWO_BUFFER[i];
//		 k230.GREENX_BUFFER[i]=k230.THREE_BUFFER[i];
//		 k230.GREENY_BUFFER[i]=k230.FOUR_BUFFER[i];
	}
		 k230.RED_x=atoi( k230.REDX_BUFFER);
		k230.RED_y=atoi( k230.REDY_BUFFER);
//		k230.GREEN_x=atoi( k230.GREENX_BUFFER);
//		k230.GREEN_y=atoi( k230.GREENY_BUFFER);
	   
   }
   else if(stuasnum==1)
   {
	   for(int i=0;i<=2;i++)
	{
		 k230.ZHONGXIN_X_BUFFER[i]=k230.ONE_BUFFER[i];
		 k230.ZHONGXIN_Y_BUFFER[i]=k230.TWO_BUFFER[i];
		 k230.ONE_X_BUFFER[i]=k230.THREE_BUFFER[i];
		 k230.ONE_Y_BUFFER[i]=k230.FOUR_BUFFER[i];
		 k230.TWO_X_BUFFER[i]=k230.FIVE_BUFFER[i];
		 k230.TWO_Y_BUFFER[i]=k230.SIX_BUFFER[i];
		 k230.THREE_X_BUFFER[i]=k230.SEVEN_BUFFER[i];
		 k230.THREE_Y_BUFFER[i]=k230.EVERN_BUFFER[i];
		 k230.FOUR_X_BUFFER[i]=k230.NINE_BUFFER[i];
		 k230.FOUR_Y_BUFFER[i]=k230.TEN_BUFFER[i];
		
	}
		k230.ZHONGXIN_x=atoi( k230.ZHONGXIN_X_BUFFER);
		k230.ZHONGXIN_y=atoi( k230.ZHONGXIN_Y_BUFFER);
		k230.ONE_x=atoi( k230.ONE_X_BUFFER);
		k230.ONE_y=atoi( k230.ONE_Y_BUFFER);
		k230.TWO_x=atoi( k230.TWO_X_BUFFER);
		k230.TWO_y=atoi( k230.TWO_Y_BUFFER);
		k230.THREE_x=atoi( k230.THREE_X_BUFFER);
		k230.THREE_y=atoi( k230.THREE_Y_BUFFER);
		k230.FOUR_x=atoi( k230.FOUR_X_BUFFER);
		k230.FOUR_y=atoi( k230.FOUR_Y_BUFFER);
		
   
   
   }


}
void K230_Init_DATA_IT(void)
{

	for(int i=0;i<20;i++)
	{
		k230.STAUS_buffer[i]=0;
		k230.ONE_BUFFER[i]=0;
		k230.TWO_BUFFER[i]=0;
//		k230.THREE_BUFFER[i]=0;
//		k230.FOUR_BUFFER[i]=0;
//		k230.FIVE_BUFFER[i]=0;
//		k230.SIX_BUFFER[i]=0;
//		k230.SEVEN_BUFFER[i]=0;
//		k230.EVERN_BUFFER[i]=0;
		
	}
	
	//���в��Ե�ʱ�򣬽����ע��  (�ù۲�)
	for(int i=0;i<99;i++)
	{
		k230.DATA_buffer[i]=0;
		k230.RX_BUFFER[i]=0;
		k230.REXEIVE[i]=0;
	}

}
void K230_UART_Init(void)
{

	 
	

}

void K230_COUNTER(int num)
{
  if(num==1)
  {
	  //const char *msg = "@1#";
	uart3_send_string("@1#");
    // ʹ��HAL_UART_Transmit�����ַ���
  //  HAL_UART_Transmit_DMA(&huart3, (uint8_t*)msg, strlen(msg));
  
  }
   else	 if(num==2)
  {
	  //const char *msg1 = "@2#";
		uart3_send_string("@2#");
    // ʹ��HAL_UART_Transmit�����ַ���
   // HAL_UART_Transmit_DMA(&huart3, (uint8_t*)msg1, strlen(msg1));
  
  }
  else	 if(num==0)
  {
	 // const char *msg2 = "@0#";
	 uart3_send_string("@0#");
    // ʹ��HAL_UART_Transmit�����ַ���
  //  HAL_UART_Transmit_DMA(&huart3, (uint8_t*)msg1, strlen(msg1));
  
  }


}


void K230_DISPOSE(void)
{
	for(int i=0;i<100;i++)
	{
	   if(k230.REXEIVE[i]=='@')
	   {
		   k230.head_location=i;
		   break;
	   
	   }
	
	}
	
	for(int i=k230.head_location;i<99;i++)
	{
		   if(k230.REXEIVE[i]=='#')//�Ұ�β
		   {
			  k230.length=i-k230.head_location;//���㵽�˳���
		   
		   }
		   
	}
	for(int i=0;i<k230.length;i++)
	{
	  k230.RX_BUFFER[i]=k230.REXEIVE[i+k230.head_location+1];
	}
	
	for(int i=0; i<k230.length-1;i++)
	{
		if(k230.RX_BUFFER[i]=='^')
		{
			k230.STAUS_LENGTH=i-0;
			for(int k=0;k<k230.STAUS_LENGTH;k++)
			{
				k230.STAUS_buffer[k]=k230.RX_BUFFER[k] ;
			}
			 k230.STAUS=atoi(k230.STAUS_buffer); //�õ�״̬��
			
			break;
		}	
	}
//	     char REDX_BUFFER[20];
//	   char REDY_BUFFER[20];
//	   char GREENX_BUFFER[20];
//	   char GREENY_BUFFER[20];
	if( k230.STAUS==2) //״̬�����Ϊ2 //���͵ĺ��̵������
	{
		for(int i=0; i<k230.length;i++)
		{
		   if(k230.RX_BUFFER[i]=='^')
		   {
			   k230.DATA_HEAD_LOCATION=i;
		   }
		   else if(k230.RX_BUFFER[i]=='#')
		   {
			   k230.DATA_length=i-k230.DATA_HEAD_LOCATION;
			   for(int i=0;i<k230.DATA_length-1;i++) //�����Ѿ������е����ֽ����������
			   {
					  k230.DATA_buffer[i]=k230.RX_BUFFER[i+k230.DATA_HEAD_LOCATION+1];
			   }
			  				
		   }
		}
		//�����ǽ���Ӧ��λ�ô������ܰ�������
		for(int q=0;q<=2;q++)
		{
		   k230.ONE_BUFFER[q]=k230.DATA_buffer[q+0];
		   k230.TWO_BUFFER[q]=k230.DATA_buffer[q+3];
//		   k230.THREE_BUFFER[q]=k230.DATA_buffer[q+6];
//		   k230.FOUR_BUFFER[q]=k230.DATA_buffer[q+9];
			
		
		}
		
		  k230_DATA_GET(k230.STAUS);
		
		
		
	
	}
	else if(k230.STAUS==1)//���Ϊ1��ʾ������Ҫ���о��ο� ��  ��24λ
	{
		 for(int i=0; i<k230.length;i++)
		{
		   if(k230.RX_BUFFER[i]=='^')
		   {
			   k230.DATA_HEAD_LOCATION=i;
		   }
		   else if(k230.RX_BUFFER[i]=='#')
		   {
			   k230.DATA_length=i-k230.DATA_HEAD_LOCATION;
			   for(int i=0;i<k230.DATA_length-1;i++) //�����Ѿ������е����ֽ����������
			   {
					  k230.DATA_buffer[i]=k230.RX_BUFFER[i+k230.DATA_HEAD_LOCATION+1];
			   }
			  				
		   }
		}
		
		//�����ǽ���Ӧ��λ�ô������ܰ�������
		for(int q=0;q<=2;q++)
		{
		   k230.ONE_BUFFER[q]=k230.DATA_buffer[q+0];
		   k230.TWO_BUFFER[q]=k230.DATA_buffer[q+3];
		   k230.THREE_BUFFER[q]=k230.DATA_buffer[q+6];
		   k230.FOUR_BUFFER[q]=k230.DATA_buffer[q+9];
		   k230.FIVE_BUFFER[q]=k230.DATA_buffer[q+12];
		   k230.SIX_BUFFER[q]=k230.DATA_buffer[q+15];
		   k230.SEVEN_BUFFER[q]=k230.DATA_buffer[q+18];
		   k230.EVERN_BUFFER[q]=k230.DATA_buffer[q+21];
		   k230.NINE_BUFFER[q]=k230.DATA_buffer[q+24];
		   k230.TEN_BUFFER[q]=k230.DATA_buffer[q+27];
			
		
		}
		
		  k230_DATA_GET(k230.STAUS);
		
		
		
		
	
	
	
	}
	
	
	
	
	
	

	
K230_Init_DATA_IT();



}


