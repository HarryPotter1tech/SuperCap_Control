#include "MOSdriver.hpp"
#include "hrtim.h"
#include "stm32_hal_legacy.h"
#include "stm32g4xx_hal_hrtim.h"

void mosdriver::MosDriver::MosDriver_init()
{
    HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1|HRTIM_OUTPUT_TA2|HRTIM_OUTPUT_TB1|HRTIM_OUTPUT_TB2);
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_MASTER);
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_TIMER_A);
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_TIMER_B);
}
void mosdriver::MosDriver::MosDriver_cap_set(uint16_t cap_duty)
{
    
}