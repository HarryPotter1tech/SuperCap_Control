#pragma once
#include "data.h"
#include "datacollect.h"
#include "fdcan.h"
#include "main.h"
#include "stm32g4xx_hal_fdcan.h"

typedef struct {
  uint16_t chassis_power;
  uint16_t supercap_voltage;
  uint16_t chassis_voltage;
  uint8_t enabled;
  uint8_t unused;
} CAN_TX;

typedef struct {
  uint8_t targetChassisPower;
  uint8_t enabled;
} CAN_RX;
CAN_TX tx_data;
CAN_RX rx_data;
void CAN_init();
void CAN_send();
void CAN_receive();
void CAN_disconnect_detection();
