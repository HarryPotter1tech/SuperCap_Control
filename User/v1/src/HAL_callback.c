#include "HAL_callback.h"
#include "MOS_driver.h"
#include "module_data.h"
#include "stm32g4xx_hal_fdcan.h"
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan,
                               uint32_t RxFifo0ITs) {
  if (RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) {
    CAN_receive();
  }
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
  if (hadc->Instance == ADC1) {
    Data_distribute(&adc_data); // 处理ADC采样数据,包括分发数据和转换真实值
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM8) {
    uint32_t counter = __HAL_TIM_GET_COUNTER(&htim8);
    // 1kHz 功率环：目标功率 vs 实际功率 (V * I)
    if (PID_FREQUENCY_INDEX == counter / 100) {
      PID_calculate(&power_pid_configs, can_rx.targetChassisPower,
                    adc_data.V_CAP_TF * adc_data.I_CAP_TF);
    }

    // 5kHz 电压环：目标电压 (来自功率环) vs 实际电压
    else if (PID_FREQUENCY_INDEX == counter / 20) {
      PID_calculate(&voltage_pid_configs, power_pid_configs.output,
                    adc_data.V_CAP_TF);
    }

    // 50kHz 电流环：目标电流 (来自电压环) vs 实际电流
    else if (PID_FREQUENCY_INDEX == counter / 2) {
      ADC_Transformer_voltage(&adc_data);
      ADC_Transformer_current(&adc_data);

      if (adc_data.I_CAP_TF > 15.0f || adc_data.V_CAP_TF < 30.0f) {
        MosDriver_stop(&mos_driver);
      } // 过流保护&过压保护

      PID_calculate(&current_pid_configs, voltage_pid_configs.output,
                    adc_data.I_CAP_TF);
      MosDriver_dutylimit(&mos_driver, current_pid_configs.output);
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