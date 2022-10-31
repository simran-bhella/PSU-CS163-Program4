cmake_minimum_required(VERSION 3.16)
project(program4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(program4
        main.cpp
        tree.cpp
        tree.h)
