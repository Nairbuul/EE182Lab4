#include "parser.h"
#include "decoder.h"
#include <iostream>


//FAR: File Attributes Record
//ATR: Audit Trail Records
std::string recordName(uint8_t type, uint8_t sub){
    switch(type){
        case 0:   // file info
            if (sub == 10) return "FAR";
            if (sub == 20) return "ATR";
            break;
        case 1:   // per lot
            if (sub == 10) return "MIR";
            if (sub == 20) return "MRR";
            if (sub == 30) return "PCR";
            if (sub == 40) return "HBR";
            if (sub == 50) return "SBR";
            if (sub == 60) return "PMR";
            if (sub == 62) return "PGR";
            if (sub == 63) return "PLR";
            if (sub == 70) return "RDR";
            if (sub == 80) return "SDR";
            break;
        case 2:   // per wafer
            if (sub == 10) return "WIR";
            if (sub == 20) return "WRR";
            if (sub == 30) return "WCR";
            break;
        case 5:   // per part
            if (sub == 10) return "PIR";
            if (sub == 20) return "PRR";
            break;
        case 10:  // per test
            if (sub == 30) return "TSR";
            break;
        case 15:  // per test execution
            if (sub == 10) return "PTR";
            if (sub == 15) return "MPR";
            if (sub == 20) return "FTR";
            break;
        case 20:  // per program segment
            if (sub == 10) return "BPS";
            if (sub == 20) return "EPS";
            break;
        case 50:  // generic
            if (sub == 10) return "GDR";
            if (sub == 30) return "DTR";
            break;
    }

    return "UNKNOWN";
}
std::vector<PRR> parse(const std::vector<uint8_t>& buf){    
    std::vector<PRR> parts;
    size_t pos = 0;

    while (pos + 4 <= buf.size()) {
        // Header (Table 1)
        uint16_t recLen = readU2(buf, pos);
        uint8_t  recTyp = readU1(buf, pos);
        uint8_t  recSub = readU1(buf, pos);

        size_t recordStart = pos;   // first byte of this record's data

        // Task 3: print header info
        std::cout << "REC_LEN: " << recLen
                  << "  REC_TYP: " << static_cast<int>(recTyp)
                  << "  REC_SUB: " << static_cast<int>(recSub)
                  << "  Type: "    << recordName(recTyp, recSub) << "\n";

        // Task 4: decode PRR (Table 4 field order)
        if (recTyp == 5 && recSub == 20) {
            readU1(buf, pos);   // HEAD_NUM
            readU1(buf, pos);   // SITE_NUM
            readU1(buf, pos);   // PART_FLG (B*1)
            readU2(buf, pos);   // NUM_TEST
            readU2(buf, pos);   // HARD_BIN
            readU2(buf, pos);   // SOFT_BIN

            PRR p;
            p.x = readI2(buf, pos);   // X_COORD
            p.y = readI2(buf, pos);   // Y_COORD
            readU4(buf, pos);         // TEST_T
            p.partId = readCn(buf, pos);   // PART_ID

            parts.push_back(p);
        }

        pos = recordStart + recLen;   // jump to next header
    }

    return parts;

}
