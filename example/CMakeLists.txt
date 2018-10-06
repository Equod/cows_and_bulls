cmake_minimum_required(VERSION 3.5)
project(cows_and_bulls_core_example)

set(CMAKE_CXX_STANDARD 17)

include_directories(${cows_and_bulls_core_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} cows_and_bulls_core)
