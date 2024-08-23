/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 07:46:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include <math.h>
#include "controls.h"
#include "render_ceiling_floor.h"
#include "ray_casting.h"

static void	muve_axis_y(t_data *data);
static void	muve_axis_x(t_data *data);

/**
 * @brief Updates the player's position on the X and Y axes based on user input.
 * 
 * This function handles the movement logic when the player
 * presses a movement key, specifically the key mapped to 
 * moving leftward in the game world.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * 
 * The following attributes are utilized or updated within this function:
 *  - data->worldmap: 
 *      Used to validate collisions before updating the player's position.
 *  - data->coord->pos[Y]: 
 *      Updates the player's Y-coordinate on the map.
 *  - data->coord->pos[X]: 
 *      Updates the player's X-coordinate on the map.
 *  - data->coord->dir[](Y or X): 
 *      Used to determine the direction the player is facing for movement.
 * 
 * @return int The return is to signal an update in the
 * 			   coordinates and execute the updated rendering.
 */
int	muve_left(t_data *data)
{
	muve_axis_x(data);
	muve_axis_y(data);
	return (1);
}

/**
 * @brief Updates the player's Y-axis coordinate, considering collisions.
 * 
 * This function checks for possible collisions before updating the player's
 * Y-axis position.
 * If the space ahead is free (represented as '0' on the 2d map),
 * the player's Y coordinate will be updated.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * 
 * The function first checks whether the position update is valid:
 * This is done by checking the player's positional vector
 * (using only the integer part of the Y and X axis) relative to the 2D map. 
 * If the content of `map[y][x]` is '0', the position is valid.
 *  
 * The variable `data->coord->pos[Y]` is then updated by subtracting
 * the product of the player's plane on the Y axis and MOVE_SPEED (0.05).
 * Depending on the plane the player is facing, this operation can result 
 * in an increase or decrease in the Y positional axis.
 * 
 * */
static void	muve_axis_y(t_data *data)
{
	t_ctrl	c;

	c.x = (int)(data->coord->pos[X]);
	c.y = (int)(data->coord->pos[Y] - data->coord->plane[Y] * MOVE_SPPED);
	c.map = data->worldmap;
	if (c.map[c.y][c.x] == '0')
		data->coord->pos[Y] -= data->coord->plane[Y] * MOVE_SPPED;
}

/**
 * @brief Updates the player's X-axis coordinate, considering collisions.
 * 
 * This function checks for possible collisions before updating the player's
 * X-axis position.
 * If the space ahead is free (represented as '0' on the 2d map),
 * the player's Y coordinate will be updated.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * 
 * The function first checks whether the position update is valid:
 * This is done by checking the player's positional vector
 * (using only the integer part of the Y and X axis) relative to the 2D map. 
 * If the content of `map[y][x]` is '0', the position is valid.
 *  
 * The variable `data->coord->pos[X]` is then updated by subtracting
 * the product of the player's plane on the X axis and MOVE_SPEED (0.05).
 * Depending on the plane the player is facing, this operation can result 
 * in an increase or decrease in the X positional axis.
 * 
 * */
static void	muve_axis_x(t_data *data)
{
	t_ctrl	c;

	c.x = (int)(data->coord->pos[X] - data->coord->plane[X] * MOVE_SPPED);
	c.y = (int)data->coord->pos[Y];
	c.map = data->worldmap;
	if (c.map[c.y][c.x] == '0')
		data->coord->pos[X] -= data->coord->plane[X] * MOVE_SPPED;
}
