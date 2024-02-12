cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")
project(test_data_structures)

set(HEADER FILES
    ../../src/data_structures/matrix.h
    ../../src/data_structures/square_matrix.h
)
set(SOURCES 
    ../../src/data_structures/matrix.cpp
    ../../src/data_structures/square_matrix.cpp
    matrix_test.cpp
    square_matrix_test.cpp
)

find_package(Boost 1.84.0)
if (Boost_FOUND)
    enable_testing()
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(test_data_structures ${SOURCES})
    target_include_directories(test_data_structures PRIVATE ${BOOST_INCLUDE_DIRS})
    add_test(NAME matrix_test COMMAND matrix_test)
    add_test(NAME square_matrix_test COMMAND square_matrix_test)
endif()
