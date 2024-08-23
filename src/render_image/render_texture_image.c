/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:03:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 09:59:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ray_casting.h"
#include "defines.h"

/**
 * @brief Renders a vertical line of pixels from a texture on to the screen image.
 * 
 * This function iterates through a specified vertical segment on the screen, 
 * filling it with pixel colors extracted from a texture.
 * It is used in the context of raycasting
 * to render textured walls or surfaces.
 * 
 * @param data A pointer to the main game data structure (`t_data`).
 *   - `data->window.image`: The image buffer where the pixels will be drawn.
 * 
 * @param ray A pointer to the raycasting data structure (`t_ray`).
 *   This function utilizes the following attributes:
 *   - `ray->draw_start`: The starting Y-coordinate for drawing.
 *   - `ray->draw_end`: The ending Y-coordinate for drawing.
 *   - `ray->index`: The X-coordinate on the screen where
 * 		the vertical line is drawn.
 * 
 * @param buffercolor An array containing the RGBA
 * 					  values extracted from the texture.
 *  - Each element in this array represents the color of a pixel 
 *  at a corresponding Y-coordinate on the screen.
 */
void	render_texture_on_image(t_data *data, t_ray *ray, int bufercolor[HEIGHT])
{
	while (ray->draw_start < ray->draw_end)
	{
		mlx_put_pixel(data->window.image, ray->index,
			ray->draw_start, bufercolor[ray->draw_start]);
		ray->draw_start++;
	}
}
