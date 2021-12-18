project(loglib_tests)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

set(SOURCES
    file_logger.cpp
    stderr_logger.cpp
    stdout_logger.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    loglib
    gtest_main
)
