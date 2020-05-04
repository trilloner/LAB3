cmake_minimum_required(VERSION 3.15)
project(Thread_Queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(Thread_Queue main.cpp Queue.inl Queue.h Node.h TheadQueue.h TheadQueue.inl QueueInterface.h demonstration.cpp Node.inl)