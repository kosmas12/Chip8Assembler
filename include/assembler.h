//
// Created by kosmas on 15/2/21.
//

#ifndef CHIP8ASSEMBLER_ASSEMBLER_H
#define CHIP8ASSEMBLER_ASSEMBLER_H

#include <iostream>

void assembleLine(std::string line, int lineNum, std::string romName);

typedef struct {
    uint16_t machineCode;
    std::string asmInstruction;
    unsigned char firstNibble;
    unsigned char lastNibble;
}Chip8Instruction;

#endif //CHIP8ASSEMBLER_ASSEMBLER_H
