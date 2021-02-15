//
// Created by kosmas on 15/2/21.
//

#ifndef CHIP8ASSEMBLER_FILES_H
#define CHIP8ASSEMBLER_FILES_H

#include <iostream>
#include <fstream>

std::ifstream openAsmFile(std::string fname);
void writeLnToROM(const std::string& romName, uint16_t data);
uint16_t swapBytes(uint16_t number);
void writeHexDigitToROM(const std::string& romName, unsigned char digit);
void readFile(std::string fName);

#endif //CHIP8ASSEMBLER_FILES_H
