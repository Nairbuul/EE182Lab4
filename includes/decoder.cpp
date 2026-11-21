#include "decoder.h"

uint8_t readU1(const std::vector<uint8_t>& buf, size_t& pos){
    uint8_t v = buf[pos];
    pos += 1;
    return v;
}
uint16_t readU2(const std::vector<uint8_t>& buf, size_t& pos){
    uint16_t v = buf[pos] | (buf[pos + 1] << 8);
    pos += 2;
    return v;
}
int16_t readI2(const std::vector<uint8_t>& buf, size_t& pos){
    int16_t v = buf[pos] | (buf[pos + 1] << 8);
    pos += 2;
    return v;
}
// Size too large must static cast
uint32_t readU4(const std::vector<uint8_t>& buf, size_t& pos){
    uint32_t v =  static_cast<uint32_t>(buf[pos])
                | (static_cast<uint32_t>(buf[pos + 1]) << 8)
                | (static_cast<uint32_t>(buf[pos + 2]) << 16)
                | (static_cast<uint32_t>(buf[pos + 3]) << 24);
    pos += 4;
    return v;
}
std::string readCn(const std::vector<uint8_t>& buf, size_t& pos){
    uint8_t len = readU1(buf, pos); 
    std::string s; 
    for(int i = 0; i < len; i++){
        s += static_cast<char>(buf[pos + i]);
    }
    pos += len;
    return s;
}