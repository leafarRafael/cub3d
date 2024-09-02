/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:38:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/02 09:46:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include "defines.h"
#include <math.h>
#include "pixels_texture.h"
#include "error_handler.h"

static int	get_coordinate_x_text(t_data *data, t_ray *ray, t_dda *dda);
static void	calc_coord_tex(t_data *data, t_dda *dda, t_ray *ray, t_text *pix);
static void	get_color_buffer(t_ray *ray, t_text *pix);

/**
 * @brief Selects texture pixels for column rendering.
 * 
 * This function identifies the texture pixel data corresponding to the wall 
 * section being rendered, ensuring that the correct part of the texture is 
 * displayed for each column of the wall.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * 
 * If the current map position is not empty:
 *  - calc_coord_tex(data, dda, ray, &pixel):
 *    Calculates the texture coordinates for the pixels that will be rendered.
 *  
 *  - get_color_buffer(ray, &pixel):
 *    Retrieves the color data for the corresponding pixels in the texture buffer.
 * 
 */
void	buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray)
{
	t_text	pixel;

	if (data->worldmap[dda->map[Y]][dda->map[X]] != EMPTY_SPACE)
	{
		calc_coord_tex(data, dda, ray, &pixel);
		get_color_buffer(ray, &pixel);
	}
}

/**
 * @brief Calculates the coordinate of the texture that will be rendered.
 * 
 * This function computes the vertical texture coordinate (Y-axis) and sets up 
 * the necessary parameters for rendering the correct part of the texture on 
 * the screen, ensuring the texture is proportionally mapped to the wall height.
 * 
 * @param data A pointer to the main game data structure.
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 * @param pix Pointer to the pixels structure, which contains some control variables.
 */
static void	calc_coord_tex(t_data *data, t_dda *dda, t_ray *ray, t_text *pix)
{
	int	pos_height;
	int	size_height;
	
	pix->height = data->window.wall[dda->side]->height;
	pix->width = data->window.wall[dda->side]->width;
	pix->pixels = data->window.wall[dda->side]->pixels;
	pos_height = ray->draw_start - HEIGHT_2;
	size_height = ray->column_height / 2;
	pix->step = (double)pix->height / ray->column_height;
	pix->texPos = (pos_height + size_height) * pix->step;	
	pix->tex[X] = get_coordinate_x_text(data, ray, dda);
}

/**
 * @brief Computes the X coordinate of the texture for the wall.
 * 
 * Based on the wall's position and orientation, this function calculates the 
 * horizontal texture coordinate (X-axis) to ensure the texture is correctly 
 * aligned with the wall section being rendered.
 * 
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variables.
 * @param dda Pointer to structure with dda algorithm variables.
 * @return int The X coordinate in the texture.
 * 
 * 
 */
static int	get_coordinate_x_text(t_data *data, t_ray *ray, t_dda *dda)
{
	double	distance[2];
	double	wall;
	int		pos_x;
	double	width;

	distance[X] = ray->distance_wall * ray->ray_dir[X];
	distance[Y] = ray->distance_wall * ray->ray_dir[Y];	
	width = (double)data->window.wall[dda->side]->width;
	if(dda->side == NORTH || dda->side == SOUTH)
		wall = data->coord->pos[X] + distance[X];
	else
		wall = data->coord->pos[Y] + distance[Y];
	wall -= floor(wall);
	pos_x = (int)(wall * width);
	return (pos_x); 
}

/**
 * @brief Fills the color buffer with texture data.
 * 
 * This function copies the pixel data from the texture buffer into the screen's 
 * color buffer, applying the necessary transformations to match the screen's 
 * resolution and aspect ratio.
 * 
 * @param ray Pointer to structure with raycasting algorithm variables.
 * @param pix Pointer to the pixels structure, which contains some control variables.
 * 
 * 
 */
static void	get_color_buffer(t_ray *ray, t_text *pix)
{
	int	color;
	int	index;
	int i;

	color = 0;
	index = 0;
	i = ray->draw_start;
	while(i < ray->draw_end)
	{
		pix->tex[Y] = (int)pix->texPos & (pix->height -1);
		index = pix->height * pix->tex[Y] + pix->tex[X];
		color = ((uint32_t*)pix->pixels)[index];
		ray->buffer[i] = arrange_color(color);
		pix->texPos += pix->step;
		i++;
	}
}