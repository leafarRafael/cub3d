/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 13:54:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "data.h"
#include "error_handler.h"
#include "hook.h"
#include "init_atributes_mlx.h"
#include "parse.h"
#include "ray_casting.h"
#include "render_ceiling_floor.h"
#include "set_rgb.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parse(argc, argv);
	if (!data)
		return (error_handler(0));
	if (set_rgb(data))
		return (error_handler(E_COLOR));
	if (init_atributes_mlx(data))
		return (error_handler(E_MLX42));
	render_ceiling_floor(data);
	ray_casting(data);
	mlx_image_to_window(data->window.mlx, data->window.image, 0, 0);
	mlx_loop_hook(data->window.mlx, ft_hook, (void *)data);
	mlx_loop(data->window.mlx);
	destroy_data(data);
	return (SUCCESS);
}
