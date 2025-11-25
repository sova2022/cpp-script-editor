cmake_minimum_required(VERSION 3.16)
project(cpp-script-editor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

add_compile_options(/W4 /WX)

find_package(Qt5
    COMPONENTS
        Core
        Gui
        Widgets        
        Network
)

set(PROJECT_SOURCES
    src/main.cpp
    src/ui.h
    src/ui.cpp
    src/script_editor.h
    src/script_editor.cpp
    src/udp_file_server.h
    src/udp_file_server.cpp
    resources/resources.rc
    resources/resources.qrc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

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
        Qt::Network
)

set(SCRIPTS_DIR "${CMAKE_SOURCE_DIR}/scripts")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${PROJECT_NAME}>/scripts"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${SCRIPTS_DIR}"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/scripts"
)