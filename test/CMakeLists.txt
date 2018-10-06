cmake_minimum_required(VERSION 3.5)

project(cows_and_bulls_core_test)

file(GLOB SOURCE_FILES *.cpp)

add_subdirectory(third_party/gtest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main)