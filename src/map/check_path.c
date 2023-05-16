/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:22:56 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 12:06:21 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"
#include "libft.h"
#include <stdlib.h>
#include "../../include/utils.h"

int	check_valid_list(t_coordinate *valid_node, int x, int y)
{
	while (valid_node != NULL)
	{
		if (valid_node->y == y && valid_node->x == x)
			return (0);
		valid_node = valid_node->next;
	}
	return (1);
}

static void	add_coordinate(t_coordinate **head, int x, int y)
{
	t_coordinate	*new;

	new = malloc(sizeof (t_coordinate));
	if (new == NULL)
		ft_error("Error\n new node malloc fail\n");
	new->y = y;
	new->x = x;
	new->next = *head;
	*head = new;
}

static int	check_sides(t_game_map *map, t_queue *q, int32_t x, int32_t y)
{
	if (map->map[y - 1][x] != '1' &&
		check_valid_list(map->valid_coordinates, x, y - 1) != 0 &&
		check_queue(q, x, y - 1) != 0)
		enqueue(q, x, y - 1);
	if (map->map[y][x - 1] != '1' &&
		check_valid_list(map->valid_coordinates, x - 1, y) != 0 &&
		check_queue(q, x - 1, y) != 0)
		enqueue(q, x - 1, y);
	if (map->map[y + 1][x] != '1' &&
		check_valid_list(map->valid_coordinates, x, y + 1) != 0 &&
		check_queue(q, x, y + 1) != 0)
		enqueue(q, x, y + 1);
	if (map->map[y][x + 1] != '1' &&
		check_valid_list(map->valid_coordinates, x + 1, y) != 0 &&
		check_queue(q, x + 1, y) != 0)
	{
		add_coordinate(&map->valid_coordinates, x + 1, y);
		return (1);
	}
	return (0);
}

static t_queue	*init_structs(t_game_map *map)
{
	t_queue	*q;

	q = malloc(sizeof (t_queue));
	if (q == NULL)
		ft_error("Error\nQueue malloc fail\n");
	q->head = NULL;
	q->tail = NULL;
	map->valid_coordinates = malloc(sizeof (t_coordinate));
	if (map->valid_coordinates == NULL)
		ft_error("Error\nValid_coordinates malloc fail\n");
	map->valid_coordinates->x = map->player-> x;
	map->valid_coordinates->y = map->player-> y;
	map->valid_coordinates->next = NULL;
	return (q);
}

void	map_valid_coordinates(t_game_map *map)
{
	t_queue	*q;
	int		count_y;
	int		count_x;

	count_x = map->player->x;
	count_y = map->player->y;
	q = init_structs(map);
	while (count_x < map->width - 1)
	{
		if (check_sides(map, q, count_x, count_y) == 1)
			count_x++;
		else
		{
			if (q->head != NULL)
			{
				count_y = q->head->y;
				count_x = q->head->x;
				dequeue(q);
				add_coordinate(&map->valid_coordinates, count_x, count_y);
			}
			else
				break ;
		}
	}
}
