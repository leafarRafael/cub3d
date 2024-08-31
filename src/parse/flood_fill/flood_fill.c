/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:16:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/31 15:36:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "data.h"
#include "utils.h"
#include "defines.h"
#include "libft.h"
#include <stdio.h>

void	flood_fill(char **map, int map_max_y, int y, int x)
{
	if (y < 0 || y >= map_max_y || x < 0 || x >= (int)ft_strlen(map[0])
		|| map[y][x] == '1' || map[y][x] == '$')
		return ;
	if (map[y][x] == '#')
	{
		printf("X = %d Y = %d\n", x, y);
		exit(error_handler("ERROR\n", "leaky map\n", NULL, NULL));
	}
	map[y][x] = '$';
	flood_fill(map, map_max_y, y - 1, x);
	flood_fill(map, map_max_y, y + 1, x);
	flood_fill(map, map_max_y, y, x - 1);
	flood_fill(map, map_max_y, y, x + 1);
	return ;
}