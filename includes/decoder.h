#ifndef DECODER
#define DECODER

#include <cstdint>
#include <string>
#include <vector>

uint8_t     readU1(const std::vector<uint8_t>& buf, size_t& pos);
uint16_t    readU2(const std::vector<uint8_t>& buf, size_t& pos);
int16_t     readI2(const std::vector<uint8_t>& buf, size_t& pos);
uint32_t    readU4(const std::vector<uint8_t>& buf, size_t& pos);
std::string readCn(const std::vector<uint8_t>& buf, size_t& pos);

#endif