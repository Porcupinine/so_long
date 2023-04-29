
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <error.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42/include/MLX42/MLX42_Int.h"
#include "include/graphics.h"
#include "libft.h"

#define WIDTH 256
#define HEIGHT 256
#define SIZE 65

int32_t	main(void)
{
	game_map  map;
//	collectable *fish;

	get_map("maps/no_collectables.ber", &map);
//    print_map(&map);
	validate_map(&map);
	// Start mlx
	map.mlx = mlx_init(map.width * SIZE, map.height * SIZE, "Test", true);
	if (!map.mlx)
		ft_error("MLX42 init fail\n");

	draw_map(&map);
//    init_player(&map);

	mlx_key_hook(map.mlx, &move_player, &map);
	mlx_loop(map.mlx);

//	 Optional, terminate will clean up any leftovers, this is just to demonstrate.
//	mlx_delete_image(mlx, img);
//	mlx_delete_texture(texture);
	mlx_terminate(map.mlx);
	return (EXIT_SUCCESS);
}

//#include <stdlib.h>
//#include <stdio.h>
//#include <stdio.h>
//#include "MLX42/MLX42.h"
//#define WIDTH 720
//#define HEIGHT 480
//
//void my_keyhook(mlx_key_data_t keydata, void* param)
//{
//	// If we PRESS the 'J' key, print "Hello".
//	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
//		puts("Hello ");
//
//	// If we RELEASE the 'K' key, print "World".
//	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
//		puts("World");
//
//	// If we HOLD the 'L' key, print "!".
//	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
//		puts("!");
//}
//
//int32_t	main(void)
//{
//	mlx_t* mlx;
//
//	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
//		return (EXIT_FAILURE);
//
//	mlx_key_hook(mlx, &my_keyhook, NULL);
//	mlx_loop(mlx);
//	mlx_terminate(mlx);
//	return (EXIT_SUCCESS);
//}
