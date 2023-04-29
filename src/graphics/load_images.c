//
// Created by laura on 17/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"

#define SIZE 65

void draw_wall(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_wall;
	mlx_image_t* img_wall;

	texture_wall = mlx_load_png("images/rockbrounish.png");
	if (!texture_wall)
		ft_error("Texture fail\n"); //free shit
	img_wall = mlx_texture_to_image(mlx, texture_wall);
	if (!img_wall)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_wall, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_collectable(game_map *map, int32_t x, int32_t y)
{
    collectables_data *collectable;

    collectable = find_collectable(map->collectables, x, y);
    collectable->collectable_text = mlx_load_png("images/food2.png");
	if (!collectable->collectable_text)
		ft_error("Texture fail\n"); //free shit
    collectable->collectable_img = mlx_texture_to_image(map->mlx, collectable->collectable_text);
	if (!collectable->collectable_img)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(map->mlx, collectable->collectable_img, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_ground(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_ground;
	mlx_image_t* img_ground;

	texture_ground = mlx_load_png("images/bg2.png");
	if (!texture_ground)
		ft_error("Texture fail\n"); //free shit
	img_ground = mlx_texture_to_image(mlx, texture_ground);
	if (!img_ground)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_ground, x, y) < 0)
		ft_error("Fail\n");
}

void draw_exit(mlx_t* mlx, int32_t x, int32_t y)
{
	mlx_texture_t* texture_exit;
	mlx_image_t* img_exit;

	texture_exit = mlx_load_png("images/meh.png");
	if (!texture_exit)
		ft_error("Texture fail\n"); //free shit
	img_exit = mlx_texture_to_image(mlx, texture_exit);
	if (!img_exit)
		ft_error("Image fail\n"); //free shit
	if (mlx_image_to_window(mlx, img_exit, x * SIZE, y * SIZE) < 0)
		ft_error("Fail\n");
}

void draw_player(game_map *map, int32_t x, int32_t y)
{
	map->player->player_text = mlx_load_png("images/dolgr.png");
	if (!map->player->player_text)
		ft_error("Texture fail\n"); //free shit
    map->player->player_img = mlx_texture_to_image(map->mlx, map->player->player_text);
	if (!map->player->player_img )
		ft_error("Image fail\n"); //free shit
    if (mlx_image_to_window(map->mlx, map->player->player_img, x * SIZE, y * SIZE) < 0)
        ft_error("Fail\n");
}
