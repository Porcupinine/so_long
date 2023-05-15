/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   directions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lpraca-l <lpraca-l@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:29:27 by lpraca-l      #+#    #+#                 */
/*   Updated: 2023/05/15 11:33:15 by lpraca-l      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"
#include "ft_printf.h"

static void	checks_after_move(t_game_map *map, char c)
{
	if (c == 'C')
	{
		map->map[map->player->y][map->player->x] = 'C';
		if (find_collectable(map->collectables, map->player->x,
				map->player->y)->collectable_img->enabled == true)
			map->collected++;
		find_collectable(map->collectables, map->player->x,
			map->player->y)->collectable_img->enabled = false;
	}
	if (c == 'E' && map->collectable_count == map->collected)
		exit(0);
	map->moves++;
	ft_printf("Movements: %d\n", map->moves);
}

void	move_up(t_game_map *map)
{
	char	c;

	c = map->map[map->player->y - 1][map->player->x];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->player->player_img->instances[0].y -= 65;
		map->player->y--;
		checks_after_move(map, c);
	}
}

void	move_left(t_game_map *map)
{
	char	c;

	c = map->map[map->player->y][map->player->x - 1];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->player->player_img->instances[0].x -= 65;
		map->player->x--;
		checks_after_move(map, c);
	}
}

void	move_right(t_game_map *map)
{
	char	c;

	c = map->map[map->player->y][map->player->x + 1];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->player->player_img->instances[0].x += 65;
		map->player->x++;
		checks_after_move(map, c);
	}
}

void	move_down(t_game_map *map)
{
	char	c;

	c = map->map[map->player->y + 1][map->player->x];
	if (c == '0' || c == 'C' || c == 'E')
	{
		map->player->player_img->instances[0].y += 65;
		map->player->y++;
		checks_after_move(map, c);
	}
}
