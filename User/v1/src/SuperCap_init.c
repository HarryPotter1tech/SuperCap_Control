#include "SuperCap_init.h"

#include "CAN_communicate.h"
#include "Data_collect.h"
#include "MOS_driver.h"
#include "PID_controller.h"
#include "module_data.h"

void SuperCap_init(void) {
    if (ADC_ID_init()) {
        CAN_init();
        MosDriver_init(&mos_driver);
        MosDriver_TIMER_init();
        Data_init(&adc_data);
        PID_init(&current_pid_configs);
        PID_init(&voltage_pid_configs);
        PID_init(&power_pid_configs);
        PID_set(&current_pid_configs, 0.01f, 0.0f, 0.0f, MAX_DUTY, MIN_DUTY,
                true);  // 电流环PID参数设置
        PID_set(&voltage_pid_configs, 0.0f, 0.00f, 0.0f, V_CAP_MAX, V_CAP_MIN,
                false);  // 电压环PID参数设置
        PID_set(&power_pid_configs, 0.0f, 0.00f, 0.0f, P_CHASSIS_MAX,
                P_CHASSIS_MIN, false);  // 功率环PID参数设置
    } else {
        Error_Handler();
    }
    SuperCap_softstart();
}

void SuperCap_softstart() {
    HAL_Delay(10);  // 等待数据获取，ADC采样-转换完成

    Data_distribute(&adc_data);

    float V_CHASSIS_INIT = adc_data.V_CHASSIS_ADC;
    float V_CAP_INIT = adc_data.V_CAP_ADC;
    // 这里的其实ADC/转换值都行，只是ADC值计算更简单一些
    float general_duty = 0.45f;
    // MosDriver_chassis_set(general_duty, &mos_driver);
    // MosDriver_cap_set(1 - general_duty, &mos_driver);
    MosDriver_dutylimit(&mos_driver, general_duty);
    HAL_Delay(10);  // 等待软启动完成
}
