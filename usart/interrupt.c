#include "interrupt.h"

int tim1_count = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM1)
    {
        tim1_count++;
        if(tim1_count>1000)
        {
            tim1_count = 0;
        }
    }
}