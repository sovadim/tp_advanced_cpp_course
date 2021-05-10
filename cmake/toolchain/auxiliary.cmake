# Auxiliary functions to setup toolchain

function(set_c_compiler compiler_name)
    find_program(c_compiler ${compiler_name})
    if (NOT c_compiler)
        message(FATAL_ERROR "Compiler ${compiler_name} not found")
    endif()
    set(CMAKE_C_COMPILER ${c_compiler} PARENT_SCOPE)
endfunction()

function(set_cxx_compiler compiler_name)
    find_program(cxx_compiler ${compiler_name})
    if (NOT cxx_compiler)
        message(FATAL_ERROR "Compiler ${compiler_name} not found")
    endif()
    set(CMAKE_CXX_COMPILER ${cxx_compiler} PARENT_SCOPE)
endfunction()
