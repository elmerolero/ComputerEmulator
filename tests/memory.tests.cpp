#include <iostream>
#include "../include/memory.h"
#include "../src/memory.cpp"
using namespace std;

void Memory_ConstructorAllocatesRightMemoryAmount()
{
    // Test
    cout << "Memory_ConstructorAllocatesRightMemoryAmount" << endl;

    // Arrange
    const uint32_t length = 512;
    memory memory(length);

    // Act
    uint32_t value = memory.GetLength();

    // Assert
    if(value != 512){
        cout << "Expected length (" << length << ") incorrect" << value << ": X\n" << endl;
        return;
    }

    cout << "Expected length (" << length << ") correct" << value << ": O\n" << endl;
}

void Memory_ReadsAndWritesByteAtAddress()
{
    // Test
    cout << "Memory_ReadsAndWritesByteAtAddress" << endl;

    // Arrange
    const uint32_t address[4] = {0, 1, 2, 3};
    const uint32_t expectedValue[3] = {1, 64, 255};
    memory memory(512);

    // Act and Assert
    for(size_t j = 0; j < 4; ++j){
        for(size_t i = 0; i < 3; ++i ) {
            memory.WriteAtAddress(address[j], DataSize::BYTE, expectedValue[i]);
            uint32_t value = memory.ReadAtAddress(address[j], DataSize::BYTE);

            if(value != expectedValue[i]){
                cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") incorrect " << value << ": X\n";
                continue;
            }

            cout << "Expected at address " << address[j] << "value (" << expectedValue[ i ] << ") correct " << value << ": O\n";
        }
    }

    cout << endl;
}

void Memory_ReadsAtAddress()
{
    // Test
    cout << "Memory_ConstructorAllocatesRightMemoryAmount" << endl;

    // Arrange
    memory memory(512);

    // Act
    uint32_t length = memory.GetLength();

    // Assert
    if(length != 512){
        cout << "Same length: X" << endl;
        return;
    }
}
