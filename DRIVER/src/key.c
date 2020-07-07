#include "key.h"

void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(KEY1_CLK | KEY2_CLK ,ENABLE);

	GPIO_InitStructure.GPIO_Pin=KEY1_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;

	GPIO_Init(KEY1_PORT,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=KEY2_PIN;
	GPIO_Init(KEY2_PORT,&GPIO_InitStructure);
}

u8 Key_Scan(GPIO_TypeDef * GPIOx, u16 GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 1)//KEY_ON
	{
		//Delay(1s);
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 1)
		{
			while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 1);
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

void EXTI_GPIO_Config(void)
{
	EXTI_InitTypeDef EXIT_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(KEY1_EXIT_GPIO_PORTSOURCE,KEY1_EXIT_GPIO_PINSOURCE);
	EXIT_InitStructure.EXTI_Line=EXTI_Line13;
	EXIT_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXIT_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXIT_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXIT_InitStructure);

	GPIO_EXTILineConfig(KEY2_EXIT_GPIO_PORTSOURCE,KEY2_EXIT_GPIO_PINSOURCE);
	EXIT_InitStructure.EXTI_Line=EXTI_Line0;
	EXIT_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXIT_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXIT_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXIT_InitStructure);	
}
