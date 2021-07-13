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

#ifndef CHIP8ASSEMBLER_ASSEMBLER_H
#define CHIP8ASSEMBLER_ASSEMBLER_H

#include <iostream>

void assembleLine(const std::string& line, int lineNum, const std::string& romName);
void getParams(const std::string& line, int numParams);


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
