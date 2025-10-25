#pragma once
#include "main.h"
#include <vector>

namespace algorithm::pid_controller{
/**
 * @brief 简单 PID 控制器类
 *
 * 使用比例-积分-微分算法计算控制输出。构造时传入增益与输出限幅参数。
 */
class PID_Controller{
    public:
    /**
     * @brief 构造函数
     * @param Kp 比例增益
     * @param Ki 积分增益
     * @param Kd 微分增益
     * @param OUT_MAX 输出上限（用于限幅）
     * @param OUT_MIN 输出下限（用于限幅）
     * @param SWITCH 控制器使能开关，true 表示使能
     *
     * 注意：构造函数仅进行参数保存，若需要清除积分/历史状态请调用 PID_reset().
     */
    PID_Controller(float Kp,float Ki,float Kd,float OUT_MAX,float OUT_MIN,bool SWITCH):Kp(Kp),Ki(Ki),Kd(Kd),OUT_MAX(OUT_MAX),OUT_MIN(OUT_MIN),SWITCH(SWITCH),previous_error(0),integral(0){};

    /**
     * @brief 初始化 PID 控制器
     *
     * 执行任何需要的初始化步骤（如初始化内部状态、滤波器等）。
     * 在当前实现中可用于在任务启动时做一次性初始化。
     */
    void PID_init();

    /**
     * @brief 重置 PID 状态
     *
     * 将内部历史量（如上次误差、积分项等）清零，以避免旧状态影响后续控制。
     * 在控制器启停或切换目标时建议调用。
     */
    void PID_reset();

    /**
     * @brief 计算 PID 输出
     * @param target_point 目标值（期望值）
     * @param real_value 实际测量值
     * @return 受限的控制输出（已应用 OUT_MIN/OUT_MAX）
     *
     * 说明：
     * - 采用 (error = target_point - real_value) 作为误差信号。
     * - 函数应处理开关位 SWITCH：若 SWITCH 为 false，应返回 0 或不执行积分/微分更新（具体实现由 .cpp 决定）。
     * - 若使用积分，调用方需注意防积分饱和（可在实现中加入积分限幅）。
     */
    float PID_calculate(float target_point, float real_value);
    
    private:
    float Kp;
    float Ki;
    float Kd;
    float OUT_MAX;
    float OUT_MIN;
    bool SWITCH;
    float previous_error;
    float integral;
};
}