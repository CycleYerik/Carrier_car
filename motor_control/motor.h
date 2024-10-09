#ifndef __MOTOR_H__
#define __MOTOR_H__
#include "main.h"
#include "my_usart.h"


void test_move();
void stop();
void Forward_move_velocity(uint16_t vel,uint8_t acc);
void Forward_move( uint16_t vel,uint8_t acc, uint32_t distance);
void Backward_move_velocity(uint16_t vel,uint8_t acc);
void Backward_move( uint16_t vel,uint8_t acc, uint32_t distance);
void spin_left_velocity(uint16_t vel,uint8_t acc);
void spin_left(uint16_t vel,uint8_t acc, uint32_t angle);
void spin_right_velocity(uint16_t vel,uint8_t acc);
void spin_right(uint16_t vel,uint8_t acc, uint32_t angle);
void move_left_velocity(uint16_t vel,uint8_t acc);
void move_left(uint16_t vel,uint8_t acc, uint32_t distance);
void move_right_velocity(uint16_t vel,uint8_t acc);
void move_right(uint16_t vel,uint8_t acc, uint32_t distance);

void Emm_V5_Pos_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, bool raF, bool snF);
void Emm_V5_Vel_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, bool snF);
void Emm_V5_Stop_Now(uint8_t addr, bool snF);
void Emm_V5_Reset_CurPos_To_Zero(uint8_t addr);
void Emm_V5_Synchronous_motion(uint8_t addr);
void Emm_V5_Read_Sys_Params(uint8_t addr, SysParams_t s);

#endif
