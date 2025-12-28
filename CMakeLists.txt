cmake_minimum_required(VERSION 3.16)
project(CircuitGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Wichtig für Q_OBJECT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(CircuitGUI
    main.cpp
    mainwindow.cpp
    mainwindow.h
    algorithms.cpp
    bipoles.cpp
)

target_link_libraries(CircuitGUI PRIVATE Qt6::Widgets)

