cmake_minimum_required(VERSION 3.10)

# project name: test
project(
  parser_test CXX
  )

find_package(GTest REQUIRED)
include(GoogleTest)

set(CMAKE_C_FLAGS_RELEASE "-std=c++14 -Wall -Wextra -O2")
set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/build)
add_executable(Test_app
  ./test_impl.cpp
  )

target_link_libraries(Test_app
  parser
  GTest::GTest
  GTest::Main
  )

include_directories(${PROJECT_SOURCE_DIR}/src
  ${GTEEST_INCLUDE_DIRS}
  )

gtest_add_tests(TARGET
  Test_app
  )
