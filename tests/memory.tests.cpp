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
        cout << "Expected length (" << length << ") incorrect " << value << ":\tX\n" << endl;
        return;
    }

    cout << "Expected length (" << length << ") correct " << value << ":\tO\n" << endl;
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
                cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") incorrect " << value << ":\tX\n";
                continue;
            }

            cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") correct " << value << ":\tO\n";
        }
    }

    cout << endl;
}

void Memory_ReadsAndWritesHalfAtAddress()
{
    // Test
    cout << "Memory_ReadsAndWritesHalfAtAddress" << endl;

    // Arrange
    const uint32_t address[4] = {0, 2, 4, 7};
    const uint32_t expectedValue[3] = {128, 1024, 65535};
    memory memory(512);

    // Act and Assert
    for(size_t j = 0; j < 4; ++j){
        for(size_t i = 0; i < 3; ++i ) {
            memory.WriteAtAddress(address[j], DataSize::HALF, expectedValue[i]);
            uint32_t value = memory.ReadAtAddress(address[j], DataSize::HALF);

            if(value != expectedValue[i]){
                cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") incorrect " << value << ":\tX\n";
                continue;
            }

            cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") correct " << value << ":\tO\n";
        }
    }

    cout << endl;
}

void Memory_ReadsAndWritesWordAtAddress()
{
    // Test
    cout << "Memory_ReadsAndWritesWordAtAddress" << endl;

    // Arrange
    const uint32_t address[4] = {0, 5, 12, 17};
    const uint32_t expectedValue[3] = {255, 65535, 4294967295};
    memory memory(512);

    // Act and Assert
    for(size_t j = 0; j < 4; ++j){
        for(size_t i = 0; i < 3; ++i ) {
            memory.WriteAtAddress(address[j], DataSize::WORD, expectedValue[i]);
            uint32_t value = memory.ReadAtAddress(address[j], DataSize::WORD);

            if(value != expectedValue[i]){
                cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") incorrect " << value << ":\tX\n";
                continue;
            }

            cout << "Expected at address " << address[j] << " value (" << expectedValue[ i ] << ") correct " << value << ":\tO\n";
        }
    }

    cout << endl;
}
