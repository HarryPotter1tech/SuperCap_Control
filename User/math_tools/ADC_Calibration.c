#include "ADC_Calibration.h"
#include "module_data.h"
#include "stm32g4xx_hal_conf.h"
#include <stdint.h>

void ADC_Calibration(datacollect* adc_data,datacollect* adc_calibrated_data,uint16_t RAW_V_CHASSIS_ADC,uint16_t RAW_I_CHASSIS_ADC,
                         uint16_t RAW_V_CAP_ADC,uint16_t RAW_I_CAP_ADC) {

    adc_calibrated_data->V_CHASSIS_ADC = ADC_CALIBRATION_CONFIGS[0][0] * RAW_V_CHASSIS_ADC + ADC_CALIBRATION_CONFIGS[0][1];
    adc_calibrated_data->I_CHASSIS_ADC = ADC_CALIBRATION_CONFIGS[1][0] * RAW_I_CHASSIS_ADC + ADC_CALIBRATION_CONFIGS[1][1];
    adc_calibrated_data->V_CAP_ADC = ADC_CALIBRATION_CONFIGS[2][0] * RAW_V_CAP_ADC + ADC_CALIBRATION_CONFIGS[2][1];
    adc_calibrated_data->I_CAP_ADC = ADC_CALIBRATION_CONFIGS[3][0] * RAW_I_CAP_ADC + ADC_CALIBRATION_CONFIGS[3][1];
}