cmake_minimum_required(VERSION 3.5)

add_compile_options(-O3)
set(CMAKE_CXX_STANDARD 20)

project(demo)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/../../include
)

set_target_properties(log PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../build/liblog.so)

target_link_libraries(${PROJECT_NAME} log)
