cmake_minimum_required(VERSION 3.21)
project(hash_table C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")

add_executable(hash_table main.c)