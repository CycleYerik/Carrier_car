# 电机驱动

## 概述
移植自张大头步进电机驱动代码，采用串口总线与四个电机进行通信，通过串口发送数据控制电机的转动，也接受电机的反馈的转速和位置数据

## 使用
- 在cubemx中配置串口usart1，配置串口的波特率为115200
- 在main.c中引入头文件`#include "motor.h"`
- 调用各种函数即可，传入速度、加速度、移动距离、电机地址等参数
- 电机的地址为1,2,3,4 分别为左前轮、右前轮、左后轮、右后轮

## 已完成
- 电机的转速控制
- 电机的转动圈数控制
- 电机的停车控制

## 待完成
- 读取电机的转速和位置数据
- 电机原地旋转的控制
- 电机校正函数（结合陀螺仪、视觉等进行行驶方向的辅助校正）
- 执行特定路径的控制（如从原点到某个点）
