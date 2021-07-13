/*
  This file is part of Chip8Assembler - a FOSS CHIP-8 assembler in C
  Copyright (C) 2021 Kosmas Raptis

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "files.h"
#include "assembler.h"
#include <cstdio>

std::ifstream openAsmFile(std::string fname) {
    std::cout << "Assembly code file: " << fname << std::endl;
    std::ifstream asmFile (fname);
    return asmFile;
}

void writeLnToROM(const std::string& romName, uint16_t data, int lineNum) {

    FILE *romFile = nullptr;

    if (lineNum == 1) {
        romFile = fopen(romName.c_str(), "wb");
    }
    else {
        romFile = fopen(romName.c_str(), "ab+");
    }

    int n = 1;
    // Host machine is little endian if true
    if(*(char *)&n == 1) {
        // Bit shift instruction because CHIP-8 is big endian
        data = swapBytes(data);
    }

    fwrite(&data, 1, sizeof(data), romFile);
    fclose(romFile);
}

uint16_t swapBytes(uint16_t number) {
    uint16_t result;
    result = (number >> 8) | (number << 8);

    return result;
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

    size_t dotPlace = fName.find_last_of('.');

    romName = fName.erase(dotPlace);

    romName += ".ch8";

    int curLineNum = 1;
    while (std::getline(fp, curLine))
    {
        assembleLine(curLine, curLineNum, romName);
        curLineNum++;
    }
    std::cout << "Succesfully wrote machine code to " << romName << ". Assembly complete!" << std::endl;

}