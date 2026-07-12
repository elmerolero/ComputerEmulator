#pragma once
#include <cstdint>
#include <cstdbool>

class decoder {
    public:
        void SetInstruction(std::uint32_t instruction);

        void GetCondition(void);

    private:
        std::uint32_t Instruction;
}; 

std::uint32_t And(std::uint32_t a, std::uint32_t b);
bool ConditionAlways(void);
