#include "MOSdriver.hpp"
#include "hrtim.h"


void mosdriver::MosDriver::MosDriver_TIMER_init()
{
    
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_MASTER);
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_TIMER_A);
    HAL_HRTIM_WaveformCountStart(&hhrtim1,HRTIM_TIMERID_TIMER_B);
}
void mosdriver::MosDriver::MosDriver_CHANCEL_init()
{
    HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TA1|HRTIM_OUTPUT_TA2|HRTIM_OUTPUT_TB1|HRTIM_OUTPUT_TB2);
}
void mosdriver::MosDriver::MosDriver_cap_set(uint16_t cap_duty)
{
    
}
void mosdriver::MosDriver::MosDriver_chassis_set(uint16_t chassis_duty)
{

}
void mosdriver::MosDriver::MosDriver_start()
{
    MosDriver_TIMER_init();
    HAL_Delay(2);
    MosDriver_CHANCEL_init();
}
void mosdriver::MosDriver::MosDriver_stop()
{
    HAL_HRTIM_WaveformOutputStop(&hhrtim1, HRTIM_OUTPUT_TA1|HRTIM_OUTPUT_TA2|HRTIM_OUTPUT_TB1|HRTIM_OUTPUT_TB2);
    chassis_compare1_index=0;
    chassis_compare3_index=0;
    cap_compare1_index=0;
    cap_compare3_index=0;
}