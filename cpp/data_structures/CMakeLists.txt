set(SOURCES
    matrix.cpp
    square_matrix.cpp
)
add_library(data_structures STATIC ${SOURCES})

target_compile_features(data_structures PUBLIC cxx_std_23)

target_include_directories(data_structures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
