#pragma once
#include "const_data.h"
#include "module_data.h"
#include "Data_collect.h"
#include "fdcan.h"
#include "main.h"
#include "stm32g4xx_hal_fdcan.h"

CAN_TX tx_data;
CAN_RX rx_data;
void CAN_init();
void CAN_send();
void CAN_receive();
void CAN_disconnect_detection();
