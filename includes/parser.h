#ifndef PARSER
#define PARSER

#include <cstdint>
#include <string>
#include <vector>

struct PRR{
    int16_t x;
    int16_t y;
    std::string partId;
};

std::string recordName(uint8_t type, uint8_t sub);
std::vector<PRR> parse(const std::vector<uint8_t>& buf);

#endif