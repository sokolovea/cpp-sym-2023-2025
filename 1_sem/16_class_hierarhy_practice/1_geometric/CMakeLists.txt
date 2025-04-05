cmake_minimum_required(VERSION 3.16)

project(1_geometric LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(1_geometric main.cpp
    shape.h shape.cpp
    circle.h circle.cpp
    parallelogram.h parallelogram.cpp
    rectangle.h rectangle.cpp
    pryamougolnic.h pryamougolnic.cpp)

include(GNUInstallDirs)
install(TARGETS 1_geometric
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
