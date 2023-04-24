//
// Created by laura on 22/04/23.
//

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "../../include/graphics.h"

//void move_up(game_map *map)
//{
//	if (map->map[map->player_y+1][map->player_x] == '0')
//		map->player_y = map->player_y++;
//	if (map->map[map->player_y+1][map->player_x] == 'C')
//}
//
//void move_left(game_map *map)
//{
//
//}
//
//void move_right(game_map *map)
//{
//
//}
//
//void move_down(game_map *map)
//{
//
//}
//
//void move_player(mlx_key_data_t keydata, void* param)
//{
//	if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//		move_up((game_map *)param);
//	if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
//		move_left((game_map *)param);
//	if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
//		move_down((game_map *)param);
//	if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
//		move_right((game_map *)param);
//}