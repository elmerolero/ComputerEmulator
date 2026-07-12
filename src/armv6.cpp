#include "../include/armv6.h"

void armv6::ExecuteInstruction(void) {
    uint32_t rd;
    uint32_t rn;
    uint32_t operand;
    bool shift;
    if(shift) operand = ;
    Registers[rd] = op(Registers[rn], operand);
}

void And(uint32_t a, uint32_t b) {
    a & b;
}
