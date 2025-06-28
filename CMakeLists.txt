cmake_minimum_required(VERSION 3.10)
project(math_library)

add_library(math STATIC src/math.cpp)
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
