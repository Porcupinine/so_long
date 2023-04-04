/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 17:32:50 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/03/30 17:32:50 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_MAP_H
#define SO_LONG_MAP_H

#include <stdio.h>

typedef struct game_map
{
	size_t height;
	size_t width;
	char **map;

}game_map;

typedef struct fish
{
	size_t x;
	size_t y;
	struct fish *next;

}fish;

void get_map(char *argv, game_map *map);
void print_map(game_map *map);

//--------------------------------------------------------------validate_map.c
int check_shape(game_map *map);
int check_borders(game_map *map);
int check_exit(game_map *map);
int check_player(game_map *map);
int check_collectables(game_map *map);

//--------------------------------------------------------------free_fail_map.c
int free_fail_map(game_map *map, int count);

#endif //SO_LONG_MAP_H
