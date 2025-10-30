#include "PIDcontroller.hpp"

namespace algorithm::pid_controller{
    void PID_Controller::PID_init()
    {
        integral = 0.0f;
        previous_error = 0.0f;
    }
    float PID_Controller::PID_calculate(float target_point, float real_value)
    {
        if(!SWITCH){
            return 0.0f;
        }
        float error = target_point - real_value;
        integral += error;
        float derivative = error - previous_error;
        previous_error = error;
        float output = Kp * error + Ki * integral + Kd * derivative;
        if(output > OUT_MAX){
            output = OUT_MAX;
        }else if(output < OUT_MIN){
            output = OUT_MIN;
        }
        return output;
    }
}