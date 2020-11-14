cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# == C++ lang setup ==
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# == Toolchain ==
include(cmake/toolchain/auxiliary.cmake)
set_cxx_compiler(clang++-11)

# == Default flags ==
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Werror -pedantic")

# == Project ==
project(ADVANCEDCPP LANGUAGES CXX)

# == Static analysis ==
include(cmake/ClangTidy.cmake)

# == Targets ==
add_subdirectory(hw1_processlib)
add_subdirectory(hw2_loglib)

# == Testing ==
enable_testing()
