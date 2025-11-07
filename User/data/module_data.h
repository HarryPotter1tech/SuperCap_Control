#pragma once
#include <stdint.h>
#include <sys/_intsup.h>

// 控制算法开关（放在枚举之外，作为独立的常量）
bool control_v1 = 0; // 控制算法v1
bool control_v2 = 0; // 控制算法v2

/*这里有两个版本是由于版本一是洪泓霖学长设计的控制算法，版本二是我
新设计的控制算法，本套代码主要目的是重构洪泓霖学长的代码，提供更好
的调试框架，其次才是我考虑实现我的控制算法，具体这两种控制算法的设
计可以查看下面这个链接:
https://fa4g5no1b1f.feishu.cn/wiki/AhU2wcN2ditQpXkVa6RcQfOXnyc

// */

// 存放超级电容相关的运行状态枚举
enum State {
  DCDC_OUTPUT_DISABLE = 0, // DCDC 输出关闭
  DCDC_OUTPUT_ENABLE = 1,  // DCDC 输出使能
}; // enum State

//CAN_communicate模块的数据结构体定义
typedef struct {
  uint16_t chassis_power;
  uint16_t supercap_voltage;
  uint16_t chassis_voltage;
  uint8_t enabled;
  uint8_t unused;
} CAN_TX;
typedef struct {
  uint16_t targetChassisPower;
  uint8_t enabled;
} CAN_RX;

// MOS_driver模块的数据结构体定义
typedef struct {
  uint16_t cap_compare1_index;
  uint16_t cap_compare3_index;
  uint16_t chassis_compare1_index;
  uint16_t chassis_compare3_index;
  uint16_t Phase_shift_angle;
} mosdriver;

// Data_collect模块的数据结构体定义
typedef struct {
  uint16_t V_CHASSIS_ADC; // 底盘端电压
  uint16_t I_CHASSIS_ADC; // 底盘端电流
  uint16_t V_CAP_ADC;     // 电容组端电压
  uint16_t I_CAP_ADC;     // 电容组端电流
  uint32_t DataArray[4];  // ADC采样数组
} datacollect;

// PID_controller模块的数据结构体定义
typedef struct {
  float Kp;
  float Ki;
  float Kd;
  float error;
  float pre_error;
  float integral;
  float derivative;
  float output;
  float OUT_MAX;
  float OUT_MIN;
  bool SWITCH;
} PID_Configs;

// 全局变量声明
// CAN通信相关全局变量
extern CAN_TX can_tx;// 全局CAN发送数据结构体
extern CAN_RX can_rx;// 全局CAN接收数据结构体

// MOS驱动相关全局变量
extern mosdriver mos_driver;// 全局MOS驱动数据结构体

// ADC采集相关全局变量
extern datacollect adc_data;// 全局ADC采集数据结构体
extern datacollect adc_calibrated_data;// 全局ADC校准后数据结构体

// PID控制相关全局变量
extern PID_Configs current_pid_configs;// 全局电流环PID配置结构体
extern PID_Configs voltage_pid_configs;// 全局电压环PID配置结构体
extern PID_Configs power_pid_configs;// 全局功率环PID配置结构体

// 控制算法转换系数
extern float power_offset_to_voltage;// 功率环输出转电压环目标值的转换系数
extern float voltage_offset_to_current;// 电压环输出转电流环目标值的转换系数