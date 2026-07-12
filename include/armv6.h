#pragma once
#include <cstdint>
#include <cstdbool>

class armV6 {
    public:


    private:
        std::uint32_t Registers[16];
        std::uint8_t* Memory;

        bool Carry;
        bool Zero;
        bool Overflow;
        bool Negative;
};
