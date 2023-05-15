/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:34:59 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:35:01 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "MLX42/MLX42.h"
#include "../../include/move.h"

void	move_player(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP
		&& keydata.action == MLX_PRESS)
		move_up((t_game_map *)param);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT
		&& keydata.action == MLX_PRESS)
		move_left((t_game_map *)param);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN
		&& keydata.action == MLX_PRESS)
		move_down((t_game_map *)param);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT
		&& keydata.action == MLX_PRESS)
		move_right((t_game_map *)param);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}
