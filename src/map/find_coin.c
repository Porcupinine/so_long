//
// Created by laura on 24/04/23.
//

#include "../../include/map.h"

int find_collectable(collectable *fish, int32_t x, int32_t y)
{
	while (fish->x != x && fish->y != y)
		fish = fish->next;
	return (fish->status);
}