#pragma once
#include <stdint.h>
#include <sys/_intsup.h>

const int RMCS_ID = 0x1fe;   // RMCS 设备ID
const int LEGGED_ID = 0x427; // Legged 设备ID
const uint32_t SUPERCAP_ID[3] = {0x0034003C, 0x534B5009,
                                 0x20343732}; // Supercap 设备ID//测试板的ID
const int P_CHASSIS_LIMIT = 35.0f;            // 底盘功率上限（单位：W）

const float ADC1_OFFSET[4] = {2048.0, 2048.0, 2048.0,
                              2048.0}; // ADC 校准/偏移值：按通道给出的偏移量

const float V_CHASSIS_MAX = 26.0f;
const float V_CHASSIS_MIN = 22.0f;

const float V_CAP_MAX = 27.0f;
const float V_CAP_MIN = 4.0f;
const float I_CAP_MAX = 15.0f;

const float P_CHASSIS_MAX = 200.0f;
const float P_CHASSIS_MIN = 15.0f; // 存疑

const float CYCLE_INDEX = 27200.0f;
const float HALF_CYCLE_INDEX = CYCLE_INDEX / 2;

const int MAX_POWER_LOST_DETECTION_TIME = 1000;
static int POWER_LOST_DETECTION_TIME_INDEX;
const int MAX_CAN_DISCONNECT_DETECTION_TIME = 500;
static int CAN_DISCONNECT_DETECTION_TIME_INDEX;

