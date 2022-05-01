#include "stm32f10x.h"
#include "bsp_uart.h"

int main(void)//(int argc, char *argv)
{
	USART_Config();
	Uart_SendByte(USART1, 'K');
	//while(1)
	//{}
}
