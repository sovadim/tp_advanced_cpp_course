cmake_minimum_required(VERSION 3.5)

add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

project(process)

set(SOURCES
    src/process.cpp
    src/pipe.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
