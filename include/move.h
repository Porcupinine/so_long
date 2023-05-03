//
// Created by laura on 29-4-23.
//

#ifndef SO_LONG_MOVE_H
#define SO_LONG_MOVE_H

#include "map.h"

//-----------------------------------------------------------------directions.c
/**
 * if possible moves the player up and checks for collectables and
 * exit
 * @param map
 */
void move_up(game_map *map);
/**
 * if possible moves the player to the left and checks for collectables and
 * exit
 * @param map
 */
void move_left(game_map *map);
/**
 * if possible moves the player to the right and checks for collectables and
 * exit
 * @param map
 */
void move_right(game_map *map);
/**
 * if possible moves the player down and checks for collectables and
 * exit
 * @param map
 */
void move_down(game_map *map);
//----------------------------------------------------------------move_player.c
/**
 * recognizes key being pushed and calls the related function
 * @param keydata
 * @param param
 */
void move_player(mlx_key_data_t keydata, void* param);


#endif //SO_LONG_MOVE_H
