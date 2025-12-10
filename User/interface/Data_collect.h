#pragma once
#include "ADC_Calibration.h"
#include "adc.h"
#include "const_data.h"
#include "main.h"
#include "module_data.h"
#include "stm32g4xx_hal_adc.h"
#include <stdint.h>

void Data_init(datacollect *data);       // 重置清零，初始化
void Data_distribute(datacollect *data); // 在ADC转换完成回调中处理分发adc值
