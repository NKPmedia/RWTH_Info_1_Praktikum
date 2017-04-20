cmake_minimum_required(VERSION 3.6)
project(RWTH_Info_1_Praktikum)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE sources *.cpp *.h)

list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/Versuch 0/main.cpp")
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/Versuch1_1/Variablen.cpp")
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/Versuch1_2/Strukturen.cpp")
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/Versuch2_1/fibonacci.cpp")
list(REMOVE_ITEM sources "${CMAKE_CURRENT_SOURCE_DIR}/Versuch2_2/main.cpp")

add_executable(Versuch0 ${sources} "Versuch 0/main.cpp")
add_executable(Versuch1_1 ${sources} "Versuch1_1/Variablen.cpp")
add_executable(Versuch1_2 ${sources} "Versuch1_2/Strukturen.cpp")
add_executable(Versuch2_1 ${sources} "Versuch2_1/fibonacci.cpp")
add_executable(Versuch2_2 ${sources} "Versuch2_2/main.cpp")