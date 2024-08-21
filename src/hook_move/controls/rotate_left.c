/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/21 13:55:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include <math.h>
#include "render_ceiling_floor.h"
#include "ray_casting.h"
#include <stdio.h>

static void	rotate_dir(t_data *data);
static void	rotate_plane(t_data *data);

/**
 * @brief Updates the player's direction and camera plane when rotating to the left.
 * 
 * This function handles the logic needed to rotate the player's view to the left.
 * When called, it updates both the direction vector and the camera plane,
 * ensuring the player's perspective in the game world is correctly adjusted.
 * 
 * @param data A pointer to the main game data structure (t_data).
 *  
 * The following attributes are updated within this function:
 *  - data->coord->dir[X]:
 * 		Controls the horizontal component of the player's direction vector,
 *		which affects the player's viewing angle along the east-west axis.
 *  - data->coord->dir[Y]:
 *      Controls the vertical component of the player's direction vector,
 * 		which affects the player's viewing angle along the north-south axis.
 *  - data->coord->plane[](Y or X):
 *      Define the camera plane, which is perpendicular to the direction vector.
 * 		This plane is crucial for determining the field of view (FOV)
 * 		and correctly rendering the 3D perspective on the 2D screen.
 * 
 * The auxiliary functions:
 * 	- rotate_dir(data):
 * 		Calculates and updates the direction vector.
 *	- rotate_plane(data);
 * 		Calculates and updates the plane vector.
 *  - render_ceiling_floor(data):
 * 		Renders the ceiling and floor based on the updated data.
 * 	- ray_casting(data):
 * 		Performs raycasting to render the game image with the new data.
 */
void	rotate_cam_left(t_data *data)
{
	rotate_dir(data);
	rotate_plane(data);
	render_ceiling_floor(data);
	ray_casting(data);
}

/**
 * @brief Rotates the player's direction vector to the left.
 * 
 * This function applies a rotation matrix to the player's direction vector,
 * changing the angle at which the player is facing. It effectively rotates
 * the player's view within the game world, adjusting the direction in which
 * the player is looking.
 * 
 * 
 * @param data A pointer to the main game data structure (t_data).
 * 
 * To update, we first create some temporary variables:
 * 
 * 	- old_dir_y:
 * 		Is the value of Y before the update, (it will be used to calculate the X axis).
 * 	- cos_dir[] and sin_dir[]:
 * 		Is the multiplication of the corresponding axis (Y or X) by the cosine and sine of ROT_SPEED.
 * 
 * Then the Y and X axis of the direction are updated: 
 * 	- data->coord->dir[Y]:
 * 		With the subtraction between cos_dir[Y] - sin_dir[X].
 * 	- data->coord->dir[X]:
 * 		With the sum between sin_dir[Y] + cos_dir[X].
 **/

static void	rotate_dir(t_data *data)
{
	double	old_dir_y;
	double	cos_dir[2];
	double	sin_dir[2];

	old_dir_y = data->coord->dir[Y];
	sin_dir[Y] = old_dir_y * sin(ROT_SPEED);
	cos_dir[X] = data->coord->dir[X] * cos(ROT_SPEED);
	cos_dir[Y] = data->coord->dir[Y] * cos(ROT_SPEED);
	sin_dir[X] = data->coord->dir[X] * sin(ROT_SPEED);
	data->coord->dir[Y] = cos_dir[Y] - sin_dir[X];
	data->coord->dir[X] = sin_dir[Y] + cos_dir[X];
}

/**
 * @brief Rotates the player's camera plane to the left.
 * 
 * This function adjusts the player's camera plane, which is necessary
 * for maintaining the correct field of view after the player's direction
 * has been rotated. The camera plane defines the part of the world that
 * is visible on the screen and is always perpendicular to the direction vector.
 *   
 * @param data A pointer to the main game data structure (t_data).
 * 
 * To update, we first create some temporary variables:
 * 
 * 	- old_plane_y:
 * 		Is the value of Y before the update, (it will be used to calculate the X axis).
 * 	- cos_plane[] and sin_plane[2]:
 * 		Is the multiplication of the corresponding axis (Y or X) by the cosine and sine of ROT_SPEED.
 * 
 * Then the Y and X axis of the direction are updated: 
 * 	- data->coord->plane[Y]:
 * 		With the subtraction between cos_dir[Y] - sin_dir[X].
 * 	- data->coord->plane[X]:
 * 		With the sum between sin_dir[Y] + cos_dir[X].
 * */
static void	rotate_plane(t_data *data)
{
	double	cos_plane[2];
	double	sin_plane[2];
	double	old_plane_y;

	old_plane_y = data->coord->plane[Y];
	sin_plane[Y] = old_plane_y * sin(ROT_SPEED);
	cos_plane[Y] = data->coord->plane[Y] * cos(ROT_SPEED);
	sin_plane[X] = data->coord->plane[X] * sin(ROT_SPEED);
	cos_plane[X] = data->coord->plane[X] * cos(ROT_SPEED);
	data->coord->plane[Y] = cos_plane[Y] - sin_plane[X];
	data->coord->plane[X] = sin_plane[Y] + cos_plane[X];
}
