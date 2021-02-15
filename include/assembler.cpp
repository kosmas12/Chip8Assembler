//
// Created by kosmas on 15/2/21.
//

#include "assembler.h"
#include "files.h"
#include <iostream>

Chip8Instruction instructions[] = {
        {.machineCode=0x00E0, .asmInstruction="CLS", .firstNibble=0x0, .lastNibble=0x0},
        {.machineCode=0x00EE, .asmInstruction="RET", .firstNibble=0x0, .lastNibble=0xE},
        {.machineCode=0x0, .asmInstruction="SYS", .firstNibble=0x0},
};

uint16_t swap_bytes(uint16_t number) {
    uint16_t result;
    result = (number >> 8) | (number << 8);

    return result;
}

void assembleLine(std::string line, int lineNum, std::string romName) {
    std::string instruction;

    instruction = line.substr(0, 3);

    for (int i = 0; i < sizeof(instructions)/sizeof(Chip8Instruction); i++) {
        if (instructions[i].asmInstruction == instruction) {
            if (instructions[i].asmInstruction == "CLS" || instructions[i].asmInstruction == "RET") {
                writeLnToROM(romName, instructions[i].machineCode);
                break;
            }
        }
        else if(instructions[i].asmInstruction != instruction && i == (sizeof(instructions)/sizeof(Chip8Instruction))-1) {
            printf("Invalid instruction on line %d!\n", lineNum);
        }
    }
}