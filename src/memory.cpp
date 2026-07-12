#include "../include/memory.h"
#include <stdexcept>
#include <iostream>
using namespace std;

/**
 * Constructor
 */
memory::memory(size_t size) {
    if(size <= 0) {
        this -> Data = nullptr;
        this -> Length = size;
        return;
    }

    uint32_t length = (size / sizeof(uint32_t)) + (size % sizeof(uint32_t) > 0 ? 1 : 0);
    this -> Data = new uint32_t[length];
    this -> Length = size;
}

/**
 * Gets memory's size
 */
size_t memory::GetLength() {
    return this -> Length;
}

/**
 * Writes an address in memory
 */
void memory::WriteAtAddress(const uint32_t address, DataSize dataSize, uint32_t value)
{
    // Is address in range?
    size_t bytes = dataSize == DataSize::BYTE ? 1 : dataSize == DataSize::HALF ? 2 : 4;
    if(address >= Length || bytes > Length - address) throw out_of_range("MEMORY.ACCESS_OUT_OF_BOUNDS");

    // Is data aligned
    if((address & 3) == 0 && dataSize == DataSize::WORD) {
        size_t index = address >> 2;
        this -> Data[index] = value;
    }

    // Pointer to read data as a byte array
    uint8_t* data = reinterpret_cast<uint8_t*>(this -> Data);
    data[address] = static_cast<uint8_t>(value & 0xFF);
    if(dataSize == DataSize::WORD || dataSize == DataSize::HALF) {
        data[address + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
    }

    if(dataSize == DataSize::WORD) {
        data[address + 2] = static_cast<uint8_t>((value >> 16) & 0xFF);
        data[address + 3] = static_cast<uint8_t>((value >> 24) & 0xFF);
    }
}

/**
 * Reads an address in memory
 */
uint32_t memory::ReadAtAddress(const uint32_t address, DataSize dataSize)
{
    // Is address in range?
    size_t bytes = dataSize == DataSize::BYTE ? 1 : dataSize == DataSize::HALF ? 2 : 4;
    if(address >= Length || bytes > Length - address) throw out_of_range("MEMORY.ACCESS_OUT_OF_BOUNDS");

    // Is data aligned
    if((address & 3) == 0 && dataSize == DataSize::WORD) {
        size_t index = address >> 2;
        return this -> Data[index];
    }

    // Pointer to read data as a byte array
    uint8_t* data = reinterpret_cast<uint8_t*>(this -> Data);
    uint32_t value = data[address];
    if(dataSize == DataSize::WORD || dataSize == DataSize::HALF) {
        value = value | static_cast<uint32_t>(data[address + 1]) << 8;
    }

    if(dataSize == DataSize::WORD) {
        value = value | static_cast<uint32_t>(data[address + 2]) << 16;
        value = value | static_cast<uint32_t>(data[address + 3]) << 24;
    }

    return value;
}

memory::~memory() {
    if(this -> Data != nullptr)
        delete Data;
    
    this -> Data = nullptr;
    this -> Length = 0;
}
