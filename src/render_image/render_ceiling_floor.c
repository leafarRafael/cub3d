/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:17:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/22 20:32:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include "utils.h"
#include "data.h"
#include "libft.h"
#include "defines.h"

static void	render_pixel(int plaine[2],
				int pos[2], int color, mlx_image_t *image);
static void	define_value(int ptr[2], int value1, int value2);

/**
 * @brief Draw the ceiling and floor colors on the image.
 * 
 * This function fills the image buffer with the colors for the
 * ceiling and floor by dividing the screen into two sections.
 * The ceiling color is drawn on the upper half,
 * and the floor color is drawn on the lower half. The function uses the 
 * defined color values from the `data` structure to fill these areas.
 * 
 @param data A pointer to the main game data structure (`t_data`) that holds:
 *   rgb_cel: An array containing the RGBA values for the ceiling color.
 *   rgb_floor: An array containing the RGBA values for the floor color.
 *   window.image: The image buffer where the pixels will be drawn.
 */

void	render_ceiling_floor(t_data *data)
{
	int	color;
	int	plaine[2];
	int	pos[2];

	{
		define_value(pos, 0, 0);
		define_value(plaine, WIDTH, HEIGHT);
		color = ft_color(0, 0, 0, 0);
		render_pixel(plaine, pos, color, data->window.image);
	}
	{
		define_value(pos, 0, 0);
		define_value(plaine, WIDTH, HEIGHT / 2);
		color = ft_color(data->rgb_cel[0],
				data->rgb_cel[1], data->rgb_cel[2], data->rgb_cel[3]);
		render_pixel(plaine, pos, color, data->window.image);
	}
	{
		define_value(plaine, WIDTH, HEIGHT / 2);
		define_value(pos, 0, HEIGHT / 2);
		color = ft_color(data->rgb_floor[0],
				data->rgb_floor[1], data->rgb_floor[2], data->rgb_floor[3]);
		render_pixel(plaine, pos, color, data->window.image);
	}
}

/**
 * @brief Sets the X and Y values of a 2-element integer array.
 * 
 * This utility function assigns the provided X and Y values
 * to the respective indices of the given integer array.
 * It is used to define coordinates or
 * dimensions within other functions.
 * 
 * @param ptr A pointer to a 2-element integer array
 * 			where the values will be set.
 * @param pos_x The value to assign to the X
 * 			(index 1) position in the array.
 * @param pos_y The value to assign to the Y
 * 			(index 0) position in the array.
 */

static void	define_value(int ptr[2], int pos_x, int pos_y)
{
	ptr[0] = pos_y;
	ptr[1] = pos_x;
}

/**
 * @brief Fills a rectangular area of the image with a specified color.
 * 
 * This function draws a rectangle on the image by iterating over a specified 
 * range of pixels and setting each pixel to the provided color. The rectangle 
 * is defined by the starting position and the dimensions given by `plaine`.
 * 
 * @param plaine A 2-element array representing the width (X) and height (Y) 
 *          of the rectangle to be drawn.
 * @param pos A 2-element array representing the starting position (X, Y) 
 *          from where the rectangle will be drawn on the image.
 * @param color The RGBA color value that will be applied to
 * 			the pixels in the rectangle.
 * @param image A pointer to the `mlx_image_t` structure that
 * 			represents the image where the pixels will be drawn.
 */
static void	render_pixel(int plaine[2], int pos[2], int color, mlx_image_t *image)
{
	int	y;
	int	x;

	y = 0;
	while (y < plaine[X])
	{
		x = 0;
		while (x < plaine[Y])
		{
			mlx_put_pixel(image, pos[Y] + x, pos[X] + y, color);
			x++;
		}
		y++;
	}
}
