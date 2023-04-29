

#include "../../include/map.h"

void validate_map(game_map *map)
{
	check_shape(map);
    check_collectables(map);
    check_exit(map);
    check_player(map);
    check_borders(map);
}
