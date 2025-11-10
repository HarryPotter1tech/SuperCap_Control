#pragma once
#include "module_data.h"
#include <stdint.h>
#include <sys/_intsup.h>

//设备固有常量定义
const int RMCS_ID = 0x1fe;   // RMCS 设备ID
const int LEGGED_ID = 0x427; // Legged 设备ID
const uint32_t SUPERCAP_ID[4][3] = {{{0x0034003C, 0x534B5009,
                                 0x20343732}}}; // Supercap 设备ID//测试板的ID
const int DEFAULT_POWER_CHASSIS = 35.0f;      // 初始默认底盘功率（单位：W）

// ADC校准参数定义
const double ADC_CALIBRATION_CONFIGS[4][4][2] = {{
    {0.0f, 0.0f},  // V_CHASSIS_Scale, V_CHASSIS_Bias
    {0.0f, 0.0f},  // V_CAP_Scale, V_CAP_Bias
    {0.01289f, 0.01289f}, // I_CHASSIS_Scale, I_CHASSIS_Bias
    {0.01289f, 0.01289f}  // I_CAP_Scale, I_CAP_Bias}
}}; // ADC校准参数配置数组

//底盘工作电压范围
const float V_CHASSIS_MAX = 26.0f;
const float V_CHASSIS_MIN = 22.0f;
const float P_CHASSIS_MAX = 200.0f;
const float P_CHASSIS_MIN = 35.0f; //底盘能量消耗至0后，机器人进入节能模式 35W

//超级电容工作电压、电流范围
const float V_CAP_MAX = 27.0f;
const float V_CAP_MIN = 4.0f;
const float I_CAP_MAX = 15.0f;

//开关管驱动参数
const float CYCLE_INDEX = 27200.0f;
const float HALF_CYCLE_INDEX = CYCLE_INDEX / 2;

//保护机制时间常数定义
const int MAX_POWER_LOST_DETECTION_TIME = 1000;//最大掉电检测时间
const int MAX_CAN_DISCONNECT_DETECTION_TIME = 500;//最大CAN断联检测时间
extern int POWER_LOST_DETECTION_TIME_INDEX;//掉电检测时间计数变量
extern int CAN_DISCONNECT_DETECTION_TIME_INDEX;//CAN断联检测时间计数变量
extern uint32_t PID_FREQUENCY_INDEX;//PID控制频率计数变量

