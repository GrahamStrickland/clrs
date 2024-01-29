cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

project(test_data_structures)
enable_testing()

set(BOOST_INCLUDE_DIRS /usr/local/boost_1_82_0)

set(HEADER FILES
    ../../src/data_structures/matrix.h
)

set(SOURCES 
    ../../src/data_structures/matrix.cpp
    matrix_test.cpp
)

add_executable(matrix_test ${SOURCES})

target_include_directories(matrix_test PRIVATE ${BOOST_INCLUDE_DIRS})

add_test(NAME test_constructors COMMAND matrix_test)
