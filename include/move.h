/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 13:18:04 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 13:18:45 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "map.h"

//-----------------------------------------------------------------directions.c
/**
 * if possible moves the player up and checks for collectables and
 * exit
 * @param map
 */
void	move_up(t_game_map *map);
/**
 * if possible moves the player to the left and checks for collectables and
 * exit
 * @param map
 */
void	move_left(t_game_map *map);
/**
 * if possible moves the player to the right and checks for collectables and
 * exit
 * @param map
 */
void	move_right(t_game_map *map);
/**
 * if possible moves the player down and checks for collectables and
 * exit
 * @param map
 */
void	move_down(t_game_map *map);
//----------------------------------------------------------------move_player.c
/**
 * recognizes key being pushed and calls the related function
 * @param keydata
 * @param param
 */
void	move_player(mlx_key_data_t keydata, void *param);

#endif //SO_LONG_MOVE_H
