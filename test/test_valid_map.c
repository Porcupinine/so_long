

#include "../include/map.h"

int test_shape(void)
{
	game_map map;
	get_map("../maps/not_a_box.ber", &map);
	print_map(&map);
	check_shape(&map);

	game_map map1;
	get_map("../maps/mapgpt.ber", &map1);
	print_map(&map1);
	check_shape(&map1);

	game_map map2;
	get_map("../maps/not_rectangular.ber", &map2);
	print_map(&map2);
	check_shape(&map2);

	return(0);
}

int test_box(void)
{
	game_map map;
	get_map("../maps/not_a_box.ber", &map);
	print_map(&map);
	check_borders(&map);
	return (0);
}

int test_exit(void)
{
	game_map map;
	get_map("../maps/no_exit.ber", &map);
	print_map(&map);
	check_exit(&map);

	game_map map1;
	get_map("../maps/not_a_box.ber", &map1);
	print_map(&map1);
	check_exit(&map1);

	game_map map2;
	get_map("../maps/too_many_exits.ber", &map2);
	print_map(&map2);
	check_exit(&map2);

	game_map map3;
	get_map("../maps/simple_valid_map.ber", &map3);
	print_map(&map3);
	check_exit(&map3);

	return (0);
}

int test_players(void)
{
	game_map map;
	get_map("../maps/no_exit.ber", &map);
	print_map(&map);
	check_player(&map);

	game_map map1;
	get_map("../maps/not_a_box.ber", &map1);
	print_map(&map1);
	check_player(&map1);

	game_map map2;
	get_map("../maps/too_many_exits.ber", &map2);
	print_map(&map2);
	check_player(&map2);

	game_map map3;
	get_map("../maps/simple_valid_map.ber", &map3);
	print_map(&map3);
	check_player(&map3);

	return (0);
}

int test_collectables(void)
{
	collectable *fish;

	game_map map;
	get_map("../maps/no_exit.ber", &map);
	print_map(&map);
	check_collectables(&map, fish);

	game_map map1;
	get_map("../maps/not_a_box.ber", &map1);
	print_map(&map1);
	check_collectables(&map1, fish);

	game_map map2;
	get_map("../maps/too_many_exits.ber", &map2);
	print_map(&map2);
	check_collectables(&map2, fish);

	game_map map3;
	get_map("../maps/simple_valid_map.ber", &map3);
	print_map(&map3);
	check_collectables(&map3, fish);

	return (0);
}
