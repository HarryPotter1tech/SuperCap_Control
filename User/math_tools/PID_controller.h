#pragma once
#include "main.h"
#include "const_data.h"
#include "module_data.h"

void PID_init(PID_Configs *pid_configs);
void PID_set(PID_Configs *pid_configs, float Kp, float Ki, float Kd,
             float OUT_MAX, float OUT_MIN, bool SWITCH);
float PID_calculate(PID_Configs *pid_configs, float target_point,
                    float real_value);
