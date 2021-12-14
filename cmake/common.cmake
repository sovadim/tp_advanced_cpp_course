
function(disable_in_source_builds)
    if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
        message(FATAL_ERROR "
        FATAL: In-source builds are not allowed.
               You should create a separate directory for build files.
        ")
    endif()
endfunction()
