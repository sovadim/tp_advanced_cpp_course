project(echo-server)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/../../include
)

add_library(process SHARED IMPORTED)
set_target_properties(process PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../processlib/build/libprocess.so)

target_link_libraries(${PROJECT_NAME} processlib)
