#include "SuperCap_Init.h"
#include "CAN_communicate.h"
#include "PID_controller.h"
#include "module_data.h"

void SuperCap_init(void) {
    if (ADC_ID_init()) {
        CAN_init();
        MosDriver_TIMER_init();
        MosDriver_CHANCEL_init();
        Data_init(&adc_data);
        PID_init(&current_pid_configs);
        PID_init(&voltage_pid_configs);
        PID_init(&power_pid_configs);
    } else {
        Error_Handler();
    }
}