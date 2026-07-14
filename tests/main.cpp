#include "./memory.tests.cpp"
#include "./decoder.tests.cpp"

int main() {
    Memory_ConstructorAllocatesRightMemoryAmount();
    Memory_ReadsAndWritesByteAtAddress();
    Memory_ReadsAndWritesHalfAtAddress();
    Memory_ReadsAndWritesWordAtAddress();
    Decoder_GetCoditionReturnsAValidFunction();
}