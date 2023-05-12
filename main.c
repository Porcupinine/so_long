/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 14:34:12 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/12 14:34:26 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "include/graphics.h"
#include "libft.h"
#include "include/move.h"

#define SIZE 65

int	main(int argc, char **argv)
{
    game_map  map;

    if (argc != 2)
        ft_error("Error\nWrong amount of arguments\n");
	get_map(argv[1], &map);
	validate_map(&map);
	map.mlx = mlx_init(map.width * SIZE, map.height * SIZE,
                       "Boto cor-de-rosa", true);
	if (!map.mlx)
		ft_error("Error\nMLX42 init fail\n");
	draw_map(&map);
	mlx_key_hook(map.mlx, &move_player, &map);
	mlx_loop(map.mlx);
	return (EXIT_SUCCESS);
}
