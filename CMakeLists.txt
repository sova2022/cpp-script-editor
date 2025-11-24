cmake_minimum_required(VERSION 3.16)
project(cpp-script-editor LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    src/main.cpp
    src/script_editor.h
    src/script_editor.cpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL "Release")

    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif()

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

