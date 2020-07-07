#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY1_CLK RCC_APB2Periph_GPIOC
#define KEY1_PORT GPIOC
#define KEY1_PIN GPIO_Pin_13

#define KEY1_EXIT_GPIO_PORTSOURCE GPIO_PortSourceGPIOC
#define KEY1_EXIT_GPIO_PINSOURCE GPIO_PinSource13

#define KEY2_CLK RCC_APB2Periph_GPIOA
#define KEY2_PORT GPIOA
#define KEY2_PIN GPIO_Pin_0

#define KEY2_EXIT_GPIO_PORTSOURCE GPIO_PortSourceGPIOA
#define KEY2_EXIT_GPIO_PINSOURCE GPIO_PinSource0

void NVIC_Config(void);
void Key_GPIO_Config(void);
u8 Key_Scan(GPIO_TypeDef * GPIOx, u16 GPIO_Pin);
void EXTI_GPIO_Config(void);


#endif
