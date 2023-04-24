

#include "../../include/map.h"

int validate_map(game_map *map)
{
	if (check_shape(map) == 1)
		return (1);
	if (check_collectables(map) == 1)
		return (1);
	if (check_exit(map) == 1)
		return (1);
	if (check_player(map) == 1)
		return (1);
	if (check_borders(map) == 1)
		return (1);
	return (0);
}
