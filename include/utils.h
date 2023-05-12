//
// Created by laura on 5-5-23.
//

#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

#include "map.h"

void free_map_map(game_map *map);
void free_collectables_data(game_map *map);
void free_game_map(game_map *map);
//------------------------------------------------------------queue_functions.c
void enqueue (queue *q, int x, int y);
void dequeue (queue *q);
int check_queue(queue *q, int x, int y);

#endif //SO_LONG_UTILS_H
