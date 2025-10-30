#pragma once
#include "main.h"
#include <cstdint>
#include <stdint.h>

namespace mosdriver{
    class MosDriver{
        public:
        MosDriver();
        void MosDriver_init();
        void MosDriver_cap_set(uint16_t cap_duty);
        void MosDriver_chassis_set(uint16_t chassis_duty);
        void MosDriver_start();
        void MosDriver_stop();
        private:
        uint16_t cap_compare1_index=0;
        uint16_t cap_compare3_index=0;
        uint16_t chassis_compare1_index=0;
        uint16_t chassis_compare3_index=0;
    };
}