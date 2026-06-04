add_executable(compruntime main.cpp)

target_compile_features(compruntime PUBLIC cxx_std_26)

target_link_libraries(compruntime PUBLIC algorithms)
