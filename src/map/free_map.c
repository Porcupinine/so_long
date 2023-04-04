/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/31 10:25:02 by laura         #+#    #+#                 */
/*   Updated: 2023/03/31 10:25:02 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../../lib42/include/get_next_line.h"
#include "../../lib42//include/ft_printf.h"
#include "../../lib42/include/libft.h"
#include "../../include/map.h"


//static int	string_malloc_fail(char **arr, int count_arr)
//{
//	if (arr[count_arr] == NULL)
//	{
//		while (count_arr >= 0)
//		{
//			free(arr[count_arr]);
//			count_arr--;
//		}
//		free(arr);
//		return (0);
//	}
//	return (1);
//}

int free_fail_map(game_map *map, int count)
{
	if (map->map[count] == NULL) {
		while (count >= 0) {
			free(map->map[count]);
			count--;
		}
		free(map->map);
		return (0);
	}
	return(1);
}
