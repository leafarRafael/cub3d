/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:48:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 16:07:43 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "data.h"
#include "parse.h"
#include "render_ceiling_floor.h"
#include "libft.h"
#include "MLX42.h"
#include "ray_casting.h"
#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = parse(argc, argv);
	if (!data)
		return (display_error("ERROR\n", NULL, NULL, NULL));
	render_ceiling_floor(data);
	ray_casting(data);
	mlx_image_to_window(data->window.mlx, data->window.image, 0, 0);
	mlx_loop_hook(data->window.mlx, ft_hook, (void*)data);
	mlx_loop(data->window.mlx);
	mlx_terminate(data->window.mlx);
	ft_delcmtrx(data->worldmap);
	return (EXIT_SUCCESS);
}
