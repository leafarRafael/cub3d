/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:16:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 12:03:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "data.h"
#include "defines.h"
#include "libft.h"
#include "error_handler.h"
#include "matrix_lst.h"

static int	flood_fill(char **map, int map_max_y, int y, int x);

int	flood_fill_valid(t_data *data, t_mlst *mlst)
{
	char	**map;
	int		size;
	int		pos[2];
	int		status;

	map = ft_cpy_mtrllst_to_cmtrx(mlst);
	size = mlst->size;
	pos[Y] = data->coord->pos[Y];
	pos[X] = data->coord->pos[X];
	map[pos[Y]][pos[X]] = '0';
	status = flood_fill(map, size, pos[Y], pos[X]);
	ft_delcmtrx(map);
	if (status == ERROR)
		return (ERROR);
	return (0);
}

static int	flood_fill(char **map, int map_max_y, int y, int x)
{
	if (y < 0 || y >= map_max_y || x < 0 || x >= (int)ft_strlen(map[0])
		|| map[y][x] == '1' || map[y][x] == '$')
		return (0);
	if (map[y][x] == '#')
		return (ERROR);
	map[y][x] = '$';
	if (flood_fill(map, map_max_y, y - 1, x))
		return (ERROR);
	if (flood_fill(map, map_max_y, y + 1, x))
		return (ERROR);
	if (flood_fill(map, map_max_y, y, x - 1))
		return (ERROR);
	if (flood_fill(map, map_max_y, y, x + 1))
		return (ERROR);
	return (0);
}
