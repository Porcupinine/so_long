
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <error.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42/include/MLX42/MLX42_Int.h"
#include "include/graphics.h"
#include "libft.h"
#include "include/move.h"
#include "ft_printf.h"

#define WIDTH 256
#define HEIGHT 256
#define SIZE 65

int32_t	main(void)
{
	game_map  map;

	get_map("maps/simple_valid_map.ber", &map);
//    print_map(&map);
	validate_map(&map);
	map.mlx = mlx_init(map.width * SIZE, map.height * SIZE, "Test", true);
	if (!map.mlx)
		ft_error("MLX42 init fail\n");
	draw_map(&map);
	mlx_key_hook(map.mlx, &move_player, &map);
	mlx_loop(map.mlx);

//	Optional, terminate will clean up any leftovers, this is just to demonstrate.
//	mlx_delete_image(mlx, img);
//	mlx_delete_texture(texture);
	mlx_terminate(map.mlx);
	return (EXIT_SUCCESS);
}