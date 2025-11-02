#include "MOSdriver.hpp"

void mosdriver::MosDriver::MosDriver_TIMER_init() {
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_MASTER);
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_TIMER_A);
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_TIMER_B);
}
void mosdriver::MosDriver::MosDriver_CHANCEL_init() {
  HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2 |
                                              HRTIM_OUTPUT_TB1 |
                                              HRTIM_OUTPUT_TB2);
}
void mosdriver::MosDriver::MosDriver_chassis_set(uint16_t chassis_duty) {
  chassis_compare1_index = data::const_data::HALF_CYCLE_INDEX -
                           0.9 * chassis_duty * data::const_data::CYCLE_INDEX;
  chassis_compare3_index = data::const_data::HALF_CYCLE_INDEX +
                           0.9 * chassis_duty * data::const_data::CYCLE_INDEX;
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_A, HRTIM_COMPAREUNIT_1,
                         chassis_compare1_index);
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_A, HRTIM_COMPAREUNIT_3,
                         chassis_compare3_index);
}
void mosdriver::MosDriver::MosDriver_cap_set(uint16_t cap_duty) {
  cap_compare1_index = data::const_data::HALF_CYCLE_INDEX -
                       0.9 * cap_duty * data::const_data::CYCLE_INDEX;
  cap_compare3_index = data::const_data::HALF_CYCLE_INDEX +
                       0.9 * cap_duty * data::const_data::CYCLE_INDEX;
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_B, HRTIM_COMPAREUNIT_1,
                         cap_compare1_index);
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_B, HRTIM_COMPAREUNIT_3,
                         cap_compare3_index);
}
void mosdriver::MosDriver::MosDriver_start() {
  MosDriver_TIMER_init();
  HAL_Delay(2);
  MosDriver_CHANCEL_init();
}
void mosdriver::MosDriver::MosDriver_stop() {
  HAL_HRTIM_WaveformOutputStop(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2 |
                                             HRTIM_OUTPUT_TB1 |
                                             HRTIM_OUTPUT_TB2);
  chassis_compare1_index = 0;
  chassis_compare3_index = 0;
  cap_compare1_index = 0;
  cap_compare3_index = 0;
  Phase_shift_angle = 0;
}