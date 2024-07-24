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
    test_algorithms.cpp
    test_search.cpp 
    test_sorting.cpp
)

find_package(Boost 1.85.0 REQUIRED COMPONENTS unit_test_framework)
if (Boost_FOUND)
    enable_testing()
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_executable(test_algorithms ${SOURCES})
    target_include_directories(test_algorithms PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(test_algorithms ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(NAME test_search COMMAND test_search)
    add_test(NAME test_sorting COMMAND test_sorting)
endif()

