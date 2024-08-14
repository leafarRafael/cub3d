/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:48:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/14 16:19:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include <stdio.h>
#include "draw_image.h"
#include <libft.h>
#include "defines.h"
#include "ray_casting.h"
#include <math.h>

static void ctrl(int c, t_data *data);

void ft_hook(void* param)
{
	t_data *data;

	data = (t_data*) param;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->window.mlx);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_UP))
		ctrl(MLX_KEY_UP, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_DOWN))
		ctrl(MLX_KEY_DOWN, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_LEFT))
		ctrl(MLX_KEY_LEFT, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_RIGHT))
		ctrl(MLX_KEY_RIGHT, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_A))
		ctrl(MLX_KEY_A, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_D))
		ctrl(MLX_KEY_D, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_S))
		ctrl(MLX_KEY_S, data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_W))
		ctrl(MLX_KEY_W, data);
	draw_plaine(data);
	ray_casting(data);
}

static void ctrl(int c, t_data *data)
{
	double dir;
	double plane;

	if (c == MLX_KEY_W)
	{
		if (data->worldmap[(int)(data->coord->pos[X] + data->coord->dir[X] * data->move_speed)][(int) (data->coord->pos[Y])] == false)
			data->coord->pos[X] +=  data->coord->dir[X] * data->move_speed;
		if (data->worldmap[(int)data->coord->pos[X]][(int)(data->coord->pos[Y] + data->coord->dir[Y] * data->move_speed)] == false)
			data->coord->pos[Y] += data->coord->dir[Y] * data->move_speed;
	}
	else if (c == MLX_KEY_S)
	{
		if (data->worldmap[(int)(data->coord->pos[X] - data->coord->dir[X] * data->move_speed)][(int) (data->coord->pos[Y])] == false)
			data->coord->pos[X] +=  data->coord->dir[X] * data->move_speed;
		if (data->worldmap[(int)data->coord->pos[X]][(int)(data->coord->pos[Y] - data->coord->dir[Y] * data->move_speed)] == false)
			data->coord->pos[Y] += data->coord->dir[Y] * data->move_speed;
	}
	else if (c == MLX_KEY_A)
	{
		dir = data->coord->dir[X];
		plane = data->coord->plane[X];
		data->coord->dir[X] = data->coord->dir[X] * cos(-data->rote_speed) - data->coord->dir[Y] * sin (-data->rote_speed);
		data->coord->dir[Y] = dir * sin (-data->rote_speed) + data->coord->dir[Y] * cos(-data->rote_speed);
		data->coord->plane[X] = data->coord->plane[X] * cos(-data->rote_speed) - data->coord->plane[Y] * sin (-data->rote_speed);
		data->coord->plane[Y] = plane * sin (-data->rote_speed) + data->coord->plane[Y] * cos(-data->rote_speed);
	}
	else if (c == MLX_KEY_D)
	{
		dir = data->coord->dir[X];
		plane = data->coord->plane[X];
		data->coord->dir[X] = data->coord->dir[X] * cos(data->rote_speed) - data->coord->dir[Y] * sin (data->rote_speed);
		data->coord->dir[Y] = dir * sin (data->rote_speed) + data->coord->dir[Y] * cos(data->rote_speed);
		data->coord->plane[X] = data->coord->plane[X] * cos(data->rote_speed) - data->coord->plane[Y] * sin (data->rote_speed);
		data->coord->plane[Y] = plane * sin (data->rote_speed) + data->coord->plane[Y] * cos(data->rote_speed);
	}
	else if (c == MLX_KEY_UP)
		printf("Aguardando desenvolvimento da tecla [UP]\n");
	else if (c == MLX_KEY_DOWN)
		printf("Aguardando desenvolvimento da tecla [DOWN]\n");
	else if (c == MLX_KEY_LEFT)
		printf("Aguardando desenvolvimento da tecla [<-]\n");	
	else if (c == MLX_KEY_RIGHT)
		printf("Aguardando desenvolvimento da tecla [->]\n");
}