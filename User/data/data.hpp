#pragma once
#include <cstdint>
#include <vector>

/*
  命名空间：data::const_data
  存放工程中使用的只读常量（编译期常量或只读运行时常量）。
*/
namespace data::const_data{
    // CAN/消息或设备 ID（十六进制表示）
    constexpr uint16_t RMCS_ID   = 0x1fe;  // RMCS 设备ID
    constexpr uint16_t LEGGED_ID = 0x427;  // Legged 设备ID
    constexpr uint16_tint SUPERCAP_ID = 0x300;// Supercap 设备ID
    constexpr uint32_t P_CHASSIS_LIMIT = 35.0; // 底盘功率上限（单位：W）
    const std::vector<double> ADC1_OFFSET = {2048.0, 2048.0, 2048.0, 2048.0};// ADC 校准/偏移值：按通道给出的偏移量
    const uint32_t V_CHASISS_MAX=26;
    const uint32_t V_CHASSIS_MIN=22;
    const uint32_t V_CAP_MAX=27;
    const uint32_t V_CAP_MIN=4;
    const uint32_t I_CAP_MAX=16;
    
}

// 命名空间：data::supercap_state
// 存放超级电容相关的运行状态枚举
namespace data::supercap_state{
    enum State{
        DCDC_OUTPUT_DISABLE = 0, // DCDC 输出关闭
        DCDC_OUTPUT_ENABLE  = 1, // DCDC 输出使能
    };
}