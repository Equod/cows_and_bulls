cmake_minimum_required(VERSION 3.12)

project(cows_and_bulls_core)

file(GLOB SOURCE_FILES src/*.cpp)

include_directories(include)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

add_custom_target(
        create_numbers_dat
        COMMAND python create_numbers.py
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

add_dependencies(${PROJECT_NAME} create_numbers_dat)