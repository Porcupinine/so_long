//
// Created by laura on 22/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "ft_printf.h"

static void checks_after_move(game_map *map, char c)
{
    if (c == 'C')
    {
        map->map[map->player->y][map->player->x] = 'C';
        if (find_collectable(map->collectables, map->player->x,
                             map->player->y)->collectable_img->enabled == true)
            map->collected++;
        find_collectable(map->collectables, map->player->x,
                         map->player->y)->collectable_img->enabled = false;
    }
    if (c == 'E' && map->collectable_count == map->collected)
            exit(0);
    map->moves++;
    ft_printf("Movements: %d\n", map->moves);
    ft_printf("cloctaveis %d/%d\n", map->collected, map->collectable_count);
//    print_map_data(map);
}

void move_up(game_map *map)
{
	char c = map->map[map->player->y-1][map->player->x];
//    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->player->player_img->instances[0].y -= 65;
        map->player->y--;
        checks_after_move(map, c);
//        puts("up");
	}
}

void move_left(game_map *map)
{
	char c = map->map[map->player->y][map->player->x-1];
//    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
        map->player->player_img->instances[0].x -= 65;
        map->player->x--;
        checks_after_move(map, c);
//        puts("left");
	}
}

void move_right(game_map *map)
{
	char c = map->map[map->player->y][map->player->x+1];
//    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
        map->player->player_img->instances[0].x += 65;
        map->player->x++;
        checks_after_move(map, c);
//		puts("right");
	}
}

void move_down(game_map *map)
{
	char c = map->map[map->player->y+1][map->player->x];
//    ft_printf("%c\n", c);
	if (c == '0' || c == 'C' || c == 'E')
	{
        map->player->player_img->instances[0].y += 65;
        map->player->y++;
        checks_after_move(map, c);
//		puts("down");
	}
}
