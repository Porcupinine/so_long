cmake_minimum_required(VERSION 3.23.2)
project(so_long C)

set(CMAKE_C_STANDARD 90)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
add_subdirectory(${CMAKE_SOURCE_DIR}/MLX42)
include_directories(${CMAKE_SOURCE_DIR}/lib42/include)
add_executable(so_long main.c src/map/validate_map.c include/map.h src/map/make_map.c)
target_link_libraries(so_long ${CMAKE_SOURCE_DIR}/lib42/libft.a)


add_executable(test_so_long src/map/validate_map.c include/map.h src/map/make_map.c test/test_read_map.c test/test_main.c)
target_link_libraries(test_so_long ${CMAKE_SOURCE_DIR}/lib42/libft.a)
