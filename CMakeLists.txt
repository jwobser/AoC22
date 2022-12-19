cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_COMPILER clang++)

project(AoC22)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# add_compile_options(/Wall)

add_executable(AoC22d1 1/main.cpp)

add_executable(AoC22d2p1 2/main1.cpp)

add_executable(AoC22d2p2 2/main.cpp)

add_executable(d3p1 3/main.cpp 3/main.hpp)

add_executable(t3 3/tests/test.cpp)

add_executable(d3p2 3/main2.cpp)

add_executable(d4p1 4/main.cpp)
add_executable(d4p2 4/main2.cpp)

add_executable(d15p1 15/main.cpp 15/helpers.cpp 15/helpers.h 15/combine.cpp 15/combine.h)
add_executable(t15 15/tests/gtest.cpp 15/helpers.cpp 15/helpers.h 15/combine.cpp 15/combine.h)
add_executable(e15 15/tests/example.cpp 15/helpers.cpp 15/helpers.h 15/combine.cpp 15/combine.h)

target_link_libraries(t15 GTest::gtest_main)
target_link_libraries(e15 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(t15)
gtest_discover_tests(e15)

enable_testing()

add_test(NAME d3_Unit_tests COMMAND $<TARGET_FILE:t3> -s)