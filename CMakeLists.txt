cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cmake/common.cmake)

disable_in_source_builds()

# == Project ==
project(ADVANCEDCPP LANGUAGES CXX)

# == C++ lang setup ==
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == Default flags ==
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

# == Static analysis ==
include(cmake/ClangTidy.cmake)

# == Testing ==
include(CTest)

# == Targets ==
add_subdirectory(entrance_task)
add_subdirectory(hw1_processlib)
add_subdirectory(hw2_loglib)
