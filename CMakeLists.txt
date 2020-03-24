cmake_minimum_required(VERSION 3.15)
project(LAB1)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB1 main.cpp Lists/List.cpp Lists/List.h Lists/ArrayList.h Lists/ArrayList.cpp Lists/CircularList.h Lists/CircularList.cpp Library/Book.h Library/Book.cpp Library/Series.h Library/Series.cpp Library/Character.h Library/Character.cpp)