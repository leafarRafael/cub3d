/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:53 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/14 14:19:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "data.h"
#include "ray_casting.h"
#include <math.h>
#include <stdio.h>
#include "defines.h"
#include <stdlib.h>

static void	init_dda_variables(t_dda *dda, t_data *data, t_ray *ray);
static void define_step(t_data *data, t_dda *dda, t_ray *ray);
static void	find_collision(t_data *data, t_dda *dda, t_ray *ray);

void ft_dda(t_data *data, t_ray *ray, t_dda *dda)
{
	init_dda_variables(dda, data, ray);
	define_step(data, dda, ray);
	find_collision(data, dda, ray);
}

static void	init_dda_variables(t_dda *dda, t_data *data, t_ray *ray)
{
	dda->map[X] = (int) data->coord->pos[X];
	dda->map[Y] = (int) data->coord->pos[Y];
	dda->delta_dist[X] = (ray->ray_dir[X] == 0) ? 1e30 : fabs(1 / ray->ray_dir[X]);
	dda->delta_dist[Y] = (ray->ray_dir[Y] == 0) ? 1e30 : fabs(1 / ray->ray_dir[Y]);
	dda->hit = 0;
}

static void define_step(t_data *data, t_dda *dda, t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		dda->step[X] = -1;
		dda->side_dist[X] = (data->coord->pos[X] - dda->map[X]) * dda->delta_dist[X];
	}
	else
	{
		dda->step[X] = 1;
		dda->side_dist[X] = (dda->map[X] + 1.0 - data->coord->pos[X]) * dda->delta_dist[X];
	}
	if (ray->ray_dir[Y] < 0)
	{
		dda->step[Y] = -1;
		dda->side_dist[Y] = (data->coord->pos[Y] - dda->map[Y]) * dda->delta_dist[Y];
	}
	else
	{
		dda->step[Y] = 1;
		dda->side_dist[Y] = (dda->map[Y] + 1.0 - data->coord->pos[Y]) * dda->delta_dist[Y];
	}
}

#include <stdlib.h>
static void	find_collision(t_data *data, t_dda *dda, t_ray *ray)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist[X] < dda->side_dist[Y])
		{
			dda->side_dist[X] = dda->side_dist[X] + dda->delta_dist[X];
			dda->map[X] = dda->map[X] + dda->step[X];
			dda->side = 0;
		}
		else
		{
			dda->side_dist[Y] += dda->delta_dist[Y];
			dda->map[Y] += dda->step[Y];
			dda->side = 1;
		}
		if (data->worldmap[dda->map[X]][dda->map[Y]] > 0)
			dda->hit = 1;
	}
	if (dda->side == 0)
		ray->distance_wall = (dda->side_dist[X] - dda->delta_dist[X]);
	else
		ray->distance_wall = (dda->side_dist[Y] - dda->delta_dist[Y]);
}