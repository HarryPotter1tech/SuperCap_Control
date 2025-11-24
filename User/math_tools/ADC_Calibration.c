#include "ADC_Calibration.h"

bool ADC_ID_init()//要做RMCS_ID/LEGGED_ID与SUPERCAP_ID  ADC_CALIBRATION_CONFIGS的匹配检测
{
    uint32_t uid[3];
    uid[0] = HAL_GetUIDw0();
    uid[1] = HAL_GetUIDw1();
    uid[2] = HAL_GetUIDw2();
    for(int i=0;i<4;i++)
    {
        if(uid[0]==SUPERCAP_ID[i][0]&&uid[1]==SUPERCAP_ID[i][1]&&uid[2]==SUPERCAP_ID[i][2])//匹配成功,分发对应ADC_CALIBRATION_CONFIGS
        {
            for (int j = 0; j < 4; j++) {
                ADC_CALIBRATION_CONFIGS_BOARD[j][0] = ADC_CALIBRATION_CONFIGS[i][j][0];
                ADC_CALIBRATION_CONFIGS_BOARD[j][1] = ADC_CALIBRATION_CONFIGS[i][j][1];
            }
            return true;
        }
    }
    return false;
}


void ADC_Calibration(datacollect* data) {

    data->V_CHASSIS_REAL = ADC_CALIBRATION_CONFIGS_BOARD[0][0] * data->V_CHASSIS_ADC + ADC_CALIBRATION_CONFIGS_BOARD[0][1];
    data->I_CHASSIS_REAL = ADC_CALIBRATION_CONFIGS_BOARD[1][0] * data->I_CHASSIS_ADC + ADC_CALIBRATION_CONFIGS_BOARD[1][1];
    data->V_CAP_REAL = ADC_CALIBRATION_CONFIGS_BOARD[2][0] * data->V_CAP_ADC + ADC_CALIBRATION_CONFIGS_BOARD[2][1];
    data->I_CAP_REAL = ADC_CALIBRATION_CONFIGS_BOARD[3][0] * data->I_CAP_ADC + ADC_CALIBRATION_CONFIGS_BOARD[3][1];
}