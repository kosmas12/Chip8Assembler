cmake_minimum_required(VERSION 3.17)
project(Chip8Assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp include/files.cpp include/assembler.cpp)