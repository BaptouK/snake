cmake_minimum_required(VERSION 3.30)
project(snake)

set(CMAKE_CXX_STANDARD 26)

add_executable(snake main.cpp
        Snake.cpp
        Snake.h)
