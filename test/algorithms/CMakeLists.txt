cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++20 -pedantic -Wall -Wextra -Werror")
project(test_algorithms)

set(HEADER FILES
    ../../src/algorithms/search/binary_search.h
    ../../src/algorithms/search/linear_search.h
    ../../src/algorithms/search/recursive_binary_search.h
)

set(SOURCES 
    test_search.cpp 
)

find_package(Boost 1.87.0 REQUIRED COMPONENTS unit_test_framework)
if (Boost_FOUND)
    enable_testing()

    add_executable(test_search ${SOURCES})
    target_link_libraries(test_search Boost::headers)
    target_compile_definitions(test_search PRIVATE BOOST_ALLOW_DEPRECATED_HEADERS)
    add_test(NAME test_search COMMAND test_search)
endif()

