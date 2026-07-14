#include <iostream>
#include "../include/decoder.h"
#include "../include/armv6Cpsr.h"
#include "../src/decoder.cpp"
#include "../src/armv6Cpsr.cpp"
using namespace std;

void Decoder_GetCoditionReturnsAValidFunction()
{
    // Arrange
    decoder decoder;
    armv6Cpsr cpsr;
    auto expected = true;
    cpsr.SetCarry(false);
    cpsr.SetNegative(false);
    cpsr.SetOverflow(false);
    cpsr.SetZero(false);

    // Act
    decoder.SetInstruction(0xe92d4070);
    auto function = decoder.GetCondition();

    // 
    auto value = function(cpsr);
    if(expected != value){
        cout << "Expected value (" << expected << ") incorrect " << value << ":\tX\n" << endl;
    }
    cout << "Expected value (" << expected << ") correct " << value << ":\tO\n" << endl;
}