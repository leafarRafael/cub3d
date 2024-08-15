/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/15 08:48:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "data.h"
#include "utils.h"
#include <MLX42.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include "defines.h"

static int init_data(t_data *data, char *file);
static char **cpy_file(char *file);
static void	init_coord(t_plr *coord, t_data *data);

t_data *parse(int argc, char **argv)
{
	static t_data	*data;
	static t_plr	*coord;

	if (argc != 2)
		return (NULL);
	if (!argv)
		return (NULL);
	data = malloc(sizeof(t_data));
	coord = malloc(sizeof(t_plr));
	init_data(data, argv[1]);
	init_coord(coord, data);
	return (data);
}

static int init_data(t_data *data, char *file)
{
	data->window.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->window.image = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->window.player = mlx_new_image(data->window.mlx, 200, 200);
	data->rgb_floor[0] = 0;
	data->rgb_floor[1] = 100;
	data->rgb_floor[2] = 0;
	data->rgb_floor[3] = 255;
	data->rgb_cel[0] = 0;
	data->rgb_cel[1] = 0;
	data->rgb_cel[2] = 100;
	data->rgb_cel[3] = 255;
	data->worldmap = cpy_file(file);
	if(!data->worldmap)
		return (1);
	return (0);
}

static char **cpy_file(char *file)
{
	int		fd;
	int		i;
	char	**cpy;
	char	*str;

	cpy = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while ((str = get_next_line(fd)))
	{
		free(str);
		i++;
	}
	cpy = malloc(sizeof(char *) * (i + 1));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while ((str = get_next_line(fd)))
	{
		cpy[i] = str;
		i++;
	}
	cpy[i] = NULL;
	close(fd);
	return (cpy);
}

static void init_coord(t_plr *coord, t_data *data)
{
	coord->pos[X] = 22;
	coord->pos[Y] = 12;
	coord->plane[X] = 0;
	coord->plane[Y] = 0.66;
	coord->dir[X] = -1;
	coord->dir[Y] = 0;
	coord->time[CURRENT] = 0;
	coord->time[OLD_TIME] = 0;

	data->coord = coord; 
}