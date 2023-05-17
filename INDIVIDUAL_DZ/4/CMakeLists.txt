cmake_minimum_required(VERSION 3.23)
project(4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(4
        Graph.h
        LinkedList.h
        main.cpp
        Queue.h)
