#pragma once
#include "ADC_Calibration.h"
#include "Data_collect.h"
#include "const_data.h"
#include "module_data.h"
#include <stdbool.h>
#include <stdint.h>

bool ADC_ID_init();
void ADC_Transformer_voltage(datacollect *adc_data);
void ADC_Transformer_current(datacollect *adc_data);
// 对adc_data进行转换然后存回adc_data