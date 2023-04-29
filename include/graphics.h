//
// Created by laura on 17/04/23.
//

#ifndef SO_LONG_GRAPHICS_H
#define SO_LONG_GRAPHICS_H

#include <stddef.h>
#include "../../MLX42/include/MLX42/MLX42.h"
#include "map.h"

//----------------------------------------------------------------load_images.c
void draw_exit(mlx_t* mlx, int32_t x, int32_t y);
void draw_collectable(game_map *map, int32_t x, int32_t y);
void draw_ground(mlx_t* mlx, int32_t x, int32_t y);
void draw_wall(mlx_t* mlx, int32_t x, int32_t y);
void draw_player(game_map *map, int32_t x, int32_t y);
//-------------------------------------------------------------------draw_map.c

void draw_map(game_map *map);
void init_player (game_map *map);
void move_player(mlx_key_data_t keydata, void* param);
#endif //SO_LONG_GRAPHICS_H
