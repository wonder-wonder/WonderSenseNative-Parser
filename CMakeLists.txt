cmake_minimum_required(VERSION 3.10)

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

include(cmake/DownloadProject/DownloadProject.cmake)
download_project(
    PROJ googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
enable_testing()
add_subdirectory(test)
