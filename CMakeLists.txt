cmake_minimum_required(VERSION 3.6)
project(RWTH_Info_1_Praktikum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "Versuch 0/main.cpp")

file(GLOB_RECURSE sources *.cpp *.h)

add_executable(Versuch0 ${sources})