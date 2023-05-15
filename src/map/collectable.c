/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:25:47 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:26:48 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/map.h"
#include "libft.h"

void	add_collectable(t_collectables_data **head, int32_t x, int32_t y)
{
	t_collectables_data	*fish;

	fish = malloc(1 * sizeof(t_collectables_data));
	if (fish == NULL)
		ft_error("Malloc fail\n");
	fish->x = x;
	fish->y = y;
	fish->collectable_img = NULL;
	fish->collectable_text = NULL;
	fish->next = *head;
	*head = fish;
}

t_collectables_data	*find_collectable(t_collectables_data *collectables,
                                         int32_t x, int32_t y)
{
	while (collectables != NULL && (collectables->x != x
			|| collectables->y != y))
		collectables = collectables->next;
	return (collectables);
}
