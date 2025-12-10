#include "Data_collect.h"
#include "adc.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_adc_ex.h"
#include <stdint.h>

void Data_init(datacollect *data) {
  data->V_CHASSIS_ADC = 0;
  data->I_CHASSIS_ADC = 0;
  data->V_CAP_ADC = 0;
  data->I_CAP_ADC = 0;
  data->V_CHASSIS_TF = 0;
  data->I_CHASSIS_TF = 0;
  data->V_CAP_TF = 0;
  data->I_CAP_TF = 0;
  for (int i = 0; i < 4; i++) {
    data->DataArray[i] = 0;
  }
  HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
  HAL_Delay(10);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)data->DataArray, 4);
}

void Data_distribute(datacollect *data) {
  data->V_CHASSIS_ADC = data->DataArray[0];
  data->I_CHASSIS_ADC = data->DataArray[1];
  data->I_CAP_ADC = data->DataArray[2];
  data->V_CAP_ADC = data->DataArray[3];
}
