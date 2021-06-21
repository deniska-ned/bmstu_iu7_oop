cmake_minimum_required(VERSION 3.5)

project(lab_04 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(lab_04
        src/main.cpp

        src/cabin.cpp
        src/cabin.h
        src/control_panel.cpp
        src/control_panel.h
        src/direction.h
        src/doors.cpp
        src/doors.h
        src/files.txt
        src/lift.cpp
        src/lift.h
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        )

target_link_libraries(lab_04 PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        )

target_include_directories(lab_04 PUBLIC
        src/
        )
