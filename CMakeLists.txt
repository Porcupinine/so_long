cmake_minimum_required(VERSION 3.21.0)
project(so_long)

#find_package(GTest REQUIRED)
set(CMAKE_C_STANDARD 90)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

#add_compile_options(-fsanitize=address -fsanitize=leak)
#add_link_options(-fsanitize=address -fsanitize=leak)
add_subdirectory(${CMAKE_SOURCE_DIR}/MLX42)
include_directories(${CMAKE_SOURCE_DIR}/lib42/include)

SET(SOURCES
    src/map/validate_map.c
    include/map.h
    src/map/make_map.c
        src/utils/free_map.c
    src/map/print.c
        src/map/check_path.c src/graphics/draw_map.c lib42/libft_src/ft_error.c
        src/graphics/load_images.c include/graphics.h
        src/map/check_map.c src/move/directions.c src/map/collectable.c
        src/utils/queue_functions.c)

add_executable(so_long main.c ${SOURCES} src/move/move_player.c include/move.h include/utils.h src/utils/queue_functions.c src/graphics/home.c)
set_target_properties(so_long PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(so_long ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42)


add_executable(test_so_long ${SOURCES} test/test_read_map.c test/test_main.c test/test_valid_map.c test/test_map_data.c test/test_fish_status.c)
target_link_libraries(test_so_long ${CMAKE_SOURCE_DIR}/lib42/libft.a mlx42)

set(TEST_SOURCES
    test/test_map.cpp)

#add_executable(tests_map ${SOURCES} ${TEST_SOURCES})
#set_target_properties(tests_map PROPERTIES LINKER_LANGUAGE CXX)
#target_link_libraries(tests_map ${CONAN_LIBS})
