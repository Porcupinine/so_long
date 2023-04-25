//
// Created by laura on 22/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "../../include/graphics.h"

void move_up(game_map *map)
{
	char c = map->map[map->player_y-1][map->player_x];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->player_y = map->player_y--;
		map->map[map->player_y-1][map->player_x] = 'P';
		puts("up");
		if (c == 'C')
			map->map[map->player_y][map->player_x] = '0';
		else if (c == 'E' && map->fish == NULL)
		{
			//TODO quit
		}
	}
//		map->player_y = map->player_y++;
//	else if (map->map[map->player_y+1][map->player_x] == 'C')
//	{
//		map->player_y = map->player_y++;
//		find_collectable(map->fish, map->player_x, map->player_y)->status = 1;
		// TODO remover nó
//	}
}

void move_left(game_map *map)
{
	char c = map->map[map->player_y][map->player_x-1];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->player_x = map->player_x--;
		map->map[map->player_y][map->player_x-1] = 'P';
		puts("left");
		if (c == 'C')
			map->map[map->player_y][map->player_x] = '0';
		else if (c == 'E' && map->fish == NULL)
		{
			//TODO quit
		}
	}
}

void move_right(game_map *map)
{
	char c = map->map[map->player_y][map->player_x+1];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->player_x = map->player_x++;
		map->map[map->player_y][map->player_x+1] = 'P';
		puts("right");
		if (c == 'C')
			map->map[map->player_y][map->player_x] = '0';
		else if (c == 'E' && map->fish == NULL)
		{
			//TODO quit
		}
	}
}

void move_down(game_map *map)
{
	char c = map->map[map->player_y+1][map->player_x];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->player_y = map->player_y++;
		map->map[map->player_y+1][map->player_x] = 'P';
		puts("down");
		if (c == 'C')
			map->map[map->player_y][map->player_x] = '0';
		else if (c == 'E' && map->fish == NULL)
		{
			//TODO quit
		}
	}
}

void move_player(mlx_key_data_t keydata, void* param)
{
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up((game_map *)param);
	else if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left((game_map *)param);
	else if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down((game_map *)param);
	else if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right((game_map *)param);
	draw_map((game_map*)param);
}