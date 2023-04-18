cmake_minimum_required(VERSION 3.0.0)
project(levenshtein VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Levenshtein STATIC levenshtein.h levenshtein.cpp)
set_property(TARGET Levenshtein PROPERTY CXX_STANDARD 20)

add_subdirectory(tests)
