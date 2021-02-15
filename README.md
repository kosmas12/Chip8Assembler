# Chip8Assembler
A FOSS assembler for the CHIP-8

# Syntax

Keep in mind, the carry flag is register `VF`.

| Instruction      | Description                                                                                                      | Parameter(s)                          |
| ---------------- | -----------------------------------------------------------------------------------------------------------------| --------------------------------------|
| CLSC             | CLear the SCreen.                                                                                                |                                       |
| RTRN             | ReTuRN from subroutine.                                                                                          |                                       |
| CALM             | CALl Machine code routine at `nnn`.                                                                              | `nnn`                                 |
| JUMP             | JUMP to address `nnn`.                                                                                           | `nnn`                                 |
| CALL             | CALL subroutine at `nnn`.                                                                                        | `nnn`                                 |
| SERB             | Skip next instruction if Register `Vx` is Equal to Byte `kk`.                                                    | `Vx, kk`                              |
| SNRB             | Skip next instruction if Register `Vx` is Not Equal to Byte `kk`.                                                | `Vx, kk`                              |
| SERR             | Skip next instruction if Register `Vx` is Equal to Register `Vy`.                                                | `Vx, Vy`                              |
| LDRB             | LoaD Register `Vx` with Byte `kk`.                                                                               | `Vx, kk`                              |
| ADDB             | ADD Byte `kk` to register `Vx`.                                                                                  | `Vx, kk`                              |
| LDRR             | LoaD Register `Vx` with the value of register `Vy`.                                                              | `Vx, Vy`                              |
| ORRR             | OR on Registers `Vx` and `Vy` and store the result in `Vx`.                                                      | `Vx, Vy`                              |
| ANDR             | AND Registers `Vx` and `Vy` and store the result in `Vx.`                                                        | `Vx, Vy`                              |
| XORR             | eXclusive OR on Register `Vx` and Register `Vy` and store in `Vx`.                                               | `Vx, Vy`                              |
| ADDR             | ADD Register `Vy` to `Vx` and store in `Vx`. If result > 8 bits, set carry.                                      | `Vx, Vy`                              |
| SUBR             | if `Vx > Vy`, set carry. Then SUBtract `Vy` from `Vx` and store in `Vx`.                                         | `Vx, Vy`                              |
| SHRR             | if the least significant bit of `Vx` is 1, set carry. Then half `Vx`.                                            | `Vx, Vy` (`Vy` ignored but necessary) |
| SUBN             | If `Vy` > `Vx`, then VF is set to 1, otherwise 0. Then Vx is subtracted from Vy, and the results stored in Vx.   | `Vx, Vy`                              |
| SHLR             | If the most significant bit of Vx is 1, set carry. Then double `Vx`.                                             | `Vx, Vy` (`Vy` ignored but necessary) |
| SNER             | Skip next instruction if Registers `Vx` and `Vy` are Not Equal.                                                  | `Vx, Vy`                              |
| LDIR             | LoaD Index Register                                                                                              | `nnn`                                 |
| JPRZ             | JumP to address `nnn + V0`                                                                                       | `nnn`                                 |
| RAND             | generate RANDom number in the range of 0-255, AND with `kk` and store in `Vx`.                                   | `Vx, kk`                              |
| DRAW             | DRAW n-byte sprite starting at memory location I at (Vx, Vy). Set carry if there's a collision.                  | `Vx, Vy, n`                           |
| SKIP             | SKIP next instruction if key with value of register `Vx` is pressed.                                              | `Vx`                                  |
| SKNP             | SKIP next instruction if key with value of register `Vx` is not pressed.                                          | `Vx`                                  |
| LDFD             | LoaD From Delay timer to register `Vx`.                                                                           | `Vx`                                  |
| WFKP             | Wait For Key Press and store value of pressed key to register `Vx`.                                               | `Vx`                                  |
| LDTD             | LoaD To Delay timer from `Vx`.                                                                                    | `Vx`                                  |
| LDTS             | LoaD to Sound timer from `Vx`.                                                                                    | `Vx`                                  |
| ADDI             | ADD `Vx` to I.                                                                                                    | `Vx`                                  |
| LDIL             | LoaD to I the Location of the sprite for hex digit `Vx`.                                                          | `Vx`                                  |
| SBCD             | Store BCD representation of `Vx` in memory locations I, I+1 and I+2.                                              | `Vx`                                  |
| SMEM             | Store values of registers `V0` through `Vx` to MEMory starting at the location pointed to by the index register. | `Vx`                                  |
| RMEM             | Read registers V0 through Vx from MEMory starting at the location pointed to by the index register.               | `Vx`                                      |