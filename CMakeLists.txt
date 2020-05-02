cmake_minimum_required(VERSION 3.15)
project(Thread_Queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(Thread_Queue main.cpp BlockingQueue.inl BlockingQueue.h Time.h Node.cpp Node.h Queue.h Queue.inl)