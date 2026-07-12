#include "../include/decoder.h"
#include "../include/armv6Cpsr.h"
using namespace std;

void decoder::SetInstruction(uint32_t instruction) {
    this -> Instruction = instruction;
}

void decoder::GetCondition(void) {

}

uint32_t And(uint32_t a, uint32_t b) {
    return a + b;
}

bool ConditionalEq(const armv6Cpsr & const cpsr) {
    return cpsr.IsZero();
}

bool ConditionAlways(const armv6Cpsr & const cpsr) {
    return true;
}


