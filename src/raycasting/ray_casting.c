/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/13 16:06:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include <stdio.h>
#include "defines.h"
#include <MLX42.h>
#include "utils.h"

static void	init(t_ray *ray, t_data *data);

void	ray_casting(t_data *data)
{
	t_ray	ray;	
	t_dda	dda;

	ray.index = 0;
	while (ray.index < WIDTH)
	{
		init(&ray, data);
		ft_dda(data, &ray, &dda);
		ray.line_height = (int) (HEIGHT / ray.distance_wall);
		ray.draw_start = -ray.line_height /2 + HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = 	ray.line_height /2 + HEIGHT / 2;
		if (ray.draw_end >= HEIGHT)
			ray.draw_end = HEIGHT -1;
		int red = ft_color(100, 100, 100, 150);
		int m = ray.draw_start;
		while (m < ray.draw_end)
		{
			mlx_put_pixel(data->window.image, ray.index, m, red);
			m++;
		}
		ray.index++;
	}
}

static void	init(t_ray *ray, t_data *data)
{
	ray->camX = 2 * ray->index / (double) WIDTH -1;
	ray->ray_dir[X] = data->coord->dir[X] + data->coord->plane[X] * ray->camX;
	ray->ray_dir[Y] = data->coord->dir[Y] + data->coord->plane[Y] * ray->camX;
	ray->distance_wall = 0;
}