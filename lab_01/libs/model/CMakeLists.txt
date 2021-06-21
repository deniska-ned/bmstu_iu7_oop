cmake_minimum_required(VERSION 3.5)

project(model LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_subdirectory(libs/points)

add_library(${PROJECT_NAME}
        src/model/model.cpp
        src/model/model_nodes.cpp
        src/model/model_edge.cpp
        src/model/model_edges.cpp
        src/model_wrapper/qt_model_proxy.cpp
        src/model_wrapper/qt_model_drawer.cpp
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        points)

target_include_directories(${PROJECT_NAME} PUBLIC
        ./include/model/

        ./src/model/
        ./src/model_wrapper/

        ./libs/points/include/
        )
