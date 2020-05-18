cmake_minimum_required(VERSION 3.16)

add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang)

add_subdirectory(hw1_processlib)
add_subdirectory(hw2_loglib)
