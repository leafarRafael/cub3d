/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:16:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 14:07:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "defines.h"
#include "utils.h"

static void	set_coords(t_data *data);
static int	set_direction(double dir[2], char c);
static void	set_vector_rotation_cam_plane(double plane[2], double dir[2]);

void	set_player(t_data *data)
{
	set_coords(data);
	set_direction(data->coord->dir, data->identifier);
	set_vector_rotation_cam_plane(data->coord->plane, data->coord->dir);
}

/**
 * @brief Sets the initial player position in a 2D map
 *
 * This function initializes the player's
 * position on the X and Y axes based on the 
 * provided coordinates.
 * 
 * @param pos A 2-element array where the player's X
 * 			  and Y coordinates will be stored.
 * 	pos[Y] stores the Y-axis position.
 * 	pos[X] stores the X-axis position.
 * 
 * @param y the Y-axis position in the 2D map 
 * @param x the X-axis position in the 2D map
 */
static void	set_coords(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = data->worldmap;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_coord(map[y][x]))
			{
				data->coord->pos[X] = (double)x + 0.5;
				data->coord->pos[Y] = (double)y + 0.5;
				data->identifier = map[y][x];
				map[y][x] = '0';
				return ;
			}
			x += 1;
		}
		y += 1;
	}
}

/**
 * @brief Determines the initial direction the player is facing.
 * 
 * Based on the provided character,
 * this function sets the player's initial direction
 * vector. The direction is represented by
 * the X and Y components of the vector.
 *
 * @param dir A 2-element array where the direction vector will be stored.
 * 		dir[Y] and dir[X] components determine the direction.
 * @param c 
 * 'N' for North = (dir[Y] = -1,	dir[X] = 0)
 * 'S' for Sout  = (dir[Y] = 1,	dir[X] = 0)
 * 'W' for West  = (dir[Y] = 0,	dir[X] = -1)
 * 'A' for EAST  = (dir[Y] = 0,	dir[X] = 1)
 * 
 * @return int SUCCESS if valid direction, ERROR otherwise
 */
static int	set_direction(double dir[2], char c)
{
	if (c != 'W' && c != 'E' && c != 'N' && c != 'S')
		return (ERROR);
	if (c == 'W')
	{
		dir[Y] = 0;
		dir[X] = -1;
	}
	else if (c == 'E')
	{
		dir[Y] = 0;
		dir[X] = 1;
	}
	else if (c == 'N')
	{
		dir[Y] = -1;
		dir[X] = 0;
	}
	else if (c == 'S')
	{
		dir[Y] = 1;
		dir[X] = 0;
	}
	return (SUCCESS);
}

/**
 * @brief Calculates the camera plane vector for field of view rotation.
 * 
 * This function determines the camera plane vector,
 * which is perpendicular to the player's direction vector.
 * The plane vector is used to calculate the player's 
 * field of view (FOV) rotation, which affects how the scene is rendered.
 * 
 * @param plane A 2-element array where the camera plane vector will be stored.
 * 	plane[Y] stores the Y-axis component.
 * 	plane[X] stores the X-axis component.
 * 
 * @param dir The direction vector representing where the player is looking.
 * 	dir[X] and dir[Y] are used to calculate the plane vector.
 */
static void	set_vector_rotation_cam_plane(double plane[2], double dir[2])
{
	plane[Y] = dir[X] * FOV;
	plane[X] = -dir[Y] * FOV;
}
