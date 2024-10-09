#include "my_usart.h"

uint8_t rxdata_u2[50],rxdata_u3[50]; // usart2,3接收缓冲区
uint8_t received_rxdata_u2,received_rxdata_u3; // 暂存usart2,3接收到的数据
uchar rxflag_u2,rxflag_u3;
int velocity = 30;
int acceleration = 20;

__IO bool rxFrameFlag = false;
__IO uint8_t rxCmd[FIFO_SIZE] = {0};
__IO uint8_t rxCount = 0;
#define FIFO_SIZE 128

/// @brief 串口中断回调函数
/// @param huart 
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    rxdata_u2[rxflag_u2++] = received_rxdata_u2;
    rxdata_u3[rxflag_u3++] = received_rxdata_u3;
    if(huart->Instance == USART2)
    {
        HAL_UART_Receive_IT(huart, &received_rxdata_u2, 1); // 每次处理一个字符
    }
    else if(huart->Instance == USART3)
    {
        HAL_UART_Receive_IT(huart, &received_rxdata_u3, 1); // 每次处理一个字符
    }
}
  
/// @brief 处理接收到的串口屏数据
void UART_receive_process()
{
    if(rxflag_u3 >0)
    {
        HAL_UART_Transmit(&huart3, (uint8_t*)"hello,summer", strlen("hello,summer"), 50);
        // 将PB0引脚电平翻转
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
        printf("t0.txt=\"%s\"\xff\xff\xff",rxdata_u3);
        rxflag_u3 = 0;
        memset(rxdata_u3, 0, 30);
 
    }
    if(rxflag_u2 >0)
    {
        // if(
			// rxflag > 50)
        // {
        //     HAL_UART_Transmit(&huart3, (uint8_t*)"too long\r\n", 10, 50);
        // }
        // else
        // {
        //     HAL_UART_Transmit(&huart3, (uint8_t*)"success", strlen("success"), 50);
        //     HAL_UART_Transmit(&huart3, (uint8_t*)rxdata, rxflag, 50);
        // }

        // 处理接收到的数据


        // 前进
        if(rxdata_u2[0] == 0x21)
        {
            Forward_move_velocity(velocity, acceleration);
        }
        // 后退
        else if(rxdata_u2[0] == 0x12)
        {
            Backward_move_velocity(velocity, acceleration);
        }
        // 停止
        else if (rxdata_u2[0] == 0x88)
        {
            stop();
        }
        
        // 左走
        else if(rxdata_u2[0] == 0x13)
        {
            move_left_velocity(velocity,acceleration);
        }
        // 右走
        else if(rxdata_u2[0] == 0x14)
        {
            move_right_velocity(velocity,acceleration);
        }
        // 左旋
        else if(rxdata_u2[0] == 0x15)
        {
            spin_left_velocity(velocity,acceleration);
        }
        // 右旋
        else if(rxdata_u2[0] == 0x16)
        {
            spin_right_velocity(velocity, acceleration);
        }
        else if (rxdata_u2[0] == 0x66)
        {
            if(velocity < 200)
            {
                velocity += 10;
            }
        }
        else if (rxdata_u2[0] == 0x99)
        {
            if(velocity > 10)
            {
                velocity -= 10;
            }
        }



        // 清空接收缓冲区
        rxflag_u2 = 0;
        memset(rxdata_u2, 0, 30);
    }
}

void UART_send_data_u2(char* data)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), 50);
}




void usart_SendCmd_u1(__IO uint8_t *cmd, uint8_t len)
{
	__IO uint8_t i = 0;
	
	for(i=0; i < len; i++) { usart_SendByte_u1(cmd[i]); }
}

void usart_SendByte_u1(uint16_t data)
{
	__IO uint16_t t0 = 0;
	
	USART1->DR = (data & (uint16_t)0x01FF);

	while(!(USART1->SR & USART_FLAG_TXE))
	{
		++t0; if(t0 > 8000)	{	return; }
	}
}
