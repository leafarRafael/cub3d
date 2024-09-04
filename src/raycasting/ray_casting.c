/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:40:19 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include "defines.h"
#include "pixels_texture.h"
#include "render_texture_image.h"

static void	ray_dir(t_ray *ray, t_data *data);
static void	set_column_height(t_ray *ray);

void	ray_casting(t_data *data)
{
	t_ray	ray;
	t_dda	dda;

	ray.index = 0;
	while (ray.index < WIDTH)
	{
		ray_dir(&ray, data);
		ft_dda(data, &ray, &dda);
		set_column_height(&ray);
		buffer_pixel_texture(data, &dda, &ray);
		render_texture_on_image(data, &ray, ray.buffer);
		ray.index++;
	}
}

/**
 * @brief Calculates the ray direction vector for the current column.
 * 
 *	This function calculates the angle of each beam that will be fired,
 *  covering all columns within the field of view (FOV).
 * 
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param data A pointer to the main game data structure (t_data).
 * The following attributes are calculated or updated updated in this function:
 *  - cam:
 * 	Is the basis for calculating the angle of the radius direction vector.
 *	- ray->ray_dir[](Y and X):
 * 	This is the direction in which the beam will be fired.
 *	- ray->distance_wall:
 * 	You will then be given the distance by radius to the collision.
 **/
static void	ray_dir(t_ray *ray, t_data *data)
{
	double	cam;

	cam = 2 * ray->index / (double) WIDTH -1;
	ray->ray_dir[Y] = data->coord->dir[Y] + (data->coord->plane[Y] * cam);
	ray->ray_dir[X] = data->coord->dir[X] + (data->coord->plane[X] * cam);
	ray->distance_wall = 0;
}

/**
 * @brief Calculates the start and end
 * 		  point for rendering the texture.
 * 
 * Here we calculate the vertical range
 * of pixels that will be rendered.
 * 
 * @param ray Pointer to structure with raycasting algorithm variable.
 * 
 * 	The following attributes are calculated
 *  or updated updated in this function:
 *  - ray->column_height:
 * 	Result between the ratio of the distance
 *  traveled and the height of the screen.
 * 
 * 	- ray->draw_start and ray->draw_end:
 * 	point in the window where the column's
 *  rendering begins and ends respectively.
 *  We make a protection in case the start and end
 *  values are outside the window's range.
 **/
static void	set_column_height(t_ray *ray)
{
	ray->column_height = (int)(HEIGHT / ray->distance_wall);
	ray->draw_start = (-ray->column_height / 2) + HEIGHT_2;
	ray->draw_end = ray->column_height / 2 + HEIGHT_2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT -1;
}
