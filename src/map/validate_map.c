/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:29:06 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:29:18 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"

void	validate_map(t_game_map *map)
{
	check_borders(map);
	check_shape(map);
	check_player(map);
	map_valid_coordinates(map);
	check_collectables(map);
	check_exit(map);
}
