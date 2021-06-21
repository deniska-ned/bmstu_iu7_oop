cmake_minimum_required(VERSION 3.5)

project(points LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}
        src/point_3d.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        include/points/
        ./src/
        )
