
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
	collectable *fish;

	get_map("maps/simple_valid_map.ber", &map);
	if (validate_map(&map, &fish) == 1)
		exit(1);
	// Start mlx
	mlx_t* mlx = mlx_init(map.width * SIZE, map.height * SIZE, "Test", true);
	if (!mlx)
		error();

	draw_map(mlx, &map, fish);
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


//liberar o mapa