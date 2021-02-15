//
// Created by kosmas on 15/2/21.
//

#include "files.h"
#include "assembler.h"

std::ifstream openAsmFile(std::string fname) {
    std::cout << "Opening file: " << fname << std::endl;
    std::ifstream asmFile (fname);
    return asmFile;
}

void writeLnToROM(const std::string& romName, unsigned int data) {

    std::fstream romFile (romName, std::ios::out|std::ios::binary);
    romFile.seekp(0, std::ios::end);

    int n = 1;
    // Host machine is little endian if true
    if(*(char *)&n == 1) {
        // Bit shift instruction because CHIP-8 is big endian
        data = data << 8;
    }

    romFile << std::hex << std::uppercase << data;
    romFile.close();
}

void writeHexDigitToROM(const std::string& romName, unsigned char digit) {

    std::fstream romFile (romName, std::fstream::out|std::fstream::binary);
    romFile.seekp(0, std::ios::end);

    romFile << digit;
    romFile.close();
}

void readFile(std::string fName) {

    std::ifstream fp (fName);

    std::string curLine;
    std::string romName;

    unsigned long dotPlace = fName.length()-4;

    romName = fName.erase(dotPlace, 4);

    romName += ".ch8";

    int curLineNum = 1;
    while (std::getline(fp, curLine))
    {
        assembleLine(curLine, curLineNum, romName);
        curLineNum++;
    }

}