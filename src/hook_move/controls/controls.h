/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:10:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:23:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

typedef struct s_data	t_data;

typedef struct s_ctrl
{
	int		x;
	int		y;
	char	**map;
}		t_ctrl;

typedef struct s_ctrl_rotate
{
	int		x;
	int		y;
	double	dir;
	double	pla;
}		t_rotate;

/**
 * @brief Updates the player's position on the X and Y axes based on user input.
 * 
 * This function handles the movement logic when the player
 * presses a movement key, specifically the key mapped to 
 * moving forward in the game world.
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
int	muve_up(t_data *data);

/**
 * @brief Updates the player's position on the X and Y axes based on user input.
 *
 * This function handles the movement logic when the player
 * presses a movement key, specifically the key mapped to
 * moving backwards in the game world.
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
 * 				coordinates and execute the updated rendering.
 */
int	muve_down(t_data *data);

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
int	muve_left(t_data *data);

/**
 * @brief Updates the player's position on the X and Y axes based on user input.
 * 
 * This function handles the movement logic when the player
 * presses a movement key, specifically the key mapped to 
 * moving rightward in the game world.
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
int	muve_right(t_data *data);

/**
 * @brief Updates the player's direction and
 * 		  camera plane when rotating to the left.
 * 
 * This function handles the logic needed to
 * rotate the player's view to the left.
 * When called, it updates both the directionvector and the camera plane,
 * ensuring the player's perspective in the game world is correctly adjusted.
 * 
 * @param data A pointer to the main game data structure (t_data).
 *  
 * The following attributes are updated within this function:
 *  - data->coord->dir[X]:
 * 	Controls the horizontal component of the player's direction vector,
 *	which affects the player's viewing angle along the east-west axis.
 *  - data->coord->dir[Y]:
 *  Controls the vertical component of the player's direction vector,
 * 	which affects the player's viewing angle along the north-south axis.
 *  - data->coord->plane[](Y or X):
 *  Define the camera plane, which is perpendicular to the direction vector.
 * 	This plane is crucial for determining the field of view (FOV)
 * 	and correctly rendering the 3D perspective on the 2D screen.
 * 
 * The auxiliary functions:
 * 	- rotate_dir(data):
 * 		Calculates and updates the direction vector.
 *	- rotate_plane(data);
 * 		Calculates and updates the plane vector.
 * 
 * @return int The return is to signal an update in the
 * 			   coordinates and execute the updated rendering.
 */
int	rotate_cam_left(t_data *data);

/**
 * @brief Updates the player's direction and
 * 		  camera plane when rotating to the right.
 *
 * This function handles the logic needed 
 * to rotate the player's view to the right.
 * When called, it updates both the direction vector and the camera plane,
 * ensuring the player's perspective in the game world is correctly adjusted.
 *
 * @param data A pointer to the main game data structure (t_data).
 *
 * The following attributes are updated within this function:
 * - data->coord->dir[X]:
 * 	Controls the horizontal component of the player's direction vector,
 *	which affects the player's viewing angle along the east-west axis.
 *  - data->coord->dir[Y]:
 *  Controls the vertical component of the player's direction vector,
 * 	which affects the player's viewing angle along the north-south axis.
 * - data->coord->plane[](Y or X):
 *   Define the camera plane, which is perpendicular to the direction vector.
 * 	This plane is crucial for determining the field of view (FOV)
 * 	and correctly rendering the 3D perspective on the 2D screen.
 *
 * @return int The return is to signal an update in the
 * 		   coordinates and execute the updated rendering.
 */
int	rotate_cam_right(t_data *data);

#endif