#pragma once
#include <cstdint>
#include <sys/_intsup.h>
#include <vector>

/*
  命名空间：data::const_data
  存放工程中使用的只读常量（编译期常量或只读运行时常量）。
*/
namespace data::const_data {
// CAN/消息或设备 ID（十六进制表示）
constexpr int RMCS_ID = 0x1fe;         // RMCS 设备ID
constexpr int LEGGED_ID = 0x427;       // Legged 设备ID
constexpr int SUPERCAP_ID = 0x300;     // Supercap 设备ID
constexpr int P_CHASSIS_LIMIT = 35.0f; // 底盘功率上限（单位：W）
const std::vector<double> ADC1_OFFSET = {
    2048.0, 2048.0, 2048.0, 2048.0}; // ADC 校准/偏移值：按通道给出的偏移量
const float V_CHASISS_MAX = 26.0f;
const float V_CHASSIS_MIN = 22.0f;

const float V_CAP_MAX = 27.0f;
const float V_CAP_MIN = 4.0f;
const float I_CAP_MAX = 15.0f;

const float P_CHASSIS_MAX = 200.0f;
const float P_CHASSIS_MIN = 15.0f; // 存疑

const float CYCLE_INDEX = 27200.0f;
const float HALF_CYCLE_INDEX = CYCLE_INDEX / 2;
const int MAX_POWERLOST_DETECTION_TIME = 1000;
} // namespace data::const_data

// 命名空间：data::supercap_state
// 存放超级电容相关的运行状态枚举
namespace data::supercap_state {
enum State {
  DCDC_OUTPUT_DISABLE = 0, // DCDC 输出关闭
  DCDC_OUTPUT_ENABLE = 1,  // DCDC 输出使能
};
}
namespace data::version {
constexpr bool v1 = false; // 控制算法v1
constexpr bool v2 = false; // 控制算法v2

/*这里有两个版本是由于版本一是洪泓霖学长设计的控制算法，版本二是我
新设计的控制算法，本套代码主要目的是重构洪泓霖学长的代码，提供更好
的调试框架，其次才是我考虑实现我的控制算法，具体这两种控制算法的设
计可以查看下面这个链接:
https://fa4g5no1b1f.feishu.cn/wiki/AhU2wcN2ditQpXkVa6RcQfOXnyc

// */
} // namespace data::version