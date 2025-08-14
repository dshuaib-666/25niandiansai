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
//下列函数为TI串口不定长接收加DMA转运函数，使用前需要配置DMA发送模式Repeat Single|Transfer Size=1|ADD MODE为 Fixed addr. to Block addr.|Source Lengt Byte|Destination Length Byte

*/





uint8_t      U1gConsoleTxTransmitted=1;
uint8_t		 U1gConsoleTxDMATransmitted ;
 void UART1_Console_write(uint8_t *data, uint16_t size)
{
    //当串口发送完毕后，才可再次发送
//    if(U1gConsoleTxTransmitted)
//    {
//        //设置源地址
//        DL_DMA_setSrcAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)(data));
//    
//        //设置目标地址
//        DL_DMA_setDestAddr(DMA, DMA_CH2_CHAN_ID, (uint32_t)(&UART_1_INST->TXDATA));
//    
//        //设置要搬运的字节数
//        DL_DMA_setTransferSize(DMA, DMA_CH2_CHAN_ID, size);
//    
//        //使能DMA通道
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
//    //使能DMA通道
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
		    //串口发送完成
	
    
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
		    //串口发送完成
	case DL_UART_MAIN_IIDX_EOT_DONE:
		U1gConsoleTxTransmitted = true;
	NVIC_ClearPendingIRQ(UART1_INT_IRQn);
		break;
	//DMA搬运完成
	case DL_UART_MAIN_IIDX_DMA_DONE_TX:
		U1gConsoleTxDMATransmitted = true;
	NVIC_ClearPendingIRQ(UART1_INT_IRQn);
		break;
    
  default:  NVIC_ClearPendingIRQ(UART1_INT_IRQn);
    break;
  }
	
  NVIC_ClearPendingIRQ(UART1_INT_IRQn);
}

////串口的中断服务函数
//void UART_1_INST_IRQHandler(void)
//{
//    //如果产生了串口中断
//    switch( DL_UART_getPendingInterrupt(UART_3_INST) )
//    {		
//					case DL_UART_MAIN_IIDX_DMA_DONE_RX:   			
//         
//					
//					NVIC_ClearPendingIRQ(UART1_INT_IRQn);
//            break;

//        default://其他的串口中断
//					NVIC_ClearPendingIRQ(UART1_INT_IRQn);
//            break;
//    }
//}


#endif /* MY_USART_DMA_C_ */
