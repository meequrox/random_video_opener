cmake_minimum_required(VERSION 3.5)

project(RandomVideoOpener LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RandomVideoOpener src/main.cpp)

target_sources(RandomVideoOpener PRIVATE
    # .h .hpp
    src/directory.hpp

    # .c .cpp .cc
    src/directory.cpp
)

target_include_directories(RandomVideoOpener PRIVATE "include")

add_compile_definitions("_PDEBUG_=$<CONFIG:Debug>")

set_target_properties(RandomVideoOpener PROPERTIES LINK_FLAGS_RELEASE -s)

install(TARGETS RandomVideoOpener
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
