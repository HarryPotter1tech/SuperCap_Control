#pragma once
#include "Data_collect.h"
#include "module_data.h"
#include "adc.h"
#include "hrtim.h"
#include "tim.h"
#include "stm32g4xx_hal_adc.h"
#include "stm32g4xx_hal_hrtim.h"
#include "stm32g4xx_hal_tim.h"

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void HAL_HRTIM_Compare4EventCallback(HRTIM_HandleTypeDef *hhrtim, uint32_t TimerIdx);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);