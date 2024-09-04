/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:54:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:45:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# define COLLIDED 1
# define DID_NOT_COLLIDE 0
# define EMPTY_SPACE '0'

typedef struct s_data			t_data;
typedef struct s_ray_casting	t_ray;

enum e_side
{
	NORTH_UP = -1,
	SOUTH_DOWN = 1,
	WEST_LEFT = -1,
	EAST_RIGHT = 1,
};

typedef struct s_dda
{
	int		hit;
	int		side;
	int		step[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
}		t_dda;

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
void	ft_dda(t_data *data, t_ray *ray, t_dda *dda);

/**
 * @brief Determine the side to travel on the 2d map
 * 
 * This function initializes the control variables for both the X and Y axes,
 * allowing the DDA algorithm to correctly determine
 * the direction to move in the grid based on the ray's direction.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * 
 * 	- y_axis(data, dda, ray): 
 * 		Initializes the Y-axis control variables for traversal.
 * 	- x_axis(data, dda, ray): 
 * 		Initializes the X-axis control variables for traversal.
 */
void	side(t_data *data, t_dda *dda, t_ray *ray);

/**
 * @brief Traverse the 2D map until a collision is detected.
 *
 * This function continuously traverses the 2D map
 * in the direction specified by the ray,
 * updating the position on the map and
 * checkingfor collisions at each step.
 * Once a collision is detected, it calculates
 * the distance traveled by the ray
 * and determines the appropriate texture
 * to render for the corresponding wall.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable (t_ray).
 * @param dda Pointer to structure with dda algorithm variable (t_dda).
 * 
 * The main loop continues until a collision is detected, during which:
 *
 * 	- update_y_axis(dda, ray) and update_x_axis(dda, ray):
 * 	Update the position and side distances
 *  along the Y and X axes, respectively,
 * 	which controls the ray's movement across
 *  the 2D map and helps determine the texture.
 * 
 *  - check_collision(map[y][x]):
 * 	Checks if the current position on
 *  the map contains a wall or obstacle,
 * 	indicating a collision.
 * 
 *  - calculate_distance(dda, ray);
 * Calculates the distance the ray
 * traveled to the point of collision.
 */
void	find_collision(t_data *data, t_dda *dda, t_ray *ray);

#endif