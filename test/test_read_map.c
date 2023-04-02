

#include "../../lib42/include/ft_printf.h"
#include "../../include/map.h"

int test_read_map(char **argv)
{
	game_map map;

	get_map(argv[1], &map);
	print_map(&map);
	return (0);
}