cmake_minimum_required(VERSION 3.5)

add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

project(echo-server)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/../../processlib/include
)

add_library(process SHARED IMPORTED)
set_target_properties(process PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../processlib/build/libprocess.so)

target_link_libraries(${PROJECT_NAME} process)
