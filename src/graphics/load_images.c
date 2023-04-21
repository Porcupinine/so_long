//
// Created by laura on 17/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"

#define SIZE 65

void draw_wall(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_wall;
	mlx_image_t* img_wall;

	texture_wall = mlx_load_png("images/black.png");
	if (!texture_wall)
		ft_error("Texture fail\n"); //free shit
	img_wall = mlx_texture_to_image(mlx, texture_wall);
	if (!img_wall)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_wall, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_collectable(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_collectable;
	mlx_image_t* img_collectable;

	texture_collectable = mlx_load_png("images/food.png");
	if (!texture_collectable)
		ft_error("Texture fail\n"); //free shit
	img_collectable = mlx_texture_to_image(mlx, texture_collectable);
	if (!img_collectable)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_collectable, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_ground(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_ground;
	mlx_image_t* img_ground;

	texture_ground = mlx_load_png("images/grass.png");
	if (!texture_ground)
		ft_error("Texture fail\n"); //free shit
	img_ground = mlx_texture_to_image(mlx, texture_ground);
	if (!img_ground)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_ground, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_exit(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_exit;
	mlx_image_t* img_exit;

	texture_exit = mlx_load_png("images/dolgr.png");
	if (!texture_exit)
		ft_error("Texture fail\n"); //free shit
	img_exit = mlx_texture_to_image(mlx, texture_exit);
	if (!img_exit)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_exit, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}