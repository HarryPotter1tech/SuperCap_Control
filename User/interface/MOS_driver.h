#pragma once
#include "const_data.h"
#include "module_data.h"
#include "hrtim.h"
#include "main.h"
#include "stm32g4xx_hal_hrtim.h"

void MosDriver_TIMER_init();
void MosDriver_CHANCEL_init();
void MosDriver_chassis_set(uint16_t chassis_duty,mosdriver* driver);
void MosDriver_cap_set(uint16_t cap_duty,mosdriver* driver);
void MosDriver_init(mosdriver* driver);
void MosDriver_stop(mosdriver* driver);
void MosDriver_dutylimit(mosdriver* driver,float duty);
