#include "algorithm/filter.hpp"

namespace algorithm::filter{
    void Filter::Filter_init()
    {
        buffer.clear();
    }
    float Filter::Filter_calculate(float input)
    {
        if(!SWITCH){
            return input;
        }
        if (buffer.empty()) {
            // 首次样本：预填充整个缓冲区为相同值，避免启动偏差，虽然可能初始的响应会变慢
            buffer.assign(WINDOW_SIZES, input);
            return input;
        }
        buffer.push_back(input);
        if (buffer.size() > WINDOW_SIZES) {
            buffer.erase(buffer.begin());
        }
        float sum = 0.0f;
        for (float value : buffer) {
            sum += value;
        }
        return sum / buffer.size();
    }
}