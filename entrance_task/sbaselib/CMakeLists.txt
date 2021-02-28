project(sbaselib)

set(SOURCES
    src/stringbase.cpp
    src/stringhelper.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
