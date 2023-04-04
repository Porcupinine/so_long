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
#include "../../lib42/include/get_next_line.h"
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
