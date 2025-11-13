#pragma once
#include "Data_collect.h"
#include "module_data.h"
#include "const_data.h"
#include "adc.h"
#include "hrtim.h"
#include "tim.h"
#include "stm32g4xx_hal_adc.h"
#include "stm32g4xx_hal_hrtim.h"
#include "stm32g4xx_hal_tim.h"

void HAL_FDCAN_RxFifo0Msgallback(FDCAN_HandleTypeDef *hfdcan);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
