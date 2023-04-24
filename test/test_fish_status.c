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
	while (y < map.height)
	{
		while (x < map.width)
		{
			if (map.map[y][x] == 'C')
				ft_printf("status: %d\n", find_collectable(map.fish, x, y));
			x++;
		}
		x = 0;
		y++;
	}
}