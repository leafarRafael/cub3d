/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:38:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 10:03:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include "defines.h"
#include <math.h>
#include "render_texture_image.h"
#include "pixels_texture.h"

static int	get_coordinate_x_text(t_data *data, t_ray *ray, t_dda *dda);
static void	calc_coord_tex(t_data *data, t_dda *dda, t_ray *ray, t_text *pix);
static void	get_color_buffer(t_ray *ray, t_text *pix);

void	buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray)
{
	t_text	pixel;

	if (data->worldmap[dda->map[Y]][dda->map[X]] != '0')
	{
		calc_coord_tex(data, dda, ray, &pixel);
		get_color_buffer(ray, &pixel);
		render_texture_on_image(data, ray, pixel.buffer);
	}
}

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
		pix->buffer[i] = rearrange_color(color);
		pix->texPos += pix->step;
		i++;
	}
}