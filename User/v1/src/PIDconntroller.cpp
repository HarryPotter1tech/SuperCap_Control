#include "PIDcontroller.hpp"

namespace algorithm::pid_controller {
void PID_Controller::PID_init() {
  error = 0;
  pre_error = 0;
  integral = 0;
  derivative = 0;
  output = 0;
}
float PID_Controller::PID_calculate(float target_point, float real_value) {
  if (!SWITCH) {
    return 0.0f;
  }
  error = target_point - real_value;
  integral += error;
  derivative = error - pre_error;
  pre_error = error;
  output = Kp * error + Ki * integral + Kd * derivative;
  if (output > OUT_MAX) {
    output = OUT_MAX;
  } else if (output < OUT_MIN) {
    output = OUT_MIN;
  }
  return output;
}
} // namespace algorithm::pid_controller