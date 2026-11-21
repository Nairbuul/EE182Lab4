#ifndef FILEREADER
#define FILEREADER

#include <cstdint>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

std::vector<uint8_t> readFile(const std::string& path);

#endif