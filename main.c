
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <error.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42/include/MLX42/MLX42_Int.h"
#include "include/graphics.h"

#define WIDTH 256
#define HEIGHT 256
#define SIZE 65


// Exit the program as failure.
static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);;
//	texture->height = 75;
}

int32_t	main(void)
{
	game_map  map;
//	collectable *fish;

	get_map("maps/large_valid_enemy.ber", &map);
	if (validate_map(&map) == 1)
		exit(1);
	// Start mlx
	mlx_t* mlx = mlx_init(map.width * SIZE, map.height * SIZE, "Test", true);
	if (!mlx)
		error();

	draw_map(mlx, &map);
	// Try to load the file
//	mlx_texture_t* texture = mlx_load_png("images/dolgr.png");
//	if (!texture)
//		error();
//	// Convert texture to a displayable image
//	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
//	if (!img)
//		error();

	// Display the image
//	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//		error();

	mlx_loop(mlx);

//	 Optional, terminate will clean up any leftovers, this is just to demonstrate.
//	mlx_delete_image(mlx, img);
//	mlx_delete_texture(texture);
	mlx_terminate(mlx);
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
