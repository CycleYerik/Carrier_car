#include "motor.h"
// 轮子直径10cm，轮子周长31.4cm

#define pi 3.1415926
#define wheel_circumference 31.4 //轮子周长
#define pulse_per_circle 3200 //每圈脉冲数
#define spin_radius 15 //自转半径，数据不准确


/// @brief  用来测试底盘移动
void test_move()
{
    Forward_move(100, 10, 50);
    HAL_Delay(4000);
}

/// @brief 整车立即停车
void stop()
{
    Emm_V5_Stop_Now(1, 0);
    HAL_Delay(10);
    Emm_V5_Stop_Now(2, 0);
    HAL_Delay(10);
    Emm_V5_Stop_Now(3, 0);
    HAL_Delay(10);
    Emm_V5_Stop_Now(4, 0);
    HAL_Delay(10);
}

/// @brief 以速度模式前进
/// @param vel 
/// @param acc 
void Forward_move_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
    HAL_Delay(10);
}

/// @brief 整车前进
/// @param vel 
/// @param acc 
/// @param distance //单位cm 
void Forward_move( uint16_t vel,uint8_t acc, uint32_t distance)
{
    uint32_t clk = distance / wheel_circumference * pulse_per_circle;
    Emm_V5_Pos_Control(1, 0, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 0, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 以速度模式后退
/// @param vel 
/// @param acc 
void Backward_move_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 整车后退
/// @param vel 
/// @param acc 
/// @param distance //单位cm
void Backward_move( uint16_t vel,uint8_t acc, uint32_t distance)
{
    uint32_t clk = distance / wheel_circumference * pulse_per_circle;
    Emm_V5_Pos_Control(1, 1, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 1, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 以速度模式左走
/// @param vel 
/// @param acc 
void move_left_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 左走
/// @param vel 
/// @param acc 
/// @param distance //单位cm
void move_left(uint16_t vel,uint8_t acc, uint32_t distance)
{
    uint32_t clk = distance / wheel_circumference * pulse_per_circle;
    Emm_V5_Pos_Control(1, 0, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 1, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 以速度模式右走
/// @param vel 
/// @param acc 
void move_right_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}


/// @brief 右走
/// @param vel 
/// @param acc 
/// @param distance //单位cm
void move_right(uint16_t vel,uint8_t acc, uint32_t distance)
{
    uint32_t clk = distance / wheel_circumference * pulse_per_circle;
    Emm_V5_Pos_Control(1, 1, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 0, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 以速度模式左转
/// @param vel 
/// @param acc 
void spin_left_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 1, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}


/// @brief 左转
/// @param vel 
/// @param acc 
/// @param angle //单位度 
void spin_left(uint16_t vel,uint8_t acc, uint32_t angle)
{
    uint32_t clk = (uint32_t)((float)angle / 360 * spin_radius * 2 * pi / wheel_circumference * pulse_per_circle);
    Emm_V5_Pos_Control(1, 1, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 1, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 1, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 以速度模式右转
/// @param vel 
/// @param acc 
void spin_right_velocity(uint16_t vel,uint8_t acc)
{
    Emm_V5_Vel_Control(1, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(2, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(3, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Vel_Control(4, 0, vel, acc, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}

/// @brief 右转
/// @param vel 
/// @param acc 
/// @param angle //单位度 
void spin_right(uint16_t vel,uint8_t acc, uint32_t angle)
{
    uint32_t clk = (uint32_t)((float)angle / 360 * spin_radius * 2 * pi / wheel_circumference * pulse_per_circle);
    Emm_V5_Pos_Control(1, 0, vel, acc,clk, 0,1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(2, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(3, 0, vel, acc,clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Pos_Control(4, 0, vel, acc, clk, 0, 1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(1);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(2);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(3);
    HAL_Delay(10);
    Emm_V5_Synchronous_motion(4);
}




/**
  * @brief    速度模式
  * @param    addr：电机地址
  * @param    dir ：方向       ，0为CW，其余值为CCW(逆时针)
  * @param    vel ：速度       ，范围0 - 5000RPM
  * @param    acc ：加速度     ，范围0 - 255，注意：0是直接启动
  * @param    snF ：多机同步标志，false为不启用，true为启用
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Vel_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, bool snF)
{
  uint8_t cmd[16] = {0};

  // 装载命令
  cmd[0] =  addr;                       // 地址
  cmd[1] =  0xF6;                       // 功能码
  cmd[2] =  dir;                        // 方向
  cmd[3] =  (uint8_t)(vel >> 8);        // 速度(RPM)高8位字节
  cmd[4] =  (uint8_t)(vel >> 0);        // 速度(RPM)低8位字节
  cmd[5] =  acc;                        // 加速度，注意：0是直接启动
  cmd[6] =  snF;                        // 多机同步运动标志
  cmd[7] =  0x6B;                       // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, 8);
}

/**
  * @brief    位置模式
  * @param    addr：电机地址
  * @param    dir ：方向        ，0为CW，其余值为CCW
  * @param    vel ：速度(RPM)   ，范围0 - 5000RPM
  * @param    acc ：加速度      ，范围0 - 255，注意：0是直接启动
  * @param    clk ：脉冲数      ，范围0- (2^32 - 1)个
  * @param    raF ：相位/绝对标志，false为相对运动，true为绝对值运动
  * @param    snF ：多机同步标志 ，false为不启用，true为启用
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Pos_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, bool raF, bool snF)
{
  uint8_t cmd[16] = {0};

  // 装载命令
  cmd[0]  =  addr;                      // 地址
  cmd[1]  =  0xFD;                      // 功能码
  cmd[2]  =  dir;                       // 方向
  cmd[3]  =  (uint8_t)(vel >> 8);       // 速度(RPM)高8位字节
  cmd[4]  =  (uint8_t)(vel >> 0);       // 速度(RPM)低8位字节 
  cmd[5]  =  acc;                       // 加速度，注意：0是直接启动
  cmd[6]  =  (uint8_t)(clk >> 24);      // 脉冲数(bit24 - bit31)
  cmd[7]  =  (uint8_t)(clk >> 16);      // 脉冲数(bit16 - bit23)
  cmd[8]  =  (uint8_t)(clk >> 8);       // 脉冲数(bit8  - bit15)
  cmd[9]  =  (uint8_t)(clk >> 0);       // 脉冲数(bit0  - bit7 )
  cmd[10] =  raF;                       // 相位/绝对标志，false为相对运动，true为绝对值运动
  cmd[11] =  snF;                       // 多机同步运动标志，false为不启用，true为启用
  cmd[12] =  0x6B;                      // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, 13);
}

/**
  * @brief    立即停止（所有控制模式都通用）
  * @param    addr  ：电机地址
  * @param    snF   ：多机同步标志，false为不启用，true为启用
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Stop_Now(uint8_t addr, bool snF)
{
  uint8_t cmd[16] = {0};
  
  // 装载命令
  cmd[0] =  addr;                       // 地址
  cmd[1] =  0xFE;                       // 功能码
  cmd[2] =  0x98;                       // 辅助码
  cmd[3] =  snF;                        // 多机同步运动标志
  cmd[4] =  0x6B;                       // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, 5);
}

/**
  * @brief    将当前位置清零
  * @param    addr  ：电机地址
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Reset_CurPos_To_Zero(uint8_t addr)
{
  uint8_t cmd[16] = {0};
  
  // 装载命令
  cmd[0] =  addr;                       // 地址
  cmd[1] =  0x0A;                       // 功能码
  cmd[2] =  0x6D;                       // 辅助码
  cmd[3] =  0x6B;                       // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, 4);
}

/**
  * @brief    多机同步运动
  * @param    addr  ：电机地址
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Synchronous_motion(uint8_t addr)
{
  uint8_t cmd[16] = {0};
  
  // 装载命令
  cmd[0] =  addr;                       // 地址
  cmd[1] =  0xFF;                       // 功能码
  cmd[2] =  0x66;                       // 辅助码
  cmd[3] =  0x6B;                       // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, 4);
}

/**
  * @brief    读取系统参数
  * @param    addr  ：电机地址
  * @param    s     ：系统参数类型
  * @retval   地址 + 功能码 + 命令状态 + 校验字节
  */
void Emm_V5_Read_Sys_Params(uint8_t addr, SysParams_t s)
{
  uint8_t i = 0;
  uint8_t cmd[16] = {0};
  
  // 装载命令
  cmd[i] = addr; ++i;                   // 地址

  switch(s)                             // 功能码
  {
    case S_VER  : cmd[i] = 0x1F; ++i; break;
    case S_RL   : cmd[i] = 0x20; ++i; break;
    case S_PID  : cmd[i] = 0x21; ++i; break;
    case S_VBUS : cmd[i] = 0x24; ++i; break;
    case S_CPHA : cmd[i] = 0x27; ++i; break;
    case S_ENCL : cmd[i] = 0x31; ++i; break;
    case S_TPOS : cmd[i] = 0x33; ++i; break;
    case S_VEL  : cmd[i] = 0x35; ++i; break;
    case S_CPOS : cmd[i] = 0x36; ++i; break;
    case S_PERR : cmd[i] = 0x37; ++i; break;
    case S_FLAG : cmd[i] = 0x3A; ++i; break;
    case S_ORG  : cmd[i] = 0x3B; ++i; break;
    case S_Conf : cmd[i] = 0x42; ++i; cmd[i] = 0x6C; ++i; break;
    case S_State: cmd[i] = 0x43; ++i; cmd[i] = 0x7A; ++i; break;
    default: break;
  }

  cmd[i] = 0x6B; ++i;                   // 校验字节
  
  // 发送命令
  usart_SendCmd_u1(cmd, i);
}

