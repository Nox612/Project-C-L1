cmake_minimum_required(VERSION 3.24)
project(Project_C_L1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Project_C_L1
        CDataFrame.c
        Function.c
        Header.h
        Main.c Menu.c)
