#pragma once
#include "adc.h"
#include "main.h"
#include "stm32g4xx_hal_adc.h"
#include <stdint.h>

void Data_init();               // 重置清零，初始化
void Data_get();                // 获取adc采样值
uint16_t Get_voltage_chassis(); // 获取底盘端电压
uint16_t Get_current_chassis(); // 获取底盘端电流
uint16_t Get_voltage_cap();     // 获取电容组端电压
uint16_t Get_current_cap();     // 获取电容组端电流
struct DataCollector {
  uint16_t V_CHASSIS_ADC; // 底盘端电压
  uint16_t I_CHASSIS_ADC; // 底盘端电流
  uint16_t V_CAP_ADC;     // 电容组端电压
  uint16_t I_CAP_ADC;     // 电容组端电流
  uint32_t DataArray[4];  // ADC采样数组
};
