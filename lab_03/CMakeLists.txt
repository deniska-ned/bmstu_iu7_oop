cmake_minimum_required(VERSION 3.5)

project(lab_03 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(lab_03
        src/main.cpp

        src/base_classes/base_command.h
        src/base_classes/base_manager.h
        src/base_classes/base_visitor.h

        src/commands/commands.h
        src/commands/commands.cpp
        src/commands/facade.h
        src/commands/facade.cpp

        src/drawing/canvas.h
        src/drawing/canvas.cpp
        src/drawing/draw_manager.h
        src/drawing/draw_manager.cpp
        src/drawing/draw_visitor.h
        src/drawing/draw_visitor.cpp
        src/drawing/drawer.h
        src/drawing/drawer.cpp
        src/drawing/drawer_factory.h
        src/drawing/drawer_factory.cpp
        src/drawing/drawer_solution.h
        src/drawing/drawer_solution.cpp

        src/errors/errors.hpp

        src/gui/mainwindow.h
        src/gui/mainwindow.cpp

        src/loading/builders.h
        src/loading/builders.cpp
        src/loading/directors.h
        src/loading/directors.cpp
        src/loading/load_managers.h
        src/loading/load_managers.cpp
        src/loading/loader_creators.h
        src/loading/loader_creators.cpp
        src/loading/loader_solution.h
        src/loading/loader_solution.cpp
        src/loading/loaders.h
        src/loading/loaders.cpp

        src/objects/camera.h
        src/objects/camera.cpp
        src/objects/composite.h
        src/objects/composite.cpp
        src/objects/edge.h
        src/objects/edge.cpp
        src/objects/model.h
        src/objects/model.cpp
        src/objects/model_units.h
        src/objects/model_units.cpp
        src/objects/object.h
        src/objects/point.h
        src/objects/point.cpp

        src/reforming/matrix.h
        src/reforming/matrix_base.h
        src/reforming/reform_manager.h
        src/reforming/reform_manager.cpp
        src/reforming/transform_matrix.h
        src/reforming/transform_matrix.cpp

        src/scene/scene.h
        src/scene/scene.cpp
        src/scene/scene_manager.h
        src/scene/scene_manager.cpp
        )

target_link_libraries(lab_03 PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        )

target_include_directories(lab_03 PUBLIC
        src/
        )
