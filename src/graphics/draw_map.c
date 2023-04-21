//
// Created by laura on 17/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "../../include/graphics.h"

void draw_map(mlx_t* mlx, game_map *map, collectable *fish)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				draw_wall(mlx, x, y);
//			if (map->map[y][x] == '0')
//				draw_ground(mlx, x, y);
			if (map->map[y][x] == 'E')
				draw_exit(mlx, x, y);
			if (map->map[y][x] == 'C' && fish->status == 0)
			{
				draw_ground(mlx, x, y);
				draw_collectable(mlx, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
