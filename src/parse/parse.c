/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:49:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 18:24:55 by rbutzke          ###   ########.fr       */
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
#include "defines.h"
#include "coordinates.h"
#include "valid_file.h"
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "parse.h"

static int init_data(t_data *data, t_mlst *mlst);

t_data *parse(int argc, char **argv)
{
	static t_data	data;
	static t_plr	coord;
	int				status;
	t_mlst			*mlst_file;

	status = valid_file(argc, argv[1]);
	if (status)
		exit(error_handler("Error\n", argv[1], msg_error(status), NULL) + status);
	mlst_file = NULL;
	mlst_file = get_file(argv[1]);
	if (mlst_file == NULL)
		exit(error_handler("Error\n", "Invalid formate file\n", NULL, NULL));
	if (get_texture_in_file(mlst_file, &data))
		exit(error_handler("Error\n", "The texture path is wrong or has multiple definitions.\n", NULL, NULL));
	if (get_ceiling_floor(mlst_file, &data))
		exit(error_handler("Error\n", "The texture path is wrong or has multiple definitions.\n", NULL, NULL));
	init_data(&data, mlst_file);
	set_initial_coordinates(&coord, &data);
	return (&data);
}

static int init_data(t_data *data, t_mlst *mlst)
{
	data->window.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data->window.image = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	data->window.player = mlx_new_image(data->window.mlx, 400, 400);
	data->window.wall[NORTH] = mlx_load_png(data->path_text[NORTH]);
	data->window.wall[SOUTH] = mlx_load_png(data->path_text[SOUTH]);
	data->window.wall[WEST] = mlx_load_png(data->path_text[WEST]);
	data->window.wall[EAST] = mlx_load_png(data->path_text[EAST]);
	data->worldmap = ft_cpy_mtrllst_to_cmtrx(mlst);
	if(!data->worldmap)
		return (1);
	return (0);
}
