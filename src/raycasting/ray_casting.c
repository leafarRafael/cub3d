/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/18 19:02:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include <stdio.h>
#include "defines.h"
#include <MLX42.h>
#include "utils.h"
#include <stdlib.h>
#include "libft.h"
#include <math.h>
#include "pixels_texture.h"

static void	define_ray_dir(t_ray *ray, t_data *data);

void	ray_casting(t_data *data)
{
	t_ray	ray;
	t_dda	dda;

	ray.index = 0;
	while (ray.index < WIDTH)
	{
		define_ray_dir(&ray, data);
		ft_dda(data, &ray, &dda);
		ray.line_height = (int) (HEIGHT / ray.distance_wall);
		ray.draw_start = (-ray.line_height / 2) + (HEIGHT / 2);
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = 	ray.line_height / 2 + HEIGHT / 2;
		if (ray.draw_end >= HEIGHT)
			ray.draw_end = HEIGHT -1;
		buffer_pixel_texture(data, &dda, &ray);
		ray.index++;
	}
}

static void	define_ray_dir(t_ray *ray, t_data *data)
{
	ray->camX = 2 * ray->index / (double) WIDTH -1;
	ray->ray_dir[Y] = data->coord->dir[Y] + (data->coord->plane[Y] * ray->camX);
	ray->ray_dir[X] = data->coord->dir[X] + (data->coord->plane[X] * ray->camX);
	ray->distance_wall = 0;
}
