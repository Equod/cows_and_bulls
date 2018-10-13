cmake_minimum_required(VERSION 3.5)

project(cows_and_bulls_core)

file(GLOB SOURCE_FILES src/*.cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_custom_target(
        generate_numbers_dat
        COMMAND python generate_numbers.py
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)

add_dependencies(${PROJECT_NAME} generate_numbers_dat)