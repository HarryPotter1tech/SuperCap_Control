#include "module_data.h"

//CAN_communicate模块的数据结构体实例化
CAN_TX can_tx;
CAN_RX can_rx;

// MOS_driver模块的数据结构体实例化
mosdriver mos_driver;
// Data_collect模块的数据结构体实例化
datacollect adc_data;
// PID_controller模块的数据结构体实例化
PID_Configs voltage_pid_configs;// 电压环PID配置结构体全局定义
PID_Configs current_pid_configs;// 电流环PID配置结构体全局定义
PID_Configs power_pid_configs;// 功率环PID配置结构体全局定义
// ADC校准配置数组实例化
double ADC_CALIBRATION_CONFIGS_BOARD[4][2] = {
    {0.0, 0.0}, // V_CHASSIS
    {0.0, 0.0}, // I_CHASSIS
    {0.0, 0.0}, // V_CAP
    {0.0, 0.0}  // I_CAP
};
// 控制算法Z转换系数实例化
float power_offset_to_voltage = 1.0f; // 功率环输出转电压环目标值的转换系数全局定义
float voltage_offset_to_current = 1.0f; // 电压环输出转电流环目标值的转换系数全局定义