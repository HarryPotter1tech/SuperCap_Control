#include "algorithm/filter.hpp"

namespace algorithm::filter{
    void Filter::Filter_init()
    {
        buffer.clear();
        head = 0;
        sum = 0.0f;
    }

    float Filter::Filter_calculate(float input)
    {
        if(!SWITCH) return input;

        // 首次调用：预填充整个缓冲区为相同值，保持原有行为但使用环形缓冲实现
        if (buffer.empty()) {
            buffer.assign(WINDOW_SIZES, input);
            sum = input * static_cast<float>(WINDOW_SIZES);
            head = 0;
            return input;
        }

        // 使用环形缓冲覆盖 oldest 元素，更新 sum（O(1)）
        // head 指向将被覆盖的位置（即最旧的元素）
        sum -= buffer[head];        // 移除被覆盖的旧值
        buffer[head] = input;       // 写入新值
        sum += input;               // 加上新值
        head = (head + 1) % WINDOW_SIZES; // 推进 head

        return sum / static_cast<float>(WINDOW_SIZES);
    }
}