#include "datacollect.hpp"
#include "adc.h"

void datacollect::DataCollector::Data_init() {
  V_CHASSIS_ADC = 0;
  I_CHASSIS_ADC = 0;
  V_CAP_ADC = 0;
  I_CAP_ADC = 0;
  DataArray[4] = {0};
}

void datacollect::DataCollector::Data_get() {
  HAL_ADC_Start_DMA(&hadc1, DataArray, 4);
  HAL_ADC_GetValue(&hadc1);
}

void datacollect::DataCollector::HAL_ADC_ConvCpltCallback(
    ADC_HandleTypeDef *hadc) {
  for (unit8_t i = 0; i < 4; i++) // 转换映射为实际电压值，电流值
  {
    DataArray[i] *= 33.0f / 4095.0f;
  }
  V_CHASSIS_ADC = DataArray[0];
  I_CHASSIS_ADC = DataArray[1];
  V_CAP_ADC = DataArray[2];
  I_CAP_ADC = DataArray[3];
}
uint16_t datacollect::DataCollector::Get_voltage_chassis() {
  return V_CHASSIS_ADC;
}
uint16_t datacollect::DataCollector::Get_current_chassis() {
  return I_CHASSIS_ADC;
}
uint16_t datacollect::DataCollector::Get_voltage_cap() { return V_CAP_ADC; }
uint16_t datacollect::DataCollector::Get_current_cap() { return I_CAP_ADC; }