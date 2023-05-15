/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 13:18:53 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 13:19:30 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"

void	free_map_map(t_game_map *map);
void	free_collectables_data(t_game_map *map);
void	free_game_map(t_game_map *map);
//------------------------------------------------------------queue_functions.c
/**
 * adds new coordinate node to the tail of the queue
 * @param q head of the queue
 * @param x
 * @param y
 */
void	enqueue(t_queue *q, int x, int y);
/**
 * removes head node of the queue
 * @param q head of the qqueeue
 */
void	dequeue(t_queue *q);
/**
 * check is a coordinate node is on the queue
 * @param q head of the queue
 * @param x coordinate
 * @param y coordinate
 * @return 1 if it's not found and 0 if found
 */
int		check_queue(t_queue *q, int x, int y);

#endif //SO_LONG_UTILS_H
