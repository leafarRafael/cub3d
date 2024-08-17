/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/17 17:50:08 by rbutzke          ###   ########.fr       */
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
static int defineColor(t_data *data, t_dda *dda, t_ray *ray);
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
	ray->ray_dir[Y] = data->coord->dir[Y] + data->coord->plane[Y] * ray->camX;
	ray->ray_dir[X] = data->coord->dir[X] + data->coord->plane[X] * ray->camX;
	ray->distance_wall = 0;
}

static int		defineColor(t_data *data, t_dda *dda, t_ray *ray)
{
	int allcolor[5];
	int color;
	int value;

	allcolor[0] = ft_color(255, 0, 0, 255);
	allcolor[1] = ft_color(0, 255, 0, 255);
	allcolor[2] = ft_color(0, 0, 255, 255);
	allcolor[3] = ft_color(0, 0, 0, 255);
	allcolor[4] = ft_color(255, 255, 224, 255);
	value = data->worldmap[dda->map[Y]][dda->map[Y]] - '0';
	if (value == 1)
	{
		if (ray->ray_dir[Y] < 0)
			color = allcolor[0];
		else if (ray->ray_dir[Y] > 0)
			color = allcolor[1];
		else if (ray->ray_dir[X] < 0)
			color = allcolor[2];
		else if (ray->ray_dir[X] > 0)
			color = allcolor[3];
	}
	if (dda->side == 1)
		color = color / 2;
	return (color);
}

static void draw(t_data *data, t_dda *dda, t_ray ray)
{
	int red = defineColor(data, dda, &ray);

	while (ray.draw_start < ray.draw_end)
	{
		mlx_put_pixel(data->window.image, ray.index, ray.draw_start, red);
		ray.draw_start++;
	}
}

static int		defineTexture(t_data *data, t_dda *dda, t_ray *ray)
{
	int value;

	value = data->worldmap[dda->map[Y]][dda->map[Y]] - '0';
	if (value == 1)
	{
		double wallX; //where exactly the wall was hit
    	if(dda->side == 0) wallX = data->coord->pos[Y] + ray->distance_wall * ray->dir[Y];
    	else          wallX = data->coord->pos[X] + ray->distance_wall * ray->dir[X];
		wallX -= floor(wallX);
		
		int	texX = (int) (wallX * (double)data->window.wall[NORTH]->width);
		if (dda->side == 0 && ray->dir[X] > 0) texX = data->window.wall[NORTH]->width - texX -1;
		if (dda->side == 1 && ray->dir[Y] < 0) texX = data->window.wall[NORTH]->width - texX -1;
		// if (ray->ray_dir[Y] < 0)
		// else if (ray->ray_dir[Y] > 0)
			
		// else if (ray->ray_dir[X] < 0)
			
		// else if (ray->ray_dir[X] > 0)
			
	}

	return ();
}