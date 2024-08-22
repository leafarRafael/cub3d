/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:38:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/22 18:16:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "dda.h"
#include "defines.h"
#include <MLX42.h>
#include "libft.h"
#include <math.h>
#include "render_texture_image.h"

static unsigned int	rearrange_color(unsigned int argb);
static double define_wallX(t_data *data, t_ray *ray, t_dda *dda);
static void get_pixels_texture(t_dda *dda, t_ray *ray, t_data *data, int tex[2], int bufercolor[HEIGHT]);

int	buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray)
{
	double		wallX;
	int			tex[2];
	int			bufercolor[HEIGHT];

	if (data->worldmap[dda->map[Y]][dda->map[X]] != '0')
	{
		wallX = define_wallX(data,ray, dda);
		tex[X] = (int)(wallX * (double)data->window.wall[dda->side]->width);
		get_pixels_texture(dda, ray, data, tex, bufercolor);
		return (render_texture_on_image(data, ray, bufercolor));
	}
	return (0);
}

static void get_pixels_texture(t_dda *dda, t_ray *ray, t_data *data, int tex[2], int bufercolor[HEIGHT])
{
	uint32_t		color;
	int				h;
	double	 		step;
	double			texPos;
	mlx_texture_t	*text;

	text = data->window.wall[dda->side];
	h = data->window.wall[dda->side]->height;
	step = (double)text->height / ray->column_height;
	texPos = (ray->draw_start - HEIGHT / 2 + ray->column_height / 2) * step;
	for(int i  = ray->draw_start; i < ray->draw_end; i++)
	{
		tex[Y] = (int)texPos & (text->height -1);
		color = ((uint32_t*)text->pixels)[h * tex[Y] + tex[X]];
		bufercolor[i] = rearrange_color(color);
		texPos += step;
	}	
}

static double define_wallX(t_data *data, t_ray *ray, t_dda *dda)
{
	double		wallX;
	
	if(dda->side == NORTH || dda->side == SOUTH)
		wallX = data->coord->pos[X] + ray->distance_wall * ray->ray_dir[X];
	else
		wallX = data->coord->pos[Y] + ray->distance_wall * ray->ray_dir[Y];
	wallX -= floor(wallX);
	return (wallX); 
}

static unsigned int	rearrange_color(unsigned int argb)
{
	unsigned int	blue;
	unsigned int	green;
	unsigned int	red;
	unsigned int	alpha;

	blue = (argb & 0xFF) << 24;
	green = (argb & 0xFF00) << 8;
	red = (argb & 0xFF0000) >> 8;
	alpha = (argb & 0xFF000000) >> 24;
	return (blue | green | red | alpha);
}