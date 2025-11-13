#include "SuperCap_init.h"
#include "CAN_communicate.h"
#include "PID_controller.h"
#include "module_data.h"

void SuperCap_init(void) {
    if (ADC_ID_init()) {
        CAN_init();
        MosDriver_init(&mos_driver);
        Data_init(&adc_data);
        PID_init(&current_pid_configs);
        PID_init(&voltage_pid_configs);
        PID_init(&power_pid_configs);
    } else {
        Error_Handler();
    }
    SuperCap_softstart();
}

void SuperCap_softstart() {
    HAL_Delay(20);//等待数据获取，ADC采样-转换完成
    float general_duty =Get_voltage_chassis(&adc_data)/Get_voltage_cap(&adc_data);
    MosDriver_dutylimit(&mos_driver, general_duty);
}
