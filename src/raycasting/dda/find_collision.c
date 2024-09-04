/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:54:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:41:33 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"
#include "data.h"
#include "ray_casting.h"
#include "defines.h"

static void	calculate_distance(t_dda *dda, t_ray *ray);
static void	update_x_axis(t_dda *dda, t_ray *ray);
static void	update_y_axis(t_dda *dda, t_ray *ray);
static int	check_collision(char c);

void	find_collision(t_data *data, t_dda *dda, t_ray *ray)
{
	char	**map;
	int		y;
	int		x;

	while (dda->hit == DID_NOT_COLLIDE)
	{
		if (dda->side_dist[Y] < dda->side_dist[X])
			update_y_axis(dda, ray);
		else
			update_x_axis(dda, ray);
		map = data->worldmap;
		y = dda->map[Y];
		x = dda->map[X];
		dda->hit = check_collision(map[y][x]);
	}
	calculate_distance(dda, ray);
}

/**
 * @brief Update the X-axis position and manage
 * 		  textures for east and west sides.
 * 
 * This function increments or decrements the player's
 * position on the X-axis based on the ray's direction.
 * 
 * It also updates the side distance along the X-axis
 * and determines whether the collision occurred
 * on the east or west side of a wall,
 * which is used to select the correct texture.
 * 
 * @param ray Pointer to the structure containing
 * 			  raycasting algorithm variables (t_ray).
 * 
 * @param dda Pointer to the structure containing
 *            DDA algorithm variables (t_dda).
 * 
 * 	- dda->map[X]:
 * 	Updates the player's position on the 2D map along
 *  the X-axis by incrementing or decrementing 
 * 	based on the ray's direction.
 * 
 * 	- dda->side_dist[X]:
 * 	Increases the distance from the player's
 *  position to the next X-axis grid line
 * 	in proportion to the ray's movement across the 2D map.
 * 
 * 	- dda->side:
 * 	Sets the side (east or west) based on the ray's direction,
 *  which is used to determine the texture.
 */
static void	update_x_axis(t_dda *dda, t_ray *ray)
{
	dda->map[X] += dda->step[X];
	dda->side_dist[X] += dda->delta_dist[X];
	if (ray->ray_dir[X] < 0)
		dda->side = WEST;
	else
		dda->side = EAST;
}

/**
 * @brief Update the Y-axis position and manage
 *    	  textures for north and south sides.
 * 
 * This function increments or decrements the player's
 * position on the Y-axis based on the ray's direction.
 * It also updates the side distance along the Y-axis and
 * determines whether the collision occurred
 * on the north or south side of a wall,
 * which is used to select the correct texture.
 * 
 * @param ray Pointer to the structure containing 
 * 			  raycasting algorithm variables (t_ray).
 * 
 * @param dda Pointer to the structure containing
 *     		  DDA algorithm variables (t_dda).
 * 
 * 	- dda->map[Y]:
 * 	Updates the player's position on the 2D map
 *  along the Y-axis by incrementing or decrementing 
 * 	based on the ray's direction.
 * 
 * 	- dda->side_dist[Y]:
 * 	Increases the distance from the player's position
 *  to the next Y-axis grid line
 * 	in proportion to the ray's movement across the 2D map.
 * 
 * 	- dda->side:
 * 	Sets the side (north or south) based on the ray's direction,
 *  which is used to determine the texture.
 */
static void	update_y_axis(t_dda *dda, t_ray *ray)
{
	dda->map[Y] += dda->step[Y];
	dda->side_dist[Y] += dda->delta_dist[Y];
	if (ray->ray_dir[Y] < 0)
		dda->side = NORTH;
	else
		dda->side = SOUTH;
}

/**
 * @brief Calculate the distance traveled by the ray.
 * 
 * This function calculates the distance from the
 * player to the point of collision based on which
 * axis (X or Y) the collision occurred.
 * The calculated distance is stored in the ray structure
 * and used for rendering the correct size of the wall slice.
 * 
 * @param ray Pointer to the structure containing
 * 			  raycasting algorithm variables (t_ray).
 * 
 * @param dda Pointer to the structure containing
 *     		  DDA algorithm variables (t_dda).
 * 
 * If the collision occurred on the X-axis,
 * the distance is calculated using side_dist[X] - delta_dist[X].
 * If the collision occurred on the Y-axis,
 * it is calculated using side_dist[Y] - delta_dist[Y].
 */
static int	check_collision(char c)
{
	if (c != EMPTY_SPACE)
		return (COLLIDED);
	return (DID_NOT_COLLIDE);
}

/**
 * @brief Assigns the calculation of the distance traveled.
 * 
 * @param ray Pointer to structure with
 * 			  raycasting algorithm variable (t_ray).
 * 
 * @param dda Pointer to structure with dda algorithm variable (t_dda).
 * 
 * If the axis where the collision occurred was X, then ray->distance_wal
 * receives the subtraction between side_dist[X] and delta_dist[X], 
 * otherwise side_dist[Y] and delta_dist[Y].
 */
static void	calculate_distance(t_dda *dda, t_ray *ray)
{
	if (dda->side == WEST || dda->side == EAST)
		ray->distance_wall = dda->side_dist[X] - dda->delta_dist[X];
	else
		ray->distance_wall = dda->side_dist[Y] - dda->delta_dist[Y];
}
