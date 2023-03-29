cmake_minimum_required(VERSION 3.24)
project(so_long C)

set(CMAKE_C_STANDARD 90)

add_executable(so_long main.c src/map/validate_map.c)
