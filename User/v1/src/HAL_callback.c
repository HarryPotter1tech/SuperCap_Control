#include "HAL_callback.h"
#include "ADC_Calibration.h"
#include "CAN_communicate.h"
#include "Data_collect.h"
#include "MOS_driver.h"
#include "PID_controller.h"
#include "const_data.h"
#include "module_data.h"
#include "stm32g474xx.h"
#include "stm32g4xx_hal_tim.h"
#include "tim.h"

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
  if (hadc->Instance == ADC1) {
    Data_process(&adc_data);// 处理ADC采样数据,包括分发数据和转换真实值
  }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM8) {

    // 2kHz 功率环
    if (PID_FREQUENCY_INDEX == __HAL_TIM_GET_COUNTER(&htim8) / 50) {
      PID_calculate(&voltage_pid_configs, power_pid_configs.output,
                    adc_data.V_CHASSIS_REAL);
    }

    // 10kHz 电压环
    else if (PID_FREQUENCY_INDEX == __HAL_TIM_GET_COUNTER(&htim8) / 10) {
      PID_calculate(&power_pid_configs, can_rx.targetChassisPower,
                    adc_data.V_CHASSIS_REAL *
                        adc_data.I_CHASSIS_REAL);
    }

    // 100kHz 电流环
    else {
      PID_calculate(&current_pid_configs, voltage_pid_configs.output,
                    adc_data.I_CHASSIS_REAL);
      MosDriver_chassis_set(current_pid_configs.output, &mos_driver);
      MosDriver_cap_set(1 - current_pid_configs.output, &mos_driver);
    }
  }
  // 1kHz CAN发送和断连检测
  if (htim->Instance == TIM16) {
    CAN_send();
    CAN_disconnect_detection();
  }
}

/*控制环路运行流程图*/
// 1 所有模块初始化
// 2 CAN_receive接收目标功率和使能信号
// 3 调用一次电流环PID根据采样直接设置输出，初始化输出
// 4 触发HRTIM PWM输出
// 5 HRTIM Compare4事件触发ADC采样
// 6 ADC转换完成中断回调处理采样数据
// 7 定时器6中断回调进行数据校准、电流环PID计算和MOS驱动更新
// 8 定时器7中断回调进行电压环PID计算
// 9 定时器1中断回调进行功率环PID计算
// 10 定时器16中断回调进行CAN发送和断连检测
// 11 重复步骤4-10