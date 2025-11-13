#pragma once
#include "adc.h"
#include "main.h"
#include "stm32g4xx_hal_adc.h"
#include "module_data.h"
#include "const_data.h"
#include <stdint.h>

void Data_init(datacollect* data);               // 重置清零，初始化
void Data_process(datacollect*data);             // 在ADC转换完成回调中处理分发adc值
uint16_t Get_voltage_chassis(datacollect* data); // 获取底盘端电压
uint16_t Get_current_chassis(datacollect* data); // 获取底盘端电流
uint16_t Get_voltage_cap(datacollect* data);     // 获取电容组端电压
uint16_t Get_current_cap(datacollect* data);     // 获取电容组端电流
