cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++20")
project(test_algorithms)

set(HEADER FILES
    ../../src/algorithms/search/binary_search.h
    ../../src/algorithms/search/linear_search.h
    ../../src/algorithms/search/recursive_binary_search.h
    ../../src/algorithms/sorting/bubble_sort.h
)
set(SOURCES 
    ../../src/algorithms/search/binary_search.cpp
    ../../src/algorithms/search/linear_search.cpp
    ../../src/algorithms/search/recursive_binary_search.cpp
    ../../src/algorithms/sorting/bubble_sort.cpp
    search_test.cpp 
    sorting_test.cpp
)

find_package(Boost 1.85.0)
if (Boost_FOUND)
    enable_testing()
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(test_algorithms ${SOURCES})
    target_include_directories(test_algorithms PRIVATE ${BOOST_INCLUDE_DIRS})
    add_test(NAME search_test COMMAND search_test)
    add_test(NAME sorting_test COMMAND sorting_test)
endif()

