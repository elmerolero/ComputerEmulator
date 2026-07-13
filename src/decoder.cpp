#include "../include/decoder.h"
using namespace std;

void decoder::SetInstruction(uint32_t instruction) {
    this -> Instruction = instruction;
}

void decoder::GetCondition(void) {

}

bool (*const decoder::conditionals[])(const armv6Cpsr & const cpsr) = {
    &ConditionEqual,
    &ConditionNotEqual,
    &ConditionHigherOrSame,
    &ConditionLower,
    &ConditionMinus,
    &ConditionPlus,
    &ConditionSignedOverflow,
    &ConditionNoSignedOverflow,
    &ConditionHigher,
    &ConditionLowerOrSame,
    &ConditionGreaterOrEqual,
    &ConditionLessThan,
    &ConditionGreaterThan,
    &ConditionLessThanOrEqual,
    &ConditionAlways
};

uint32_t And(uint32_t a, uint32_t b) {
    return a + b;
}

/*
 * Represents the conditional operation EQ (Equal).
 * Indicated when Zero (Z) == 1
 */
bool ConditionEqual(const armv6Cpsr & const cpsr) {
    return cpsr.IsZero();
}


/*
 * Represents the conditional operation NE (Not equal).
 * Indicated when Zero (Z) == 0
 */
bool ConditionNotEqual(const armv6Cpsr & const cpsr) {
    return !cpsr.IsZero();
}


/*
 * Represents the conditional operation HS/CS (Unsigned higher or same
 * or carry set).
 * Indicated when Carry (C) == 1
 */
bool ConditionHigherOrSame(const armv6Cpsr & const cpsr) {
    return cpsr.IsCarry();
}

/*
 * Represents the conditional operation LO/CC (Unsigned lower or same
 * or carry clear).
 * Indicated when Carry (C) == 0
 */
bool ConditionLower(const armv6Cpsr & const cpsr) {
    return !cpsr.IsCarry();
}

/*
 * Represents the conditional operation MI (Negative or minus).
 * Indicated when Negative (N) == 1
 */
bool ConditionMinus(const armv6Cpsr & const cpsr) {
    return cpsr.IsNegative();
}

/*
 * Represents the conditional operation PL (Positive or plus).
 * Indicated when Negative (N) == 0
 */
bool ConditionPlus(const armv6Cpsr & const cpsr) {
    return !cpsr.IsNegative();
}

/*
 * Represents the conditional operation VS (Signed overflow).
 * Indicated when Negative (V) == 1
 */
bool ConditionSignedOverflow(const armv6Cpsr & const cpsr) {
    return cpsr.IsOverflow();
}

/*
 * Represents the conditional operation VS (No signed overflow).
 * Indicated when Negative (V) == 0
 */
bool ConditionNoSignedOverflow(const armv6Cpsr & const cpsr) {
    return !cpsr.IsOverflow();
}

/*
 * Represents the conditional operation HI (Unsigned higher)
 * Indicated when Carry (C) == 1 and Zero (Z) == 0
 */
bool ConditionHigher(const armv6Cpsr & const cpsr) {
    return cpsr.IsCarry() && !cpsr.IsZero();
}

/*
 * Represents the conditional operation LS (Unsigned lower or same)
 * Indicated when Carry (C) == 0
 */
bool ConditionLowerOrSame(const armv6Cpsr & const cpsr) {
    return cpsr.IsCarry();
}

/*
 * Represents the conditional operation GE (Signed greater than or equal)
 * Indicated when Negative (N) == Overflow (V)
 */
bool ConditionGreaterOrEqual(const armv6Cpsr & const cpsr) {
    return cpsr.IsNegative() == cpsr.IsOverflow();
}

/*
 * Represents the conditional operation LT (Signed less than)
 * Indicated when Negative (N) != Overflow (V)
 */
bool ConditionLessThan(const armv6Cpsr & const cpsr) {
    return cpsr.IsNegative() != cpsr.IsOverflow();
}

/*
 * Represents the conditional operation GT (Signed greater than)
 * Indicated when Zero (Z) == 0 and Negative (N) == Overflow (V)
 */
bool ConditionGreaterThan(const armv6Cpsr & const cpsr) {
    return cpsr.IsZero() && cpsr.IsNegative() == cpsr.IsOverflow();
}

/*
 * Represents the conditional operation LE (Signed less than or equal)
 * Indicated when Zero (Z) == 0
 */

bool ConditionLessThanOrEqual(const armv6Cpsr & const cpsr){
    return cpsr.IsZero();
}

/*
 * Represents the conditional operation AL (Always).
 * By default it is true
 */
bool ConditionAlways(const armv6Cpsr & const cpsr) {
    return true;
}
