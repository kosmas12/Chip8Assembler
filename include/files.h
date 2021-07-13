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

#ifndef CHIP8ASSEMBLER_FILES_H
#define CHIP8ASSEMBLER_FILES_H

#include <iostream>
#include <fstream>

std::ifstream openAsmFile(std::string fname);
void writeLnToROM(const std::string& romName, uint16_t data, int lineNum);
uint16_t swapBytes(uint16_t number);
void writeHexDigitToROM(const std::string& romName, unsigned char digit);
void readFile(std::string fName);

#endif //CHIP8ASSEMBLER_FILES_H
