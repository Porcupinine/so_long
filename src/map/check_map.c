/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 17:21:23 by laura         #+#    #+#                 */
/*   Updated: 2023/03/29 17:21:23 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../include/map.h"
#include "libft.h"
#include "../../lib42/include/ft_printf.h"

void check_shape(game_map *map)
{
	int32_t y;
	int32_t x;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
			x++;
		if (x != map->width)
            ft_error("Map is not rectangular\n");
		x = 0;
		y++;
	}
}

void check_borders(game_map *map)
{
	int32_t count_x;
	int32_t count_y;

	count_x = 0;
	count_y = 0;
	while (count_x < (map->width))
	{
		if (map->map[0][count_x] != '1'||
        map->map[map->height-1][count_x] != '1')
            ft_error("Map not surrounded\n");
		count_x++;
	}
	while (count_y < map->height)
	{
		if (map->map[count_y][0] != '1' ||
        map->map[count_y][map->width -1] != '1' )
            ft_error("Map not surrounded\n");
		count_y++;
	}
}

void check_exit(game_map *map)
{
	int exit;
	int32_t count_x;
	int32_t count_y;

	exit = 0;
	count_x = -1;
	count_y = -1;
	while (++count_y < map->height)
	{
		while (++count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'E')
			{
				map->exit_x = count_x;
				map->exit_y = count_y;
				exit++;
			}
		}
		count_x = 0;
	}
	if (exit == 0 || exit > 1)
        ft_error("Wrong amount of exits\n");
}

void check_player(game_map *map)
{
	int player_count;
	int32_t count_x;
	int32_t count_y;

    map->player = malloc(1 * sizeof (player_data));
    if(map->player == NULL)
        ft_error("player malloc fail\n");
    player_count = 0;
	count_x = -1;
	count_y = -1;
	while (++count_y < map->height)
	{
		while (++count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'P')
			{
                player_count++;
				map->player->x = count_x;
				map->player->y = count_y;
			}
		}
		count_x = 0;
	}
	if (player_count == 0 || player_count > 1)
        ft_error("Wrong amount of players\n");
}

void check_collectables(game_map *map)
{
	int32_t count_x;
	int32_t count_y;

	count_x = 0;
	count_y = 0;
	while (count_y < map->height)
	{
		while (count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'C')
			{
                if (check_valid_list(map->valid_coordinates, count_x, count_y) == 1)
                    ft_error("no path\n");
                add_collectable(&map->collectables, count_x, count_y);
				map->collectable_count++;
			}
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	if (map->collectable_count == 0)
        ft_error("Missing collectables\n");
}
