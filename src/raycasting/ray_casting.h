/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:58:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/07 11:13:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "defines.h"

typedef struct s_ray_casting
{
	int			index;
	int			buffer[HEIGHT];
	long double	ray_dir[2];
	long double	distance_wall;
	int			column_height;
	int			draw_start;
	int			draw_end;
}		t_ray;

/**
 * @brief Render the 2d game image with 3d perspective using raycasting.
 * 
 * This function implements the raycasting
 * algorithm to render a 3D view from a 2D map.
 * It works by iterating through each vertical stripe
 * of the screen (represented by the image width),
 * casting a ray from the player's position through
 * the screen's plane in the direction the player is facing.
 * The function calculates the distance to the nearest wall along each ray, 
 * determines the height of the wall to be rendered,
 * and then samples the appropriate texture
 * for that wall segment.
 *
 * @param data A pointer to the main game data structure (t_data).
 * 
 * Steps involved:
 *  - define_ray_dir(&ray, data):
 *  Determines the direction of the current ray
 *  based on the player's direction and camera plane.
 * 
 *  - ft_dda(data, &ray, &dda):
 *  Performs the Digital Differential Analysis (DDA) algorithm
 *  to find the point of collision with a wall on the 2D map.
 *  Also determines the appropriate texture to use for the wall.
 * 
 *  - set_column_height(&ray):
 *  Calculates the start and end positions of the wall 
 *  slice on the screen based on the distance to the wall.
 * 
 *  - buffer_pixel_texture(data, &dda, &ray):
 *  Samples the correct pixels from the texture and stores
 *  them in the buffer to be drawn to the screen.
 * 
 * 	- render_texture_on_image(data, &ray, ray.buffer):
 * 	Renders an image with texture pixels.
 *
 */
void	ray_casting(t_data *data);

#endif