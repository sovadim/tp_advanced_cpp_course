
add_executable(loglib_tests loglib_test.cpp)

add_test(
    NAME loglib_tests
    COMMAND run_loglib_tests
)

target_include_directories(loglib_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
