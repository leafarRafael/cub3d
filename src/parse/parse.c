/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/31 16:14:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "data.h"
#include "utils.h"
#include <MLX42.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "defines.h"
#include "parse.h"
#include "matrix_lst.h"
#include "get_attr.h"
#include "is_valid_map.h"
#include "normalize_map.h"
#include "set_player.h"
#include "flood_fill.h"
#include "stdio.h"

void put(t_mlst *mlst);
static int init_data(t_data *data);

t_data *parse(int argc, char **argv)
{
	t_mlst			*mlst;
	static t_data	data;
	static t_plr	coord;

	valid_arguments(argc, argv);
	mlst = read_file(argv[1]);
	if (mlst->size == 0)
		exit(error_handler("ERROR\n", "fail to read file\n", NULL, NULL) + ft_delete_matrix(mlst));
	get_attr(mlst, &data);
	if (is_valid_map(mlst))
		exit(error_handler("ERROR\n", "is invalid map\n", NULL, NULL) + ft_delete_matrix(mlst));
	normalize(mlst);
	data.coord = &coord;
	data.worldmap = ft_cpy_mtrllst_to_cmtrx(mlst);
	set_player(&data);
	// for(int i = 0; data.worldmap[i]; i++)
	// 	printf("%s\n", data.worldmap[i]);
	flood_fill(data.worldmap, mlst->size, data.coord->pos[Y], data.coord->pos[X]);
	ft_delcmtrx(data.worldmap);
	data.worldmap = ft_cpy_mtrllst_to_cmtrx(mlst);
	data.worldmap[(int)data.coord->pos[Y]][(int)data.coord->pos[X]] = '0';
	for(int i = 0; data.worldmap[i]; i++)
		printf("%s\n", data.worldmap[i]);
	ft_delete_matrix(mlst);
	printf("player pos Y = %f player pos X = %f\n", data.coord->pos[Y], data.coord->pos[X]);
	printf("player dir Y = %f player dir X = %f\n", data.coord->dir[Y], data.coord->dir[X]);
	printf("player plane Y = %f player plane X = %f\n", data.coord->plane[Y], data.coord->plane[X]);
	init_data(&data);
	return (&data);
}

static int init_data(t_data *data)
{
	data->window.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->window.image = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->window.player = mlx_new_image(data->window.mlx, 400, 400);
	data->window.wall[NORTH] = mlx_load_png("textures/eagle.png");
	data->window.wall[SOUTH] = mlx_load_png("textures/bluestone.png");
	data->window.wall[WEST] = mlx_load_png("textures/mossy.png");
	data->window.wall[EAST] = mlx_load_png("textures/wood.png");
	data->rgb_floor[0] = 0;
	data->rgb_floor[1] = 100;
	data->rgb_floor[2] = 0;
	data->rgb_floor[3] = 255;
	data->rgb_cel[0] = 0;
	data->rgb_cel[1] = 0;
	data->rgb_cel[2] = 100;
	data->rgb_cel[3] = 255;
	return (0);
}

void put(t_mlst *mlst)
{
	int		i;
	t_llst	*llst;

	i = 0;
	llst = mlst->head;
	while(i < mlst->size)
	{
		ft_putlst_fd(llst->lst, 1, 2);
		llst = llst->next;
		i++;
	}

}