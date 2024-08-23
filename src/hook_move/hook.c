/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:48:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 08:16:47 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "render_ceiling_floor.h"
#include "ray_casting.h"
#include "controls.h"
#include <stdio.h>

void	ft_hook(void *param)
{
	t_data	*data;
	int		update;

	data = (t_data *) param;
	update = 0;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->window.mlx);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_LEFT))
		update += rotate_cam_left(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_RIGHT))
		update += rotate_cam_right(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_A))
		update += muve_left(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_D))
		update += muve_right(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_S))
		update += muve_down(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_W))
		update += muve_up(data);
	if (update)
	{
		render_ceiling_floor(data);
		ray_casting(data);
	}
}
