#pragma once
#include "data.h"
#include "hrtim.h"
#include "main.h"
#include "stm32g4xx_hal_hrtim.h"

typedef struct {
  uint16_t cap_compare1_index;
  uint16_t cap_compare3_index;
  uint16_t chassis_compare1_index;
  uint16_t chassis_compare3_index;
  uint16_t Phase_shift_angle;
} mosdriver;

void MosDriver_TIMER_init();
void MosDriver_CHANCEL_init();
void MosDriver_chassis_set(uint16_t chassis_duty,mosdriver* driver);
void MosDriver_cap_set(uint16_t cap_duty,mosdriver* driver);
void MosDriver_start(mosdriver* driver);
void MosDriver_stop(mosdriver* driver);

