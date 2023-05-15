

#include <stdlib.h>
#include "../../lib42/include/ft_printf.h"
#include "../../include/map.h"

int test_read_map(char **argv)
{
	t_game_map map;
	t_game_map map1;
	t_game_map map2;
	t_game_map map3;

	ft_printf("minimal_map.ber\n");
	get_map("../maps/minimal_map.ber", &map);
	print_map(&map);

	ft_printf("simple_valid_map.ber\n");
	get_map("../maps/simple_valid_map.ber", &map1);
	print_map(&map1);

	ft_printf("mapgpt.ber\n");
	get_map("../maps/mapgpt.ber", &map2);
	print_map(&map2);

	ft_printf("not_rectangular\n");
	get_map("../maps/not_rectangular.ber", &map3);
	print_map(&map3);

	return (0);
}