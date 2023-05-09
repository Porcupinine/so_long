

#include "../../include/map.h"

void validate_map(game_map *map)
{
    check_borders(map);
	check_shape(map);
    check_player(map);
    map_valid_coordinates(map);
    check_collectables(map);
    check_exit(map);
}
