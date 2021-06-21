cmake_minimum_required(VERSION 3.5)

project(lab_01 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(lab_01
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.hpp
        src/mainwindow.ui
        )

add_subdirectory(libs/model)

target_link_libraries(lab_01 PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        model
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        ./src/

        ./libs/model/include
        )
