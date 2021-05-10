cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Disable in-source builds to prevent source tree corruption.
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

# == C++ lang setup ==
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# == Default flags ==
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

# == Project ==
project(ADVANCEDCPP LANGUAGES CXX)

# == Static analysis ==
include(cmake/ClangTidy.cmake)

# == Targets ==
add_subdirectory(entrance_task)
add_subdirectory(hw1_processlib)
add_subdirectory(hw2_loglib)

# == Testing ==
enable_testing()
