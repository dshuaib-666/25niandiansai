/*
 * MY_USART_DMA.c
 *
 *  Created on: Jul 12, 2025
 *      Author: 31552
 */
  #include "CSZ_ALL.h"


#ifndef MY_USART_DMA_C_
#define MY_USART_DMA_C_

/**
//���к���ΪTI���ڲ��������ռ�DMAת�˺�����ʹ��ǰ��Ҫ����DMA����ģʽRepeat Single|Transfer Size=1|ADD MODEΪ Fixed addr. to Block addr.|Source Lengt Byte|Destination Length Byte

*/





uint8_t      U1gConsoleTxTransmitted=1;
uint8_t		 U1gConsoleTxDMATransmitted ;
 void UART1_Console_write(uint8_t *data, uint16_t size)
{
    //�����ڷ�����Ϻ󣬲ſ��ٴη���
//    if(U1gConsoleTxTransmitted)
//    {
//        //����Դ��ַ
//        DL_DMA_setSrcAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)(data));
//    
//        //����Ŀ���ַ
//        DL_DMA_setDestAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)(&UART_1_INST->TXDATA));
//    
//        //����Ҫ���˵��ֽ���
//        DL_DMA_setTransferSize(DMA, DMA_CH2_CHAN_ID, size);
//    
//        //ʹ��DMAͨ��
//        DL_DMA_enableChannel(DMA, DMA_CH2_CHAN_ID);
//    
//        U1gConsoleTxTransmitted    = false;
//        U1gConsoleTxDMATransmitted = false;
//    }

}




	

void my_usart_receive_idle_dma_INIT(void)
{
//		NVIC_ClearPendingIRQ(UART3_INT_IRQn);
//		NVIC_EnableIRQ(UART3_INT_IRQn);
//		 DL_UART_enableInterrupt(UART_3_INST, DL_UART_IIDX_RX);
//		
//		DL_DMA_setSrcAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)(&UART_3_INST->RXDATA));
//		DL_DMA_setDestAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)k230.REXEIVE);
//		DL_DMA_setTransferSize(DMA, DMA_CH2_CHAN_ID, 1);
//	    //DL_DMA_setTriggerSource(DMA, DMA_CH0_CHAN_ID, DL_DMA_TRIGGER_SOURCE_UART_RX);
//		DL_DMA_enableChannel(DMA, DMA_CH2_CHAN_ID);
}

void my_usart_tf_dma_init(void)
{


	
	NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);

NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
//    //ʹ��DMAͨ��
//    DL_DMA_enableChannel(DMA, DMA_CH0_CHAN_ID);
//	DL_DMA_enableChannel(DMA, DMA_CH2_CHAN_ID);

}


void dma_tset(void)
{



	 //	 UART1_Console_write("122",7);
        delay_1ms(1000);
	//	 	 UART1_Console_write("122",7);
        delay_1ms(1000);
		
}


void UART3_IRQHandler(void) {
  
	switch (DL_UART_Main_getPendingInterrupt(UART_3_INST)) {
  /*! UART interrupt index for UART receive */
		case DL_UART_MAIN_IIDX_RX: 
		   k230.REXEIVE[k230.POINT] = DL_UART_Main_receiveData(UART_3_INST);
		   if(k230.REXEIVE[k230.POINT]!='@'&&k230.STAUS_STUAS==0) 
		   {
			  k230.REXEIVE[k230.POINT]=0;
                  			  k230.POINT=0;
		   
		   }
		   else if(k230.REXEIVE[k230.POINT]=='@'&&k230.STAUS_STUAS==0)
		   {                 
			  k230.POINT++;
			 k230.STAUS_STUAS=1;  
		   
		   }
		   else if(k230.REXEIVE[k230.POINT]!='^'&&k230.STAUS_STUAS==1)
		   {
			 k230.POINT++;
		   }
		   else if(k230.REXEIVE[k230.POINT]=='^'&&k230.STAUS_STUAS==1)
		   {
			   k230.POINT++;
			   k230.STAUS_STUAS=2;
		   }
		   else if(k230.REXEIVE[k230.POINT]!='#'&&k230.STAUS_STUAS==2)
		   {
			   k230.POINT++;
			
		   }
		   else if(k230.REXEIVE[k230.POINT]=='#'&&k230.STAUS_STUAS==2)
		   {
			  // k230.POINT++;
			   k230.STAUS_STUAS=0;
			   k230.POINT=0;
			   K230_DISPOSE();
		   }
 
		  
     
 
    break;
		    //���ڷ������
	
    
  default: 
    break;
  }
}

 
void UART_1_INST_IRQHandler(void) {
  
	switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) {
  /*! UART interrupt index for UART receive */
		case DL_UART_MAIN_IIDX_DMA_DONE_RX: 

     
	  NVIC_ClearPendingIRQ(UART1_INT_IRQn);
    break;
		    //���ڷ������
	case DL_UART_MAIN_IIDX_EOT_DONE:
		U1gConsoleTxTransmitted = true;
	NVIC_ClearPendingIRQ(UART1_INT_IRQn);
		break;
	//DMA�������
	case DL_UART_MAIN_IIDX_DMA_DONE_TX:
		U1gConsoleTxDMATransmitted = true;
	NVIC_ClearPendingIRQ(UART1_INT_IRQn);
		break;
    
  default:  NVIC_ClearPendingIRQ(UART1_INT_IRQn);
    break;
  }
	
  NVIC_ClearPendingIRQ(UART1_INT_IRQn);
}

////���ڵ��жϷ�����
//void UART_1_INST_IRQHandler(void)
//{
//    //��������˴����ж�
//    switch( DL_UART_getPendingInterrupt(UART_3_INST) )
//    {		
//					case DL_UART_MAIN_IIDX_DMA_DONE_RX:   			
//         
//					
//					NVIC_ClearPendingIRQ(UART1_INT_IRQn);
//            break;

//        default://�����Ĵ����ж�
//					NVIC_ClearPendingIRQ(UART1_INT_IRQn);
//            break;
//    }
//}


#endif /* MY_USART_DMA_C_ */
