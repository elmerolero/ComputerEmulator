#pragma once
#include <cstdint>
#include <cstdbool>
#include "../include/memory.h"
#include "../include/armv6Cpsr.h"
#include "../include/armv6Decoder.h"

class armv6 {
    public:
        void ExecuteInstruction(void);

        std::uint32_t And(std::uint32_t a, std::uint32_t b);
        std::uint32_t Eor(std::uint32_t a, std::uint32_t b);
        std::uint32_t Sub(std::uint32_t a, std::uint32_t b);
        std::uint32_t Rsb(std::uint32_t a, std::uint32_t b);
        std::uint32_t Add(std::uint32_t a, std::uint32_t b);
        std::uint32_t Adc(std::uint32_t a, std::uint32_t b);
        std::uint32_t Sbc(std::uint32_t a, std::uint32_t b);
        std::uint32_t Rsc(std::uint32_t a, std::uint32_t b);
        std::uint32_t Tst(std::uint32_t a, std::uint32_t b);
        std::uint32_t Teq(std::uint32_t a, std::uint32_t b);
        std::uint32_t Cmp(std::uint32_t a, std::uint32_t b);
        std::uint32_t Cmn(std::uint32_t a, std::uint32_t b);
        std::uint32_t Orr(std::uint32_t a, std::uint32_t b);
        std::uint32_t Mov(std::uint32_t a, std::uint32_t b);
        std::uint32_t Bic(std::uint32_t a, std::uint32_t b);
        std::uint32_t Mvn(std::uint32_t a, std::uint32_t b);

    private:
        std::uint32_t Registers[16];
        memory Memory;
        armv6Cpsr Cpsr;
        armv6Decoder decoder;     
};
