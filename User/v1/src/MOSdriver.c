#include "MOSdriver.h"

void MosDriver_TIMER_init() {
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_MASTER);
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_TIMER_A);
  HAL_HRTIM_WaveformCountStart(&hhrtim1, HRTIM_TIMERID_TIMER_B);
}
void MosDriver_CHANCEL_init() {
  HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2 |
                                              HRTIM_OUTPUT_TB1 |
                                              HRTIM_OUTPUT_TB2);
}
void MosDriver_chassis_set(uint16_t chassis_duty,mosdriver* driver) {
  driver->chassis_compare1_index = HALF_CYCLE_INDEX -
                           0.9 * chassis_duty * CYCLE_INDEX;
  driver->chassis_compare3_index = HALF_CYCLE_INDEX +
                           0.9 * chassis_duty * CYCLE_INDEX;
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_A, HRTIM_COMPAREUNIT_1,
                         driver->chassis_compare1_index);
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_A, HRTIM_COMPAREUNIT_3,
                         driver->chassis_compare3_index);
}
void MosDriver_cap_set(uint16_t cap_duty,mosdriver* driver) {
  driver->cap_compare1_index = HALF_CYCLE_INDEX -
                       0.9 * cap_duty * CYCLE_INDEX;
  driver->cap_compare3_index = HALF_CYCLE_INDEX +
                       0.9 * cap_duty * CYCLE_INDEX;
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_B, HRTIM_COMPAREUNIT_1,
                         driver->cap_compare1_index);
  __HAL_HRTIM_SETCOMPARE(&hhrtim1, HRTIM_TIMERID_TIMER_B, HRTIM_COMPAREUNIT_3,
                         driver->cap_compare3_index);
}
void MosDriver_start(mosdriver* driver) {
  MosDriver_TIMER_init();
  HAL_Delay(2);
  MosDriver_CHANCEL_init();
}
void MosDriver_stop(mosdriver* driver) {
  HAL_HRTIM_WaveformOutputStop(&hhrtim1, HRTIM_OUTPUT_TA1 | HRTIM_OUTPUT_TA2 |
                                             HRTIM_OUTPUT_TB1 |
                                             HRTIM_OUTPUT_TB2);
  driver->chassis_compare1_index = 0;
  driver-> chassis_compare3_index = 0;
  driver->cap_compare1_index = 0;
  driver->cap_compare3_index = 0;
  driver->Phase_shift_angle = 0;
}