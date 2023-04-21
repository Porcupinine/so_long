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
#include <stdint.h>

typedef struct game_map
{
	int32_t height;
	int32_t width;
	char **map;
	int32_t exit_x;
	int32_t exit_y;
	int32_t player_x;
	int32_t player_y;
	int32_t collectables;
}game_map;

typedef struct collectable
{
	int status;
	int32_t x;
	int32_t y;
	struct collectable *next;
}collectable;

//----------------------------------------------------------------------print.c
/**
 * prints 2D array with the map
 * @param map map struct
 */
void print_map(game_map *map);
/**
 * print map data
 * @param map map struct
 * @param fish collectable struct
 */
void print_map_data(game_map *map, collectable *fish);
//-------------------------------------------------------------------make_map.c
/**
 * read data from .ber and write as a 2D array in game_map, calculates and store
 * size of the map
 * @param argv .ber file
 * @param map map struct
 */
void get_map(char *argv, game_map *map);
void add_collectable(collectable **head, int32_t x, int32_t y);
//---------------------------------------------------------------validate_map.c
int validate_map(game_map *map, collectable **fish);

//------------------------------------------------------------------check_map.c
/**
 * Check if givem map is rectangular
 * @param map map struct
 * @return 0 if rectangular or 1 if not
 */
int check_shape(game_map *map);
/**
 * check if givem map has all borders
 * @param map map struct
 * @return 0 if surrounded by ones or 1 if not
 */
int check_borders(game_map *map);
/**
 * check if there is 1 and only exit and store its coordinates on map struct
 * @param map map struct
 * @return 0 if there is one and only exit, 1 if there are more or none
 */
int check_exit(game_map *map);
/**
 * check if there is one and only player and store its coordinates on map struct
 * @param map map struct
 * @return 0 if there is one and only player, 1 if there are more or none
 */
int check_player(game_map *map);
/**
 * check if there are collectables and store the coordinate on fish struct and
 * amount on map struct
 * @param map map struct
 * @param fish collectables struct
 * @return 0 if there are collectables, 1 if there are no collectables
 */
int check_collectables(game_map *map, collectable **fish);
//--------------------------------------------------------------free_fail_map.c
int free_fail_map(game_map *map, int count);

#endif //SO_LONG_MAP_H
