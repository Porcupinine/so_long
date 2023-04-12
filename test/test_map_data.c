//
// Created by laura on 10/04/23.
//

#include "../include/map.h"

void test_map_data(void)
{
	game_map map;
	collectable *fish;
	fish = NULL;

	get_map("../maps/minimal_map.ber", &map);
	check_player(&map);
	check_exit(&map);
	check_collectables(&map, &fish);
	print_map(&map);
	print_map_data(&map, fish);
}