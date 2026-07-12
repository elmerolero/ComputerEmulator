#pragma once

class armv6Cpsr {
    public:
        void SetCarry(bool carry);
        bool IsCarry(void) const;

        void SetZero(bool zero);
        bool IsZero(void) const;

        void SetNegative(bool negative);
        bool IsNegative(void) const;

        void SetOverflow(bool overflow);
        bool IsOverflow(void) const;

    private:
        bool Carry;
        bool Zero;
        bool Negative;
        bool Overflow;
};
