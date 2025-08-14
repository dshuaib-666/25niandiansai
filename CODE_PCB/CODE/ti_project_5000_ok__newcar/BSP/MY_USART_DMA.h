/*
 * MY_USRT_DMA.h
 *
 *  Created on: Jul 12, 2025
 *      Author: 31552
 */

#ifndef MY_USART_DMA_H_
#define MY_USART_DMA_H_
#include "stdint.h"
////void my_usart_receive_idle_dma_INIT(UART_HandleTypeDef *huart, uint8_t *pData,uint16_t SIZE);

int DATE_analysis(char* date, int* output_X,int* output_Y,int*output_S);

void my_usart_receive_idle_dma_INIT(void);

void my_usart_tf_dma_init(void);
void dma_tset(void);
 void UART1_Console_write(uint8_t *data, uint16_t size);
#endif /* MY_USART_DMA_H_ */
