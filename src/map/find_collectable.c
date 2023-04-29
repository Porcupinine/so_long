//
// Created by laura on 24/04/23.
//

#include "../../include/map.h"

collectables_data *find_collectable(collectables_data *collectables, int32_t x, int32_t y)
{
	while (collectables->x != x && collectables->y != y && collectables != NULL)
		collectables = collectables->next;
	return (collectables);
}