/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/05 16:11:35 by rbutzke          ###   ########.fr       */
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

int	rotate_cam_left(t_data *data)
{
	rotate_dir(data);
	rotate_plane(data);
	return (1);
}

/**
 * @brief Rotates the player's direction vector to the left.
 * 
 * This function applies a rotation matrix to the player's direction vector,
 * changing the angle at which the player is facing. It effectively rotates
 * the player's view within the game world, adjusting the direction in which
 * the player is looking.
 *
 * @param data A pointer to the main game data structure (t_data).
 *
 * To update, we first create some temporary variables:
 * 	- old_dir_y:
 * 	Is the value of Y before the update,
 *  (it will be used to calculate the X axis).
 *
 * - cos_dir[] and sin_dir[]:
 * 	Is the multiplication of the corresponding axis (Y or X)
 *  by the cosine and sine of ROT_SPEED.
 *
 * Then the Y and X axis of the direction are updated: 
 * 	- data->coord->dir[Y]:
 * 	With the subtraction between cos_dir[Y] - sin_dir[X].
 * 
 * 	- data->coord->dir[X]:
 * 	With the sum between sin_dir[Y] + cos_dir[X].
 **/
static void	rotate_dir(t_data *data)
{
	long double	old_dir_y;
	long double	cos_dir[2];
	long double	sin_dir[2];

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
 *  Is the value of Y before the update,
 *  (it will be used to calculate the X axis).
 * 	- cos_plane[] and sin_plane[2]:
 * 	Is the multiplication of the corresponding axis (Y or X)
 *  by the cosine and sine of ROT_SPEED.
 * 
 * Then the Y and X axis of the direction are updated: 
 * 	- data->coord->plane[Y]:
 * 		With the subtraction between cos_dir[Y] - sin_dir[X].
 * 	- data->coord->plane[X]:
 * 		With the sum between sin_dir[Y] + cos_dir[X].
 * */
static void	rotate_plane(t_data *data)
{
	long double	cos_plane[2];
	long double	sin_plane[2];
	long double	old_plane_y;

	old_plane_y = data->coord->plane[Y];
	sin_plane[Y] = old_plane_y * sin(ROT_SPEED);
	cos_plane[Y] = data->coord->plane[Y] * cos(ROT_SPEED);
	sin_plane[X] = data->coord->plane[X] * sin(ROT_SPEED);
	cos_plane[X] = data->coord->plane[X] * cos(ROT_SPEED);
	data->coord->plane[Y] = cos_plane[Y] - sin_plane[X];
	data->coord->plane[X] = sin_plane[Y] + cos_plane[X];
}
