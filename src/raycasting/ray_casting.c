/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/21 17:29:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include "defines.h"
#include <MLX42.h>
#include "pixels_texture.h"

static void	define_ray_dir(t_ray *ray, t_data *data);
static void set_column_height(t_ray *ray);

/**
 * @brief Render the 2d game image with 3d perspective using raycasting.
 * 
 * This function implements the raycasting algorithm to render a 3D view from a 2D map.
 * It works by iterating through each vertical stripe of the screen (represented by the image width),
 * casting a ray from the player's position through the screen's plane in the direction the player is facing.
 * The function calculates the distance to the nearest wall along each ray, 
 * determines the height of the wall to be rendered, and then samples the appropriate texture
 * for that wall segment.
 *
 * @param data A pointer to the main game data structure (t_data).
 * 
 * Steps involved:
 *  - define_ray_dir(&ray, data):
 *      Determines the direction of the current ray based on the player's direction and camera plane.
 *  - ft_dda(data, &ray, &dda):
 *      Performs the Digital Differential Analysis (DDA) algorithm to find the point of collision with a wall on the 2D map.
 *      Also determines the appropriate texture to use for the wall.
 *  - set_column_height(&ray):
 *      Calculates the start and end positions of the wall slice on the screen based on the distance to the wall.
 *  - buffer_pixel_texture(data, &dda, &ray):
 *      Samples the correct pixels from the texture and stores them in the buffer to be drawn to the screen.
 */

void	ray_casting(t_data *data)
{
	t_ray	ray;
	t_dda	dda;

	ray.index = 0;
	while (ray.index < WIDTH)
	{
		define_ray_dir(&ray, data);
		ft_dda(data, &ray, &dda);
		set_column_height(&ray);
		buffer_pixel_texture(data, &dda, &ray);
		ray.index++;
	}
}

/**
 * @brief 
 * 
 * @param ray 
 * @param data 
 */

static void	define_ray_dir(t_ray *ray, t_data *data)
{
	ray->camX = 2 * ray->index / (double) WIDTH -1;
	ray->ray_dir[Y] = data->coord->dir[Y] + (data->coord->plane[Y] * ray->camX);
	ray->ray_dir[X] = data->coord->dir[X] + (data->coord->plane[X] * ray->camX);
	ray->distance_wall = 0;
}

static void set_column_height(t_ray *ray)
{
	ray->line_height = (int) (HEIGHT / ray->distance_wall);
	ray->draw_start = (-ray->line_height / 2) + (HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = 	ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT -1;
}