/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/20 15:12:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "data.h"
#include "defines.h"
#include <math.h>

static void	rotate_dir(t_data *data);
static void	rotate_plane(t_data *data);

/**
 * @brief Updates the player's direction and camera plane when rotating to the right.
 * 
 * This function handles the logic needed to rotate the player's view to the right. 
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
 */
void	rotate_cam_right(t_data *data)
{
	rotate_dir(data);
	rotate_plane(data);
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
 * 
 * */
static void	rotate_dir(t_data *data)
{
	double	dir;
	double	diry_cos;
	double	dirx_cos;
	double	dirx_sin;

	dir = data->coord->dir[Y];
	diry_cos = data->coord->dir[Y] * cos(-ROT_SPEED);
	dirx_sin = data->coord->dir[X] * sin(-ROT_SPEED);
	data->coord->dir[Y] = diry_cos - dirx_sin;
	dirx_sin = dir * sin(-ROT_SPEED);
	dirx_cos = data->coord->dir[X] * cos(-ROT_SPEED);
	data->coord->dir[X] = dirx_sin + dirx_cos;
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
 * 
 * */
static void	rotate_plane(t_data *data)
{
	double	pl;
	double	plny_cos;
	double	plnx_cos;
	double	plnx_sin;

	pl = data->coord->plane[Y];
	plny_cos = data->coord->plane[Y] * cos(-ROT_SPEED);
	plnx_sin = data->coord->plane[X] * sin(-ROT_SPEED);
	data->coord->plane[Y] = plny_cos - plnx_sin;
	plnx_cos = data->coord->plane[X] * cos(-ROT_SPEED);
	data->coord->plane[X] = pl * sin(-ROT_SPEED) + plnx_cos;
}
