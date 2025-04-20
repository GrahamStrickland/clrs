cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++23 -pedantic -Wall -Wextra -Werror")
project(test)

set(HEADER FILES
    ../../src/data_structures/matrix.h
    ../../src/data_structures/square_matrix.h
    ../../src/algorithms/search/binary_search.h
    ../../src/algorithms/search/linear_search.h
    ../../src/algorithms/search/recursive_binary_search.h
)

set(DS_SOURCES 
    ../../src/data_structures/matrix.cpp
    ../../src/data_structures/square_matrix.cpp
    data_structures/test_matrix.cpp
)
set(ALG_SOURCES 
    algorithms/test_search.cpp 
)

find_package(Boost 1.88.0 REQUIRED COMPONENTS unit_test_framework)
if (Boost_FOUND)
    enable_testing()

    add_executable(test_data_structures ${DS_SOURCES})
    target_link_libraries(test_data_structures Boost::headers)
    target_compile_definitions(test_data_structures PRIVATE BOOST_ALLOW_DEPRECATED_HEADERS)
    add_test(NAME test_matrix COMMAND test_matrix)
    add_test(NAME test_square_matrix COMMAND test_square_matrix)

    add_executable(test_algorithms ${ALG_SOURCES})
    target_link_libraries(test_algorithms Boost::headers)
    target_compile_definitions(test_algorithms PRIVATE BOOST_ALLOW_DEPRECATED_HEADERS)
    add_test(NAME test_search COMMAND test_search)
endif()

