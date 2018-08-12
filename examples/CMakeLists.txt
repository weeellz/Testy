cmake_minimum_required(VERSION 2.8)
project(examples)
set(CMAKE_C_STANDART 11)
include_directories(../include)

add_executable(main main.c)
target_link_libraries(main testy)

add_executable(benchmark benchmark.c)
target_link_libraries(benchmark testy)