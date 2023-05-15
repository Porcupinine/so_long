//
// Created by laura on 10/04/23.
//

#include "../include/map.h"

void test_map_data(void)
{
	t_game_map map;

	get_map("../maps/minimal_map.ber", &map);
	check_player(&map);
	check_exit(&map);
	check_collectables(&map);
	print_map(&map);
//	print_map_data(&map);
}