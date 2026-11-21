#include "fileReader.h"


std::vector<uint8_t> readFile(const std::string& path){
    // Opens files and reads.
    // std::ios::ate starts the read position at the end so tellg() gives the size.
    std::ifstream in(path, std::ios::binary | std::ios::ate);
    if (!in) {
        throw std::runtime_error("Could not open file: " + path);
    }

    // Tells us the size of the file. 
    std::streamsize size = in.tellg(); 

    // Moves to the read position byte 0
    // Similar to fseek(f, 0 seek_set)
    in.seekg(0);

    // Buffer
    std::vector<uint8_t> buffer(size);

    // Reading and storing in buffer
    in.read(reinterpret_cast<char*>(buffer.data()), size);

    return buffer;
}
