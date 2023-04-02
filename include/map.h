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


//typedef struct fish
//{
//    size_t x;
//	size_t y;
//    fish *next;
//
//}fish;

typedef struct game_map
{
	size_t height;
	size_t width;
	char **map;

}game_map;

void get_map(char *argv, game_map *map);
void print_map(game_map *map);

#endif //SO_LONG_MAP_H
