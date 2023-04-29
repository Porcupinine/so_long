//
// Created by laura on 17/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "../../include/graphics.h"

//void init_player (game_map *map)
//{
////    draw_ground(map->mlx, map->player->x, map->player->y);
//    draw_player(map, map->player->x, map->player->y);
//}

void draw_map(game_map *map)
{
	int x;
	int y;

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
