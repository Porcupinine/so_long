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

#include "../../lib42//include/ft_printf.h"
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

void print_map_data(game_map *map)
{
	int count;
    collectables_data *copy_collectable;

    copy_collectable = map->collectables;
	count = 0;
	ft_printf("Map size: %dX%d\n", map->height, map->width);
	ft_printf("Exit coordinates: (%d, %d)\n", map->exit_x, map->exit_y);
	ft_printf("Player coordinate: (%d, %d)\n", map->player->x, map->player->y);
	ft_printf("Amount of collectables: %d\n", map->collectable_count);
	while (copy_collectable != NULL)
	{
		ft_printf("fish %d: (%d, %d) status: %d\n", count,
                  copy_collectable->x, copy_collectable->y,
                  copy_collectable->collectable_img->enabled);
        copy_collectable = copy_collectable->next;
		count++;
	}
}
