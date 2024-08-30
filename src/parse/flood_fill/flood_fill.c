/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:16:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 19:37:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "data.h"
#include "utils.h"
#include "defines.h"
#include "libft.h"

#include <stdio.h>

void get_player_pos(t_data *data)
{
	char **map;
	int x;
	int y;
	
	x = 0;
	y = 0;
	map = data->worldmap;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E'
				||  map[y][x] == 'S' || map[y][x] == 'W')
			{
				printf("x = %d y = %d\n", x, y);
				data->coord->pos[X] = (double)x;
				data->coord->pos[Y] = (double)y;
				map[y][x] = '0';
				return ;
			}
			x += 1;
		}
		y += 1;
	}
	exit(error_handler("ERROR\n", "invalid map\n", NULL, NULL));
}

void	flood_fill(char **map, int map_max_y, int y, int x)
{
	if (y < 0 || y >= map_max_y || x < 0 || x >= (int)ft_strlen(map[0])
		|| map[y][x] == '1' || map[y][x] == '$')
		return ;
	if (map[y][x] == '9')
		exit(error_handler("ERROR\n", "leaky map\n", NULL, NULL));
	map[y][x] = '$';
	flood_fill(map, map_max_y, y - 1, x);
	flood_fill(map, map_max_y, y + 1, x);
	flood_fill(map, map_max_y, y, x - 1);
	flood_fill(map, map_max_y, y, x + 1);
	return ;
}