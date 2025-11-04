#pragma once
#include "main.h"
typedef struct {
  float Kp;
  float Ki;
  float Kd;
  float error;
  float pre_error;
  float integral;
  float derivative;
  float output;
  float OUT_MAX;
  float OUT_MIN;
  bool SWITCH;
} PID_Configs;
void PID_init(PID_Configs *pid_configs);
void PID_set(PID_Configs *pid_configs, float Kp, float Ki, float Kd,
             float OUT_MAX, float OUT_MIN, bool SWITCH);
float PID_calculate(PID_Configs *pid_configs, float target_point,
                    float real_value);
