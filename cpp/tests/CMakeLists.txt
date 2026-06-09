find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if (Boost_FOUND)
    enable_testing()

    add_executable(test_matrix data_structures/test_matrix.cpp)
    target_link_libraries(test_matrix data_structures ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    add_executable(test_algorithms algorithms/test_algorithms.cpp)
    target_link_libraries(test_algorithms algorithms ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    add_test(NAME data_structures.all COMMAND test_matrix --catch_system_error=yes)
    add_test(NAME algorithms.all COMMAND test_algorithms --catch_system_error=yes)
endif()
