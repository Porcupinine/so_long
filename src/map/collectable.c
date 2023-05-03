//
// Created by laura on 24/04/23.
//

#include <malloc.h>
#include "../../include/map.h"
#include "libft.h"

void add_collectable(collectables_data **head, int32_t x, int32_t y)
{
    collectables_data *fish;

    fish = malloc( 1 * sizeof(collectables_data));
    if (fish == NULL)
        ft_error("Malloc fail\n");
    fish->x = x;
    fish->y = y;
    fish->collectable_img = NULL;
    fish->collectable_text = NULL;
    fish->next = *head;
    *head = fish;
}

collectables_data *find_collectable(collectables_data *collectables,
                                    int32_t x, int32_t y)
{
	while (collectables->x != x && collectables->y != y && collectables != NULL)
		collectables = collectables->next;
	return (collectables);
}
