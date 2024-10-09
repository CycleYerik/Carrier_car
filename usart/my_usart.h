#ifndef __MY_USART_H__
#define __MY_USART_H__

#include "main.h"
#include "stm32f1xx_hal_usart.h"
#include "usart.h"
#include "string.h"
#include "motor.h"
#include "uart_screen.h"

void usart_SendCmd_u1(__IO uint8_t *cmd, uint8_t len);
void usart_SendByte_u1(uint16_t data);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void UART_receive_process();
void UART_send_data_u2(char* data);

// 定义uchar
typedef unsigned char uchar;

#endif
