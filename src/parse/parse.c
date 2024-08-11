/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/11 16:00:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int init_data(t_data *data, char *file);
static char **cpy_file(char *file);

t_data *parse(int argc, char **argv)
{
	static t_data data;

	if (argc != 2)
		return (NULL);
	if (!argv)
		return (NULL);
	init_data(&data, argv[1]);
	return (&data);
}

static int init_data(t_data *data, char *file)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player = mlx_new_image(data->mlx, 200, 200);
	data->pos[X] = 19;
	data->pos[Y] = 21;
	data->dir[X] = -1;
	data->dir[Y] = 0;
	data->plane[X] = 0;
	data->plane[Y] = 0.66;
	data->rgb_floor[0] = 0;
	data->rgb_floor[1] = 100;
	data->rgb_floor[2] = 0;
	data->rgb_floor[3] = 255;
	data->rgb_cel[0] = 0;
	data->rgb_cel[1] = 0;
	data->rgb_cel[2] = 100;
	data->rgb_cel[3] = 255;
	data->player_rgb[0] = 100;
	data->player_rgb[1] = 0;
	data->player_rgb[2] = 0;
	data->player_rgb[3] = 255;
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
	cpy = ft_calloc(sizeof(char *), i + 1);
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