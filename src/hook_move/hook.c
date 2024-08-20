/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:48:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/20 11:16:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "render_ceiling_floor.h"
#include "ray_casting.h"
#include "controls.h"

void	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->window.mlx);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_LEFT))
		rotate_cam_left(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_RIGHT))
		rotate_cam_right(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_A))
		muve_left(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_D))
		muve_right(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_S))
		muve_down(data);
	if (mlx_is_key_down(data->window.mlx, MLX_KEY_W))
		muve_up(data);
	render_ceiling_floor(data);
	ray_casting(data);
}
