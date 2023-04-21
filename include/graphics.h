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
void draw_collectable(mlx_t* mlx, int32_t x, int32_t y);
void draw_ground(mlx_t* mlx, int32_t x, int32_t y);
void draw_wall(mlx_t* mlx, int32_t x, int32_t y);

//-------------------------------------------------------------------draw_map.c

void draw_map(mlx_t* mlx, game_map *map, collectable *fish);

#endif //SO_LONG_GRAPHICS_H
