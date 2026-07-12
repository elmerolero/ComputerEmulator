#pragma once
#include <cstdint>
#include <cstdbool>
#include "../include/memory.h"

class armv6 {
    public:
        void ExecuteInstruction(void);

    private:
        std::uint32_t Registers[16];
        memory Memory;     
};

void And(std::uint32_t a, std::uint32_t b);
