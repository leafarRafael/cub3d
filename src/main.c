/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 14:25:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "data.h"
#include "parse.h"
#include "libft.h"
#include "MLX42.h"
#include "ray_casting.h"
#include "error_handler.h"
#include "init_atributes_mlx.h"
#include "render_ceiling_floor.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = parse(argc, argv);
	if (!data)
		return (error_handler("ERROR\n", NULL, NULL, NULL));
	init_atributes_mlx(data);
	render_ceiling_floor(data);
	ray_casting(data);
	mlx_image_to_window(data->window.mlx, data->window.image, 0, 0);
	mlx_loop_hook(data->window.mlx, ft_hook, (void*)data);
	mlx_loop(data->window.mlx);
	destroy_data(data);
	return (EXIT_SUCCESS);
}
