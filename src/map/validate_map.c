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

int check_shape(game_map *map)
{
	size_t y;
	size_t x;

	x = 0;
	y = 0;
	while (y <= map->height)
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
	size_t count_x;
	size_t count_y;

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
	size_t count_x;
	size_t count_y;

	exit = 0;
	count_x = 0;
	count_y = 0;
	while (count_y < map->height)
	{
		while (count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'E')
			{
				if (exit == 1)
					return (ft_printf("ERROR Multiple exits\n"), 1);
				exit = 1;
			}
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	if (exit == 0)
		return (ft_printf("ERROR No exit found\n"), 1);
	return (0);
}

int check_player(game_map *map)
{
	int player;
	size_t count_x;
	size_t count_y;

	player = 0;
	count_x = 0;
	count_y = 0;

	while (count_y < map->height)
	{
		while (count_x < (map->width))
		{
			if (map->map[count_y][count_x] == 'P')
			{
				if (player == 1)
					return (ft_printf("ERROR Multiple players\n"), 1);
				player = 1;
			}
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	if (player == 0)
		return (ft_printf("ERROR No player found\n"), 1);
	return (0);
}

int check_collectables(game_map *map)
{
	int collectables;
	size_t count_x;
	size_t count_y;

	collectables = 0;
	count_x = 0;
	count_y = 0;

	while (count_y < map->height)
	{
		while (count_x < (map->width)) {
			if (map->map[count_y][count_x] == 'C')
				collectables++;
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	if (collectables == 0)
		return (ft_printf("ERROR No collectables\n"), 1);
	return (0);
}
