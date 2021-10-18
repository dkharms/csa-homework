cmake_minimum_required(VERSION 3.20)
project(second_homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(second_homework main.cpp container.cpp container.h shapes/tetrahedron.cpp shapes/tetrahedron.h shapes/sphere.cpp shapes/sphere.h shapes/shape.cpp shapes/shape.h shapes/parallelepiped.cpp shapes/parallelepiped.h)
