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

// some can be void and check value on the struct latter

int check_shape(game_map *map)
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
			return (ft_printf("MAP ERROR not rectangular\n"), 1);
		x = 0;
		y++;
	}
	return (0);
}

int check_borders(game_map *map)
{
	int32_t count_x;
	int32_t count_y;

	count_x = 0;
	count_y = 0;
	while (count_x < (map->width))
	{
		if (map->map[0][count_x] != '1'|| map->map[map->height-1][count_x] != '1')
			return (ft_printf("ERROR Not surrounded\n"), 1);
		count_x++;
	}
	while (count_y < map->height)
	{
		if (map->map[count_y][0] != '1' || map->map[count_y][map->width -1] != '1' )
			return (ft_printf("ERROR Not surrounded\n"), 1);
		count_y++;
	}
	return (0);
}

int check_exit(game_map *map)
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
		return (ft_printf("ERROR Wrong amount of exits\n"), 1);
	return (0);
}

int check_player(game_map *map)
{
	int player;
	int32_t count_x;
	int32_t count_y;

	player = 0;
	count_x = -1;
	count_y = -1;
	while (++count_y < map->height)
	{
		while (++count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'P')
			{
				player++;
				map->player_x = count_x;
				map->player_y = count_y;
			}
		}
		count_x = 0;
	}
	if (player == 0 || player > 1)
		return (ft_printf("ERROR wrong amount of players\n"), 1);
	return (0);
}

int check_collectables(game_map *map, collectable **fish)
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
				add_collectable(fish, count_x, count_y);
				map->collectables++;
			}
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	if (map->collectables == 0)
		return (ft_printf("ERROR No collectables\n"), 1);
	return (0);
}
