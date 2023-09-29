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

set_target_properties(RandomVideoOpener PROPERTIES LINK_FLAGS_RELEASE -s)
