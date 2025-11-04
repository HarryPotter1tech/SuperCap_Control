#include "HAL_callback.h"

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
  if (hadc->Instance == ADC1) {
    extern datacollect adc_data;
    Data_process(&adc_data);
  }
}

