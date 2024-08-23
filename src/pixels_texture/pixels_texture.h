/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:54:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 09:58:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXELS_TEXTURE_H
 #define PIXELS_TEXTURE_H

typedef struct s_ray_casting t_ray;
typedef struct s_data t_data;
typedef struct s_dda t_dda;

typedef struct s_coord_texture
{
	int				buffer[HEIGHT];
	int				tex[2];
	int				width;
	int				height;
	uint8_t			*pixels;
	double	 		step;
	double			texPos;
}	t_text;

void			buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray);
unsigned int	rearrange_color(unsigned int argb);

#endif