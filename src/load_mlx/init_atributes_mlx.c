/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atributes_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:22 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 14:27:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "defines.h"
#include "error_handler.h"
#include <stdlib.h>

static int	loadpng(mlx_texture_t **wall, char *str);

int	init_atributes_mlx(t_data *data)
{
	int	status;

	status = 0;
	data->window.mlx = mlx_init(WIDTH, HEIGHT, GAME, true);
	data->window.image = mlx_new_image(data->window.mlx, WIDTH, HEIGHT);
	status += loadpng(&data->window.wall[NORTH], data->args_file[NORTH].str);
	status += loadpng(&data->window.wall[SOUTH], data->args_file[SOUTH].str);
	status += loadpng(&data->window.wall[WEST], data->args_file[WEST].str);
	status += loadpng(&data->window.wall[EAST], data->args_file[EAST].str);
	if (status)
		exit(destroy_data(data) + error_handler(E_MAP, 0, 0, 0) + 1);
	return (0);
}

static int	loadpng(mlx_texture_t **wall, char *str)
{
	if (!str)
		return (ERROR);
	(*wall) = mlx_load_png(str);
	if (!wall)
		return (ERROR);
	return (0);
}
