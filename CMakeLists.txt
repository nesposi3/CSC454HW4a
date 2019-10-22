cmake_minimum_required(VERSION 3.14)
project(CSC4544a)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSC454HW4a Main.cpp Model.h Pipe.h Port.h Network.h XORModel.cpp XORModel.h MemoryModel.cpp MemoryModel.h)
