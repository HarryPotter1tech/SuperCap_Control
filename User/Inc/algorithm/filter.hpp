#pragma once
#include "main.h"
#include <vector>

namespace algorithm::filter{
/**
 * @brief 简单滑动/窗口滤波器类
 *
 * 使用固定窗口大小的缓冲区对输入数据进行平滑处理。
 */
class Filter{
    public:
    /**
     * @brief 构造函数
     * @param WINDOW_SIZES 窗口大小（样本点数），应为正整数,注意一定不要等于零
     * @param SWITCH 滤波器使能标志，true 表示启用滤波，false 直接透传输入
     *
     * 构造时不会填充缓冲区，首次调用 Filter_calculate 时根据实现决定如何处理不足窗口的数据。
     */
    Filter(int WINDOW_SIZES,bool SWITCH):WINDOW_SIZES(WINDOW_SIZES),SWITCH(SWITCH){
        if(WINDOW_SIZES<=0) this->WINDOW_SIZES=10;
    }

    /**
     * @brief 计算滤波输出
     * @param input 新的输入样本
     * @return 滤波后的输出值（若 SWITCH 为 false，则通常返回 input）
     *
     * 说明：
     * - 典型实现为滑动窗口平均（或加权平均），内部使用 buffer 存储最近 WINDOW_SIZES 个样本。
     * - 当缓冲区未填满时，可返回当前缓冲区的平均值或直接返回输入（由实现决定）。
     * - 若 WINDOW_SIZES <= 0，应直接返回输入以避免错误。
     */
    void Filter_init();
    float Filter_calculate(float input);
    private:
    int WINDOW_SIZES;
    bool SWITCH;
    std::vector<float> buffer;

    // 新增用于环形缓冲的状态，避免每次 erase/shift
    int head = 0;        // 下一个被覆盖的位置
    float sum = 0.0f;    // 当前窗口和，用于 O(1) 计算平均
};
}