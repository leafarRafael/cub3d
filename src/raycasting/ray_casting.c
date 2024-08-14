/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/14 11:48:18 by rbutzke          ###   ########.fr       */
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

static void	init(t_ray *ray, t_data *data);
static int defineColor(t_data *data, t_dda *dda);
static void draw(t_data *data, t_dda *dda, t_ray ray);


void	ray_casting(t_data *data)
{
	t_ray	ray;	
	t_dda	dda;

	ray.index = 0;
	while (ray.index < WIDTH -1)
	{
		init(&ray, data);
		ft_dda(data, &ray, &dda);
		ray.line_height = (int) (HEIGHT / ray.distance_wall);
		ray.draw_start = -ray.line_height / 2 + HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = 	ray.line_height / 2 + HEIGHT / 2;
		if (ray.draw_end >= HEIGHT)
			ray.draw_end = HEIGHT -1;
		draw(data, &dda, ray);
		ray.index++;
	}
}

static void	init(t_ray *ray, t_data *data)
{
	ray->camX = 2 * ray->index / (double) WIDTH -1;
	ray->ray_dir[X] = data->coord->dir[X] + data->coord->plane[X] * ray->camX;
	ray->ray_dir[Y] = data->coord->dir[Y] + data->coord->plane[Y] * ray->camX;
	ray->distance_wall = 0;
/* 	printf("ray->index = %d\n", ray->index);
	printf("2 * ray->index = %d\n", 2 * ray->index);
	printf("(double) WIDTH -1 = %f\n", (double) WIDTH -1);
	printf("ray->camX = %f\n", ray->camX);
	printf("ray->ray_dir[X] = %f\n", ray->ray_dir[X]);
	printf("ray->ray_dir[Y] = %f\n", ray->ray_dir[Y]); */
	//exit(1);
}


static int		defineColor(t_data *data, t_dda *dda)
{
	int allcolor[5];
	int color;
	int value;

	allcolor[0] = ft_color(255, 0, 0, 1);
	allcolor[1] = ft_color(0, 255, 0, 1);
	allcolor[2] = ft_color(0, 0, 255, 1);
	allcolor[3] = ft_color(0, 0, 0, 1);
	allcolor[4] = ft_color(255, 255, 224, 1);
	value = data->worldmap[dda->map[X]][dda->map[X]] - '0';
	switch (value)
	{
		case 1: color = allcolor[0]; break;
		case 2: color = allcolor[1]; break;
		case 3: color = allcolor[2]; break;
		case 4: color = allcolor[3]; break;
		default: color = allcolor[4]; break;
	}
	if (dda->side == 1)
			color = color / 2;
	return (color);
}

static void draw(t_data *data, t_dda *dda, t_ray ray)
{
	int red = defineColor(data, dda);

	while (ray.draw_start < ray.draw_end)
	{
		mlx_put_pixel(data->window.image, ray.index, ray.draw_start, red);
		ray.draw_start++;
	}	
}