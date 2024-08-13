/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/13 14:55:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include <stdio.h>
#include "defines.h"

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