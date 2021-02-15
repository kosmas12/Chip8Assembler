//
// Created by kosmas on 15/2/21.
//

#ifndef CHIP8ASSEMBLER_FILES_H
#define CHIP8ASSEMBLER_FILES_H

#include <iostream>
#include <fstream>

std::ifstream openAsmFile(std::string fname);
void writeLnToROM(const std::string& romName, unsigned int data);
void writeHexDigitToROM(const std::string& romName, unsigned char digit);
void readFile(std::string fName);

#endif //CHIP8ASSEMBLER_FILES_H
