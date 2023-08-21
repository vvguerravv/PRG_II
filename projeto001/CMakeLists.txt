cmake_minimum_required(VERSION 3.26)
project(projeto001 C)

set(CMAKE_C_STANDARD 17)

add_executable(projeto001 main.c
        arquivo.c
        arquivo.h)
