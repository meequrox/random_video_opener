set(target_name random_video_opener)

add_executable(${target_name})

include(CompileOptions)
set_compile_options(${target_name})

target_sources(${target_name} PRIVATE main.cpp)

target_link_libraries(${target_name} PRIVATE
    openers
    builders
)

set_target_properties(${target_name} PROPERTIES
    LINK_FLAGS_RELEASE -s
)
