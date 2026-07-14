#pragma once
#include <cstdint>
#include <cstdbool>
#include "../include/memory.h"
#include "../include/armv6Cpsr.h"
#include "../include/decoder.h"

class armv6 {
    public:
        void ExecuteInstruction(void);

    private:
        std::uint32_t Registers[16];
        memory Memory;
        armv6Cpsr Cpsr;
        decoder decoder;     
};

void And(std::uint32_t a, std::uint32_t b);
