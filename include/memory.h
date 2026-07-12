#pragma once
#include <cstdint>

enum class DataSize{
    WORD = 0,
    HALF,
    BYTE
};


class memory {
    public:
        memory(std::size_t size);
        ~memory();
        
        std::size_t GetLength();
        std::uint32_t ReadAtAddress(const std::uint32_t addresss, DataSize dataSize);
        void WriteAtAddress(const std::uint32_t address, DataSize dataSize, std::uint32_t value);

    private:
        std::size_t Length;
        std::uint32_t* Data;
};
