cmake_minimum_required(VERSION 3.5)

add_subdirectory(core)
add_subdirectory(test)
add_subdirectory(example)

enable_testing()
add_test (NAME cows_and_bulls_core_test COMMAND cows_and_bulls_core_test)
