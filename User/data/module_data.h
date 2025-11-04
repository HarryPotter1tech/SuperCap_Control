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
  uint8_t targetChassisPower;
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