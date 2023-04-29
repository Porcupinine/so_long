#include "../include/map.h"
#include "ft_printf.h"

//
// Created by laura on 24/04/23.
//
void test_fish_status(void)
{
	int y = 0;
	int x = 0;
	game_map map;
	get_map("../maps/simple_valid_map.ber", &map);
	validate_map(&map);
    print_map(&map);
    print_map_data(&map);
}