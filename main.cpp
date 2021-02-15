/*
Chip8Assembler - A FOSS assembler for the CHIP-8
Copyright (C) 2021  Kosmas Raptis

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/

#include <iostream>
#include "include/files.h"

int main(int argc, char *argv[]) {
    printf("Welcome to Chip8Assembler!\n");

    if (argc == 1) {
        printf("Give me a file bro, come on!\n");
    }
    else {
        std::ifstream asmFile = openAsmFile(argv[1]);
        if (!asmFile) {
            printf("Couldn't open file %s\n", argv[1]);
        }
        else {
            printf("Succesfully opened %s\n", argv[1]);
            readFile(argv[1]);
        }
    }
    return 0;
}
