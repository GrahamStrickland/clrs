set(SOURCES
    big_oh.cpp
    binary.cpp
    max_subarray.cpp
    polynomials.cpp
    search.cpp
    sorting.cpp
)

add_library(algorithms STATIC ${SOURCES})

target_compile_features(algorithms PUBLIC cxx_std_26)

target_include_directories(algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
