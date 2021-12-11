cmake_minimum_required(VERSION 3.20)
project(fifth_homework)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(fifth_homework main.cpp entities/book/book.cpp entities/book/book.h entities/closet/closet.cpp entities/closet/closet.h entities/row/row.cpp entities/row/row.h entities/library/library.cpp entities/library/library.h entities/record/record.cpp entities/record/record.h entities/rucksack.cpp)
