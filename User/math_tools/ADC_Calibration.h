#pragma once
#include "const_data.h"
#include "module_data.h"
#include "Data_collect.h"
#include <stdint.h>
#include <stdbool.h>
#include "ADC_Calibration.h"



bool ADC_ID_init();
void ADC_Calibration(datacollect* adc_data);//对adc_data进行校准和转换然后存回adc_data