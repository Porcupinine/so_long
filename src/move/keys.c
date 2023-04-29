//
// Created by laura on 22/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "../../include/graphics.h"
#include "ft_printf.h"

static void checks_after_move(game_map *map, char c) {
    if (c == 'C')
    {
        map->map[map->player->y][map->player->x] = 'C';
        find_collectable(map->collectables, map->player->x, map->player->y)->collectable_img->enabled = false;
        map->collectable_count--;
    }
    map->map[map->player->y][map->player->x] = 'P';
    if (c == 'E' && map->collectable_count == 0)
        exit(0);
}

void move_up(game_map *map)
{
	char c = map->map[map->player->y-1][map->player->x];
    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
        map->map[map->player->y][map->player->x] = '0';
		map->player->player_img->instances[0].y -= 65;
        map->player->y--;

        checks_after_move(map, c);
        puts("up");
		print_map(map);
//        print_map_data(map);
        if (c == 'E' && map->collectable_count == 0)
        {
            exit(0);
        }
//			//TODO quit if E
	}
//	else if (map->map[map->player_y+1][map->player_x] == 'C')
//	{
//		map->player_y = map->player_y++;
//		find_collectable(map->fish, map->player_x, map->player_y)->status = 1;
		// TODO remover nó
//	}
}

void move_left(game_map *map)
{
	char c = map->map[map->player->y][map->player->x-1];
    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player->y][map->player->x] = '0';
        map->player->player_img->instances[0].x -= 65;
        map->player->x--;
        checks_after_move(map, c);
        puts("left");
        print_map(map);
//        print_map_data(map);

//		else if (c == 'E' && map->fish == NULL)
//		{
//			//TODO quit
//		}
	}
}

void move_right(game_map *map)
{
	char c = map->map[map->player->y][map->player->x+1];
    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player->y][map->player->x] = '0';
        map->player->player_img->instances[0].x += 65;
        map->player->x++;

        checks_after_move(map, c);
		puts("right");
        print_map(map);
//        print_map_data(map);

//
//		if (c == 'C')
//			map->map[map->player_y][map->player_x] = '0';
//		else if (c == 'E' && map->fish == NULL)
//		{
//			//TODO quit
//		}
	}
}

void move_down(game_map *map)
{
	char c = map->map[map->player->y+1][map->player->x];
    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->map[map->player->y][map->player->x] = '0';
        map->player->player_img->instances[0].y += 65;
        map->player->y++;

        checks_after_move(map, c);
		puts("down");
        print_map(map);
//        print_map_data(map);

//
//		if (c == 'C')
//			map->map[map->player_y][map->player_x] = '0';
//		else if (c == 'E' && map->fish == NULL)
//		{
//			//TODO quit
//		}
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
	//draw_map((game_map*)param);
}