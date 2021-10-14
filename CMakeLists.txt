cmake_minimum_required(VERSION 3.16)
project(asm C)


set(CMAKE_C_STANDARD 99)

#include(cmake/ide.cmake)
#include(cmake/platform.cmake)

add_executable(asm WIN32 main.c foo.c)