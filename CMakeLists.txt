cmake_minimum_required(VERSION 3.24)
project(AoC22)
set(CMAKE_CXX_STANDARD 20)
# add_compile_options(/Wall)

add_executable(AoC22d1 1/main.cpp)

add_executable(AoC22d2p1 2/main1.cpp)

add_executable(AoC22d2p2 2/main.cpp)

add_executable(d3p1 3/main.cpp 3/main.hpp)

add_executable(t3 3/tests/test.cpp)

add_executable(d3p2 3/main2.cpp)

add_executable(d4p1 4/main.cpp)

enable_testing()

add_test(NAME d3_Unit_tests COMMAND $<TARGET_FILE:t3> -s)