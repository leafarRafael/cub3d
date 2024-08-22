/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:16:53 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/22 13:36:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "data.h"
#include "ray_casting.h"
#include "defines.h"
#include <math.h>

static void	dda_variables(t_dda *dda, t_data *data, t_ray *ray);

/**
 * @brief Digital differential analysis (DDA) algorithm.
 * 
 * The dda algorithm works by traversing a map 2d in a specified
 * direction and from a given point to an occurrence.
 * By incrementing or decrementing on the Y and X axes,
 * we can determine direction, and the axis on which an event occurred.  
 * Used here to determine collision, distance and game textures.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * 
 * 	- dda_variables(t_dda *dda, t_data *data, t_ray *ray);
 *	Initializes the starting point, control and side of the collision.
 *	- side(data, dda, ray);
 *  Determine the side and angle we are traveling on the 2d map.
 * 	- find_collision(data, dda, ray);
 * 	Traverses the matrix, determines the distance and texture.
 */
void ft_dda(t_data *data, t_ray *ray, t_dda *dda)
{
	dda_variables(dda, data, ray);
	side(data, dda, ray);
	find_collision(data, dda, ray);
}

/**
 * @brief Initializes the starting point, control variables, and collision sides.
 * 
 * This function sets up the initial state for the DDA algorithm, 
 * including initializing the collision detection variable,
 * converting the player's position to map coordinates,
 * and calculating the proportional distance increments along the X and Y axes. 
 * This ensures that the DDA can correctly step through the
 * map to detect the nearest wall collision.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * 
 * 	- dda->hit:
 *  Controls the loop that runs through the 2D map, checking for collisions.
 * 	- dda->map[Y][X]:
 * 	This is the player's position on the map, converted from double to integer. 
 *  The conversion makes it easier to calculate the collision.
 * 	- dda->delta_dist[Y][X]:
 * 	This is the proportional increment between the window and the 2d map.
 *  Protected against division by zero.
 * */
static void	dda_variables(t_dda *dda, t_data *data, t_ray *ray)
{
	dda->hit = DID_NOT_COLLIDE;
	dda->map[Y] = (int)data->coord->pos[Y];
	dda->map[X] = (int)data->coord->pos[X];
	if (ray->ray_dir[Y] == 0)
		dda->delta_dist[Y] = INFINITY;
	else
		dda->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
	if (ray->ray_dir[X] == 0)
		dda->delta_dist[X] = INFINITY;
	else
		dda->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
}