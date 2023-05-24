/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphics.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 13:11:07 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/24 09:52:52 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stddef.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include "map.h"

//----------------------------------------------------------------load_images.c
/**
 * draws the exit on the window
 * @param mlx mlx instance
 * @param x coordinate x
 * @param y coordinate y
 */
void	draw_exit(mlx_t *mlx, int32_t x, int32_t y);
/**
 * draws the collectable on the window
 * @param mlx mlx instance
 * @param x coordinate x
 * @param y coordinate y
 */
void	draw_collectable(t_game_map *map, int32_t x, int32_t y);
/**
 * draws the ground on the window
 * @param mlx mlx instance
 * @param x coordinate x
 * @param y coordinate y
 */
void	draw_ground(mlx_t *mlx, int32_t x, int32_t y);
/**
 * draws the walls on the window
 * @param mlx mlx instance
 * @param x coordinate x
 * @param y coordinate y
 */
void	draw_wall(mlx_t *mlx, int32_t x, int32_t y);
/**
 * draws the player on the window
 * @param mlx mlx instance
 * @param x coordinate x
 * @param y coordinate y
 */
void	draw_player(t_game_map *map, int32_t x, int32_t y);
//-------------------------------------------------------------------draw_map.c
/**
 * iterates trough the 2D array with the map and
 * calls necessary drawing function.
 * @param map game map data
 */
void	draw_map(t_game_map *map);

#endif //SO_LONG_GRAPHICS_H
