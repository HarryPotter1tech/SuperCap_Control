#pragma once
#include "main.h"
#include <vector>

namespace algorithm::pid_controller{

class PID_Controller{
    public:
    PID_Controller(float Kp,float Ki,float Kd,float OUT_MAX,float OUT_MIN,bool SWITCH):Kp(Kp),Ki(Ki),Kd(Kd),pre_error(0),integral(0),OUT_MAX(OUT_MAX),OUT_MIN(OUT_MIN),SWITCH(SWITCH){};
    void PID_init();
    float PID_calculate(float target_point, float real_value);
    
    private:
    float Kp;
    float Ki;
    float Kd;
    float error;
    float pre_error;
    float integral ;
    float derivative;
    float output;
    float OUT_MAX;
    float OUT_MIN;
    bool SWITCH;
};
}