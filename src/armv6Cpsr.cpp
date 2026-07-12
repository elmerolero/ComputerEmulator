#include "../include/armv6Cpsr.h"

void armv6Cpsr::SetCarry(bool carry) {
    this -> Carry = carry;
}

bool armv6Cpsr::IsCarry(void) const {
    return this -> Carry;
}

void armv6Cpsr::SetZero(bool zero) {
    this -> Zero = zero;
}

bool armv6Cpsr::IsZero(void) const {
    return this -> Zero;
}

void armv6Cpsr::SetNegative(bool negative) {
    this -> Negative = negative;
}

bool armv6Cpsr::IsNegative(void) const {
    return this -> Negative;
}

void armv6Cpsr::SetOverflow(bool overflow) {
    this -> Overflow = overflow;
}

bool armv6Cpsr::IsOverflow(void) const {
    return this -> Overflow;
}

