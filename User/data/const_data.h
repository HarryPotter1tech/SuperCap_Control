#pragma once
#include "module_data.h"
#include <stdint.h>
#include <sys/_intsup.h>

//设备固有常量定义
extern const int RMCS_ID;   // RMCS 设备ID
extern const int LEGGED_ID; // Legged 设备ID
extern const uint32_t SUPERCAP_ID[4][3]; // Supercap 设备ID//测试板的ID
extern const int DEFAULT_POWER_CHASSIS;      // 初始默认底盘功率（单位：W）
// ADC校准参数定义
extern const double ADC_CALIBRATION_CONFIGS[4][4][2];
// I_CAP_Scale, I_CAP_Bias} // ADC校准参数配置数组

//底盘工作电压范围
extern const float V_CHASSIS_MAX;
extern const float V_CHASSIS_MIN;
extern const float P_CHASSIS_MAX;
extern const float P_CHASSIS_MIN; //底盘能量消耗至0后，机器人进入节能模式 35W

//超级电容工作电压、电流范围
extern const float V_CAP_MAX;
extern const float V_CAP_MIN;
extern const float I_CAP_MAX;

//开关管驱动参数
extern const float CYCLE_INDEX;
extern const float HALF_CYCLE_INDEX;

//保护机制时间常数定义
extern const int MAX_POWER_LOST_DETECTION_TIME;//最大掉电检测时间
extern const int MAX_CAN_DISCONNECT_DETECTION_TIME;//最大CAN断联检测时间
extern int POWER_LOST_DETECTION_TIME_INDEX;//掉电检测时间计数变量
extern int CAN_DISCONNECT_DETECTION_TIME_INDEX;//CAN断联检测时间计数变量
extern uint32_t PID_FREQUENCY_INDEX;//PID控制频率计数变量

