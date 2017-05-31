cmake_minimum_required(VERSION 3.6)
project(Cell)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinTree.h Utils.h BSTree.h BinHeap.h Heap.h STL/Tuple.h STL/SimpleVector.h)
add_executable(Cell ${SOURCE_FILES})