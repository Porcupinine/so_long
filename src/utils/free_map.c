/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 10:25:02 by laura         #+#    #+#                 */
/*   Updated: 2023/05/15 11:35:30 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include "../../include/map.h"

void	free_map_map(t_game_map *map)
{
	int	count;

	count = 0;
	while (count < map->height)
	{
		free(map->map[count]);
		count++;
	}
	free(map->map);
}

void	free_collectables_data(t_game_map *map)
{
	t_collectables_data	*temp;
	t_collectables_data	*head;

	head = map->collectables;
	while (head != NULL)
	{
		temp = head;
		mlx_delete_image(map->mlx, (temp)->collectable_img);
		mlx_delete_texture(temp->collectable_text);
		head = (head)->next;
		free(temp);
	}
}

void	free_game_map(t_game_map *map)
{
	free_map_map(map);
	free_collectables_data(map);
}
