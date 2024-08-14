/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:48:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/14 08:28:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include <stdio.h>
#include "draw_image.h"
#include <libft.h>
#include "defines.h"
#include "ray_casting.h"

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
}

static void ctrl(int c, t_data *data)
{
	if (c == MLX_KEY_UP)
	{
		printf("Aguardando desenvolvimento da tecla [UP]\n");
		draw_plaine(data);
		ray_casting(data);
	}
	else if (c == MLX_KEY_DOWN)
	{
		printf("Aguardando desenvolvimento da tecla [DOWN]\n");
		draw_plaine(data);
		ray_casting(data);
	}
	else if (c == MLX_KEY_LEFT)
	{
;
		printf("Aguardando desenvolvimento da tecla [<-]\n");	
		draw_plaine(data);
		ray_casting(data);
	}
	else if (c == MLX_KEY_RIGHT)
	{
		printf("Aguardando desenvolvimento da tecla [->]\n");
		draw_plaine(data);
		ray_casting(data);
	}
	else
	{
		printf("Aguardando desenvolvimento da tecla [%c]\n", c);
		draw_plaine(data);
		ray_casting(data);
	}
}