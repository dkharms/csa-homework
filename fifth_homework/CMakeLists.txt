cmake_minimum_required(VERSION 3.20)
project(fifth_homework)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_executable(fifth_homework main.cpp entities/book/book.cpp entities/book/book.h entities/closet/closet.cpp entities/closet/closet.h entities/row/row.cpp entities/row/row.h entities/library/library.cpp entities/library/library.h entities/rucksack/rucksack.cpp entities/rucksack/rucksack.h)
