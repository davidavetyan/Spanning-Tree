cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME SpanTree)

project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS .)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

include_directories(src/include)

set(HEADERS
    src/core/matrix.h
    src/core/gridgraph.h
    src/core/stgenerator.h
    src/gui/spantree.h
    src/gui/canvaswidget.h
    src/gui/griddrawer.h
)

set(SOURCES
    src/app/main.cpp
    src/core/gridgraph.cpp
    src/core/stgenerator.cpp
    src/gui/spantree.cpp
    src/gui/canvaswidget.cpp
    src/gui/griddrawer.cpp
)

set(QRC
    SpanTree.qrc
)

set(UI
    SpanTree.ui
)

add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES} ${QRC} ${UI})

target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
