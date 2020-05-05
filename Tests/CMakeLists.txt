cmake_minimum_required(VERSION 3.15)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tests main.cpp catch.hpp)
