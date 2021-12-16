project(demo)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/../../include
)

set_target_properties(loglib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../build/liblog.so)

target_link_libraries(${PROJECT_NAME} loglib)
