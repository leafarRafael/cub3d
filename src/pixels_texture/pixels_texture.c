/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:38:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/20 08:07:21 by rbutzke          ###   ########.fr       */
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

int	buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray)
{
	uint32_t	color;
	double		wallX;
	double	 	step;
	double 		texPos;
	int 		texY;
	int			texX;
	int			bufercolor[HEIGHT];
	int			h;

	if (data->worldmap[dda->map[Y]][dda->map[X]] != '0')
	{
		if(dda->side == NORTH || dda->side == SOUTH)
			wallX = data->coord->pos[X] + (ray->distance_wall * ray->ray_dir[X]);
		else
			wallX = data->coord->pos[Y] + ray->distance_wall * ray->ray_dir[Y];
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)data->window.wall[dda->side]->width);
		step = 1.0 * data->window.wall[dda->side]->height / ray->line_height;
		texPos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
		for(int i  = ray->draw_start; i < ray->draw_end; i++)
		{
			texY = (int)texPos & (data->window.wall[dda->side]->height -1);
			texPos += step;
			h = data->window.wall[dda->side]->height;
			color = ((uint32_t*)data->window.wall[dda->side]->pixels)[h * texY + texX];
			bufercolor[i] = rearrange_color(color);
		}
	}
	return (render_texture_on_image(data, ray, bufercolor));
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