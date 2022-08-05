cmake_minimum_required(VERSION 3.22)
project(VMEDA)

set(CMAKE_CXX_STANDARD 23)

add_executable(VMEDA main.cpp VMEDA/Vmedalib.cpp VMEDA/Vmedalib.h)
