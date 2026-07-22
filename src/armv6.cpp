#include "../include/armv6.h"

void armv6::ExecuteInstruction(void) {
    // Checks whether condition allows running the function
    auto condition = this -> decoder.GetCondition();
    if(!condition(this -> Cpsr))
        return;
        
    uint32_t rd;
    uint32_t rn;
    uint32_t operand;
    uint32_t updateRegister = false;
        
    bool shift;
    if(shift) operand = 0;
    uint32_t result = op(Registers[rn], operand);
    if(updateRegister) Registers[rd] = result;

    // Update flags after the result is conceived
}

/*
 * 0000 - And Operator Instruction
 * Returns the AND operation of A and B
 */
std::uint32_t armv6::And(std::uint32_t a, std::uint32_t b) {
    return a & b;
}

/*
 * 0001 - EOR (Exclusive Operator) Instruction
 * Returns the EOR operation of A and B
 */
std::uint32_t armv6::Eor(std::uint32_t a, std::uint32_t b) {
    return a ^ b;
}

/*
 * 0010 - SUB (Substract operator) Instruction
 * Returns the difference of A and B
 */
std::uint32_t armv6::Sub(std::uint32_t a, std::uint32_t b) {
    return a - b;
}

/*
 * 0011 - RSB (Reverse substraction operator) Instruction
 * Returns the difference of A and B
 */
std::uint32_t armv6::Rsb(std::uint32_t a, std::uint32_t b) {
    return b - a;
}

/*
 * 0100 - ADD (Addition operator) Instruction
 * Returns the sum of A and B
 */
std::uint32_t armv6::Add(std::uint32_t a, std::uint32_t b) {
    return a + b;
}

/*
 * 0101 - ADC (Addition with carry operator) Instruction
 * Returns the sum of A, B and Carry bit
 */
std::uint32_t armv6::Adc(std::uint32_t a, std::uint32_t b) {
    return a + b + Cpsr.IsCarry();
}

/*
 * 0110 - SBC (Substraction with carry operator) instruction
 * Returns the substraction of A, B and Carry bit
 */
std::uint32_t armv6::Sbc(std::uint32_t a, std::uint32_t b) {
    return a - b - static_cast<uint32_t>(!Cpsr.IsCarry());
}

/*
 * 0111 - RSC (Reverse substraction with carry) instruction
 * Returns the substraction of B and A
 */
std::uint32_t armv6::Rsc(std::uint32_t a, std::uint32_t b) {
    return b - a;
}

/*
 * 1000 - TST (Test operator) instruction
 * Returns the AND operation of A & B
 * This will return a result, but this will be
 * used only to update the flags.
 */
std::uint32_t armv6::Tst(std::uint32_t a, std::uint32_t b) {
    return a & b;
}

/*
 * 1001 - TEQ (Test equiality operator) instruction
 * Returns the EOR operation of A and B
 * This will return a result, but this will be
 * used only to update the flags.
 */
std::uint32_t armv6::Teq(std::uint32_t a, std::uint32_t b) {
    return a ^ b;
}

/*
 * 1010 - CMP (Compare operator) instruction
 * Returns the difference of A and B
 * This will return a result, but this will be
 * used only to update the flags.
 */
std::uint32_t armv6::Cmp(std::uint32_t a, std::uint32_t b) {
    return a - b;
}

/*
 * 1010 - CMP (Compare operator) instruction
 * Returns the difference of A and B
 * This will return a result, but this will be
 * used only to update the flags.
 */
std::uint32_t armv6::Cmn(std::uint32_t a, std::uint32_t b) {
    return a + b;
}

std::uint32_t armv6::Orr(std::uint32_t a, std::uint32_t b) {
    return a | b;
}

std::uint32_t armv6::Mov(std::uint32_t a, std::uint32_t b) {
    return a;
}

std::uint32_t armv6::Bic(std::uint32_t a, std::uint32_t b) {
    return a & (~b);
}

std::uint32_t armv6::Mvn(std::uint32_t a, std::uint32_t b) {
    return ~a;
}
