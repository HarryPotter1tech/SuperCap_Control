#pragma once
#include "const_data.h"
#include "module_data.h"
#include "Data_collect.h"
#include <stdint.h>

void ADC_Calibration(datacollect* adc_data, datacollect* adc_calibrated_data, uint16_t RAW_V_CHASSIS_ADC, uint16_t RAW_V_CAP_ADC,
                         uint16_t RAW_I_CHASSIS_ADC,uint16_t RAW_I_CAP_ADC);