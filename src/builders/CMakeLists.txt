set(target_name builders)

set(LIBRARY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/${target_name})

add_library(${target_name} STATIC
    ${LIBRARY_INCLUDE_DIR}/file_list_builder.hpp
    file_list_builder.cpp
)

target_include_directories(${target_name} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

include(CompileOptions)
set_compile_options(${target_name})
