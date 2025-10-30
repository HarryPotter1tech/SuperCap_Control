#pragma once
#include "main.h"
#include "stm32g4xx_hal_adc.h"
#include <cstdint>

namespace datacollect {
    class DataCollector {
    public:
    DataCollector();
    void Data_init();//重置清零，初始化
    void Data_get();//获取adc采样值
    void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);//重定义ADC转换回调函数，分发变量
    uint16_t Get_voltage_chassis();//获取底盘端电压
    uint16_t Get_current_chassis();//获取底盘端电流
    uint16_t Get_voltage_cap();//获取电容组端电压
    uint16_t Get_current_cap();//获取电容组端电流
    private:
    uint16_t V_CHASSIS_ADC;//底盘端电压
    uint16_t I_CHASSIS_ADC;//底盘端电流
    uint16_t V_CAP_ADC;//电容组端电压
    uint16_t I_CAP_ADC;//电容组端电流
    uint32_t DataArray[4]={0};//ADC采样数组
};
} 
