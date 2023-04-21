/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 10:25:02 by laura         #+#    #+#                 */
/*   Updated: 2023/03/31 10:25:02 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../../lib42//include/ft_printf.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"

void print_map(game_map *map)
{
	int y;

	y = 0;
	ft_printf("(%d, %d)\n", map->width, map->height);
	while (y < map->height)
	{
		ft_printf("%s", map->map[y]);
		y++;
	}
	ft_printf("\n\n");
}

void print_map_data(game_map *map, collectable *fish)
{
	int count;

	count = 0;
	ft_printf("Map size: %dX%d\n", map->height, map->width);
	ft_printf("Exit coordinates: (%d, %d)\n", map->exit_x, map->exit_y);
	ft_printf("Player coordinate: (%d, %d)\n", map->player_x, map->player_y);
	ft_printf("Amount of collectables: %d\n", map->collectables);
	while (fish != NULL)
	{
		ft_printf("fish %d: (%d, %d) status: %d\n", count, fish->x, fish->y, fish->status);
		fish = fish->next;
		count++;
	}
}
