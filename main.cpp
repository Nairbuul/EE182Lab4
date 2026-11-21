#include <iostream>
#include "includes/parser.h"
#include "includes/fileReader.h"
#include "includes/decoder.h"

int main(){
    // std::cout << "hello world" << std::endl; 

    bool test_1 = 0;
    bool test_2 = 0;
    bool test_3 = 1;

    // --------------------------------------------------
    // File Reader test
    // --------------------------------------------------

    if(test_1){
        auto buf = readFile("wafer1.stdf");
        std::cout << buf.size() << std::endl;          // expect 1093    
        for(int i = 0; i< buf.size(); i++){
            std::cout << buf[i] << std::endl;
        }  
    }

    // --------------------------------------------------
    // File Reader test
    // --------------------------------------------------
    if(test_2){
        auto buf = readFile("wafer1.stdf");
        size_t pos = 0;
        std::cout << readU2(buf, pos) << std::endl;         // 2 record length
        std::cout << (int)readU1(buf, pos) << std::endl;    // 0 record type
        std::cout << (int)readU1(buf, pos) << std::endl;    // 10 record subtype
        std::cout << pos << std::endl;                      // 4 Position in bytes
    }

    // --------------------------------------------------
    // Parser test.
    // --------------------------------------------------
    if(test_3){
        std::vector<uint8_t> buf = readFile("wafer1.stdf");
        std::vector<PRR> parts = parse(buf);

        std::cout << "\nPart ID\tX\tY\n";
        for (const PRR& p : parts) {
            std::cout << p.partId << "\t" << p.x << "\t" << p.y << "\n";
        }
    }

    return 0;
}