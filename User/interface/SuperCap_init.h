#pragma once
#include <stdint.h>
#include "main.h"
#include "CAN_communicate.h"
#include "Data_collect.h"
#include "HAL_callback.h"
#include "MOS_driver.h"
#include "PID_controller.h"
#include "ADC_Calibration.h"
#include "const_data.h"
#include "module_data.h"

void SuperCap_init();//超级电容系统总初始化函数
void SuperCap_reinit();//超级电容系统下电重启函数