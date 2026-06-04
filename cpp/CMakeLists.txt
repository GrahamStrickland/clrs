cmake_minimum_required(VERSION 3.24)
project(clrs_test
    VERSION 0.0.1
    DESCRIPTION "Tests for the data structures and algorithms from Introduction to Algorithms - Cormen, Leiserson, Rivest, & Stein"
    HOMEPAGE_URL "https://github/com/GrahamStrickland/clrs"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++26 -pedantic -Wall -Wextra -Werror")

include(CTest)

add_subdirectory(algorithms)
add_subdirectory(data_structures)
add_subdirectory(compruntime)

# Tests
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
