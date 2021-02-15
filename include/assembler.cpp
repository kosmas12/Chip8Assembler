//
// Created by kosmas on 15/2/21.
//

#include "assembler.h"
#include "files.h"
#include <iostream>

// Complete list of instructions for the CHIP-8
Chip8Instruction instructions[] = {
        {.machineCode=0x00E0, .asmInstruction="CLSC", .numParams=0},
        {.machineCode=0x00EE, .asmInstruction="RTRN", .numParams=0},
        {.asmInstruction="CALM", .firstNibble=0x0, .numParams=3},
        {.asmInstruction="JUMP", .firstNibble=0x1, .numParams=3},
        {.asmInstruction="CALL", .firstNibble=0x2, .numParams=3},
        {.asmInstruction="SREB", .firstNibble=0x3, .numParams=3},
        {.asmInstruction="SRNB", .firstNibble=0x4, .numParams=3},
        {.asmInstruction="SRER", .firstNibble=0x5, .numParams=3},
        {.asmInstruction="LDRB", .firstNibble=0x6, .numParams=3},
        {.asmInstruction="ADDB", .firstNibble=0x7, .numParams=3},
        {.asmInstruction="LDRR", .firstNibble=0x8, .lastNibble=0x0, .numParams=2},
        {.asmInstruction="ORRR", .firstNibble=0x8, .lastNibble=0x1, .numParams=2},
        {.asmInstruction="ANDR", .firstNibble=0x8, .lastNibble=0x2, .numParams=2},
        {.asmInstruction="XORR", .firstNibble=0x8, .lastNibble=0x3, .numParams=2},
        {.asmInstruction="ADDR", .firstNibble=0x8, .lastNibble=0x4, .numParams=2},
        {.asmInstruction="SUBR", .firstNibble=0x8, .lastNibble=0x4, .numParams=2},
        {.asmInstruction="SHRR", .firstNibble=0x8, .lastNibble=0x6, .numParams=2},
        {.asmInstruction="SUBN", .firstNibble=0x8, .lastNibble=0x7, .numParams=2},
        {.asmInstruction="SHLR", .firstNibble=0x8, .lastNibble=0xE, .numParams=2},
        {.asmInstruction="SNER", .firstNibble=0x9, .lastNibble=0x0, .numParams=2},
        {.asmInstruction="LDIR", .firstNibble=0xA, .numParams=3},
        {.asmInstruction="JPRZ", .firstNibble=0xB, .numParams=3},
        {.asmInstruction="RAND", .firstNibble=0xC, .numParams=3},
        {.asmInstruction="DRAW", .firstNibble=0xD, .numParams=3},
        {.asmInstruction="SKIP", .firstNibble=0xE, .thirdNibble=0x9, .lastNibble=0xE, .numParams=1},
        {.asmInstruction="SKNP", .firstNibble=0xE, .thirdNibble=0xA, .lastNibble=0x1, .numParams=1},
        {.asmInstruction="LDFD", .firstNibble=0xF, .thirdNibble=0x0, .lastNibble=0x7, .numParams=1},
        {.asmInstruction="WFKP", .firstNibble=0xF, .thirdNibble=0x0, .lastNibble=0xA, .numParams=1},
        {.asmInstruction="LDTD", .firstNibble=0xF, .thirdNibble=0x1, .lastNibble=0x5, .numParams=1},
        {.asmInstruction="LDTS", .firstNibble=0xF, .thirdNibble=0x1, .lastNibble=0x8, .numParams=1},
        {.asmInstruction="ADDI", .firstNibble=0xF, .thirdNibble=0x1, .lastNibble=0xE, .numParams=1},
        {.asmInstruction="LDIL", .firstNibble=0xF, .thirdNibble=0x2, .lastNibble=0x9, .numParams=1},
        {.asmInstruction="SBCD", .firstNibble=0xF, .thirdNibble=0x3, .lastNibble=0x3, .numParams=1},
        {.asmInstruction="SMEM", .firstNibble=0xF, .thirdNibble=0x5, .lastNibble=0x5, .numParams=1},
        {.asmInstruction="RMEM", .firstNibble=0xF, .thirdNibble=0x6, .lastNibble=0x5, .numParams=1}

};

uint16_t swap_bytes(uint16_t number) {
    uint16_t result;
    result = (number >> 8) | (number << 8);

    return result;
}

void assembleLine(std::string line, int lineNum, std::string romName) {
    std::string instruction;

    instruction = line.substr(0, 4);

    for (int i = 0; i < sizeof(instructions)/sizeof(Chip8Instruction); i++) {
        if (instructions[i].asmInstruction == instruction) {
            if (instructions[i].asmInstruction == "CLSC" || instructions[i].asmInstruction == "RTRN") {
                writeLnToROM(romName, instructions[i].machineCode);
            }
            break;
        }
        else if(instructions[i].asmInstruction != instruction && i == (sizeof(instructions)/sizeof(Chip8Instruction))-1) {
            printf("Invalid instruction on line %d!\n", lineNum);
        }
    }
}