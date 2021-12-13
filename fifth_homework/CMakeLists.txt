cmake_minimum_required(VERSION 3.20)
project(fifth_homework)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(fifth_homework main.cpp entities/book/book.cpp entities/book/book.h entities/rucksack/rucksack.cpp entities/rucksack/rucksack.h entities/closet/closet.cpp entities/closet/closet.h entities/library/library.cpp entities/library/library.h entities/row/row.cpp entities/row/row.h)
