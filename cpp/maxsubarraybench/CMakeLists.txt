add_executable(maxsubarraybench main.cpp)

target_compile_features(maxsubarraybench PUBLIC cxx_std_26)

target_link_libraries(maxsubarraybench PUBLIC algorithms)
