cmake_minimum_required(VERSION 4.1)
project(lab_five_oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_five_oop main.cpp
        Shape.cpp
        Shape.h
        Circle.cpp
        Circle.h)
