#pragma once
#include <cstdint>
#include <cstdbool>
#include "../include/armv6Cpsr.h"

class decoder {
    public:
        void SetInstruction(std::uint32_t instruction);

        void GetCondition(void);

    private:
        std::uint32_t Instruction;
        static bool (*const conditionals[])(const armv6Cpsr & const cpsr);
}; 

std::uint32_t And(std::uint32_t a, std::uint32_t b);
bool ConditionEqual(const armv6Cpsr & cpsr);
bool ConditionNotEqual(const armv6Cpsr & cpsr);
bool ConditionHigherOrSame(const armv6Cpsr & cpsr);
bool ConditionLower(const armv6Cpsr & cpsr);
bool ConditionMinus(const armv6Cpsr & cpsr);
bool ConditionPlus(const armv6Cpsr & cpsr);
bool ConditionSignedOverflow(const armv6Cpsr & cpsr);
bool ConditionNoSignedOverflow(const armv6Cpsr & cpsr);
bool ConditionHigher(const armv6Cpsr & cpsr);
bool ConditionLowerOrSame(const armv6Cpsr & cpsr);
bool ConditionGreaterOrEqual(const armv6Cpsr & cpsr);
bool ConditionLessThan(const armv6Cpsr & cpsr);
bool ConditionGreaterThan(const armv6Cpsr & cpsr);
bool ConditionLessThanOrEqual(const armv6Cpsr & cpsr);
bool ConditionAlways(const armv6Cpsr & cpsr);
