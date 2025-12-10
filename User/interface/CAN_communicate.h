#pragma once
#include "Data_collect.h"
#include "const_data.h"
#include "fdcan.h"
#include "main.h"
#include "module_data.h"
#include "stm32g4xx_hal_fdcan.h"

void CAN_init();
void CAN_send();
void CAN_receive();
void CAN_disconnect_detection();
