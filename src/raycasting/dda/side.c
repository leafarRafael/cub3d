/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:33:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:43:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "data.h"
#include "ray_casting.h"
#include "defines.h"

static void	y_axis(t_data *data, t_dda *dda, t_ray *ray);
static void	x_axis(t_data *data, t_dda *dda, t_ray *ray);

void	side(t_data *data, t_dda *dda, t_ray *ray)
{
	y_axis(data, dda, ray);
	x_axis(data, dda, ray);
}

/**
 * @brief Initializes the Y-axis control variables
 * 
 * This function sets up the necessary variables
 * to control movement along the Y-axis.
 * It determines whether the ray is moving up
 * (north) or down (south) on the map,
 * and calculates the initial distance to
 * the first grid intersection along the Y-axis.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * 
 * 	- traveled: 
 * 	The distance the player has traveled within the current
 *  grid square along the Y-axis.
 * 
 *  - dda->step[Y]:
 * 	Determines the direction of traversal on the 2D map:
 * 	positive for north (up) and negative for south (down).
 * 
 * 	- dda->side_dist[Y]:
 * 	Initializes the distance from the player's current position
 * 	to the next Y-axis grid line.
 * 	This value will be incremented as the DDA algorithm steps through the grid.
 * 
 */
static void	y_axis(t_data *data, t_dda *dda, t_ray *ray)
{
	double	traveled;

	if (ray->ray_dir[Y] < 0)
	{
		dda->step[Y] = NORTH_UP;
		traveled = data->coord->pos[Y] - dda->map[Y];
		dda->side_dist[Y] = traveled * dda->delta_dist[Y];
	}
	else
	{
		dda->step[Y] = SOUTH_DOWN;
		traveled = dda->map[Y] + 1.0 - data->coord->pos[Y];
		dda->side_dist[Y] = traveled * dda->delta_dist[Y];
	}
}

/**
 * @brief Initializes the X-axis control variables.
 * 
 * This function sets up the necessary variables
 * to control movement along the X-axis.
 * It determines whether the ray is moving
 * left (west) or right (east) on the map,
 * and calculates the initial distance to the
 * first grid intersection along the X-axis.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to the structure containing
 * 			  raycasting algorithm variables.
 * @param dda Pointer to the structure
 * 			  containing DDA algorithm variables.
 * 
 * 	- traveled: 
 * 	The distance the player has traveled within
 *  the current grid square along the X-axis.
 * 
 *  - dda->step[X]:
 * 	Determines the direction of traversal on the 2D map:
 * 	positive for east (right) and negative for west (left).
 * 
 * 	- dda->side_dist[X]:
 * 	Initializes the distance from the player's current
 *  position to the next X-axis grid line.
 * 	This value will be incremented as
 *  the DDA algorithm steps through the grid.
 */
static void	x_axis(t_data *data, t_dda *dda, t_ray *ray)
{
	double	traveled;

	if (ray->ray_dir[X] < 0)
	{
		dda->step[X] = WEST_LEFT;
		traveled = data->coord->pos[X] - dda->map[X];
		dda->side_dist[X] = traveled * dda->delta_dist[X];
	}
	else
	{
		dda->step[X] = EAST_RIGHT;
		traveled = dda->map[X] + 1.0 - data->coord->pos[X];
		dda->side_dist[X] = traveled * dda->delta_dist[X];
	}
}
