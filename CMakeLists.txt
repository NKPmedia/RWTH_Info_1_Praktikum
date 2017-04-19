cmake_minimum_required(VERSION 3.6)
project(RWTH_Info_1_Praktikum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES "Versuch 0/main.cpp")
add_executable(Versuch0 ${SOURCE_FILES})