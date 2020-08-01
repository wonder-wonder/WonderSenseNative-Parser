cmake_minimum_required(VERSION 3.13.4)

project(
        parser_lib
        VERSION 1.0.0
        DESCRIPTION "Parser library"
        LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "-O2 -std=c++14 -Wall")

add_library(
        parser
        SHARED

        parser.cpp
)

set_target_properties(
        parser

        PROPERTIES
        VERSION ${PROJECT_VERSION}
)

enable_testing()
add_subdirectory(test)
