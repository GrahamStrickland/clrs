cmake_minimum_required(VERSION 3.16)

find_package(Boost1.82.0 COMPONENTS unit_test_framework REQUIRED)

add_excecutable(data_structures/test_matrix data_structures/test_matrix.cpp)

target_link_libraries(data_structures/test_matrix 
    PRIVATE
    Boost::unit_test_framework
)

