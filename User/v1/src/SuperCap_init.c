#include "SuperCap_init.h"
#include "CAN_communicate.h"
#include "Data_collect.h"
#include "MOS_driver.h"
#include "PID_controller.h"
#include "module_data.h"

void SuperCap_init(void) {
  if (ADC_ID_init()) {
    CAN_init();
    Data_init(&adc_data);
    MosDriver_init(&mos_driver);
    MosDriver_TIMER_init();
    // Data_init(&adc_data);
    PID_init(&current_pid_configs);
    PID_init(&voltage_pid_configs);
    PID_init(&power_pid_configs);
  } else {
    Error_Handler();
  }
  SuperCap_softstart();
}

void SuperCap_softstart() {
  HAL_Delay(10); // 等待数据获取，ADC采样-转换完成

  Data_distribute(&adc_data);

  float V_CHASSIS_INIT = adc_data.V_CHASSIS_ADC;
  float V_CAP_INIT = adc_data.V_CAP_ADC;
  // 这里的其实ADC/转换值都行，只是ADC值计算更简单一些

  float general_duty = V_CAP_INIT / V_CHASSIS_INIT;
  MosDriver_dutylimit(&mos_driver, general_duty);
  HAL_Delay(10); // 等待软启动完成
}
