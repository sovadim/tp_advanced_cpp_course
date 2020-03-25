cmake_minimum_required(VERSION 3.5)

add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 20)

project (process)

set(SOURCES
    src/process.cpp
    src/main.cpp
    src/tsv.cpp
    src/pipe.cpp
)

add_executable(process ${SOURCES})

target_include_directories(process
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)