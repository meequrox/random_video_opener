cmake_minimum_required(VERSION 3.5)

project(RandomVideoOpener LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RandomVideoOpener src/main.cpp)

# target_sources(
	# #headers
#
	# #sources
# )

install(TARGETS RandomVideoOpener
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
