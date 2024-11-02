#include "uart.h"
unsigned char string_buffer1[100] ="learn-in-depth:saif-essam";
unsigned char const string_buffer2[100] ="learn-in-depth:saif-essam";

void main(void)
{
	Uart_Send_string(string_buffer1);
}

