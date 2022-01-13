#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>

typedef enum{
    BINARY,
    DEFINES,
} OutType;

typedef std::pair<uint32_t, uint32_t> CRC;

CRC bk_crc(const std::vector<uint8_t> &buffer){
    CRC crc = {0, 0xFFFFFFFF};
    for (auto byte : buffer){
        crc.first += byte;
        crc.second ^= (byte << (crc.first & 0x17));
    }
    return crc;
}

/* calculate Banjo-Kazooie CRC and write value to bin OR txt file with gcc defines */
/// -D output as defines
int main(int argc, char *argv[]){
    struct {
        OutType type;
        std::string name;
    } config = {BINARY, ""};

    //parse arguments
    for(int i = 1; i < argc - 1; i++){
        std::string argi = argv[i];
        if(argi == "-D" || argi == "-d") //no loop
            config.type = DEFINES;
            config.name = argv[++i];
            std::transform(config.name.begin(), config.name.end(), config.name.begin(), ::toupper);
    }

    std::string in_bin = argv[argc -1];
    std::ifstream in_f(in_bin, std::ios::in | std::ios::binary | std::ios::ate);
    size_t in_size = in_f.tellg();
    in_f.seekg(0);
    std::vector<uint8_t> in_data;
    in_data.resize(in_size);
    in_f.read(reinterpret_cast<char*>(in_data.data()), in_size);
    
    auto result = bk_crc(in_data);

    switch(config.type){
        case OutType::BINARY:
            std::cout << (char)((result.first >> 24) & 0xff) << (char)((result.first >> 16) & 0xff) << (char)((result.first >> 8) & 0xff) << (char)((result.first >> 0) & 0xff);
            std::cout << (char)((result.second >> 24) & 0xff) << (char)((result.second >> 16) & 0xff) << (char)((result.second >> 8) & 0xff) << (char)((result.second >> 0) & 0xff);
            std::cout << std::flush;
            break;

        case OutType::DEFINES:
            std::cout << "-D'" << config.name << "_CRC1=0x";
            std::cout << std::hex <<std::setfill('0') << std::setw(8) << result.first;
            std::cout << "' ";
            std::cout << "-D'" << config.name << "_CRC2=0x";
            std::cout << std::hex <<std::setfill('0') << std::setw(8) << result.second;
            std::cout << "'";
            std::cout << std::endl;
            break;
    }

    return 0; 
}