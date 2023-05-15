/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:15:26 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:15:46 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../include/map.h"
#include "../../include/graphics.h"

void	draw_map(t_game_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_ground(map->mlx, x, y);
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				draw_wall(map->mlx, x, y);
			if (map->map[y][x] == 'E')
				draw_exit(map->mlx, x, y);
			if (map->map[y][x] == 'C')
				draw_collectable(map, x, y);
			if (map->map[y][x] == 'P')
				draw_player(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
