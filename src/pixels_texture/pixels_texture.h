/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_texture.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:54:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/07 11:14:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXELS_TEXTURE_H
# define PIXELS_TEXTURE_H

typedef struct s_ray_casting	t_ray;
typedef struct s_data			t_data;
typedef struct s_dda			t_dda;

typedef struct s_coord_texture
{
	int			buffer[HEIGHT];
	int			tex[2];
	int			width;
	int			height;
	uint8_t		*pixels;
	long double	step;
	long double	texpos;
}	t_text;

/**
 * @brief Selects texture pixels for column rendering.
 *
 * This function identifies the texture
 * pixel data corresponding to the wall
 * section being rendered, ensuring that
 * the correct part of the texture is
 * displayed for each column of the wall.
 *
 * @param data A pointer to the main game data structure (t_data).
 * @param ray Pointer to structure with raycasting algorithm variable.
 * @param dda Pointer to structure with dda algorithm variable.
 *
 * If the current map position is not empty:
 * - calc_coord_tex(data, dda, ray, &pixel):
 *  Calculates the texture coordinates
 *  for the pixels that will be rendered.
 *
 *  - get_color_buffer(ray, &pixel):
 * Retrieves the color data for the
 * corresponding pixels in the texture buffer.
 **/
void			buffer_pixel_texture(t_data *data, t_dda *dda, t_ray *ray);

/**
 * @brief Arranges the color components of an ARGB value.
 *
 * This function takes a 32-bit unsigned integer representing a color
 * in ARGB format and arranges the components into a new order:
 * Blue, Green, Red, Alpha.
 *
 * @param argb The input color value in ARGB.
 * @return unsigned int The arranged color value with the order BGRA.
 */
unsigned int	arrange_color(unsigned int argb);

#endif