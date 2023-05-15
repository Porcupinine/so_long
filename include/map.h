/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 17:32:50 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 13:32:13 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <stdint.h>
# include "../MLX42/include/MLX42/MLX42.h"

/**
 * list of coordinates
 */
typedef struct s_coordinate
{
	int32_t				x;
	int32_t				y;
	struct s_coordinate	*next;
}t_coordinate;

/**
 * queue struct
 */
typedef struct s_queue
{
	t_coordinate	*head;
	t_coordinate	*tail;
}t_queue;

/**
 * struct holding
 * x and y coordinates of the player
 * pointer to the player texture and image
 */
typedef struct s_player_data
{
	int32_t			x;
	int32_t			y;
	mlx_image_t		*player_img;
	mlx_texture_t	*player_text;

}t_player_data;

/**
 * struct holding
 * collectable coordinates x and y
 * pointer to collectable texture and image
 * pointer to the next collectable in the list
 */
typedef struct s_collectables_data
{
	int32_t						x;
	int32_t						y;
	mlx_image_t					*collectable_img;
	mlx_texture_t				*collectable_text;
	struct s_collectables_data	*next;
}t_collectables_data;

/**
 * struct holding map information
 * pointer to mlx instance, player data and collectables list
 * size of the map,
 * collectables counter that is set to the collectables amount and deducted
 * everytime player finds a collectable
 * 2D array with map data from .ber file
 */
typedef struct s_game_map
{
	mlx_t				*mlx;
	int32_t				height;
	int32_t				width;
	char				**map;
	int32_t				exit_x;
	int32_t				exit_y;
	int32_t				collectable_count;
	int32_t				collected;
	t_player_data		*player;
	t_collectables_data	*collectables;
	int32_t				moves;
	t_coordinate		*valid_coordinates;

}t_game_map;

//----------------------------------------------------------------------print.c
/**
 * prints 2D array with the map
 * @param map map struct
 */
void				print_map(t_game_map *map);
/**
 * print map data
 * @param map map struct
 * @param fish collectable struct
 */
void				print_map_data(t_game_map *map);
/**
 * printe valid coordinates list
 * @param map
 */
void				print_valid_coordinates(t_game_map *map);
/**
 * print items on the queue
 * @param q
 */
void				print_queue(t_queue *q);
//-------------------------------------------------------------------make_map.c
/**
 * read data from .ber and write as a 2D array in game_map, calculates and
 * store size of the map
 * @param argv .ber file
 * @param map map struct
 */
void				get_map(char *argv, t_game_map *map);
//---------------------------------------------------------------validate_map.c
/**
 * calls all check functions to see if map is valid.
 * @param map  game data
 */
void				validate_map(t_game_map *map);
//------------------------------------------------------------------check_map.c
/**
 * Check if givem map is rectangular
 * @param map map struct
 * @return 0 if rectangular or 1 if not
 */
void				check_shape(t_game_map *map);
/**
 * check if givem map has all borders
 * @param map map struct
 * @return 0 if surrounded by ones or 1 if not
 */
void				check_borders(t_game_map *map);
/**
 * check if there is 1 and only exit and store its coordinates on map struct
 * @param map map struct
 * @return 0 if there is one and only exit, 1 if there are more or none
 */
void				check_exit(t_game_map *map);
/**
 * check if there is one and only player and store its coordinates on map
 * struct
 * @param map map struct
 * @return 0 if there is one and only player, 1 if there are more or none
 */
void				check_player(t_game_map *map);
/**
 * check if there are collectables and store the coordinate on fish struct and
 * amount on map struct
 * @param map map struct
 * @param fish collectables struct
 * @return 0 if there are collectables, 1 if there are no collectables
 */
void				check_collectables(t_game_map *map);
//----------------------------------------------------------------collectable.c
/**
 * find the node with given coordinates
 * @param collectables head of collectables list
 * @param x coordinate x
 * @param y coordinate y
 * @return a pointer to the node
 */
t_collectables_data	*find_collectable(t_collectables_data *collectables,
						int32_t x, int32_t y);
/**
 * creates a neew node to collectables_data list adds its coordinates
 * and initialize image and texture.
 * @param head head of the list
 * @param x coordinate x
 * @param y coordinate y
 */
void				add_collectable(t_collectables_data **head,
						int32_t x, int32_t y);
//-----------------------------------------------------------------check_path.c
/**
 * searches for a pair of coordinates on the list
 * @param valid_node list to search
 * @param x
 * @param y
 * @return 0 if it finds and 1 if it doesn't
 */
int					check_valid_list(t_coordinate *valid_node, int x, int y);
/**
 * Goes through the map and adds all reachable coordinates on the
 * valid_coordinates inside the map struct
 * @param map
 */
void				map_valid_coordinates(t_game_map *map);

#endif //SO_LONG_MAP_H
