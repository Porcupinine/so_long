/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:35:43 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:36:46 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"
#include <stdlib.h>
#include "libft.h"

void	enqueue(t_queue *q, int x, int y)
{
	t_coordinate	*new;

	new = malloc(sizeof(t_coordinate));
	if (new == NULL)
		ft_error("Error\n New node malloc fail\n");
	new->y = y;
	new->x = x;
	new->next = NULL;
	if (q->tail != NULL)
		q->tail->next = new;
	q->tail = new;
	if (q->head == NULL)
		q->head = new;
}

void	dequeue(t_queue *q)
{
	t_coordinate	*temp;

	if (q->head == NULL)
		return ;
	temp = q->head;
	q->head = q->head->next;
	free (temp);
	if (q->head == NULL)
		q->tail = NULL;
}

int	check_queue(t_queue *q, int x, int y)
{
	t_coordinate	*c;

	c = q->head;
	while (c != NULL)
	{
		if (c->x == x && c->y == y)
			return (0);
		c = c->next;
	}
	return (1);
}
