project(loglib)

set(SOURCES
    src/logger.cpp
    src/baselogger.cpp
    src/filelogger.cpp
    src/stdoutlogger.cpp
    src/stderrlogger.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tests)
