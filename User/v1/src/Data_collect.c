#include "Data_collect.h"

void Data_init(datacollect *data) {
  data->V_CHASSIS_ADC = 0;
  data->I_CHASSIS_ADC = 0;
  data->V_CAP_ADC = 0;
  data->I_CAP_ADC = 0;
  data->V_CHASSIS_REAL = 0;
  data->I_CHASSIS_REAL = 0;
  data->V_CAP_REAL = 0;
  data->I_CAP_REAL = 0;
  for (int i = 0; i < 4; i++) {
    data->DataArray[i] = 0;
  }
}


void Data_process(datacollect *data)//这里还需要进一步的数据转换y=kx+b，要把adc值转换成实际的电压电流值.应该还会有一个函数 Data_collect_to_real()
{
  data->V_CHASSIS_ADC=data->DataArray[0];
  data->I_CHASSIS_ADC=data->DataArray[1];
  data->V_CAP_ADC=data->DataArray[2];
  data->I_CAP_ADC=data->DataArray[3];
  ADC_Calibration(data);
}


uint16_t Get_voltage_chassis(datacollect *data) { return data->V_CHASSIS_REAL; }


uint16_t Get_current_chassis(datacollect *data) { return data->I_CHASSIS_REAL; }


uint16_t Get_voltage_cap(datacollect *data) { return data->V_CAP_REAL; }


uint16_t Get_current_cap(datacollect *data) { return data->I_CAP_REAL; }
