#pragma once
#include "main.h"
#include "data.hpp"
#include "hrtim.h"
#include "stm32g4xx_hal_hrtim.h"

namespace mosdriver {

class MosDriver {
public:
  MosDriver();
  void MosDriver_TIMER_init();
  void MosDriver_CHANCEL_init();
  void MosDriver_chassis_set(uint16_t chassis_duty);
  void MosDriver_cap_set(uint16_t cap_duty);
  void MosDriver_start();
  void MosDriver_stop();

private:
  uint16_t cap_compare1_index = 0;
  uint16_t cap_compare3_index = 0;
  uint16_t chassis_compare1_index = 0;
  uint16_t chassis_compare3_index = 0;
  uint16_t Phase_shift_angle = 0;
};

} // namespace mosdriver