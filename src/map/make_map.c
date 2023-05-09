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

static void map_x_size(game_map *map)
{
	char *line;
	int count;

	count = 0;
	while (map->map[0][count] != '\n')
		count++;
	map->width = count;
}

static void map_y_size(char *argv, game_map *map)
{
	int count;
	char *line;
	int fd;

	count = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = count;
	close(fd);
}

void get_map(char *argv, game_map *map)
{
	int fd;
	int count;
	char *line;

	count = 0;
	map_y_size(argv, map);
	map->map = malloc(map->height * sizeof(char *));
	if (map->map == NULL)
        ft_error("Malloc fail\n");
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[count] = line;
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	map_x_size(map);
    map->moves = 0;
    map->collected = 0;
}