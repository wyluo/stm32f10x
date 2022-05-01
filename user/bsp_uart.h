#ifndef BSP_UART_H
#define BSP_UART_H

#include "stm32f10x.h"

#define USART_TX_PIN GPIO_Pin_9
#define USART_RX_PIN GPIO_Pin_10

static void NVIC_Configuration(void);
void USART_Config(void);
void Uart_SendByte(USART_TypeDef *pUSARTx, uint16_t data);


#endif
