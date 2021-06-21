cmake_minimum_required(VERSION 3.0)

project(f_list)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(PUBLIC
    include/
    )

include_directories(PRIVATE
    src/
    )

### GTEST

add_executable(unit_gtests
    test/gtest_member_methods.cpp
    test/gtest_iterators.cpp
    test/gtest_member_methods.cpp
    test/gtest_modifiers.cpp
    test/gtest_overloaded_operators.cpp
    test/gtest_state.cpp
    test/gtest_operations.cpp
    )

add_subdirectory(libs/googletest)

target_link_libraries(unit_gtests gtest gtest_main)
