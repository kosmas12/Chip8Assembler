//
// Created by kosmas on 15/2/21.
//

#ifndef CHIP8ASSEMBLER_ASSEMBLER_H
#define CHIP8ASSEMBLER_ASSEMBLER_H

#include <iostream>

void assembleLine(std::string line, int lineNum, std::string romName);


typedef struct {
    // The machine code property is used if the instruction is always the same.
    uint16_t machineCode;
    std::string asmInstruction;
    unsigned char firstNibble;
    unsigned char secondNibble;
    unsigned char thirdNibble;
    unsigned char lastNibble;
    // 3 in this is 2 parameters with just the 2nd one being 2 digits long, or 1 parameter of 3 digits length
    int numParams;

}Chip8Instruction;

#endif //CHIP8ASSEMBLER_ASSEMBLER_H
