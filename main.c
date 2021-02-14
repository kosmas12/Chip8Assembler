#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openAsmFile(char *fname) {
    printf("Opening file: %s\n", fname);
    FILE *asmFile = fopen(fname, "r");
    if (!asmFile) {
        printf("Couldn't open file %s\n", fname);
    }
    return asmFile;
}

typedef struct {
    unsigned int machineCode;
    char *asmInstruction;
}Chip8Instruction;

Chip8Instruction instructions[] = {
        {.machineCode=0x00E0, .asmInstruction="CLS"}
};

void writeToFile(const char *fname, unsigned int data) {
    char *romName = fname;
    romName = strcat(romName, ".ch8");
    FILE *romFile = fopen(romName, "wb+");
    fseek(romFile, 0, SEEK_END);
    // Bit shift instruction
    data = data << 8;
    fwrite(&data, sizeof(data), 1, romFile);
    fclose(romFile);
}

void assembleLine(const char *line, int lineNum, const char *romName) {
    char first3[3];

    for (int i = 0; i < 3; i++) {
        first3[i] = line[i];
    }

    for (int i = 0; i < sizeof(instructions)/sizeof(Chip8Instruction); i++) {
        if (strcmp(instructions[i].asmInstruction, first3) == 0) {
            writeToFile(romName, instructions[i].machineCode);
        }
        else if(strcmp(instructions[i].asmInstruction, first3) != 0 && i == (sizeof(instructions)/sizeof(Chip8Instruction))-1) {
            printf("Invalid instruction on line %d!\n", lineNum);
        }
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome to CHIP8Assembler!\n");

    if (argc == 1) {
        printf("Give me a file bro, come on!\n");
    }
    else {
        FILE *asmFile = openAsmFile(argv[1]);
        char *curLine;
        size_t maxLineLen = 32;
        char *fName = (char *) malloc(40 * sizeof(char));

        for (int i = 0; argv[1][i] != '.'; ++i) {
            fName[i] = argv[1][i];
        }
        char *romName = strchr(argv[1], '.');

        int curLineNum = 1;
        while (getline(&curLine, &maxLineLen, asmFile) != -1) {
            assembleLine(curLine, curLineNum, fName);
            curLineNum++;
        }
    }

    return 0;
}
