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
#include <fcntl.h>
#include <unistd.h>
#include "../../lib42/include/get_next_line.h"
#include "../../lib42//include/ft_printf.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"

/* ************************************************************************** */
static int map_x_size(int fd)
{
	char *line;
	int count;

	count = 0;
	line = get_next_line(fd);
	while (line[count] != '\0')
		count++;
	free(line);
	return count;
}

static int map_y_size(int fd)
{
	int count;
	char *line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

void print_map(game_map *map)
{
	int y;

	y = 0;
	while (map->map[y] != NULL)
	{
		ft_printf("%s", map->map[y]);
		y++;
	}
}

void get_map(char *argv, game_map *map)
{
	int fd;
	int count;
	char *line;

	count = 0;
	fd = open(argv, O_RDONLY);
	map->height = map_y_size(fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	map->width = map_x_size(fd);
	close(fd);
	map->map = malloc(map->height * sizeof (char*));
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[count] = line;
		line = get_next_line(fd);
		count++;
	}
	close(fd);
}
